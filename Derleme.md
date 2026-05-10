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
| 2 | Low-Light Image Enhancement: A Comparative Review and Prospects | Wonjun Kim | 2022 | Low-light Image Enhancement (Geleneksel ve Derin Öğrenme Kıyaslaması) | İstatistiksel, Ayrıştırma (Decomposition), Referanslı ve Referanssız (Sıfır-Veri) Derin Öğrenme tabanlı 13 algoritma (LIME, Zero-DCE, HDRNet, vb.) | NASA Retinex, HDR, NPE, LIME, MIT-Adobe FiveK, SICE, LOL | PSNR, SSIM, NIQE, BTMQI, NIQMC | Doğrudan FPS/ms ölçümü yok ancak mobil cihazlar ve donanıma dağıtım (deployability) için hafif (lightweight) algoritma ihtiyacı tartışılmış | Geliştirilecek hibrit C++ ve Python mimarisinde kullanılacak algoritmaların (özellikle referanssız modellerin) donanım üzerindeki işlem yükü ve dağıtılabilirlik kısıtlarını anlamak için temel referanstır | C++ veya Python özelinde dil/performans kıyaslaması sunmuyor; otonom sürüşe özgü veri setleri (BBD100K vb.) üzerinde gecikme (latency) testleri içermiyor |
| 3 | Perceptual Quality Assessment of Low-light Image Enhancement | Guangtao Zhai, Wei Sun, Xiongkuo Min, Jiantao Zhou | 2021 | Düşük Işıklı Görüntü İyileştirmede Algısal Kalite Değerlendirmesi (IQA) | Tam referanslı (FR) LIEQA (Low-light Image Enhancement Quality Assessment) endeksi; parlaklık, renk sunumu, LBP ile gürültü ve yapı koruma ölçümü yapar. | 10 farklı algoritma ile üretilmiş 1000 görüntüden oluşan LIEQ veri seti. | SRCC, KRCC, PLCC, RMSE (IQA performansını ölçmek için); Karşılaştırma için PSNR, SSIM, NIQE vb. | Modellerin işlem karmaşıklığı saniye/görüntü cinsinden test edilmiş; LIEQA'nın 512x512 görüntüde CPU üzerinde ~0.4950 saniye sürdüğü belirtilmiştir. | Otonom araçlar için geliştirilecek hibrit algoritmaların çıktı kalitesini (offline olarak) doğrularken standart PSNR/SSIM metriklerinin neden yetersiz kalacağını açıklar ve alternatif bir doğrulama yöntemi sunar. | Tam referanslı (FR) bir yaklaşım olduğu için otonom sürüş esnasında (çevrimiçi/online) anlık kalite ölçümünde kullanılamaz (gerçek zamanlı mükemmel referans görüntü bulunamaz). |
| 4 | Benchmarking Low-Light Image Enhancement and Beyond | Jiaying Liu, Dejia Xu, Wenhan Yang, Minhao Fan, Haofeng Huang | 2021 | Düşük Işıklı Görüntü İyileştirme ve Yüksek Seviyeli Makine Görmesi (Yüz Tespiti) Performansı | Ortak İyileştirme ve Tespit (Joint Enhancement and Detection) mimarisi ile kapsamlı Benchmark değerlendirmesi | VE-LOL (Vision Enhancement in the LOw-Light condition - düşük ışık eşleşmeli ve yüz tespit etiketli) | Tam Referanslı (FR), Referanssız (NR), Semantik Benzerlik ve Yüz Tespit Metrikleri | Doğrudan FPS/ms veya Python/C++ performans kıyaslaması odaklı değildir; daha çok tespit görevindeki başarı oranına odaklanır. | İyileştirme algoritmalarının sadece görsel kaliteyi değil, bilgisayarlı görü görevlerini (otonom araçlardaki nesne/şerit tespiti gibi) nasıl etkilediğini anlamak için temel bir metodoloji sunar. | Otonom sürüş (araç/yol tespiti) yerine yüz tespitine odaklanmıştır. Hibrit mimariler (C++/Python) üzerinden gerçek zamanlı gecikme (latency) optimizasyonu içermez. |
| 5 | Gap-Closing Matters: Perceptual Quality Evaluation and Optimization of Low-Light Image Enhancement | Baoliang Chen, Lingyu Zhu, Hanwei Zhu, Wenhan Yang, Linqi Song, Shiqi Wang | 2024 | Düşük Işıklı Görüntü İyileştirmede Algısal Kalite Değerlendirmesi ve Optimizasyonu | SQUARE-LOL veri seti ile oluşturulan objektif kalite ölçütünün, görüntü iyileştirme algoritmasının optimizasyon döngüsüne (quality-guided framework) doğrudan entegrasyonu | SQUARE-LOL (Subjective Quality Assessment of REconstructed LOw-Light Images) | Subjektif kullanıcı değerlendirmeleri ve önerilen yeni algısal objektif kalite ölçütü | FPS, gecikme (latency) veya donanım kullanımına (CPU/RAM) yönelik doğrudan bir analiz içermez; odak noktası algısal kalitedir. | Geliştirilecek otonom araç iyileştirme algoritmalarının çıktı kalitesini standart metriklerin ötesinde, insan algısına ve pratik kullanıma en uygun şekilde nasıl değerlendirileceği konusunda çok güncel (2024) bir kalite ölçüm referansı sunar. | Donanım üzerinde çalışma süresi (ms), gömülü sistem performansı veya C++/Python mimari kıyaslaması gibi hesaplama karmaşıklığına dair performans analizleri içermez. |
| 6 |  |  |  | Real-Time Performance |  |  | FPS, Latency, CPU, RAM | Var / Yok / Belirtilmemiş |  |  |
| 7 |  |  |  | Python-C++ / OpenCV Performance |  |  | Execution Time, FPS | Var / Yok / Belirtilmemiş |  |  |
| 8 |  |  |  | Object Detection Support |  |  | mAP, Precision, Recall | Var / Yok / Belirtilmemiş |  |  |
| 9 |  |  |  | Lane Detection Support |  |  | Accuracy, IoU, FPS | Var / Yok / Belirtilmemiş |  |  |

---

# Detailed Literature Notes

## Paper 1

### Makale Bilgisi

- **Makale Adı:** A survey on image enhancement for Low-light images
- **Yazarlar:** Jiawei Guo, Jieming Ma, Ángel F. García-Fernández, Yungang Zhang, Haining Liang
- **Yıl:** 2023
- **Yayın Yeri:** (Dergi/Konferans eklenecek)
- **DOI / Link:** (Link eklenecek)

### Çalışmanın Amacı

Düşük ışıklı görüntü iyileştirme yöntemlerini geleneksel ve makine öğrenmesi tabanlı olarak sınıflandırmak ve kalitelerini standart metrikler ile kıyaslamaktır.


## Paper 2

### Makale Bilgisi

- **Makale Adı:** Low-Light Image Enhancement: A Comparative Review and Prospects
- **Yazarlar:** Wonjun Kim
- **Yıl:** 2022
- **Yayın Yeri:** IEEE Access
- **DOI / Link:** 10.1109/ACCESS.2022.3197629

### Çalışmanın Amacı

Düşük ışıklı ortamlarda çalışan görüntü iyileştirme algoritmalarının kapsamlı bir taksonomisini çıkararak, geleneksel yöntemler ile modern derin öğrenme tabanlı algoritmaları tarafsız bir şekilde kıyaslamayı amaçlamaktadır. Otonom sistemler ve gömülü platformlarda karşılaşılan işlem yükü, öğrenme önyargısı (learning bias) ve donanıma dağıtılabilirlik (deployability) gibi pratik engelleri ortaya koymayı hedefler.


## Paper 3

### Makale Bilgisi

- **Makale Adı:** Perceptual Quality Assessment of Low-light Image Enhancement
- **Yazarlar:** Guangtao Zhai, Wei Sun, Xiongkuo Min, Jiantao Zhou
- **Yıl:** 2021
- **Yayın Yeri:** ACM Transactions on Multimedia Computing, Communications, and Applications
- **DOI / Link:** 10.1145/3457905

### Çalışmanın Amacı

Düşük ışıklı görüntü iyileştirme algoritmalarının çıktılarının nesnel kalitesini (IQA) doğru bir şekilde değerlendirme problemini çözmeyi amaçlamaktadır. Geleneksel görüntü kalite metriklerinin (PSNR, SSIM vb.) düşük ışık iyileştirmede oluşan karmaşık bozulmaları (renk kayması, yapısal hasar, aşırı aydınlatma, gürültü) ölçmede yetersiz kaldığını göstererek, dört temel bileşeni (parlaklık artışı, renk sunumu, gürültü seviyesi, yapısal bütünlük) birleştiren tam referanslı (FR) yeni bir "LIEQA" metriği önermektedir.


## Paper 4

### Makale Bilgisi

- **Makale Adı:** Benchmarking Low-Light Image Enhancement and Beyond
- **Yazarlar:** Jiaying Liu, Dejia Xu, Wenhan Yang, Minhao Fan, Haofeng Huang
- **Yıl:** 2021
- **Yayın Yeri:** International Journal of Computer Vision (IJCV)
- **DOI / Link:** 10.1007/s11263-020-01418-8

### Çalışmanın Amacı

Düşük ışıklı görüntü iyileştirme algoritmalarının performansını yalnızca "düşük seviyeli" görsel kalite (insan algısı) açısından değil, aynı zamanda yüz tespiti gibi "yüksek seviyeli" bilgisayarlı görü görevleri üzerindeki etkileri açısından da değerlendirmeyi amaçlamaktadır. Bu kapsamda, hem görüntü kalitesi hem de makine görmesi görevlerini destekleyen VE-LOL (Vision Enhancement in the LOw-Light condition) adlı büyük ölçekli bir veri seti önerilmiş ve iyileştirme modülü ile tespit modülünün ortaklaşa (joint) çalıştığı bir mimari sunulmuştur. Geliştirilecek sistemlerin nesne tespit başarılarına etkisini ölçmek için metodolojik bir temel oluşturur.

## Paper 5

### Makale Bilgisi

- [cite_start]**Makale Adı:** Gap-Closing Matters: Perceptual Quality Evaluation and Optimization of Low-Light Image Enhancement [cite: 5]
- [cite_start]**Yazarlar:** Baoliang Chen, Lingyu Zhu, Hanwei Zhu, Wenhan Yang, Linqi Song, Shiqi Wang [cite: 5]
- [cite_start]**Yıl:** 2024 [cite: 5]
- [cite_start]**Yayın Yeri:** IEEE Transactions on Multimedia [cite: 5]
- **DOI / Link:** (DOI eklenecek)

### Çalışmanın Amacı

Bu çalışma hangi problemi çözmeyi amaçlıyor?

Düşük ışıklı görüntü iyileştirme algoritmalarının tasarımı ile son kullanıcıların algıladığı görsel kalite arasındaki "boşluğu (gap)" kapatmayı amaçlamaktadır. Literatürde kalite değerlendirmesine yeterince odaklanılmadığını savunan yazarlar, SQUARE-LOL (Subjective Quality Assessment of REconstructed LOw-Light Images) adında geniş çaplı yeni bir veri seti oluşturmuşlardır[cite: 5]. [cite_start]Sadece kaliteyi ölçmekle kalmayıp, geliştirdikleri objektif kalite ölçütünü iyileştirme algoritmalarının optimizasyon sürecine (loss function vb. olarak) dahil ederek daha yüksek algısal kaliteye sahip çıktılar üretmeyi başarmışlardır.

**Teze Katkısı:** Hibrit (C++/Python) mimarilerle geliştirilecek görüntü iyileştirme modellerinin başarısını kanıtlarken, yalnızca işlem süresi (FPS) olarak değil, "çıktı kalitesi" olarak da literatürün kabul ettiği en güncel (2024) algısal kalite değerlendirme yaklaşımlarına atıf yapmanızı sağlayacaktır.
