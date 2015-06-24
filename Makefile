include Makefile.inc

.PHONY : mission1 localisationmodule lidar rosbee environmentsimulator clean

mission1 : $(UI_HEADERS) $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(OBJ) $(LDLIBS)
	
localisationmodule : $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(OBJ) $(LDLIBS)
	
lidar : 
	

rosbee : 
	
environmentsimulator : $(UI_HEADERS) $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(OBJ) $(LDLIBS)

	
clean : 
	for prefix in $(MODULES); do \
		del -f "$$prefix"*.o; \
		del -f "$$prefix"*.d; \
		del -f "$$prefix"ui_*.h; \
		del -f "$$prefix"moc_*.cpp; \
	done
	del -f *.exe

-include $(OBJ:.o=.d)
