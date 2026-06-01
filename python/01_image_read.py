import cv2

image = cv2.imread("test.jpg")

if image is None:
   print("Görüntü okunamadı")
else: 
  print("Görüntü başarıyla okundu")
