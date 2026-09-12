/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _SEC_INPUT_UNIVERSAL_H
#define _SEC_INPUT_UNIVERSAL_H

#include <linux/of.h>
#include <linux/string.h>

#ifdef CONFIG_SEC_UNIVERSAL_PROJECT
/* Stock DTs share compatible strings but describe different controller ABIs. */
static inline bool sec_input_is_s23_spi(struct device_node *np)
{
	const char *project;

	if (of_property_read_string(np, "sec,project_name", &project))
		return false;
	return !strcmp(project, "dm1q") || !strcmp(project, "dm2q") ||
		!strcmp(project, "dm3q");
}

static inline bool sec_input_is_q5q_spi(struct device_node *np)
{
	const char *project;

	return !of_property_read_string(np, "sec,project_name", &project) &&
		!strcmp(project, "q5q");
}

static inline bool sec_input_is_s23_wacom(struct device_node *np)
{
	return of_property_read_bool(np, "wacom,fw_path") &&
		!of_property_read_bool(np, "sec,firmware_name");
}

static inline bool sec_input_is_q5q_wacom(struct device_node *np)
{
	return of_property_read_bool(np, "sec,firmware_name");
}
#endif

#endif
