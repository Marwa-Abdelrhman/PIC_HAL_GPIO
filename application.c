/* 
 * File:   application.c
 * Author: Marwa Abdelrahman
 *
 * Created on August 1, 2024, 12:53 AM
 */


#include"application.h"





pin_config_t led_0={
    .port=PORTC_INDEX,
    .pin=GPIO_PIN0,
    .direction=GPIO_DIRECTION_OUTPUT,
    .state=GPIO_STATE_HIGH
};

pin_config_t led_1={
    .port=PORTC_INDEX,
    .pin=GPIO_PIN1,
    .direction=GPIO_DIRECTION_OUTPUT,
    .state=GPIO_STATE_HIGH
};

pin_config_t led_2={
    .port=PORTC_INDEX,
    .pin=GPIO_PIN2,
    .direction=GPIO_DIRECTION_OUTPUT,
    .state=GPIO_STATE_HIGH
};

direction_t led_state;
Std_RetrunType ret=E_OK;
port_t port_c;
uint8 port_state;


int main() {
    app_init();

while(1){
    /*gpio_pin_toggle(&led_0);
    __delay_ms(250);
     gpio_pin_toggle(&led_1);
    __delay_ms(250);
     gpio_pin_toggle(&led_2);
    __delay_ms(250);*/
    ret=gpio_port_toggle(PORTC_INDEX);
    __delay_ms(1000);
}
    return (EXIT_SUCCESS);
}

void app_init(void){
    /*ret=gpio_pin_init(&led_0);
    ret=gpio_pin_get_direction_status(&led_0,&led_state);
    ret=gpio_pin_init(&led_1);
    ret=gpio_pin_init(&led_2);*/
    ret=gpio_port_direction_init(PORTC_INDEX,0x00);
    ret=gpio_port_get_direction_status(PORTC_INDEX,&port_state);
    ret=gpio_port_write(PORTC_INDEX,0xAA);
    ret=gpio_port_read(PORTC_INDEX,&port_state);
    
}