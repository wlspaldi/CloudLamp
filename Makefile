# Arduino Make file. Refer to https://github.com/sudar/Arduino-Makefile
# ARDUINO_DIR = ~/arduino-1.8.5/
PROJECT_DIR = /home/luke/Documents/CloudLamp
ARDMK_DIR = /usr/share/arduino
ARDUINO_DIR = /usr/share/arduino
ARDUINO_LIBS = FastLED-3.1.8 \
	MsTimer2
USER_LIB_PATH = /home/luke/Arduino/libraries/
AVR_TOOLS_DIR = /usr
AVRDUDE = /usr/bin/avrdude

# MONITOR_BAUDRATE = 115200
BOARD_TAG = uno

CFLAGS_STD = -std=gnu11
CXXFLAGS_STD = -std=gnu++11
# CXXFLAGS += -pedantic -Wall -Wextra

#MONITOR_PORT = /dev/ttyACM0
ISP_PORT = /dev/ttyACM0

# LIB = \
# 	$(USER_LIB_PATH)/FastLED-3.1.8/ \
# 	/home/luke/Documents/CloudLamp/lib/FastLED-3.1.8/FastLED.h \
# 	/home/luke/Documents/CloudLamp/lib/FastLED-3.1.8/controller.h

LIBRARIES := \
	Wire \
	FastLED

CINCS = $(USER_LIB_PATH)/FastLED-3.1.8

CURRENT_DIR = $(shell basename $(CURDIR))

OBJDIR = $(PROJECT_DIR)/bin/$(BOARD_TAG)/$(CURRENT_DIR)

include $(ARDMK_DIR)/Arduino.mk
