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
SOURCES := irSendTask.cpp irLed.cpp oledController.cpp keyPadTaskInit.cpp registerEntity.cpp initTask.cpp keypad.cpp

# header files in this project
HEADERS := irSendTask.hpp irLed.hpp oledController.hpp keyPadTaskInit.hpp registerEntity.hpp initTask.hpp keypad.hpp

# other places to look for files for this project
SEARCH  := $(BoundaryObjects) $(ControlObjects) $(EntityObjects) $(Tasks)

# set RELATIVE to the next higher directory and defer to the Makefile.due
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due
