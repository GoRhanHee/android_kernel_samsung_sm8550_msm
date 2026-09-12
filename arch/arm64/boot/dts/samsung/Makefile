# SPDX-License-Identifier: GPL-2.0

# diamond/dm3q_eur_openx is retained as source only.
ifeq ($(CONFIG_SM8550_DTBO),y)
ifeq ($(CONFIG_SEC_UNIVERSAL_PROJECT),y)
dts-dirs-y += diamond/dm1q
dts-dirs-y += diamond/dm2q
dts-dirs-y += diamond/dm3q
dts-dirs-y += foldable/q5q
dts-dirs-y += foldable/b5q
else
dts-dirs-$(CONFIG_SEC_DM1Q_PROJECT) += diamond/dm1q
dts-dirs-$(CONFIG_SEC_DM2Q_PROJECT) += diamond/dm2q
dts-dirs-$(CONFIG_SEC_DM3Q_PROJECT) += diamond/dm3q
dts-dirs-$(CONFIG_SEC_Q5Q_PROJECT) += foldable/q5q
dts-dirs-$(CONFIG_SEC_B5Q_PROJECT) += foldable/b5q
endif
else
# Product DTBs depend on DTBOs. Build and install only their base DTBs when
# overlays are disabled, including for the universal packaging profile.
kalama-dtb-$(CONFIG_ARCH_KALAMA) += \
	../vendor/qcom/kalama.dtb ../vendor/qcom/kalama-v2.dtb \
	../vendor/qcom/kalamap.dtb ../vendor/qcom/kalamap-v2.dtb
kalama-overlays-dtb-y += $(kalama-dtb-y)
dtb-y += $(kalama-dtb-y)
endif

always          := $(dtb-y)
subdir-y        := $(dts-dirs-y)

clean-files := *.dtb *.reverse.dts *.dtbo
