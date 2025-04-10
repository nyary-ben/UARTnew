#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/printk.h>
/* Include the header file of the UART driver in main.c */
#include <zephyr/drivers/uart.h>

/* Define the number of data to be printed */
 #define NUM_T 4

int main(void)
{
    float T[NUM_T];
    /* Redefine this float T for the data from Lucas*/
    while (true) {   
        T[0] = 7.0;
        T[1] = 4.0;
        T[2] = 23.5;
        T[3] = 99;
        for (int i = 0; i < NUM_T; i++) {
            printk("%.2f\t", T[i]);
        }
        printk("\n"); // easier method than UART to send and receive data because a lot of threads interrupt would crash and have a lot of risks to fail
        k_msleep(100);
    }
}