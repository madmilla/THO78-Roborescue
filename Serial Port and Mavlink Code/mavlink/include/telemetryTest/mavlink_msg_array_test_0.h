// MESSAGE ARRAY_TEST_0 PACKING

#define MAVLINK_MSG_ID_ARRAY_TEST_0 150

typedef struct __mavlink_array_test_0_t
{
 uint8_t id; ///< Stub field
 char ar_c[32]; ///< Value array
} mavlink_array_test_0_t;

#define MAVLINK_MSG_ID_ARRAY_TEST_0_LEN 33
#define MAVLINK_MSG_ID_150_LEN 33

#define MAVLINK_MSG_ID_ARRAY_TEST_0_CRC 102
#define MAVLINK_MSG_ID_150_CRC 102

#define MAVLINK_MSG_ARRAY_TEST_0_FIELD_AR_C_LEN 32

#define MAVLINK_MESSAGE_INFO_ARRAY_TEST_0 { \
	"ARRAY_TEST_0", \
	2, \
	{  { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_array_test_0_t, id) }, \
         { "ar_c", NULL, MAVLINK_TYPE_CHAR, 32, 1, offsetof(mavlink_array_test_0_t, ar_c) }, \
         } \
}


/**
 * @brief Pack a array_test_0 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param id Stub field
 * @param ar_c Value array
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_array_test_0_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t id, const char *ar_c)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_ARRAY_TEST_0_LEN];
	_mav_put_uint8_t(buf, 0, id);
	_mav_put_char_array(buf, 1, ar_c, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ARRAY_TEST_0_LEN);
#else
	mavlink_array_test_0_t packet;
	packet.id = id;
	mav_array_memcpy(packet.ar_c, ar_c, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ARRAY_TEST_0_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_ARRAY_TEST_0;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ARRAY_TEST_0_LEN, MAVLINK_MSG_ID_ARRAY_TEST_0_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ARRAY_TEST_0_LEN);
#endif
}

/**
 * @brief Pack a array_test_0 message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param id Stub field
 * @param ar_c Value array
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_array_test_0_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t id,const char *ar_c)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_ARRAY_TEST_0_LEN];
	_mav_put_uint8_t(buf, 0, id);
	_mav_put_char_array(buf, 1, ar_c, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ARRAY_TEST_0_LEN);
#else
	mavlink_array_test_0_t packet;
	packet.id = id;
	mav_array_memcpy(packet.ar_c, ar_c, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ARRAY_TEST_0_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_ARRAY_TEST_0;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ARRAY_TEST_0_LEN, MAVLINK_MSG_ID_ARRAY_TEST_0_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ARRAY_TEST_0_LEN);
#endif
}

/**
 * @brief Encode a array_test_0 struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param array_test_0 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_array_test_0_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_array_test_0_t* array_test_0)
{
	return mavlink_msg_array_test_0_pack(system_id, component_id, msg, array_test_0->id, array_test_0->ar_c);
}

/**
 * @brief Encode a array_test_0 struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param array_test_0 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_array_test_0_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_array_test_0_t* array_test_0)
{
	return mavlink_msg_array_test_0_pack_chan(system_id, component_id, chan, msg, array_test_0->id, array_test_0->ar_c);
}

/**
 * @brief Send a array_test_0 message
 * @param chan MAVLink channel to send the message
 *
 * @param id Stub field
 * @param ar_c Value array
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_array_test_0_send(mavlink_channel_t chan, uint8_t id, const char *ar_c)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_ARRAY_TEST_0_LEN];
	_mav_put_uint8_t(buf, 0, id);
	_mav_put_char_array(buf, 1, ar_c, 32);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ARRAY_TEST_0, buf, MAVLINK_MSG_ID_ARRAY_TEST_0_LEN, MAVLINK_MSG_ID_ARRAY_TEST_0_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ARRAY_TEST_0, buf, MAVLINK_MSG_ID_ARRAY_TEST_0_LEN);
#endif
#else
	mavlink_array_test_0_t packet;
	packet.id = id;
	mav_array_memcpy(packet.ar_c, ar_c, sizeof(char)*32);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ARRAY_TEST_0, (const char *)&packet, MAVLINK_MSG_ID_ARRAY_TEST_0_LEN, MAVLINK_MSG_ID_ARRAY_TEST_0_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ARRAY_TEST_0, (const char *)&packet, MAVLINK_MSG_ID_ARRAY_TEST_0_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_ARRAY_TEST_0_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_array_test_0_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t id, const char *ar_c)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, id);
	_mav_put_char_array(buf, 1, ar_c, 32);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ARRAY_TEST_0, buf, MAVLINK_MSG_ID_ARRAY_TEST_0_LEN, MAVLINK_MSG_ID_ARRAY_TEST_0_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ARRAY_TEST_0, buf, MAVLINK_MSG_ID_ARRAY_TEST_0_LEN);
#endif
#else
	mavlink_array_test_0_t *packet = (mavlink_array_test_0_t *)msgbuf;
	packet->id = id;
	mav_array_memcpy(packet->ar_c, ar_c, sizeof(char)*32);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ARRAY_TEST_0, (const char *)packet, MAVLINK_MSG_ID_ARRAY_TEST_0_LEN, MAVLINK_MSG_ID_ARRAY_TEST_0_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ARRAY_TEST_0, (const char *)packet, MAVLINK_MSG_ID_ARRAY_TEST_0_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE ARRAY_TEST_0 UNPACKING


/**
 * @brief Get field id from array_test_0 message
 *
 * @return Stub field
 */
static inline uint8_t mavlink_msg_array_test_0_get_id(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field ar_c from array_test_0 message
 *
 * @return Value array
 */
static inline uint16_t mavlink_msg_array_test_0_get_ar_c(const mavlink_message_t* msg, char *ar_c)
{
	return _MAV_RETURN_char_array(msg, ar_c, 32,  1);
}

/**
 * @brief Decode a array_test_0 message into a struct
 *
 * @param msg The message to decode
 * @param array_test_0 C-struct to decode the message contents into
 */
static inline void mavlink_msg_array_test_0_decode(const mavlink_message_t* msg, mavlink_array_test_0_t* array_test_0)
{
#if MAVLINK_NEED_BYTE_SWAP
	array_test_0->id = mavlink_msg_array_test_0_get_id(msg);
	mavlink_msg_array_test_0_get_ar_c(msg, array_test_0->ar_c);
#else
	memcpy(array_test_0, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_ARRAY_TEST_0_LEN);
#endif
}
