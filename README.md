
# Bare-Metal ARM Example (STM32F030F4Px) - GPIO

This project is a **basic example of coding bare-metal applications** for ARM Cortex-M microcontrollers using the STM32F030F4P6.  
Any similar STM32F030F4Px board (like P4 or P6 variants) will generally work.

The example demonstrates how to compile, link, and flash a simple program without using STM32Cube or HAL libraries, using only ARM-GCC toolchain commands.

---

## Build Instructions (PowerShell)

```powershell
# Assemble the startup file
arm-none-eabi-g++ -mcpu=cortex-m0 -c -x assembler-with-cpp -MMD -MF"build/obj/startup_stm32f030f4px.d" -MT"build/obj/startup_stm32f030f4px.o" --specs=nano.specs -mfloat-abi=soft -mthumb -o "build/obj/startup_stm32f030f4px.o" "startup/startup_stm32f030f4px.s"

# Compile the main source file
arm-none-eabi-g++ "src/main.cpp" -mcpu=cortex-m0 -std=c++11 -DSTM32 -DSTM32F0 -DSTM32F030F4Px -c -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"build/obj/main.d" --specs=nano.specs -mfloat-abi=soft -mthumb -o "build/obj/main.o"

# Link everything into an ELF file
arm-none-eabi-g++ -o "build/build.elf" "build/obj/main.o" "build/obj/startup_stm32f030f4px.o" -mcpu=cortex-m0 -T"STM32F030F4PX_FLASH.ld" --specs=nosys.specs "-Wl,-Map=build/build.map" "-Wl,--gc-sections" -static --specs=nano.specs -mfloat-abi=soft -mthumb "-Wl,--start-group" -lc -lm -lstdc++ -lsupc++ "-Wl,--end-group"

# Check ELF size
arm-none-eabi-size build/build.elf

# View ELF sections
arm-none-eabi-objdump -h -s .\build\build.elf
````

The compiled ELF file will be located at:

```
build/build.elf
```

---

## Flashing with OpenOCD

```powershell
openocd -f openocd/scripts/interfaces/stlink.cfg
```

---

## Upload via GDB

```powershell
arm-none-eabi-gdb
target remote localhost:3333
monitor reset init
monitor flash write_image erase build/build.elf
continue
```

---

### Notes

* Ensure `arm-none-eabi-gcc` and `openocd` are installed and added to your system PATH.
* The `.ld` linker script must match your STM32F030F4Px memory map.
* If you dont wish to install all these but still wish to test it out, you can get the pre-built `.elf` at `build/build.elf` 

```
