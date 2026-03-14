// Bibliotecas utilizadas 
#include <stdio.h>
#include "pico/stdlib.h"

// Definição dos pinos para os LEDs e botões
#define LED_G 11  
#define LED_B 12   
#define LED_R 13   
#define BTN_A 5    
#define BTN_B 6    

void set_LED(bool g, bool b, bool r) {
    gpio_put(LED_G, g);  
    gpio_put(LED_B, b);  
    gpio_put(LED_R, r);  
}

void peripheral_init() {
    for (int led = LED_G; led <= LED_R; led++) {
        gpio_init(led);
        gpio_set_dir(led, GPIO_OUT);
    }

    for (int btn = BTN_A; btn <= BTN_B; btn++) {
        gpio_init(btn);
        gpio_set_dir(btn, GPIO_IN);
        gpio_pull_up(btn);  // Ativar pull-up ao invés de pull-down
    }
}

int main() {
    stdio_init_all();
    peripheral_init();

    while (true) {
        printf("PINO %d - Estado: %d\n", BTN_A, gpio_get(BTN_A));     

        if (!gpio_get(BTN_A)) {  // Agora detecta quando o botão A é pressionado (nível baixo)
            sleep_ms(50);  // Debounce
            if (!gpio_get(BTN_A)) {
                set_LED(false, true, false); 
                printf("Led azul aceso\n");
            }
        } else if (!gpio_get(BTN_B)) {  // Agora detecta quando o botão B é pressionado (nível baixo)
            sleep_ms(50);  // Debounce
            if (!gpio_get(BTN_B)) {
                set_LED(false, false, true); 
                printf("Led vermelho aceso\n");
            }
        } else {
            set_LED(true, false, false);  // LED verde quando o botão não está pressionado
        }

        sleep_ms(100);  // Pequena pausa para melhorar a resposta
    }
}
