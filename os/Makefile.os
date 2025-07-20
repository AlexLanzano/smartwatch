include .config
ifdef CONFIG_CORTEX_M
GCC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy
AR = arm-none-eabi-ar
CFLAGS += -mcpu=cortex-m4
LDFLAGS ?= -static -nostartfiles -specs=nosys.specs -specs=nano.specs -mthumb
endif

os.bin: os.elf
	$(OBJCOPY) $^ -O binary $@

os.elf: $(bins)
	$(GCC) $(LDFLAGS) -T configs/$(CONFIG_LINKER_SCRIPT) -o $@ $^
