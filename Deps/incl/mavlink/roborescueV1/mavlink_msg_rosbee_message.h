// MESSAGE rosbee_message PACKING

#define MAVLINK_MSG_ID_rosbee_message 194

typedef struct __mavlink_rosbee_message_t
{
 uint64_t Payload; ///< Payload
 uint8_t Destination; ///< Device ID
 uint8_t Function; ///< Name of the function
} mavlink_rosbee_message_t;

#define MAVLINK_MSG_ID_rosbee_message_LEN 10
#define MAVLINK_MSG_ID_194_LEN 10

#define MAVLINK_MSG_ID_rosbee_message_CRC 67
#define MAVLINK_MSG_ID_194_CRC 67



#define MAVLINK_MESSAGE_INFO_rosbee_message { \
	"rosbee_message", \
	3, \
	{  { "Payload", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_rosbee_message_t, Payload) }, \
         { "Destination", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_rosbee_message_t, Destination) }, \
         { "Function", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_rosbee_message_t, Function) }, \
         } \
}


/**
 * @brief Pack a rosbee_message message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param Payload Payload
 * @param Destination Device ID
 * @param Function Name of the function
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_rosbee_message_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t Payload, uint8_t Destination, uint8_t Function)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_rosbee_message_LEN];
	_mav_put_uint64_t(buf, 0, Payload);
	_mav_put_uint8_t(buf, 8, Destination);
	_mav_put_uint8_t(buf, 9, Function);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_rosbee_message_LEN);
#else
	mavlink_rosbee_message_t packet;
	packet.Payload = Payload;
	packet.Destination = Destination;
	packet.Function = Function;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_rosbee_message_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_rosbee_message;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_rosbee_message_LEN, MAVLINK_MSG_ID_rosbee_message_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_rosbee_message_LEN);
#endif
}

/**
 * @brief Pack a rosbee_message message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param Payload Payload
 * @param Destination Device ID
 * @param Function Name of the function
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_rosbee_message_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t Payload,uint8_t Destination,uint8_t Function)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_rosbee_message_LEN];
	_mav_put_uint64_t(buf, 0, Payload);
	_mav_put_uint8_t(buf, 8, Destination);
	_mav_put_uint8_t(buf, 9, Function);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_rosbee_message_LEN);
#else
	mavlink_rosbee_message_t packet;
	packet.Payload = Payload;
	packet.Destination = Destination;
	packet.Function = Function;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_rosbee_message_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_rosbee_message;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_rosbee_message_LEN, MAVLINK_MSG_ID_rosbee_message_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_rosbee_message_LEN);
#endif
}

/**
 * @brief Encode a rosbee_message struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param rosbee_message C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_rosbee_message_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_rosbee_message_t* rosbee_message)
{
	return mavlink_msg_rosbee_message_pack(system_id, component_id, msg, rosbee_message->Payload, rosbee_message->Destination, rosbee_message->Function);
}

/**
 * @brief Encode a rosbee_message struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param rosbee_message C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_rosbee_message_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_rosbee_message_t* rosbee_message)
{
	return mavlink_msg_rosbee_message_pack_chan(system_id, component_id, chan, msg, rosbee_message->Payload, rosbee_message->Destination, rosbee_message->Function);
}

/**
 * @brief Send a rosbee_message message
 * @param chan MAVLink channel to send the message
 *
 * @param Payload Payload
 * @param Destination Device ID
 * @param Function Name of the function
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_rosbee_message_send(mavlink_channel_t chan, uint64_t Payload, uint8_t Destination, uint8_t Function)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_rosbee_message_LEN];
	_mav_put_uint64_t(buf, 0, Payload);
	_mav_put_uint8_t(buf, 8, Destination);
	_mav_put_uint8_t(buf, 9, Function);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_rosbee_message, buf, MAVLINK_MSG_ID_rosbee_message_LEN, MAVLINK_MSG_ID_rosbee_message_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_rosbee_message, buf, MAVLINK_MSG_ID_rosbee_message_LEN);
#endif
#else
	mavlink_rosbee_message_t packet;
	packet.Payload = Payload;
	packet.Destination = Destination;
	packet.Function = Function;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_rosbee_message, (const char *)&packet, MAVLINK_MSG_ID_rosbee_message_LEN, MAVLINK_MSG_ID_rosbee_message_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_rosbee_message, (const char *)&packet, MAVLINK_MSG_ID_rosbee_message_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_rosbee_message_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_rosbee_message_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t Payload, uint8_t Destination, uint8_t Function)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, Payload);
	_mav_put_uint8_t(buf, 8, Destination);
	_mav_put_uint8_t(buf, 9, Function);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_rosbee_message, buf, MAVLINK_MSG_ID_rosbee_message_LEN, MAVLINK_MSG_ID_rosbee_message_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_rosbee_message, buf, MAVLINK_MSG_ID_rosbee_message_LEN);
#endif
#else
	mavlink_rosbee_message_t *packet = (mavlink_rosbee_message_t *)msgbuf;
	packet->Payload = Payload;
	packet->Destination = Destination;
	packet->Function = Function;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_rosbee_message, (const char *)packet, MAVLINK_MSG_ID_rosbee_message_LEN, MAVLINK_MSG_ID_rosbee_message_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_rosbee_message, (const char *)packet, MAVLINK_MSG_ID_rosbee_message_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE rosbee_message UNPACKING


/**
 * @brief Get field Payload from rosbee_message message
 *
 * @return Payload
 */
static inline uint64_t mavlink_msg_rosbee_message_get_Payload(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field Destination from rosbee_message message
 *
 * @return Device ID
 */
static inline uint8_t mavlink_msg_rosbee_message_get_Destination(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field Function from rosbee_message message
 *
 * @return Name of the function
 */
static inline uint8_t mavlink_msg_rosbee_message_get_Function(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Decode a rosbee_message message into a struct
 *
 * @param msg The message to decode
 * @param rosbee_message C-struct to decode the message contents into
 */
static inline void mavlink_msg_rosbee_message_decode(const mavlink_message_t* msg, mavlink_rosbee_message_t* rosbee_message)
{
#if MAVLINK_NEED_BYTE_SWAP
	rosbee_message->Payload = mavlink_msg_rosbee_message_get_Payload(msg);
	rosbee_message->Destination = mavlink_msg_rosbee_message_get_Destination(msg);
	rosbee_message->Function = mavlink_msg_rosbee_message_get_Function(msg);
#else
	memcpy(rosbee_message, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_rosbee_message_LEN);
#endif
}
