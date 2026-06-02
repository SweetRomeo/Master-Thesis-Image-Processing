# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
import cv2

image = cv2.imread("./images/dog.jpg")

while True:
    cv2.imshow("Puppy", image)

    # If we've waited at least 1 ms, and we've pressed the esc
    if cv2.waitKey(1) & 0xFF == 27:
        break

cv2.destroyAllWindows()