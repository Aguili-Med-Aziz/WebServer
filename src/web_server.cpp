#include "Mongoose.h"
#include "sensor_handler.cpp"
#include "motor_control.cpp"
#include "authentication.cpp"

struct mg_mgr mgr;

static void handle_http_request(struct mg_connection *c, int ev, void *p) {
  if (ev == MG_EV_HTTP_REQUEST) {
    if (!authenticate(c)) {
      mg_send_http_redirect(c, 302, "/login", NULL);
      return;
    }

    // Serve the index.html page
    if (mg_strcmp(c->uri, "/") == 0) {
      mg_send_http_ok(c, "text/html", index_html, strlen(index_html));
    }
    
    // Serve sensor data
    else if (mg_strcmp(c->uri, "/getSensorData") == 0) {
      readSensors();
      mg_send_http_ok(c, "application/json", getSensorData().c_str(), getSensorData().length());
    }
    
    // Control motor
    else if (mg_strcmp(c->uri, "/setMotorSpeed") == 0) {
      float speed = atof(mg_get_http_var(c, "speed", "0"));
      setMotorSpeed(speed);
      mg_send_http_ok(c, "text/plain", "Motor speed updated", 18);
    }
  }
}
