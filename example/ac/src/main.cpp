// Auto generated code by esphomeyaml
#include "esphomelib/application.h"
#include "ESPHomeLibFrigidaireACComponent.h"

using namespace esphomelib;

void setup() {
  // ===== DO NOT EDIT ANYTHING BELOW THIS LINE =====
  // ========== AUTO GENERATED CODE BEGIN ===========
  App.set_name("ac");
  App.set_compilation_datetime(__DATE__ ", " __TIME__);
  ::LogComponent *_logcomponent = App.init_log(115200);
  _logcomponent->set_global_log_level(ESPHOMELIB_LOG_LEVEL_INFO);
  ::WiFiComponent *_wificomponent = App.init_wifi();
  _wificomponent->set_sta(::WiFiAp{
      .ssid = "My Wifi SSID",
      .password = "My Wifi Password",
      .channel = -1,
  });
  ::OTAComponent *_otacomponent = App.init_ota();
  _otacomponent->start_safe_mode();
  mqtt::MQTTClientComponent *mqtt_mqttclientcomponent = App.init_mqtt("mosquitto.org", 1883, "", "");
  // =========== AUTO GENERATED CODE END ============
  // ========= YOU CAN EDIT AFTER THIS LINE =========

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

  App.setup();
}

void loop() {
  App.loop();
  delay(16);
}
