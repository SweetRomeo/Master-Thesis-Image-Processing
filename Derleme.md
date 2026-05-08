# Literature Review Table

Bu tablo, yüksek lisans tezi kapsamında incelenen makaleleri sistemli şekilde sınıflandırmak için hazırlanmıştır.

## Tez Konusu

**Otonom araç görüntülerinde görüntü iyileştirme algoritmalarının pure Python ve hibrit Python-C++ mimarileri üzerinden performans karşılaştırması**

## Literatür Tarama Amaçları

- Otonom araçlarda görüntü iyileştirme problemlerini belirlemek
- Düşük ışık, sis, yağmur, kar ve gürültü gibi görüntü bozulmalarını incelemek
- Kullanılan görüntü iyileştirme algoritmalarını sınıflandırmak
- Performans ölçütlerini belirlemek
- Gerçek zamanlı çalışabilirlik açısından mevcut çalışmaları değerlendirmek
- Python, C++ ve hibrit mimari açısından literatürdeki boşluğu tespit etmek

---

# Literature Review Summary Table

| No | Makale Adı | Yazarlar | Yıl | Problem Alanı | Kullanılan Yöntem / Algoritma | Veri Seti | Kullanılan Metrikler | Gerçek Zamanlılık Değerlendirmesi | Tezime Katkısı | Eksik / Sınırlı Yön |
|---:|---|---|---:|---|---|---|---|---|---|---|
| 1 | A survey on image enhancement for Low-light images | Jiawei Guo, Jieming Ma, Ángel F. García-Fernández, Yungang Zhang, Haining Liang | 2023 | Low-light / Night Driving, General Image Enhancement | Gray level transformation, Histogram Equalization, CLAHE, Retinex, Machine Learning-based enhancement | Çeşitli low-light image datasets incelenmiş | MSE, NIQE, SSIM, PSNR vb. | Doğrudan gerçek zamanlı Python-C++ performans karşılaştırması yok; bazı yöntemler kalite açısından karşılaştırılmış | Düşük ışıklı görüntü iyileştirme yöntemlerini geleneksel ve makine öğrenmesi tabanlı olarak sınıflandırmak için ana kaynak olarak kullanılabilir | Otonom araçlara doğrudan odaklanmıyor; Python-C++ hibrit mimari ve FPS/latency karşılaştırması içermiyor |
| 2 |  |  |  | Fog / Haze |  |  |  | Var / Yok / Belirtilmemiş |  |  |
| 3 |  |  |  | Rain / Snow |  |  |  | Var / Yok / Belirtilmemiş |  |  |
| 4 |  |  |  | General Image Enhancement |  |  |  | Var / Yok / Belirtilmemiş |  |  |
| 5 |  |  |  | Real-Time Performance |  |  | FPS, Latency, CPU, RAM | Var / Yok / Belirtilmemiş |  |  |
| 6 |  |  |  | Python-C++ / OpenCV Performance |  |  | Execution Time, FPS | Var / Yok / Belirtilmemiş |  |  |
| 7 |  |  |  | Object Detection Support |  |  | mAP, Precision, Recall | Var / Yok / Belirtilmemiş |  |  |
| 8 |  |  |  | Lane Detection Support |  |  | Accuracy, IoU, FPS | Var / Yok / Belirtilmemiş |  |  |
| 9 |  |  |  | Image Quality Assessment |  |  | PSNR, SSIM, NIQE, BRISQUE | Var / Yok / Belirtilmemiş |  |  |
| 10 |  |  |  | Deep Learning-Based Enhancement |  |  |  | Var / Yok / Belirtilmemiş |  |  |

---

# Detailed Literature Notes

## Paper 1

### Makale Bilgisi

- **Makale Adı:**  
- **Yazarlar:**  
- **Yıl:**  
- **Yayın Yeri:**  
- **DOI / Link:**  

### Çalışmanın Amacı

Bu çalışma hangi problemi çözmeyi amaçlıyor?

Bu zamana kadar yapılmış olan çalışmalarda ağırlıklı olarak görüntü iyileştirme algoritmaları 
