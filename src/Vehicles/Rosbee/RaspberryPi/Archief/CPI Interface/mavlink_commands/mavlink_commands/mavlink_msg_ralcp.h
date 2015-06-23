// MESSAGE RALCP PACKING

#define MAVLINK_MSG_ID_RALCP 0

typedef struct __mavlink_ralcp_t
{
 uint64_t Payload; ///< Payload
 uint8_t Destination; ///< Device ID
 uint8_t Function; ///< Name of the function
} mavlink_ralcp_t;

#define MAVLINK_MSG_ID_RALCP_LEN 10
#define MAVLINK_MSG_ID_0_LEN 10

#define MAVLINK_MSG_ID_RALCP_CRC 185
#define MAVLINK_MSG_ID_0_CRC 185



#define MAVLINK_MESSAGE_INFO_RALCP { \
	"RALCP", \
	3, \
	{  { "Payload", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_ralcp_t, Payload) }, \
         { "Destination", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_ralcp_t, Destination) }, \
         { "Function", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_ralcp_t, Function) }, \
         } \
}


/**
 * @brief Pack a ralcp message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param Destination Device ID
 * @param Function Name of the function
 * @param Payload Payload
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ralcp_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t Destination, uint8_t Function, uint64_t Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_RALCP_LEN];
	_mav_put_uint64_t(buf, 0, Payload);
	_mav_put_uint8_t(buf, 8, Destination);
	_mav_put_uint8_t(buf, 9, Function);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RALCP_LEN);
#else
	mavlink_ralcp_t packet;
	packet.Payload = Payload;
	packet.Destination = Destination;
	packet.Function = Function;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RALCP_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_RALCP;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RALCP_LEN, MAVLINK_MSG_ID_RALCP_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RALCP_LEN);
#endif
}

/**
 * @brief Pack a ralcp message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param Destination Device ID
 * @param Function Name of the function
 * @param Payload Payload
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ralcp_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t Destination,uint8_t Function,uint64_t Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_RALCP_LEN];
	_mav_put_uint64_t(buf, 0, Payload);
	_mav_put_uint8_t(buf, 8, Destination);
	_mav_put_uint8_t(buf, 9, Function);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RALCP_LEN);
#else
	mavlink_ralcp_t packet;
	packet.Payload = Payload;
	packet.Destination = Destination;
	packet.Function = Function;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RALCP_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_RALCP;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RALCP_LEN, MAVLINK_MSG_ID_RALCP_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RALCP_LEN);
#endif
}

/**
 * @brief Encode a ralcp struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ralcp C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ralcp_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ralcp_t* ralcp)
{
	return mavlink_msg_ralcp_pack(system_id, component_id, msg, ralcp->Destination, ralcp->Function, ralcp->Payload);
}

/**
 * @brief Encode a ralcp struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ralcp C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ralcp_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ralcp_t* ralcp)
{
	return mavlink_msg_ralcp_pack_chan(system_id, component_id, chan, msg, ralcp->Destination, ralcp->Function, ralcp->Payload);
}

/**
 * @brief Send a ralcp message
 * @param chan MAVLink channel to send the message
 *
 * @param Destination Device ID
 * @param Function Name of the function
 * @param Payload Payload
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ralcp_send(mavlink_channel_t chan, uint8_t Destination, uint8_t Function, uint64_t Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_RALCP_LEN];
	_mav_put_uint64_t(buf, 0, Payload);
	_mav_put_uint8_t(buf, 8, Destination);
	_mav_put_uint8_t(buf, 9, Function);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RALCP, buf, MAVLINK_MSG_ID_RALCP_LEN, MAVLINK_MSG_ID_RALCP_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RALCP, buf, MAVLINK_MSG_ID_RALCP_LEN);
#endif
#else
	mavlink_ralcp_t packet;
	packet.Payload = Payload;
	packet.Destination = Destination;
	packet.Function = Function;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RALCP, (const char *)&packet, MAVLINK_MSG_ID_RALCP_LEN, MAVLINK_MSG_ID_RALCP_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RALCP, (const char *)&packet, MAVLINK_MSG_ID_RALCP_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_RALCP_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ralcp_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t Destination, uint8_t Function, uint64_t Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, Payload);
	_mav_put_uint8_t(buf, 8, Destination);
	_mav_put_uint8_t(buf, 9, Function);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RALCP, buf, MAVLINK_MSG_ID_RALCP_LEN, MAVLINK_MSG_ID_RALCP_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RALCP, buf, MAVLINK_MSG_ID_RALCP_LEN);
#endif
#else
	mavlink_ralcp_t *packet = (mavlink_ralcp_t *)msgbuf;
	packet->Payload = Payload;
	packet->Destination = Destination;
	packet->Function = Function;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RALCP, (const char *)packet, MAVLINK_MSG_ID_RALCP_LEN, MAVLINK_MSG_ID_RALCP_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RALCP, (const char *)packet, MAVLINK_MSG_ID_RALCP_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE RALCP UNPACKING


/**
 * @brief Get field Destination from ralcp message
 *
 * @return Device ID
 */
static inline uint8_t mavlink_msg_ralcp_get_Destination(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field Function from ralcp message
 *
 * @return Name of the function
 */
static inline uint8_t mavlink_msg_ralcp_get_Function(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field Payload from ralcp message
 *
 * @return Payload
 */
static inline uint64_t mavlink_msg_ralcp_get_Payload(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Decode a ralcp message into a struct
 *
 * @param msg The message to decode
 * @param ralcp C-struct to decode the message contents into
 */
static inline void mavlink_msg_ralcp_decode(const mavlink_message_t* msg, mavlink_ralcp_t* ralcp)
{
#if MAVLINK_NEED_BYTE_SWAP
	ralcp->Payload = mavlink_msg_ralcp_get_Payload(msg);
	ralcp->Destination = mavlink_msg_ralcp_get_Destination(msg);
	ralcp->Function = mavlink_msg_ralcp_get_Function(msg);
#else
	memcpy(ralcp, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_RALCP_LEN);
#endif
}
