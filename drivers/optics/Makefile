KBUILD_CFLAGS += -Wno-unused-variable -Wno-unused-function -Wno-unused-label -Wno-unused-parameter -Wno-frame-larger-than= -Wno-vla -Wno-uninitialized

obj-$(CONFIG_SENSORS_FLICKER_SELF_TEST) += flicker_test.o

KBUILD_CFLAGS += -Wno-unused-variable -Wno-unused-function -Wno-unused-label -Wno-unused-parameter -Wno-frame-larger-than= -Wno-vla -Wno-uninitialized -Wno-incompatible-function-pointer-types

stk-src := stk6d2x.c stk6d2x_fifo.c stk6d2x_sec.c common_i2c.c common_timer.c common_gpio_sec.c

ifneq (,$(filter y m,$(CONFIG_SENSORS_TSL2585)))
flicker_sensor-y := tsl2585.o
flicker_sensor-$(CONFIG_FLICKER_PWM_CALIBRATION) += tsl2585_cal.o
obj-$(CONFIG_SENSORS_TSL2585) += flicker_sensor.o

ifneq (,$(filter y m,$(CONFIG_SENSORS_STK6D2X)))
# Universal builds enable both optical sensors. Keep the S23 TSL2585 module
# name and build the foldable STK6D2X driver separately so one implementation
# cannot replace the other in flicker_sensor.ko.
stk_flicker_sensor-y := $(stk-src:.c=.o)
obj-$(CONFIG_SENSORS_STK6D2X) += stk_flicker_sensor.o
endif
else
flicker_sensor-y := $(stk-src:.c=.o)
obj-$(CONFIG_SENSORS_STK6D2X) += flicker_sensor.o
endif
