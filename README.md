# 🌡️ Arduino ile Sıcaklık Kontrollü Soğutma Sistemi

![Arduino](https://img.shields.io/badge/Arduino-00878F?style=flat-square&logo=arduino&logoColor=white)
![C++](https://img.shields.io/badge/C++-00599C?style=flat-square&logo=cplusplus&logoColor=white)

LM35 sensörüyle ortam sıcaklığını ölçen ve sıcaklık eşiği aşıldığında fanı PWM ile çalıştıran gömülü sistem projesi.

## ⚙️ Çalışma Mantığı
1. LM35'ten analog değer okunur ve °C'ye çevrilir (10 mV/°C).
2. Sıcaklık **30 °C'nin üzerindeyse** fan, L298N motor sürücüsü üzerinden **25 kHz PWM** ile çalıştırılır.
3. Sıcaklık ve fan durumu seri port üzerinden izlenir.

## 🔧 Donanım
- Arduino Uno
- LM35 sıcaklık sensörü
- L298N motor sürücü
- DC fan

## 📁 Dosyalar
| Dosya | Açıklama |
|---|---|
| `gomulu/gomulu.ino` | Arduino kaynak kodu (`TimerOne` kütüphanesi) |
| `gomulu/fritzing çizim.png` | Devre şeması |
| `gomulu/projerapor.docx` | Proje raporu |

![Devre şeması](gomulu/fritzing%20çizim.png)
