// UART config
#define BAUDRATE 115200

// WiFi config
#define SSID_MAX_LEN 32
#define PASS_MAX_LEN 63

struct WIFI_CONFIG
{
  char ssid[SSID_MAX_LEN + 1];
  char pass[PASS_MAX_LEN + 1];
};

WIFI_CONFIG wifi_config;

void initGPIO();
void connectWiFi();
