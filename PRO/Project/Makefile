# Set gcc as the C++ compiler
CXX=g++
CXXFLAGS=-std=c++11  -pedantic -Wall -Wuninitialized -Werror -g -fsanitize=address -fsanitize=undefined

HEADERS= external/tinyxml2/tinyxml2.h \
		Color.hpp \
		PNGImage.hpp \
		Point.hpp \
		SVGElements.hpp

COMMON_OBJ_FILES= external/tinyxml2/tinyxml2.o \
 				  Color.o \
				  Point.o \
				  PNGImage.o \
				  Point.o \
				  SVGElements.o \
				  readSVG.o \
				  convert.o 

LIBRARY=libproj.a
PROGRAMS=svgtopng test xmldump

all:  $(PROGRAMS)

%.o: $(HEADERS) %.cpp
	$(CXX) $(CXXFLAGS) -c -o $*.o $*.cpp

$(LIBRARY): $(COMMON_OBJ_FILES)
	ar cr $(LIBRARY) $(COMMON_OBJ_FILES)

test: test.o $(LIBRARY)
	$(CXX) $(CXXFLAGS) -o test test.o $(LIBRARY)

xmldump: xmldump.o $(LIBRARY)
	$(CXX) $(CXXFLAGS) -o xmldump xmldump.o $(LIBRARY)

svgtopng: svgtopng.o $(LIBRARY)
	$(CXX) $(CXXFLAGS) -o svgtopng svgtopng.o $(LIBRARY)

clean: 
	rm -f test_log.txt test.o xmldump.o svgtopng.o  $(COMMON_OBJ_FILES) output/* $(PROGRAMS) $(LIBRARY) delivery.zip

delivery.zip: 
	rm -f delivery.zip
	zip -9r delivery.zip README.md SVGElements.hpp SVGElements.cpp readSVG.cpp