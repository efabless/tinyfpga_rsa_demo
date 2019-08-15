FIRMWARE_DIR = ../../firmware
HDL_DIR = ../../hdl
INCLUDE_DIR = ../../libraries
VERILOG_FILES = \
           $(HDL_DIR)/top.v \
           $(HDL_DIR)/picosoc/uart/simpleuart.v \
           $(HDL_DIR)/picosoc/picosoc.v \
           $(HDL_DIR)/picorv32/picorv32.v \
           $(HDL_DIR)/picosoc/spi_master/spi_master.v \
           $(HDL_DIR)/picosoc/i2c/i2c.v \
           $(HDL_DIR)/picosoc/nunchuk/I2C_master.v \
           $(HDL_DIR)/picosoc/pll/pll.v \
           $(HDL_DIR)/picosoc/gpio/gpio.v \

PCF_FILE = $(HDL_DIR)/pins.pcf
LDS_FILE = $(FIRMWARE_DIR)/firmware.lds
START_FILE = $(FIRMWARE_DIR)/firmware.S
C_FILES = main.c \
          $(INCLUDE_DIR)/delay/delay.c \
          $(INCLUDE_DIR)/uart/uart.c \
          $(INCLUDE_DIR)/string/string.c \
          $(INCLUDE_DIR)/rsa/rsa.c

DEFINES = -Dgpio -Dwarm_boot -Di2c -Dpll
#LINKER_FLAGS = -static-libgcc -lgcc
LINKER_FLAGS = -lgcc

include $(HDL_DIR)/tiny_soc.mk

