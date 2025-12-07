# Arduino TEA5767 FM Radyo Projesi 📻

Bu proje, Arduino ve TEA5767 modülü kullanılarak yapılmış, LCD ekran üzerinden frekansın görülebildiği ve potansiyometre ile kontrol edilen bir FM Radyo uygulamasıdır.


## 🎥 Proje Videosu

Projenin çalışır halini ve detaylı anlatımını aşağıdaki videodan izleyebilirsiniz:

[![Arduino FM Radyo Video](https://img.youtube.com/vi/B3Dgg-0vkHU/0.jpg)](https://www.youtube.com/watch?v=B3Dgg-0vkHU)

*(Videoyu izlemek için resme tıklayın)*

## 🛠️ Malzemeler

* **Arduino Uno** (veya Nano)
* **TEA5767** FM Radyo Modülü
* **LCD1602** Ekran (I2C Modüllü)
* **Potansiyometre** (10kΩ önerilir)
* Jumper kablolar ve Breadboard
* Hoparlör veya Kulaklık

## 🔌 Bağlantı Şeması (Pinout)

Projede kullanılan bağlantılar aşağıdadır. Kodları yüklemeden önce bağlantılarınızı bu tabloya göre kontrol edin.

### TEA5767 Radyo Modülü
| TEA5767 Pin | Arduino Pin | Açıklama |
| :--- | :--- | :--- |
| VCC | 5V | Güç |
| GND | GND | Toprak |
| SDA | A4 | I2C Veri |
| SCL | A5 | I2C Saat |

### LCD1602 Ekran (I2C)
| LCD Pin | Arduino Pin |
| :--- | :--- |
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |


### Potansiyometre (Kanal Ayarı)
| Potansiyometre Pin | Arduino Pin |
| :--- | :--- |
| Orta Uç (Sinyal) | **A1** |
| Kenar Uç 1 | 5V |
| Kenar Uç 2 | GND |

## 🚀 Kurulum ve Kullanım

1.  Yukarıdaki şemaya göre devrenizi kurun.
2.  Bu depodaki `.ino` uzantılı dosyayı bilgisayarınıza indirin.
3.  Arduino IDE ile dosyayı açın.
4.  Gerekli kütüphanelerin (Örn: `Wire.h`, `LiquidCrystal_I2C.h`) yüklü olduğundan emin olun.
5.  Kodu Arduino kartınıza yükleyin.
6.  Potansiyometreyi çevirerek frekanslar arasında gezinebilirsiniz.

## 📝 Notlar
* LCD ekranınızda görüntü gelmezse, I2C modülünün arkasındaki mavi potansiyometre ile kontrast ayarı yapmayı unutmayın.
* Daha net ses alabilmek için TEA5767 modülünün anten girişine bir kablo lehimlemeniz gerekebilir.

---
