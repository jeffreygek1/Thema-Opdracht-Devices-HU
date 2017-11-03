#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := Beeper.cpp BeeperTask.cpp RunGameTask.cpp IRSendTask.cpp IR_LED.cpp Register_entity.cpp HP_entity.cpp OLEDTask.cpp 

# header files in this project
HEADERS := Beeper.hpp BeeperTask.hpp RunGameTask.hpp IRSendTask.hpp IR_LED.hpp Register_entity.hpp HP_entity.hpp OLEDTask.hpp

# other places to look for files for this project
SEARCH  := C:/ti-software/Thema-Opdracht-Devices-HU/Code/RTOS/BoundaryObjects C:/ti-software/Thema-Opdracht-Devices-HU/Code/RTOS/ControlObjects C:/ti-software/Thema-Opdracht-Devices-HU/Code/RTOS/EntityObjects C:/ti-software/Thema-Opdracht-Devices-HU/Code/RTOS/Tasks

# set RELATIVE to the next higher directory and defer to the Makefile.due
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due
