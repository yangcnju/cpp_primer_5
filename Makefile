# OBJS specifies which files to compile as part of the project
#OBJS = main.cc
#OBJS = ex13.40.cc StrVec.cc
#OBJS = ex13.46.cc
OBJS = ex13.48.main.cc String.cc

# CPP specifies compiler
CPP = g++

# INCLUDE_PATHS specifies additional include paths
INCLUDE_PATHS = -I/usr/local/include
#-I/opt/X11/include

# LIBRARY_PATHS specifies additional library
LIBRARY_PATHS = -L/usr/local/lib 
#-L/opt/X11/lib

# C++ 11 standard
COMPILER_FLAGS = -Wall -std=gnu++11

# Cocoa, IOKit, and CoreVideo are needed for static GLFW3
#LINKER_FLAGS = -framework OpenGL -lglfw3 -lglew

# OBJ_NAME specifies the name of exectuable
OBJ_NAME = main

# This is the target that compiles executable
all : $(OBJS)
	$(CPP) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(OBJS) $(LINKER_FLAGS) -o $(OBJ_NAME)
