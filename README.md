# Embedded Systems Lab (RP2040 & ESP32)

Este repositório é o meu laboratório técnico de desenvolvimento de baixo nível. Aqui estão consolidados módulos de firmware, drivers e implementações focadas em performance, paralelismo e eficiência energética.

---

## Estrutura do Laboratório

Os projetos estão divididos por arquitetura para facilitar a navegação técnica:

### Raspberry Pi Pico (RP2040)
* **[01 - Blink RGB](./RP2040-Pico/01-gpio-blink-rgb):** Fundamentos de GPIO e abstração de hardware (Output).
* **[02 - Button Polling](./RP2040-Pico/02-gpio-button-polling):** Gerenciamento de entradas digitais e software debounce.
* **[03 - IRQ & Timer Callback](./RP2040-Pico/03-gpio-irq-callback):** Interrupções de hardware, timers e controle de frequência assíncrono.
* *Aguardando o proximo upload...*

### ESP32 Series
* *Em breve: Projetos com ESP-IDF, FreeRTOS e Low Power*.

---

## Tecnologias e Ferramentas
- **Linguagens:** C (Pico SDK / ESP-IDF), C++, Python (Scripts de teste).
- **Hardwares:** RP2040, ESP32-WROOM, ESP32-S3.
- **Protocolos:** MQTT, I2C, SPI, UART, DMA, TinyUSB.

---
*Organizado por Rafael Gonçalves Sousa como parte do portfólio técnico de Engenharia de Sistemas Embarcados.*
