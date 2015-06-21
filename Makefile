include Makefile.inc

.PHONY : mission1 localisationmodule lidar rosbee clean doxygen

mission1 : $(UI_HEADERS) $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(OBJ) $(LDLIBS)
	
localisationmodule : 
	

lidar : 
	

rosbee : 
	

clean : 
	

doxygen:
	

-include $(OBJ:.o=.d)