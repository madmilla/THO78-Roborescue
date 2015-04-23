COMMANDCENTERDIR 	= src/gui
LIDARSIMDIR 		= 
LIDARDIR 			= src/sensors/lidar
ROSBEEDIR			= src/vehicles/rosbee
MANTESTSDIR			= src/tests/manual
AUTOTESTSDIR 		= src/tests/auto

.PHONY: default commandcenter doxygen lidarsimulator lidar rosbee mantest autotest clean

default:
	@echo 'No target specified, terminating.'
	exit 1

commandcenter: 
	$(MAKE) -C $(COMMANDCENTERDIR)

lidarsimulator:
	$(MAKE) -C $(LIDARSIMDIR)
	
lidar:
	$(MAKE) -C $(LIDARDIR)
	
rosbee:
ifeq ($(OS),Windows_NT)
	@echo "Rosbee can't be compiled for Windows systems"
else
	$(MAKE) -C $(ROSBEEDIR)
endif
	
mantest:
ifneq ($(TESTS),)
	$(MAKE) -C $(MANTESTSDIR) $(TESTS)
else
	@echo "No tests specified. Specify them by adding TESTS='nameA nameB ...' to the make call."
endif
	
autotest:
ifneq ($(TESTS),)
	$(MAKE) -C $(AUTOTESTSDIR) $(TESTS)
else
	@echo "No tests specified. Specify them by adding TESTS='nameA nameB ...' to the make call."
endif
		
doxygen:
	

clean:
	$(MAKE) -C $(COMMANDCENTERDIR) clean
	#TODO: Add lidarsimulator
	$(MAKE) -C $(LIDARDIR) clean
	$(MAKE) -C $(ROSBEEDIR) clean
	$(MAKE) -C $(MANTESTSDIR) clean
	$(MAKE) -C $(AUTOTESTSDIR) clean