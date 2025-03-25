#ifndef NAOCONNECTION_CPP
#define NAOCONNECTION_CPP
#include "NaoConnection.h"


void NaoConnection::getFrames(){
    // int puzzleReq = 0;
    // int blCounter = 0;

    // while (true){
    //     this->motionProxy.setAngles(this->names,this->angles,this->fractionMaxSpeed);
    //     this->motionProxy.stiffnessInterpolation(this->names,this->pStiffnessLists, this->pTimeLists);

    //     std::string videoClient = this->camProxy.subscribeCamera("C++-client",0,this->resolution,this->colorSpace,1);
    //     AL::ALValue naoImage = this->camProxy.getImageRemote(videoClient);
    //     this->camProxy.unsubscribe(videoClient);

    //     this->backlightingDetectionProxy.subscribe("testBacklighting");
    //     int backlightingStatus = this->memoryProxy.getData("BacklightingDetection/BacklightingValue");
    //     // std::cout << "Current backlighting status: " << backlighting_status << std::endl;

    //     // Start the darkness detection
    //     this->darknessDetectionProxy.subscribe("darknessDetection");
    //     int darknessValue = this->memoryProxy.getData("DarknessDetection/DarknessValue");
    //     // std::cout << "Current darkness value: " << darknessValue << std::endl;

    //     // Details of the image fetched from the NAO, including an array of its pixel values
    //     int imageWidth = naoImage[0];
    //     int imageHeight = naoImage[1];
    //     AL::ALValue imagePixelArray = naoImage[6];
    //     // cv::Mat normalNaoImage = (imageWidth, imageHeight, CV_8UC3, imagePixelArray);
    //     // cv::namedWindow("Test window", cv::WINDOW_AUTOSIZE);
    //     // cv::imshow("Test window",normalNaoImage);
    // }

    // cv::Mat I = cv::imread("/Users/lewisspencer/General/NAO-setup.png", 0);
    // cv::imshow("Test window", I);
}

void NaoConnection::testDefinition(){
    printf("Test function\n");
}

#endif
