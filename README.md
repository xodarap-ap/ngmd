# Neo Geo Marquee Driver

This is a PCB designed to drive LED or EL panels to replace those in a Neo Geo multi-slot cabinet marquee. Many of these are partially or completely failed, and the EL panels are difficult to source. For those people who want to use EL panels these are readily available with a USB based 5v inverter, and for those who wish to use LED panels either USB based or with direct connection the LED variant has a 12 pin header with 6x 5v outputs

Features

- 8 pin JST/Molex style connector matching the MVS board header for easy connection
- USB connectors for EL panel connection
- Powered by Arduino Nano
- LED indicators for active panel (for testing/diagnosis of non working panels)
- Code can be easily reconfigured to allow whichever combination of USB ports you want to use to be active
- Self test mode at power on to identify any issues
- Attract mode with adjustable delay (cycles through marquees if you wanted to have a panel but do not have a multi-slot board)
- Manual mode with button and button header to manually cycle through marquees (similar to attract mode but with manual change)

Files included here:

Releases will be updated with Gerbers for the latest version of both PCB variants to allow you to order boards from whichever manufacturer you prefer. The Gerbers will also be available separately outside of a ZIP file in case you need these. PCB design files will be available under the PCB folder and will be the current variant under releases with previous versions under Deprecated if required. The .ino file in the main directory is the code to run the PCB and will work across both PCB variants

Parts required:

- 8 pin 2.54mm header - JST NH or Molex KK right angle is recommended
- 8 pin 2.54mm socket and pins (to build harness between MVS board and NGMD)
- Arduino Nano or equivalent
- N-Channel MOSFETs x 6 (TO-220 package)
- 3mm LEDs x 6
- USB A connectors x 6
- 2.54mm header pins and sockets (for mounting Arduino)
- 12 pin 2.54mm header (LED variant only)
- Optional: 5mm switch for manual switching
- Optional: 20k resistor (required if using manual switching)
- Optional: 2 pin 2.54mm header for manual switching button (if using cabinet button)

A full BOM with Digikey part numbers has been included in the main directory as BOM.xls
