
EXENAME = main
OBJS = main.o fileToVector.o GetDistance.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME) : output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp fileToVector.h fileToVector.cpp GetDistance.h GetDistance.cpp
	$(CXX) $(CXXFLAGS) main.cpp

fileToVector.o : fileToVector.h fileToVector.cpp
	$(CXX) $(CXXFLAGS) fileToVector.cpp

GetDistance.o : GetDistance.h GetDistance.cpp
	$(CXX) $(CXXFLAGS) GetDistance.cpp







