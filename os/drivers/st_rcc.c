#include <os/device.h>

static int st_rcc_configure(void)
{
    return 0;
}

static int st_rcc_enable(void)
{
    return 0;
}

static int st_rcc_disable(void)
{
    return 0;
}

static int st_rcc_get_rate(void)
{
    return 0;
}

struct device_clock_ops st_rcc_ops = {
    .configure = st_rcc_configure,
    .enable = st_rcc_enable,
    .disable = st_rcc_disable,
    .get_rate = st_rcc_get_rate
};

struct device st_rcc_dev = {
    .name = "st_rcc",
    .type = DEVICE_TYPE_CLOCK,
    .ops = &st_rcc_ops
};
