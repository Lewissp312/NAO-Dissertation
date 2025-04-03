#ifndef NAOCONNECTION_CPP
#define NAOCONNECTION_CPP
#include "NaoConnection.h"


void NaoConnection::getFrames(){
    this->motionProxy.setAngles(this->names,this->angles,this->fractionMaxSpeed);
    this->motionProxy.stiffnessInterpolation(this->names,this->pStiffnessLists, this->pTimeLists);

    std::string videoClient = this->camProxy.subscribeCamera("C++-client",0,this->resolution,this->colorSpace,1);
    AL::ALValue naoImage = this->camProxy.getImageRemote(videoClient);
    this->camProxy.unsubscribe(videoClient);

    this->backlightingDetectionProxy.subscribe("testBacklighting");
    int backlightingStatus = this->memoryProxy.getData("BacklightingDetection/BacklightingValue");

    // Start the darkness detection
    this->darknessDetectionProxy.subscribe("darknessDetection");
    int darknessValue = this->memoryProxy.getData("DarknessDetection/DarknessValue");

    // Details of the image fetched from the NAO, including an array of its pixel values
    int imageWidth = naoImage[0];
    int imageHeight = naoImage[1];
    uchar* imageByteData = (uchar*) naoImage[6].GetBinary();
    cv::Mat imgHeader = cv::Mat(cv::Size(imageWidth, imageHeight), CV_8UC3, imageByteData);

    //Gives back the image buffer to the driver
    this->camProxy.releaseImage(videoClient);

    //Display the image on screen
    cv::resizeWindow("NAO unenhanced picture", 300, 700); 
    cv::imshow("NAO unenhanced picture", imgHeader);
    cv::waitKey(500);
}

#endif
