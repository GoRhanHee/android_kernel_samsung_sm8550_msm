#include "fingerprint_common.h"
#include <linux/module.h>

void set_sensor_type(const int type_value, int *result)
{
	if (type_value >= SENSOR_OOO) {
		if (type_value == SENSOR_OOO && *result == SENSOR_FAILED) {
			pr_info("maintain type check from out of order :%s\n",
				sensor_status[*result + 2]);
		} else {
			*result = type_value;
			pr_info("FP_SET_SENSOR_TYPE :%s\n", *result > 0 ?
					sensor_status[3] : sensor_status[*result + 2]);
		}
	} else {
		pr_err("FP_SET_SENSOR_TYPE invalid value %d\n", type_value);
		*result = SENSOR_UNKNOWN;
	}
}

EXPORT_SYMBOL_GPL(set_sensor_type);

void enable_fp_debug_timer(struct debug_logger *logger)
{
	mod_timer(&logger->dbg_timer, round_jiffies_up(jiffies + DEBUG_TIMER_SEC));
}
EXPORT_SYMBOL_GPL(enable_fp_debug_timer);

void disable_fp_debug_timer(struct debug_logger *logger)
{
	del_timer_sync(&logger->dbg_timer);
	cancel_work_sync(&logger->work_debug);
}
EXPORT_SYMBOL_GPL(disable_fp_debug_timer);

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 14, 0)
static void timer_func(unsigned long ptr)
#else
static void timer_func(struct timer_list *t)
#endif
{
#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 14, 0)
	struct debug_logger *logger = (struct debug_logger *)ptr;
#else
	struct debug_logger *logger = from_timer(logger, t, dbg_timer);
#endif

	queue_work(logger->wq_dbg, &logger->work_debug);
	enable_fp_debug_timer(logger);
}

int set_fp_debug_timer(struct debug_logger *logger,
					void (*func)(struct work_struct *work))
{
	int rc = 0;
#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 14, 0)
	setup_timer(&logger->dbg_timer, timer_func, (unsigned long)logger);
#else
	timer_setup(&logger->dbg_timer, timer_func, 0);
#endif
	logger->wq_dbg = create_singlethread_workqueue("fingerprint_debug_wq");
	if (!logger->wq_dbg) {
		rc = -ENOMEM;
		pr_err("could not create workqueue\n");
		return rc;
	}
	INIT_WORK(&logger->work_debug, func);

	return rc;
}

EXPORT_SYMBOL_GPL(set_fp_debug_timer);

void set_delay_in_spi_transfer(struct spi_transfer *xfer, unsigned int usec)
{
#if LINUX_VERSION_CODE > KERNEL_VERSION(5, 10, 0)
	xfer->delay.unit = SPI_DELAY_UNIT_USECS;
	xfer->delay.value = usec;
#else
	xfer->delay_usecs = usec;
#endif
}
EXPORT_SYMBOL_GPL(set_delay_in_spi_transfer);

MODULE_LICENSE("GPL");
