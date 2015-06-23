include Makefile.inc

.PHONY : mission1 localisationmodule lidar rosbee clean doxygen

mission1 : $(UI_HEADERS) $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(OBJ) $(LDLIBS)

ifeq ($(OS),Windows_NT)
	@echo "Can't compile on windows! Compile on an Unix based OS."
else
	localisationmodule : $(UI_HEADERS) $(OBJ)
		$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(OBJ) $(LDLIBS)
endif
lidar : 
	

rosbee : 
	

clean : 
	for prefix in $(CLEAN_MODULES); do \
		rm -f "$$prefix"*.o; \
		rm -f "$$prefix"*.d; \
		rm -f "$$prefix"ui_*.h; \
		rm -f "$$prefix"moc_*.cpp; \
	done
	rm -f *.exe
	

doxygen:
	

-include $(OBJ:.o=.d)
