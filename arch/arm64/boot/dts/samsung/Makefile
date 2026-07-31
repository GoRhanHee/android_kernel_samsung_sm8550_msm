# SPDX-License-Identifier: GPL-2.0

dts-dirs-$(CONFIG_SEC_DM1Q_PROJECT) += diamond/dm1q
dts-dirs-$(CONFIG_SEC_DM2Q_PROJECT) += diamond/dm2q
dts-dirs-$(CONFIG_SEC_DM3Q_PROJECT) += diamond/dm3q
dts-dirs-$(CONFIG_SEC_Q5Q_PROJECT) += foldable/q5q

always          := $(dtb-y)
subdir-y        := $(dts-dirs-y)

clean-files := *.dtb *.reverse.dts *.dtbo
