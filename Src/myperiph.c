#include "gpio.h"
#include "stm32f1xx_hal.h"
#include "cmsis_os.h"
#include "spi.h"
#include "myusart.h"
#include "myled.h"
#include "myspi.h"
#include "mylcd.h"
#include "mye2prom.h"

static const char PRODUCT_NAME[]= "RuffNet-FX";

void printLogo()
{
    printf("\n|==================================================\n|\n");
    printf("|             _____        __  __ _       \n");
    printf("|            |  __ \\      / _|/ _(_)      \n");
    printf("|            | |__) |   _| |_| |_ _  ___  \n");
    printf("|            |  _  / | | |  _|  _| |/ _ \\ \n");
    printf("|            | | \\ \\ |_| | | | |_| | (_) |\n");
    printf("|            |_|  \\_\\__,_|_| |_(_)_|\\___/ \n");
    printf("|\n|\n| %s\n", PRODUCT_NAME);
    printf("| 2017.7\n");
    printf("==================================================\n\n");
}

void Periph_Init()
{

    MX_GPIO_Init();

    /*
      MX_UART4_Init();
      MX_USART1_UART_Init();
      MX_USART2_UART_Init();
      MX_USART3_UART_Init();

      */

    My_Usart_Init();

    printLogo();

    LCD_Init();
    I2C1_Init();
    E2PROM_Init();

    //MX_SPI1_Init();
    //My_Spi_Init();

}
