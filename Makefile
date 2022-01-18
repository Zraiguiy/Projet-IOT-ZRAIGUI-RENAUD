APPLICATION = cayenne

BOARD ?= lora-e5-dev

RIOTBASE ?= $(CURDIR)/../../RIOT

# Default LoRa region is Europe and default band is 868MHz
LORA_REGION ?= EU868

USEMODULE += xtimer
USEMODULE += lm75a
USEMODULE += sx126x_stm32wl


# BME280 connected via I2C
USEMODULE += bme280_i2c

# When using I2C, specify the default I2C device to use,
# and the BME280's address (see datasheet).
# The values below are the defaults:
CFLAGS += -DBMX280_PARAM_I2C_DEV=I2C_DEV\‍ttyACM0\‍
CFLAGS += -DBMX280_PARAM_I2C_ADDR=0x77


USEPKG += semtech-loramac
USEMODULE += semtech_loramac_rx
USEMODULE += auto_init_loramac
USEPKG += cayenne-lpp

include $(RIOTBASE)/Makefile.include
