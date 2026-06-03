# OpenCV Python Notları

## Image Read / Görüntü Okuma

OpenCV'de görüntü okuma Python tarafında `cv2.imread()` fonksiyonu kullanılarak yapılmaktadır.

```python
import cv2

image = cv2.imread('./images/dog.jpg')

if image is None:
    print('Görüntü açılamadı.')
else:
    print('Görüntü başarıyla açıldı.')
```

`cv2.imread()` fonksiyonu görüntüyü belirtilen dosya yolundan okur. Eğer dosya
yolu hatalıysa veya görüntü okunamazsa `None` değeri döner.

## Image Show / Görüntü Gösterme

OpenCV'de görüntü gösterme Python tarafında `cv2.imshow()` fonksiyonu kullanılarak yapılmaktadır.
Aşağıdaki örnek bu fonksiyonun bir kullanım örneği gösterilmiştir.
```python
import cv2

image = cv2.imread('./images/dog.jpg')

if image is None:
    print("Görüntü açılamadı.")
else:
    print("Görüntü başarıyla açıldı.")

    cv2.imshow("Image", image)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
```

Yukarıdaki kodda `cv2.waitKey(0)` fonksiyonunun kullanılma sebebi görüntü penceresinin hemen kapanmasını engellemektir.

`cv2.imshow()` fonksiyonu iki temel parametre alır. İlk parametre açılan pencerenin adını, ikinci parametre ise gösterilecek görüntüyü ifade eder.

## Image Resize / Görüntü Ölçeklendirme

Python'da ölçeklendirme işlemi `cv2.resize()` fonksiyonu kullanılarak yapılmaktadır.

Aşağıdaki örnekte bu fonksiyonun kullanımı verilmiştir.

```python
import cv2 

image = cv2.imread('./images/dog.jpg') 
if image is None: 
    print("Görüntü açılamadı.") 
else: 
    print("Görüntü başarıyla açıldı.") 

    resized_image = cv2.resize(image, (800, 500)) 

    cv2.imshow("Original Image", image) 
    cv2.imshow("Resized Image", resized_image) 

    cv2.waitKey(0) 
    cv2.destroyAllWindows()
```

`cv2.resize()` fonksiyonunun temel kullanımında kaynak görüntü ve hedef boyut parametreleri
verilir.

`resized_image = cv2.resize(image, (800, 500))`

Burada `(800, 500)` ifadesinde ilk değer genişliği, ikinci değer yüksekliği ifade eder.

Yani:

```
800 -> width/genişlik
500 -> height/yükseklik
```

## Image Flip / Görüntüyü Ters Çevirme

Python'da görüntüyü ters çevirme işlemi `cv2.flip()` fonksiyonu kullanılarak
yapılmaktadır.

```python
import cv2

image = cv2.imread('./images/dog.jpg') 

if image is None: 
    print("Görüntü açılamadı.") 
else: 
    print("Görüntü başarıyla açıldı.") 
    
    flipped_vertical = cv2.flip(image, 0) 
    flipped_horizontal = cv2.flip(image, 1) 
    flipped_both = cv2.flip(image, -1) 

    cv2.imshow("Original Image", image) 
    cv2.imshow("Flipped Vertical", flipped_vertical) 
    cv2.imshow("Flipped Horizontal", flipped_horizontal) 
    cv2.imshow("Flipped Both", flipped_both) 
    cv2.waitKey(0) 
    cv2.destroyAllWindows()
```

`cv2.flip()` fonksiyonunda ikinci parametre çevirme yönünü belirtir.

```
0   -> dikey çevirir
1   -> yatay çevirir
-1  -> hem yatay hem dikey çevirir
```
şeklindedir.

## Color Spaces and Color Conversions / Renk Uzayları ve Renk Dönüşümleri

Bir görüntünün en önemli özelliklerinden biri renk bilgisidir. OpenCV ile görüntüler üzerinde çalışırken renk kanallarının sırasını doğru anlamak gerekir.

OpenCV'de `cv2.imread()` fonksiyonu ile okunan renkli görüntüler varsayılan olarak `BGR` formatında tutulur.
Yani kanal sırası şu şekildedir:

```
Blue - Green - Red
```
Ancak Matplotlib kütüphanesinin `plt.imshow` fonksiyonu görüntüyü `RGB` formatında bekler:
```
Red - Green - Blue
```
Bu nedenle OpenCV ile okunan bir görüntü doğrudan Matplotlib ile gösterilirse renkler bozuk ve beklenenden
farklı görünebilir. Özellikle kırmızı ve mavi kanallar yer değiştirmiş gibi algılanır.

Bu problemi çözmek için OpenCV'deki `cv2.cvtColor()` fonksiyonu kullanılır. Aşağıdaki örnekte BGR formatında
okunan görüntü RGB formatına çevrilerek Matplotlib ile doğru renklerde gösterilmiştir:

```python
import cv2
import matplotlib.pyplot as plt

img_bgr = cv2.imread("./images/dog.jpg")

img_rgb = cv2.cvtColor(img_bgr, cv2.COLOR_BGR2RGB)

plt.imshow(img_rgb)
plt.axis("off")
plt.show()
```

Burada:
`img_bgr` OpenCV'nin kullandığı `BGR` formatındaki görüntüdür.
`img_rgb` Matplotlib ile doğru şekilde göstermek için RGB formatına dönüştürülmüş görüntüdür.

Kısaca, OpenCV ile görüntü işleme yaparken BGR formatı kullanılırken Matplotlib ile görüntü gösterirken `RGB` formatına
dönüşüm gerekir.

## Image Create / Görüntü Oluşturma

Görüntü oluşturmak için pythonda kullanılan fonksiyon `cv2.imwrite` fonksiyonudur.
Bu fonksiyon ile ilgili aşağıdaki örneği inceleyiniz:
```python
import cv2

img = cv2.imread("./images/dog.jpg")
img_saved = cv2.imwrite("./outputs/dog_saved.jpg", img)

if img_saved:
    print("Görüntü başarıyla kayıt edildi.")
else: 
    print("Görüntü kaydedilemedi.")
```

Burada `cv2.imwrite()` fonksiyonunun ilk parametresi görüntünün kaydedileceği dosya yolunu ifade eder. İkinci parametre ise kaydedilecek görüntüyü temsil eder.

Genel kullanım şekli şu şekildedir:
```
cv2.imwrite(file_path, image)
```
Örneğin:
```
cv2.imwrite("./outputs/dog_saved.jpg", img)
```
Bu kod, `img` değişkeninde tutulan görüntüyü `outputs` klasörünün içerisine 
`dog_saved.jpg` adıyla kaydeder.

Dikkat edilmesi gereken noktalardan biri, görüntünün kaydedileceği klasörün önceden oluşturulmuş olmasıdır. Örneğin `outputs` 
klasörü mevcut değilse kaydetme işlemi başarısız olabilir.

Kısaca, `cv2.imwrite()` fonksiyonu OpenCV'de görüntüyü dosyaya yazmak veya kaydetmek 
için kullanılır.

## Görüntü Eşikleme / Image Thresholding

Görüntü eşikleme, görüntü işlemede sık kullanılan temel tekniklerden biridir. Bu işlemde görüntüdeki piksel değerleri belirli bir eşik değerine göre sınıflandırılır.

Özellikle gri seviye görüntülerde her pikselin değeri `0` ile `255` arasındadır. Eşikleme işleminde belirlenen bir eşik değerinin üstünde kalan pikseller genellikle beyaz, altında kalan pikseller ise siyah yapılır.

Bu yöntem sayesinde görüntüdeki belirli bölgeler daha belirgin hale getirilebilir. Aynı zamanda arka plan gibi önemsiz bölgeler bastırılarak ilgilenilen nesneler daha kolay analiz edilebilir.

OpenCV'de eşikleme işlemi için `cv2.threshold()` fonksiyonu kullanılır.
```python
import cv2
import matplotlib.pyplot as plt

img = cv2.imread("./images/dog_backpack.jpg")
img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

ret, thresh = cv2.threshold(img_gray, 127, 255, cv2.THRESH_BINARY)

plt.figure(figsize=(10, 5))

plt.subplot(1, 2, 1)
plt.imshow(img_gray, cmap="gray") 
plt.title("Grayscale Image") 
plt.axis("off")

plt.subplot(1, 2, 2) 
plt.imshow(thresh, cmap="gray") 
plt.title("Thresholded Image") 
plt.axis("off") 
plt.show()
```

Burada `cv2.threshold()` fonksiyonu iki değer döndürür:

```
ret, thresh = cv2.threshold(img_gray, 127, 255, cv2.THRESH_BINARY)
```
`ret`, kullanılan eşik değeridir. Bu örnekte `127` değerini döndürür.

`thresh` ise eşikleme işlemi sonucunda oluşan yeni görüntüdür.

Fonksiyonun parametreleri şu şekildedir:
```
cv2.threshold(source, threshold_value, max_value, threshold_type)
```

Bu örnekte: 
```
cv2.threshold(img_gray, 127, 255, cv2.THRESH_BINARY)
```
`img_gray`, eşikleme uygulanacak gri seviye görüntüdür.
`127`, eşik değeridir. Piksel değeri bu değerden büyükse farklı, küçükse farklı
işlem uygulanır.
`255`, eşik değerinin üstünde kalan piksellere verilecek maksimum değerdir.
`cv2.THRESH_BINARY`, uygulanacak eşikleme türüdür.

Bu eşikleme türünde: 
```
Piksel değeri > 127 ise 255 yapılır.
Piksel değeri <= 127 ise 0 yapılır.
```
Yani görüntü siyah-beyaz bir yapıya dönüştürülür.

## Image Blurring / Görüntü Bulanıklaştırma

Görüntü bulanıklaştırma, görüntü işlemede sık kullanılan temel tekniklerden biridir. Temel amaç görüntüdeki keskin geçişleri yumuşatmak, küçük detayları azaltmak ve gürültüyü bastırmaktır.

Blurring işlemi film sektörü, yüz gizleme, arka plan bulanıklaştırma, görüntü iyileştirme ve nesne tespiti gibi birçok alanda kullanılabilir. Ayrıca thresholding ve edge detection gibi işlemlerden önce görüntüyü daha düzgün hale getirmek için de tercih edilir.

OpenCV'de görüntü bulanıklaştırma için kullanılan önemli fonksiyonlardan biri `cv2.GaussianBlur()` fonksiyonudur.

Genel kullanım şekli şöyledir:
```
cv2.GaussianBlur(src, ksize, sigmaX)
```
Burada:

`src`, bulanıklaştırma uygulanacak görüntüdür.

`ksize`, kernel boyutunu ifade eder. Örneğin (5, 5) değerinde 5x5 boyutunda bir filtre kullanılır. Kernel boyutları genellikle pozitif ve tek sayı olmalıdır.

`sigmaX`, Gaussian fonksiyonunun X yönündeki standart sapma değeridir. Bu değer 0 verilirse OpenCV sigma değerini kernel boyutuna göre otomatik hesaplar.

Aşağıdaki örnekte bir görüntü okunmuş, RGB formatına çevrilmiş ve ardından Gaussian Blur uygulanmıştır:

```python
import cv2 
import matplotlib.pyplot as plt 

img_bgr = cv2.imread("./images/bricks.jpg") 

img_rgb = cv2.cvtColor(img_bgr, cv2.COLOR_BGR2RGB) 

blurred = cv2.GaussianBlur(img_rgb, (5, 5), 0) 

plt.figure(figsize=(12, 6)) 

plt.subplot(1, 2, 1) 
plt.imshow(img_rgb) 
plt.title("Original Image") 
plt.axis("off") 

plt.subplot(1, 2, 2) 
plt.imshow(blurred) 
plt.title("Gaussian Blurred Image") 
plt.axis("off") 
plt.show()
```
Bu örnekte img_rgb orijinal görüntüyü, blurred ise Gaussian Blur uygulanmış görüntüyü temsil eder.

Kernel boyutu arttıkça görüntü üzerindeki bulanıklık etkisi de artar. Örneğin:
```
blurred_5 = cv2.GaussianBlur(img_rgb, (5, 5), 0)
blurred_15 = cv2.GaussianBlur(img_rgb, (15, 15), 0)
blurred_31 = cv2.GaussianBlur(img_rgb, (31, 31), 0)
```
Burada `(31, 31)` kernel boyutu, `(5, 5)` kernel boyutuna göre çok daha güçlü bir bulanıklaştırma etkisi oluşturur.

Kısaca, `cv2.GaussianBlur()` fonksiyonu görüntüyü yumuşatmak ve gürültüyü azaltmak için kullanılır. Özellikle Canny Edge Detection ve Thresholding gibi işlemlerden önce daha temiz sonuçlar elde etmek için oldukça faydalıdır.

Görüntüdeki gürültüleri azaltmak için kullanılan diğer bir fonksiyon da `cv2.medianBlur()` fonksiyonudur.

`cv2.medianBlur()` fonksiyonu, görüntüdeki her pikselin komşu pikselleri içerisindeki medyan değerini alarak yeni bir görüntü oluşturur. Bu yöntem özellikle görüntüdeki tuz-biber gürültüsü olarak bilinen ani siyah-beyaz noktaların azaltılmasında oldukça etkilidir.

Genel kullanım şekli şu şekildedir:
```
cv2.medianBlur(src, size)
```
Burada:
`src`, bulanıklaştırma uygulanacak görüntüdür.

`ksize`, filtre boyutunu ifade eder. Bu değer pozitif ve tek sayı olmalıdır.
Örneğin `3`, `5`, `7` gibi değerler kullanılabilir.

Aşağıdaki örnekte bir görüntüye Median Blur uygulanmıştır:
```python
import cv2
import matplotlib.pyplot as plt

img_bgr = cv2.imread("./images/bricks.jpg")

img_rgb = cv2.cvtColor(img_bgr, cv2.COLOR_BGR2RGB)

median_blurred = cv2.medianBlur(img_rgb, 5)

plt.figure(figsize=(12, 6))

plt.subplot(1, 2, 1)
plt.imshow(img_rgb)
plt.title("Original Image")
plt.axis("off")

plt.subplot(1, 2, 2)
plt.imshow(median_blurred)
plt.title("Median Blurred")
plt.axis("off")

plt.show()
```
`GaussianBlur()` ve `medianBlur()` fonksiyonları benzer amaçlarla kullanılsa da çalışma mantıkları farklıdır. GaussianBlur() komşu piksellere ağırlıklı ortalama uygularken, medianBlur() komşu pikseller arasındaki medyan değeri kullanır.

Kısaca, `medianBlur()` özellikle ani ve keskin gürültülerin azaltılmasında etkili bir yöntemdir.

## Image Enhancement(Görüntü İyileştirme)

Görüntü iyileştirme, görüntünün görsel kalitesini artırmak veya sonraki görüntü işleme adımları için daha uygun hale getirmek amacıyla uygulanan işlemleri ifade eder.

Benim tezimin de ana konularından biri olan görüntü iyileştirme için kullanılan çok sayıda farklı algoritma bulunmaktadır. Bu algoritmalar; parlaklık düzenleme, kontrast artırma, gürültü azaltma, keskinleştirme ve renk düzenleme gibi farklı amaçlarla kullanılabilir.

Görüntü iyileştirme için kullanılan temel yöntemlerden bazıları şunlardır:
```
Gaussian Blur
Median Blur
Gamma Correction
Histogram Equalization
Contrast Adjustment
Sharpening
Denoising
```
Bu yöntemlerden biri de Gamma Correction algoritmasıdır. Gamma Correction, görüntünün parlaklık değerlerini doğrusal olmayan bir şekilde düzenlemek için kullanılır. Özellikle çok karanlık veya çok parlak görüntülerde detayların daha görünür hale getirilmesine yardımcı olabilir.

Bu nedenle Gamma Correction, görüntü iyileştirme çalışmalarında sık kullanılan temel yöntemlerden biridir.
Aşağıdaki örnekte bir gamma correction kod örneği verilmiştir:
```python
import cv2
import numpy as np
import matplotlib.pyplot as plt

def load_img():
    img = cv2.imread("./images/bricks.jpg")

    if img is None:
        raise FileNotFoundError("Image could not be loaded.")

    img = img.astype(np.float32) / 255.0
    img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

    return img

def display_images(original, gamma_corrected):
    plt.figure(figsize=(12, 6))

    plt.subplot(1, 2, 1)
    plt.imshow(original)
    plt.title("Original Image")
    plt.axis("off")

    plt.subplot(1, 2, 2)
    plt.imshow(gamma_corrected)
    plt.title("Gamma Corrected Image")
    plt.axis("off")

    plt.show()

img = load_img()

gamma = 1 / 4

gamma_corrected_image = np.power(img, gamma)

display_images(img, gamma_corrected_image)
```

Yukarıdaki örnekte gamma değeri `1`den küçük olduğu için hedef görüntü daha aydınlık hale gelecektir.

Eğer gamma değeri `1`den büyük olursa görüntü daha koyu hale gelir.
```
gamma < 1  -> görüntüyü aydınlatır
gamma = 1  -> görüntü değişmez
gamma > 1  -> görüntüyü koyulaştırır
```
Bu nedenle düşük ışıklı görüntülerde genellikle `1`den küçük gamma değerleri tercih edilir. 
Örneğin `0.4`, `0.5` veya `0.8` gibi değerler karanlık görüntülerde parlaklığı artırmak için kullanılabilir.

## Brightness Detection / Görüntüde Parlaklık Tespiti

Daha önce de bahsedildiği gibi görüntüler piksellerden oluşur. 8-bit gri seviye görüntülerde piksel değerleri 0 ile 255 arasında değişir. Burada 0 siyaha, 255 ise beyaza karşılık gelir.

Bu nedenle bir görüntünün karanlık olup olmadığını anlamak için görüntü önce gri seviyeye dönüştürülebilir. Daha sonra gri seviye görüntüdeki piksel değerlerinin ortalaması hesaplanır. Ortalama parlaklık değeri düşükse görüntü karanlık kabul edilebilir.

Bu örnekte eşik değeri olarak 80 kullanılmıştır. Eğer ortalama parlaklık değeri 80den küçükse görüntü düşük ışıklı veya karanlık olarak değerlendirilebilir.

Aşağıdaki örnekte bir görüntünün ortalama parlaklık değerine göre karanlık olup olmadığı kontrol edilmiştir:
```python
import cv2
import numpy as np

img = cv2.imread("./images/night_road.jpg")

if img is None:
    raise FileNotFoundError("Image could not be loaded.")

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

mean_brightness = np.mean(gray)

print("Mean brightness:", mean_brightness)

if mean_brightness < 80:
    print("Image is dark.")
else:
    print("Image is not dark.")
```
Burada 'cv2.cvtColor()' fonksiyonu gri seviyeye dönüştürülmüştür.
Daha sonra `np.mean()` fonksiyonu ile gri seviye görüntünün ortalama 
piksel değeri hesaplanmıştır. Kısaca:
```
mean_brightness < 80 -> görüntü karanlık kabul edilebilir.
mean_brightness >= 80 -> görüntü aydınlık kabul edilmeyebilir.
```
Bu yöntem basit ve hızlıdır. Ancak yalnızca ortalama parlaklığa bakmak her 
zaman yeterli olmayabilir. Çünkü bazı görüntülerde küçük bir bölge çok parlakken
geri kalan büyük alan karanlık olabilir. Bu nedenle daha gelişmiş analizlerde
histogram veya karanlık piksel oranı gibi ek ölçütler de kullanılabilir.