# Frigidaire AC Component for ESPHome

A barebones wrapper to enable control of a Frigidarie AC via ESPHome.
Tested with ESPHome 1.12.1, and a Wemos D1 Mini w/a IRLED.

I've decoded the IR commands for the AC and they're NEC. However, the way ESPHome's build-in Remote Transmitter works with NEC isn't compatible.

## Setup/Use

Take a look at the example directory for a fully working example (very close to my setup).