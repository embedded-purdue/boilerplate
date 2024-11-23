#include "led.h"

Led::Led(GPIO_TypeDef* gpio_port, uint16_t gpio_pin) 
    : port(gpio_port)
    , pin(gpio_pin)
    // , isBlinking(false)
    // , blinkInterval(0)
    // , lastToggle(0)
{
    // Initialize to off state
    off();
}

void Led::on() {
    HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET);
}

void Led::off() {
    HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);
}

void Led::toggle() {
    HAL_GPIO_TogglePin(port, pin);
}

void Led::startBlink(uint32_t interval_ms) {
    isBlinking = true;
    blinkInterval = interval_ms;
    lastToggle = HAL_GetTick();
}

void Led::stopBlink() {
    isBlinking = false;
    off();  // Turn off when stopping blink
}

void Led::update() {
    if (isBlinking) {
        uint32_t currentTime = HAL_GetTick();
        if ((currentTime - lastToggle) >= blinkInterval) {
            toggle();
            lastToggle = currentTime;
        }
    }
}