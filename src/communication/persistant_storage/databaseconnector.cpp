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

std::vector<map> databaseConnector::getMaps(){
	std::vector<map> maps;
	sql::ResultSet* res = stmt->executeQuery("SELECT id, name FROM map");
	while (res->next()) {
		maps.push_back(map{res->getInt(1),res->getString(2)});
	}
	delete res;
	return maps;
}

int databaseConnector::getMapId(std::string mapName){
	sql::ResultSet* res = stmt->executeQuery("SELECT id FROM map WHERE name = "+mapName);
	int returnId;
	if(!res->next()){
		delete res;
		return -1;
	}
	returnId = res->getInt(1);
	delete res;
	return returnId;
}

void databaseConnector::setMap(int id){
	mapId = id;
}

void databaseConnector::addPolygon( const std::vector<point>& polygon ) {
    if(mapId == -1){
        throw std::invalid_argument{"no map is set use setMap() first"};
    }
    std::string statement = statement_start;
    for ( unsigned int i = 0; i < polygon.size(); i++ ) {
        statement += std::to_string ( polygon.at ( i ).getX() ) + ' ' + std::to_string ( polygon.at ( i ).getY() ) + ( ( i == polygon.size()-1 ) ? ' ' : ',' );
    }
    statement += statement_mid + std::to_string(mapId) + statement_end;
    stmt->execute ( statement );
}

void databaseConnector::addPolygon( const std::vector<std::vector<point> >& polygons  ) {
    if(mapId == -1){
        throw std::invalid_argument{"no map is set use setMap() first"};
    }
    std::string statement = statement_start;
    for (unsigned int i=0; i<polygons.size(); i++ ) {
        for ( unsigned int ii = 0; ii < polygons.at ( i ).size(); ii++ ) {
            statement += std::to_string ( polygons.at ( i ).at ( ii ).getX() ) + ' ' + std::to_string ( polygons.at ( i ).at ( ii ).getY() ) + ( ( ii == polygons.at ( i ).size()-1 ) ? ' ' : ',' );
        }
        if ( i!=polygons.size()-1 ) {
            statement+=statement_mid + std::to_string(mapId) + statement_continue;
        }
    }
    statement+= statement_mid + std::to_string(mapId) + statement_end;
    stmt->execute ( statement );
}
std::vector<std::vector<point> > databaseConnector::getPolygons() {
    if(mapId == -1){
        throw std::invalid_argument{"no map is set use setMap() first"};
    }
    std::vector<std::vector<point> > polygons;
    sql::ResultSet* res = stmt->executeQuery ( "SELECT AsText(`polygon`) FROM object WHERE map_id = " + std::to_string(mapId) );
    while ( res->next() ) {
        polygons.push_back ( polygonParser ( res->getString ( 1 ) ) );
    }
    delete res;
    return polygons;
}

bool databaseConnector::isAccessable( point& p ) {
    if(mapId == -1){
        throw std::invalid_argument{"no map is set use setMap() first"};
    }
    sql::ResultSet* res= stmt->executeQuery ( "SELECT count(id) FROM `object` WHERE map_id = " + std::to_string(mapId) + " AND ST_CONTAINS(`polygon`,GeomFromText('POINT("+std::to_string ( p.getX() ) + ' ' + std::to_string ( p.getY() ) + ")'))" );
    if ( !res->next() ) {
    	delete res;
        return false;
    }
    bool returns = !res->getInt ( 1 );
    delete res;

    return returns;
}

bool databaseConnector::isAccessable( std::vector<point>& polygon) {
	if(mapId == -1){
        throw std::invalid_argument{"no map is set use setMap() first"};
    }
    std::string statement = "SELECT count(id) FROM `object` WHERE map_id = " + std::to_string(mapId) + " AND ST_INTERSECTS(`polygon`,GeomFromText('POLYGON((";
	for ( unsigned int i = 0; i < polygon.size(); i++ ) {
        statement += std::to_string ( polygon.at ( i ).getX() ) + ' ' + std::to_string ( polygon.at ( i ).getY() ) + ( ( i == polygon.size()-1 ) ? ' ' : ',' );
    }
    statement+= "))'))";
    sql::ResultSet* res= stmt->executeQuery ( statement );
    if ( !res->next() ) {
    	delete res;
        return false;
    }
    bool returns = !res->getInt ( 1 );
    delete res;

    return returns;
}

int databaseConnector::getVehicleId( const std::string& name ) {
    if(mapId == -1){
        throw std::invalid_argument{"no map is set use setMap() first"};
    }
    sql::ResultSet* res= stmt->executeQuery ( "SELECT id FROM `vehicle` WHERE name = '" + name + "'" );
    if ( !res->next() ) {
        return -1;
    }
    return res->getInt ( 1 );
}

void databaseConnector::setPosition( const int& vehicleId,const point& position ) {
    if(mapId == -1){
        throw std::invalid_argument{"no map is set use setMap() first"};
    }
    stmt->executeUpdate ( "INSERT INTO `checkpoint` (`vehicle_id`, `time`, `position`, `map_id`) VALUES ('" + std::to_string ( vehicleId ) + "', CURRENT_TIMESTAMP, GeomFromText('POINT(" + std::to_string ( position.getX() ) + " " + std::to_string ( position.getY() ) + ")')," + std::to_string(mapId) + " );" );
}

void databaseConnector::setPosition( const std::string& vehicleName,const point& position) {
    if(mapId == -1){
        throw std::invalid_argument{"no map is set use setMap() first"};
    }
    stmt->executeUpdate ( "INSERT INTO `checkpoint` (`vehicle_id`, `time`, `position`) VALUES ((SELECT id FROM `vehicle` WHERE name = '" + vehicleName + "'), CURRENT_TIMESTAMP,  GeomFromText('POINT(" + std::to_string ( position.getX() ) + " " + std::to_string ( position.getY() ) + ")')," + std::to_string(mapId) + ");" );
}

point databaseConnector::getLastPosition( const int& vehicleId ) {
    if(mapId == -1){
        throw std::invalid_argument{"no map is set use setMap() first"};
    }
    sql::ResultSet* res= stmt->executeQuery ( "SELECT asText(position) FROM `checkpoint` WHERE map_id = " + std::to_string(mapId) + " AND vehicle_id = '" + std::to_string ( vehicleId ) + "' ORDER BY time DESC LIMIT 0,1" );
    if ( res->next() ) {
        return pointParser ( res->getString ( 1 ) );
    }
    return point ( 0,0 );
}

point databaseConnector::getLastPosition( const std::string& vehicleName ) {
    if(mapId == -1){
        throw std::invalid_argument{"no map is set use setMap() first"};
    }
    sql::ResultSet* res= stmt->executeQuery ( "SELECT asText(position) FROM `checkpoint` WHERE map_id = " + std::to_string(mapId) + " AND vehicle_id = (SELECT id FROM `vehicle` WHERE name = '" + vehicleName + "') ORDER BY time DESC LIMIT 0,1" );
    if ( res->next() ) {
        return pointParser ( res->getString ( 1 ) );
    }
    return point ( 0,0 );
}

std::vector<point> databaseConnector::getAllPositions( const int& vehicleId,const bool& reverse) {
    if(mapId == -1){
        throw std::invalid_argument{"no map is set use setMap() first"};
    }
    sql::ResultSet* res = stmt->executeQuery ( "SELECT asText(position) FROM `checkpoint` WHERE map_id = " + std::to_string(mapId) + " AND vehicle_id = '" + std::to_string ( vehicleId ) + "' ORDER BY time "+ ( reverse? "DESC" : "ASC" ) );
    std::vector<point> points;
    while ( res->next() ) {
        points.push_back ( pointParser ( res->getString ( 1 ) ) );
    }
    return points;
}

std::vector<point> databaseConnector::getAllPositions( const std::string& vehicleName,const bool& reverse) {
    if(mapId == -1){
        throw std::invalid_argument{"no map is set use setMap() first"};
    }
    sql::ResultSet* res= stmt->executeQuery ( "SELECT asText(position) FROM `checkpoint` WHERE map_id = " + std::to_string(mapId) + " AND vehicle_id = (SELECT id FROM `vehicle` WHERE name = '" + vehicleName + "') ORDER BY time "+ ( reverse? "DESC" : "ASC" ) );
    std::vector<point> points;
    while ( res->next() ) {
        points.push_back ( pointParser ( res->getString ( 1 ) ) );
    }
    return points;
}

//! Parses a polygon string to a point vector
//! @param The string to be parsed
//! @return A vector of points
std::vector<point> databaseConnector::polygonParser( const std::string& polygonString) {
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
