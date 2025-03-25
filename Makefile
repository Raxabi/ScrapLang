CXX = g++
CXXFLAGS = -Iincludes -Wall -Wextra -std=c++23
LDFLAGS =
SRC = $(wildcard ./src/*.cc) $(wildcard ./src/frontend/*.cc) $(wildcard ./src/frontend/**/*.cc) $(wildcard ./src/engine/**/*.cc)
TARGET = ./build/ccscrap

# Executable compilation
$(TARGET): $(SRC)
	$(CXX) $(LDFLAGS) $(CXXFLAGS) $(SRC) -o $@

# Main rule
all: $(TARGET)

# Clean intermediate file
clean:
	rm -f $(TARGET)

print-%:
	@echo $* = $($*)

# Phony targets
.PHONY: all clean
