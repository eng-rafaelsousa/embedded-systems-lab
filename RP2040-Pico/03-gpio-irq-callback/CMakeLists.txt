cmake_minimum_required(VERSION 3.13)

# Configurações de padrões de linguagem
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Importa o SDK do Raspberry Pi Pico
include(pico_sdk_import.cmake)

project(gpio_irq_callback C CXX ASM)

# Inicializa o SDK
pico_sdk_init()

# Define o executável e o arquivo fonte
add_executable(gpio_irq_callback
    main.c 
)

# Configurações de saída via USB para debug (printf)
pico_enable_stdio_uart(gpio_irq_callback 0)
pico_enable_stdio_usb(gpio_irq_callback 1)

# Vincula a biblioteca padrão e o hardware_timer
target_link_libraries(gpio_irq_callback
    pico_stdlib
    hardware_timer
)

# Adiciona diretórios de inclusão
target_include_directories(gpio_irq_callback PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

# Gera os arquivos de saída (.uf2, .bin, etc)
pico_add_extra_outputs(gpio_irq_callback)