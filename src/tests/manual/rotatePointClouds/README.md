#Rotate point clouds

uses 
	lidar/point_clouds/rotate
	lidar/point_clouds/pointcloudobject    

Will rotate random generated point clouds with a given angle
	./rotate *rotationangle*

To test rotation, the cloud will be rotated 360 degrees and will be compared to its reference.

Testresults will be written to *testlog*