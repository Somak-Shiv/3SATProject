CXX = g++ # C++ compiler
CXXFLAGS = -std=c++17 -O2 # I use C++17 and optimization level 2

EXEC = Main # Name of the executable

SRCS = Main.cpp RandomInstanceGeneration.cpp RandomSearch.cpp ExhaustiveSearch.cpp # Source files
OBJS = $(SRCS:.cpp=.o) # Object files
HEADERS = RandomInstanceGeneration.h RandomSearch.h ExhaustiveSearch.h # *.h Header files

all: $(EXEC) # make all

$(EXEC): $(OBJS) # object files
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS) 

%.o: %.cpp $(HEADERS) # compile each object file
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean: # clean only objects (to keep executable)
	rm -f $(OBJS)

clean-all: clean # clean all
	rm -f $(EXEC)