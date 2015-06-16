#include <math.h>
#include <cstdint>

class RosbeeProtolHandler {
private:
	int yLocation = 0, xLocation = 0;
public:
	int getTargetLocation(uint8_t message);
};
