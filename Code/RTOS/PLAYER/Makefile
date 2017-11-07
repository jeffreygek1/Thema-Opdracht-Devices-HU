#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

BoundaryObjects := C:/ti-software/Thema-Opdracht-Devices-HU/Code/RTOS/BoundaryObjects
ControlObjects := C:/ti-software/Thema-Opdracht-Devices-HU/Code/RTOS/ControlObjects
EntityObjects := C:/ti-software/Thema-Opdracht-Devices-HU/Code/RTOS/EntityObjects
Tasks := C:/ti-software/Thema-Opdracht-Devices-HU/Code/RTOS/Tasks

# source files in this project (main.cpp is automatically assumed)
SOURCES := Beeper.cpp BeeperTask.cpp RunGameTask.cpp IRSendTask.cpp IR_LED.cpp Register_entity.cpp HP_entity.cpp OLED_Controller.cpp KeyPadTask.cpp IRReceiveTask.cpp IR_Receiver.cpp Keypad.cpp

# header files in this project
HEADERS := Beeper.hpp BeeperTask.hpp RunGameTask.hpp IRSendTask.hpp IR_LED.hpp Register_entity.hpp HP_entity.hpp OLED_Controller.hpp KeyPadTask.hpp IRReceiveTask.hpp IR_Receiver.hpp Keypad.hpp

# other places to look for files for this project
SEARCH  := $(BoundaryObjects) $(ControlObjects) $(EntityObjects) $(Tasks)

# set RELATIVE to the next higher directory and defer to the Makefile.due
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due
