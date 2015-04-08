// MESSAGE sendText PACKING

#define MAVLINK_MSG_ID_sendText 8

typedef struct __mavlink_sendtext_t
{
 uint8_t Destination; ///< Device ID
 uint8_t Function; ///< Name of the function
 char Payload[20]; ///< Payload
} mavlink_sendtext_t;

#define MAVLINK_MSG_ID_sendText_LEN 22
#define MAVLINK_MSG_ID_8_LEN 22

#define MAVLINK_MSG_ID_sendText_CRC 176
#define MAVLINK_MSG_ID_8_CRC 176

#define MAVLINK_MSG_sendText_FIELD_PAYLOAD_LEN 20

#define MAVLINK_MESSAGE_INFO_sendText { \
	"sendText", \
	3, \
	{  { "Destination", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_sendtext_t, Destination) }, \
         { "Function", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_sendtext_t, Function) }, \
         { "Payload", NULL, MAVLINK_TYPE_CHAR, 20, 2, offsetof(mavlink_sendtext_t, Payload) }, \
         } \
}


/**
 * @brief Pack a sendtext message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param Destination Device ID
 * @param Function Name of the function
 * @param Payload Payload
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sendtext_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t Destination, uint8_t Function, const char *Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_sendText_LEN];
	_mav_put_uint8_t(buf, 0, Destination);
	_mav_put_uint8_t(buf, 1, Function);
	_mav_put_char_array(buf, 2, Payload, 20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_sendText_LEN);
#else
	mavlink_sendtext_t packet;
	packet.Destination = Destination;
	packet.Function = Function;
	mav_array_memcpy(packet.Payload, Payload, sizeof(char)*20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_sendText_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_sendText;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_sendText_LEN, MAVLINK_MSG_ID_sendText_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_sendText_LEN);
#endif
}

/**
 * @brief Pack a sendtext message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param Destination Device ID
 * @param Function Name of the function
 * @param Payload Payload
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sendtext_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t Destination,uint8_t Function,const char *Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_sendText_LEN];
	_mav_put_uint8_t(buf, 0, Destination);
	_mav_put_uint8_t(buf, 1, Function);
	_mav_put_char_array(buf, 2, Payload, 20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_sendText_LEN);
#else
	mavlink_sendtext_t packet;
	packet.Destination = Destination;
	packet.Function = Function;
	mav_array_memcpy(packet.Payload, Payload, sizeof(char)*20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_sendText_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_sendText;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_sendText_LEN, MAVLINK_MSG_ID_sendText_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_sendText_LEN);
#endif
}

/**
 * @brief Encode a sendtext struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sendtext C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sendtext_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sendtext_t* sendtext)
{
	return mavlink_msg_sendtext_pack(system_id, component_id, msg, sendtext->Destination, sendtext->Function, sendtext->Payload);
}

/**
 * @brief Encode a sendtext struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sendtext C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sendtext_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sendtext_t* sendtext)
{
	return mavlink_msg_sendtext_pack_chan(system_id, component_id, chan, msg, sendtext->Destination, sendtext->Function, sendtext->Payload);
}

/**
 * @brief Send a sendtext message
 * @param chan MAVLink channel to send the message
 *
 * @param Destination Device ID
 * @param Function Name of the function
 * @param Payload Payload
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sendtext_send(mavlink_channel_t chan, uint8_t Destination, uint8_t Function, const char *Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_sendText_LEN];
	_mav_put_uint8_t(buf, 0, Destination);
	_mav_put_uint8_t(buf, 1, Function);
	_mav_put_char_array(buf, 2, Payload, 20);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendText, buf, MAVLINK_MSG_ID_sendText_LEN, MAVLINK_MSG_ID_sendText_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendText, buf, MAVLINK_MSG_ID_sendText_LEN);
#endif
#else
	mavlink_sendtext_t packet;
	packet.Destination = Destination;
	packet.Function = Function;
	mav_array_memcpy(packet.Payload, Payload, sizeof(char)*20);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendText, (const char *)&packet, MAVLINK_MSG_ID_sendText_LEN, MAVLINK_MSG_ID_sendText_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendText, (const char *)&packet, MAVLINK_MSG_ID_sendText_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_sendText_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sendtext_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t Destination, uint8_t Function, const char *Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, Destination);
	_mav_put_uint8_t(buf, 1, Function);
	_mav_put_char_array(buf, 2, Payload, 20);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendText, buf, MAVLINK_MSG_ID_sendText_LEN, MAVLINK_MSG_ID_sendText_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendText, buf, MAVLINK_MSG_ID_sendText_LEN);
#endif
#else
	mavlink_sendtext_t *packet = (mavlink_sendtext_t *)msgbuf;
	packet->Destination = Destination;
	packet->Function = Function;
	mav_array_memcpy(packet->Payload, Payload, sizeof(char)*20);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendText, (const char *)packet, MAVLINK_MSG_ID_sendText_LEN, MAVLINK_MSG_ID_sendText_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendText, (const char *)packet, MAVLINK_MSG_ID_sendText_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE sendText UNPACKING


/**
 * @brief Get field Destination from sendtext message
 *
 * @return Device ID
 */
static inline uint8_t mavlink_msg_sendtext_get_Destination(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field Function from sendtext message
 *
 * @return Name of the function
 */
static inline uint8_t mavlink_msg_sendtext_get_Function(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field Payload from sendtext message
 *
 * @return Payload
 */
static inline uint16_t mavlink_msg_sendtext_get_Payload(const mavlink_message_t* msg, char *Payload)
{
	return _MAV_RETURN_char_array(msg, Payload, 20,  2);
}

/**
 * @brief Decode a sendtext message into a struct
 *
 * @param msg The message to decode
 * @param sendtext C-struct to decode the message contents into
 */
static inline void mavlink_msg_sendtext_decode(const mavlink_message_t* msg, mavlink_sendtext_t* sendtext)
{
#if MAVLINK_NEED_BYTE_SWAP
	sendtext->Destination = mavlink_msg_sendtext_get_Destination(msg);
	sendtext->Function = mavlink_msg_sendtext_get_Function(msg);
	mavlink_msg_sendtext_get_Payload(msg, sendtext->Payload);
#else
	memcpy(sendtext, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_sendText_LEN);
#endif
}
