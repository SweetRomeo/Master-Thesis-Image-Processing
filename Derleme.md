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
| 19 | Real-time fast low-light vision enhancement for driver during driving at night | Gouranga Mandal, Diptendu Bhattacharya, Parthasarathi De | 2022 | Gece Sürüşü ve Gerçek Zamanlı Görüntü İyileştirme | Modifiye edilmiş parlak kanal önceliği (bright channel prior) ve adaptif gama düzeltmesi (Geleneksel Yöntem) | Gerçek zamanlı gece sürüş video kayıtları | İşlem/hesaplama süresi ve görsel nitelik | Derin öğrenme içermeyen hafif yapısı sayesinde çok hızlı ve gerçek zamanlı çalışacak şekilde tasarlanmıştır. | Python/C++ OpenCV karşılaştırmalarınızda kullanabileceğiniz, donanımı hiç yormayan en temel (baseline) algoritmalarından birini sunar. | Derin öğrenme içermediği için aşırı karmaşık aydınlatma ve yoğun gürültülü senaryolarda sinyal doğruluğu/kalitesi CNN modellerinden düşük kalabilir. |
| 20 | Performance Evaluation of Computer Vision Algorithms in a Programmable Logic Controller: An Industrial Case Study | Rodrigo Vieira, Dino Silva, Eliseu Ribeiro, Luís Perdigoto, Paulo Jorge Coelho | 2023 | Endüstriyel Görüntü İşleme ve PLC Performans Analizi | Python ve OpenCV kullanılarak standart algoritmalar (Canny, Blur, Threshold vb.) | Endüstriyel vaka çalışması (metal pul sayma) | İşlem süresi (Execution time/Latency) | PLC'nin görüntü işleme performansı bir PC ile kıyaslanarak gerçek zamanlılık kapasitesi değerlendirilmiştir. | Python'un Linux tabanlı bir kontrol cihazı (PLC) üzerindeki performans sınırlarını kanıtlar. Saf Python/OpenCV kullanımının kısıtlı donanımlardaki gecikme değerlerini savunmak için kritiktir. | Otonom araçlar yerine endüstriyel otomasyona odaklıdır. Aynı donanım üzerinde C++ ve Python arasında doğrudan bir karşılaştırma içermemektedir. |
| 21 | Low Latency Deep Learning Inference Model for Distributed Intelligent IoT Edge Clusters | Soumyalatha Naveen, Manjunath R. Kounte, Mohammed Riyaz Ahmed | 2021 | Dağıtık IoT Uç (Edge) Kümelerinde Düşük Gecikmeli Derin Öğrenme | Sınırlı kaynaklara sahip uç cihazlar için optimize edilmiş derin öğrenme çıkarım modeli | Genel IoT ve uç bilişim senaryoları | Gecikme (Latency), yanıt süresi, bellek ve güç tüketimi | Uç bilişimde gerçek zamanlı uygulamalar için uçtan uca gecikmenin minimize edilmesi hedeflenmiştir. | Otonom araçları birer "Uç Cihaz (Edge Device)" olarak konumlandırarak, donanım kısıtları altında derin öğrenme modellerinin gecikme (latency) sorunlarını doğrular. | Görüntü iyileştirme algoritması önermez veya spesifik bir Python-C++ dil kıyaslaması sunmaz. |
| 22 | Performance Evaluation of Deep Learning Compilers for Edge Inference | Gaurav Verma, Yashi Gupta, Abid M. Malik, Barbara Chapman | 2021 | Uç Cihazlarda (Edge Devices) Derin Öğrenme Çıkarım (Inference) Performans Optimizasyonu | Derin öğrenme derleyicilerinin (TensorRT, TFLite, TVM) Raspberry Pi ve Jetson donanımlarında kıyaslanması | ResNet, MobileNet, YOLO gibi standart donanım benchmark modelleri | Çıkarım süresi (Inference time/Latency), bellek kullanımı, güç tüketimi | Uç cihazlarda gerçek zamanlı çıkarım (inference) için gecikmeyi (latency) donanım seviyesinde en aza indirme yöntemlerine odaklanmıştır. | Otonom araç (uç cihaz) donanımlarında saf Python modellerinin yavaş kalabileceğini; TensorRT (C++ tabanlı alt seviye optimizasyon) gibi araçlarla hibrit yapılara geçişin hız için zorunlu olduğunu teorik olarak kanıtlar. | Düşük ışıklı görüntü iyileştirmeye özgü bir algoritma önermez; derin öğrenme modellerinin derleyici/donanım performansına (framework optimization) odaklanır. |
| 23 | Lightweight Low-Light Image Enhancement Techniques for Edge Devices | Ebin J Alapatt, Pankaj Kumar G, Narayanan V Eswar, Aman K Shihab, S Krishna Bhatt, Sreevishnu Damodaran, A A Aswathy | 2025 | Uç Cihazlar (Edge Devices) İçin Hafif Görüntü İyileştirme | Geleneksel (Gamma, HE, Retinex) ve Derin Öğrenme yöntemlerinin donanım kısıtlarına göre incelenmesi | Çeşitli genel literatür veri setleri üzerinden derleme | Hesaplama karmaşıklığı, uç cihaz uyumluluğu | Otonom navigasyon gibi uç sistemlerde gerçek zamanlı çalışabilen hafif algoritmaların gerekliliği vurgulanmıştır. | Otonom araçların kısıtlı donanımlarında (edge) işlem süresini optimize etme motivasyonunuzu 2025 tarihli "hafif algoritma" perspektifiyle teorik olarak destekler. | Doğrudan yeni bir C++ veya Python optimizasyon kod mimarisi sunmaz; mevcut algoritmaların durumunu özetleyen bir derlemedir. |
| 24 | Lightweight object detection in low light: Pixel-wise depth refinement and TensorRT optimization | K. Vinoth, Sasikumar P | 2024 | Düşük Işıklı Görüntülerde Hafif Nesne Tespiti ve Çıkarım (Inference) Hızı Optimizasyonu | Piksel bazlı derinlik tahmini (Pixel-wise depth refinement) ve TensorRT ile optimize edilmiş YOLOv8 | Genel düşük ışıklı nesne tespiti verileri | Çıkarım hızı (Inference speed), nesne tespit hassasiyeti (precision), hesaplama karmaşıklığı, bellek izi (memory footprint) | Kaynakları kısıtlı cihazlarda TensorRT kullanımıyla modelin bellek ve işlem yükü azaltılarak daha hızlı çıkarım (gerçek zamanlı performans) elde edilmiştir. | Python tabanlı YOLOv8 gibi ağır modellerin uç cihazlarda çalışabilmesi için TensorRT (C++ tabanlı hızlandırma) kullanımının gecikmeyi nasıl düşürdüğünü kanıtlayan, tam tezinizin "hibrit mimari ve hız" argümanına uyan 2024 tarihli mükemmel bir referanstır. | Görüntü iyileştirme algoritmasından ziyade nesne tespiti ve TensorRT optimizasyonuna odaklanır; salt Python vs yerel OpenCV C++ kıyaslaması yerine derleyici optimizasyonuna eğilir. |
| 25 | A Review of Recent Hardware and Software Advances in GPU-Accelerated Edge-Computing Single-Board Computers (SBCs) for Computer Vision | Umair Iqbal, Tim Davies, Pascal Perez | 2024 | GPU Hızlandırmalı Uç Cihazlarda (SBC) Bilgisayarlı Görü ve Donanım/Yazılım Optimizasyonu | NVIDIA Jetson, Raspberry Pi vb. uç cihazların (SBC) donanım mimarileri ve yazılım hızlandırıcılarının sistematik incelemesi | Endüstriyel ve otonom sistem vaka çalışmaları (Derleme) | Çıkarım hızı (Inference speed), güç tüketimi, bellek kullanımı, TFLOPS | Uç cihazlarda otonom sistemler için gerçek zamanlı bilgisayarlı görü (real-time CV) kapasiteleri incelenmiştir. | Otonom araçların kalbi olan SBC cihazlarının (örn. Jetson serisi) donanım kapasitelerini ve Python'dan C++'a (TensorRT, OpenVINO) geçişin zorunluluğunu mimari açıdan kanıtlar. | Doğrudan düşük ışık iyileştirme için yeni bir algoritma önermez; genel donanım ve framework incelemesidir. |
| 26 | Learning Optimized Low-Light Image Enhancement for Edge Vision Tasks | SMA Sharif, Azamat Myrzabekov, Nodirkhuja Khujaev, Roman Tsoy, Seongwan Kim, Jaeho Lee | 2024 | Uç Görüş Görevleri (Edge Vision) İçin Optimize Edilmiş Düşük Işık İyileştirme | Hafif (Lightweight) derin ağ ve INT8 Eğitim Sonrası Kuantizasyon (Post-training Quantization) | Çeşitli düşük ışık veri setleri ve nesne tespiti verileri | FPS (199 FPS), Çıkarım süresi, görsel kalite metrikleri | Düşük güçlü bir uç cihazda 199 FPS gibi çok yüksek bir gerçek zamanlılık hızına ulaşılmıştır. | Tezinizdeki uç cihaz entegrasyonu hedeflerini INT8 kuantizasyonu ile hızlandırma perspektifinden destekleyen mükemmel bir CVPR kaynağıdır. | Sadece model kuantizasyonuna (INT8) odaklanır, salt bir OpenCV/C++ donanım seviyesi dil kıyaslaması sunmaz. |
| 27 | Generic programming in modern C++ for Image Processing | Michaël Roynard | 2022 | C++ ile Görüntü İşleme, Jenerik Programlama ve Python-C++ Entegrasyon Performansı | Modern C++ (statik/dinamik çok biçimlilik, type erasure) ve Python binding (pybind11 vb.) performans testleri | Benchmarking için skimage.data.camera vb. standart görüntüler | Çalışma zamanı (Execution time / Benchmarking - sec) | C++'ın statik ve dinamik çağrıları ile Python üzerinden çağrılmasının (binding) mikro saniye seviyesindeki gecikme farkları incelenmiştir. | Otonom araçlarda görüntü iyileştirme algoritmalarını C++ ile yazıp Python'a bağlarken (hybrid mimari) yaşanacak performans kayıplarını (overhead) anlamak için mükemmel bir yazılım mimarisi kaynağıdır. | Doğrudan bir düşük ışık iyileştirme algoritması sunmaz; tamamen C++ ve Python dillerinin görüntü işleme kütüphaneleri özelindeki donanım/yazılım seviyesi performanslarına odaklanır. |
| 28 | Immersive Virtual Painting: Pushing Boundaries in Real-Time Computer Vision using OpenCV with C++ | Satyam Mishra, Phung Thao Vi, Vu Duy Trung | 2023 | Gerçek Zamanlı Bilgisayarlı Görü ve Gecikme Optimizasyonu (C++ vs Python) | C++ ve OpenCV ile renk tespiti; paralel işleme optimizasyonları | Canlı video akışları (Live video feeds) | İşlem süresi (kare başına 15ms), Doğruluk, Yürütme Hızı (Execution speed) | OpenCV uygulamalarında C++'ın Python'a göre **3-4 kat daha hızlı çalıştığı** kanıtlanmış ve ultra düşük gecikme elde edilmiştir. | Görüntü işleme algoritmalarında saf Python yerine neden C++ (veya hibrit) kullanılması gerektiğini "3-4 kat hız farkı" gibi somut metriklerle kanıtlar; kod mimarinizi savunmak için harika bir performans referansıdır. | Otonom sürüşe veya düşük ışık iyileştirmeye değil, renk tespiti ve sanal boyama uygulamasına odaklanmıştır. |
| 29 | Parallel Optimization of OpenCV Functions: Enhancing Image Processing Efficiency with Multi-core CPU Execution | Ali Nasir | Güncel (Belirtilmemiş) | Görüntü Ön İşleme Hızlandırması ve CPU Paralelleştirmesi | Python `multiprocessing` modülü ile OpenCV fonksiyonlarının çok çekirdekli (multi-core) CPU üzerinde paralelleştirilmesi | Kaggle Flowers Image Dataset vb. | İşlem süresi (Processing time), İş çıkarma hacmi (Throughput) | GPU erişimi olmayan ortamlarda (edge cihazlar) gerçek zamanlılık ve toplu işlem (batch processing) performansını artırmayı hedefler. | C++ entegrasyonuna geçmeden önce "saf Python" kodunun kendi içinde (multiprocessing ile) ne kadar optimize edilebileceğini gösterir; objektif bir performans referansı (baseline) oluşturur. | Görüntü iyileştirmeye özgü yeni bir algoritma sunmaz; salt CPU/Python optimizasyonudur ve C++ ile doğrudan kıyaslama içermez. |
| 30 | TVM: An Automated End-to-End Optimizing Compiler for Deep Learning | Tianqi Chen, Thierry Moreau, Ziheng Jiang, Lianmin Zheng, Eddie Yan, Haichen Shen, Meghan Cowan, Leyuan Wang, Yuwei Hu, Luis Ceze, Carlos Guestrin, Arvind Krishnamurthy | 2018 | Çeşitli Donanım Platformları İçin Derin Öğrenme Modellerinin Derlenmesi ve Optimizasyonu | TVM: Grafik seviyesi (graph-level) ve operatör seviyesi optimizasyonlar sağlayan uçtan uca derleyici ve öğrenme tabanlı maliyet modeli | Çeşitli donanım (Raspberry Pi, NVIDIA/Mali GPU) ve modeller (ResNet, MobileNet vb.) | Çıkarım gecikmesi (Inference latency), donanım kullanım verimliliği | Ağır Derin Öğrenme modellerini standart kütüphanelere (TFLite vb.) göre donanım mimarisine doğrudan derleyerek gecikmeyi dramatik ölçüde düşürür ve uç cihazlarda gerçek zamanlılığı mümkün kılar. | Tezinizin "hibrit C++ mimarisi ve donanım optimizasyonu" argümanının merkezindeki en güçlü bilgisayar bilimleri (Sistem Mimarisi) referansıdır. Modellerin Python'dan donanıma geçerken neden derlenmesi (compile edilmesi) gerektiğini teknik detaylarıyla açıklar. | Spesifik olarak düşük ışık iyileştirme algoritması sunmaz; makine öğrenmesi modellerinin genel donanım derleyicisi mimarisine odaklanır. |

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

## Paper 19

### Makale Bilgisi
- **Makale Adı:** Real-time fast low-light vision enhancement for driver during driving at night
- **Yazarlar:** Gouranga Mandal, Diptendu Bhattacharya, Parthasarathi De
- **Yıl:** 2022
- **Yayın Yeri:** Journal of Ambient Intelligence and Humanized Computing
- **DOI / Link:** 10.1007/s12652-021-02930-6

### Çalışmanın Amacı
Gece sürüşlerinde zayıf aydınlatma nedeniyle görünmeyen yayaların, çukurların ve diğer nesnelerin sürücüler tarafından gerçek zamanlı (anlık) olarak fark edilebilmesini sağlamayı amaçlamaktadır. Yazarlar, düşük bütçeli 2D kameralarla bile "gerçek zamanlılık" (real-time processing) sağlayabilmek için ağır donanım gerektiren derin öğrenme modellerinden kaçınmışlar; bunun yerine hesaplama maliyeti son derece düşük olan **modifiye edilmiş parlak kanal önceliği (modified bright channel prior)** ve **adaptif gama düzeltmesi (adaptive gamma correction)** yöntemlerini kullanmışlardır.

**Teze Katkısı:** Otonom araç tezinizde, saf C++ ve Python kullanarak OpenCV üzerinden donanım/işlem hızı kıyaslaması yapacağınızı biliyoruz. Derin öğrenme ağlarının (CNN/Transformer vb.) performans darboğazlarını net olarak ölçebilmeniz için öncelikle onlara "geleneksel ve son derece hızlı" bir rakip (baseline) sunmanız gerekmektedir. Bu makalenin sunduğu hafif, iteratif olmayan, doğrudan piksellerin histogramı ve öncelikleri üzerinden çalışan matematiksel model; tezinizdeki gecikme (latency) testlerinde en hızlı çalışacak "referans" yönteminiz olmak için biçilmiş kaftandır.

## Paper 20

### Makale Bilgisi
- **Makale Adı:** Performance Evaluation of Computer Vision Algorithms in a Programmable Logic Controller: An Industrial Case Study
- **Yazarlar:** Rodrigo Vieira, Dino Silva, Eliseu Ribeiro, Luís Perdigoto, Paulo Jorge Coelho
- **Yıl:** 2023
- **Yayın Yeri:** Sensors (MDPI)
- **DOI / Link:** 10.3390/s23094363

### Çalışmanın Amacı
Bu çalışma, Phoenix Contact'ın PLCnext ekosisteminden bir **Programlanabilir Mantıksal Denetleyicinin (PLC)** endüstriyel görüntü işleme platformu olarak kullanılabilirliğini değerlendirmeyi amaçlamaktadır. Linux tabanlı bu kontrol cihazı üzerinde Python dili ve OpenCV kütüphanesi kullanılarak standart görüntü işleme uygulamaları geliştirilmiş; sistemin performansı (işlem süresi/gecikme) standart bir bilgisayar (PC) ile karşılaştırmalı olarak analiz edilmiştir.

**Teze Katkısı:** Tezinizdeki temel odak noktası, otonom araçlar gibi gerçek zamanlı tepki vermesi gereken kısıtlı donanımlarda Python ve C++ performanslarını kıyaslamaktır. Bu makale, **saf Python ve OpenCV** ikilisinin Linux tabanlı endüstriyel bir donanım üzerindeki "milisaniye" seviyesindeki performans sınırlarını göstermesi açısından çok değerli bir referans sunar. Kontrol cihazı üzerindeki gecikme (latency) sürelerini bir PC ile kıyaslayarak sunması, sizin neden C++ entegrasyonuna veya hibrit mimariyle performans optimizasyonuna ihtiyaç duyduğunuzu teknik bir vaka çalışması üzerinden savunmanızı sağlar.

## Paper 21

### Makale Bilgisi
- **Makale Adı:** Low Latency Deep Learning Inference Model for Distributed Intelligent IoT Edge Clusters
- **Yazarlar:** Soumyalatha Naveen, Manjunath R. Kounte, Mohammed Riyaz Ahmed
- **Yıl:** 2021
- **Yayın Yeri:** IEEE Access
- **DOI / Link:** 10.1109/ACCESS.2021.3131396

### Çalışmanın Amacı
Bu çalışma, Nesnelerin İnterneti (IoT) ağlarında kullanılan düşük maliyetli ve mobil uç cihazların (edge devices) sınırlı bellek, güç ve hesaplama kapasitelerini en verimli şekilde kullanabilmeleri için optimize edilmiş bir derin öğrenme çıkarım (inference) modeli sunmayı amaçlamaktadır. Ana odak noktası, akıllı uç bilişim sistemlerinde "gerçek zamanlı" (real-time) kararlar alabilmek için gerekli olan ve genellikle birkaç saniye veya daha az olması beklenen **uçtan uca gecikmeyi (end-to-end delay / low latency)** minimize etmektir.

**Teze Katkısı:** Otonom araçlar üzerindeki kameralar ve işlemciler (örneğin NVIDIA Jetson serisi), kendi başlarına oldukça kritik ve mobil birer "Uç Cihaz (Edge Device)" olarak kabul edilirler. Bu makale, derin öğrenme algoritmalarının bu tarz donanım kısıtlı cihazlarda çalıştırılmasının doğası gereği ciddi performans (gecikme) zorlukları içerdiğini doğrular. Tezinizde, saf Python kullanmanın yaratacağı bellek ve işlemci darboğazlarını aşmak için neden C++ ile hibrit bir mimari kurmanız gerektiğini, otonom aracın bir "Edge" sistemi olduğu gerçeği üzerinden teknik olarak savunmanıza güçlü bir altyapı sağlar.

## Paper 22

### Makale Bilgisi
- **Makale Adı:** Performance Evaluation of Deep Learning Compilers for Edge Inference
- **Yazarlar:** Gaurav Verma, Yashi Gupta, Abid M. Malik, Barbara Chapman
- **Yıl:** 2021
- **Yayın Yeri:** 2021 IEEE International Parallel and Distributed Processing Symposium Workshops (IPDPSW)
- **DOI / Link:** 10.1109/IPDPSW52791.2021.00128

### Çalışmanın Amacı
Derin öğrenme modellerinin otonom araçlar, dronlar ve IoT cihazları gibi kısıtlı işlem gücüne sahip uç cihazlarda (edge devices) çalıştırılması önemli bir darboğaz yaratmaktadır. Bu çalışma, PyTorch veya TensorFlow gibi platformlarda (çoğunlukla Python kullanılarak) eğitilmiş standart modellerin, uç cihazlarda daha hızlı ve düşük gecikme (latency) ile çalışabilmesi için geliştirilen TensorRT, TensorFlow Lite ve TVM gibi derin öğrenme derleyicilerini (DL compilers) Jetson Nano ve Raspberry Pi üzerinde kıyaslamaktadır.

**Teze Katkısı:** Bu çalışma tezinizin kodlama ve donanım mimarisi (Python vs C++) altyapısına muazzam bir destek sağlar. Python, derin öğrenme modellerini eğitmek ve hızlı prototipleme yapmak için harikadır; ancak otonom sürüşte (gerçek zamanlılık gerektiğinde) saf Python kodunun C++ (veya TensorRT/TVM gibi C/C++ tabanlı derleyiciler) kadar hızlı olamayacağı bilinen bir gerçektir. Bu makale, modellerin donanım seviyesinde optimize edilmesiyle (derlenmesiyle) gecikme sürelerinin nasıl dramatik bir şekilde düştüğünü göstermektedir. Tezinizde, görüntü iyileştirme algoritmalarının "Saf Python" versiyonları ile "C++ veya Optimize Edilmiş (Hibrit)" versiyonları arasındaki performans (FPS/milisaniye) farklarını analiz ederken argümanlarınızı bu çalışmaya dayandırabilirsiniz.

## Paper 23

### Makale Bilgisi
- **Makale Adı:** Lightweight Low-Light Image Enhancement Techniques for Edge Devices
- **Yazarlar:** Ebin J Alapatt, Pankaj Kumar G, Narayanan V Eswar, Aman K Shihab, S Krishna Bhatt, Sreevishnu Damodaran, A A Aswathy
- **Yıl:** 2025
- **Yayın Yeri:** 2025 Advanced Computing and Communication Technologies for High Performance Applications (ACCTHPA)
- **DOI / Link:** 10.1109/ACCTHPA65749.2025.11168575

### Çalışmanın Amacı
Otonom navigasyon ve güvenlik gibi uygulamalarda bilgisayarlı görü sistemlerinin gece veya düşük ışıkta ciddi zorluklar yaşadığı bilinmektedir. Bu çalışma, söz konusu sistemlerin genellikle sınırlı bellek ve işlem gücüne sahip "Uç Cihazlar" (Edge Devices) üzerinde çalıştırıldığını göz önüne alarak, hem geleneksel (Gri seviye dönüşümü, Gama, Retinex) hem de derin öğrenme tabanlı düşük ışık iyileştirme algoritmalarının **"hafiflik" (lightweight)** potansiyellerini ve uç cihazlara uyumluluklarını kapsamlı bir şekilde incelemektedir.

**Teze Katkısı:** Bu makale, tezinizdeki Python vs. C++ performans kıyaslamasının "neden" gerekli olduğunu savunan çok taze (2025) bir çerçeve sunar. Çalışma, uç cihazlarda kullanılacak algoritmaların hesaplama gücü ve depolama kısıtlarına saygı göstermesi ve "gerçek zamanlı" işleme yeteneğine sahip olması gerektiğini açıkça belirtir. Tezinizin Giriş ve Yöntem bölümlerinde *"Ağır derin öğrenme modelleri otonom araçlardaki (Edge Device) işlemcilere darboğaz yaratmaktadır; bu nedenle algoritmaların C++ gibi alt seviye diller kullanılarak hafifletilmesi ve optimize edilmesi gereklidir"* şeklindeki teorik iddianızı temellendirebileceğiniz doğrudan bir referanstır.

## Paper 24

### Makale Bilgisi
- **Makale Adı:** Lightweight object detection in low light: Pixel-wise depth refinement and TensorRT optimization
- **Yazarlar:** K. Vinoth, Sasikumar P
- **Yıl:** 2024
- **Yayın Yeri:** Results in Engineering (Elsevier)
- **DOI / Link:** (Eklenecek)

### Çalışmanın Amacı
Düşük ışıklı ortamlarda yüksek gürültü ve düşük kontrast nedeniyle nesne tespitinin zorlaşması problemini, hem görsel doğruluğu artırarak hem de çıkarım (inference) hızını optimize ederek çözmeyi amaçlamaktadır. Çalışma, her pikselin derinlik eğrisini tahmin eden bir derin öğrenme modeli (Pixel-wise depth refinement) kullanarak detayları belirginleştirirken, nesne tespiti görevini NVIDIA'nın **TensorRT** motoruyla optimize edilmiş hafif bir YOLOv8 modeli ile gerçekleştirir. Bu sayede modelin hesaplama karmaşıklığı ve bellek kullanım alanı (memory footprint) ciddi oranda azaltılarak kaynakları kısıtlı cihazlarda daha hızlı yanıt süreleri hedeflenmiştir.

**Teze Katkısı:** Bu makale, tezinizdeki en kritik sorulardan birine doğrudan bir çözüm senaryosu sunar: *"Python'da eğitilen ağır yapay zeka modelleri, Jetson Orin gibi uç cihazlarda (edge devices) nasıl gerçek zamanlı çalıştırılır?"* Makalenin TensorRT (NVIDIA'nın C++ tabanlı yüksek performanslı derin öğrenme çıkarım motoru) kullanarak YOLOv8'in hızını optimize etmesi, tezinizin **hibrit mimari (Python-C++)** argümanını mükemmel bir şekilde destekler. Görüntü iyileştirme algoritmalarının Python yerine donanım seviyesine daha yakın araçlar ve diller (C++/TensorRT vb.) kullanılarak derlendiğinde gecikme (latency) sürelerinin nasıl düşürüldüğünü literatür üzerinden kanıtlamak için güçlü bir dayanaktır.

## Paper 25

### Makale Bilgisi
- **Makale Adı:** A Review of Recent Hardware and Software Advances in GPU-Accelerated Edge-Computing Single-Board Computers (SBCs) for Computer Vision
- **Yazarlar:** Umair Iqbal, Tim Davies, Pascal Perez
- **Yıl:** 2024
- **Yayın Yeri:** Sensors (MDPI)
- **DOI / Link:** 10.3390/s24154830

### Çalışmanın Amacı
Bulut bilişimin (Cloud Computing) getirdiği bant genişliği sorunları, yüksek gecikme (latency) ve veri gizliliği risklerini aşmak için bilgisayarlı görü işlemlerinin doğrudan kameranın bulunduğu uç cihaza (edge device) taşınması gerekmektedir. Bu makale, otonom araçlarda da sıkça kullanılan GPU hızlandırmalı Tek Kartlı Bilgisayarların (SBC - NVIDIA Jetson serisi, Raspberry Pi vb.) donanım kapasitelerini ve bu donanımlardan maksimum verimi almak için kullanılan yazılım optimizasyon araçlarını (TensorRT, OpenVINO, ONNX Runtime) sistematik olarak incelemeyi amaçlamaktadır.

## Paper 26

### Makale Bilgisi
- **Makale Adı:** Learning Optimized Low-Light Image Enhancement for Edge Vision Tasks
- **Yazarlar:** SMA Sharif, Azamat Myrzabekov, Nodirkhuja Khujaev, Roman Tsoy, Seongwan Kim, Jaeho Lee
- **Yıl:** 2024
- **Yayın Yeri:** CVPR Workshops
- **DOI / Link:** (Eklenecek)

### Çalışmanın Amacı
Mevcut düşük ışıklı görüntü iyileştirme yöntemlerinin yüksek hesaplama maliyetleri nedeniyle "uç görüş (edge vision)" uygulamaları için pratik olmaması sorununu çözmeyi amaçlamaktadır. Araştırmacılar, mobil uyumlu ve son derece hafif bir derin öğrenme ağı tasarlamış, ardından bu modeli INT8 hassasiyetinde eğitim sonrası kuantizasyon (post-training quantization - PTQ) stratejisi ile optimize etmişlerdir. Sonuç olarak düşük güçlü bir uç cihazda saniyede 199 kare (FPS) işleme hızına ulaşılmış ve bu iyileştirmenin diğer görüş algoritmalarının (nesne tespiti vb.) performansını da ciddi oranda artırdığı kanıtlanmıştır.

**Teze Katkısı:** Bu çalışma, tezinizin donanım performansı ve "gerçek zamanlılık" hedeflerini doğrudan vuran, CVPR 2024 tarihli son derece prestijli bir kaynaktır. Jetson Orin Nano gibi uç cihazlarda Python tabanlı modelleri çalıştırırken yaşanan yavaşlık sorunlarını aşmak için C++ optimizasyonuna ek olarak "INT8 Kuantizasyonu" gibi model hafifletme (lightweight) tekniklerini de tezinizin teorik tartışmalarına dahil etmenizi sağlayacaktır. 199 FPS gibi ölçülebilir bir hedef sunması, kendi hibrit mimarinizin gecikme (latency) testlerinde kıyaslama (benchmark) yapabileceğiniz çok güçlü bir referanstır.

## Paper 27

### Makale Bilgisi
- **Makale Adı:** Generic programming in modern C++ for Image Processing
- **Yazarlar:** Michaël Roynard
- **Yıl:** 2022
- **Yayın Yeri:** Doctoral Thesis, Sorbonne Université (HAL)
- **DOI / Link:** tel-03922670

### Çalışmanın Amacı
Bu doktora tezi, görüntü işleme kütüphanelerinin (framework) geliştirilmesinde Modern C++'ın sunduğu jenerik programlama (generic programming) yeteneklerini kullanarak yüksek performanslı ve yeniden kullanılabilir algoritmalar tasarlamayı amaçlamaktadır. Yazar; görüntü işleme algoritmalarının C++ tarafında nasıl optimize edileceğini, şablon meta programlamanın (template metaprogramming) avantajlarını ve özellikle C++ tabanlı algoritmaların Python gibi dinamik dillere (Python binding) bağlanması sırasında ortaya çıkan performans kayıplarını (overhead) detaylı mikro-benchmark testleriyle (timeit) analiz etmiştir.

**Teze Katkısı:** Bu kapsamlı tez çalışması, projenizin doğrudan "Uygulama/Yazılım Mimarisi" bölümü için muazzam bir destek sağlar. Görüntü iyileştirme modellerinizi saf Python ile çalıştırmak yerine, neden arkada C++ kodlarını çağıran "Hibrit bir Mimari" (Python-C++ binding) kurduğunuzu akademik bir temele oturtur. Dahası, C++ içindeki farklı tasarım tercihlerinin (örneğin sanal fonksiyonlar vs. statik çözünürlük) Python'a aktarılan gecikme sürelerini (latency/ms) nasıl etkilediğini açıklayarak, tezinizdeki performans karşılaştırma tablolarınızı ve kod optimizasyonu argümanlarınızı yazılım mühendisliği perspektifinden çok daha güçlü savunmanıza imkan tanır.

## Paper 28

### Makale Bilgisi
- **Makale Adı:** Immersive Virtual Painting: Pushing Boundaries in Real-Time Computer Vision using OpenCV with C++
- **Yazarlar:** Satyam Mishra, Phung Thao Vi, Vu Duy Trung
- **Yıl:** 2023
- **Yayın Yeri:** Proceedings of the Eighth International Conference on Research in Intelligent Computing in Engineering
- **DOI / Link:** 10.15439/2023R58

### Çalışmanın Amacı
Bu çalışma, gerçek zamanlı bilgisayarlı görü (real-time computer vision) tekniklerini kullanarak sürükleyici bir sanal boyama (virtual painting) uygulaması geliştirmeyi amaçlamaktadır. Yazarlar, canlı video akışlarından belirli renkleri tespit edip dijital bir tuvale yansıtmak için OpenCV kütüphanesini C++ ile entegre bir şekilde uygulamışlardır. Kare başına 15ms gibi işlem sürelerine ulaşarak ultra düşük gecikmeli (ultra-low latency) etkileşimler sağlamışlar ve paralel işleme stratejileriyle performans kazanımları elde etmişlerdir.

**Teze Katkısı:** Makalenin teziniz için en can alıcı noktası, bilgisayarlı görü görevleri için yapılan karşılaştırmalı analizde **C++ kullanımının Python'a göre 3-4 kat daha hızlı yürütüldüğünü (3-4x faster execution)** doğrudan kanıtlamasıdır. Bu sonuç, tezinizin odak noktasını oluşturan "gerçek zamanlılık gerektiren sistemlerde pure Python yerine C++ veya hibrit mimari kullanılmalıdır" argümanınızı, tamamen OpenCV kütüphanesi özelindeki performans kıyaslamalarına dayandırarak son derece somut bir şekilde savunmanızı sağlayacaktır.

## Paper 29

### Makale Bilgisi
- **Makale Adı:** Parallel Optimization of OpenCV Functions: Enhancing Image Processing Efficiency with Multi-core CPU Execution
- **Yazarlar:** Ali Nasir
- **Yıl:** Belirtilmemiş (Referanslara göre 2022 sonrası)
- **Yayın Yeri:** Bağımsız Araştırma (Independent Researcher)
- **DOI / Link:** (Eklenecek)

### Çalışmanın Amacı
OpenCV kullanılarak yapılan görüntü işleme görevlerinde (filtreleme, kenar tespiti, renk uzayı dönüşümü vb.) GPU gibi özel donanım hızlandırıcılarına erişimin olmadığı durumlarda, işlem sürelerini kısaltmak hedeflenmektedir. Bu amaçla, Python'ın yerleşik `multiprocessing` (çoklu işlem) kütüphanesinden faydalanılarak, OpenCV iş yükleri çok çekirdekli bir CPU üzerinde paralelleştirilmiş ve toplu işlemlerin (batch processing) çalışma süresinde belirgin düşüşler sağlanmıştır.

**Teze Katkısı:** Otonom araç kameralarından gelen verileri işlerken Python kodunuzun yavaşlığını salt dilin kendisine bağlamadan önce, kodun "paralel işlem" kapasitesini ölçmeniz metodolojik bir gerekliliktir. Bu çalışma, saf Python'ın kendi olanakları dahilinde maksimum verime ("optimize edilmiş Python baseline") ulaştığında bile C++ mimarisi karşısında nasıl bir performans sergileyeceğini adil bir şekilde kıyaslayabilmeniz için son derece pratik ve sağlam bir köşe taşı oluşturmaktadır.

## Paper 30

### Makale Bilgisi
- **Makale Adı:** TVM: An Automated End-to-End Optimizing Compiler for Deep Learning
- **Yazarlar:** Tianqi Chen, Thierry Moreau, Ziheng Jiang, Lianmin Zheng, Eddie Yan, Haichen Shen, Meghan Cowan, Leyuan Wang, Yuwei Hu, Luis Ceze, Carlos Guestrin, Arvind Krishnamurthy
- **Yıl:** 2018
- **Yayın Yeri:** 13th USENIX Symposium on Operating Systems Design and Implementation (OSDI '18)
- **DOI / Link:** (Eklenecek)

### Çalışmanın Amacı
Makine öğrenmesi modellerinin CPU, GPU ve alana özgü yapay zeka hızlandırıcıları (domain-specific accelerators) gibi çok çeşitli donanım arka planlarında verimli bir şekilde çalıştırılması zor bir problemdir. Mevcut derin öğrenme çerçeveleri (framework'leri), her yeni donanım türü için dar ve manuel olarak optimize edilmiş kütüphanelere dayanır. Bu çalışma, çeşitli derin öğrenme modellerini alıp doğrudan hedef donanımın özelliklerine göre (grafik ve operatör düzeyinde) optimize eden ve derleyen (compile eden) açık kaynaklı **TVM (Tensor Virtual Machine)** mimarisini tanıtmaktadır. TVM, Raspberry Pi gibi düşük güçlü uç cihazlardan sunucu GPU'larına kadar geniş bir donanım yelpazesinde çıkarım gecikmesini (inference latency) ciddi oranda azaltmaktadır.

**Teze Katkısı:** Bu çalışma, yapay zeka sistem mimarisi alanındaki en önemli köşe taşlarından biridir. Tezinizde düşük ışık görüntü iyileştirme algoritmalarının performansını test ederken, *"Modelleri neden doğrudan Python'da (PyTorch/TensorFlow) çalıştırmıyoruz da C++ tabanlı derleyicilere veya optimize edilmiş araçlara aktarıyoruz?"* sorusunun cevabını bilimsel olarak verir. Makale, bir modelin donanım seviyesinde (örneğin Jetson serisi veya Raspberry Pi'de) optimize edilebilmesi için arka planda çalışan C++ tabanlı derleme süreçlerinin ve bellek optimizasyonlarının, Python'ın getirdiği aşırı yükleri (overhead) nasıl sildiğini gösteren temel kaynaktır. Tezinizin metodolojisinde ve teknik altyapısında "Derin Öğrenme Derleyicilerinin (Deep Learning Compilers) Önemi" başlığını savunmak için referans göstereceğiniz başlıca kaynaktır.
