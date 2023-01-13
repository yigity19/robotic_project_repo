import matplotlib.pyplot as plt
import cv2
import numpy as np

# Constants for equilateral shape
DRONE_COUNT = 40
LENGTH = 10

# Put img path here
IMAGE = cv2.imread('flag.png')

def get_equilateral_corners(drone_count, length):

    # Calculating angles
    angles = np.linspace(0, 2 * np.pi, drone_count, endpoint=False)

    # Calculating points
    x = length * np.cos(angles)
    y = length * np.sin(angles)

    # Merge points
    corners = np.column_stack((x, y))

    # For visualization can commented out
    x, y = zip(*corners)
    plt.scatter(x, y)
    plt.show()

    return corners

def get_image_corners(img, drone_count):
    if img is None:
        print("Image not found or not in the correct format")
        return    

    # Make Image Gray
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        
    # Smoothing Image
    blur = cv2.GaussianBlur(gray, (5,5), 1)

    # Find Corners
    corners = cv2.goodFeaturesToTrack(blur, 
                                      qualityLevel=0.001, 
                                      minDistance=5,
                                      corners=drone_count, 
                                      maxCorners=drone_count, 
                                      mask=None)
    corners = corners.astype(int)
    corners = normalizeImage(corners, img.shape[0], img.shape[1])
    print(corners.shape)
    corners = corners.reshape(corners.shape[0], corners.shape[2])
    # Normalizing corners

    # For visualization can commented out
    x, y = zip(*corners[:,:])
    plt.scatter(x, y)
    plt.xlabel('X-axis')
    plt.ylabel('Y-axis')
    plt.show()

    # Return corners
    return corners

def normalizeImage(corners, H, W):
    corners[:, 0, 0] -= W // 2
    corners[:, 0, 1] -= H // 2
    return corners

#get_equilateral_corners(DRONE_COUNT, LENGTH)
get_image_corners(IMAGE, DRONE_COUNT)

    