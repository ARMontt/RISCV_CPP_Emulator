#Compiler

CXX = g++

#Compiler Flags
CXXFLAGS = -Wall -Wextra -Iinclude

#Source Files
SRC = $(wildcard src/*.cpp) main.cpp
OBJ = $(SRC:.cpp=.o)

#Output executable
TARGET = test

#Rule to build the executable

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

#Rule to compile .cpp files into .o object files

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
#Run the executable after building
run: $(TARGET)
	./$(TARGET)

#Clean rule to remove compiled files
clean:
	rm -f $(OBJ) $(TARGET)

#Phony targets

.PHONY: clean run
