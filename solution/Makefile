# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g -std=c++11

# Directories
SRC_DIRS = Autocompletar Functions Termo
INC_DIRS = Autocompletar Functions Listas Termo

# Source files
SRC_FILES = main.cpp \
						Autocompletar/autocompletar.cpp \
						Functions/execution.cpp \
						Functions/tests.cpp \
						Termo/termo.cpp

# Header files for dependency generation
HDR_FILES = $(wildcard Autocompletar/*.h) \
						$(wildcard Functions/*.h) \
						$(wildcard Listas/*.h) \
						$(wildcard Termo/*.h)

# Object files
OBJ_FILES = $(SRC_FILES:.cpp=.o)

# Include directories
INC_FLAGS = $(addprefix -I, $(INC_DIRS))

# Executable name
TARGET = Main

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilation
%.o: %.cpp $(HDR_FILES)
	$(CXX) $(CXXFLAGS) $(INC_FLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJ_FILES) $(TARGET)

.PHONY: all clean
