MCU=atmega162

CC=avr-gcc
LD=avr-objcopy
DOWNLOAD=avrdude
INSTALL=$(DOWNLOAD)
MKDIR=mkdir
RM=rm

SRC_DIR=src
BUILD_DIR=build
ELF_DIR=$(BUILD_DIR)/elf
HEX_DIR=$(BUILD_DIR)/hex

#CLK_DELAY='-i 1000'
CLK_DELAY=

all: .pre-build $(HEX_DIR)/main.hex


$(HEX_DIR)/%.hex: $(ELF_DIR)/%.elf
	$(LD) -j .text -j .data -O ihex $< $@

$(ELF_DIR)/%.elf: $(SRC_DIR)/%.c
	$(CC) -mmcu=$(MCU) -Wall -Os -o $@ $<

install: $(HEX_DIR)/main.hex
	$(DOWNLOAD) -p m8 -c ponyser -P /dev/ttyUSB0 $(CLK_DELAY) -U flash:w:$^

read-fusebits:
	$(DOWNLOAD) -p m8 -c ponyser -P /dev/ttyUSB0 $(CLK_DELAY) -U lfuse:r:-:i

.pre-build:
	$(MKDIR) -p $(BUILD_DIR)
	$(MKDIR) -p $(ELF_DIR)
	$(MKDIR) -p $(HEX_DIR)

clean:
	$(RM) -rf $(BUILD_DIR)
