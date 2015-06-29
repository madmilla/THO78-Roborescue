include Makefile.inc

.PHONY : mission1 localisationmodule lidar rosbee environmentsimulator test clean

echoUIHeaders:
	
mission1 : 

	@echo UI is: $(UI)
	@echo UI headers are: $(UI_HEADERS)
<<<<<<< HEAD
	
generateUIHeaders: $(UI)
	@echo UI is: $(UI)
	@echo UI headers are: $(UI_HEADERS)
	
mission1 : $(UI_HEADERS) $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(OBJ) $(LDLIBS)
=======


	$(UI_HEADERS) $(OBJ)
		$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(OBJ) $(LDLIBS)
>>>>>>> 8763ac672eff589a3d9195a5c54369a4a5185bb0
	
localisationmodule : $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(OBJ) $(LDLIBS)
	
lidar : $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(OBJ) $(LDLIBS)
	
rosbee : 
	
environmentsimulator : $(UI_HEADERS) $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(OBJ) $(LDLIBS)

test : $(UI_HEADERS) $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(OBJ) $(LDLIBS)
	
clean : 
	for prefix in $(MODULES); do \
		rm -f "$$prefix"*.o; \
		rm -f "$$prefix"*.d; \
		rm -f "$$prefix"ui_*.h; \
		rm -f "$$prefix"moc_*.cpp; \
	done
	rm -f *.exe

-include $(OBJ:.o=.d)
