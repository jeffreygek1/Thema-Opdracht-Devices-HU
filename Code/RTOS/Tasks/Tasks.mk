##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Tasks
ConfigurationName      :=Debug
WorkspacePath          :=C:/ti-software/Thema-Opdracht-Devices-HU/Code/RTOS
ProjectPath            :=C:/ti-software/Thema-Opdracht-Devices-HU/Code/RTOS/Tasks
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Arsal
Date                   :=07/11/2017
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Tasks.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  -lgdi32 -static-libgcc -static-libstdc++ 
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)../Catch/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -std=c++11 $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/BeeperTask.cpp$(ObjectSuffix) $(IntermediateDirectory)/IRReceiveTask.cpp$(ObjectSuffix) $(IntermediateDirectory)/IRSendTask.cpp$(ObjectSuffix) $(IntermediateDirectory)/KeyPadTask.cpp$(ObjectSuffix) $(IntermediateDirectory)/RunGameTask.cpp$(ObjectSuffix) $(IntermediateDirectory)/InitTask.cpp$(ObjectSuffix) $(IntermediateDirectory)/KeyPadTask_init.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/ti-software/Thema-Opdracht-Devices-HU/Code/RTOS/Tasks/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/BeeperTask.cpp$(ObjectSuffix): BeeperTask.cpp $(IntermediateDirectory)/BeeperTask.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/ti-software/Thema-Opdracht-Devices-HU/Code/RTOS/Tasks/BeeperTask.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BeeperTask.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BeeperTask.cpp$(DependSuffix): BeeperTask.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BeeperTask.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BeeperTask.cpp$(DependSuffix) -MM BeeperTask.cpp

$(IntermediateDirectory)/BeeperTask.cpp$(PreprocessSuffix): BeeperTask.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BeeperTask.cpp$(PreprocessSuffix) BeeperTask.cpp

$(IntermediateDirectory)/IRReceiveTask.cpp$(ObjectSuffix): IRReceiveTask.cpp $(IntermediateDirectory)/IRReceiveTask.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/ti-software/Thema-Opdracht-Devices-HU/Code/RTOS/Tasks/IRReceiveTask.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IRReceiveTask.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IRReceiveTask.cpp$(DependSuffix): IRReceiveTask.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IRReceiveTask.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IRReceiveTask.cpp$(DependSuffix) -MM IRReceiveTask.cpp

$(IntermediateDirectory)/IRReceiveTask.cpp$(PreprocessSuffix): IRReceiveTask.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IRReceiveTask.cpp$(PreprocessSuffix) IRReceiveTask.cpp

$(IntermediateDirectory)/IRSendTask.cpp$(ObjectSuffix): IRSendTask.cpp $(IntermediateDirectory)/IRSendTask.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/ti-software/Thema-Opdracht-Devices-HU/Code/RTOS/Tasks/IRSendTask.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IRSendTask.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IRSendTask.cpp$(DependSuffix): IRSendTask.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IRSendTask.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IRSendTask.cpp$(DependSuffix) -MM IRSendTask.cpp

$(IntermediateDirectory)/IRSendTask.cpp$(PreprocessSuffix): IRSendTask.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IRSendTask.cpp$(PreprocessSuffix) IRSendTask.cpp

$(IntermediateDirectory)/KeyPadTask.cpp$(ObjectSuffix): KeyPadTask.cpp $(IntermediateDirectory)/KeyPadTask.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/ti-software/Thema-Opdracht-Devices-HU/Code/RTOS/Tasks/KeyPadTask.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/KeyPadTask.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/KeyPadTask.cpp$(DependSuffix): KeyPadTask.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/KeyPadTask.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/KeyPadTask.cpp$(DependSuffix) -MM KeyPadTask.cpp

$(IntermediateDirectory)/KeyPadTask.cpp$(PreprocessSuffix): KeyPadTask.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/KeyPadTask.cpp$(PreprocessSuffix) KeyPadTask.cpp

$(IntermediateDirectory)/RunGameTask.cpp$(ObjectSuffix): RunGameTask.cpp $(IntermediateDirectory)/RunGameTask.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/ti-software/Thema-Opdracht-Devices-HU/Code/RTOS/Tasks/RunGameTask.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RunGameTask.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RunGameTask.cpp$(DependSuffix): RunGameTask.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RunGameTask.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/RunGameTask.cpp$(DependSuffix) -MM RunGameTask.cpp

$(IntermediateDirectory)/RunGameTask.cpp$(PreprocessSuffix): RunGameTask.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RunGameTask.cpp$(PreprocessSuffix) RunGameTask.cpp

$(IntermediateDirectory)/InitTask.cpp$(ObjectSuffix): InitTask.cpp $(IntermediateDirectory)/InitTask.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/ti-software/Thema-Opdracht-Devices-HU/Code/RTOS/Tasks/InitTask.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/InitTask.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/InitTask.cpp$(DependSuffix): InitTask.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/InitTask.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/InitTask.cpp$(DependSuffix) -MM InitTask.cpp

$(IntermediateDirectory)/InitTask.cpp$(PreprocessSuffix): InitTask.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/InitTask.cpp$(PreprocessSuffix) InitTask.cpp

$(IntermediateDirectory)/KeyPadTask_init.cpp$(ObjectSuffix): KeyPadTask_init.cpp $(IntermediateDirectory)/KeyPadTask_init.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/ti-software/Thema-Opdracht-Devices-HU/Code/RTOS/Tasks/KeyPadTask_init.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/KeyPadTask_init.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/KeyPadTask_init.cpp$(DependSuffix): KeyPadTask_init.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/KeyPadTask_init.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/KeyPadTask_init.cpp$(DependSuffix) -MM KeyPadTask_init.cpp

$(IntermediateDirectory)/KeyPadTask_init.cpp$(PreprocessSuffix): KeyPadTask_init.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/KeyPadTask_init.cpp$(PreprocessSuffix) KeyPadTask_init.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


