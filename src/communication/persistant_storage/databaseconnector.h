/**
* @file databaseconnector.h
* @author Robert Bezem
* @date 18 04 2015
* @brief File containing the declaration of the databaseConnector class
*
*/

#ifndef DATABASECONNECTOR_H
#define DATABASECONNECTOR_H

#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <string>
#include <vector>
#include "point.hpp"

/** \class databaseConnector
 * \brief This class handles all the communication with the database
 *
 */
struct map{
	int id;
	std::string name;
};

class databaseConnector {
public:
    /** \brief  Constructor of the database Connector
     *
     * \param  hostname the hostname of the database ex: tcp://127.0.0.1:3306
     * \param  username the username used to connect the database
     * \param  password the password for the user
     * \param  schemaName the name of the schema you want to use
     *
     */
    databaseConnector(std::string hostname, std::string username, std::string password, std::string schemaName);
    virtual ~databaseConnector();

	/** \brief returns all known maps
	*
	* \return all know maps as a vector of a map struct with a id and name
	*
	*/
	std::vector<map> getMaps();

	/** \brief Sets the map that is going to be used
	*
	* \param id the id of the map
	*
	*/
	void setMap(int id);

    /** \brief Add a polygon to the database
     *
     * \param polygon a vector of points aka a polygon
     *
     */
    void addPolygon( const std::vector<point>& polygon );


    /** \brief Add a list of polygons to the database
     *
     * \param  polygons A vector of polygons(which is a vector of points)
     *
     */
    void addPolygon( const std::vector<std::vector<point> >& polygons );


    /** \brief get all the polygons from the database
     *
     * \return a vector of polygons(which are a vector of points)
     *
     */
    std::vector<std::vector<point> > getPolygons();


    /** \brief checks if a point is accesable
     *
     * \param point the point to check for collisions
     * \return true if the point is accesable false if there's a object on that position
     *
     * This function checks if a point is accesable, outer borders of figures are not included and marked as accesable \n
     * ex: square with on coordinates -10 10. If the functions gets the point 10,10 it returns false. If the functions gets the point 9,9 it returns true
     */
    bool isAccessable( point& p );


    /** \brief this function sets the position of a vehicle at the current time
     *
     * \param vehicleId the id of the vehicle
     * \param position the current position of the vehicle
     *
     */
    void setPosition( const int& vehicleId,const point& position );


    /** \brief this function sets the position of a vehicle at the current time
     *
     * \param vehicleName the unique name of the vehicle
     * \param position the current position of the vehicle
     *
     */
    void setPosition( const std::string& vehicleName,const point& position );


    /** \brief this function returns the last known position of a vehicle at the current time
     *
     * \param vehicleId the id of the vehicle
     *
     * \return point the last known position of the vehicle
     *
     */
    point getLastPosition( const int& vehicleId );


    /** \brief this function returns the last known position of a vehicle at the current time
     *
     * \param vehicleName the name of the vehicle
     *
     * \return the last known position of the vehicle
     *
     */
    point getLastPosition( const std::string& vehicleName );


    /** \brief returns all the known positions of the vehicle
     *
     * \param vehicleId the id of the vehicle
     * \param reverse if values are in reverse order or not \n default:false
     * \return a vector of points where the vehicle has been
     *
     * If reverse is false you'll get the first know position first and the last know position last
     *
     */
    std::vector<point> getAllPositions( const int& vehicleId,const bool& reverse = false );

    /** \brief returns all the known positions of the vehicle
     *
     * \param vehiclenName the name of the vehicle
     * \param reverse if values are in reverse order or not \n default:false
     * \return a vector of points where the vehicle has been
     *
     * If reverse is false you'll get the first know position first and the last know position last
     *
     */
    std::vector<point> getAllPositions( const std::string& vehicleName,const bool& reverse = false );


    /** \brief gets the vehicle id from the database
     *
     * \param Name the name of the vehicle
     * \return the vehicle id
     *
     */
    int getVehicleId( const std::string& Name );

private:
    std::vector<point> polygonParser( const std::string& polygonString );
    point pointParser( const std::string& pointString );
    sql::Connection* con;
    sql::Statement* stmt;
    std::string statement_start="INSERT INTO `polygon` (`polygon`) VALUES (GeomFromText('POLYGON((";
    std::string statement_end="))'));";
    std::string statement_mid="))')),(GeomFromText('POLYGON((";
	int mapId;
};

#endif // DATABASECONNECTOR_H
