import matplotlib.pyplot as plt
import cv2
import numpy as np

# Constants for equilateral shape
DRONE_COUNT = 18
LENGTH = 10

# Put img path here
IMAGE = cv2.imread('heart.png')

def get_equil_corners(drone_count, length):

    # Calculating angles
    angles = np.linspace(0, 
                         2 * np.pi, 
                         drone_count, 
                         endpoint=False)

    # Calculating corner coordinate
    x = length * np.cos(angles)
    y = length * np.sin(angles)

    # Merge coordinate
    corners = np.column_stack((x, y))

    # For visualization can commented out
    x, y = zip(*corners[:,:])
    plt.scatter(x, y, c='r')
    plt.axhline(0, color='black', lw=0.2)
    plt.axvline(0, color='black', lw=0.2)
    plt.show()
    
    # Return corner cordinates
    return corners

def get_image_corners(img, drone_count):

    # Make image gray
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        
    # Smoothing image
    blur = cv2.GaussianBlur(gray, (5,5), 1)
    
    # Find corner coordinates
    corners = cv2.goodFeaturesToTrack(blur, 
                                      qualityLevel=0.001, 
                                      minDistance=5,
                                      corners=drone_count, 
                                      maxCorners=drone_count, 
                                      mask=None
                                      ).astype(int
                                      ).reshape(drone_count,2)

    # Normalize corner coordinates to origin
    corners = normalizeCorners(corners, 
                               img.shape[0], 
                               img.shape[1])

    # For visualization can commented out
    x, y = zip(*corners[:,:])
    plt.scatter(x, y, c='r')
    plt.axhline(0, color='black', lw=0.2)
    plt.axvline(0, color='black', lw=0.2)
    plt.show()

    # Return Corner Coordinates
    return corners

def normalizeCorners(corners, H, W):
    corners[:,0] -= W // 2
    corners[:,1] -= H // 2
    corners[:,1] = -corners[:,1]
    return corners

#get_equil_corners(DRONE_COUNT, LENGTH)
get_image_corners(IMAGE, DRONE_COUNT)

    