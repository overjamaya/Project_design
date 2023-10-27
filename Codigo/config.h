/************************ Adafruit IO Config *******************************/

#define IO_USERNAME "overjamaya"
#define IO_KEY "aio_MwKp85LN2D9N0y0FmmIkdRMwco7t"

/******************************* WIFI **************************************/

#define WIFI_SSID "OJAM"
#define WIFI_PASS "Overjamaya1945"

#include "AdafruitIO_WiFi.h"

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);
