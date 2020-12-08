<<<<<<< HEAD
EXENAME = main
OBJS = main.o fileToVector.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME) : output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp fileToVector.h fileToVector.cpp
	$(CXX) $(CXXFLAGS) main.cpp

fileToVector.o : fileToVector.h fileToVector.cpp
	$(CXX) $(CXXFLAGS) fileToVector.cpp








=======
# Executable names:
EXE = main
TEST = test

# Add all object files needed for compiling:
EXE_OBJ = main.o
OBJS = graph.o main.o vertexmaker.o fileToVector.o

# Generated files
CLEAN_RM = images/Out.png
>>>>>>> 4b0c25eaf5c5405d458c701fc53d74f8d3ce6a6d
