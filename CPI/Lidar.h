#ifndef LIDAR_H_
#define LIDAR_H_

#include <queue>
#include "CPIBoundaryObject.hpp"
#include "..\..\mavlink_commands\mavlink_commands\mavlink.h"
#include "Socket.hpp"
#include "RALCPEncoder.hpp"

//! \file Lidar.h
//! \class Lidar
//! \brief A class that communicates with the lidar
//! \details A class that sends and receives commands and manages the communicttion with the lidar
//! \author    Hamza ait Messaoud
//! \version   1.0
//! \date      9-4-2015
//! \warning


class Lidar: public CPIBoundaryObject{
public:
   // constructor to make a Rosbee object (socket)
   // @param: Socket is used to listen to a specific socket
   Lidar(Socket s) : CPIBoundaryObject(s, s.getId()){
      encoder = new RALCPEncoder(s, s.getId(), 0, 0, 0);
   }

   ~Lidar(){ delete encoder; }

   //! \brief standard constructor
   //! \param[in] m a reference to the CommandsMap class
   //! \param[in] s a reference to the CommandsStrategy class
   void sendCommand(mavlink_message_t * cmd) override;

   //! \brief Recieve line data from the lidar
   void recieveLine();

   //! \brief standard constructor
   //! \param[in] msg a reference to the mavlink message struct
   void recieveRpm();

   //! \brief standard constructor
   //! \param[in] rpm a reference to rpm to be set for the Lidar
   void sendRpm(int rpm);

   //! \brief start the lidar to scan
   void Start();

   //! \brief stops the lidar with scanning
   void Stop();

   //! \brief sends the last knwon positon of the rosbee
   //! \param[in] postion a reference to the positon of the rosbee
   void sendRosbeePositie(int postion[]);

   //! \brief sends the current flank of the rosbee
   //! \param[in] dagrees a reference to the flank of the rosbee
   void sendRosbeeFlank(int degrees);

private:
   mavlink_message_t message;
   RALCPEncoder * encoder;

};


#endif /* LIDAR_H_ */
