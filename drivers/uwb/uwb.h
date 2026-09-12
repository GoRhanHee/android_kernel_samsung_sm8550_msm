/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _SAMSUNG_UWB_H
#define _SAMSUNG_UWB_H

#include <linux/init.h>

int __init sr100_dev_init(void);
void sr100_dev_exit(void);
int __init sr200_dev_init(void);
void sr200_dev_exit(void);

#endif
