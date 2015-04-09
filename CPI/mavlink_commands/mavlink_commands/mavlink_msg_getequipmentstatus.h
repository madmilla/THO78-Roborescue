// MESSAGE getEquipmentStatus PACKING

#define MAVLINK_MSG_ID_getEquipmentStatus 2

typedef struct __mavlink_getequipmentstatus_t
{
 uint8_t Destination; ///< Device ID
 uint8_t Function; ///< Name of the function
 uint8_t Payload; ///< Payload
} mavlink_getequipmentstatus_t;

#define MAVLINK_MSG_ID_getEquipmentStatus_LEN 3
#define MAVLINK_MSG_ID_2_LEN 3

#define MAVLINK_MSG_ID_getEquipmentStatus_CRC 224
#define MAVLINK_MSG_ID_2_CRC 224



#define MAVLINK_MESSAGE_INFO_getEquipmentStatus { \
	"getEquipmentStatus", \
	3, \
	{  { "Destination", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_getequipmentstatus_t, Destination) }, \
         { "Function", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_getequipmentstatus_t, Function) }, \
         { "Payload", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_getequipmentstatus_t, Payload) }, \
         } \
}


/**
 * @brief Pack a getequipmentstatus message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param Destination Device ID
 * @param Function Name of the function
 * @param Payload Payload
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_getequipmentstatus_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t Destination, uint8_t Function, uint8_t Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_getEquipmentStatus_LEN];
	_mav_put_uint8_t(buf, 0, Destination);
	_mav_put_uint8_t(buf, 1, Function);
	_mav_put_uint8_t(buf, 2, Payload);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_getEquipmentStatus_LEN);
#else
	mavlink_getequipmentstatus_t packet;
	packet.Destination = Destination;
	packet.Function = Function;
	packet.Payload = Payload;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_getEquipmentStatus_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_getEquipmentStatus;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_getEquipmentStatus_LEN, MAVLINK_MSG_ID_getEquipmentStatus_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_getEquipmentStatus_LEN);
#endif
}

/**
 * @brief Pack a getequipmentstatus message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param Destination Device ID
 * @param Function Name of the function
 * @param Payload Payload
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_getequipmentstatus_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t Destination,uint8_t Function,uint8_t Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_getEquipmentStatus_LEN];
	_mav_put_uint8_t(buf, 0, Destination);
	_mav_put_uint8_t(buf, 1, Function);
	_mav_put_uint8_t(buf, 2, Payload);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_getEquipmentStatus_LEN);
#else
	mavlink_getequipmentstatus_t packet;
	packet.Destination = Destination;
	packet.Function = Function;
	packet.Payload = Payload;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_getEquipmentStatus_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_getEquipmentStatus;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_getEquipmentStatus_LEN, MAVLINK_MSG_ID_getEquipmentStatus_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_getEquipmentStatus_LEN);
#endif
}

/**
 * @brief Encode a getequipmentstatus struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param getequipmentstatus C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_getequipmentstatus_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_getequipmentstatus_t* getequipmentstatus)
{
	return mavlink_msg_getequipmentstatus_pack(system_id, component_id, msg, getequipmentstatus->Destination, getequipmentstatus->Function, getequipmentstatus->Payload);
}

/**
 * @brief Encode a getequipmentstatus struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param getequipmentstatus C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_getequipmentstatus_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_getequipmentstatus_t* getequipmentstatus)
{
	return mavlink_msg_getequipmentstatus_pack_chan(system_id, component_id, chan, msg, getequipmentstatus->Destination, getequipmentstatus->Function, getequipmentstatus->Payload);
}

/**
 * @brief Send a getequipmentstatus message
 * @param chan MAVLink channel to send the message
 *
 * @param Destination Device ID
 * @param Function Name of the function
 * @param Payload Payload
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_getequipmentstatus_send(mavlink_channel_t chan, uint8_t Destination, uint8_t Function, uint8_t Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_getEquipmentStatus_LEN];
	_mav_put_uint8_t(buf, 0, Destination);
	_mav_put_uint8_t(buf, 1, Function);
	_mav_put_uint8_t(buf, 2, Payload);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_getEquipmentStatus, buf, MAVLINK_MSG_ID_getEquipmentStatus_LEN, MAVLINK_MSG_ID_getEquipmentStatus_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_getEquipmentStatus, buf, MAVLINK_MSG_ID_getEquipmentStatus_LEN);
#endif
#else
	mavlink_getequipmentstatus_t packet;
	packet.Destination = Destination;
	packet.Function = Function;
	packet.Payload = Payload;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_getEquipmentStatus, (const char *)&packet, MAVLINK_MSG_ID_getEquipmentStatus_LEN, MAVLINK_MSG_ID_getEquipmentStatus_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_getEquipmentStatus, (const char *)&packet, MAVLINK_MSG_ID_getEquipmentStatus_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_getEquipmentStatus_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_getequipmentstatus_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t Destination, uint8_t Function, uint8_t Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, Destination);
	_mav_put_uint8_t(buf, 1, Function);
	_mav_put_uint8_t(buf, 2, Payload);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_getEquipmentStatus, buf, MAVLINK_MSG_ID_getEquipmentStatus_LEN, MAVLINK_MSG_ID_getEquipmentStatus_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_getEquipmentStatus, buf, MAVLINK_MSG_ID_getEquipmentStatus_LEN);
#endif
#else
	mavlink_getequipmentstatus_t *packet = (mavlink_getequipmentstatus_t *)msgbuf;
	packet->Destination = Destination;
	packet->Function = Function;
	packet->Payload = Payload;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_getEquipmentStatus, (const char *)packet, MAVLINK_MSG_ID_getEquipmentStatus_LEN, MAVLINK_MSG_ID_getEquipmentStatus_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_getEquipmentStatus, (const char *)packet, MAVLINK_MSG_ID_getEquipmentStatus_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE getEquipmentStatus UNPACKING


/**
 * @brief Get field Destination from getequipmentstatus message
 *
 * @return Device ID
 */
static inline uint8_t mavlink_msg_getequipmentstatus_get_Destination(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field Function from getequipmentstatus message
 *
 * @return Name of the function
 */
static inline uint8_t mavlink_msg_getequipmentstatus_get_Function(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field Payload from getequipmentstatus message
 *
 * @return Payload
 */
static inline uint8_t mavlink_msg_getequipmentstatus_get_Payload(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a getequipmentstatus message into a struct
 *
 * @param msg The message to decode
 * @param getequipmentstatus C-struct to decode the message contents into
 */
static inline void mavlink_msg_getequipmentstatus_decode(const mavlink_message_t* msg, mavlink_getequipmentstatus_t* getequipmentstatus)
{
#if MAVLINK_NEED_BYTE_SWAP
	getequipmentstatus->Destination = mavlink_msg_getequipmentstatus_get_Destination(msg);
	getequipmentstatus->Function = mavlink_msg_getequipmentstatus_get_Function(msg);
	getequipmentstatus->Payload = mavlink_msg_getequipmentstatus_get_Payload(msg);
#else
	memcpy(getequipmentstatus, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_getEquipmentStatus_LEN);
#endif
}
