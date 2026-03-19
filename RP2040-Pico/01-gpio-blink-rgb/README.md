# 01 - Hello World: Controle de LEDs RGB

Este módulo inicial do laboratório foca na manipulação básica de Registradores e GPIOs utilizando o **Raspberry Pi Pico SDK** em C. É a base para entender o ciclo de vida de um programa em sistemas embarcados.

## Conceitos Explorados
- **Inicialização de Periféricos:** Uso de loops para configuração em massa de GPIOs (`leds_init`).
- **Abstração de Hardware:** Implementação de funções de auxílio (`set_RGB`) para desacoplar a lógica da aplicação do acionamento físico.
- **Protocolo de Saída:** Gerenciamento de níveis lógicos (High/Low) para controle de cores compostas.

## Especificações de Hardware
- **Microcontrolador:** RP2040.
- **Atuador:** LED RGB (Catodo Comum ou Anodo Comum, dependendo da placa).
- **Pinagem:**
  - LED Verde: **GPIO 11**
  - LED Azul: **GPIO 12**
  - LED Vermelho: **GPIO 13**

---
*Desenvolvido como parte do programa Embarcatech para consolidação de fundamentos em GPIO.*
