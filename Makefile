# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/diego/Repos/uOLED

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/diego/Repos/uOLED

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/diego/Repos/uOLED/CMakeFiles /home/diego/Repos/uOLED/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/diego/Repos/uOLED/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named upload

# Build rule for target.
upload: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 upload
.PHONY : upload

# fast build rule for target.
upload/fast:
	$(MAKE) -f CMakeFiles/upload.dir/build.make CMakeFiles/upload.dir/build
.PHONY : upload/fast

#=============================================================================
# Target rules for targets named uDisplay

# Build rule for target.
uDisplay: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 uDisplay
.PHONY : uDisplay

# fast build rule for target.
uDisplay/fast:
	$(MAKE) -f CMakeFiles/uDisplay.dir/build.make CMakeFiles/uDisplay.dir/build
.PHONY : uDisplay/fast

include/Drivers/Protocols/uD_I2C.o: include/Drivers/Protocols/uD_I2C.c.o

.PHONY : include/Drivers/Protocols/uD_I2C.o

# target to build an object file
include/Drivers/Protocols/uD_I2C.c.o:
	$(MAKE) -f CMakeFiles/uDisplay.dir/build.make CMakeFiles/uDisplay.dir/include/Drivers/Protocols/uD_I2C.c.o
.PHONY : include/Drivers/Protocols/uD_I2C.c.o

include/Drivers/Protocols/uD_I2C.i: include/Drivers/Protocols/uD_I2C.c.i

.PHONY : include/Drivers/Protocols/uD_I2C.i

# target to preprocess a source file
include/Drivers/Protocols/uD_I2C.c.i:
	$(MAKE) -f CMakeFiles/uDisplay.dir/build.make CMakeFiles/uDisplay.dir/include/Drivers/Protocols/uD_I2C.c.i
.PHONY : include/Drivers/Protocols/uD_I2C.c.i

include/Drivers/Protocols/uD_I2C.s: include/Drivers/Protocols/uD_I2C.c.s

.PHONY : include/Drivers/Protocols/uD_I2C.s

# target to generate assembly for a file
include/Drivers/Protocols/uD_I2C.c.s:
	$(MAKE) -f CMakeFiles/uDisplay.dir/build.make CMakeFiles/uDisplay.dir/include/Drivers/Protocols/uD_I2C.c.s
.PHONY : include/Drivers/Protocols/uD_I2C.c.s

include/Drivers/Protocols/uD_SPI.o: include/Drivers/Protocols/uD_SPI.c.o

.PHONY : include/Drivers/Protocols/uD_SPI.o

# target to build an object file
include/Drivers/Protocols/uD_SPI.c.o:
	$(MAKE) -f CMakeFiles/uDisplay.dir/build.make CMakeFiles/uDisplay.dir/include/Drivers/Protocols/uD_SPI.c.o
.PHONY : include/Drivers/Protocols/uD_SPI.c.o

include/Drivers/Protocols/uD_SPI.i: include/Drivers/Protocols/uD_SPI.c.i

.PHONY : include/Drivers/Protocols/uD_SPI.i

# target to preprocess a source file
include/Drivers/Protocols/uD_SPI.c.i:
	$(MAKE) -f CMakeFiles/uDisplay.dir/build.make CMakeFiles/uDisplay.dir/include/Drivers/Protocols/uD_SPI.c.i
.PHONY : include/Drivers/Protocols/uD_SPI.c.i

include/Drivers/Protocols/uD_SPI.s: include/Drivers/Protocols/uD_SPI.c.s

.PHONY : include/Drivers/Protocols/uD_SPI.s

# target to generate assembly for a file
include/Drivers/Protocols/uD_SPI.c.s:
	$(MAKE) -f CMakeFiles/uDisplay.dir/build.make CMakeFiles/uDisplay.dir/include/Drivers/Protocols/uD_SPI.c.s
.PHONY : include/Drivers/Protocols/uD_SPI.c.s

include/Drivers/uD_SSD1306_Driver.o: include/Drivers/uD_SSD1306_Driver.c.o

.PHONY : include/Drivers/uD_SSD1306_Driver.o

# target to build an object file
include/Drivers/uD_SSD1306_Driver.c.o:
	$(MAKE) -f CMakeFiles/uDisplay.dir/build.make CMakeFiles/uDisplay.dir/include/Drivers/uD_SSD1306_Driver.c.o
.PHONY : include/Drivers/uD_SSD1306_Driver.c.o

include/Drivers/uD_SSD1306_Driver.i: include/Drivers/uD_SSD1306_Driver.c.i

.PHONY : include/Drivers/uD_SSD1306_Driver.i

# target to preprocess a source file
include/Drivers/uD_SSD1306_Driver.c.i:
	$(MAKE) -f CMakeFiles/uDisplay.dir/build.make CMakeFiles/uDisplay.dir/include/Drivers/uD_SSD1306_Driver.c.i
.PHONY : include/Drivers/uD_SSD1306_Driver.c.i

include/Drivers/uD_SSD1306_Driver.s: include/Drivers/uD_SSD1306_Driver.c.s

.PHONY : include/Drivers/uD_SSD1306_Driver.s

# target to generate assembly for a file
include/Drivers/uD_SSD1306_Driver.c.s:
	$(MAKE) -f CMakeFiles/uDisplay.dir/build.make CMakeFiles/uDisplay.dir/include/Drivers/uD_SSD1306_Driver.c.s
.PHONY : include/Drivers/uD_SSD1306_Driver.c.s

include/Drivers/uD_ST7789_Driver.o: include/Drivers/uD_ST7789_Driver.c.o

.PHONY : include/Drivers/uD_ST7789_Driver.o

# target to build an object file
include/Drivers/uD_ST7789_Driver.c.o:
	$(MAKE) -f CMakeFiles/uDisplay.dir/build.make CMakeFiles/uDisplay.dir/include/Drivers/uD_ST7789_Driver.c.o
.PHONY : include/Drivers/uD_ST7789_Driver.c.o

include/Drivers/uD_ST7789_Driver.i: include/Drivers/uD_ST7789_Driver.c.i

.PHONY : include/Drivers/uD_ST7789_Driver.i

# target to preprocess a source file
include/Drivers/uD_ST7789_Driver.c.i:
	$(MAKE) -f CMakeFiles/uDisplay.dir/build.make CMakeFiles/uDisplay.dir/include/Drivers/uD_ST7789_Driver.c.i
.PHONY : include/Drivers/uD_ST7789_Driver.c.i

include/Drivers/uD_ST7789_Driver.s: include/Drivers/uD_ST7789_Driver.c.s

.PHONY : include/Drivers/uD_ST7789_Driver.s

# target to generate assembly for a file
include/Drivers/uD_ST7789_Driver.c.s:
	$(MAKE) -f CMakeFiles/uDisplay.dir/build.make CMakeFiles/uDisplay.dir/include/Drivers/uD_ST7789_Driver.c.s
.PHONY : include/Drivers/uD_ST7789_Driver.c.s

include/Engines/uD_2dRendererEngine.o: include/Engines/uD_2dRendererEngine.c.o

.PHONY : include/Engines/uD_2dRendererEngine.o

# target to build an object file
include/Engines/uD_2dRendererEngine.c.o:
	$(MAKE) -f CMakeFiles/uDisplay.dir/build.make CMakeFiles/uDisplay.dir/include/Engines/uD_2dRendererEngine.c.o
.PHONY : include/Engines/uD_2dRendererEngine.c.o

include/Engines/uD_2dRendererEngine.i: include/Engines/uD_2dRendererEngine.c.i

.PHONY : include/Engines/uD_2dRendererEngine.i

# target to preprocess a source file
include/Engines/uD_2dRendererEngine.c.i:
	$(MAKE) -f CMakeFiles/uDisplay.dir/build.make CMakeFiles/uDisplay.dir/include/Engines/uD_2dRendererEngine.c.i
.PHONY : include/Engines/uD_2dRendererEngine.c.i

include/Engines/uD_2dRendererEngine.s: include/Engines/uD_2dRendererEngine.c.s

.PHONY : include/Engines/uD_2dRendererEngine.s

# target to generate assembly for a file
include/Engines/uD_2dRendererEngine.c.s:
	$(MAKE) -f CMakeFiles/uDisplay.dir/build.make CMakeFiles/uDisplay.dir/include/Engines/uD_2dRendererEngine.c.s
.PHONY : include/Engines/uD_2dRendererEngine.c.s

include/Render/uD_Renderer.o: include/Render/uD_Renderer.c.o

.PHONY : include/Render/uD_Renderer.o

# target to build an object file
include/Render/uD_Renderer.c.o:
	$(MAKE) -f CMakeFiles/uDisplay.dir/build.make CMakeFiles/uDisplay.dir/include/Render/uD_Renderer.c.o
.PHONY : include/Render/uD_Renderer.c.o

include/Render/uD_Renderer.i: include/Render/uD_Renderer.c.i

.PHONY : include/Render/uD_Renderer.i

# target to preprocess a source file
include/Render/uD_Renderer.c.i:
	$(MAKE) -f CMakeFiles/uDisplay.dir/build.make CMakeFiles/uDisplay.dir/include/Render/uD_Renderer.c.i
.PHONY : include/Render/uD_Renderer.c.i

include/Render/uD_Renderer.s: include/Render/uD_Renderer.c.s

.PHONY : include/Render/uD_Renderer.s

# target to generate assembly for a file
include/Render/uD_Renderer.c.s:
	$(MAKE) -f CMakeFiles/uDisplay.dir/build.make CMakeFiles/uDisplay.dir/include/Render/uD_Renderer.c.s
.PHONY : include/Render/uD_Renderer.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... upload"
	@echo "... uDisplay"
	@echo "... include/Drivers/Protocols/uD_I2C.o"
	@echo "... include/Drivers/Protocols/uD_I2C.i"
	@echo "... include/Drivers/Protocols/uD_I2C.s"
	@echo "... include/Drivers/Protocols/uD_SPI.o"
	@echo "... include/Drivers/Protocols/uD_SPI.i"
	@echo "... include/Drivers/Protocols/uD_SPI.s"
	@echo "... include/Drivers/uD_SSD1306_Driver.o"
	@echo "... include/Drivers/uD_SSD1306_Driver.i"
	@echo "... include/Drivers/uD_SSD1306_Driver.s"
	@echo "... include/Drivers/uD_ST7789_Driver.o"
	@echo "... include/Drivers/uD_ST7789_Driver.i"
	@echo "... include/Drivers/uD_ST7789_Driver.s"
	@echo "... include/Engines/uD_2dRendererEngine.o"
	@echo "... include/Engines/uD_2dRendererEngine.i"
	@echo "... include/Engines/uD_2dRendererEngine.s"
	@echo "... include/Render/uD_Renderer.o"
	@echo "... include/Render/uD_Renderer.i"
	@echo "... include/Render/uD_Renderer.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

