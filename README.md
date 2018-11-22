# Frigidaire AC Component for ESPHomeLib

A barebones wrapper to enable control of a Frigidarie AC via ESPHomeLib.
Tested with ESPHomeLib 1.9.1, and a Wemos D1 Mini w/a IRLED.

I've decoded the IR commands for the AC and they're NEC. However, the way ESPHomeLib's build-in Remote Transmitter works with NEC isn't compatible.

## Setup/Use

I've included my `ac.yaml`, `ac/src/main.cpp`, and `ac/platformio.ini` files as examples. My changes are isolated between:

* `; // Start FrigidaireAC Component Addition`
* `; // End FrigidaireAC Component Addition`.

### ac.yaml

```yaml
esphomeyaml:
  use_custom_code: True
  name: AC
  platform: ESP8266
  board: esp01_1m

wifi:
  ssid: !secret wifi_ssid
  password: !secret wifi_password

mqtt:
  broker: !secret mqtt_broker
  discovery: true

logger:
  level: info

ota:

binary_sensor:
  - platform: status
    name: "AC Status"
```

### ac/platformio.ini

```ini
; Auto generated code by esphomeyaml

[common]
; // Start FrigidaireAC Component Addition
lib_deps = 
  IRRemoteESP8266
  ESPHomeLibFrigidaireACComponent=https://github.com/mannkind/ESPHomeLibFrigidaireACComponent
build_flags =
upload_flags =
; // End FrigidaireAC Component Addition

; ===== DO NOT EDIT ANYTHING BELOW THIS LINE =====
; ========== AUTO GENERATED CODE BEGIN ===========
[env:AC]
platform = espressif8266@>=1.8.0
board = esp01_1m
framework = arduino
lib_deps =
    ArduinoOTA
    ESP8266WiFi
    ESP8266mDNS
    Hash
    https://github.com/OttoWinter/esphomelib.git#v1.9.1
    ${common.lib_deps}
build_flags =
    -DESPHOMELIB_LOG_LEVEL=ESPHOMELIB_LOG_LEVEL_INFO
    -DUSE_NEW_OTA
    ${common.build_flags}
upload_speed = 115200
; =========== AUTO GENERATED CODE END ============
; ========= YOU CAN EDIT AFTER THIS LINE =========
```

### AC/src/main.cpp

```c++
// Auto generated code by esphomeyaml
#include "esphomelib/application.h"
; // Start FrigidaireAC Component Addition
#include "ESPHomeLibFrigidaireACComponent.h"
; // End FrigidaireAC Component Addition

using namespace esphomelib;

void setup() {
  // ===== DO NOT EDIT ANYTHING BELOW THIS LINE =====
  // ========== AUTO GENERATED CODE BEGIN ===========
  App.set_name("AC");
  App.set_compilation_datetime(__DATE__ ", " __TIME__);
  ::LogComponent *_logcomponent = App.init_log(115200);
  _logcomponent->set_global_log_level(ESPHOMELIB_LOG_LEVEL_INFO);
  ::WiFiComponent *_wificomponent = App.init_wifi();
  _wificomponent->set_sta(::WiFiAp{
      .ssid = "",
      .password = "",
      .channel = -1,
  });
  ::OTAComponent *_otacomponent = App.init_ota();
  _otacomponent->start_safe_mode();
  mqtt::MQTTClientComponent *mqtt_mqttclientcomponent = App.init_mqtt("", 1883, "", "");
  ::Application::MakeStatusBinarySensor _application_makestatusbinarysensor = App.make_status_binary_sensor("AC Status");
  binary_sensor::StatusBinarySensor *binary_sensor_statusbinarysensor = _application_makestatusbinarysensor.status;
  binary_sensor::MQTTBinarySensorComponent *binary_sensor_mqttbinarysensorcomponent = _application_makestatusbinarysensor.mqtt;
  // =========== AUTO GENERATED CODE END ============
  // ========= YOU CAN EDIT AFTER THIS LINE =========
  ; // Start FrigidaireAC Component Addition
  auto *custom_ir = new IRComponent(
      "On",
      "Off",
      "Temp Up",
      "Temp Down",
      "Speed Up",
      "Speed Down",
      "Speed Auto",
      5,            /* IRLED pin */
      5000          /* Update interval ... unused, I think */
  );

  App.register_component(custom_ir);
  App.register_switch(custom_ir->on_switch);
  App.register_switch(custom_ir->off_switch);
  App.register_switch(custom_ir->tempup_switch);
  App.register_switch(custom_ir->tempdown_switch);
  App.register_switch(custom_ir->speedup_switch);
  App.register_switch(custom_ir->speeddown_switch);
  App.register_switch(custom_ir->speedauto_switch);
  ; // End FrigidaireAC Component Addition
  App.setup();
}

void loop() {
  App.loop();
  delay(16);
}
```