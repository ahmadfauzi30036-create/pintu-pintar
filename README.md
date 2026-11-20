# Pintu Pintar (Smart Door Servo Control)

> Arduino-based mini smart-home door: a potentiometer sets the door angle (0°–90°), a servo moves the door, and an I2C LCD shows the commanded angle.

Model rumah pintar dengan pintu mini yang bukaannya diatur memakai potensiometer. Pintu tertutup pada **0°** dan terbuka penuh pada **90°**, sehingga pengguna bisa membuka pintu sebagian atau sepenuhnya.

## Fitur
- Kontrol sudut bertahap 0°–90° dengan potensiometer
- Servo posisi menggerakkan pintu sesuai sudut perintah
- LCD 16x2 (I2C) menampilkan sudut dan status (TERTUTUP / SEBAGIAN / TERBUKA)
- Pengujian pada 0°, 30°, 60°, dan 90° dengan perbandingan sudut aktual

## Komponen
| Komponen | Jumlah |
|---|---|
| Arduino Uno | 1 |
| Potensiometer 10 kΩ | 1 |
| Servo SG90 / MG90S | 1 |
| LCD 16x2 + modul I2C | 1 |
| Breadboard dan kabel jumper | secukupnya |

## Wiring
| Komponen | Pin Arduino |
|---|---|
| Potensiometer kaki kiri | 5V |
| Potensiometer wiper (tengah) | A0 |
| Potensiometer kaki kanan | GND |
| Servo sinyal | D9 (PWM) |
| Servo VCC / GND | 5V / GND |
| LCD I2C SDA / SCL | A4 / A5 |
| LCD I2C VCC / GND | 5V / GND |

> Jika servo bergetar atau Arduino reset, gunakan catu daya 5V terpisah untuk servo dan sambungkan GND-nya ke GND Arduino.

## Cara Menjalankan
1. Pasang rangkaian sesuai tabel wiring.
2. Install library **LiquidCrystal I2C** lewat Arduino IDE (Library Manager).
3. Buka `pintu_pintar/pintu_pintar.ino`, pilih board **Arduino Uno**, lalu upload.
4. Putar potensiometer dan amati pintu serta tampilan LCD.

Jika LCD tidak menampilkan apa pun, ganti alamat I2C di kode dari `0x27` ke `0x3F`.

## Cara Kerja
Nilai ADC (0–1023) dari potensiometer dipetakan secara linear ke sudut 0–90° dengan `map()`, dibatasi dengan `constrain()`, lalu dikirim ke servo dengan `Servo.write()`. LCD hanya diperbarui saat sudut berubah agar tidak berkedip.

## Hasil Pengujian
Ukur sudut aktual pintu dengan busur derajat, lalu isi tabel berikut dengan hasil pengukuran Anda sendiri.

| Sudut perintah (LCD) | Sudut aktual (busur) | Selisih | Error (%) |
|---|---|---|---|
| 0° | | | |
| 30° | | | |
| 60° | | | |
| 90° | | | |

Rumus: `Selisih = |aktual − perintah|`, `Error (%) = selisih / perintah × 100%`.

### Analisis
Tulis di sini apa yang Anda amati. Beberapa penyebab umum selisih kecil: resolusi ADC 10-bit dan pembulatan `map()`, deadband dan backlash gigi servo murah, pembacaan busur derajat, serta tegangan suplai yang tidak stabil.

## Pengembangan Selanjutnya
- Kalibrasi sudut dengan `writeMicroseconds()`
- Pergerakan servo yang dihaluskan (smoothing)
- Kontrol lewat Bluetooth atau Wi-Fi

## Lisensi
MIT License. Lihat file [LICENSE](LICENSE).

## Penulis
Ahmad Fauzi ([@ahmadfauzi30036-create](https://github.com/ahmadfauzi30036-create))
