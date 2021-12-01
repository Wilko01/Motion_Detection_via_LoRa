# Motion sensor communicating over LoRa
The challenge is to detect motion when someone enters the premise and send it over a longer distance to a location 50+m away where the residents are located and are triggered via a signal that someone is coming.


<img src="Images/Air_quality_meter01.jpg" alt="drawing" width="700"/>

<img src="Images/Air_quality_meter08.jpg" alt="drawing" width="700"/>


## Description and operation instructions
The motion sensor HC-SR501 in combination with LoRa RFM95W-868S2 transceiver is used to send a LoRa signal when motion is detected. At some distance the signal is received with a LoRa RFM95W-868S2 transceiver and LED and beeper will signal that the motion sensor was triggered. The RFM95W-868S2 are controlled via a ESP32-WROOM-32U at the transmitter and receiver.

 ## Technical description
The LoRa RFM95W-868S2 transceiver is connected to the ESP32-WROOM-32D

 ### LoRa Transmitter
| LoRa RFM95W-868S2 | ESP32      | LED + 3k3 risistor| 3,3V beeper    | HC-SR501 | 
| ------------------|------------|-------------------|----------------| -------- |
| GND               | GND        | GND               | GND            |          |
| Reset             | D14        |                   |                |          |
| NSS               | D5         |                   |                |          |
| SCK               | D18        |                   |                |          |
| MOSI              | D23        |                   |                |          |
| MISO              | D19        |                   |                |          |
| 3.3V              | 3V3        |                   |                |          |
| DIO0              | 25         |                   |                |          |
|                   |            | D26               |                |          |
|                   |            |                   | D12            |          |
|                   |            |                   |                | D27      |

### LoRa Receiver
| LoRa RFM95W-868S2 | ESP32      | LED + 3k3 risistor| 3,3V beeper    | 
| ------------------|------------|-------------------|----------------|
| GND               | GND        | GND               | GND            |
| Reset             | D14        |                   |                |
| NSS               | D5         |                   |                |
| SCK               | D18        |                   |                |
| MOSI              | D23        |                   |                |
| MISO              | D19        |                   |                |
| 3.3V              | 3V3        |                   |                |
| DIO0              | 25         |                   |                |
|                   |            | D26               |                |
|                   |            |                   | D12            |
|                   |            |                   |                |


### Parts
- 1 x ESP32-WROOM-32U

<img src="Images/ESP32-WROOM-32U.jpg" alt="drawing" width="150"/>

- 1 x 2.4GHz antenna

<img src="Images/2.4GHz_Antenna.jpg" alt="drawing" width="150"/>



- 4 x Screws 2.6 x 20 mm
- 1 x thumbtack
- 1 x Micro USB connector


### Schematic overview
<img src="Images/Schematic_overview.jpg" alt="drawing" width="500"/>

### ESPHome installation
See the instructions https://github.com/Wilko01/ESPHome  (not listed here)


### ESPHome Configuration in Home Assistant
Create a new device  with this code:


### Interface
#### Home Assistant
Home Assistant is connected via the ESPHome integration. The hazardous values for the 2.5um are different from the values of the 10.0um. Therefore two cards are made in the dashboard.

<img src="Images/Dashboard 2.5 and 10.0um.jpg" alt="drawing" width="500"/>




### Testing
Create a dashboard in Home Assistant and see the measurements come in. Depending on the measurement interval this can take some time.

## 3D printer files
It all started by measuring the air quality when printing, so the 3D printer files must be included in this project:
- [3D files include the Sketchup make file as well as the 3D print files .STL](/3D_Printer_Files)
- [Thingiverse](https://www.thingiverse.com/thing:5135259)


### Information


Generic
- [Markdown Cheat Sheet](https://www.markdownguide.org/cheat-sheet/)


### Problems
..

### Wishlist
..


