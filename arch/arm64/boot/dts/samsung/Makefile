# SPDX-License-Identifier: GPL-2.0

dts-dirs-$(CONFIG_SEC_DM1Q_PROJECT) += diamond/dm1q
dts-dirs-$(CONFIG_SEC_DM2Q_PROJECT) += diamond/dm2q
ifeq ($(CONFIG_SEC_DM3Q_EUR_OPENX_PROJECT),y)
dts-dirs-y += diamond/dm3q_eur_openx
else
dts-dirs-$(CONFIG_SEC_DM3Q_PROJECT) += diamond/dm3q
endif
dts-dirs-$(CONFIG_SEC_Q5Q_PROJECT) += foldable/q5q
dts-dirs-$(CONFIG_SEC_B5Q_PROJECT) += foldable/b5q

always          := $(dtb-y)
subdir-y        := $(dts-dirs-y)

clean-files := *.dtb *.reverse.dts *.dtbo
