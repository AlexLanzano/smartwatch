#include <os/device.h>

struct st_rcc_config rcc0_config = {
    .clock_config = {
        .clock_freq = 64000000,
    },

    .clock_source = ST_RCC_CLK_SRC_PLL,
    .plln = 20,
    .pllm = 20,
    .pllp = 20,
    .pllq = 20,
};

struct device_config rcc0 = {
    .name = "rcc0",
    .driver = "st_rcc",
    .reg = {0x00000000, 0x400},
    .config = &rcc0_config
};


struct st_spi_config spi0 = {
    .spi_master_config = {
        .blah = 89,
    },

};

struct device_config spi0 = {
    .name = "spi0",
    .driver = "st_spi",
    .reg = {0x00000000, 0x400},
    .config = &spi0_config
};



struct display_config display0_config = {
    .spi_slave_config = {
        .spi_master = "spi0",
    },
    
}

struct device_config display0 = {
    .name = "display0",
    .driver = "display_drv",
    .reg = {0x00000000, 0x400},
    .config = &display_config
};


struct device_config dev_list[] = {
    rcc0,
}

void main()
{
    struct device *rcc_dev = device_get("st_rcc");
    if (!rcc_dev)
        while (1);

    
    clock_configure(rcc_dev);
    clock_enable(rcc_dev);
    while (1);
}
