
class COMMAND_DESTINATION{
public:
	constexpr static const unsigned short ROSBEE = 1;
};

class ROSBEE_COMMAND_FUNCTIONS{
public:
	constexpr static const char ROSBEE_INIT = 0x00;
	constexpr static const char ACKNOWLEDGE = 0x01;
	constexpr static const char SENDWAYPOINT = 0x02;
};
