MODULES := serial ioDevice mavlinkSubject someListener 


PROJECT := main

TARGET := $(PROJECT).exe
HEADERS += $(patsubst %,%.h,$(MODULES))
OBJECTS += $(patsubst %,%.o,$(MODULES) $(PROJECT))
SOURCES += $(patsubst %,%.cpp,$(MODULES) $(PROJECT))

FLAGS   := -std=gnu++11
# -pthread
LFLAGS  := -I mavlink/include -I mavlink/include/telemetryTest -I mavlink/include/common
#-L/usr/local/ssl/lib/ -lssl -lcrypto -lpthread

rm := rm -rf

.PHONY: build clean rebuild run

$(info $$(OBJECTS) is [$(OBJECTS)])
$(info $$(HEADERS) is [$(HEADERS)])

run: $(TARGET)
	sudo ./$(TARGET)

rebuild: clean build

build: $(TARGET)

clean:
	$(rm) $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS) $(HEADERS)
	$(info Building target)
	g++ $(FLAGS) -o $@ $(OBJECTS) $(HEADERS) $(LFLAGS)

%.o: %.cpp $(HEADERS)
	$(info Building $@)
	g++ -c $(FLAGS) -o $@ $< $(LFLAGS)
