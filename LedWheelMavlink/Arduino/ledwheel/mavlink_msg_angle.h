// MESSAGE angle PACKING

#define MAVLINK_MSG_ID_angle 1

typedef struct __mavlink_angle_t
{
 float angle; /*< */
} mavlink_angle_t;

#define MAVLINK_MSG_ID_angle_LEN 4
#define MAVLINK_MSG_ID_1_LEN 4

#define MAVLINK_MSG_ID_angle_CRC 165
#define MAVLINK_MSG_ID_1_CRC 165



#define MAVLINK_MESSAGE_INFO_angle { \
	"angle", \
	1, \
	{  { "angle", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_angle_t, angle) }, \
         } \
}


/**
 * @brief Pack a angle message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param angle 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_angle_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       float angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_angle_LEN];
	_mav_put_float(buf, 0, angle);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_angle_LEN);
#else
	mavlink_angle_t packet;
	packet.angle = angle;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_angle_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_angle;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_angle_LEN, MAVLINK_MSG_ID_angle_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_angle_LEN);
#endif
}

/**
 * @brief Pack a angle message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param angle 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_angle_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_angle_LEN];
	_mav_put_float(buf, 0, angle);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_angle_LEN);
#else
	mavlink_angle_t packet;
	packet.angle = angle;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_angle_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_angle;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_angle_LEN, MAVLINK_MSG_ID_angle_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_angle_LEN);
#endif
}

/**
 * @brief Encode a angle struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param angle C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_angle_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_angle_t* angle)
{
	return mavlink_msg_angle_pack(system_id, component_id, msg, angle->angle);
}

/**
 * @brief Encode a angle struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param angle C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_angle_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_angle_t* angle)
{
	return mavlink_msg_angle_pack_chan(system_id, component_id, chan, msg, angle->angle);
}

/**
 * @brief Send a angle message
 * @param chan MAVLink channel to send the message
 *
 * @param angle 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_angle_send(mavlink_channel_t chan, float angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_angle_LEN];
	_mav_put_float(buf, 0, angle);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_angle, buf, MAVLINK_MSG_ID_angle_LEN, MAVLINK_MSG_ID_angle_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_angle, buf, MAVLINK_MSG_ID_angle_LEN);
#endif
#else
	mavlink_angle_t packet;
	packet.angle = angle;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_angle, (const char *)&packet, MAVLINK_MSG_ID_angle_LEN, MAVLINK_MSG_ID_angle_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_angle, (const char *)&packet, MAVLINK_MSG_ID_angle_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_angle_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_angle_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, angle);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_angle, buf, MAVLINK_MSG_ID_angle_LEN, MAVLINK_MSG_ID_angle_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_angle, buf, MAVLINK_MSG_ID_angle_LEN);
#endif
#else
	mavlink_angle_t *packet = (mavlink_angle_t *)msgbuf;
	packet->angle = angle;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_angle, (const char *)packet, MAVLINK_MSG_ID_angle_LEN, MAVLINK_MSG_ID_angle_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_angle, (const char *)packet, MAVLINK_MSG_ID_angle_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE angle UNPACKING


/**
 * @brief Get field angle from angle message
 *
 * @return 
 */
static inline float mavlink_msg_angle_get_angle(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Decode a angle message into a struct
 *
 * @param msg The message to decode
 * @param angle C-struct to decode the message contents into
 */
static inline void mavlink_msg_angle_decode(const mavlink_message_t* msg, mavlink_angle_t* angle)
{
#if MAVLINK_NEED_BYTE_SWAP
	angle->angle = mavlink_msg_angle_get_angle(msg);
#else
	memcpy(angle, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_angle_LEN);
#endif
}
