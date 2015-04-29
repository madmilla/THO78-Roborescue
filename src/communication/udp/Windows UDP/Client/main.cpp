#include "client.h"
#include <thread>


int main(void){

   client Client = client();
	
   while (1){
	   Client.sendMessage();
	   Sleep(3000);
   }

   return 0;
}