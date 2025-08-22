#ifndef DEVICE_H
#define DEVICE_H

#define DEVICE_NAME_MAX 64

#define DEVICE_API(dev) _DEVICE_API(dev->type)
#define _DEVICE_API(type) __DEVICE_API(type)
#define __DEVICE_API(type) __DEVICE_API_##type()
#define __DEVICE_API_0 device->invalid
#define __DEVICE_API_1 device->clock

enum device_type {
    DEVICE_TYPE_INVALID,
    DEVICE_TYPE_CLOCK,
    DEVICE_TYPE_UART,
    DEVICE_TYPE_GPIO
};

struct device_clock_ops {
    int (*configure)(void);
    int (*enable)(void);
    int (*disable)(void);
    int (*get_rate)(void);
};

struct device_uart_ops {
    int (*configure)(void);
    int (*enable)(void);
    int (*disable)(void);
    int (*read)(void);
    int (*write)(void);
};

struct device_gpio_ops {
    int (*configure)(void);
    int (*enable)(void);
    int (*disable)(void);
    int (*get)(void);
    int (*set)(void);
    int (*toggle)(void);
};

struct device {
    char name[DEVICE_NAME_MAX];
    enum device_type type;
    void *ops;
    void *ctx;
};

#endif
