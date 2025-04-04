# **ESP8266 Web-Controlled LED with CSS Styling**  
*A simple project to control an onboard LED via a web interface using an ESP8266 (NodeMCU).*  

![image](https://github.com/user-attachments/assets/c215c391-559d-451c-8939-32682c813d17)

*(LED OFF state - Button turns red when LED is ON)*  

---

## **📌 Features**  
✔ **Web-Based Control** – Toggle the LED from any device with a browser.  
✔ **Modern UI** – Styled with CSS (responsive design, glowing LED indicator).  
✔ **WiFi Connectivity** – Connects to your local network for remote access.  
✔ **Serial Debugging** – Includes Serial Monitor feedback for troubleshooting.  

---

## **🛠 Hardware Requirements**  
- **NodeMCU ESP8266** (or any ESP8266-based board)  
- **Micro-USB cable** (for power & programming)  
- **Computer** (for uploading code)  

---

## **⚙ Software Requirements**  
- **Arduino IDE** ([Download here](https://www.arduino.cc/en/software))  
- **ESP8266 Board Support** (Install via **Tools > Board > Boards Manager > Search "ESP8266"**)  
- **Required Libraries** (Auto-installed via Arduino IDE):  
  - `ESP8266WiFi.h`  
  - `ESP8266WebServer.h`  

---

## **🚀 Setup Instructions**  

### **1. Upload the Code**  
- Open `ESP8266_LED_WebControl.ino` in Arduino IDE.  
- Set **Board:** `NodeMCU 1.0 (ESP-12E Module)` (*Tools > Board*).  
- Select the correct **Port** (*Tools > Port*).  
- Update WiFi credentials in the code:  
  ```cpp
  const char* ssid = "Your_WiFi_SSID";
  const char* password = "Your_WiFi_Password";
  ```
- **Upload** the sketch (▶️ button).  

### **2. Access the Web Interface**  
1. Open **Serial Monitor** (`Ctrl+Shift+M`, set baud rate to `115200`).  
2. Note the **IP address** (e.g., `192.168.1.100`).  
3. Enter this IP in any web browser (phone/PC).  

### **3. Control the LED**  
- Click **"Toggle LED"** to turn the onboard LED (GPIO2) ON/OFF.  
- The webpage updates in real-time with a visual LED indicator.  

---

## **🔧 Troubleshooting**  
❌ **No Serial Output?**  
- Check USB cable (some are power-only).  
- Ensure correct **COM port** is selected.  
- Press the **RST button** on the NodeMCU.  

❌ **WiFi Not Connecting?**  
- Verify SSID/password.  
- Move closer to the router.  
- Check for special characters in WiFi credentials.  

❌ **Webpage Not Loading?**  
- Ensure the ESP8266 and your device are on the **same network**.  
- Restart the ESP8266.  

---

## **📝 Customization**  
- **Change LED Pin**: Modify `const int ledPin = 2;` to another GPIO.  
- **Modify CSS**: Edit the HTML string in `htmlPage()` for different styles.  
- **Add More LEDs**: Extend the web interface with additional buttons.  

---

## **📂 Project Structure**  
```
ESP8266_LED_WebControl/  
├── ESP8266_LED_WebControl1.ino  # Main Arduino sketch
├── ESP8266_LED_WebControl.ino 
├── README.md                   # This guide    
```

---

## **📜 License**  
MIT License - Free to use, modify, and distribute.  

**Happy Tinkering!** 🎉  
*Let me know if you need enhancements!* 😊  

---

### **Credits**  
- **Author**: Ro706  
- **GitHub**: github.com/Ro706 
- **Inspired by**: ESP8266 WebServer examples  

🚀 **Star this repo if you found it useful!** ⭐
