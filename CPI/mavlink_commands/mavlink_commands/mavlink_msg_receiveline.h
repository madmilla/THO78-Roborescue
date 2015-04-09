// MESSAGE receiveLine PACKING

#define MAVLINK_MSG_ID_receiveLine 13

typedef struct __mavlink_receiveline_t
{
 int16_t Payload[4]; ///< Payload
 uint8_t Destination; ///< Device ID
 uint8_t Function; ///< Name of the function
} mavlink_receiveline_t;

#define MAVLINK_MSG_ID_receiveLine_LEN 10
#define MAVLINK_MSG_ID_13_LEN 10

#define MAVLINK_MSG_ID_receiveLine_CRC 253
#define MAVLINK_MSG_ID_13_CRC 253

#define MAVLINK_MSG_receiveLine_FIELD_PAYLOAD_LEN 4

#define MAVLINK_MESSAGE_INFO_receiveLine { \
	"receiveLine", \
	3, \
	{  { "Payload", NULL, MAVLINK_TYPE_INT16_T, 4, 0, offsetof(mavlink_receiveline_t, Payload) }, \
         { "Destination", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_receiveline_t, Destination) }, \
         { "Function", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_receiveline_t, Function) }, \
         } \
}


/**
 * @brief Pack a receiveline message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param Destination Device ID
 * @param Function Name of the function
 * @param Payload Payload
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_receiveline_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t Destination, uint8_t Function, const int16_t *Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_receiveLine_LEN];
	_mav_put_uint8_t(buf, 8, Destination);
	_mav_put_uint8_t(buf, 9, Function);
	_mav_put_int16_t_array(buf, 0, Payload, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_receiveLine_LEN);
#else
	mavlink_receiveline_t packet;
	packet.Destination = Destination;
	packet.Function = Function;
	mav_array_memcpy(packet.Payload, Payload, sizeof(int16_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_receiveLine_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_receiveLine;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_receiveLine_LEN, MAVLINK_MSG_ID_receiveLine_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_receiveLine_LEN);
#endif
}

/**
 * @brief Pack a receiveline message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param Destination Device ID
 * @param Function Name of the function
 * @param Payload Payload
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_receiveline_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t Destination,uint8_t Function,const int16_t *Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_receiveLine_LEN];
	_mav_put_uint8_t(buf, 8, Destination);
	_mav_put_uint8_t(buf, 9, Function);
	_mav_put_int16_t_array(buf, 0, Payload, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_receiveLine_LEN);
#else
	mavlink_receiveline_t packet;
	packet.Destination = Destination;
	packet.Function = Function;
	mav_array_memcpy(packet.Payload, Payload, sizeof(int16_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_receiveLine_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_receiveLine;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_receiveLine_LEN, MAVLINK_MSG_ID_receiveLine_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_receiveLine_LEN);
#endif
}

/**
 * @brief Encode a receiveline struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param receiveline C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_receiveline_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_receiveline_t* receiveline)
{
	return mavlink_msg_receiveline_pack(system_id, component_id, msg, receiveline->Destination, receiveline->Function, receiveline->Payload);
}

/**
 * @brief Encode a receiveline struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param receiveline C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_receiveline_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_receiveline_t* receiveline)
{
	return mavlink_msg_receiveline_pack_chan(system_id, component_id, chan, msg, receiveline->Destination, receiveline->Function, receiveline->Payload);
}

/**
 * @brief Send a receiveline message
 * @param chan MAVLink channel to send the message
 *
 * @param Destination Device ID
 * @param Function Name of the function
 * @param Payload Payload
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_receiveline_send(mavlink_channel_t chan, uint8_t Destination, uint8_t Function, const int16_t *Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_receiveLine_LEN];
	_mav_put_uint8_t(buf, 8, Destination);
	_mav_put_uint8_t(buf, 9, Function);
	_mav_put_int16_t_array(buf, 0, Payload, 4);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_receiveLine, buf, MAVLINK_MSG_ID_receiveLine_LEN, MAVLINK_MSG_ID_receiveLine_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_receiveLine, buf, MAVLINK_MSG_ID_receiveLine_LEN);
#endif
#else
	mavlink_receiveline_t packet;
	packet.Destination = Destination;
	packet.Function = Function;
	mav_array_memcpy(packet.Payload, Payload, sizeof(int16_t)*4);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_receiveLine, (const char *)&packet, MAVLINK_MSG_ID_receiveLine_LEN, MAVLINK_MSG_ID_receiveLine_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_receiveLine, (const char *)&packet, MAVLINK_MSG_ID_receiveLine_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_receiveLine_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_receiveline_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t Destination, uint8_t Function, const int16_t *Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 8, Destination);
	_mav_put_uint8_t(buf, 9, Function);
	_mav_put_int16_t_array(buf, 0, Payload, 4);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_receiveLine, buf, MAVLINK_MSG_ID_receiveLine_LEN, MAVLINK_MSG_ID_receiveLine_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_receiveLine, buf, MAVLINK_MSG_ID_receiveLine_LEN);
#endif
#else
	mavlink_receiveline_t *packet = (mavlink_receiveline_t *)msgbuf;
	packet->Destination = Destination;
	packet->Function = Function;
	mav_array_memcpy(packet->Payload, Payload, sizeof(int16_t)*4);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_receiveLine, (const char *)packet, MAVLINK_MSG_ID_receiveLine_LEN, MAVLINK_MSG_ID_receiveLine_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_receiveLine, (const char *)packet, MAVLINK_MSG_ID_receiveLine_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE receiveLine UNPACKING


/**
 * @brief Get field Destination from receiveline message
 *
 * @return Device ID
 */
static inline uint8_t mavlink_msg_receiveline_get_Destination(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field Function from receiveline message
 *
 * @return Name of the function
 */
static inline uint8_t mavlink_msg_receiveline_get_Function(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field Payload from receiveline message
 *
 * @return Payload
 */
static inline uint16_t mavlink_msg_receiveline_get_Payload(const mavlink_message_t* msg, int16_t *Payload)
{
	return _MAV_RETURN_int16_t_array(msg, Payload, 4,  0);
}

/**
 * @brief Decode a receiveline message into a struct
 *
 * @param msg The message to decode
 * @param receiveline C-struct to decode the message contents into
 */
static inline void mavlink_msg_receiveline_decode(const mavlink_message_t* msg, mavlink_receiveline_t* receiveline)
{
#if MAVLINK_NEED_BYTE_SWAP
	mavlink_msg_receiveline_get_Payload(msg, receiveline->Payload);
	receiveline->Destination = mavlink_msg_receiveline_get_Destination(msg);
	receiveline->Function = mavlink_msg_receiveline_get_Function(msg);
#else
	memcpy(receiveline, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_receiveLine_LEN);
#endif
}
