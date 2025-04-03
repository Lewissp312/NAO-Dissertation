#ifndef NAOCONNECTION_H
#define NAOCONNECTION_H
#include <stdio.h>
#include <alvalue/alvalue.h>
#include <alerror/alerror.h>
#include <alcommon/alproxy.h>
#include <alcommon/albroker.h>
#include <alproxies/alvideodeviceproxy.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/altexttospeechproxy.h>
#include <alproxies/albacklightingdetectionproxy.h>
#include <alproxies/almemoryproxy.h>
#include <alproxies/aldarknessdetectionproxy.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>

class NaoConnection{
    private:
        //naoBroker must be initialised here as the other proxies will throw up segmentation errors if not
        const std::string naoIP = "phil.local.";
        const int naoPort = 9559;
        const boost::shared_ptr<AL::ALBroker> naoBroker = AL::ALBroker::createBroker("naoBroker","0.0.0.0",0,this->naoIP,this->naoPort);
        AL::ALVideoDeviceProxy camProxy;
        AL::ALMotionProxy motionProxy;
        AL::ALTextToSpeechProxy ttsProxy;
        AL::ALBacklightingDetectionProxy backlightingDetectionProxy;
        AL::ALMemoryProxy memoryProxy;
        AL::ALDarknessDetectionProxy darknessDetectionProxy;
        const AL::ALValue names = AL::ALValue::array("HeadYaw", "HeadPitch" , "LHipRoll" , "RHipRoll");
        const AL::ALValue angles = AL::ALValue::array(0.0 , 4.0 , 0.0 , 0.0);
        const AL::ALValue pStiffnessLists = AL::ALValue::array(0.0 , 1.0 , 1.0 , 1.0);
        const float fractionMaxSpeed = 0.01;
        const float pTimeLists = 0.1;
        const int resolution = 1;
        const int colorSpace = 11;


    public:
        NaoConnection(){
            this->camProxy = this->naoBroker->getProxy("ALVideoDevice");
            this->motionProxy = this->naoBroker->getProxy("ALMotion");
            this->ttsProxy = this->naoBroker->getProxy("ALTextToSpeech");
            this->backlightingDetectionProxy = this->naoBroker->getProxy("ALBacklightingDetection");
            this->memoryProxy = this->naoBroker->getProxy("ALMemory");
            this->darknessDetectionProxy = this->naoBroker->getProxy("ALDarknessDetection");
        }

        void getFrames();
};

#endif