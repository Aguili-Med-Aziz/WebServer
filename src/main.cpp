#include <Mongoose.h>
#include "config.h"
#include "web_server.cpp"
#include "sensor_handler.cpp"
#include "motor_control.cpp"
#include "data_logger.cpp"
#include "authentication.cpp"

void setup() {
  Serial.begin(115200);

  // Initialize sensors
  initSensors();
  
  // Setup SD card for data logging
  initSDCard();
  
  // Initialize Mongoose server
  mg_mgr_init(&mgr);
  mg_bind(&mgr, "80", handle_http_request);

  // Start the Mongoose event loop
  mg_set_protocol_http_websocket(&mgr);

  Serial.println("Web Server is running...");
}

void loop() {
  // Poll Mongoose server for events
  mg_mgr_poll(&mgr, 100);
}
