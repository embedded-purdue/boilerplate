#include "app.h"
#include "hardwareConfig.h"

Led App::led1(LED_PORT, LED_PIN);

void App::init() {
    led1.startBlink(1000);

}

void App::loop() {

    led1.update();
}

// C interface implementations
extern "C" {
    void app_init(void) {
        App::init();
    }
    
    void app_loop(void) {
        App::loop();
    }

}