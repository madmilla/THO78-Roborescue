// MESSAGE LIDAR_LINE PACKING

#define MAVLINK_MSG_ID_LIDAR_LINE 180

typedef struct __mavlink_lidar_line_t
{
 int32_t start_X; ///< The starting X-coordinate of the line
 int32_t start_Y; ///< The starting Y-coordinate of the line
 int32_t end_X; ///< The ending X-coordinate of the line
 int32_t end_Y; ///< The ending Y-coordinate of the line
 uint8_t last_line; ///< 0 if this line is the last in a series. Anything other if not
} mavlink_lidar_line_t;

#define MAVLINK_MSG_ID_LIDAR_LINE_LEN 17
#define MAVLINK_MSG_ID_180_LEN 17

#define MAVLINK_MSG_ID_LIDAR_LINE_CRC 224
#define MAVLINK_MSG_ID_180_CRC 224



#define MAVLINK_MESSAGE_INFO_LIDAR_LINE { \
	"LIDAR_LINE", \
	5, \
	{  { "start_X", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_lidar_line_t, start_X) }, \
         { "start_Y", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_lidar_line_t, start_Y) }, \
         { "end_X", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_lidar_line_t, end_X) }, \
         { "end_Y", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_lidar_line_t, end_Y) }, \
         { "last_line", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_lidar_line_t, last_line) }, \
         } \
}


/**
 * @brief Pack a lidar_line message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param start_X The starting X-coordinate of the line
 * @param start_Y The starting Y-coordinate of the line
 * @param end_X The ending X-coordinate of the line
 * @param end_Y The ending Y-coordinate of the line
 * @param last_line 0 if this line is the last in a series. Anything other if not
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lidar_line_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       int32_t start_X, int32_t start_Y, int32_t end_X, int32_t end_Y, uint8_t last_line)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_LIDAR_LINE_LEN];
	_mav_put_int32_t(buf, 0, start_X);
	_mav_put_int32_t(buf, 4, start_Y);
	_mav_put_int32_t(buf, 8, end_X);
	_mav_put_int32_t(buf, 12, end_Y);
	_mav_put_uint8_t(buf, 16, last_line);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LIDAR_LINE_LEN);
#else
	mavlink_lidar_line_t packet;
	packet.start_X = start_X;
	packet.start_Y = start_Y;
	packet.end_X = end_X;
	packet.end_Y = end_Y;
	packet.last_line = last_line;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LIDAR_LINE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_LIDAR_LINE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_LIDAR_LINE_LEN, MAVLINK_MSG_ID_LIDAR_LINE_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_LIDAR_LINE_LEN);
#endif
}

/**
 * @brief Pack a lidar_line message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param start_X The starting X-coordinate of the line
 * @param start_Y The starting Y-coordinate of the line
 * @param end_X The ending X-coordinate of the line
 * @param end_Y The ending Y-coordinate of the line
 * @param last_line 0 if this line is the last in a series. Anything other if not
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lidar_line_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           int32_t start_X,int32_t start_Y,int32_t end_X,int32_t end_Y,uint8_t last_line)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_LIDAR_LINE_LEN];
	_mav_put_int32_t(buf, 0, start_X);
	_mav_put_int32_t(buf, 4, start_Y);
	_mav_put_int32_t(buf, 8, end_X);
	_mav_put_int32_t(buf, 12, end_Y);
	_mav_put_uint8_t(buf, 16, last_line);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LIDAR_LINE_LEN);
#else
	mavlink_lidar_line_t packet;
	packet.start_X = start_X;
	packet.start_Y = start_Y;
	packet.end_X = end_X;
	packet.end_Y = end_Y;
	packet.last_line = last_line;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LIDAR_LINE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_LIDAR_LINE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_LIDAR_LINE_LEN, MAVLINK_MSG_ID_LIDAR_LINE_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_LIDAR_LINE_LEN);
#endif
}

/**
 * @brief Encode a lidar_line struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param lidar_line C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lidar_line_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_lidar_line_t* lidar_line)
{
	return mavlink_msg_lidar_line_pack(system_id, component_id, msg, lidar_line->start_X, lidar_line->start_Y, lidar_line->end_X, lidar_line->end_Y, lidar_line->last_line);
}

/**
 * @brief Encode a lidar_line struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param lidar_line C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lidar_line_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_lidar_line_t* lidar_line)
{
	return mavlink_msg_lidar_line_pack_chan(system_id, component_id, chan, msg, lidar_line->start_X, lidar_line->start_Y, lidar_line->end_X, lidar_line->end_Y, lidar_line->last_line);
}

/**
 * @brief Send a lidar_line message
 * @param chan MAVLink channel to send the message
 *
 * @param start_X The starting X-coordinate of the line
 * @param start_Y The starting Y-coordinate of the line
 * @param end_X The ending X-coordinate of the line
 * @param end_Y The ending Y-coordinate of the line
 * @param last_line 0 if this line is the last in a series. Anything other if not
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_lidar_line_send(mavlink_channel_t chan, int32_t start_X, int32_t start_Y, int32_t end_X, int32_t end_Y, uint8_t last_line)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_LIDAR_LINE_LEN];
	_mav_put_int32_t(buf, 0, start_X);
	_mav_put_int32_t(buf, 4, start_Y);
	_mav_put_int32_t(buf, 8, end_X);
	_mav_put_int32_t(buf, 12, end_Y);
	_mav_put_uint8_t(buf, 16, last_line);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LIDAR_LINE, buf, MAVLINK_MSG_ID_LIDAR_LINE_LEN, MAVLINK_MSG_ID_LIDAR_LINE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LIDAR_LINE, buf, MAVLINK_MSG_ID_LIDAR_LINE_LEN);
#endif
#else
	mavlink_lidar_line_t packet;
	packet.start_X = start_X;
	packet.start_Y = start_Y;
	packet.end_X = end_X;
	packet.end_Y = end_Y;
	packet.last_line = last_line;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LIDAR_LINE, (const char *)&packet, MAVLINK_MSG_ID_LIDAR_LINE_LEN, MAVLINK_MSG_ID_LIDAR_LINE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LIDAR_LINE, (const char *)&packet, MAVLINK_MSG_ID_LIDAR_LINE_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_LIDAR_LINE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_lidar_line_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int32_t start_X, int32_t start_Y, int32_t end_X, int32_t end_Y, uint8_t last_line)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_int32_t(buf, 0, start_X);
	_mav_put_int32_t(buf, 4, start_Y);
	_mav_put_int32_t(buf, 8, end_X);
	_mav_put_int32_t(buf, 12, end_Y);
	_mav_put_uint8_t(buf, 16, last_line);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LIDAR_LINE, buf, MAVLINK_MSG_ID_LIDAR_LINE_LEN, MAVLINK_MSG_ID_LIDAR_LINE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LIDAR_LINE, buf, MAVLINK_MSG_ID_LIDAR_LINE_LEN);
#endif
#else
	mavlink_lidar_line_t *packet = (mavlink_lidar_line_t *)msgbuf;
	packet->start_X = start_X;
	packet->start_Y = start_Y;
	packet->end_X = end_X;
	packet->end_Y = end_Y;
	packet->last_line = last_line;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LIDAR_LINE, (const char *)packet, MAVLINK_MSG_ID_LIDAR_LINE_LEN, MAVLINK_MSG_ID_LIDAR_LINE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LIDAR_LINE, (const char *)packet, MAVLINK_MSG_ID_LIDAR_LINE_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE LIDAR_LINE UNPACKING


/**
 * @brief Get field start_X from lidar_line message
 *
 * @return The starting X-coordinate of the line
 */
static inline int32_t mavlink_msg_lidar_line_get_start_X(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field start_Y from lidar_line message
 *
 * @return The starting Y-coordinate of the line
 */
static inline int32_t mavlink_msg_lidar_line_get_start_Y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field end_X from lidar_line message
 *
 * @return The ending X-coordinate of the line
 */
static inline int32_t mavlink_msg_lidar_line_get_end_X(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field end_Y from lidar_line message
 *
 * @return The ending Y-coordinate of the line
 */
static inline int32_t mavlink_msg_lidar_line_get_end_Y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field last_line from lidar_line message
 *
 * @return 0 if this line is the last in a series. Anything other if not
 */
static inline uint8_t mavlink_msg_lidar_line_get_last_line(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Decode a lidar_line message into a struct
 *
 * @param msg The message to decode
 * @param lidar_line C-struct to decode the message contents into
 */
static inline void mavlink_msg_lidar_line_decode(const mavlink_message_t* msg, mavlink_lidar_line_t* lidar_line)
{
#if MAVLINK_NEED_BYTE_SWAP
	lidar_line->start_X = mavlink_msg_lidar_line_get_start_X(msg);
	lidar_line->start_Y = mavlink_msg_lidar_line_get_start_Y(msg);
	lidar_line->end_X = mavlink_msg_lidar_line_get_end_X(msg);
	lidar_line->end_Y = mavlink_msg_lidar_line_get_end_Y(msg);
	lidar_line->last_line = mavlink_msg_lidar_line_get_last_line(msg);
#else
	memcpy(lidar_line, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_LIDAR_LINE_LEN);
#endif
}
