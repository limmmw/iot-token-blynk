# IoT Token Blynk

Proyek ini adalah aplikasi sederhana yang digunakan untuk mengelola perangkat IoT yang terhubung dengan server Blynk. Aplikasi ini menyediakan beberapa endpoint untuk berinteraksi dengan perangkat IoT, seperti mendapatkan status buzzer, mengatur status buzzer, dan memperbarui lokasi perangkat.

## Fitur Utama
- **GET /get_buzzer_status.php**: Mendapatkan status buzzer perangkat.
- **POST /set_buzzer.php**: Mengatur status buzzer perangkat (on/off).
- **POST /update_location.php**: Memperbarui lokasi perangkat IoT.

## Struktur Direktori
```
.
├── esp32.ino              # Kode untuk perangkat IoT (ESP32)
├── get_buzzer_status.php  # Endpoint untuk mendapatkan status buzzer
├── index.php              # Halaman utama untuk dokumentasi API
├── set_buzzer.php         # Endpoint untuk mengatur status buzzer
├── update_location.php    # Endpoint untuk memperbarui lokasi perangkat
├── README.md              # Dokumentasi proyek
```

## Cara Menggunakan

### 1. Persiapan
- Pastikan server web (seperti Apache atau Nginx) dan PHP sudah terinstal di sistem Anda.
- Letakkan folder proyek ini di direktori root server web Anda (misalnya, `/var/www/html/`).

### 2. Endpoint yang Tersedia

#### **GET /get_buzzer_status.php**
Digunakan untuk mendapatkan status buzzer perangkat.

**Contoh Penggunaan:**
```
GET /get_buzzer_status.php?token=YOUR_VALID_TOKEN
```

#### **POST /set_buzzer.php**
Digunakan untuk mengatur status buzzer perangkat.

**Parameter:**
- `status` (wajib): Status buzzer yang diinginkan (`on` atau `off`).

**Contoh Penggunaan:**
```
POST /set_buzzer.php
Body: { "status": "on" }
```

#### **POST /update_location.php**
Digunakan untuk memperbarui lokasi perangkat IoT.

**Parameter:**
- `latitude` (wajib): Koordinat lintang perangkat.
- `longitude` (wajib): Koordinat bujur perangkat.

**Contoh Penggunaan:**
```
POST /update_location.php
Body: { "latitude": "-6.200000", "longitude": "106.816666" }
```

## Catatan Penting
- Pastikan token yang digunakan valid dan aktif.
- Gunakan koneksi yang aman (HTTPS) saat mengirimkan data sensitif.
- Hubungi administrator jika mengalami masalah.

## Lisensi
Proyek ini dilisensikan di bawah [MIT License](LICENSE).