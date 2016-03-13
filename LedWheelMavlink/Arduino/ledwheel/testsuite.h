/** @file
 *	@brief MAVLink comm protocol testsuite generated from ledwheel.xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#ifndef LEDWHEEL_TESTSUITE_H
#define LEDWHEEL_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_ledwheel(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

	mavlink_test_ledwheel(system_id, component_id, last_msg);
}
#endif




static void mavlink_test_set_rgb(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_set_rgb_t packet_in = {
		5,{ 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107 }
    };
	mavlink_set_rgb_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.led_number = packet_in.led_number;
        
        	mav_array_memcpy(packet1.led_strip_colors, packet_in.led_strip_colors, sizeof(uint8_t)*36);
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_set_rgb_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_set_rgb_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_set_rgb_pack(system_id, component_id, &msg , packet1.led_number , packet1.led_strip_colors );
	mavlink_msg_set_rgb_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_set_rgb_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.led_number , packet1.led_strip_colors );
	mavlink_msg_set_rgb_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_set_rgb_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_set_rgb_send(MAVLINK_COMM_1 , packet1.led_number , packet1.led_strip_colors );
	mavlink_msg_set_rgb_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_angle(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_angle_t packet_in = {
		17.0
    };
	mavlink_angle_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.angle = packet_in.angle;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_angle_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_angle_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_angle_pack(system_id, component_id, &msg , packet1.angle );
	mavlink_msg_angle_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_angle_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.angle );
	mavlink_msg_angle_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_angle_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_angle_send(MAVLINK_COMM_1 , packet1.angle );
	mavlink_msg_angle_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_ledwheel(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_set_rgb(system_id, component_id, last_msg);
	mavlink_test_angle(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // LEDWHEEL_TESTSUITE_H
