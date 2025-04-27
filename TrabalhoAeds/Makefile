CXX      := g++
CXXFLAGS := -Wall -Wextra
LDFLAGS  := -lstdc++ -lm
BUILD    := build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)
TARGET   := app.exe
INCLUDE  := -Iinclude/
SRC      := $(wildcard src/*.cpp)

OBJECTS := $(patsubst src/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: src/%.cpp
	@if not exist "$(OBJ_DIR)" mkdir "$(OBJ_DIR)"
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@if not exist "$(APP_DIR)" mkdir "$(APP_DIR)"
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) -o $(APP_DIR)/$(TARGET) $(OBJECTS)

.PHONY: all build clean debug release run

build:
	@if not exist "$(APP_DIR)" mkdir "$(APP_DIR)"
	@if not exist "$(OBJ_DIR)" mkdir "$(OBJ_DIR)"

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O3
release: all

clean:
	@if exist "$(OBJ_DIR)" rmdir /s /q "$(OBJ_DIR)"
	@if exist "$(APP_DIR)\$(TARGET)" del /s /q "$(APP_DIR)\$(TARGET)"

run:
	$(APP_DIR)/$(TARGET)

r: clean all run
