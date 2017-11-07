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
SOURCES := IRSendTask.cpp IR_LED.cpp OLED_Controller.cpp KeyPadTask_init.cpp Register_entity.cpp InitTask.cpp Keypad.cpp

# header files in this project
HEADERS := IRSendTask.hpp IR_LED.hpp OLED_Controller.hpp KeyPadTask_init.hpp Register_entity.hpp InitTask.hpp Keypad.hpp

# other places to look for files for this project
SEARCH  := $(BoundaryObjects) $(ControlObjects) $(EntityObjects) $(Tasks)

# set RELATIVE to the next higher directory and defer to the Makefile.due
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due
