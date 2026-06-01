# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
import cv2

image = cv2.imread("./images/dog.jpg")

if image is None:
    image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

cv2.imshow("Image", image)
cv2.waitKey(0)