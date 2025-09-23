#include <stdio.h>
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

void app_main(void)
{
    // ตัวแปรเก็บค่าปุ่มและไฟ
    int SW1_Status = 0;   // สถานะปุ่ม SW1 (GPIO15)
    int LED1_status = 0;  // สถานะไฟ LED1 (GPIO16)
    int SW2_Status = 0;   // สถานะปุ่ม SW2 (GPIO17)
    int LED3_status = 0;  // สถานะไฟ LED3 (GPIO18)

    // ตั้งค่าให้ขา GPIO16 และ GPIO18 เป็น OUTPUT (ต่อ LED)
    gpio_set_direction(16, GPIO_MODE_OUTPUT);  
    gpio_set_direction(18, GPIO_MODE_OUTPUT);  

    // ตั้งค่าให้ขา GPIO15 และ GPIO17 เป็น INPUT (ต่อปุ่ม)
    gpio_set_direction(15, GPIO_MODE_INPUT);   
    gpio_set_direction(17, GPIO_MODE_INPUT);   

    // วนลูปทำงานตลอดเวลา
    while (1)
    {
        // อ่านค่าจากปุ่ม SW1
        SW1_Status = gpio_get_level(15);

        // ถ้ากดปุ่ม SW1 → LED1 ติด
        // ถ้าไม่กด → LED1 ดับ
        LED1_status = !SW1_Status;
        gpio_set_level(16, LED1_status);

        // อ่านค่าจากปุ่ม SW2
        SW2_Status = gpio_get_level(17);

        // ถ้ากดปุ่ม SW2 → LED3 ติด
        // ถ้าไม่กด → LED3 ดับ
        LED3_status = !SW2_Status;
        gpio_set_level(18, LED3_status);

        // หน่วงเวลา 100 ms กันอ่านค่าถี่เกินไป
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}
