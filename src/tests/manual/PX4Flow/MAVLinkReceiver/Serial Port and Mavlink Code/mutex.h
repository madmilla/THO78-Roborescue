#ifdef LINUX
#include <unistd.h>
#endif
#ifdef WINDOWS
#include <windows.h>
#endif

class mutex{
public:
	void lock(){
		while (locked){
			sleep(1);
		}
		locked = true;
	}
	
	void unlock(){
		locked = false;
	}
	
private:
	bool locked = false;

	void sleep(int sleepMs)
	{
	#ifdef LINUX
		usleep(sleepMs * 1000);   // usleep takes sleep time in us (1 millionth of a second)
	#endif
	#ifdef WINDOWS
		Sleep(sleepMs);
	#endif
	}
};