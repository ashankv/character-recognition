# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ashank/CLionProjects/NaiveBayes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ashank/CLionProjects/NaiveBayes/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/NaiveBayes.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NaiveBayes.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NaiveBayes.dir/flags.make

CMakeFiles/NaiveBayes.dir/src/classifying_engine.cpp.o: CMakeFiles/NaiveBayes.dir/flags.make
CMakeFiles/NaiveBayes.dir/src/classifying_engine.cpp.o: ../src/classifying_engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ashank/CLionProjects/NaiveBayes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NaiveBayes.dir/src/classifying_engine.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NaiveBayes.dir/src/classifying_engine.cpp.o -c /Users/ashank/CLionProjects/NaiveBayes/src/classifying_engine.cpp

CMakeFiles/NaiveBayes.dir/src/classifying_engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NaiveBayes.dir/src/classifying_engine.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ashank/CLionProjects/NaiveBayes/src/classifying_engine.cpp > CMakeFiles/NaiveBayes.dir/src/classifying_engine.cpp.i

CMakeFiles/NaiveBayes.dir/src/classifying_engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NaiveBayes.dir/src/classifying_engine.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ashank/CLionProjects/NaiveBayes/src/classifying_engine.cpp -o CMakeFiles/NaiveBayes.dir/src/classifying_engine.cpp.s

CMakeFiles/NaiveBayes.dir/src/classifying_engine.cpp.o.requires:

.PHONY : CMakeFiles/NaiveBayes.dir/src/classifying_engine.cpp.o.requires

CMakeFiles/NaiveBayes.dir/src/classifying_engine.cpp.o.provides: CMakeFiles/NaiveBayes.dir/src/classifying_engine.cpp.o.requires
	$(MAKE) -f CMakeFiles/NaiveBayes.dir/build.make CMakeFiles/NaiveBayes.dir/src/classifying_engine.cpp.o.provides.build
.PHONY : CMakeFiles/NaiveBayes.dir/src/classifying_engine.cpp.o.provides

CMakeFiles/NaiveBayes.dir/src/classifying_engine.cpp.o.provides.build: CMakeFiles/NaiveBayes.dir/src/classifying_engine.cpp.o


CMakeFiles/NaiveBayes.dir/src/image_data.cpp.o: CMakeFiles/NaiveBayes.dir/flags.make
CMakeFiles/NaiveBayes.dir/src/image_data.cpp.o: ../src/image_data.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ashank/CLionProjects/NaiveBayes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/NaiveBayes.dir/src/image_data.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NaiveBayes.dir/src/image_data.cpp.o -c /Users/ashank/CLionProjects/NaiveBayes/src/image_data.cpp

CMakeFiles/NaiveBayes.dir/src/image_data.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NaiveBayes.dir/src/image_data.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ashank/CLionProjects/NaiveBayes/src/image_data.cpp > CMakeFiles/NaiveBayes.dir/src/image_data.cpp.i

CMakeFiles/NaiveBayes.dir/src/image_data.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NaiveBayes.dir/src/image_data.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ashank/CLionProjects/NaiveBayes/src/image_data.cpp -o CMakeFiles/NaiveBayes.dir/src/image_data.cpp.s

CMakeFiles/NaiveBayes.dir/src/image_data.cpp.o.requires:

.PHONY : CMakeFiles/NaiveBayes.dir/src/image_data.cpp.o.requires

CMakeFiles/NaiveBayes.dir/src/image_data.cpp.o.provides: CMakeFiles/NaiveBayes.dir/src/image_data.cpp.o.requires
	$(MAKE) -f CMakeFiles/NaiveBayes.dir/build.make CMakeFiles/NaiveBayes.dir/src/image_data.cpp.o.provides.build
.PHONY : CMakeFiles/NaiveBayes.dir/src/image_data.cpp.o.provides

CMakeFiles/NaiveBayes.dir/src/image_data.cpp.o.provides.build: CMakeFiles/NaiveBayes.dir/src/image_data.cpp.o


CMakeFiles/NaiveBayes.dir/src/model.cpp.o: CMakeFiles/NaiveBayes.dir/flags.make
CMakeFiles/NaiveBayes.dir/src/model.cpp.o: ../src/model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ashank/CLionProjects/NaiveBayes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/NaiveBayes.dir/src/model.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NaiveBayes.dir/src/model.cpp.o -c /Users/ashank/CLionProjects/NaiveBayes/src/model.cpp

CMakeFiles/NaiveBayes.dir/src/model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NaiveBayes.dir/src/model.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ashank/CLionProjects/NaiveBayes/src/model.cpp > CMakeFiles/NaiveBayes.dir/src/model.cpp.i

CMakeFiles/NaiveBayes.dir/src/model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NaiveBayes.dir/src/model.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ashank/CLionProjects/NaiveBayes/src/model.cpp -o CMakeFiles/NaiveBayes.dir/src/model.cpp.s

CMakeFiles/NaiveBayes.dir/src/model.cpp.o.requires:

.PHONY : CMakeFiles/NaiveBayes.dir/src/model.cpp.o.requires

CMakeFiles/NaiveBayes.dir/src/model.cpp.o.provides: CMakeFiles/NaiveBayes.dir/src/model.cpp.o.requires
	$(MAKE) -f CMakeFiles/NaiveBayes.dir/build.make CMakeFiles/NaiveBayes.dir/src/model.cpp.o.provides.build
.PHONY : CMakeFiles/NaiveBayes.dir/src/model.cpp.o.provides

CMakeFiles/NaiveBayes.dir/src/model.cpp.o.provides.build: CMakeFiles/NaiveBayes.dir/src/model.cpp.o


CMakeFiles/NaiveBayes.dir/src/training_data.cpp.o: CMakeFiles/NaiveBayes.dir/flags.make
CMakeFiles/NaiveBayes.dir/src/training_data.cpp.o: ../src/training_data.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ashank/CLionProjects/NaiveBayes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/NaiveBayes.dir/src/training_data.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NaiveBayes.dir/src/training_data.cpp.o -c /Users/ashank/CLionProjects/NaiveBayes/src/training_data.cpp

CMakeFiles/NaiveBayes.dir/src/training_data.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NaiveBayes.dir/src/training_data.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ashank/CLionProjects/NaiveBayes/src/training_data.cpp > CMakeFiles/NaiveBayes.dir/src/training_data.cpp.i

CMakeFiles/NaiveBayes.dir/src/training_data.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NaiveBayes.dir/src/training_data.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ashank/CLionProjects/NaiveBayes/src/training_data.cpp -o CMakeFiles/NaiveBayes.dir/src/training_data.cpp.s

CMakeFiles/NaiveBayes.dir/src/training_data.cpp.o.requires:

.PHONY : CMakeFiles/NaiveBayes.dir/src/training_data.cpp.o.requires

CMakeFiles/NaiveBayes.dir/src/training_data.cpp.o.provides: CMakeFiles/NaiveBayes.dir/src/training_data.cpp.o.requires
	$(MAKE) -f CMakeFiles/NaiveBayes.dir/build.make CMakeFiles/NaiveBayes.dir/src/training_data.cpp.o.provides.build
.PHONY : CMakeFiles/NaiveBayes.dir/src/training_data.cpp.o.provides

CMakeFiles/NaiveBayes.dir/src/training_data.cpp.o.provides.build: CMakeFiles/NaiveBayes.dir/src/training_data.cpp.o


CMakeFiles/NaiveBayes.dir/src/test_data.cpp.o: CMakeFiles/NaiveBayes.dir/flags.make
CMakeFiles/NaiveBayes.dir/src/test_data.cpp.o: ../src/test_data.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ashank/CLionProjects/NaiveBayes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/NaiveBayes.dir/src/test_data.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NaiveBayes.dir/src/test_data.cpp.o -c /Users/ashank/CLionProjects/NaiveBayes/src/test_data.cpp

CMakeFiles/NaiveBayes.dir/src/test_data.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NaiveBayes.dir/src/test_data.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ashank/CLionProjects/NaiveBayes/src/test_data.cpp > CMakeFiles/NaiveBayes.dir/src/test_data.cpp.i

CMakeFiles/NaiveBayes.dir/src/test_data.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NaiveBayes.dir/src/test_data.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ashank/CLionProjects/NaiveBayes/src/test_data.cpp -o CMakeFiles/NaiveBayes.dir/src/test_data.cpp.s

CMakeFiles/NaiveBayes.dir/src/test_data.cpp.o.requires:

.PHONY : CMakeFiles/NaiveBayes.dir/src/test_data.cpp.o.requires

CMakeFiles/NaiveBayes.dir/src/test_data.cpp.o.provides: CMakeFiles/NaiveBayes.dir/src/test_data.cpp.o.requires
	$(MAKE) -f CMakeFiles/NaiveBayes.dir/build.make CMakeFiles/NaiveBayes.dir/src/test_data.cpp.o.provides.build
.PHONY : CMakeFiles/NaiveBayes.dir/src/test_data.cpp.o.provides

CMakeFiles/NaiveBayes.dir/src/test_data.cpp.o.provides.build: CMakeFiles/NaiveBayes.dir/src/test_data.cpp.o


# Object files for target NaiveBayes
NaiveBayes_OBJECTS = \
"CMakeFiles/NaiveBayes.dir/src/classifying_engine.cpp.o" \
"CMakeFiles/NaiveBayes.dir/src/image_data.cpp.o" \
"CMakeFiles/NaiveBayes.dir/src/model.cpp.o" \
"CMakeFiles/NaiveBayes.dir/src/training_data.cpp.o" \
"CMakeFiles/NaiveBayes.dir/src/test_data.cpp.o"

# External object files for target NaiveBayes
NaiveBayes_EXTERNAL_OBJECTS =

NaiveBayes: CMakeFiles/NaiveBayes.dir/src/classifying_engine.cpp.o
NaiveBayes: CMakeFiles/NaiveBayes.dir/src/image_data.cpp.o
NaiveBayes: CMakeFiles/NaiveBayes.dir/src/model.cpp.o
NaiveBayes: CMakeFiles/NaiveBayes.dir/src/training_data.cpp.o
NaiveBayes: CMakeFiles/NaiveBayes.dir/src/test_data.cpp.o
NaiveBayes: CMakeFiles/NaiveBayes.dir/build.make
NaiveBayes: CMakeFiles/NaiveBayes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ashank/CLionProjects/NaiveBayes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable NaiveBayes"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NaiveBayes.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NaiveBayes.dir/build: NaiveBayes

.PHONY : CMakeFiles/NaiveBayes.dir/build

CMakeFiles/NaiveBayes.dir/requires: CMakeFiles/NaiveBayes.dir/src/classifying_engine.cpp.o.requires
CMakeFiles/NaiveBayes.dir/requires: CMakeFiles/NaiveBayes.dir/src/image_data.cpp.o.requires
CMakeFiles/NaiveBayes.dir/requires: CMakeFiles/NaiveBayes.dir/src/model.cpp.o.requires
CMakeFiles/NaiveBayes.dir/requires: CMakeFiles/NaiveBayes.dir/src/training_data.cpp.o.requires
CMakeFiles/NaiveBayes.dir/requires: CMakeFiles/NaiveBayes.dir/src/test_data.cpp.o.requires

.PHONY : CMakeFiles/NaiveBayes.dir/requires

CMakeFiles/NaiveBayes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NaiveBayes.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NaiveBayes.dir/clean

CMakeFiles/NaiveBayes.dir/depend:
	cd /Users/ashank/CLionProjects/NaiveBayes/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ashank/CLionProjects/NaiveBayes /Users/ashank/CLionProjects/NaiveBayes /Users/ashank/CLionProjects/NaiveBayes/cmake-build-debug /Users/ashank/CLionProjects/NaiveBayes/cmake-build-debug /Users/ashank/CLionProjects/NaiveBayes/cmake-build-debug/CMakeFiles/NaiveBayes.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NaiveBayes.dir/depend

