#include "esphome.h"
#include <IRremoteESP8266.h>
#include <IRsend.h>

static const char *TAG = "component.IR";

class FrigidaireACSwitch : public Component, public Switch {
public:
  uint8_t pin;
  IRsend *irsend;
  FrigidaireACSwitch(uint8_t pin) : pin(pin) {}
  void setup() override {
    ESP_LOGCONFIG(TAG, "Setting up FrigidaireACSwitch '%s' on pin '%d'...", this->name_.c_str(), this->pin);
    this->irsend = new IRsend(this->pin);
    this->irsend->begin();
  }
  void set_pin(uint8_t pin) { 
    ESP_LOGCONFIG(TAG, "Setting pin '%d' on '%s'...", pin, this->name_.c_str());
    this->pin = pin; 
  }
};


class IROnOffSwitch :public FrigidaireACSwitch
{
public:
  using FrigidaireACSwitch::FrigidaireACSwitch;
  void write_state(bool state) override
  {
    this->publish_state(state);
    this->irsend->sendNEC(0x10AF8877, 32);
  }
};

class IRTempUpSwitch :public FrigidaireACSwitch
{
public:
  using FrigidaireACSwitch::FrigidaireACSwitch;
  void write_state(bool state) override
  {
    this->publish_state(true);
    this->irsend->sendNEC(0x10AF708F, 32);
    this->publish_state(false);
  }
};

class IRTempDownSwitch :public FrigidaireACSwitch
{
public:
  using FrigidaireACSwitch::FrigidaireACSwitch;
  void write_state(bool state) override
  {
    this->publish_state(true);
    this->irsend->sendNEC(0x10AFB04F, 32);
    this->publish_state(false);
  }
};

class IRSpeedUpSwitch :public FrigidaireACSwitch
{
public:
  using FrigidaireACSwitch::FrigidaireACSwitch;
  void write_state(bool state) override
  {
    this->publish_state(true);
    this->irsend->sendNEC(0x10AF807F, 32);
    this->publish_state(false);
  }
};

class IRSpeedDownSwitch :public FrigidaireACSwitch
{
public:
  using FrigidaireACSwitch::FrigidaireACSwitch;
  void write_state(bool state) override
  {
    this->publish_state(true);
    this->irsend->sendNEC(0x10AF20DF, 32);
    this->publish_state(false);
  }
};

class IRSpeedAutoSwitch :public FrigidaireACSwitch
{
public:
  using FrigidaireACSwitch::FrigidaireACSwitch;
  void write_state(bool state) override
  {
    this->publish_state(true);
    this->irsend->sendNEC(0x10AFF00F, 32);
    this->publish_state(false);
  }
};
