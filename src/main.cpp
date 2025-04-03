#include "NaoConnection.h"
int main(int argc, char * argv[]){
    FILE *pictureEnhancementProgram = popen("cd '/Users/lewisspencer/Programming Projects/C++ projects/NAO_dissertation_code/'; clang++ -std=c++17\
        -I/usr/local/include -I/usr/local/Cellar/pytorch/2.5.1_4/libexec/lib/python3.13/site-packages/torch/include -I/usr/local/Cellar/pytorch/2.5.1_4/libexec/lib/python3.13/site-packages/torch/include/torch/csrc/api/include \
        -L/usr/local/lib -L/usr/local/Cellar/pytorch/2.5.1_4/libexec/lib/python3.13/site-packages/torch/lib \
        -lboost_system -lboost_thread -lopencv_core -lopencv_highgui -lopencv_imgcodecs -ltorch -lc10 \
        -o build/pictureEnhancement src/PictureEnhancement.cpp; open build/pictureEnhancement;", "r");
        pclose(pictureEnhancementProgram);
    try{
        NaoConnection* naoInstance = new NaoConnection;
        naoInstance->getFrames();
    } catch (const AL::ALError& e){
        std::cout << "A NAOqi error occured: " << e.what() << std::endl;
    } catch (const std::exception& e){
        std::cout << "A regular error occured: " << e.what() << std::endl;
    }
    return 0;
}