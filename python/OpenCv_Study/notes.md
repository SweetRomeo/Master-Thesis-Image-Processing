# OpenCV Python Notları

## Görüntü Okuma

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

## Görüntü Gösterme

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

## Görüntü Ölçeklendirme

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

## Görüntüyü Ters Çevirme

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

## Color Spaces and Color Conversions

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

## Görüntü Oluşturma

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

## Görüntü Eşikleme(Thresholding)

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

## Image Blurring(Görüntü Bulanıklaştırma)

