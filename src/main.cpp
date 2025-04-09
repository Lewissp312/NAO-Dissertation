#include "NaoConnection.h"
int main(int argc, char* argv[]){
    FILE *pictureEnhancementProgram = popen("./build/imaging", "r");
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