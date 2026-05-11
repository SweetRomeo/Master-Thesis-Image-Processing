# Literature Review Table

Bu tablo, yüksek lisans tezi kapsamında incelenen makaleleri sistemli şekilde sınıflandırmak için hazırlanmıştır.

## Tez Konusu

**Otonom Araçlarda Düşük Işıkta gerçek zamanlı Görüntü İyileştirme Uygulaması**

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
| 6 | From Fidelity to Perceptual Quality: A Semi-Supervised Approach for Low-Light Image Enhancement | Wenhan Yang, Shiqi Wang, Yuming Fang, Yue Wang, Jiaying Liu | 2020 | Düşük Işıklı Görüntü İyileştirme (Sinyal Doğruluğu vs. Algısal Kalite) | Deep Recursive Band Network (DRBN) - Yarı denetimli öğrenme yaklaşımı. | Paired (LOL, MIT-Adobe FiveK) ve Unpaired veri setleri. | PSNR, SSIM, VIF, LPIPS, NIQE | Önerilen DRBN modeli hem eşleşmiş hem eşleşmemiş verilerle eğitilebilir; otonom sistemler için esnek bir eğitim yapısı sunar. | Hibrit (C++/Python) mimarilerde kullanılacak derin öğrenme modellerinde, sinyal doğruluğu ile görsel kalite arasındaki dengeyi kuran rekürsif bir yapı sunar. | Modelin "recursive" (tekrarlamalı) yapısı, otonom sürüşün gerektirdiği gerçek zamanlı (pure Python vs. C++) performans testlerinde yüksek hesaplama maliyeti yaratabilir. |
| 7 | Low-Light Image and Video Enhancement Using Deep Learning: A Survey | Chongyi Li, Chunle Guo, Linghao Han, Jun Jiang, Ming-Ming Cheng, Jinwei Gu, Chen Change Loy | 2022 | Düşük Işıklı Görüntü ve Video İyileştirme (Derin Öğrenme Araştırması) | Derin öğrenme tabanlı algoritmaların (ağ yapıları, kayıp fonksiyonları vb.) kapsamlı taksonomisi | Yeni bir mobil telefon düşük ışık görüntü/video veri seti ve halka açık veri setleri | Nitel, nicel değerlendirmeler ve karanlıkta yüz tespiti (face detection) performansı | Derin öğrenme modellerinin genel analizi yapılsa da, doğrudan Python/C++ donanım gecikmesi (latency) odaklı bir performans testi içermez. | Otonom araç kameraları için kullanılabilecek derin öğrenme algoritmalarının en kapsamlı (TPAMI) özetini sunar ve iyileştirmenin karanlıkta makine görmesi (nesne/yüz tespiti) görevlerine katkısını kanıtlar. | Makine görmesi üzerine testler olsa da otonom sürüşteki araç/yol tespitine veya C++/OpenCV hibrit performans optimizasyonuna doğrudan odaklanmaz. |
| 8 | Ultra-High-Definition Low-Light Image Enhancement: A Benchmark and Transformer-Based Method | Tao Wang, Kaihao Zhang, Tianrun Shen, Wenhan Luo, Bjorn Stenger, Tong Lu | 2023 | Ultra Yüksek Çözünürlüklü (UHD - 4K/8K) Düşük Işıklı Görüntü İyileştirme | Transformer tabanlı LLFormer (Eksen tabanlı çoklu-başlı öz-dikkat mekanizması) | UHD-LL (Yeni 4K/8K veri seti), LOL, MIT-Adobe FiveK | PSNR, SSIM, LPIPS | Lineer karmaşıklığı azaltarak yüksek çözünürlüklerde hesaplama yükünü optimize etmeyi hedefler; doğrudan FPS/ms analizi içermez. | Yüksek çözünürlüklü (4K/8K) otonom araç kameralarından gelen verilerin işlenmesinde, donanım kaynaklarını tüketmeyecek (düşük karmaşıklıklı) modern Transformer mimarilerinin tasarımı için referanstır. | Otonom sürüş ortamında gerçek zamanlı gecikme (latency/ms) testi veya C++/Python dil temelli performans kıyaslaması bulunmamaktadır. |
| 9 | A Survey of Deep Learning-Based Low-Light Image Enhancement | Zhen Tian, Peixin Qu, Jielin Li, Yukun Sun, Guohou Li, Zheng Liang, Weidong Zhang | 2023 | Düşük Işıklı Görüntü İyileştirme (Derin Öğrenme Derlemesi) | CNN tabanlı (Fiziksel model tabanlı ve tabansız) ve GAN tabanlı algoritmaların sistematik taksonomisi. | NPE, MEF, VV, SID, LOL, SCIE, ExDark, RELLISUR, LLIV-Phone. | Tam referanslı (PSNR, SSIM, MSE) ve referanssız (NIQE, Brenner/Tenengrad Gradient, Bilgi Entropisi) metrikler. | Modellerin genel analizi yapılsa da doğrudan FPS kıyaslaması sunmaz; ancak gerçek zamanlı işleme hızına ulaşılmasının gelecekteki temel araştırma yönü olduğunu açıkça vurgular. | Derin öğrenme algoritmalarının otonom araçlara uygulanmasında en büyük engellerden birinin "işlem hızı" (speed/efficiency) olduğunu belirterek, tezinizdeki hibrit performans optimizasyonu ihtiyacını teorik olarak doğrular. | Sadece derin öğrenme (CNN/GAN) yapılarına ve görsel kalite metriklerine odaklanmış olup, şerit/nesne tespiti gibi otonom sürüş görevlerindeki etkisine veya Python-C++ dil özelinde donanım kıyaslamalarına değinilmemiştir. |
| 10 | LightingNet: An Integrated Learning Method for Low-Light Image Enhancement | Shaoliang Yang, Dongming Zhou, Jinde Cao, Yanbu Guo | 2023 | Düşük Işıklı Görüntü İyileştirme (Gürültü, Renk Sapması, Detay Kaybı)  | Bütünleşik Öğrenme: Vision Transformer (ViT) tabanlı iyileştirme alt ağı ve Res2Net tabanlı tamamlayıcı CNN alt ağı | Referanslı: LOL, SICE. Referanssız: ExDARK, DICM, LIME, MEF, NPE. | PSNR, SSIM, MS-SSIM, UQI, VIF, SCC, SAM, BRISQUE, NIQE, Inference Time, YOLOv4 nesne tespiti | 1024x1024 çözünürlükte farklı algoritmalar için çıkarım süresi (saniye) analizi yapılmıştır (Örn: LightingNet 0.19s, Zero-DCE 0.04s). | Otonom araçlar için görüntü iyileştirmenin YOLOv4 nesne tespitine etkisini ve yüksek çözünürlükte gerçek zamanlı işleme potansiyelini kanıtlayarak tezdeki hibrit performans kıyaslamasına doğrudan ölçülebilir (FPS/saniye) bir veri sağlar. | Transformer mimarilerinin hesaplama yükü optimize edilmeye çalışılsa da, saf C++ vs Python dilleri arasındaki bellek ve donanım kullanım farklarına (CPU/RAM) değinilmemiş.
| 11 | Low-light image enhancement by deep learning network for improved illumination map | Manli Wang, Jiayue Li, Changsen Zhang  | 2023 | Düşük Işıklı Görüntü İyileştirme (Aydınlatma Haritası ve Gürültü Kontrolü)  | Retinex Teorisi + CNN: Üç alt modül (ayrıştırma, aydınlatma, yansıma). Aydınlatma modülünde **Derinlemesine Ayrılabilir Evrişim (DSC)** kullanımı. | LOL dataset  | PSNR, SSIM, LOE, NIQE  | Modeli basit ve etkili tutarak gürültüyü artırmadan iyileştirme yapmayı amaçlar; doğrudan FPS/ms karşılaştırması sunmaz. | Kullanılan **DSC (Depth-Separable Convolution)** tekniği, derin öğrenme modellerini hafifletmek için kritiktir. Hibrit (C++/Python) mimari tasarımında hesaplama yükünü azaltacak yöntemler için teknik referans sağlar. | Otonom sürüşe özgü nesne tespiti testleri veya gömülü donanım (Jetson vb.) üzerinde Python-C++ çalışma süresi (latency) kıyaslaması içermez. |
| 12 | R2RNet: Low-light image enhancement via Real-low to Real-normal Network | Jiang Hai, Zhu Xuan, Ren Yang, Yutong Hao, Fengzhu Zou, Fang Lin, Songchen Han | 2023 | Gerçek Dünya Düşük Işıklı Görüntü İyileştirme | Retinex tabanlı R2RNet: Decom-Net (ayrıştırma), Denoise-Net (gürültü giderme) ve Relight-Net (aydınlatma) | Gerçek dünya düşük/normal ışık görüntü çiftleri (Real-world pairs) | PSNR, SSIM vb. (Standart metrikler) | Mekansal ve frekans bilgisini birlikte kullanarak detayları koruyan dayanıklı (robust) yapı | Sentezlenmiş veriler yerine gerçek dünya verileriyle eğitilmesi ve frekans bilgisini kullanması, otonom araçlardaki detay koruma ihtiyacı için kritiktir. | Doğrudan otonom sürüş görevlerindeki (obje tespiti) etkisi veya Python-C++ dil temelli gecikme kıyaslaması sunmamaktadır. |
| 13 | Zero-Reference Deep Curve Estimation for Low-Light Image Enhancement | Chunle Guo, Chongyi Li, Jichang Guo, Chen Change Loy, Sam Kwong, Runmin Cong | 2020 | Referanssız (Zero-reference) İyileştirme | DCE-Net: Hafif bir ağ ile görüntüye özgü eğri tahmini | SICE (Eğitim), LIME, DICM, MEF, VV, NPE (Test) | PSNR, SSIM, MAE, User Study, PI, Yüz Tespiti | **Saniyede 500 Kare (500 FPS)** çıkarım hızı (640x480 görüntüler için GPU'da). | Otonom araçlar için hayati olan yüksek FPS değerlerini sağlayan en verimli modellerden biridir; hibrit mimari için temel benchmark adayıdır. | Çok düşük ışıklı (extremely low-light) sahnelerde sinyal doğruluğu, daha ağır modellere göre sınırlı kalabilir. |
| 13 | Zero-Reference Deep Curve Estimation for Low-Light Image Enhancement | Chunle Guo, Chongyi Li, Jichang Guo, Chen Change Loy, Junhui Hou, Sam Kwong, Runmin Cong | 2020 | Referanssız (Zero-reference) İyileştirme | DCE-Net: Hafif bir ağ ile görüntüye özgü eğri tahmini | SICE, LIME, DICM, MEF vb. | PSNR, SSIM, MAE, Yüz Tespiti | Saniyede 500 Kare (500 FPS) çıkarım hızı | Yüksek FPS değerlerini sağlayan en verimli benchmark adayıdır | Çok düşük ışıklı sahnelerde sinyal doğruluğu sınırlı kalabilir |
| 14 | Bridging Robustness and Efficiency: Real-Time Low-Light Enhancement via Attention U-Net GAN | [cite_start]Yash Thesia, Meera Suthar  | [cite_start]2026  | [cite_start]Gerçek Zamanlı Düşük Işıklı Görüntü İyileştirme (Difüzyon Gecikmesi vs CNN Düzleştirmesi)  | [cite_start]Attention U-Net GAN: Hafif U-Net omurgası ve Dikkat Kapıları (Attention Gates) içeren çekişmeli ağ  | [cite_start]SID veri seti  | [cite_start]LPIPS (0.112 skoru)  | [cite_start]Uç cihazlarda (edge-deployable) tek bir ileri geçişte (single forward pass) gerçek zamanlı çıkarım (real-time inference) sunar. | [cite_start]Otonom araçlardaki işlem hızını donanım üzerinde optimize etme hedefinizi doğrudan destekleyen en güncel (2026) gerçek zamanlı ağ mimarilerinden biridir. | [cite_start]C++ ve Python dilleri arasındaki bellek ve çalışma zamanı optimizasyonuna dair spesifik kodlama seviyesi metrikler içermez. |
| 15 | UMLE: Unsupervised Multi-discriminator Network for Low Light Enhancement | [cite_start]Yangyang Qu, Kai Chen, Chao Liu, Yongsheng Ou  | [cite_start]2021  | [cite_start]Otonom Sürüş İçin Gerçek Zamanlı Denetimsiz Görüntü İyileştirme  | [cite_start]Çoklu Ayrıştırıcılı (Multi-discriminator) Denetimsiz GAN: Renk, doku ve çoklu-ölçek ayrıştırıcıları ile özellik füzyonu  | [cite_start]Otonom sürüş senaryoları ve SLAM verileri  | [cite_start]Nitel, Nicel metrikler ve SLAM yerelleştirme (localization) başarısı  | [cite_start]Otonom sistemlerde kullanılmak üzere tasarlanmış gerçek zamanlı (real-time) denetimsiz bir GAN modelidir. | [cite_start]İyileştirilmiş düşük ışıklı görüntülerin, otonom araçlardaki SLAM (eşzamanlı yerelleştirme ve haritalama) performansını görünür şekilde artırdığını kanıtlar. | [cite_start]Kullanılan algoritmanın hibrit mimariler (C++/OpenCV vb.) üzerinden CPU/RAM kullanım optimizasyonları sunulmamıştır. |
| 16 | Vision-Based Autonomous Vehicle Systems Based on Deep Learning: A Systematic Literature Review | Monirul Islam Pavel, Siok Yee Tan, Azizi Abdullah | 2022 | Derin Öğrenme Tabanlı Görsel Otonom Araç Sistemleri (Literatür Taraması) | Sistematik Literatür Taraması (Systematic Literature Review) | Çeşitli otonom sürüş çalışmaları | - | Otonom araçların algılama ve karar verme mekanizmalarının karşılaştığı zorlukları derler. | Otonom araçlarda kamera ve görsel algı sistemlerinin önemini, çevresel faktörlerin (düşük ışık, hava koşulları) yarattığı zorlukları tezinizin giriş bölümünde geniş bir bağlamla sunmak için temel referanstır. | Doğrudan yeni bir düşük ışıklı görüntü iyileştirme algoritması veya performans optimizasyonu önermeyen genel bir derlemedir. |
| 17 | A Survey and New Perspective of Sensing in the Dark for Intelligent Transportation Systems | Yiting Wang, Boda Li, Zixiang Wei, Anima Rahman, Daniel Gummadi, Valentina Donzella | 2025 | Otonom Araçlar İçin Karanlıkta Algılama (DarkSensing) ve Sensör Füzyonu | Kamera, LiDAR, RADAR, termal ve olaya dayalı (event-based) sensörlerin incelemesi (Survey) | Çeşitli otonom sürüş veri setleri ve yaklaşımları | Algı ve güvenlik metrikleri üzerine genel inceleme | Sensörlerin işbirliğine dayalı çerçevelerini (cooperative frameworks) inceler ancak doğrudan gecikme (ms) ölçmez. | Otonom sürüşte "karanlıkta algılama" problemini tüm sensör modaliteleriyle ele alan 2025 tarihli en kapsamlı vizyon makalesidir. Tezin motivasyonunu desteklemek için zirve referanstır. | Yeni bir algoritma önermez veya doğrudan Python/C++ kod-seviyesi performans kıyaslaması sunmaz. |
| 18 | Edge Computing Driven Low-Light Image Dynamic Enhancement for Object Detection | Yirui Wu, Haifeng Guo, Chinmay Chakraborty, Mohammad R. Khosravi, Stefano Berretti, Shaohua Wan | 2023 | Uç Bilişim (Edge Computing) Destekli Düşük Işık İyileştirme ve Nesne Tespiti | Bulut (Cloud) ve Uç (Edge) işbirlikçi uçtan uca çerçeve: Bulutta iyileştirme, uç cihazda tespit | ExDARK (Exclusively Dark Dataset) vb. | Gerçek zamanlı yanıt süresi (response time) ve nesne tespit başarı metrikleri | Kısıtlı donanıma sahip uç cihazlarda (edge) derin öğrenmenin gerçek zamanlı yanıt (real-time response) hızını artırmayı hedefler. | Otonom araçlar gibi uç (edge) donanımların limitlerini aşmak için hesaplama yükünün nasıl dağıtılacağı/optimize edileceği konusunda güçlü bir sistem mimarisi perspektifi sağlar. | Modeli cihaz üzerinde (on-device) tek başına çalıştırmak yerine bulut bağlantısına bağımlıdır; otonom sürüşte kesintisiz internet varsayımı pratik bir risk taşır. |

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

## Paper 6

### Makale Bilgisi
- **Makale Adı:** From Fidelity to Perceptual Quality: A Semi-Supervised Approach for Low-Light Image Enhancement
- **Yazarlar:** Wenhan Yang, Shiqi Wang, Yuming Fang, Yue Wang, Jiaying Liu
- **Yıl:** 2020
- **Yayın Yeri:** CVPR 2020

### Çalışmanın Amacı
Düşük ışıkta yakalanan görüntülerdeki azalan görünürlük, yoğun gürültü ve renk kayması problemlerini çözmek için yarı denetimli (semi-supervised) bir öğrenme yaklaşımı önermektir. Önerilen Deep Recursive Band Network (DRBN) mimarisi, eşleşmiş verilerle sinyal doğruluğunu (fidelity) öğrenirken, eşleşmemiş verilerle algısal kaliteyi (perceptual quality) optimize etmek için çekişmeli öğrenme (adversarial learning) kullanır.

**Teze Katkısı:** Otonom araçlar için geliştirilecek hibrit sistemlerde, modelin kısıtlı etiketli veri ile eğitilebilmesi (semi-supervised) ve sinyal kalitesini korurken görsel anlamda (perceptual) da başarılı sonuçlar üretmesi açısından önemli bir teknik temel sağlar.

## Paper 7

### Makale Bilgisi
- **Makale Adı:** Low-Light Image and Video Enhancement Using Deep Learning: A Survey
- **Yazarlar:** Chongyi Li, Chunle Guo, Linghao Han, Jun Jiang, Ming-Ming Cheng, Jinwei Gu, Chen Change Loy
- **Yıl:** 2022
- **Yayın Yeri:** IEEE Transactions on Pattern Analysis and Machine Intelligence (TPAMI)
- **DOI / Link:** (Eklenecek)

### Çalışmanın Amacı
Düşük ışıklı görüntü ve video iyileştirme alanında derin öğrenme tabanlı yöntemlerin (ağ mimarileri, kayıp fonksiyonları, eğitim stratejileri) çok kapsamlı bir incelemesini (survey) sunmak. Çalışma, literatürü derlemekle kalmayıp yeni bir veri seti ve çevrimiçi bir platform sunarak algoritmaların genellenebilirliğini test etmektedir. Ayrıca algoritmaların karanlıkta yüz tespiti (face detection in the dark) gibi yüksek seviye makine görmesi görevlerindeki pratik başarılarını da doğrulamaktadır.

**Teze Katkısı:** Derin öğrenme tabanlı iyileştirme yöntemlerinin makine görmesi performansına etkisini kanıtlayan en üst düzey (TPAMI) referanslardan biridir. Geliştirilecek otonom sürüş iyileştirme algoritmalarının nesne/şerit tespitine nasıl pozitif etki edeceği savunulurken doğrudan atıf yapılabilecek teorik arka planı sağlar.

## Paper 8

### Makale Bilgisi
- **Makale Adı:** Ultra-High-Definition Low-Light Image Enhancement: A Benchmark and Transformer-Based Method
- **Yazarlar:** Tao Wang, Kaihao Zhang, Tianrun Shen, Wenhan Luo, Bjorn Stenger, Tong Lu
- **Yıl:** 2023
- **Yayın Yeri:** AAAI Conference on Artificial Intelligence (AAAI-23)
- **DOI / Link:** (Eklenecek)

### Çalışmanın Amacı
Gelişen optik sensörlerle birlikte artan 4K ve 8K (Ultra-High-Definition) yüksek çözünürlüklü görüntülerin düşük ışık altında iyileştirilmesi problemini çözmeyi amaçlamaktadır. Yüksek çözünürlüklü görüntülerin standart algoritmalarla işlenmesi devasa bir hesaplama yükü getirdiğinden, yazar ekibi lineer karmaşıklığı önemli ölçüde azaltan "LLFormer" adında Transformer tabanlı yeni bir yöntem önermiştir. Ayrıca bu alandaki boşluğu doldurmak için 4K ve 8K görüntülerden oluşan UHD-LL adlı devasa bir veri seti literatüre kazandırılmıştır.

**Teze Katkısı:** Otonom araçlarda 4K/8K gibi yüksek çözünürlüklü sensörlerin standart hale gelmeye başladığı günümüzde, saf Python veya C++ ile yazılacak hibrit mimarilerin yüksek çözünürlükte nasıl darboğazlar (bottleneck) yaşayacağını tartışmak ve hesaplama yükü hafifletilmiş (lightweight) Transformer alternatiflerini incelemek için çok güçlü bir kaynaktır.

## Paper 9

### Makale Bilgisi
- **Makale Adı:** A Survey of Deep Learning-Based Low-Light Image Enhancement
- **Yazarlar:** Zhen Tian, Peixin Qu, Jielin Li, Yukun Sun, Guohou Li, Zheng Liang, Weidong Zhang
- **Yıl:** 2023 
- **Yayın Yeri:** Sensors (MDPI) 
- **DOI / Link:** 10.3390/s23187763 

### Çalışmanın Amacı
Düşük ışıklı görüntü iyileştirme alanında son yıllarda geliştirilen derin öğrenme tabanlı (CNN ve GAN) algoritmaları sistemli bir şekilde sınıflandırmak, ağ mimarilerini, kullanılan veri setlerini (NPE, MEF, SID, LOL vb.) ve kalite değerlendirme metriklerini analiz etmektir. Literatürdeki yöntemlerin avantajlarını ve dezavantajlarını ortaya koyarak gelecekteki araştırma yönlerine ışık tutmayı hedefler.

**Teze Katkısı:** Bu derleme çalışması, derin öğrenme modellerinin başarısına rağmen işlem hızı ve verimliliğinin (speed and efficiency) artırılmasının pratik uygulamalar (özellikle gerçek zamanlı sistemler) için hala aşılması gereken en önemli sorunlardan biri olduğunu vurgular. [cite_start]Otonom araç kameralarından alınan görüntülerin işlenmesinde salt Python kullanmak yerine performans darboğazlarını aşmak için neden C++ veya hibrit sistemlere ihtiyaç duyduğunuzu literatüre (güncel 2023 tarihli bir makaleye) dayandırarak savunmanız için mükemmel bir teorik temel sağlar.

## Paper 10

### Makale Bilgisi
- **Makale Adı:** LightingNet: An Integrated Learning Method for Low-Light Image Enhancement
- **Yazarlar:** Shaoliang Yang, Dongming Zhou, Jinde Cao, Yanbu Guo
- **Yıl:** 2023
- **Yayın Yeri:** IEEE Transactions on Computational Imaging
- **DOI / Link:** 10.1109/TCI.2023.3240087

### Çalışmanın Amacı
Düşük ışıklı ortamlarda çekilen görüntülerde oluşan gürültü, renk sapması ve detay bozulması problemlerini çözmek amacıyla "LightingNet" adında bütünleşik bir öğrenme (integrated learning) yaklaşımı önermektir. Bu model, yerel üst düzey özellikleri öğrenmek için tam ölçekli bir Vision Transformer (ViT) alt ağı ve küresel özellikleri ince ayarlamak için transfer öğrenme (Res2Net) tabanlı tamamlayıcı bir CNN alt ağı kullanır.

## Paper 11

### Makale Bilgisi
- **Makale Adı:** Low-light image enhancement by deep learning network for improved illumination map 
- **Yazarlar:** Manli Wang, Jiayue Li, Changsen Zhang 
- **Yıl:** 2023 
- **Yayın Yeri:** Computer Vision and Image Understanding (Elsevier) 
- **DOI / Link:** (Eklenecek)

### Çalışmanın Amacı
Yetersiz aydınlatma koşullarında çekilen görüntülerin kalitesini artırırken, karanlık bölgelerin parlaklaştırılmasının gürültü kirliliğini (noise pollution) artırması sorununu çözmeyi amaçlar. Retinex teorisini temel alan model; ayrıştırma (decomposition), aydınlatma (illumination) ve yansıma (reflection) olmak üzere üç modülden oluşur. Aydınlatma modülünde kullanılan derinlemesine ayrılabilir evrişimler (DSC) sayesinde modelin hesaplama karmaşıklığı azaltılırken özellik çıkarımı iyileştirilir.

**Teze Katkısı:** Hibrit (C++/Python) mimarilerle geliştireceğin otonom araç görüntü iyileştirme sisteminde, derin öğrenme modellerinin işlem gücünü nasıl optimize edebileceğin konusunda teknik bir temel sağlar. Özellikle **DSC (Depth-Separable Convolution)** kullanımı, gömülü donanımlarda modelin hızlanması için başvurulan en önemli yöntemlerden biridir. Bu makale, seçeceğin veya optimize edeceğin algoritmaların donanım üzerindeki verimliliğini savunurken güçlü bir teknik referans olacaktır.

## Paper 12

### Makale Bilgisi
- **Makale Adı:** R2RNet: Low-light image enhancement via Real-low to Real-normal Network
- **Yazarlar:** Jiang Hai, Zhu Xuan, Ren Yang, Yutong Hao, Fengzhu Zou, Fang Lin, Songchen Han
- **Yıl:** 2023
- **Yayın Yeri:** Journal of Visual Communication and Image Representation (Elsevier)
- **DOI / Link:** 10.1016/j.jvcir.2022.103712

### Çalışmanın Amacı
Sentetik (yapay olarak karartılmış) görüntüler yerine gerçek dünya düşük/normal ışık görüntü çiftlerini kullanarak daha gerçekçi ve dayanıklı (robust) bir iyileştirme modeli (R2RNet) geliştirmeyi amaçlamaktadır. Model; ayrıştırma, gürültü giderme ve yeniden aydınlatma modülleri üzerinden hem mekansal bilgiyi (kontrast için) hem de frekans bilgisini (detayları korumak için) kullanır.

**Teze Katkısı:** Otonom sürüş senaryolarında yol işaretleri veya uzak nesneler gibi kritik detayların korunması hayati önem taşır. R2RNet'in **frekans bilgisini** işleme dahil ederek detayları koruma stratejisi ve gerçek dünya verilerine dayanması, geliştireceğiniz hibrit C++/Python sistemlerinde model doğruluğunu savunmak için teknik bir temel oluşturur.

## Paper 13

### Makale Bilgisi
- **Makale Adı:** Zero-Reference Deep Curve Estimation for Low-Light Image Enhancement
- **Yazarlar:** Chunle Guo, Chongyi Li, Jichang Guo, Chen Change Loy, Junhui Hou, Sam Kwong, Runmin Cong
- **Yıl:** 2020
- **Yayın Yeri:** CVPR 2020
- **DOI / Link:** (Eklenecek)

### Çalışmanın Amacı
Eşleşmiş (paired) veya eşleşmemiş (unpaired) referans görüntülere ihtiyaç duymadan, düşük ışıklı görüntüleri iyileştirmeyi amaçlayan **Zero-Reference** bir yöntem sunmaktır. Önerilen DCE-Net, her bir piksel için dinamik aralığı ayarlayan yüksek dereceli eğriler tahmin eder ve bu süreci referanssız kayıp fonksiyonları (spatial consistency, exposure control vb.) ile yönetir.

## Paper 14

### Makale Bilgisi
- [cite_start]**Makale Adı:** Bridging Robustness and Efficiency: Real-Time Low-Light Enhancement via Attention U-Net GAN 
- [cite_start]**Yazarlar:** Yash Thesia, Meera Suthar 
- [cite_start]**Yıl:** 2026 
- [cite_start]**Yayın Yeri:** arXiv (2601.06518v1) 

### Çalışmanın Amacı
[cite_start]Difüzyon modellerinin (Diffusion Models) sunduğu yüksek algısal kalite ile oluşturdukları 2-4 saniyelik kabul edilemez gecikme süresi (latency) ve geleneksel CNN'lerin hızına karşılık detayları aşırı düzleştirmesi (over-smoothing) arasındaki boşluğu kapatmayı amaçlamaktadır. [cite_start]Öncelikli hedef, uç cihazlarda (edge-deployable) kullanılmak üzere tek bir ileri geçişte (single forward pass) üretici model (generative) seviyesinde yüksek frekanslı detay geri kazanımı sağlayan hibrit bir Attention U-Net GAN mimarisi oluşturmaktır.

**Teze Katkısı:** Bu çalışma, donanım kapasitesi kısıtlı olabilen otonom araç platformlarında (Jetson Orin Nano vb.) algoritmaların "gerçek zamanlılık" (real-time) özelliğinin ne kadar kritik olduğunu 2026 yılının en güncel verileriyle kanıtlar. Hibrit sistem tasarımınızda model gecikmelerini C++ entegrasyonu ile neden optimize etmeniz gerektiğini savunurken doğrudan kullanabileceğiniz güçlü bir modern yaklaşımdır.

## Paper 15

### Makale Bilgisi
- **Makale Adı:** UMLE: Unsupervised Multi-discriminator Network for Low Light Enhancement 
- **Yazarlar:** Yangyang Qu, Kai Chen, Chao Liu, Yongsheng Ou 
- **Yıl:** 2021 
- **Yayın Yeri:** 2021 IEEE International Conference on Robotics and Automation (ICRA) 
- **DOI / Link:** 10.1109/ICRA48506.2021.9561051 

### Çalışmanın Amacı
Otonom sürüş senaryolarında düşük ışık koşullarının görme tabanlı uygulamalar üzerinde yarattığı ciddi sorunları çözmek için gerçek zamanlı, denetimsiz (unsupervised) bir Üretken Çekişmeli Ağ (GAN) geliştirmeyi hedefler. [cite_start]Mimaride; görüntüleri farklı açılardan değerlendirmek için çok ölçekli, doku ve renk odaklı birden fazla ayrıştırıcı (multi-discriminator) kullanılmış ve özellik füzyonunda piksel ile kanal dikkat mekanizmaları (attention module) birleştirilmiştir.

**Teze Katkısı:** Geliştirilen görüntü iyileştirme yöntemlerinin, otonom araçların çevreyi haritalaması ve kendi konumunu bulması (SLAM - Simultaneous Localization and Mapping) görevleri üzerindeki etkisini doğrudan kanıtlayan bir çalışmadır. İyileştirme algoritmalarının sadece görsel kaliteyi değil, otonom aracın karar alma ve yön bulma mekanizmalarını nasıl iyileştirdiğini anlatırken temel alınmalıdır.

## Paper 16

### Makale Bilgisi
- **Makale Adı:** Vision-Based Autonomous Vehicle Systems Based on Deep Learning: A Systematic Literature Review [cite: 16]
- **Yazarlar:** Monirul Islam Pavel, Siok Yee Tan, Azizi Abdullah [cite: 16]
- **Yıl:** 2022 [cite: 16]
- **Yayın Yeri:** Applied Sciences (MDPI) [cite: 16]
- **DOI / Link:** 10.3390/app12146831 [cite: 16]

### Çalışmanın Amacı
Son on yılda hızla gelişen otonom araç sistemlerinde (AVS) kullanılan derin öğrenme tabanlı görme/kamera (vision-based) sistemlerini sistematik bir şekilde taramayı ve derlemeyi (Systematic Literature Review) amaçlamaktadır[cite: 16]. [cite_start]Otonom araçların algılama ve karar verme süreçlerindeki mevcut durumları, yapay zeka entegrasyonunu ve bu sistemlerin sahada karşılaştığı çeşitli zorlukları bir araya getirir[cite: 16].

**Teze Katkısı:** Tezinizin "Giriş" (Introduction) ve "Problem Tanımı" (Problem Definition) bölümlerini yazarken, otonom araçların çevresel koşullardan (özellikle düşük ışık) neden bu kadar fazla etkilendiğini açıklamak ve görüntü iyileştirmenin bu sistemlerdeki geniş önemini okuyucuya aktarmak için harika bir çerçeve (framework) makalesidir.

**Teze Katkısı:** Otonom araçların anlık tepki verebilmesi için görüntü işleme hattının çok düşük gecikme süresine sahip olması gerekir. Zero-DCE'nin sunduğu **500 FPS** gibi olağanüstü işlem hızı, tezinizde C++ ve Python hibrit mimarisinin hız performansını kıyaslarken kullanacağınız en verimli ve modern referans noktalarından birini oluşturur.

## Paper 17

### Makale Bilgisi
- **Makale Adı:** A Survey and New Perspective of Sensing in the Dark for Intelligent Transportation Systems
- **Yazarlar:** Yiting Wang, Boda Li, Zixiang Wei, Anima Rahman, Daniel Gummadi, Haonan Zhao, Valentina Donzella
- **Yıl:** 2025
- **Yayın Yeri:** IEEE Transactions on Intelligent Transportation Systems
- **DOI / Link:** (Eklenecek)

### Çalışmanın Amacı
Karanlık veya düşük aydınlatmalı ortamların Akıllı Ulaşım Sistemleri (ITS) üzerinde algı, karar verme ve güvenlik açısından yarattığı zorlukları sistematik olarak incelemeyi amaçlamaktadır. Makale, otonom araçların karanlık koşullar altında gezinmesini sağlamak için kullanılan algılama teknolojileri ve algoritmalarını ifade eden **"DarkSensing" (Karanlıkta Algılama)** konseptini tanıtır. Çalışma sadece kameralara odaklanmakla kalmaz; LiDAR, RADAR, termal sensörler ve olaya dayalı (event-based) sensörlerin karanlıktaki donanım kısıtlarını, veri iyileştirme algoritmalarını ve işbirlikçi algılama (collaborative sensing) çerçevelerini de kapsamlı biçimde değerlendirir.

**Teze Katkısı:** Tezinizin vizyonunu ve teorik çerçevesini çok güçlü bir şekilde destekler. Yalnızca kameranın (vision) değil, otonom araçtaki diğer sensörlerin de düşük ışıkta ciddi kısıtlamalar yaşadığını ve kamera verisinin derin öğrenme / hibrit mimarilerle iyileştirilmesinin (low-light enhancement) tüm sistem güvenliği (sensor fusion) için ne kadar hayati olduğunu **2025 yılının en taze literatürüyle** ortaya koyar.

## Paper 18

### Makale Bilgisi
- **Makale Adı:** Edge Computing Driven Low-Light Image Dynamic Enhancement for Object Detection
- **Yazarlar:** Yirui Wu, Haifeng Guo, Chinmay Chakraborty, Mohammad R. Khosravi, Stefano Berretti, Shaohua Wan
- **Yıl:** 2023
- **Yayın Yeri:** IEEE Transactions on Network Science and Engineering
- **DOI / Link:** (Eklenecek)

### Çalışmanın Amacı
Mobil multimedya verilerinin hızla artmasıyla birlikte, ağır derin öğrenme modellerini "gerçek zamanlı" (real-time response) çalıştırabilmek için **Uç Bilişim (Edge Computing)** mimarisine dayanan uçtan uca bir çerçeve önermektedir. Bu yaklaşımda; ağır hesaplama gerektiren düşük ışıklı görüntü iyileştirme işlemi (enhancement subnetwork) bulut sunucularda (cloud) paralel olarak yürütülürken, nesne tespiti görevi uça (edge device) taşınarak yanıt süresinin optimize edilmesi hedeflenmiştir.

**Teze Katkısı:** Otonom araçlar tipik birer "Uç Cihazdır" (Edge Device). Teziniz, otonom araçlardaki donanım kısıtlarını aşmak ve gerçek zamanlılığı sağlamak için yazılım düzeyinde (Python yerine C++ kullanımı vb.) bir hibrit optimizasyon öneriyor. Bu makale ise aynı problemi "uç-bulut mimarisi" yaklaşımıyla ele almaktadır. Literatür taramanızda *"Donanım darboğazını aşmak için bulut bilişim önerilse de, otonom araçlardaki bağlantı gecikmeleri risk yarattığı için algoritmaların cihaz üzerinde (on-device) C++ gibi düşük seviyeli dillerle optimize edilmesi daha güvenli bir yaklaşımdır"* argümanını savunurken harika bir referans olacaktır.
