#ifndef NAOCONNECTION_H
#define NAOCONNECTION_H
#include <stdio.h>
#include <alerror/alerror.h>
#include <alcommon/alproxy.h>
#include <alcommon/albroker.h>
#include <alproxies/alvideodeviceproxy.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/altexttospeechproxy.h>
#include <alproxies/albacklightingdetectionproxy.h>
#include <alproxies/almemoryproxy.h>
#include <alproxies/aldarknessdetectionproxy.h>

class NaoConnection{
    private:
        //TODO: add GUI variables here
        AL::ALVideoDeviceProxy camProxy;
        AL::ALMotionProxy motionProxy;
        AL::ALTextToSpeechProxy ttsProxy;
        AL::ALBacklightingDetectionProxy backlightDetectionProxy;
        AL::ALMemoryProxy memoryProxy;
        AL::ALDarknessDetectionProxy darknessDetectionProxy;
        const boost::shared_ptr<AL::ALBroker> naoBroker = AL::ALBroker::createBroker("naoBroker","0.0.0.0",0,this->naoIP,this->naoPort);
        //TODO: add zmq variables here
        const std::string names[4] = {"HeadYaw", "HeadPitch" , "LHipRoll" , "RHipRoll"};
        const float angles[4] = {0.0 , 4.0 , 0.0 , 0.0};
        const float pStiffnessLists[4] = {0.0 , 1.0 , 1.0 , 1.0};
        const float fractionMaxSpeed = 0.01;
        const float pTimeLists = 0.1;
        const int naoPort = 9559;
        const int resolution = 1;
        const int colorSpace = 11;
        const std::string naoIP = "phil.local.";


    public:
        NaoConnection(){
            //it's also 192,168,0,100 if you get NAO working with wifi
            printf("I'm constructing it");
            this->camProxy = naoBroker->getProxy("ALVideoDevice");
            this->motionProxy = naoBroker->getProxy("ALMotion");
            this->ttsProxy = naoBroker->getProxy("ALTextToSpeech");
            this->backlightDetectionProxy = naoBroker->getProxy("ALBackLightingDetection");
            this->memoryProxy = naoBroker->getProxy("ALMemory");
            this->darknessDetectionProxy = naoBroker->getProxy("ALDarknessDetection");
        }

        inline void testDefinition();
};

#endif