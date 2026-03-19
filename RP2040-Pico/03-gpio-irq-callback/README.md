# 03 - Interrupções de Hardware (IRQ) e Controle de Frequência

Este módulo demonstra a transição do método de verificação constante (Polling) para o uso de **Interrupções de Hardware (IRQ)**. Esta é uma técnica essencial para sistemas de tempo real, permitindo que o processador execute outras tarefas enquanto aguarda eventos externos.

## Conceitos Aplicados
- **GPIO Interrupts:** Uso de `gpio_set_irq_enabled_with_callback` para disparar funções de retorno (callbacks) em bordas de descida (`FALLING_EDGE`).
- **Debounce de Precisão:** Implementação de debounce por software utilizando o tempo absoluto do sistema (`get_absolute_time`) para ignorar ruídos elétricos.
- **Gerenciamento de Estados:** Alternância entre frequências de operação (1Hz e 10Hz) baseada em eventos de entrada.
- **Variáveis Voláteis:** Uso do qualificador `volatile` para variáveis compartilhadas entre o contexto de interrupção e o loop principal.

## Funcionamento
- **Botão A (GPIO 5):** Contador de pressões. Ao atingir 5 cliques, dispara um ciclo de pisca de 10 segundos.
- **Botão B (GPIO 6):** Altera dinamicamente a frequência do LED entre **1Hz** e **10Hz**.
- **Contexto de Execução:** A interrupção apenas sinaliza o evento (seta a flag), enquanto o processamento pesado ocorre no `main`, respeitando as boas práticas de baixa latência em IRQs.

---
*Módulo desenvolvido para demonstrar o controle assíncrono de periféricos no Raspberry Pi Pico.*
