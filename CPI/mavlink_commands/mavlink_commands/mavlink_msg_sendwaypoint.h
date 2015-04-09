// MESSAGE sendWaypoint PACKING

#define MAVLINK_MSG_ID_sendWaypoint 3

typedef struct __mavlink_sendwaypoint_t
{
 uint16_t Payload; ///< Payload
 uint8_t Destination; ///< Device ID
 uint8_t Function; ///< Name of the function
} mavlink_sendwaypoint_t;

#define MAVLINK_MSG_ID_sendWaypoint_LEN 4
#define MAVLINK_MSG_ID_3_LEN 4

#define MAVLINK_MSG_ID_sendWaypoint_CRC 58
#define MAVLINK_MSG_ID_3_CRC 58



#define MAVLINK_MESSAGE_INFO_sendWaypoint { \
	"sendWaypoint", \
	3, \
	{  { "Payload", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_sendwaypoint_t, Payload) }, \
         { "Destination", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_sendwaypoint_t, Destination) }, \
         { "Function", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_sendwaypoint_t, Function) }, \
         } \
}


/**
 * @brief Pack a sendwaypoint message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param Destination Device ID
 * @param Function Name of the function
 * @param Payload Payload
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sendwaypoint_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t Destination, uint8_t Function, uint16_t Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_sendWaypoint_LEN];
	_mav_put_uint16_t(buf, 0, Payload);
	_mav_put_uint8_t(buf, 2, Destination);
	_mav_put_uint8_t(buf, 3, Function);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_sendWaypoint_LEN);
#else
	mavlink_sendwaypoint_t packet;
	packet.Payload = Payload;
	packet.Destination = Destination;
	packet.Function = Function;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_sendWaypoint_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_sendWaypoint;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_sendWaypoint_LEN, MAVLINK_MSG_ID_sendWaypoint_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_sendWaypoint_LEN);
#endif
}

/**
 * @brief Pack a sendwaypoint message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param Destination Device ID
 * @param Function Name of the function
 * @param Payload Payload
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sendwaypoint_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t Destination,uint8_t Function,uint16_t Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_sendWaypoint_LEN];
	_mav_put_uint16_t(buf, 0, Payload);
	_mav_put_uint8_t(buf, 2, Destination);
	_mav_put_uint8_t(buf, 3, Function);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_sendWaypoint_LEN);
#else
	mavlink_sendwaypoint_t packet;
	packet.Payload = Payload;
	packet.Destination = Destination;
	packet.Function = Function;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_sendWaypoint_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_sendWaypoint;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_sendWaypoint_LEN, MAVLINK_MSG_ID_sendWaypoint_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_sendWaypoint_LEN);
#endif
}

/**
 * @brief Encode a sendwaypoint struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sendwaypoint C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sendwaypoint_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sendwaypoint_t* sendwaypoint)
{
	return mavlink_msg_sendwaypoint_pack(system_id, component_id, msg, sendwaypoint->Destination, sendwaypoint->Function, sendwaypoint->Payload);
}

/**
 * @brief Encode a sendwaypoint struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sendwaypoint C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sendwaypoint_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sendwaypoint_t* sendwaypoint)
{
	return mavlink_msg_sendwaypoint_pack_chan(system_id, component_id, chan, msg, sendwaypoint->Destination, sendwaypoint->Function, sendwaypoint->Payload);
}

/**
 * @brief Send a sendwaypoint message
 * @param chan MAVLink channel to send the message
 *
 * @param Destination Device ID
 * @param Function Name of the function
 * @param Payload Payload
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sendwaypoint_send(mavlink_channel_t chan, uint8_t Destination, uint8_t Function, uint16_t Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_sendWaypoint_LEN];
	_mav_put_uint16_t(buf, 0, Payload);
	_mav_put_uint8_t(buf, 2, Destination);
	_mav_put_uint8_t(buf, 3, Function);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendWaypoint, buf, MAVLINK_MSG_ID_sendWaypoint_LEN, MAVLINK_MSG_ID_sendWaypoint_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendWaypoint, buf, MAVLINK_MSG_ID_sendWaypoint_LEN);
#endif
#else
	mavlink_sendwaypoint_t packet;
	packet.Payload = Payload;
	packet.Destination = Destination;
	packet.Function = Function;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendWaypoint, (const char *)&packet, MAVLINK_MSG_ID_sendWaypoint_LEN, MAVLINK_MSG_ID_sendWaypoint_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendWaypoint, (const char *)&packet, MAVLINK_MSG_ID_sendWaypoint_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_sendWaypoint_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sendwaypoint_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t Destination, uint8_t Function, uint16_t Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint16_t(buf, 0, Payload);
	_mav_put_uint8_t(buf, 2, Destination);
	_mav_put_uint8_t(buf, 3, Function);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendWaypoint, buf, MAVLINK_MSG_ID_sendWaypoint_LEN, MAVLINK_MSG_ID_sendWaypoint_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendWaypoint, buf, MAVLINK_MSG_ID_sendWaypoint_LEN);
#endif
#else
	mavlink_sendwaypoint_t *packet = (mavlink_sendwaypoint_t *)msgbuf;
	packet->Payload = Payload;
	packet->Destination = Destination;
	packet->Function = Function;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendWaypoint, (const char *)packet, MAVLINK_MSG_ID_sendWaypoint_LEN, MAVLINK_MSG_ID_sendWaypoint_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendWaypoint, (const char *)packet, MAVLINK_MSG_ID_sendWaypoint_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE sendWaypoint UNPACKING


/**
 * @brief Get field Destination from sendwaypoint message
 *
 * @return Device ID
 */
static inline uint8_t mavlink_msg_sendwaypoint_get_Destination(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field Function from sendwaypoint message
 *
 * @return Name of the function
 */
static inline uint8_t mavlink_msg_sendwaypoint_get_Function(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field Payload from sendwaypoint message
 *
 * @return Payload
 */
static inline uint16_t mavlink_msg_sendwaypoint_get_Payload(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Decode a sendwaypoint message into a struct
 *
 * @param msg The message to decode
 * @param sendwaypoint C-struct to decode the message contents into
 */
static inline void mavlink_msg_sendwaypoint_decode(const mavlink_message_t* msg, mavlink_sendwaypoint_t* sendwaypoint)
{
#if MAVLINK_NEED_BYTE_SWAP
	sendwaypoint->Payload = mavlink_msg_sendwaypoint_get_Payload(msg);
	sendwaypoint->Destination = mavlink_msg_sendwaypoint_get_Destination(msg);
	sendwaypoint->Function = mavlink_msg_sendwaypoint_get_Function(msg);
#else
	memcpy(sendwaypoint, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_sendWaypoint_LEN);
#endif
}
