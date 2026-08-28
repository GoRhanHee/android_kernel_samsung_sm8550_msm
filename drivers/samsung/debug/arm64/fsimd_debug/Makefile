obj-$(CONFIG_SEC_ARM64_FSIMD_DEBUG)	+= sec_arm64_fsimd_debug.o
# Clang inherits -mgeneral-regs-only, but this assembly intentionally uses
# SIMD registers and FPSR/FPCR.
CFLAGS_REMOVE_sec_arm64_fsimd_debug.o += -mgeneral-regs-only
