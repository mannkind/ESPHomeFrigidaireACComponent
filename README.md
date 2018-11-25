# Frigidaire AC Component for ESPHomeLib

A barebones wrapper to enable control of a Frigidarie AC via ESPHomeLib.
Tested with ESPHomeLib 1.9.1, and a Wemos D1 Mini w/a IRLED.

I've decoded the IR commands for the AC and they're NEC. However, the way ESPHomeLib's build-in Remote Transmitter works with NEC isn't compatible.

## Setup/Use

Take a look at the example directory for a fully working example (very close to my setup).

In short:

* Add `#include "ESPHomeLibFrigidaireACComponent.h"` under the esphomelib include.

* Add the following before `App.setup()`

  ```c++
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
  ```