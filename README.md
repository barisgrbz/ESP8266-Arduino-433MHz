# ESP8266-Arduino-433MHz

## 📡 ESP8266 & Arduino ile 433MHz RF Alıcı & Verici Kontrolü
Bu proje, **ESP8266 veya Arduino** kullanarak **433MHz RF sinyalleri alıp göndermenizi** sağlar. **RCSwitch** kütüphanesi ile **kablosuz haberleşme** yapmak mümkündür.

---

## 🚀 Özellikler
✅ **ESP8266 ve Arduino Desteği**
✅ **433MHz RF Alıcı & Verici Kullanımı**
✅ **Seri Port Üzerinden Komut Gönderme**
✅ **Otomatik Kart Algılama (ESP8266 / Arduino)**
✅ **Kolay Entegrasyon & Kullanım**

---

## 🔧 Donanım Gereksinimleri
- **ESP8266 (NodeMCU, Wemos D1 Mini) veya Arduino (Uno, Mega vb.)**
- **433MHz RF Alıcı (RXB6, MX-RM-5V vb.)**
- **433MHz RF Verici (XY-FST, FS1000A vb.)**
- **Bağlantı kabloları**

---

## 🔌 Bağlantı Şeması
### **Arduino İçin**
- **Verici Data Pin:** 10. Pin
- **Alıcı Data Pin:** 2. Pin

### **ESP8266 İçin**
- **Verici Data Pin:** D2 (GPIO4)
- **Alıcı Data Pin:** D1 (GPIO5)

---

## 🛠️ Kütüphane Kurulumu
Arduino IDE veya PlatformIO üzerinde **RCSwitch** kütüphanesini yüklemek için:
1. **Arduino IDE** için:
   - "Sketch" -> "Include Library" -> "Manage Libraries" menüsüne girin.
   - **"RCSwitch"** yazarak kütüphaneyi yükleyin.

2. **PlatformIO** için:
   ```ini
   lib_deps = sui77/RCSwitch@^2.6.4
   ```

---

## 🎮 Kullanım
1. **Cihazı USB ile bağlayın ve kodu yükleyin.**
2. **Seri Monitörü (Baud: 9600) açın.**
3. **Komutlar:**
   - **'r'** tuşuna basarsanız **alıcı modu** aktif olur.
   - **'t'** tuşuna basarsanız **verici modu** aktif olur ve RF kodu gönderilir.

---

## 📜 Lisans
Bu proje, **GNU GPL-2.0** lisansı altında yayımlanmaktadır. **RCSwitch** kütüphanesi de **GPL-2.0 lisansı** altındadır. Daha fazla bilgi için: [GPL-2.0 Lisans Metni](https://www.gnu.org/licenses/old-licenses/gpl-2.0.txt)

**RCSwitch Kütüphanesi:** [https://github.com/sui77/rc-switch](https://github.com/sui77/rc-switch)

---

## 📩 Katkıda Bulunma
Projeye katkıda bulunmak için **pull request gönderebilir** veya **hata bildirimi** yapabilirsiniz. Geri bildirimleriniz değerlidir! 😊

