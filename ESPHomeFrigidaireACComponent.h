#include "esphome.h"
#include <IRremoteESP8266.h>
#include <IRsend.h>
using namespace esphomelib;

static const char *TAG = "component.IR";

class IROnOffSwitch : public switch_::Switch
{
public:
  IRsend *irsend;
  IROnOffSwitch(const std::string &name, IRsend *irsend) : switch_::Switch(name), irsend(irsend) {}

  void write_state(bool state) override
  {
    this->publish_state(state);
    this->irsend->sendNEC(0x10AF8877, 32);
  }
};

class IRTempUpSwitch : public switch_::Switch
{
public:
  IRsend *irsend;
  IRTempUpSwitch(const std::string &name, IRsend *irsend) : switch_::Switch(name), irsend(irsend) {}

  void write_state(bool state) override
  {
    this->publish_state(true);
    this->irsend->sendNEC(0x10AF708F, 32);
    this->publish_state(false);
  }
};

class IRTempDownSwitch : public switch_::Switch
{
public:
  IRsend *irsend;
  IRTempDownSwitch(const std::string &name, IRsend *irsend) : switch_::Switch(name), irsend(irsend) {}

  void write_state(bool state) override
  {
    this->publish_state(true);
    this->irsend->sendNEC(0x10AFB04F, 32);
    this->publish_state(false);
  }
};

class IRSpeedUpSwitch : public switch_::Switch
{
public:
  IRsend *irsend;
  IRSpeedUpSwitch(const std::string &name, IRsend *irsend) : switch_::Switch(name), irsend(irsend) {}

  void write_state(bool state) override
  {
    this->publish_state(true);
    this->irsend->sendNEC(0x10AF807F, 32);
    this->publish_state(false);
  }
};

class IRSpeedDownSwitch : public switch_::Switch
{
public:
  IRsend *irsend;
  IRSpeedDownSwitch(const std::string &name, IRsend *irsend) : switch_::Switch(name), irsend(irsend) {}

  void write_state(bool state) override
  {
    this->publish_state(true);
    this->irsend->sendNEC(0x10AF20DF, 32);
    this->publish_state(false);
  }
};

class IRSpeedAutoSwitch : public switch_::Switch
{
public:
  IRsend *irsend;
  IRSpeedAutoSwitch(const std::string &name, IRsend *irsend) : switch_::Switch(name), irsend(irsend) {}

  void write_state(bool state) override
  {
    this->publish_state(true);
    this->irsend->sendNEC(0x10AFF00F, 32);
    this->publish_state(false);
  }
};

class IRComponent : public PollingComponent
{
public:
  IRsend *irsend;
  IROnOffSwitch *onoff_switch;
  IRTempUpSwitch *tempup_switch;
  IRTempDownSwitch *tempdown_switch;
  IRSpeedUpSwitch *speedup_switch;
  IRSpeedDownSwitch *speeddown_switch;
  IRSpeedAutoSwitch *speedauto_switch;

  IRComponent(
      const std::string &onoffSwitchName,
      const std::string &tempUpSwitchName,
      const std::string &tempDownSwitchName,
      const std::string &speedUpSwitchName,
      const std::string &speedDownSwitchName,
      const std::string &speedAutoSwitchName,
      uint8_t pin)
      : PollingComponent(0)
  {
    this->irsend = new IRsend(pin);
    this->onoff_switch = new IROnOffSwitch(onoffSwitchName, irsend);
    this->tempup_switch = new IRTempUpSwitch(tempUpSwitchName, irsend);
    this->tempdown_switch = new IRTempDownSwitch(tempDownSwitchName, irsend);
    this->speedup_switch = new IRSpeedUpSwitch(speedUpSwitchName, irsend);
    this->speeddown_switch = new IRSpeedDownSwitch(speedDownSwitchName, irsend);
    this->speedauto_switch = new IRSpeedAutoSwitch(speedAutoSwitchName, irsend);
  }

  void setup() override
  {
      this->irsend->begin();
  }

  void update() override
  {
  }
};
