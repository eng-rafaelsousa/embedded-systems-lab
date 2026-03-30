#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define BTN_A 5 //BOTÃO A
#define LED_G 11 //LED VERMELHO
#define LED_B 12 //LED VERMELHO
#define LED_R 13 //LED VERMELHO

volatile bool botao_pressionado = false;
void funcao_irq(uint gpio, uint32_t events);

void set_RGB(bool r, bool g, bool b) {
    gpio_put(LED_R, r); // Configura o estado do LED vermelho
    gpio_put(LED_G, g); // Configura o estado do LED verde
    gpio_put(LED_B, b); // Configura o estado do LED azul
}

void pedestrian_detected(){
    
    set_RGB(true, true, false); // Acende o LED amarelo
    printf("\nLED AMARELO LIGADO"); // Mensagem no terminal
    sleep_ms(3000);  // Espera 3 segundo 

    set_RGB(true, false, false); // Acende o LED vermelho
    printf("\nLED VERMELHO LIGADO"); // Mensagem no terminal
    sleep_ms(10000);  // Espera 10 segundo

}

// Função para Inicializar os pinos dos LEDs
void leds_init(){
  for (int led = LED_G; led <= LED_R; led++){
    gpio_init(led);
    gpio_set_dir(led, GPIO_OUT);
  }
}

int main()
{    
    stdio_init_all();

    //Inicializa os leds
    leds_init();

    gpio_init(BTN_A);
    gpio_set_dir(BTN_A, GPIO_IN);
    gpio_pull_up(BTN_A);  // Pull-up ativado (espera nível alto por padrão)

    gpio_set_irq_enabled_with_callback(BTN_A, GPIO_IRQ_EDGE_FALL, true, &funcao_irq);

    while (true) {
        
        //sleep_ms(1000);  // Espera 1 segundo
        
        if(botao_pressionado){
            printf("Pedestre detectado\n");
            pedestrian_detected();
            botao_pressionado = false;
        }else{
            set_RGB(false, true, false);  // Acende o LED verde
            printf("\nLED VERDE LIGADO"); // Mensagem no terminal
        }
        sleep_ms(1000);
        printf("Botão pressionado -  %d\n", botao_pressionado);
    }
}

void funcao_irq(uint gpio, uint32_t events) {
    static absolute_time_t ultimo_tempo = {0};  // Tempo do último evento
    absolute_time_t agora = get_absolute_time();

    // Debounce: verifica se passaram pelo menos 200 ms desde a última pressão
    if (absolute_time_diff_us(ultimo_tempo, agora) > 200000) {

     if(gpio_get(BTN_A)){// Aguarda o botão ser solto
       sleep_ms(50);
     }
     botao_pressionado = true;  // Marca o botão como pressionado
     ultimo_tempo = agora;  // Atualiza o tempo do último clique
    }
}