#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
extern "C" void app_main(void)
{
    gpio_set_direction(GPIO_NUM_5, GPIO_MODE_INPUT_OUTPUT);
    gpio_set_pull_mode(GPIO_NUM_5, GPIO_PULLDOWN_ONLY);

    while (true) {
        if (gpio_get_level(GPIO_NUM_5))
            gpio_set_level(GPIO_NUM_5, 0);
        else
            gpio_set_level(GPIO_NUM_5, 1);
        vTaskDelay(300);
    }
}
