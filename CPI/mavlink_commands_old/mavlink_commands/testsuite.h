/** @file
 *	@brief MAVLink comm protocol testsuite generated from mavlink_commands.xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#ifndef MAVLINK_COMMANDS_TESTSUITE_H
#define MAVLINK_COMMANDS_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_mavlink_commands(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

	mavlink_test_mavlink_commands(system_id, component_id, last_msg);
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

static void mavlink_test_getequipmentstatus(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_getequipmentstatus_t packet_in = {
		5,72,139
    };
	mavlink_getequipmentstatus_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.Destination = packet_in.Destination;
        	packet1.Function = packet_in.Function;
        	packet1.Payload = packet_in.Payload;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_getequipmentstatus_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_getequipmentstatus_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_getequipmentstatus_pack(system_id, component_id, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_getequipmentstatus_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_getequipmentstatus_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_getequipmentstatus_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_getequipmentstatus_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_getequipmentstatus_send(MAVLINK_COMM_1 , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_getequipmentstatus_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_startmission(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_startmission_t packet_in = {
		5,72,139
    };
	mavlink_startmission_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.Destination = packet_in.Destination;
        	packet1.Function = packet_in.Function;
        	packet1.Payload = packet_in.Payload;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_startmission_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_startmission_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_startmission_pack(system_id, component_id, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_startmission_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_startmission_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_startmission_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_startmission_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_startmission_send(MAVLINK_COMM_1 , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_startmission_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_sendwaypoint(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_sendwaypoint_t packet_in = {
		17235,139,206
    };
	mavlink_sendwaypoint_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.Payload = packet_in.Payload;
        	packet1.Destination = packet_in.Destination;
        	packet1.Function = packet_in.Function;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sendwaypoint_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_sendwaypoint_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sendwaypoint_pack(system_id, component_id, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_sendwaypoint_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sendwaypoint_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_sendwaypoint_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_sendwaypoint_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sendwaypoint_send(MAVLINK_COMM_1 , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_sendwaypoint_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_getrequest(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_getrequest_t packet_in = {
		5,72,139
    };
	mavlink_getrequest_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.Destination = packet_in.Destination;
        	packet1.Function = packet_in.Function;
        	packet1.Payload = packet_in.Payload;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_getrequest_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_getrequest_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_getrequest_pack(system_id, component_id, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_getrequest_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_getrequest_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_getrequest_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_getrequest_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_getrequest_send(MAVLINK_COMM_1 , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_getrequest_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_stopmission(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_stopmission_t packet_in = {
		{ 17235, 17236, 17237, 17238 },29,96
    };
	mavlink_stopmission_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.Destination = packet_in.Destination;
        	packet1.Function = packet_in.Function;
        
        	mav_array_memcpy(packet1.Payload, packet_in.Payload, sizeof(int16_t)*4);
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_stopmission_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_stopmission_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_stopmission_pack(system_id, component_id, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_stopmission_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_stopmission_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_stopmission_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_stopmission_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_stopmission_send(MAVLINK_COMM_1 , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_stopmission_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_abortmission(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_abortmission_t packet_in = {
		5,72,139
    };
	mavlink_abortmission_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.Destination = packet_in.Destination;
        	packet1.Function = packet_in.Function;
        	packet1.Payload = packet_in.Payload;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_abortmission_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_abortmission_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_abortmission_pack(system_id, component_id, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_abortmission_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_abortmission_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_abortmission_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_abortmission_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_abortmission_send(MAVLINK_COMM_1 , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_abortmission_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_sonarinterrupt(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_sonarinterrupt_t packet_in = {
		5,72,139
    };
	mavlink_sonarinterrupt_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.Destination = packet_in.Destination;
        	packet1.Function = packet_in.Function;
        	packet1.Payload = packet_in.Payload;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sonarinterrupt_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_sonarinterrupt_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sonarinterrupt_pack(system_id, component_id, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_sonarinterrupt_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sonarinterrupt_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_sonarinterrupt_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_sonarinterrupt_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sonarinterrupt_send(MAVLINK_COMM_1 , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_sonarinterrupt_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_acknowledge(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_acknowledge_t packet_in = {
		5,72,139
    };
	mavlink_acknowledge_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.Destination = packet_in.Destination;
        	packet1.Function = packet_in.Function;
        	packet1.Payload = packet_in.Payload;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_acknowledge_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_acknowledge_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_acknowledge_pack(system_id, component_id, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_acknowledge_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_acknowledge_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_acknowledge_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_acknowledge_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_acknowledge_send(MAVLINK_COMM_1 , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_acknowledge_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_batterystatus(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_batterystatus_t packet_in = {
		5,72,139
    };
	mavlink_batterystatus_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.Destination = packet_in.Destination;
        	packet1.Function = packet_in.Function;
        	packet1.Payload = packet_in.Payload;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_batterystatus_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_batterystatus_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_batterystatus_pack(system_id, component_id, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_batterystatus_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_batterystatus_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_batterystatus_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_batterystatus_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_batterystatus_send(MAVLINK_COMM_1 , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_batterystatus_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_sendinterrupt(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_sendinterrupt_t packet_in = {
		5,72,139
    };
	mavlink_sendinterrupt_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.Destination = packet_in.Destination;
        	packet1.Function = packet_in.Function;
        	packet1.Payload = packet_in.Payload;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sendinterrupt_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_sendinterrupt_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sendinterrupt_pack(system_id, component_id, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_sendinterrupt_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sendinterrupt_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_sendinterrupt_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_sendinterrupt_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sendinterrupt_send(MAVLINK_COMM_1 , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_sendinterrupt_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_getdevice(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_getdevice_t packet_in = {
		5,72,139
    };
	mavlink_getdevice_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.Destination = packet_in.Destination;
        	packet1.Function = packet_in.Function;
        	packet1.Payload = packet_in.Payload;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_getdevice_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_getdevice_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_getdevice_pack(system_id, component_id, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_getdevice_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_getdevice_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_getdevice_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_getdevice_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_getdevice_send(MAVLINK_COMM_1 , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_getdevice_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_receiveline(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_receiveline_t packet_in = {
		{ 17235, 17236, 17237, 17238 },29,96
    };
	mavlink_receiveline_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.Destination = packet_in.Destination;
        	packet1.Function = packet_in.Function;
        
        	mav_array_memcpy(packet1.Payload, packet_in.Payload, sizeof(int16_t)*4);
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_receiveline_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_receiveline_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_receiveline_pack(system_id, component_id, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_receiveline_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_receiveline_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_receiveline_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_receiveline_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_receiveline_send(MAVLINK_COMM_1 , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_receiveline_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_receiverpm(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_receiverpm_t packet_in = {
		17235,139,206
    };
	mavlink_receiverpm_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.Payload = packet_in.Payload;
        	packet1.Destination = packet_in.Destination;
        	packet1.Function = packet_in.Function;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_receiverpm_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_receiverpm_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_receiverpm_pack(system_id, component_id, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_receiverpm_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_receiverpm_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_receiverpm_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_receiverpm_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_receiverpm_send(MAVLINK_COMM_1 , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_receiverpm_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_sendrpm(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_sendrpm_t packet_in = {
		17235,139,206
    };
	mavlink_sendrpm_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.Payload = packet_in.Payload;
        	packet1.Destination = packet_in.Destination;
        	packet1.Function = packet_in.Function;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sendrpm_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_sendrpm_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sendrpm_pack(system_id, component_id, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_sendrpm_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sendrpm_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_sendrpm_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_sendrpm_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sendrpm_send(MAVLINK_COMM_1 , packet1.Destination , packet1.Function , packet1.Payload );
	mavlink_msg_sendrpm_decode(last_msg, &packet2);
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
		5,72,{ 139, 140 }
    };
	mavlink_sendrosbeeposition_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.Destination = packet_in.Destination;
        	packet1.Function = packet_in.Function;
        
        	mav_array_memcpy(packet1.Payload, packet_in.Payload, sizeof(int8_t)*2);
        

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
		17235,139,206
    };
	mavlink_sendrosbeeflank_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.Payload = packet_in.Payload;
        	packet1.Destination = packet_in.Destination;
        	packet1.Function = packet_in.Function;
        
        

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

static void mavlink_test_mavlink_commands(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_init(system_id, component_id, last_msg);
	mavlink_test_getequipmentstatus(system_id, component_id, last_msg);
	mavlink_test_startmission(system_id, component_id, last_msg);
	mavlink_test_sendwaypoint(system_id, component_id, last_msg);
	mavlink_test_getrequest(system_id, component_id, last_msg);
	mavlink_test_stopmission(system_id, component_id, last_msg);
	mavlink_test_abortmission(system_id, component_id, last_msg);
	mavlink_test_sonarinterrupt(system_id, component_id, last_msg);
	mavlink_test_acknowledge(system_id, component_id, last_msg);
	mavlink_test_batterystatus(system_id, component_id, last_msg);
	mavlink_test_sendinterrupt(system_id, component_id, last_msg);
	mavlink_test_getdevice(system_id, component_id, last_msg);
	mavlink_test_receiveline(system_id, component_id, last_msg);
	mavlink_test_receiverpm(system_id, component_id, last_msg);
	mavlink_test_sendrpm(system_id, component_id, last_msg);
	mavlink_test_start(system_id, component_id, last_msg);
	mavlink_test_stop(system_id, component_id, last_msg);
	mavlink_test_sendrosbeeposition(system_id, component_id, last_msg);
	mavlink_test_sendrosbeeflank(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_COMMANDS_TESTSUITE_H
