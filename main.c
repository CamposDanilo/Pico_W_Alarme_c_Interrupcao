#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"


volatile bool flag = false;

void gpio_callback(uint gpio, uint32_t events) {
    printf("Interupcao GPIO %d  \n",gpio);
    printf("Alarme Disparado \n");
    //cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN,true);  
    flag = true;
}
void buz (){
    int j = 19;
    gpio_init(j);
    gpio_set_dir(j,GPIO_OUT);
    //printf("buzz");
    for (int i=0;i<1000;i++){
        gpio_put(j,true);
        sleep_us(1418);
        gpio_put(j,false);
        sleep_us(1418);
    }
}


int main() {
    
    stdio_init_all();
    cyw43_arch_init();
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN,false);
    sleep_ms(5000);
    printf("Se Interrupcao - Soar Alarme\n");
    int i = 2;
    gpio_init(i);
    gpio_set_dir(i,GPIO_IN);
    gpio_set_pulls(i, true, false);
    gpio_set_irq_enabled_with_callback(i,GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL , true, &gpio_callback);

    while(true){
         if (flag == true){
            buz();
            flag = false;
        }
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN,false);
        sleep_ms(200);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN,true);
        sleep_ms(200);
    }
}
