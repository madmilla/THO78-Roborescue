// MESSAGE getData PACKING

#define MAVLINK_MSG_ID_getData 2

typedef struct __mavlink_getdata_t
{
 int16_t Payload[4]; ///< Payload
 uint8_t Destination; ///< Device ID
 uint8_t Function; ///< Name of the function
} mavlink_getdata_t;

#define MAVLINK_MSG_ID_getData_LEN 10
#define MAVLINK_MSG_ID_2_LEN 10

#define MAVLINK_MSG_ID_getData_CRC 16
#define MAVLINK_MSG_ID_2_CRC 16

#define MAVLINK_MSG_getData_FIELD_PAYLOAD_LEN 4

#define MAVLINK_MESSAGE_INFO_getData { \
	"getData", \
	3, \
	{  { "Payload", NULL, MAVLINK_TYPE_INT16_T, 4, 0, offsetof(mavlink_getdata_t, Payload) }, \
         { "Destination", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_getdata_t, Destination) }, \
         { "Function", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_getdata_t, Function) }, \
         } \
}


/**
 * @brief Pack a getdata message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param Destination Device ID
 * @param Function Name of the function
 * @param Payload Payload
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_getdata_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t Destination, uint8_t Function, const int16_t *Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_getData_LEN];
	_mav_put_uint8_t(buf, 8, Destination);
	_mav_put_uint8_t(buf, 9, Function);
	_mav_put_int16_t_array(buf, 0, Payload, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_getData_LEN);
#else
	mavlink_getdata_t packet;
	packet.Destination = Destination;
	packet.Function = Function;
	mav_array_memcpy(packet.Payload, Payload, sizeof(int16_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_getData_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_getData;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_getData_LEN, MAVLINK_MSG_ID_getData_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_getData_LEN);
#endif
}

/**
 * @brief Pack a getdata message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param Destination Device ID
 * @param Function Name of the function
 * @param Payload Payload
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_getdata_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t Destination,uint8_t Function,const int16_t *Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_getData_LEN];
	_mav_put_uint8_t(buf, 8, Destination);
	_mav_put_uint8_t(buf, 9, Function);
	_mav_put_int16_t_array(buf, 0, Payload, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_getData_LEN);
#else
	mavlink_getdata_t packet;
	packet.Destination = Destination;
	packet.Function = Function;
	mav_array_memcpy(packet.Payload, Payload, sizeof(int16_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_getData_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_getData;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_getData_LEN, MAVLINK_MSG_ID_getData_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_getData_LEN);
#endif
}

/**
 * @brief Encode a getdata struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param getdata C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_getdata_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_getdata_t* getdata)
{
	return mavlink_msg_getdata_pack(system_id, component_id, msg, getdata->Destination, getdata->Function, getdata->Payload);
}

/**
 * @brief Encode a getdata struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param getdata C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_getdata_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_getdata_t* getdata)
{
	return mavlink_msg_getdata_pack_chan(system_id, component_id, chan, msg, getdata->Destination, getdata->Function, getdata->Payload);
}

/**
 * @brief Send a getdata message
 * @param chan MAVLink channel to send the message
 *
 * @param Destination Device ID
 * @param Function Name of the function
 * @param Payload Payload
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_getdata_send(mavlink_channel_t chan, uint8_t Destination, uint8_t Function, const int16_t *Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_getData_LEN];
	_mav_put_uint8_t(buf, 8, Destination);
	_mav_put_uint8_t(buf, 9, Function);
	_mav_put_int16_t_array(buf, 0, Payload, 4);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_getData, buf, MAVLINK_MSG_ID_getData_LEN, MAVLINK_MSG_ID_getData_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_getData, buf, MAVLINK_MSG_ID_getData_LEN);
#endif
#else
	mavlink_getdata_t packet;
	packet.Destination = Destination;
	packet.Function = Function;
	mav_array_memcpy(packet.Payload, Payload, sizeof(int16_t)*4);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_getData, (const char *)&packet, MAVLINK_MSG_ID_getData_LEN, MAVLINK_MSG_ID_getData_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_getData, (const char *)&packet, MAVLINK_MSG_ID_getData_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_getData_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_getdata_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t Destination, uint8_t Function, const int16_t *Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 8, Destination);
	_mav_put_uint8_t(buf, 9, Function);
	_mav_put_int16_t_array(buf, 0, Payload, 4);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_getData, buf, MAVLINK_MSG_ID_getData_LEN, MAVLINK_MSG_ID_getData_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_getData, buf, MAVLINK_MSG_ID_getData_LEN);
#endif
#else
	mavlink_getdata_t *packet = (mavlink_getdata_t *)msgbuf;
	packet->Destination = Destination;
	packet->Function = Function;
	mav_array_memcpy(packet->Payload, Payload, sizeof(int16_t)*4);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_getData, (const char *)packet, MAVLINK_MSG_ID_getData_LEN, MAVLINK_MSG_ID_getData_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_getData, (const char *)packet, MAVLINK_MSG_ID_getData_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE getData UNPACKING


/**
 * @brief Get field Destination from getdata message
 *
 * @return Device ID
 */
static inline uint8_t mavlink_msg_getdata_get_Destination(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field Function from getdata message
 *
 * @return Name of the function
 */
static inline uint8_t mavlink_msg_getdata_get_Function(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field Payload from getdata message
 *
 * @return Payload
 */
static inline uint16_t mavlink_msg_getdata_get_Payload(const mavlink_message_t* msg, int16_t *Payload)
{
	return _MAV_RETURN_int16_t_array(msg, Payload, 4,  0);
}

/**
 * @brief Decode a getdata message into a struct
 *
 * @param msg The message to decode
 * @param getdata C-struct to decode the message contents into
 */
static inline void mavlink_msg_getdata_decode(const mavlink_message_t* msg, mavlink_getdata_t* getdata)
{
#if MAVLINK_NEED_BYTE_SWAP
	mavlink_msg_getdata_get_Payload(msg, getdata->Payload);
	getdata->Destination = mavlink_msg_getdata_get_Destination(msg);
	getdata->Function = mavlink_msg_getdata_get_Function(msg);
#else
	memcpy(getdata, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_getData_LEN);
#endif
}
