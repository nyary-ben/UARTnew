#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/printk.h>
/* Include the header file of the UART driver in main.c */
#include <zephyr/drivers/uart.h>

/* Define the number of data to be printed */
 #define NUM_T 100

int main(void)
{
    float T[NUM_T];
    /* Redefine this float T for the data from Lucas*/
    while (true) {   /* run the reading temperature inside the loop and save each 100 data and then send, save and then send*/
        T[0] = 7.0;
        T[1] = 4.0;
        T[2] = 23.5;
        T[3] = 99;
        T[4] = 18;
        T[5] = 21;
        T[6] = 5;
        T[7] = 100;
        T[8] = 13;
        T[9] = 21;
        T[10] = 18;
        T[11] = 21;
        T[12] = 79;
        T[13] = 73;
        T[14] = 1;
        T[15] = 62;
        T[16] = 45;
        T[17] = 27;
        T[18] = 18;
        T[19] = 19;
        T[20] = 20;
        T[21] = 21;
        T[22] = 10;
        T[23] = 23;
        T[24] = 28;
        T[25] = 33;
        T[26] = 39;
        T[27] = 55;
        T[28] = 28;
        T[29] = 29;
        T[30] = 8;
        T[31] = 2;
        T[32] = 66;
        T[33] = 77;
        T[34] = 91;
        T[35] = 44;
        T[36] = 36;
        T[37] = 37;
        T[38] = 38;
        T[39] = 39;
        T[40] = 18;
        T[41] = 21;
        T[42] = 75;
        T[43] = 25;
        T[44] = 61;
        T[45] = 45;
        T[46] = 18;
        T[47] = 22;
        T[48] = 75;
        T[49] = 34;
        T[50] = 35;
        T[51] = 38;
        T[52] = 18;
        T[53] = 21;
        T[54] = 54;
        T[55] = 55;
        T[56] = 17;
        T[57] = 16;
        T[58] = 18;
        T[59] = 21;
        T[60] = 60;
        T[61] = 61;
        T[62] = 18;
        T[63] = 21;
        T[64] = 10;
        T[65] = 6;
        T[66] = 45;
        T[67] = 28;
        T[68] = 1;
        T[69] = 2;
        T[70] = 0;
        T[71] = 12;
        T[72] = 66;
        T[73] = 64;
        T[74] = 18;
        T[75] = 21;
        T[76] = 15;
        T[77] = 27;
        T[78] = 78;
        T[79] = 79;
        T[80] = 100;
        T[81] = 71;
        T[82] = 30;
        T[83] = 29;
        T[84] = 18;
        T[85] = 21;
        T[86] = 86;
        T[87] = 87;
        T[88] = 48;
        T[89] = 20;
        T[90] = 18;
        T[91] = 21;
        T[92] = 33;
        T[93] = 16;
        T[94] = 67;
        T[95] = 22;
        T[96] = 18;
        T[97] = 21;
        T[98] = 98;
        T[99] = 99;
    
        for (int i = 0; i < NUM_T; i++) {
            printk("%.2f\t", T[i]);
        }
        printk("\n"); /* prints in all in one line and then goes to next line (easier method than UART to send and receive data because a lot of threads interrupt would crash 
        and have a lot of risks to fail)*/
        k_msleep(100);
    }
}