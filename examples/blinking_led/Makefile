FIRMWARE_DIR = ../../firmware
HDL_DIR = ../../hdl
INCLUDE_DIR = ../../libraries
VERILOG_FILES = \
           $(HDL_DIR)/top.v \
           $(HDL_DIR)/picosoc/uart/simpleuart.v \
           $(HDL_DIR)/picosoc/picosoc.v \
           $(HDL_DIR)/picorv32/picorv32.v \
           $(HDL_DIR)/picosoc/ili9341/ili9341_direct.v \
           $(HDL_DIR)/picosoc/sdcard/sdcard.v \
           $(HDL_DIR)/picosoc/spi_master/spi_master.v \
           $(HDL_DIR)/picosoc/flash_write/flash_write.v \
           $(HDL_DIR)/picosoc/gpio/gpio.v \

PCF_FILE = $(HDL_DIR)/pcbsd.pcf
LDS_FILE = $(FIRMWARE_DIR)/firmware.lds
START_FILE = $(FIRMWARE_DIR)/firmware.S
C_FILES = main.c 

DEFINES = -Dgpio -Dflash_write -Dwarm_boot

include $(HDL_DIR)/tiny_soc.mk

