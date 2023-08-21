# Moji: Solusi Monitorisasi Haji Berbasis IoT

Moji merupakan sebuah solusi monitorisasi haji yang inovatif, dirancang sebagai perangkat Internet of Things (IoT) dengan tujuan utama untuk mengatasi dan mencegah masalah kehilangan atau penyimpangan jamaah haji. Perangkat ini disediakan kepada setiap jemaah sebagai sarana untuk memungkinkan petugas melaksanakan pemantauan yang efisien terhadap pergerakan jamaah. Dilengkapi dengan teknologi GPS canggih, sensor suhu udara, dan pengukuran kelembaban, Moji tidak hanya menjamin keamanan jamaah, tetapi juga memberikan informasi yang berharga untuk pengelolaan optimal selama perjalanan haji. Dengan Moji, kita memasuki era baru dalam penyelenggaraan haji yang lebih terencana, aman, dan berfokus pada kebutuhan jamaah. Perangkat ini menggunakan konsep Internet of Things (IoT) dan dilengkapi dengan berbagai komponen canggih, termasuk:

- Papan Arduino yang handal
- Sensor DHT untuk pemantauan suhu dan kelembaban udara
- Modul GPS untuk pelacakan akurat lokasi
- Layar LCD yang informatif

Selain itu, Moji juga dibekali dengan baterai daya tahan seharian, sehingga memungkinkan operasional yang lancar tanpa khawatir kehabisan daya. Moji berperan sebagai alat yang memberikan informasi real-time kepada petugas dan jamaah, dengan tujuan meningkatkan pengawasan dan pengelolaan proses perjalanan haji secara efisien.

Dalam era di mana teknologi semakin berperan dalam berbagai aspek kehidupan, Moji menjadi contoh nyata bagaimana konsep IoT dan komponen teknologi modern dapat digunakan untuk meningkatkan kualitas, keamanan, dan pengalaman dalam menjalankan ibadah haji.

## Komponen Alat Moji terdiri dari beberapa komponen utama yang bekerja secara sinergis:

- **Papan Arduino**: Digunakan sebagai otak perangkat, mengendalikan berbagai sensor dan modul. 

- **Sensor DHT**: Memonitor suhu dan kelembaban udara di sekitar perangkat. 

- **Modul GPS**: Menggunakan GPS untuk pelacakan akurat lokasi perangkat. 

- **Layar LCD**: Menampilkan informasi penting kepada petugas dan jamaah.

## Jalur Kabel Jalur kabel pada Moji dirancang untuk koneksi yang efisien:

1. Hubungkan sensor DHT ke pin analog Arduino. 
   
   | Fungsi | Pin Arduino | Keterangan                               |
   | ------ | ----------- | ---------------------------------------- |
   | data   | A0          | Mengukur suhu udara di sekitar perangkat |
   | VCC    | VCC         | Potensial Positif                        |
   | GND    | GND         | Potensial Negatif                        |

2. Sambungkan modul GPS ke pin komunikasi serial Arduino. 
   
   | Fungsi | Pin Arduino | Keterangan        |
   | ------ | ----------- | ----------------- |
   | TX     | A1          | TX                |
   | RX     | A2          | RX                |
   | VCC    | VCC         | Potensial Positif |
   | GND    | GND         | Potensial Negatif |

3. Koneksikan layar LCD dengan pin yang ditentukan di papan Arduino.
   
   | Fungsi | Pin Arduino | Keterangan        |
   | ------ | ----------- | ----------------- |
   | SDA    | A4          | SDA               |
   | SCL    | A5          | SCL               |
   | VCC    | VCC         | Potensial Positif |
   | GND    | GND         | Potensial Negatif |
