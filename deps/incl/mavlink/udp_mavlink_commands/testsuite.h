/** @file
 *	@brief MAVLink comm protocol testsuite generated from ralcp.xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#ifndef RALCP_TESTSUITE_H
#define RALCP_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_ralcp(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

	mavlink_test_ralcp(system_id, component_id, last_msg);
}
#endif




static void mavlink_test_rosbee_message(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_rosbee_message_t packet_in = {
		93372036854775807ULL,29,96
    };
	mavlink_rosbee_message_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.Payload = packet_in.Payload;
        	packet1.Destination = packet_in.Destination;
        	packet1.Function = packet_in.Function;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_rosbee_message_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_rosbee_message_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_rosbee_message_pack(system_id, component_id, &msg , packet1.Payload , packet1.Destination , packet1.Function );
	mavlink_msg_rosbee_message_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_rosbee_message_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Payload , packet1.Destination , packet1.Function );
	mavlink_msg_rosbee_message_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_rosbee_message_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_rosbee_message_send(MAVLINK_COMM_1 , packet1.Payload , packet1.Destination , packet1.Function );
	mavlink_msg_rosbee_message_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_lidar_message(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_lidar_message_t packet_in = {
		{ 963497464, 963497465, 963497466, 963497467, 963497468 },65,132
    };
	mavlink_lidar_message_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.Destination = packet_in.Destination;
        	packet1.Function = packet_in.Function;
        
        	mav_array_memcpy(packet1.Payload, packet_in.Payload, sizeof(int32_t)*5);
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_lidar_message_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_lidar_message_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_lidar_message_pack(system_id, component_id, &msg , packet1.Payload , packet1.Destination , packet1.Function );
	mavlink_msg_lidar_message_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_lidar_message_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Payload , packet1.Destination , packet1.Function );
	mavlink_msg_lidar_message_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_lidar_message_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_lidar_message_send(MAVLINK_COMM_1 , packet1.Payload , packet1.Destination , packet1.Function );
	mavlink_msg_lidar_message_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_ralcp(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_rosbee_message(system_id, component_id, last_msg);
	mavlink_test_lidar_message(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // RALCP_TESTSUITE_H
