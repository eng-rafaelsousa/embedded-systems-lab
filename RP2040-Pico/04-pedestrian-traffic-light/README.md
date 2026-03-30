# 04 - Semáforo Inteligente com Travessia de Pedestres 🚦

Este módulo aplica os conceitos de GPIO e Interrupções para simular um sistema de controle de tráfego real. O projeto foca na implementação de uma sequência lógica de estados e na priorização de eventos externos (pedestres).

## Conceitos Aplicados
- **Lógica de Estados:** Gerenciamento da transição entre Verde, Amarelo e Vermelho com tempos distintos.
- **Interrupção de Prioridade:** Uso de IRQ para detectar o botão de pedestre de forma imediata, sem interromper o fluxo principal de forma abrupta.
- **Funções de Atuadores:** Encapsulamento da lógica de cores na função `set_RGB` para manter o código limpo e modular.

## Funcionamento
1. **Estado Normal:** O semáforo permanece no Verde.
2. **Detecção de Pedestre:** Ao pressionar o Botão A (GPIO 5), a interrupção sinaliza a solicitação.
3. **Sequência de Segurança:**
   - **Amarelo:** 3 segundos (Atenção).
   - **Vermelho:** 10 segundos (Travessia liberada).
   - **Retorno:** O sistema volta automaticamente ao estado Verde.


---
*Módulo focado em lógica de automação e sistemas de segurança viária com RP2040.*