# HÖRMANN Promatic 3 ESPHome Bridge
// what is this Repository about?  
// Requirements?

> [!CAUTION]  
> Read the [official Manual](TR10A147_E_ProMatic_3_DE.pdf) for safety instruction. Never work on 230V when your're not an expert. Unplug the device before start working for your own safety and to prevent damages while assembling.

// Why the ESP8266 and ESP32?

| Qty. | Ref.  | Part | Notes |
| ---- | ----  | ---- | ----- |
| 1    | A1    | **MP1584** 3,3V buck regulator | provides 3,3V stabilized; Input: 4,5–28 V |
| 1    | A2    | D1 Mini **ESP8266** or **ESP32** | use ESP32 version for BLE Support |
| 4    | U1-U4 | **PC819** optocoupler | for 24V/3,3V separation |
| 2    | R1-R2 | **2,2kΩ ½W** resistor | series resistor optocoupler LED at 24V |
| 2    | R3-R4 | **330Ω ¼W** resistor | series resistor optocoupler LED at 3,3V |
| 2    | C1-C2 | **0,47μF 35V** capacitor | catch voltage peaks from the driving motor |
| 1    | B1    | **reed switch** | to retrieve the "open" position |
| 1    | S1    | **momentary switch** | optional; for manual open/close/stop trigger |
| 1    | J1    | 2 leg **screw terminal** | for 24V/GND power supply |
| 1    | J2    | 4 leg **screw terminal** | for "garage closed", "motor opening/closing" and "open/close/stop trigger" |
| 1    | J3    | 3 leg **screw terminal** | for "garage open" (reed switch) and "manual open/close/stop" (momentary switch) |
| 1    | -     | Housing | recommended since the PCB does not fit in the Promatic 3 housing <br> as reference: I'm using these [project boxes](https://www.amazon.de/dp/B0BWLW941S) |



## Option 1: ESP8266
<details>
<summary>For basic functionalities the ESP8266 is totally suitable</summary>

### Circuit Diagram
![ESP8266 circuit diagram](images/ESP8266_circuit-diagram.svg)

### PCB-Design
<img src="images\ESP8266_PCB.png" width=500px>

If you like to order the PCB shown above, feel free to use the already exported production files. Or implement changes using **[fritzing](https://fritzing.org/download)** (check the [ESP8266 Pinout Reference](https://randomnerdtutorials.com/esp8266-pinout-reference-gpios/#wemos-d1-mini-pinout)!):
- **PCB-Design**: [ESP8266_extended-gerber.zip](ESP8266_extended-gerber.zip) (76 x 55,7mm)
- **Project File**: [ESP8266.fzz](ESP8266.fzz)

### Results (grid PCB)

I did my prototype on a grip PCB which also works great.  
Grid PCB: 70 x 50 mm / 24 x 18 holes / resistors vertical to save space

<img src="images\ESP8266_grid-PCB_top.jpg" width=300px>
<img src="images\ESP8266_grid-PCB_bottom.jpg" width=300px>

</details>


## Option 2: ESP32 mini
<details>
<summary>For extended functionalities the ESP32 mini is the better option</summary>

https://www.esp32learning.com/micropython/mh-et-live-minikit-for-esp32-and-micropython.php

</details>


## Connection

> [!WARNING]  
> Unplug the device before start working for your own safety and to prevent damages while assembling.

| this PCB | Promatic 3 | External | Function | Notes |
| -------- | ---------- | -------- | -------- | ----- |
| J1.1 | Terminal: 20 |  | **GND**  | see manual page 25, image 11 |
| J1.2 | Terminal: 5 |  | **24V**  | see manual page 25, image 11 |
| J2.1 | Terminal: 0V |  | **closed** state | see manual page 27, image 17 + 20.1 * |
| J2.2 | black motor wire |  | motor **opening** | will be pulled to GND when motor is running |
| J2.3 | red motor wire |  | motor **closing** | will be pulled to GND when motor is running |
| J2.4 | Terminal: 21 |  | **open/close/stop** trigger | see manual page 25, image 11 |
| J3.1 |  | reed switch <br> momentary switch | common **GND** | may have two wires; one to each switch |
| J3.2 |  | momentary switch | **manual trigger** | optional; will be pulled to GND as a trigger |
| J3.3 |  | reed switch | **open** state | will be pulled to GND when triggered |

To find the correct Terminal on this projects PCB please use the circuit diagramms and the official handbook as reference:
- [ESP8266_circuit-diagram.pdf](ESP8266_circuit-diagram.pdf)
- [ESP32-mini_circuit-diagram.pdf](ESP32-mini_circuit-diagram.pdf)
- [TR10A147_E_ProMatic_3_DE.pdf](TR10A147_E_ProMatic_3_DE.pdf) (or see pictures below)


| Image 11 | Image 17 * | Image 20.1 * |
| -------- | ---------- | ------------ |
| ![](images\manual_image-11.png) | ![](images\manual_image-17.png) | ![](images\manual_image-20.1.png) |

\* As can be seen in Image 20.1, the **DIP switch B** must be turned **ON**. This is required, so that the Terminal 0V (Image 17) gets activated when the Promatic 3 detects the garage door as closed. This will then subsequential set the garage door state in the ESP and Home Assistant to `closed`.



## Home Assistant Script



## Home Assistant Automation

