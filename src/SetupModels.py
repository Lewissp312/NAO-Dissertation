import torch
import timm
import cv2

print(torch)
if torch.backends.mps.is_available():
    device = torch.device("mps")
    print('device is mps')
else:
    device = torch.device("cpu")
        
# # Load the MiDaS model
# midas = torch.hub.load("intel-isl/MiDaS", "DPT_Large")
# midas.to(device)
# midas.eval()
# # Load transforms to resize and normalize the image
# transforms = torch.hub.load("intel-isl/MiDaS", "transforms")
# transform = transforms.small_transform
# img = cv2.imread("NAO-setup.png")
# img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
# print(f"Img type: {type(img)}")
# print(f"img:\n{img}")
# input_batch = transform(img).to(device)
# print(f"Input batch type: {type(input_batch)}")
# print(f"Input batch:\n{input_batch}")
# prediction = midas(input_batch)
# print(f"Prediction type: {type(prediction)}")
# cv2.imshow("Image",input_batch)
# cv2.waitKey(500);
