# Author: Ruben Rehal

import cv2

print("Starting Calorify Food Detection...")

cap = cv2.VideoCapture(0)
if not cap.isOpened():
    print("Webcam not accessible.")
    exit()

while True:
    ret, frame = cap.read()
    if not ret:
        break

    cv2.putText(frame, "Detecting food item...", (20, 30),
                cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)

    cv2.rectangle(frame, (100, 100), (300, 300), (255, 0, 0), 2)
    cv2.imshow("Calorify Detection", frame)
    if cv2.waitKey(1) & 0xFF == 27:
        break

cap.release()
cv2.destroyAllWindows()
