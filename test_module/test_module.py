import cv2
import numpy as np
import dlib

class faceDectector:
    def __init__(self,xml_path):
        self.face_casecade = cv2.CascadeClassifier(xml_path)

    def detect(self,img):
        gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
        faces = self.face_casecade.detectMultiScale(gray,1.3,5) 
        points = None
        return faces, points
   

def draw_faces(img, faces):
    ans = img.copy()
    for (x,y,w,h) in faces:
        ans=cv2.rectangle(ans,(x,y),(x+w,y+h),(255,0,0),2)
    return ans

def draw_points(img,points):
    pass





if __name__=='__main__':
    #face_dectector = faceDectector(r'D:\software\anaconda3\envs\py36_cv3\Lib\site-packages\cv2\data\haarcascade_frontalface_default.xml')

    yun = cv2.imread(r'C:\Users\feon\Desktop\yun2.jpg')


    

    #yuan = cv2.imread(r'C:\Users\feon\Desktop\yun.jpg')

    #yun_faces,yun_points = face_dectector.detect(yun)

    #f_yun = draw_faces(yun,yun_faces)
    

    #gray_yun = cv2.cvtColor(yun,cv2.COLOR_BGR2GRAY)
    #faces=face_casecade.detectMultiScale(gray_yun,1.3,5)   
    #for (x,y,w,h) in faces:
    #    yun=cv2.rectangle(yun,(x,y),(x+w,y+h),(255,0,0),2)

    detector = dlib.get_frontal_face_detector()
    predictor = dlib.shape_predictor(r'D:\software\anaconda3\envs\py36_cv3\data\shape_predictor_68_face_landmarks.dat')
    img = dlib.load_rgb_image(r'C:\Users\feon\Desktop\yuan.jpg')
    dets = detector(img, 1)
    shape = predictor(img,dets[0])
    #dlib.full_object_detection
    print(dlib.points)
    for i, d in enumerate(dets):
        yun=cv2.rectangle(yun,(d.left(), d.top()),(d.right(), d.bottom()),(255,0,0),2)
    for p in shape.parts():
        x = p.x
        y = p.y
        yun = cv2.circle(yun,(x,y),3,(0,0,255),1,1)


    cv2.imshow('yun',yun)

    cv2.waitKey(0)

