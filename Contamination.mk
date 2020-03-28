##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Contamination
ConfigurationName      :=Debug
WorkspacePath          :=/home/thefamousrat/Documents/ENSAI/Cpp/DM1/Contamination
ProjectPath            :=/home/thefamousrat/Documents/ENSAI/Cpp/DM1/Contamination/Contamination
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Guillaume Roy
Date                   :=28/03/20
CodeLitePath           :=/home/thefamousrat/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
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
ObjectsFileList        :="Contamination.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/agent.cpp$(ObjectSuffix) $(IntermediateDirectory)/config.cpp$(ObjectSuffix) $(IntermediateDirectory)/zone.cpp$(ObjectSuffix) 



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
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/thefamousrat/Documents/ENSAI/Cpp/DM1/Contamination/Contamination/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/agent.cpp$(ObjectSuffix): agent.cpp $(IntermediateDirectory)/agent.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/thefamousrat/Documents/ENSAI/Cpp/DM1/Contamination/Contamination/agent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/agent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/agent.cpp$(DependSuffix): agent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/agent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/agent.cpp$(DependSuffix) -MM agent.cpp

$(IntermediateDirectory)/agent.cpp$(PreprocessSuffix): agent.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/agent.cpp$(PreprocessSuffix) agent.cpp

$(IntermediateDirectory)/config.cpp$(ObjectSuffix): config.cpp $(IntermediateDirectory)/config.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/thefamousrat/Documents/ENSAI/Cpp/DM1/Contamination/Contamination/config.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/config.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/config.cpp$(DependSuffix): config.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/config.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/config.cpp$(DependSuffix) -MM config.cpp

$(IntermediateDirectory)/config.cpp$(PreprocessSuffix): config.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/config.cpp$(PreprocessSuffix) config.cpp

$(IntermediateDirectory)/zone.cpp$(ObjectSuffix): zone.cpp $(IntermediateDirectory)/zone.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/thefamousrat/Documents/ENSAI/Cpp/DM1/Contamination/Contamination/zone.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zone.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zone.cpp$(DependSuffix): zone.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zone.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/zone.cpp$(DependSuffix) -MM zone.cpp

$(IntermediateDirectory)/zone.cpp$(PreprocessSuffix): zone.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zone.cpp$(PreprocessSuffix) zone.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


