# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/pacoalgar/.local/lib/python3.10/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/pacoalgar/.local/lib/python3.10/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pacoalgar/Documentos/uco/3º/alg/p1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pacoalgar/Documentos/uco/3º/alg/p1/build

# Include any dependencies generated for this target.
include CMakeFiles/p1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/p1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/p1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/p1.dir/flags.make

CMakeFiles/p1.dir/main.cpp.o: CMakeFiles/p1.dir/flags.make
CMakeFiles/p1.dir/main.cpp.o: /home/pacoalgar/Documentos/uco/3º/alg/p1/main.cpp
CMakeFiles/p1.dir/main.cpp.o: CMakeFiles/p1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pacoalgar/Documentos/uco/3º/alg/p1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/p1.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/p1.dir/main.cpp.o -MF CMakeFiles/p1.dir/main.cpp.o.d -o CMakeFiles/p1.dir/main.cpp.o -c /home/pacoalgar/Documentos/uco/3º/alg/p1/main.cpp

CMakeFiles/p1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pacoalgar/Documentos/uco/3º/alg/p1/main.cpp > CMakeFiles/p1.dir/main.cpp.i

CMakeFiles/p1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pacoalgar/Documentos/uco/3º/alg/p1/main.cpp -o CMakeFiles/p1.dir/main.cpp.s

CMakeFiles/p1.dir/functions.cpp.o: CMakeFiles/p1.dir/flags.make
CMakeFiles/p1.dir/functions.cpp.o: /home/pacoalgar/Documentos/uco/3º/alg/p1/functions.cpp
CMakeFiles/p1.dir/functions.cpp.o: CMakeFiles/p1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pacoalgar/Documentos/uco/3º/alg/p1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/p1.dir/functions.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/p1.dir/functions.cpp.o -MF CMakeFiles/p1.dir/functions.cpp.o.d -o CMakeFiles/p1.dir/functions.cpp.o -c /home/pacoalgar/Documentos/uco/3º/alg/p1/functions.cpp

CMakeFiles/p1.dir/functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p1.dir/functions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pacoalgar/Documentos/uco/3º/alg/p1/functions.cpp > CMakeFiles/p1.dir/functions.cpp.i

CMakeFiles/p1.dir/functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p1.dir/functions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pacoalgar/Documentos/uco/3º/alg/p1/functions.cpp -o CMakeFiles/p1.dir/functions.cpp.s

CMakeFiles/p1.dir/ClaseTiempo.cpp.o: CMakeFiles/p1.dir/flags.make
CMakeFiles/p1.dir/ClaseTiempo.cpp.o: /home/pacoalgar/Documentos/uco/3º/alg/p1/ClaseTiempo.cpp
CMakeFiles/p1.dir/ClaseTiempo.cpp.o: CMakeFiles/p1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pacoalgar/Documentos/uco/3º/alg/p1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/p1.dir/ClaseTiempo.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/p1.dir/ClaseTiempo.cpp.o -MF CMakeFiles/p1.dir/ClaseTiempo.cpp.o.d -o CMakeFiles/p1.dir/ClaseTiempo.cpp.o -c /home/pacoalgar/Documentos/uco/3º/alg/p1/ClaseTiempo.cpp

CMakeFiles/p1.dir/ClaseTiempo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p1.dir/ClaseTiempo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pacoalgar/Documentos/uco/3º/alg/p1/ClaseTiempo.cpp > CMakeFiles/p1.dir/ClaseTiempo.cpp.i

CMakeFiles/p1.dir/ClaseTiempo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p1.dir/ClaseTiempo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pacoalgar/Documentos/uco/3º/alg/p1/ClaseTiempo.cpp -o CMakeFiles/p1.dir/ClaseTiempo.cpp.s

CMakeFiles/p1.dir/sistemaEcuaciones.cpp.o: CMakeFiles/p1.dir/flags.make
CMakeFiles/p1.dir/sistemaEcuaciones.cpp.o: /home/pacoalgar/Documentos/uco/3º/alg/p1/sistemaEcuaciones.cpp
CMakeFiles/p1.dir/sistemaEcuaciones.cpp.o: CMakeFiles/p1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pacoalgar/Documentos/uco/3º/alg/p1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/p1.dir/sistemaEcuaciones.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/p1.dir/sistemaEcuaciones.cpp.o -MF CMakeFiles/p1.dir/sistemaEcuaciones.cpp.o.d -o CMakeFiles/p1.dir/sistemaEcuaciones.cpp.o -c /home/pacoalgar/Documentos/uco/3º/alg/p1/sistemaEcuaciones.cpp

CMakeFiles/p1.dir/sistemaEcuaciones.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p1.dir/sistemaEcuaciones.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pacoalgar/Documentos/uco/3º/alg/p1/sistemaEcuaciones.cpp > CMakeFiles/p1.dir/sistemaEcuaciones.cpp.i

CMakeFiles/p1.dir/sistemaEcuaciones.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p1.dir/sistemaEcuaciones.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pacoalgar/Documentos/uco/3º/alg/p1/sistemaEcuaciones.cpp -o CMakeFiles/p1.dir/sistemaEcuaciones.cpp.s

# Object files for target p1
p1_OBJECTS = \
"CMakeFiles/p1.dir/main.cpp.o" \
"CMakeFiles/p1.dir/functions.cpp.o" \
"CMakeFiles/p1.dir/ClaseTiempo.cpp.o" \
"CMakeFiles/p1.dir/sistemaEcuaciones.cpp.o"

# External object files for target p1
p1_EXTERNAL_OBJECTS =

p1: CMakeFiles/p1.dir/main.cpp.o
p1: CMakeFiles/p1.dir/functions.cpp.o
p1: CMakeFiles/p1.dir/ClaseTiempo.cpp.o
p1: CMakeFiles/p1.dir/sistemaEcuaciones.cpp.o
p1: CMakeFiles/p1.dir/build.make
p1: CMakeFiles/p1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pacoalgar/Documentos/uco/3º/alg/p1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable p1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/p1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/p1.dir/build: p1
.PHONY : CMakeFiles/p1.dir/build

CMakeFiles/p1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/p1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/p1.dir/clean

CMakeFiles/p1.dir/depend:
	cd /home/pacoalgar/Documentos/uco/3º/alg/p1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pacoalgar/Documentos/uco/3º/alg/p1 /home/pacoalgar/Documentos/uco/3º/alg/p1 /home/pacoalgar/Documentos/uco/3º/alg/p1/build /home/pacoalgar/Documentos/uco/3º/alg/p1/build /home/pacoalgar/Documentos/uco/3º/alg/p1/build/CMakeFiles/p1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/p1.dir/depend

