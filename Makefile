include Makefile.inc

.PHONY : mission1 localisationmodule lidar rosbee environmentsimulator test clean

mission1 : $(UI_HEADERS) $(OBJ)
	@echo UI headers are: $(UI_HEADERS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(OBJ) $(LDLIBS)

ui_%.h : %.ui
	$(UIC) $< -o $@

	
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
