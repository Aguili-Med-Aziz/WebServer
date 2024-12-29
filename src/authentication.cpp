#include "Mongoose.h"

const char* username = "admin";
const char* password = "password123";

bool authenticate(struct mg_connection *c) {
  const char *authHeader = mg_get_http_header(c, "Authorization");
  
  if (authHeader == NULL) {
    mg_send_http_redirect(c, 302, "http://localhost:80/login", NULL);
    return false;
  }

  // Parse and validate credentials
  if (strncmp(authHeader, "Basic ", 6) == 0) {
    char decoded[256];
    base64_decode(authHeader + 6, decoded);
    char *user = strtok(decoded, ":");
    char *pass = strtok(NULL, ":");

    if (strcmp(user, username) == 0 && strcmp(pass, password) == 0) {
      return true;
    }
  }

  mg_send_http_redirect(c, 302, "/login", NULL);
  return false;
}
