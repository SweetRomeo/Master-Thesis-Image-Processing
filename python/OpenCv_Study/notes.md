# OpenCV Python Notları

## Görüntü Okuma

OpenCV'de görüntü okuma Python tarafında `cv2.imread()` fonksiyonu kullanılarak yapılmaktadır.

```python
import cv2

image = cv2.imread('./images/dog.jpg')

if image is None:
    print('Görüntü açılamadı.')
else:
    print('Görüntü başarılıyla açıldı.')
```

## Görüntü Gösterme

OpenCV'de görüntü gösterme Python tarafında `cv2.imshow()` fonksiyonu kullanılarak yapılmaktadır.

```python
import cv2

image = cv2.imread('./images/dog.jpg')

if image is None:
    print("Görüntü açılamadı.")
else:
    print("Görüntü başarıyla açıldı.")

cv2.imshow("Image", image)
cv2.waitKey(0)
```

Yukarıdaki kodda waitKey fonksiyonunun kullanılma sebebi görüntünün görünüp kaybolmasını engellemektir.
cv2.imshow fonksiyonu iki parametre alır ve ilk parametre açılan pop-up görüntüsünün ismini ifade ederken
diğer parametre görüntü değişkenini ister.

## Görüntü Ölçeklendirme

Python'da 