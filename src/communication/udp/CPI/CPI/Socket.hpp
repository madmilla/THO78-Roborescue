#ifndef __SOCKET__
#define __SOCKET__
#include <queue>
#include "../../../../../deps/incl/mavlink/udp_mavlink_commands/mavlink.h"
class UDPServer;

/// author@ Rene Keijzer<rene.keijzer@student.hu.nl>
/// class@ Socket
/// brief the base class for a socket, this has the virtual function which needs to be overwritten by other sockets like UDPsocket or a RF socket
class Socket{
public:
   Socket(){}

   /// brief virtual send function which needs to be implemented
   /// param@ pointer to mavlink message
   virtual void send(mavlink_message_t * message) {}


   /// \brief virtual receive function which needs to be implemented
   /// param@ pointer to mavlink message
   virtual void receive(mavlink_message_t * message){}


   /// brief virtual getid function which needs to be implemented, returns 0 on default
   /// return@ uint8_t id of socket
   virtual uint8_t getId(){ return 0; }
   ~Socket(){}
};
#endif