/**
* @file databaseconnector.cpp
* @author Robert Bezem
* @date 18 04 2015
* @brief File containing the implementation of the databaseConnector class
*
*/

#include "databaseconnector.h"

#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/datatype.h>
#include <cppconn/exception.h>

databaseConnector::databaseConnector( std::string hostname,std::string username, std::string password, std::string schema ) {

    sql::Driver* driver = get_driver_instance();
    con = driver->connect ( hostname,username,password );
    con->setSchema ( schema );
    stmt = con->createStatement();
}

databaseConnector::~databaseConnector() {
    delete con;
    delete stmt;
}

std::vector<map> getMaps(){
	std::vector<map> maps;
	sql::ResultSet* res = stmt->executeQuery("SELECT id, name FROM map");
	while (res->next()) {
		polygons.push_back(map{res->getInt(1),res->getString(2));
	}
	delete res;
	return maps;
}

void setMap(int id){

}

void databaseConnector::addPolygon( const std::vector<point>& polygon ) {
    std::string statement = statement_start;
    for ( unsigned int i = 0; i < polygon.size(); i++ ) {
        statement += std::to_string ( polygon.at ( i ).getX() ) + ' ' + std::to_string ( polygon.at ( i ).getY() ) + ( ( i == polygon.size()-1 ) ? ' ' : ',' );
    }
    statement += statement_end;
    stmt->execute ( statement );
}

void databaseConnector::addPolygon( const std::vector<std::vector<point> >& polygons  ) {
    std::string statement = statement_start;
    for (unsigned int i=0; i<polygons.size(); i++ ) {
        for ( unsigned int ii = 0; ii < polygons.at ( i ).size(); ii++ ) {
            statement += std::to_string ( polygons.at ( i ).at ( ii ).getX() ) + ' ' + std::to_string ( polygons.at ( i ).at ( ii ).getY() ) + ( ( ii == polygons.at ( i ).size()-1 ) ? ' ' : ',' );
        }
        if ( i!=polygons.size()-1 ) {
            statement+=statement_mid;
        }
    }
    statement+=statement_end;
    stmt->execute ( statement );
}
std::vector<std::vector<point> > databaseConnector::getPolygons() {
    std::vector<std::vector<point> > polygons;
    sql::ResultSet* res = stmt->executeQuery ( "SELECT AsText(`polygon`) FROM polygon" );
    while ( res->next() ) {
        polygons.push_back ( polygonParser ( res->getString ( 1 ) ) );
    }
    delete res;
    return polygons;
}

bool databaseConnector::isAccessable( point& p ) {
    sql::ResultSet* res= stmt->executeQuery ( "SELECT count(id) FROM `polygon` WHERE contains(`polygon`,GeomFromText('POINT("+std::to_string ( p.getX() ) + ' ' + std::to_string ( p.getY() ) + ")'));" );
    if ( !res->next() ) {
        return false;
    }
    std::cout<<res->getInt ( 1 );
    bool returns = !res->getInt ( 1 );
    delete res;

    return returns;
}

int databaseConnector::getVehicleId( const std::string& name ) {
    sql::ResultSet* res= stmt->executeQuery ( "SELECT id FROM `vehicle` WHERE name = '" + name + "'" );
    if ( !res->next() ) {
        return -1;
    }
    return res->getInt ( 1 );
}

void databaseConnector::setPosition( const int& vehicleId,const point& position ) {
    stmt->executeUpdate ( "INSERT INTO `checkpoint` (`vehicle_id`, `time`, `position`) VALUES ('" + std::to_string ( vehicleId ) + "', CURRENT_TIMESTAMP, GeomFromText('POINT(" + std::to_string ( position.getX() ) + " " + std::to_string ( position.getY() ) + ")') );" );
}

void databaseConnector::setPosition( const std::string& vehicleName,const point& position) {
    stmt->executeUpdate ( "INSERT INTO `checkpoint` (`vehicle_id`, `time`, `position`) VALUES ((SELECT id FROM `vehicle` WHERE name = '" + vehicleName + "'), CURRENT_TIMESTAMP,  GeomFromText('POINT(" + std::to_string ( position.getX() ) + " " + std::to_string ( position.getY() ) + ")') );" );
}

point databaseConnector::getLastPosition( const int& vehicleId ) {
    sql::ResultSet* res= stmt->executeQuery ( "SELECT asText(position) FROM `checkpoint` WHERE vehicle_id = '" + std::to_string ( vehicleId ) + "' ORDER BY time DESC LIMIT 0,1" );
    if ( res->next() ) {
        return pointParser ( res->getString ( 1 ) );
    }
    return point ( 0,0 );
}

point databaseConnector::getLastPosition( const std::string& vehicleName ) {
    sql::ResultSet* res= stmt->executeQuery ( "SELECT asText(position) FROM `checkpoint` WHERE vehicle_id = (SELECT id FROM `vehicle` WHERE name = '" + vehicleName + "') ORDER BY time DESC LIMIT 0,1" );
    if ( res->next() ) {
        return pointParser ( res->getString ( 1 ) );
    }
    return point ( 0,0 );
}

std::vector<point> databaseConnector::getAllPositions( const int& vehicleId,const bool& reverse) {
    sql::ResultSet* res = stmt->executeQuery ( "SELECT asText(position) FROM `checkpoint` WHERE vehicle_id = '" + std::to_string ( vehicleId ) + "' ORDER BY time "+ ( reverse? "DESC" : "ASC" ) );
    std::vector<point> points;
    while ( res->next() ) {
        points.push_back ( pointParser ( res->getString ( 1 ) ) );
    }
    return points;
}

std::vector<point> databaseConnector::getAllPositions( const std::string& vehicleName,const bool& reverse) {
    sql::ResultSet* res= stmt->executeQuery ( "SELECT asText(position) FROM `checkpoint` WHERE vehicle_id = (SELECT id FROM `vehicle` WHERE name = '" + vehicleName + "') ORDER BY time "+ ( reverse? "DESC" : "ASC" ) );
    std::vector<point> points;
    while ( res->next() ) {
        points.push_back ( pointParser ( res->getString ( 1 ) ) );
    }
    return points;
}

//! Parses a polygon string to a point vector
//! @param The string to be parsed
//! @return A vector of points
std::vector<point> databaseConnector:: polygonParser( const std::string& polygonString) {
    std::vector<point> rtn;                             // vector of points to be returned
    int i = polygonString.find_first_of ( "((" ) + 2;
    std::string tmp = polygonString.substr ( i, polygonString.length() - i - 2 ); // strip to points only

    unsigned int index = 0;
    std::string split;
    std::vector<std::string> points;
    while ( static_cast<int>((index = tmp.find ( "," ) )) != -1 ) {          // loop till can't find more ,
        split = tmp.substr ( 0, index );
        points.push_back ( split );                               // push point in string format
        tmp.erase ( 0, index + 1 );                               // erase found point
    }
    points.push_back ( tmp );

    for ( unsigned int j = 0; j < points.size(); j++ ) {
        std::string sPoint = points[j];
        int spaceIndex = sPoint.find ( " " );                     // find space in string point format
        int x = std::stoi ( sPoint.substr ( 0, spaceIndex ) ); // x of point
        int y = std::stoi ( sPoint.substr ( spaceIndex + 1 ) ); // y of point
        rtn.push_back ( point {x, y} );
    }

    return rtn;
}

point databaseConnector::pointParser( const std::string& pointString ) {
    int i = pointString.find_first_of ( "(" )+1;
    std::string tmp = pointString.substr ( i, pointString.length() - i - 1 ); // strip to points only
    int spaceIndex = tmp.find ( " " );                // find space in string point format
    int x = std::stoi ( tmp.substr ( 0, spaceIndex ) ); // x of point
    int y = std::stoi ( tmp.substr ( spaceIndex + 1 ) ); // y of point
    return point ( x,y );
}
