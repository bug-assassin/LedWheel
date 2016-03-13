// MESSAGE SET_RGB PACKING

#define MAVLINK_MSG_ID_SET_RGB 0

typedef struct __mavlink_set_rgb_t
{
 uint8_t led_number; /*< */
 uint8_t led_strip_colors[36]; /*< */
} mavlink_set_rgb_t;

#define MAVLINK_MSG_ID_SET_RGB_LEN 37
#define MAVLINK_MSG_ID_0_LEN 37

#define MAVLINK_MSG_ID_SET_RGB_CRC 254
#define MAVLINK_MSG_ID_0_CRC 254

#define MAVLINK_MSG_SET_RGB_FIELD_LED_STRIP_COLORS_LEN 36

#define MAVLINK_MESSAGE_INFO_SET_RGB { \
	"SET_RGB", \
	2, \
	{  { "led_number", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_set_rgb_t, led_number) }, \
         { "led_strip_colors", NULL, MAVLINK_TYPE_UINT8_T, 36, 1, offsetof(mavlink_set_rgb_t, led_strip_colors) }, \
         } \
}


/**
 * @brief Pack a set_rgb message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param led_number 
 * @param led_strip_colors 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_rgb_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t led_number, const uint8_t *led_strip_colors)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SET_RGB_LEN];
	_mav_put_uint8_t(buf, 0, led_number);
	_mav_put_uint8_t_array(buf, 1, led_strip_colors, 36);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_RGB_LEN);
#else
	mavlink_set_rgb_t packet;
	packet.led_number = led_number;
	mav_array_memcpy(packet.led_strip_colors, led_strip_colors, sizeof(uint8_t)*36);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_RGB_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SET_RGB;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SET_RGB_LEN, MAVLINK_MSG_ID_SET_RGB_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SET_RGB_LEN);
#endif
}

/**
 * @brief Pack a set_rgb message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param led_number 
 * @param led_strip_colors 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_rgb_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t led_number,const uint8_t *led_strip_colors)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SET_RGB_LEN];
	_mav_put_uint8_t(buf, 0, led_number);
	_mav_put_uint8_t_array(buf, 1, led_strip_colors, 36);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_RGB_LEN);
#else
	mavlink_set_rgb_t packet;
	packet.led_number = led_number;
	mav_array_memcpy(packet.led_strip_colors, led_strip_colors, sizeof(uint8_t)*36);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_RGB_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SET_RGB;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SET_RGB_LEN, MAVLINK_MSG_ID_SET_RGB_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SET_RGB_LEN);
#endif
}

/**
 * @brief Encode a set_rgb struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param set_rgb C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_rgb_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_set_rgb_t* set_rgb)
{
	return mavlink_msg_set_rgb_pack(system_id, component_id, msg, set_rgb->led_number, set_rgb->led_strip_colors);
}

/**
 * @brief Encode a set_rgb struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param set_rgb C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_rgb_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_set_rgb_t* set_rgb)
{
	return mavlink_msg_set_rgb_pack_chan(system_id, component_id, chan, msg, set_rgb->led_number, set_rgb->led_strip_colors);
}

/**
 * @brief Send a set_rgb message
 * @param chan MAVLink channel to send the message
 *
 * @param led_number 
 * @param led_strip_colors 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_set_rgb_send(mavlink_channel_t chan, uint8_t led_number, const uint8_t *led_strip_colors)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SET_RGB_LEN];
	_mav_put_uint8_t(buf, 0, led_number);
	_mav_put_uint8_t_array(buf, 1, led_strip_colors, 36);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_RGB, buf, MAVLINK_MSG_ID_SET_RGB_LEN, MAVLINK_MSG_ID_SET_RGB_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_RGB, buf, MAVLINK_MSG_ID_SET_RGB_LEN);
#endif
#else
	mavlink_set_rgb_t packet;
	packet.led_number = led_number;
	mav_array_memcpy(packet.led_strip_colors, led_strip_colors, sizeof(uint8_t)*36);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_RGB, (const char *)&packet, MAVLINK_MSG_ID_SET_RGB_LEN, MAVLINK_MSG_ID_SET_RGB_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_RGB, (const char *)&packet, MAVLINK_MSG_ID_SET_RGB_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_SET_RGB_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_set_rgb_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t led_number, const uint8_t *led_strip_colors)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, led_number);
	_mav_put_uint8_t_array(buf, 1, led_strip_colors, 36);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_RGB, buf, MAVLINK_MSG_ID_SET_RGB_LEN, MAVLINK_MSG_ID_SET_RGB_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_RGB, buf, MAVLINK_MSG_ID_SET_RGB_LEN);
#endif
#else
	mavlink_set_rgb_t *packet = (mavlink_set_rgb_t *)msgbuf;
	packet->led_number = led_number;
	mav_array_memcpy(packet->led_strip_colors, led_strip_colors, sizeof(uint8_t)*36);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_RGB, (const char *)packet, MAVLINK_MSG_ID_SET_RGB_LEN, MAVLINK_MSG_ID_SET_RGB_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_RGB, (const char *)packet, MAVLINK_MSG_ID_SET_RGB_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE SET_RGB UNPACKING


/**
 * @brief Get field led_number from set_rgb message
 *
 * @return 
 */
static inline uint8_t mavlink_msg_set_rgb_get_led_number(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field led_strip_colors from set_rgb message
 *
 * @return 
 */
static inline uint16_t mavlink_msg_set_rgb_get_led_strip_colors(const mavlink_message_t* msg, uint8_t *led_strip_colors)
{
	return _MAV_RETURN_uint8_t_array(msg, led_strip_colors, 36,  1);
}

/**
 * @brief Decode a set_rgb message into a struct
 *
 * @param msg The message to decode
 * @param set_rgb C-struct to decode the message contents into
 */
static inline void mavlink_msg_set_rgb_decode(const mavlink_message_t* msg, mavlink_set_rgb_t* set_rgb)
{
#if MAVLINK_NEED_BYTE_SWAP
	set_rgb->led_number = mavlink_msg_set_rgb_get_led_number(msg);
	mavlink_msg_set_rgb_get_led_strip_colors(msg, set_rgb->led_strip_colors);
#else
	memcpy(set_rgb, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_SET_RGB_LEN);
#endif
}
