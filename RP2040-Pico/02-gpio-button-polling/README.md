# 02 - Entrada Digital: Leitura de Botões via Polling 🔘💡

Este módulo avança para o controle de entradas digitais, explorando como o **RP2040** interpreta sinais externos de botões táteis e como gerenciar o estado dos LEDs a partir dessas entradas.

## 🧠 Conceitos Aplicados
- **Input com Pull-up:** Uso de `gpio_pull_up` para garantir um nível lógico estável (High) quando o botão não está pressionado.
- **Polling:** Técnica de verificação contínua do estado do pino dentro do loop principal (`while`).
- **Software Debounce (Delay):** Implementação de um pequeno atraso (`sleep_ms`) para filtrar o ruído mecânico dos contatos do botão.
- **Lógica Inversa:** Detecção de pressão em nível baixo (`!gpio_get`), comum em configurações de botões com pull-up.

## 🛠️ Funcionamento
- **Botão A (GPIO 5):** Quando pressionado, acende o LED Verde (GPIO 11).
- **Botão B (GPIO 6):** Quando pressionado, acende o LED Azul (GPIO 12).
- O sistema realiza o debounce de 50ms para evitar acionamentos falsos.


---
*Desenvolvido como parte do laboratório de fundamentos de IO no programa Embarcatech.*