// SPDX-License-Identifier: GPL-2.0
#include <linux/module.h>

#include "uwb.h"
#include "uwb_logger/uwb_logger.h"

/* The composite module registers every configured controller independently. */
static int __init samsung_uwb_init(void)
{
#if defined(CONFIG_UWB_SR200) || defined(CONFIG_UWB_SR100)
	int ret;
#endif

#ifdef CONFIG_UWB_SR200
	ret = sr200_dev_init();
	if (ret) {
		uwb_logger_exit();
		return ret;
	}
#endif
#ifdef CONFIG_UWB_SR100
	ret = sr100_dev_init();
	if (ret) {
#ifdef CONFIG_UWB_SR200
		sr200_dev_exit();
#endif
		uwb_logger_exit();
		return ret;
	}
#endif
	return 0;
}

static void __exit samsung_uwb_exit(void)
{
#ifdef CONFIG_UWB_SR100
	sr100_dev_exit();
#endif
#ifdef CONFIG_UWB_SR200
	sr200_dev_exit();
#endif
	uwb_logger_exit();
}

module_init(samsung_uwb_init);
module_exit(samsung_uwb_exit);

MODULE_DESCRIPTION("Samsung UWB controllers");
MODULE_LICENSE("GPL");
