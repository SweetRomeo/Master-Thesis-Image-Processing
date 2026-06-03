# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
import cv2
import numpy as np
import matplotlib.pyplot as plt

def load_img():
    img = cv2.imread("./images/bricks.jpg").astype(np.float32) / 255
    img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    return img

def display_img(img):
    fig = plt.figure(figsize=(12, 10))
    ax = fig.add_subplot(111)
    ax.imshow(img)

img = load_img()
display_img(img)
gamma = 1 / 4
gammaCorrectedImage = np.power(img, gamma)
display_img(gammaCorrectedImage)
cv2.destroyAllWindows()