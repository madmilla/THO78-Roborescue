#include <stdlib.h>
#include <iostream>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <chrono>

using namespace sql;
using namespace std;
using namespace std::chrono;

int main(void){
  try{
	  cout<<"database connection opening\n";
	  sql::Driver *driver;
	  sql::Connection *con;
	  sql::ResultSet *res;
	  sql::Statement *stmt;
	  sql::PreparedStatement *pstmt;

	  driver = get_driver_instance();
	  con = driver->connect("tcp://127.0.0.1:3306", "root", "desktop");
	  /* Connect to the MySQL test database */
	  con->setSchema("test");
	  duration<float> add;
	  duration<float> read;
	  for(int i = 10; i <= 10000000; i *= 10){
		  stmt = con->createStatement();
		  stmt->execute("DROP TABLE IF EXISTS test");
		  stmt->execute("CREATE TABLE test(id INT)");
		  for(int i=0; i<100; i++){
			  /* '?' is the supported placeholder syntax */
			  pstmt = con->prepareStatement("INSERT INTO test(id) VALUES (?)");
			  system_clock::time_point start = system_clock::now();
			  for (int i2 = 1; i2 <= i; i2++) {
			    pstmt->setInt(1, i2);
			    pstmt->executeUpdate();
			  }
			  add += (system_clock::now() - start);


			  /* Select in ascending order */
			  start = start = system_clock::now();
			  pstmt = con->prepareStatement("SELECT id FROM test ORDER BY id ASC");
			  res = pstmt->executeQuery();
		          read+= (system_clock::now() - start);
		  }
		  auto addAverage=add/100;
		  auto readAverage=read/100;
		  cout << "\n\n---------------------------------Test with " << i << " lines-------------------------------------------\n" ;
		  cout << "add Average is: " << addAverage.count() << "s\n";
		  cout << "read Average is: " << readAverage.count() << "s\n\n";
	  }	
	  delete stmt;
	  delete res;
	  delete pstmt;
	  delete con;
 }catch(exception &e){
	cout<<"error: " << e.what() <<"\n";
 }
  return 0;
}
