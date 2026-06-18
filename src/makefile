ARDUINO_INCLUDES = $(foreach x,$(EXTRA_INCLUDES),-I${HOME}/Arduino/libraries/$(x))

SOURCES=$(shell find src -type f -iname '*.cpp')
OBJECTS=$(foreach x, $(basename $(SOURCES)), $(x).o)

ARDUINO_SOURCES=$(shell find arduino -type f -iname '*.cpp')
ARDUINO_OBJECTS=$(foreach x, $(basename $(ARDUINO_SOURCES)), $(x).o) \
	$(patsubst %.cpp,arduino/lib_%.o,$(EXTRA_SOURCES)) \
	$(foreach x,$(EXTRA_OBJECTS),arduino/$(x))


RAYLIB_URL = https://github.com/raysan5/raylib/releases/download/5.5/raylib-5.5_linux_amd64.tar.gz
RAYLIB_TAR_FILE = $(notdir $(RAYLIB_URL))
RAYLIB_DIR = $(basename $(basename $(RAYLIB_TAR_FILE)))
RAYLIB_BIN_DIR = lib/$(RAYLIB_DIR)/lib

LIB_INCLUDES = -I. -Iarduino -Ilib/$(RAYLIB_DIR)/include

CXX = g++
CC = gcc
STD = -std=c++11

WINDOW_SCALE = 1
CFLAGS = -DDEBUG -DEMULATE -DARDUINO=300 -DARDUINO_GIGA \
	-D__LINUX__ -DWINDOW_SCALE=$(WINDOW_SCALE) \
	-m64 -Wno-narrowing -Wextra \
	$(LIB_INCLUDES) $(ARDUINO_INCLUDES) \
	$(EXTRA_CFLAGS) \
	-Dmemcpy_P=memcpy -Dstrlen_P=strlen -Dstrncmp_P=strncmp \
	-Dstrcmp_P=strcmp -Dmemcmp_P=memcmp


all: lib src ino

ino: main.o ino.o $(OBJECTS) $(ARDUINO_OBJECTS)
	$(CXX) -o $@ $^ -l:libraylib.a -lm -lpthread -ldl -lrt -L$(RAYLIB_BIN_DIR) $(EXTRA_LFLAGS)

main.o: main.cpp
	$(CXX) $(CFLAGS) $(STD) -o $@ -c $<

arduino/lib_%.o: $(HOME)/Arduino/libraries/%/src
	$(CXX) $(CFLAGS) $(STD) -o $@ -c $</$(patsubst arduino/lib_%.o,%,$@).cpp

arduino/png_%.o: $(HOME)/Arduino/libraries/PNGdec/src/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

arduino/%.o: arduino/%.cpp arduino/%.h
	$(CXX) $(CFLAGS) -o $@ -c $<

%.o: %.cpp %.hpp
	$(CXX) $(CFLAGS) $(STD) -o $@ -c $<

src:
	rsync -a ../src .

lib: $(RAYLIB_TAR_FILE)
	mkdir -p lib
	tar xzf $< -C lib/ || rm lib -rf

$(RAYLIB_TAR_FILE):
	wget $(RAYLIB_URL)

.PHONY: clean wipe

clean:
	rm -rf src ino *.o ino.cpp arduino/*.o

wipe: clean
	rm -rf lib $(RAYLIB_TAR_FILE)
