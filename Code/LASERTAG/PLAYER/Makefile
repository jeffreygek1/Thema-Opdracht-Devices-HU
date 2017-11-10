#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# Voeg hier het pad in tot aan ../Thema-Opdracht-Devices-HU/Code/LASERTAG
STARTMAP := C:/ti-software/Thema-Opdracht-Devices-HU/Code/LASERTAG

BoundaryObjects := $(STARTMAP)/BoundaryObjects
ControlObjects := $(STARTMAP)/ControlObjects
EntityObjects := $(STARTMAP)/EntityObjects
Tasks := $(STARTMAP)/Tasks

# source files in this project (main.cpp is automatically assumed)
SOURCES := beeper.cpp beeperTask.cpp runGameTask.cpp irSendTask.cpp irLed.cpp registerEntity.cpp hpEntity.cpp oledController.cpp keyPadTask.cpp irReceiveTask.cpp irReceiver.cpp keypad.cpp

# header files in this project
HEADERS := beeper.hpp beeperTask.hpp runGameTask.hpp irSendTask.hpp irLed.hpp registerEntity.hpp hpEntity.hpp oledController.hpp keyPadTask.hpp irReceiveTask.hpp irReceiver.hpp keypad.hpp 

# other places to look for files for this project
SEARCH  := $(BoundaryObjects) $(ControlObjects) $(EntityObjects) $(Tasks)

# set RELATIVE to the next higher directory and defer to the Makefile.due
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due
