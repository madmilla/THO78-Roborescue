// MESSAGE sendRosbeeFlank PACKING

#define MAVLINK_MSG_ID_sendRosbeeFlank 18

typedef struct __mavlink_sendrosbeeflank_t
{
 int16_t Payload; ///< Payload
 uint8_t Destination; ///< Device ID
 uint8_t Function; ///< Name of the function
} mavlink_sendrosbeeflank_t;

#define MAVLINK_MSG_ID_sendRosbeeFlank_LEN 4
#define MAVLINK_MSG_ID_18_LEN 4

#define MAVLINK_MSG_ID_sendRosbeeFlank_CRC 143
#define MAVLINK_MSG_ID_18_CRC 143



#define MAVLINK_MESSAGE_INFO_sendRosbeeFlank { \
	"sendRosbeeFlank", \
	3, \
	{  { "Payload", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_sendrosbeeflank_t, Payload) }, \
         { "Destination", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_sendrosbeeflank_t, Destination) }, \
         { "Function", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_sendrosbeeflank_t, Function) }, \
         } \
}


/**
 * @brief Pack a sendrosbeeflank message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param Destination Device ID
 * @param Function Name of the function
 * @param Payload Payload
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sendrosbeeflank_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t Destination, uint8_t Function, int16_t Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_sendRosbeeFlank_LEN];
	_mav_put_int16_t(buf, 0, Payload);
	_mav_put_uint8_t(buf, 2, Destination);
	_mav_put_uint8_t(buf, 3, Function);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_sendRosbeeFlank_LEN);
#else
	mavlink_sendrosbeeflank_t packet;
	packet.Payload = Payload;
	packet.Destination = Destination;
	packet.Function = Function;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_sendRosbeeFlank_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_sendRosbeeFlank;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_sendRosbeeFlank_LEN, MAVLINK_MSG_ID_sendRosbeeFlank_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_sendRosbeeFlank_LEN);
#endif
}

/**
 * @brief Pack a sendrosbeeflank message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param Destination Device ID
 * @param Function Name of the function
 * @param Payload Payload
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sendrosbeeflank_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t Destination,uint8_t Function,int16_t Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_sendRosbeeFlank_LEN];
	_mav_put_int16_t(buf, 0, Payload);
	_mav_put_uint8_t(buf, 2, Destination);
	_mav_put_uint8_t(buf, 3, Function);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_sendRosbeeFlank_LEN);
#else
	mavlink_sendrosbeeflank_t packet;
	packet.Payload = Payload;
	packet.Destination = Destination;
	packet.Function = Function;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_sendRosbeeFlank_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_sendRosbeeFlank;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_sendRosbeeFlank_LEN, MAVLINK_MSG_ID_sendRosbeeFlank_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_sendRosbeeFlank_LEN);
#endif
}

/**
 * @brief Encode a sendrosbeeflank struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sendrosbeeflank C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sendrosbeeflank_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sendrosbeeflank_t* sendrosbeeflank)
{
	return mavlink_msg_sendrosbeeflank_pack(system_id, component_id, msg, sendrosbeeflank->Destination, sendrosbeeflank->Function, sendrosbeeflank->Payload);
}

/**
 * @brief Encode a sendrosbeeflank struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sendrosbeeflank C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sendrosbeeflank_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sendrosbeeflank_t* sendrosbeeflank)
{
	return mavlink_msg_sendrosbeeflank_pack_chan(system_id, component_id, chan, msg, sendrosbeeflank->Destination, sendrosbeeflank->Function, sendrosbeeflank->Payload);
}

/**
 * @brief Send a sendrosbeeflank message
 * @param chan MAVLink channel to send the message
 *
 * @param Destination Device ID
 * @param Function Name of the function
 * @param Payload Payload
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sendrosbeeflank_send(mavlink_channel_t chan, uint8_t Destination, uint8_t Function, int16_t Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_sendRosbeeFlank_LEN];
	_mav_put_int16_t(buf, 0, Payload);
	_mav_put_uint8_t(buf, 2, Destination);
	_mav_put_uint8_t(buf, 3, Function);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendRosbeeFlank, buf, MAVLINK_MSG_ID_sendRosbeeFlank_LEN, MAVLINK_MSG_ID_sendRosbeeFlank_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendRosbeeFlank, buf, MAVLINK_MSG_ID_sendRosbeeFlank_LEN);
#endif
#else
	mavlink_sendrosbeeflank_t packet;
	packet.Payload = Payload;
	packet.Destination = Destination;
	packet.Function = Function;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendRosbeeFlank, (const char *)&packet, MAVLINK_MSG_ID_sendRosbeeFlank_LEN, MAVLINK_MSG_ID_sendRosbeeFlank_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendRosbeeFlank, (const char *)&packet, MAVLINK_MSG_ID_sendRosbeeFlank_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_sendRosbeeFlank_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sendrosbeeflank_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t Destination, uint8_t Function, int16_t Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_int16_t(buf, 0, Payload);
	_mav_put_uint8_t(buf, 2, Destination);
	_mav_put_uint8_t(buf, 3, Function);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendRosbeeFlank, buf, MAVLINK_MSG_ID_sendRosbeeFlank_LEN, MAVLINK_MSG_ID_sendRosbeeFlank_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendRosbeeFlank, buf, MAVLINK_MSG_ID_sendRosbeeFlank_LEN);
#endif
#else
	mavlink_sendrosbeeflank_t *packet = (mavlink_sendrosbeeflank_t *)msgbuf;
	packet->Payload = Payload;
	packet->Destination = Destination;
	packet->Function = Function;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendRosbeeFlank, (const char *)packet, MAVLINK_MSG_ID_sendRosbeeFlank_LEN, MAVLINK_MSG_ID_sendRosbeeFlank_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendRosbeeFlank, (const char *)packet, MAVLINK_MSG_ID_sendRosbeeFlank_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE sendRosbeeFlank UNPACKING


/**
 * @brief Get field Destination from sendrosbeeflank message
 *
 * @return Device ID
 */
static inline uint8_t mavlink_msg_sendrosbeeflank_get_Destination(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field Function from sendrosbeeflank message
 *
 * @return Name of the function
 */
static inline uint8_t mavlink_msg_sendrosbeeflank_get_Function(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field Payload from sendrosbeeflank message
 *
 * @return Payload
 */
static inline int16_t mavlink_msg_sendrosbeeflank_get_Payload(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Decode a sendrosbeeflank message into a struct
 *
 * @param msg The message to decode
 * @param sendrosbeeflank C-struct to decode the message contents into
 */
static inline void mavlink_msg_sendrosbeeflank_decode(const mavlink_message_t* msg, mavlink_sendrosbeeflank_t* sendrosbeeflank)
{
#if MAVLINK_NEED_BYTE_SWAP
	sendrosbeeflank->Payload = mavlink_msg_sendrosbeeflank_get_Payload(msg);
	sendrosbeeflank->Destination = mavlink_msg_sendrosbeeflank_get_Destination(msg);
	sendrosbeeflank->Function = mavlink_msg_sendrosbeeflank_get_Function(msg);
#else
	memcpy(sendrosbeeflank, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_sendRosbeeFlank_LEN);
#endif
}
