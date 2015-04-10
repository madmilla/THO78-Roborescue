/** @file
 *	@brief MAVLink comm protocol testsuite generated from mavlink_commands(2).xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#ifndef MAVLINK_COMMANDS(2)_TESTSUITE_H
#define MAVLINK_COMMANDS(2)_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_mavlink_commands(2)(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

	mavlink_test_mavlink_commands(2)(system_id, component_id, last_msg);
}
#endif




static void mavlink_test_ralcp(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_ralcp_t packet_in = {
		93372036854775807ULL,29,96
    };
	mavlink_ralcp_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.Payload = packet_in.Payload;
        	packet1.Destination = packet_in.Destination;
        	packet1.Function = packet_in.Function;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ralcp_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_ralcp_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ralcp_pack(system_id, component_id, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_ralcp_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ralcp_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_ralcp_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_ralcp_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ralcp_send(MAVLINK_COMM_1 , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_ralcp_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_mavlink_commands(2)(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_ralcp(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_COMMANDS(2)_TESTSUITE_H
