cmake_minimum_required(VERSION 3.13)

# Configurações de padrões de linguagem
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Importa o SDK do Raspberry Pi Pico
include(pico_sdk_import.cmake)

project(gpio_button_polling C CXX ASM)

# Inicializa o SDK
pico_sdk_init()

# Define o executável e o arquivo fonte
add_executable(gpio_button_polling
    main.c 
)

# Configurações de saída via USB/UART
# Habilitamos USB (1) para você ver os prints no terminal serial
pico_enable_stdio_uart(gpio_button_polling 0)
pico_enable_stdio_usb(gpio_button_polling 1)

# Vincula a biblioteca padrão do Pico
target_link_libraries(gpio_button_polling
    pico_stdlib
)

# Adiciona diretórios de inclusão
target_include_directories(gpio_button_polling PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

# Gera os arquivos de saída (.uf2, .bin, etc)
pico_add_extra_outputs(gpio_button_polling)