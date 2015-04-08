/** @file
 *	@brief MAVLink comm protocol testsuite generated from test_command.xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#ifndef TEST_COMMAND_TESTSUITE_H
#define TEST_COMMAND_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_test_command(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

	mavlink_test_test_command(system_id, component_id, last_msg);
}
#endif




static void mavlink_test_init(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_init_t packet_in = {
		5,72,139
    };
	mavlink_init_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.Destination = packet_in.Destination;
        	packet1.Function = packet_in.Function;
        	packet1.Payload = packet_in.Payload;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_init_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_init_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_init_pack(system_id, component_id, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_init_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_init_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_init_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_init_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_init_send(MAVLINK_COMM_1 , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_init_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_getdata(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_getdata_t packet_in = {
		{ 17235, 17236, 17237, 17238 },29,96
    };
	mavlink_getdata_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.Destination = packet_in.Destination;
        	packet1.Function = packet_in.Function;
        
        	mav_array_memcpy(packet1.Payload, packet_in.Payload, sizeof(int16_t)*4);
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_getdata_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_getdata_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_getdata_pack(system_id, component_id, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_getdata_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_getdata_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_getdata_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_getdata_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_getdata_send(MAVLINK_COMM_1 , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_getdata_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_getrpm(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_getrpm_t packet_in = {
		5,72,139
    };
	mavlink_getrpm_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.Destination = packet_in.Destination;
        	packet1.Function = packet_in.Function;
        	packet1.Payload = packet_in.Payload;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_getrpm_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_getrpm_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_getrpm_pack(system_id, component_id, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_getrpm_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_getrpm_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_getrpm_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_getrpm_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_getrpm_send(MAVLINK_COMM_1 , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_getrpm_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_start(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_start_t packet_in = {
		5,72,139
    };
	mavlink_start_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.Destination = packet_in.Destination;
        	packet1.Function = packet_in.Function;
        	packet1.Payload = packet_in.Payload;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_start_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_start_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_start_pack(system_id, component_id, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_start_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_start_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_start_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_start_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_start_send(MAVLINK_COMM_1 , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_start_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_stop(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_stop_t packet_in = {
		5,72,139
    };
	mavlink_stop_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.Destination = packet_in.Destination;
        	packet1.Function = packet_in.Function;
        	packet1.Payload = packet_in.Payload;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_stop_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_stop_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_stop_pack(system_id, component_id, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_stop_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_stop_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_stop_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_stop_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_stop_send(MAVLINK_COMM_1 , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_stop_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_sendrosbeeposition(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_sendrosbeeposition_t packet_in = {
		{ 17235, 17236, 17237, 17238 },29,96
    };
	mavlink_sendrosbeeposition_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.Destination = packet_in.Destination;
        	packet1.Function = packet_in.Function;
        
        	mav_array_memcpy(packet1.Payload, packet_in.Payload, sizeof(int16_t)*4);
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sendrosbeeposition_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_sendrosbeeposition_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sendrosbeeposition_pack(system_id, component_id, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_sendrosbeeposition_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sendrosbeeposition_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_sendrosbeeposition_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_sendrosbeeposition_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sendrosbeeposition_send(MAVLINK_COMM_1 , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_sendrosbeeposition_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_sendrosbeeflank(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_sendrosbeeflank_t packet_in = {
		5,72,139
    };
	mavlink_sendrosbeeflank_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.Destination = packet_in.Destination;
        	packet1.Function = packet_in.Function;
        	packet1.Payload = packet_in.Payload;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sendrosbeeflank_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_sendrosbeeflank_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sendrosbeeflank_pack(system_id, component_id, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_sendrosbeeflank_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sendrosbeeflank_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_sendrosbeeflank_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_sendrosbeeflank_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sendrosbeeflank_send(MAVLINK_COMM_1 , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_sendrosbeeflank_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_sendtext(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_sendtext_t packet_in = {
		5,72,"CDEFGHIJKLMNOPQRSTU"
    };
	mavlink_sendtext_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.Destination = packet_in.Destination;
        	packet1.Function = packet_in.Function;
        
        	mav_array_memcpy(packet1.Payload, packet_in.Payload, sizeof(char)*20);
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sendtext_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_sendtext_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sendtext_pack(system_id, component_id, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_sendtext_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sendtext_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_sendtext_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_sendtext_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sendtext_send(MAVLINK_COMM_1 , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_sendtext_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_test_command(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_init(system_id, component_id, last_msg);
	mavlink_test_getdata(system_id, component_id, last_msg);
	mavlink_test_getrpm(system_id, component_id, last_msg);
	mavlink_test_start(system_id, component_id, last_msg);
	mavlink_test_stop(system_id, component_id, last_msg);
	mavlink_test_sendrosbeeposition(system_id, component_id, last_msg);
	mavlink_test_sendrosbeeflank(system_id, component_id, last_msg);
	mavlink_test_sendtext(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // TEST_COMMAND_TESTSUITE_H
