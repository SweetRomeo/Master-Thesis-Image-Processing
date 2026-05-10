# Literature Review Summary Table

| No | Makale Adı | Yazarlar | Yıl | Problem Alanı | Kullanılan Yöntem / Algoritma | Veri Seti | Kullanılan Metrikler | Gerçek Zamanlılık Değerlendirmesi | Tezime Katkısı | Eksik / Sınırlı Yön |
|---:|---|---|---:|---|---|---|---|---|---|---|
| 1 | A survey on image enhancement for Low-light images | Jiawei Guo, Jieming Ma, Ángel F. García-Fernández, Yungang Zhang, Haining Liang | 2023 | Low-light / Night Driving, General Image Enhancement | Gray level transformation, Histogram Equalization, CLAHE, Retinex, Machine Learning-based enhancement | Çeşitli low-light image datasets incelenmiş | MSE, NIQE, SSIM, PSNR vb. | Doğrudan gerçek zamanlı Python-C++ performans karşılaştırması yok; bazı yöntemler kalite açısından karşılaştırılmış | Düşük ışıklı görüntü iyileştirme yöntemlerini geleneksel ve makine öğrenmesi tabanlı olarak sınıflandırmak için ana kaynak olarak kullanılabilir | Otonom araçlara doğrudan odaklanmıyor; Python-C++ hibrit mimari ve FPS/latency karşılaştırması içermiyor |
| 2 | Low-Light Image Enhancement: A Comparative Review and Prospects | Wonjun Kim | 2022 | Low-light Image Enhancement (Geleneksel ve Derin Öğrenme Kıyaslaması) | İstatistiksel, Ayrıştırma (Decomposition), Referanslı ve Referanssız (Sıfır-Veri) Derin Öğrenme tabanlı 13 algoritma (LIME, Zero-DCE, HDRNet, vb.) | NASA Retinex, HDR, NPE, LIME, MIT-Adobe FiveK, SICE, LOL | PSNR, SSIM, NIQE, BTMQI, NIQMC | Doğrudan FPS/ms ölçümü yok ancak mobil cihazlar ve donanıma dağıtım (deployability) için hafif (lightweight) algoritma ihtiyacı tartışılmış | Geliştirilecek hibrit C++ ve Python mimarisinde kullanılacak algoritmaların (özellikle referanssız modellerin) donanım üzerindeki işlem yükü ve dağıtılabilirlik kısıtlarını anlamak için temel referanstır | C++ veya Python özelinde dil/performans kıyaslaması sunmuyor; otonom sürüşe özgü veri setleri (BBD100K vb.) üzerinde gecikme (latency) testleri içermiyor |
| 3 |  |  |  | Rain / Snow |  |  |  | Var / Yok / Belirtilmemiş |  |  |
| 4 |  |  |  | General Image Enhancement |  |  |  | Var / Yok / Belirtilmemiş |  |  |
| 5 |  |  |  | Real-Time Performance |  |  | FPS, Latency, CPU, RAM | Var / Yok / Belirtilmemiş |  |  |
| 6 |  |  |  | Python-C++ / OpenCV Performance |  |  | Execution Time, FPS | Var / Yok / Belirtilmemiş |  |  |
| 7 |  |  |  | Object Detection Support |  |  | mAP, Precision, Recall | Var / Yok / Belirtilmemiş |  |  |
| 8 |  |  |  | Lane Detection Support |  |  | Accuracy, IoU, FPS | Var / Yok / Belirtilmemiş |  |  |
| 9 |  |  |  | Image Quality Assessment |  |  | PSNR, SSIM, NIQE, BRISQUE | Var / Yok / Belirtilmemiş |  |  |
| 10 |  |  |  | Deep Learning-Based Enhancement |  |  |  | Var / Yok / Belirtilmemiş |  |  |
