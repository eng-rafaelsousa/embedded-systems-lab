#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define BTN_A 5 // BOTÃO A
#define BTN_B 6 // BOTÃO A
#define LED_R 13 // LED VERMELHO

volatile bool btnA_pressed = false;
volatile bool btnB_pressed = false;
volatile int cnt = 0; //contador
volatile bool freq_state = true;
volatile int freq = 100;

void btn_press(uint gpio, uint32_t events);

void blink_LED() {
    int tempo_total = 10 * 1000;  // 10 segundos em ms
    int intervalo = 100;  // 10 Hz = 100 ms por ciclo

    absolute_time_t tempo_inicio = get_absolute_time();

    while (absolute_time_diff_us(tempo_inicio, get_absolute_time()) < tempo_total * 1000) {
        gpio_put(LED_R, 1);  // Liga o LED
        sleep_ms(intervalo / 2);
        
        gpio_put(LED_R, 0);  // Desliga o LED
        sleep_ms(intervalo / 2);
    }
}

int main() {
    stdio_init_all();
    gpio_set_function(BTN_A, GPIO_FUNC_SIO);
    gpio_set_dir(BTN_A, GPIO_IN);
    gpio_pull_up(BTN_A);
  
    gpio_set_function(BTN_B, GPIO_FUNC_SIO);
    gpio_set_dir(BTN_B, GPIO_IN);
    gpio_pull_up(BTN_B);
  
    gpio_init(LED_R);
    gpio_set_dir(LED_R, GPIO_OUT);
  
    // Configura interrupção na borda de descida (pressionado)
    gpio_set_irq_enabled_with_callback(BTN_A, GPIO_IRQ_EDGE_FALL, true, &btn_press);
    gpio_set_irq_enabled_with_callback(BTN_B, GPIO_IRQ_EDGE_FALL, true, &btn_press);
  
    while (true) {
      if (btnA_pressed) {
        cnt++;  
        printf("Botão A pressionado %dº vez!\n", cnt);
        if(cnt == 5){
          blink_LED();  // Chama a função para piscar o LED
          cnt = 0;  // Reseta o contador após 5 pressões
        }
        btnA_pressed = false; 
      }
  
      if(btnB_pressed){
        if(freq_state){
          freq = 1000;
          printf("Frequêcia alterada para 1Hz\n");
          freq_state = !freq_state;
        }
        else{
          freq = 100;
          printf("Frequêcia alterada para 10Hz\n");
          freq_state = !freq_state;
        }
        btnB_pressed = false;
      }
      sleep_ms(100);  
    }
  
    return 0;
}

void btn_press(uint gpio, uint32_t events) {
    static absolute_time_t ultimo_tempo = {0};  // Tempo do último evento
    absolute_time_t agora = get_absolute_time();
    
    // Debounce: verifica se passaram pelo menos 200 ms desde a última pressão
    if (absolute_time_diff_us(ultimo_tempo, agora) > 200000) {

        if(gpio_get(BTN_A) == 1){// Aguarda o botão ser solto
          sleep_ms(50);
          printf("OK\n");
        }
        btnA_pressed = true;
        ultimo_tempo = agora;  // Atualiza o tempo do último clique
       }
}