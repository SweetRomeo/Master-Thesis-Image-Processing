# OpenCV C++ Notları

## Görüntü Okuma

OpenCV'de görüntü okuma C++ tarafında `cv::imread()` fonksiyonu kullanılarak yapılmaktadır.

```c++
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
```c++
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

```c++
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
```c++
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

```c++
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
```c++
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
```c++
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

Görüntü eşikleme, görüntü işlemede sık kullanılan temel tekniklerden biridir. Bu işlemde görüntüdeki piksel değerleri belirli bir eşik değerine göre sınıflandırılır.

Özellikle 8-bit gri seviye görüntülerde her pikselin değeri 0 ile 255 arasındadır. Eşikleme işleminde belirlenen bir eşik değerinin üstünde kalan pikseller genellikle beyaz, altında kalan pikseller ise siyah yapılır.

Bu yöntem sayesinde görüntüdeki belirli bölgeler daha belirgin hale getirilebilir. Aynı zamanda arka plan gibi önemsiz bölgeler bastırılarak ilgilenilen nesneler daha kolay analiz edilebilir.

OpenCV C++ tarafında eşikleme işlemi için cv::threshold() fonksiyonu kullanılır.

Genel kullanım şekli şu şekildedir:

cv::threshold(src, dst, threshold_value, max_value, threshold_type);

Burada:

src, eşikleme uygulanacak kaynak görüntüdür.

dst, eşikleme sonucunda oluşacak hedef görüntüdür.

threshold_value, eşik değeridir.

max_value, eşik değerinin üstünde kalan piksellere atanacak maksimum değerdir.

threshold_type, uygulanacak eşikleme türünü ifade eder.

Aşağıdaki örnekte bir görüntü okunmuş, gri seviyeye dönüştürülmüş ve ardından binary thresholding uygulanmıştır:
```c++
#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
cv::Mat img = cv::imread("./images/dog_backpack.jpg");

    if (img.empty()) {
        std::cout << "Image could not be loaded.\n";
        return -1;
    }

    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    cv::Mat thresholded;

    double used_threshold = cv::threshold(
        gray,
        thresholded,
        127,
        255,
        cv::THRESH_BINARY
    );

    std::cout << "Used threshold value: " << used_threshold << '\n';

    cv::imshow("Original Image", img);
    cv::imshow("Grayscale Image", gray);
    cv::imshow("Thresholded Image", thresholded);

    cv::waitKey(0);

    return 0;
}
```
Bu örnekte görüntü önce `cv::imread()` fonksiyonu ile okunmuştur. Daha sonra cv::cvtColor() fonksiyonu kullanılarak gri seviyeye dönüştürülmüştür.

cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

Eşikleme işlemi ise şu satırda yapılmıştır:
```
double used_threshold = cv::threshold(
gray,
thresholded,
127,
255,
cv::THRESH_BINARY
);
```
Burada 127 eşik değeridir. Piksel değeri 127den büyükse 255, küçük veya eşitse 0 yapılır.
```
Piksel değeri > 127  -> 255
Piksel değeri <= 127 -> 0
```
`cv::THRESH_BINARY` türünde görüntü siyah-beyaz bir yapıya dönüştürülür.

`cv::threshold()` fonksiyonu C++ tarafında kullanılan eşik değerini double türünde geri döndürür. Eşikleme sonucunda oluşan görüntü ise ikinci parametre olarak verilen thresholded değişkenine yazılır.

Kısaca, `cv::threshold()` fonksiyonu görüntüdeki piksel değerlerini belirli bir eşik değerine göre ayırmak ve daha belirgin bir siyah-beyaz görüntü elde etmek için kullanılır.

## Görüntü Bulanıklaştırma / Image Blurring

Görüntü bulanıklaştırma, görüntü işlemede sık kullanılan temel tekniklerden biridir. Bu işlemin temel amacı görüntüdeki keskin geçişleri yumuşatmak, küçük detayları azaltmak ve gürültüyü bastırmaktır.

Blurring işlemi; görüntü iyileştirme, yüz gizleme, arka plan bulanıklaştırma, nesne tespiti, thresholding ve edge detection gibi birçok alanda kullanılabilir.

Özellikle Canny Edge Detection ve Thresholding gibi işlemlerden önce görüntüdeki küçük gürültüleri azaltmak için bulanıklaştırma uygulanabilir. Böylece sonraki işlemler daha temiz sonuç verebilir.

OpenCV C++ tarafında görüntü bulanıklaştırma için sık kullanılan fonksiyonlardan biri `cv::GaussianBlur()` fonksiyonudur.

Genel kullanım şekli şu şekildedir:

```
cv::GaussianBlur(src, dst, ksize, sigmaX);
```

Burada:

`src`, bulanıklaştırma uygulanacak kaynak görüntüdür.

`dst`, bulanıklaştırma sonucunda oluşacak hedef görüntüdür.

`ksize`, kernel boyutunu ifade eder. Örneğin `cv::Size(5, 5)` değeri 5x5 boyutunda bir filtre kullanıldığını gösterir. Kernel boyutları genellikle pozitif ve tek sayı olmalıdır.

`sigmaX`, Gaussian fonksiyonunun X yönündeki standart sapma değeridir. Bu değer `0` verilirse OpenCV sigma değerini kernel boyutuna göre otomatik hesaplar.

Aşağıdaki örnekte bir görüntü okunmuş ve Gaussian Blur uygulanmıştır:

```c++
#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat img = cv::imread("./images/dog.jpg");

    if (img.empty()) {
        std::cout << "Image could not be loaded.\n";
        return -1;
    }

    cv::Mat blurred;

    cv::GaussianBlur(img, blurred, cv::Size(5, 5), 0);

    cv::imshow("Original Image", img);
    cv::imshow("Gaussian Blurred Image", blurred);

    cv::waitKey(0);

    return 0;
}
```

Bu örnekte `img` orijinal görüntüyü, `blurred` ise Gaussian Blur uygulanmış görüntüyü temsil eder.

```
cv::GaussianBlur(img, blurred, cv::Size(5, 5), 0);
```

Bu satırda görüntüye 5x5 boyutunda Gaussian filtre uygulanmıştır.

Kernel boyutu arttıkça bulanıklaştırma etkisi de artar. Örneğin:

```c++
cv::Mat blurred_5;
cv::Mat blurred_15;
cv::Mat blurred_31;

cv::GaussianBlur(img, blurred_5, cv::Size(5, 5), 0);
cv::GaussianBlur(img, blurred_15, cv::Size(15, 15), 0);
cv::GaussianBlur(img, blurred_31, cv::Size(31, 31), 0);
```

Burada `cv::Size(31, 31)` değeri, `cv::Size(5, 5)` değerine göre daha güçlü bir bulanıklaştırma etkisi oluşturur.

Görüntü bulanıklaştırma için kullanılan bir diğer fonksiyon da `cv::medianBlur()` fonksiyonudur.

Genel kullanım şekli şu şekildedir:

```
cv::medianBlur(src, dst, ksize);
```

`cv::medianBlur()` fonksiyonu, her pikselin komşu pikselleri içerisindeki medyan değeri alarak yeni bir görüntü oluşturur. Bu yöntem özellikle görüntüdeki ani siyah-beyaz noktaların, yani tuz-biber gürültüsünün azaltılmasında etkilidir.

Aşağıdaki örnekte aynı görüntüye Median Blur uygulanmıştır:

```c++
#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat img = cv::imread("./images/dog.jpg");

    if (img.empty()) {
        std::cout << "Image could not be loaded.\n";
        return -1;
    }

    cv::Mat median_blurred;

    cv::medianBlur(img, median_blurred, 5);

    cv::imshow("Original Image", img);
    cv::imshow("Median Blurred Image", median_blurred);

    cv::waitKey(0);

    return 0;
}
```

Burada:

```cpp
cv::medianBlur(img, median_blurred, 5);
```

satırı, görüntüye 5 boyutlu Median Blur filtresi uygular.

`GaussianBlur()` ve `medianBlur()` fonksiyonları benzer amaçlarla kullanılsa da çalışma mantıkları farklıdır. `GaussianBlur()` komşu piksellere ağırlıklı ortalama uygular. `medianBlur()` ise komşu pikseller arasındaki medyan değeri kullanır.

Kısaca, `cv::GaussianBlur()` görüntüyü yumuşatmak ve gürültüyü azaltmak için kullanılır. `cv::medianBlur()` ise özellikle ani ve keskin gürültülerin azaltılmasında etkili bir yöntemdir.

## Görüntü İyileştirme / Image Enhancement

Görüntü iyileştirme, görüntünün görsel kalitesini artırmak veya sonraki görüntü işleme adımları için daha uygun hale getirmek amacıyla uygulanan işlemleri ifade eder.

OpenCV C++ tarafında da parlaklık düzenleme, kontrast artırma, gürültü azaltma, keskinleştirme ve renk düzenleme gibi birçok görüntü iyileştirme işlemi yapılabilir.

Görüntü iyileştirme için kullanılan temel yöntemlerden bazıları şunlardır:

```text
Gaussian Blur
Median Blur
Gamma Correction
Histogram Equalization
Contrast Adjustment
Sharpening
Denoising
```

Bu yöntemlerden biri de Gamma Correction algoritmasıdır. Gamma Correction, görüntüdeki parlaklık değerlerini doğrusal olmayan bir şekilde düzenlemek için kullanılır.

Özellikle düşük ışıklı veya karanlık görüntülerde detayların daha görünür hale getirilmesine yardımcı olabilir.

Gamma Correction işleminin temel mantığı şu şekildedir:

```text
output = image ^ gamma
```

Bu işlem uygulanmadan önce görüntünün genellikle `0-1` aralığına normalize edilmesi tercih edilir. Çünkü piksel değerleri normalde `0-255` aralığındadır. Normalize edildiğinde matematiksel işlem daha kontrollü yapılabilir.

C++ tarafında Gamma Correction işlemi için `cv::pow()` fonksiyonu kullanılabilir.

Aşağıdaki örnekte bir görüntü okunmuş, `0-1` aralığına normalize edilmiş, Gamma Correction uygulanmış ve tekrar `0-255` aralığına dönüştürülmüştür:

```c++
#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat img = cv::imread("./images/bricks.jpg");

    if (img.empty()) {
        std::cout << "Image could not be loaded.\n";
        return -1;
    }

    cv::Mat img_float;

    img.convertTo(img_float, CV_32F, 1.0 / 255.0);

    double gamma = 1.0 / 4.0;

    cv::Mat gamma_corrected_float;

    cv::pow(img_float, gamma, gamma_corrected_float);

    cv::Mat gamma_corrected;

    gamma_corrected_float.convertTo(gamma_corrected, CV_8U, 255.0);

    cv::imshow("Original Image", img);
    cv::imshow("Gamma Corrected Image", gamma_corrected);

    cv::waitKey(0);

    return 0;
}
```

Burada görüntü önce `cv::imread()` fonksiyonu ile okunmuştur.

```cpp
cv::Mat img = cv::imread("./images/bricks.jpg");
```

Daha sonra görüntü `0-255` aralığından `0-1` aralığına dönüştürülmüştür:

```cpp
img.convertTo(img_float, CV_32F, 1.0 / 255.0);
```

Bu işlemde `CV_32F`, görüntünün 32-bit float türüne dönüştürüleceğini ifade eder. `1.0 / 255.0` katsayısı ise piksel değerlerini normalize etmek için kullanılır.

Gamma değeri şu şekilde belirlenmiştir:

```cpp
double gamma = 1.0 / 4.0;
```

Bu örnekte gamma değeri `1`den küçük olduğu için görüntü daha aydınlık hale gelir.

Gamma Correction işlemi şu satırda uygulanmıştır:

```cpp
cv::pow(img_float, gamma, gamma_corrected_float);
```

Bu işlemden sonra görüntü hâlâ `0-1` aralığındadır. Bu yüzden tekrar `0-255` aralığına dönüştürülür:

```cpp
gamma_corrected_float.convertTo(gamma_corrected, CV_8U, 255.0);
```

Kısaca:

```text
gamma < 1  -> görüntüyü aydınlatır
gamma = 1  -> görüntü değişmez
gamma > 1  -> görüntüyü koyulaştırır
```

Bu nedenle düşük ışıklı görüntülerde genellikle `1`den küçük gamma değerleri tercih edilir. Örneğin `0.4`, `0.5` veya `0.8` gibi değerler karanlık görüntülerde parlaklığı artırmak için kullanılabilir.

Aşağıdaki örnekte farklı gamma değerleri denenmiştir:

```cpp
double gamma1 = 0.5;
double gamma2 = 1.0;
double gamma3 = 2.0;
```

Burada `0.5` görüntüyü aydınlatır, `1.0` görüntüyü değiştirmez, `2.0` ise görüntüyü koyulaştırır.

Gamma Correction özellikle otonom araç görüntülerinde düşük ışık, gece sürüşü, tünel içi görüntüler veya gölgeli yol sahneleri gibi durumlarda kullanılabilir.

## Görüntüde Parlaklık Tespiti / Brightness Detection

Bir görüntüye Gamma Correction gibi görüntü iyileştirme algoritmaları uygulamadan önce, görüntünün gerçekten karanlık olup olmadığını anlamak faydalıdır. Böylece iyileştirme işlemi rastgele değil, görüntünün parlaklık durumuna göre uygulanmış olur.

8-bit gri seviye görüntülerde piksel değerleri `0` ile `255` arasında değişir. Burada `0` siyaha, `255` ise beyaza karşılık gelir. Bu nedenle bir görüntünün karanlık olup olmadığını anlamak için görüntü önce gri seviyeye dönüştürülebilir ve ardından ortalama piksel değeri hesaplanabilir.

OpenCV C++ tarafında ortalama parlaklık değerini hesaplamak için `cv::mean()` fonksiyonu kullanılabilir.

Aşağıdaki örnekte bir görüntünün ortalama parlaklık değeri hesaplanmış ve bu değere göre görüntünün karanlık olup olmadığı kontrol edilmiştir:

```c++
#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat img = cv::imread("./images/night_road.jpg");

    if (img.empty()) {
        std::cout << "Image could not be loaded.\n";
        return -1;
    }

    cv::Mat gray;

    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    cv::Scalar mean_value = cv::mean(gray);

    double mean_brightness = mean_value[0];

    std::cout << "Mean brightness: " << mean_brightness << '\n';

    if (mean_brightness < 80) {
        std::cout << "Image is dark.\n";
    }
    else {
        std::cout << "Image is not dark.\n";
    }

    cv::imshow("Original Image", img);
    cv::imshow("Grayscale Image", gray);

    cv::waitKey(0);

    return 0;
}
```

Bu örnekte görüntü önce `cv::imread()` fonksiyonu ile okunmuştur. Daha sonra `cv::cvtColor()` fonksiyonu ile gri seviyeye dönüştürülmüştür.

```cpp
cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
```

Ortalama parlaklık değeri ise şu satırda hesaplanmıştır:

```cpp
cv::Scalar mean_value = cv::mean(gray);
```

`cv::mean()` fonksiyonu görüntünün ortalama piksel değerini döndürür. Gri seviye görüntü tek kanallı olduğu için parlaklık değeri `mean_value[0]` üzerinden alınır.

```cpp
double mean_brightness = mean_value[0];
```

Bu örnekte eşik değeri olarak `80` kullanılmıştır.

```text
mean_brightness < 80  -> görüntü karanlık kabul edilebilir
mean_brightness >= 80 -> görüntü karanlık kabul edilmeyebilir
```

Bu yöntem basit ve hızlıdır. Ancak yalnızca ortalama parlaklığa bakmak her zaman yeterli olmayabilir. Çünkü bazı görüntülerde küçük bir bölge çok parlakken, geri kalan büyük alan karanlık olabilir. Bu nedenle daha gelişmiş çalışmalarda histogram analizi veya karanlık piksel oranı gibi ek ölçütler de kullanılabilir.

Bu parlaklık tespiti, Gamma Correction ile birlikte kullanılabilir. Örneğin görüntü karanlık ise gamma değeri `1`den küçük seçilerek görüntü daha aydınlık hale getirilebilir.

```cpp
if (mean_brightness < 80) {
    std::cout << "Gamma Correction can be applied.\n";
}
```

Kısaca, parlaklık tespiti görüntünün düşük ışıklı olup olmadığını anlamak için kullanılabilir. Bu sayede görüntü iyileştirme algoritmaları daha bilinçli ve kontrollü bir şekilde uygulanabilir.

## OpenCV'de Kamera İşlemleri

OpenCV'de kameradan görüntü okuma işlemi, gerçek zamanlı görüntü işleme uygulamalarında sıkça kullanılan temel işlemlerden biridir. Bu işlem için OpenCV'nin `cv::VideoCapture` sınıfı kullanılır.

Kamerayı açmak için `cv::VideoCapture` türünden bir nesne oluşturulur. Aşağıdaki örnekte `0` değeri kullanılmıştır:

```cpp
cv::VideoCapture cap(0);
```

Buradaki `0`, bilgisayardaki varsayılan kamerayı ifade eder. Eğer harici bir kamera kullanılacaksa bazı sistemlerde `1`, `2` gibi farklı indeksler denenebilir.

Kamera başarıyla açılıp açılmadığını kontrol etmek için `isOpened()` fonksiyonu kullanılır:

```c++
if (!cap.isOpened()) {
    std::cerr << "Unable to open camera\n";
    return -1;
}
```

Kameradan gelen görüntüler OpenCV'de `cv::Mat` nesnesi içinde tutulur. Her döngüde kameradan yeni bir frame okunur ve bu frame üzerinde görüntü işleme işlemleri yapılabilir.

Aşağıdaki örnekte kameradan sürekli görüntü alınmakta, alınan görüntü gri tona çevrilmekte ve ekranda gösterilmektedir:

```c++
#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    cv::VideoCapture cap(0);

    if (!cap.isOpened()) {
        std::cerr << "Unable to open camera\n";
        return -1;
    }

    int width = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH));
    int height = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT));

    std::cout << "Camera resolution: " << width << "x" << height << '\n';

    cv::Mat frame;
    cv::Mat img_gray;

    while (true) {
        cap >> frame;

        if (frame.empty()) {
            std::cerr << "Empty frame received\n";
            break;
        }

        cv::cvtColor(frame, img_gray, cv::COLOR_BGR2GRAY);

        cv::imshow("Gray Camera", img_gray);

        if ((cv::waitKey(1) & 0xFF) == 'q') {
            break;
        }
    }

    cap.release();
    cv::destroyAllWindows();

    return 0;
}
```

### Kodun Açıklaması

```cpp
cv::VideoCapture cap(0);
```

Varsayılan kamerayı açar.

```cpp
cap >> frame;
```

Kameradan bir görüntü karesi okur ve `frame` değişkenine aktarır.

```cpp
if (frame.empty())
```

Kameradan görüntü okunamazsa programın hata vermemesi için kontrol yapılır.

```cpp
cv::cvtColor(frame, img_gray, cv::COLOR_BGR2GRAY);
```

Kameradan gelen renkli görüntüyü gri tonlamalı görüntüye çevirir.

```cpp
cv::imshow("Gray Camera", img_gray);
```

Gri tonlamalı görüntüyü ekranda gösterir.

```cpp
if ((cv::waitKey(1) & 0xFF) == 'q')
```

Her kareden sonra 1 milisaniye bekler ve klavyeden `q` tuşuna basılıp basılmadığını kontrol eder. `q` tuşuna basılırsa döngü sonlanır.

```cpp
cap.release();
cv::destroyAllWindows();
```

Kamera serbest bırakılır ve OpenCV tarafından açılan tüm pencereler kapatılır.

Bu yapı, gerçek zamanlı görüntü işleme uygulamalarının temelini oluşturur. Kameradan alınan `frame` üzerinde gri tonlama dışında bulanıklaştırma, kenar tespiti, eşikleme, yüz tespiti veya nesne algılama gibi farklı işlemler de uygulanabilir.
