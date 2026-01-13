# Prototype
# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
# 	$(CC) $(CFLAGS) $^ -o $@

CC = arm-none-eabi-gcc
CXX = arm-none-eabi-g++
AS = arm-none-eabi-gcc

CFLAGS = -mcpu=cortex-m0 -DSTM32 -DSTM32F0 -DSTM32F030F4Px -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -mfloat-abi=soft -mthumb
CXXFLAGS = $(CFLAGS) -std=c++11 -Iinclude/ -c
LDFLAGS = -mcpu=cortex-m0 --specs=nosys.specs "-Wl,-Map=build/build.map" "-Wl,--gc-sections" -static --specs=nano.specs -mfloat-abi=soft -mthumb "-Wl,--start-group" -lc -lm -lstdc++ -lsupc++ "-Wl,--end-group"
AS_FLAGS = -mcpu=cortex-m0 -mthumb -x assembler-with-cpp -c
SRC_DIR = src
OBJ_DIR = build/obj
BIN_DIR = build/bin
OBJS = \
	$(OBJ_DIR)/startup_stm32f030f4px.o \
	$(OBJ_DIR)/main.o \
	$(OBJ_DIR)/gpio.o

LD_SCRIPT = STM32F030F4PX_FLASH.ld

# OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

.PHONY : all clean

all: $(BIN_DIR)/main.elf

# Ensure OBJ_DIR exists
$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

# Ensure BIN_DIR exists
$(BIN_DIR) :
	mkdir $(BIN_DIR)

$(OBJ_DIR)/main.o : $(SRC_DIR)/main.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/gpio.o : $(SRC_DIR)/gpio.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/startup_stm32f030f4px.o : startup/startup_stm32f030f4px.s | $(OBJ_DIR)
	$(AS) $(AS_FLAGS) $^ -o $@

$(BIN_DIR)/main.elf : $(OBJS) | $(BIN_DIR)
	$(CXX) $(LDFLAGS) -T$(LD_SCRIPT) $^ -o $@

clean :
	rm build
