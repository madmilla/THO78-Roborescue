/** @file
 *	@brief MAVLink comm protocol built from test_command.xml
 *	@see http://mavlink.org
 */
#ifndef MAVLINK_LIDAR_H
#define MAVLINK_LIDAR_H

#ifndef MAVLINK_STX
#define MAVLINK_STX 254
#endif

#ifndef MAVLINK_ENDIAN
#define MAVLINK_ENDIAN MAVLINK_LITTLE_ENDIAN
#endif

#ifndef MAVLINK_ALIGNED_FIELDS
#define MAVLINK_ALIGNED_FIELDS 1
#endif

#ifndef MAVLINK_CRC_EXTRA
#define MAVLINK_CRC_EXTRA 1
#endif

#include "version.h"
#include "test_command.h"

#endif // MAVLINK_H
