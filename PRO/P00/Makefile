# Set gcc as the C++ compiler
CXX=g++

# Enforce C++ 2011 as the language standard
CXXFLAGS=-std=c++11  -pedantic

# Enable all standard warnings, uninitialized variable warnings, 
# and treat all warnings as errors
CXXFLAGS+= -Wall -Wuninitialized -Werror

# Generate code with debugging information
# (for use with a debugger like gdb)
CXXFLAGS+= -g

# Link with math library
CXXFLAGS+= -lm

# Enable ASan (Address Sanitizer) 
# and UBSan (Undefined Behavior Sanitizer)
#
# NOTE: comment these temporarily if 
# your development environment is failing
# due to these settings - it is important that 
# you fix your environment at some point.
CXXFLAGS+=-fsanitize=address -fsanitize=undefined


# The settings below are necessary only 
# in the case of multiple source files

# C++ source files to consider in compilation
CPP_FILES=
# C++ header files to consider in compilation
HEADERS=
# Name of executable program
PROG=

$(PROG): $(CPP_FILES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(CPP_FILES) -o $(PROG)
