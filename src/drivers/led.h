#pragma once

#include "main.h"
#include <stdint.h>

#ifdef __cplusplus
class Led {
public:
    // Constructor takes GPIO port and pin
    Led(GPIO_TypeDef* port, uint16_t pin);
    
    // Basic control
    void on();
    void off();
    void toggle();
    
    // Blinking control
    void startBlink(uint32_t interval_ms);
    void stopBlink();
    
    // Must be called periodically to update blinking
    void update();
    
private:
    GPIO_TypeDef* port;
    uint16_t pin;
    bool isBlinking;
    uint32_t blinkInterval;
    uint32_t lastToggle;
};
#endif  // __cplusplus