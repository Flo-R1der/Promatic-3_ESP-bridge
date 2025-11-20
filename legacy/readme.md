

> [!IMPORTANT]  
> The ESP32 D1 Mini was causing a lot of trouble. Therefore it is now **marked as legacy**. If you still want to use it and experience the same, here is what I did to overcome the issues:
> 1. The ESP32 D1 mini does not have a BOOT button. To put the device in FLASH-Mode, **`GPIO0` must be connected to `GND`** ([Pinout Reference](https://www.espboards.dev/esp32/d1-mini32/)).
> 2. The [ESPHome Web Installer](https://web.esphome.io/) wasn't connecting to my device, but **the [Tasmota Web Installer](https://tasmota.github.io/install/) worked _sometimes_.**
> 3. To ensure proper connection I installed [ESPHome on the local PC](https://esphome.io/guides/installing_esphome/). From there I was able to **[compile and flash](https://esphome.io/guides/getting_started_command_line/#first-uploading) from the shell**.  
>    - Command: `esphome run garage.yaml` _(you may adapt the yaml-name)_
> 4. When something seems to be corrupt an `erase-flash`-command from the [Espressif ESPTool](https://docs.espressif.com/projects/esptool/en/latest/esp32/) may help performing a **factory reset, if required** (see also [this Tutorial](https://randomnerdtutorials.com/esp32-erase-flash-memory/)).
> 5. The more modern **framework type `esp-idf` was causing boot-loops** on the ESP32 D1 mini, whenever **WiFi is enabled**.
> 6. Switching to  `arduino` framework was causing an **oversized firmware, with bluetooth components** enabled. Therefore, I disabled the fallback-hotspot and captive portal to reduce it's size, which removes the ability to update WiFi-password from the device hotspot.
> 7. When powering the ESP32 D1 Mini **with 3.3V only, the device would not start** most of the times. With additional USB power connected it's starting, but that is just a workaround. At least when started and USB disconnected, the device was capable to do everything as expected, including OTA-Updates.

### ESP32 D1 mini

> **Firmware Template: [ESP32-D1-mini.yaml](ESP32-D1-mini.yaml)**

This file is basically a copy of the ESP8266 and is working the same way. Also the entities mentioned above are similar. However, the ESP32 has some considerable extras defined:
- **Bluetooth Beacon**
  - can be used to identify the vehicle, on which the garage door should open.
  - To discover bluetooth beacons, you might use the [discovery code](ESP32_beacon-discovery.yaml) first.
- **Bluetooth Proxy**
  - To proxy bluetooth signals (button press, BLE-sensors, etc.) to your Home Assistant instance.


<br>