/************************ Adafruit IO Config *******************************/

#define IO_USERNAME "Victor24"
#define IO_KEY "aio_OfjV861O6hpzkIKJ1MKc2S8UQCkk"

/******************************* WIFI **************************************/

#define WIFI_SSID "OJAM"
#define WIFI_PASS "Overjamaya1945"

#include "AdafruitIO_WiFi.h"

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);
