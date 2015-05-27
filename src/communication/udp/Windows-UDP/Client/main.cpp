#include "client.h"



int main(void){

	Client client;
	
   while (1){
	   client.sendMessage();
	   Sleep(3000);
   }

   return 0;
}