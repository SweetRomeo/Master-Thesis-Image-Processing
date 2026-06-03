# OpenCV C++ Notları

## Görüntü Okuma

OpenCV'de görüntü okuma C++ tarafında `cv::imread()` fonksiyonu kullanılarak yapılmaktadır.

```cpp
#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    cv::Mat image = cv::imread("../images/test.jpg");

    if (image.empty())
    {
        std::cout << "Görüntü okunamadı." << std::endl;
        return -1;
    }

    std::cout << "Görüntü başarıyla okundu." << std::endl;

    return 0;
}
```

`cv::imread()` fonksiyonu temel olarak dosya yolunu parametre olarak alır. İsteğe bağlı olarak ikinci parametre ile görüntünün hangi formatta okunacağı belirtilebilir.

## Görüntü Gösterme

C++'ta görüntü gösterme `cv::imshow()` fonksiyonu kullanılarak yapılır.

Bu işlemi yapan C++ kodu aşağıdaki gibidir:
```cpp
#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat image = cv::imread("../images/dog.jpg");

    if (image.empty()) {
        std::cout << "Cannot open/read dog.jpg\n";
        return -1;
    }

    cv::imshow("Image Window", image);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
```

`cv::imshow()` fonksiyonu görüntüyü bir pencere içinde gösterir.  
`cv::waitKey(0)` kullanılmazsa pencere hemen kapanabilir.

## Görüntü Ölçeklendirme

C++'ta görüntü ölçeklendirme `cv::resize()` fonksiyonu kullanılarak yapılmaktadır.

```cpp
#include <iostream>
#include <filesystem>
#include <opencv2/opencv.hpp>

int main()
{
    std::cout << "Working directory: "
              << std::filesystem::current_path()
              << "\n";

    cv::Mat image = cv::imread("../images/dog.jpg");

    if (image.empty()) {
        std::cout << "Cannot open/read dog.jpg\n";
        return -1;
    }

    cv::imshow("Original Image", image);
    cv::waitKey(0);

    cv::Mat resizedImage;

    // Görseli 800x500 boyutuna getirir
    cv::resize(image, resizedImage, cv::Size(800, 500));

    cv::imshow("Resized Image", resizedImage);
    cv::waitKey(0);

    cv::imwrite("../outputs/resized_dog.jpg", resizedImage);

    cv::destroyAllWindows();

    return 0;
}
```

`cv::resize()` fonksiyonunun temel kullanımında kaynak görüntü, hedef görüntü ve hedef boyut parametreleri verilir.
Burada `cv::Size(800, 500)` ifadesinde ilk değer genişliği, ikinci değer yüksekliği ifade eder.

## Görüntüyü Ters Çevirme

C++'ta resmi ters çevirme işlemi `cv::flip()` fonksiyonu kullanılarak yapılmaktadır.
```cpp
#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat image = cv::imread("../images/dog.jpg");

    if (image.empty()) {
        std::cout << "Cannot open/read dog.jpg\n";
        return -1;
    }

    cv::Mat flippedVertical;
    cv::Mat flippedHorizontal;
    cv::Mat flippedBoth;

    // Dikey çevirme
    cv::flip(image, flippedVertical, 0);

    // Yatay çevirme
    cv::flip(image, flippedHorizontal, 1);

    // Hem yatay hem dikey çevirme
    cv::flip(image, flippedBoth, -1);

    cv::imshow("Original Image", image);
    cv::imshow("Flipped Vertical", flippedVertical);
    cv::imshow("Flipped Horizontal", flippedHorizontal);
    cv::imshow("Flipped Both", flippedBoth);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
```

Burada yorum satırında da belirtildiği üzere:
```
0   -> dikey çevirir
1   -> yatay çevirir
-1  -> hem yatay hem dikey çevirir
```
şeklindedir.

## Color Spaces and Color Conversions

Bir görüntünün en önemli özelliklerinden biri renk bilgisidir. OpenCV ile görüntüler üzerinde çalışırken renk kanallarının sırasını doğru anlamak gerekir.

OpenCV'de `cv::imread()` fonksiyonu ile okunan renkli görüntüler varsayılan olarak `BGR` formatında tutulur.
Yani kanal sırası şu şekildedir:

```
Blue - Green - Red
```

Bu durum OpenCV'nin hem Python hem de C++ tarafında geçerlidir. Ancak C++ tarafında görüntü gösterme işlemi genellikle cv::imshow() fonksiyonu ile yapıldığı için, BGR formatındaki görüntü doğrudan doğru renklerle gösterilir.

Yani C++ tarafında şu kullanım doğrudur:
```
cv::imshow("Image", img_bgr);
```
Buna rağmen bazı durumlarda görüntüyü farklı renk uzaylarına dönüştürmek gerekebilir. Örneğin:

- `BGR` formatından RGB formatına dönüştürme
- `BGR` formatından Grayscale formatına dönüştürme
- `BGR` formatından HSV formatına dönüştürme

OpenCV'de bu dönüşümler için `cv::cvtColor()` fonksiyonu kullanılır.

Aşağıdaki örnekte bir görüntü okunmuş, ardından farklı renk uzaylarına dönüştürülmüştür:

```cpp
#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img_bgr = cv::imread("./images/dog.jpg");
    if (img_bgr.empty()) {
        std::cout << "Image could not be loaded.\n";
        return -1;
    }
    cv::Mat img_rgb;
    cv::Mat img_gray;
    cv::Mat img_hsv;
    cv::cvtColor(img_bgr, img_rgb, cv::COLOR_BGR2RGB);
    cv::cvtColor(img_bgr, img_gray, cv::COLOR_BGR2GRAY);
    cv::cvtColor(img_bgr, img_hsv, cv::COLOR_BGR2HSV);
    cv::imshow("Original BGR Image", img_bgr);
    cv::imshow("Grayscale Image", img_gray);
    cv::imshow("HSV Image", img_hsv);
    cv::waitKey(0);
    return 0;
}
```

Burada `cv::cvtColor()` fonksiyonu görüntüyü bir renk formatından başka bir renk formatına dönüştürmek için kullanılır.

Genel kullanım şekli şu şekildedir:
```
cv::cvtColor(source, destination, conversion_code);
```
Örneğin:
```
cv::cvtColor(img_bgr, img_gray, cv::COLOR_BGR2GRAY);
```
Bu satırda `img_bgr` isimli BGR formatındaki görüntü gri seviye görüntüye dönüştürülür ve sonuç `img_gray` değişkeninde saklanır.

Benzer şekilde:
```
cv::cvtColor(img_bgr, img_rgb, cv::COLOR_BGR2RGB);
```
Bu satırda görüntü `BGR` formatından `RGB` formatına çevrilir. Ancak C++ tarafında `cv::imshow()` kullanırken genellikle RGB formatına çevirmeye gerek yoktur. Çünkü `cv::imshow()` OpenCV'nin kendi görüntü gösterme fonksiyonudur ve `BGR` formatındaki görüntüyü doğru şekilde gösterir.

Kısaca, OpenCV C++ tarafında görüntüler varsayılan olarak BGR formatında tutulur. Görüntüyü farklı renk uzaylarına çevirmek için `cv::cvtColor()` fonksiyonu kullanılır.

## Görüntü Kaydetme / Image Saving

OpenCV ile okunan veya üzerinde işlem yapılan görüntüler dosya olarak kaydedilebilir. C++ tarafında bunun için cv::imwrite() fonksiyonu kullanılır.

Bu fonksiyon, cv::Mat türündeki görüntüyü belirtilen dosya yoluna kaydeder.

Aşağıdaki örnekte bir görüntü okunmuş ve `outputs` klasörü içerisine farklı bir isimle kaydedilmiştir:
```cpp
#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat img = cv::imread("./images/dog.jpg");

    if (img.empty()) {
        std::cout << "Image could not be loaded.\n";
        return -1;
    }

    bool img_saved = cv::imwrite("./outputs/dog_saved.jpg", img);

    if (img_saved) {
        std::cout << "Image saved successfully.\n";
    }
    else {
        std::cout << "Error occurred while saving the file.\n";
    }

    return 0;
}
```
Burada `cv::imread()` fonksiyonu ile görüntü okunmuştur. Görüntünün başarılı şekilde okunup okunmadığı `img.empty()` kontrolü
ile test edilmiştir.
```cpp
if (img.empty()) {
    std::cout << "Image could not be loaded.\n";
    return -1;
}
```
Daha sonra `cv::imwrite()` fonksiyonu ile görüntü dosyaya kaydedilmiştir.
```
bool img_saved = cv::imwrite("./outputs/dog_saved.jpg", img);
```
`cv::imwrite` fonksiyonu kaydetme işlemi başarılı olursa `true`, başarısız olursa `false` değerini
döndürür.

Genel kullanım şu şekildedir:
```
cv::imwrite(file_path, image);
```
Burada `file_path`, görüntünün kaydedileceği dosya yolunu ifade eder. `image` ise kaydedilecek `cv::Mat` nesnesidir.

Dikkat edilmesi gereken noktalardan biri, görüntünün kaydedileceği klasörün önceden oluşturulmuş olmasıdır. Örneğin `outputs` klasörü mevcut değilse kaydetme işlemi başarısız olabilir.

Kısaca, `cv::imwrite()` fonksiyonu OpenCV C++ tarafında görüntüyü dosyaya kaydetmek için kullanılan temel fonksiyonlardan biridir.

## Görüntü Eşikleme / Image Thresholding

Görüntü eşikleme 