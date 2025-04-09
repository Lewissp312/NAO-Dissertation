#ifndef PICTUREENHANCEMENT_H
#define PICTUREENHANCEMENT_H
#include <stdio.h>
#include <torch/torch.h>
#include <torch/script.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>

int main(int argc, char* argv[]){
    std::cout << "PyTorch version: "
    << TORCH_VERSION_MAJOR << "."
    << TORCH_VERSION_MINOR << "."
    << TORCH_VERSION_PATCH << std::endl;
    cv::Mat test = cv::imread("NAO-setup.png");
    return 0;
}

#endif