#include "pico/stdlib.h"

#define LED_PIN 13 // GPIO da placa BitDogLab

// Função para representar um ponto (.)
void ponto() {
    gpio_put(LED_PIN, true);
    sleep_ms(200);
    gpio_put(LED_PIN, false);
    sleep_ms(125); // GAP
}

// Função para representar um traço (-)
void traco() {
    gpio_put(LED_PIN, true);
    sleep_ms(800);
    gpio_put(LED_PIN, false);
    sleep_ms(125); // GAP
}

// Função principal
int main() {
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        // Sequência SOS
        for (int i = 0; i < 3; i++) ponto(); // S: ...
        sleep_ms(250); // Intervalo entre letras
        for (int i = 0; i < 3; i++) traco(); // O: ---
        sleep_ms(250); // Intervalo entre letras
        for (int i = 0; i < 3; i++) ponto(); // S: ...
        
        // Intervalo de reinício
        sleep_ms(3000);
    }
}
