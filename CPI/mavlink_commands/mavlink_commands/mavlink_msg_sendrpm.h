// MESSAGE sendRPM PACKING

#define MAVLINK_MSG_ID_sendRPM 15

typedef struct __mavlink_sendrpm_t
{
 uint8_t Destination; ///< Device ID
 uint8_t Function; ///< Name of the function
 int8_t Payload; ///< Payload
} mavlink_sendrpm_t;

#define MAVLINK_MSG_ID_sendRPM_LEN 3
#define MAVLINK_MSG_ID_15_LEN 3

#define MAVLINK_MSG_ID_sendRPM_CRC 26
#define MAVLINK_MSG_ID_15_CRC 26



#define MAVLINK_MESSAGE_INFO_sendRPM { \
	"sendRPM", \
	3, \
	{  { "Destination", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_sendrpm_t, Destination) }, \
         { "Function", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_sendrpm_t, Function) }, \
         { "Payload", NULL, MAVLINK_TYPE_INT8_T, 0, 2, offsetof(mavlink_sendrpm_t, Payload) }, \
         } \
}


/**
 * @brief Pack a sendrpm message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param Destination Device ID
 * @param Function Name of the function
 * @param Payload Payload
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sendrpm_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t Destination, uint8_t Function, int8_t Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_sendRPM_LEN];
	_mav_put_uint8_t(buf, 0, Destination);
	_mav_put_uint8_t(buf, 1, Function);
	_mav_put_int8_t(buf, 2, Payload);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_sendRPM_LEN);
#else
	mavlink_sendrpm_t packet;
	packet.Destination = Destination;
	packet.Function = Function;
	packet.Payload = Payload;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_sendRPM_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_sendRPM;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_sendRPM_LEN, MAVLINK_MSG_ID_sendRPM_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_sendRPM_LEN);
#endif
}

/**
 * @brief Pack a sendrpm message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param Destination Device ID
 * @param Function Name of the function
 * @param Payload Payload
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sendrpm_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t Destination,uint8_t Function,int8_t Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_sendRPM_LEN];
	_mav_put_uint8_t(buf, 0, Destination);
	_mav_put_uint8_t(buf, 1, Function);
	_mav_put_int8_t(buf, 2, Payload);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_sendRPM_LEN);
#else
	mavlink_sendrpm_t packet;
	packet.Destination = Destination;
	packet.Function = Function;
	packet.Payload = Payload;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_sendRPM_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_sendRPM;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_sendRPM_LEN, MAVLINK_MSG_ID_sendRPM_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_sendRPM_LEN);
#endif
}

/**
 * @brief Encode a sendrpm struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sendrpm C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sendrpm_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sendrpm_t* sendrpm)
{
	return mavlink_msg_sendrpm_pack(system_id, component_id, msg, sendrpm->Destination, sendrpm->Function, sendrpm->Payload);
}

/**
 * @brief Encode a sendrpm struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sendrpm C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sendrpm_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sendrpm_t* sendrpm)
{
	return mavlink_msg_sendrpm_pack_chan(system_id, component_id, chan, msg, sendrpm->Destination, sendrpm->Function, sendrpm->Payload);
}

/**
 * @brief Send a sendrpm message
 * @param chan MAVLink channel to send the message
 *
 * @param Destination Device ID
 * @param Function Name of the function
 * @param Payload Payload
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sendrpm_send(mavlink_channel_t chan, uint8_t Destination, uint8_t Function, int8_t Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_sendRPM_LEN];
	_mav_put_uint8_t(buf, 0, Destination);
	_mav_put_uint8_t(buf, 1, Function);
	_mav_put_int8_t(buf, 2, Payload);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendRPM, buf, MAVLINK_MSG_ID_sendRPM_LEN, MAVLINK_MSG_ID_sendRPM_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendRPM, buf, MAVLINK_MSG_ID_sendRPM_LEN);
#endif
#else
	mavlink_sendrpm_t packet;
	packet.Destination = Destination;
	packet.Function = Function;
	packet.Payload = Payload;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendRPM, (const char *)&packet, MAVLINK_MSG_ID_sendRPM_LEN, MAVLINK_MSG_ID_sendRPM_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendRPM, (const char *)&packet, MAVLINK_MSG_ID_sendRPM_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_sendRPM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sendrpm_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t Destination, uint8_t Function, int8_t Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, Destination);
	_mav_put_uint8_t(buf, 1, Function);
	_mav_put_int8_t(buf, 2, Payload);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendRPM, buf, MAVLINK_MSG_ID_sendRPM_LEN, MAVLINK_MSG_ID_sendRPM_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendRPM, buf, MAVLINK_MSG_ID_sendRPM_LEN);
#endif
#else
	mavlink_sendrpm_t *packet = (mavlink_sendrpm_t *)msgbuf;
	packet->Destination = Destination;
	packet->Function = Function;
	packet->Payload = Payload;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendRPM, (const char *)packet, MAVLINK_MSG_ID_sendRPM_LEN, MAVLINK_MSG_ID_sendRPM_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendRPM, (const char *)packet, MAVLINK_MSG_ID_sendRPM_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE sendRPM UNPACKING


/**
 * @brief Get field Destination from sendrpm message
 *
 * @return Device ID
 */
static inline uint8_t mavlink_msg_sendrpm_get_Destination(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field Function from sendrpm message
 *
 * @return Name of the function
 */
static inline uint8_t mavlink_msg_sendrpm_get_Function(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field Payload from sendrpm message
 *
 * @return Payload
 */
static inline int8_t mavlink_msg_sendrpm_get_Payload(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int8_t(msg,  2);
}

/**
 * @brief Decode a sendrpm message into a struct
 *
 * @param msg The message to decode
 * @param sendrpm C-struct to decode the message contents into
 */
static inline void mavlink_msg_sendrpm_decode(const mavlink_message_t* msg, mavlink_sendrpm_t* sendrpm)
{
#if MAVLINK_NEED_BYTE_SWAP
	sendrpm->Destination = mavlink_msg_sendrpm_get_Destination(msg);
	sendrpm->Function = mavlink_msg_sendrpm_get_Function(msg);
	sendrpm->Payload = mavlink_msg_sendrpm_get_Payload(msg);
#else
	memcpy(sendrpm, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_sendRPM_LEN);
#endif
}
