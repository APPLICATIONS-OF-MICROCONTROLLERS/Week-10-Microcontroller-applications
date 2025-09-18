#include <stdio.h>
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

void app_main(void)
{
    // 0. create variables 
    // 0.1 Switch_1 and LED_1 status
    int SW1_Status = 0;
    int LED1_status = 0;
    int SW2_Status = 0;
    int LED3_status = 0;

    // 1. gpio_set_direction pin 16 and 18 to Output.
    gpio_set_direction(16, GPIO_MODE_OUTPUT);  // LED1
    gpio_set_direction(18, GPIO_MODE_OUTPUT);  // LED3

    // 2. gpio_set_direction pin 15 and 17 to Input.
    gpio_set_direction(15, GPIO_MODE_INPUT);  // SW1
    gpio_set_direction(17, GPIO_MODE_INPUT);  // SW2

    while(1)
    {
        // read level of gpio 15 and store in SW1_Status 
        SW1_Status = gpio_get_level(15);
        LED1_status = !SW1_Status;     
        gpio_set_level(16, LED1_status);

        // read level of gpio 17 and store in SW2_Status 
        SW2_Status = gpio_get_level(17);
        LED3_status = !SW2_Status;
        gpio_set_level(18, LED3_status);

        // Delay
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}
