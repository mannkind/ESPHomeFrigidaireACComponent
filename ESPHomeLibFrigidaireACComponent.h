#include "esphomelib/application.h"
#include <IRremoteESP8266.h>
#include <IRsend.h>

using namespace esphomelib;

static const char *TAG = "component.IR";

class IROnSwitch : public switch_::Switch
{
public:
  IRsend *irsend;
  IROnSwitch(const std::string &name, IRsend *irsend) : switch_::Switch(name), irsend(irsend) {}

  void write_state(bool state) override
  {
    this->publish_state(true);
    this->irsend->sendNEC(0x10AF8877, 32);
    this->publish_state(false);
  }
};

class IROffSwitch : public switch_::Switch
{
public:
  IRsend *irsend;
  IROffSwitch(const std::string &name, IRsend *irsend) : switch_::Switch(name), irsend(irsend) {}

  void write_state(bool state) override
  {
    this->publish_state(true);
    this->irsend->sendNEC(0x10AF8877, 32);
    this->publish_state(false);
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
  IROnSwitch *on_switch;
  IROnSwitch *off_switch;
  IROnSwitch *tempup_switch;
  IROnSwitch *tempdown_switch;
  IROnSwitch *speedup_switch;
  IROnSwitch *speeddown_switch;
  IROnSwitch *speedauto_switch;

  IRComponent(
      const std::string &onSwitchName,
      const std::string &offSwitchName,
      const std::string &tempUpSwitchName,
      const std::string &tempDownSwitchName,
      const std::string &speedUpSwitchName,
      const std::string &speedDownSwitchName,
      const std::string &speedAutoSwitchName,
      uint8_t pin,
      uint32_t update_interval)
      : PollingComponent(update_interval)
  {
    this->irsend = new IRsend(pin);
    this->on_switch = new IROnSwitch(onSwitchName, irsend);
    this->off_switch = new IROnSwitch(offSwitchName, irsend);
    this->tempup_switch = new IROnSwitch(tempUpSwitchName, irsend);
    this->tempdown_switch = new IROnSwitch(tempDownSwitchName, irsend);
    this->speedup_switch = new IROnSwitch(speedUpSwitchName, irsend);
    this->speeddown_switch = new IROnSwitch(speedDownSwitchName, irsend);
    this->speedauto_switch = new IROnSwitch(speedAutoSwitchName, irsend);
  }

  void setup() override
  {
      this->irsend->begin();
  }

  void update() override
  {
  }
};
