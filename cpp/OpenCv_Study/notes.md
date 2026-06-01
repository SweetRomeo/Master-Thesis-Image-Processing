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