# Important Information

If you are running this project using an Apple Silicon mac, you will need to run the terminal in Rosetta, as the NAOqi SDK does not support arm64 architecture. This can be done by right clicking terminal in your applications folder, clicking "Get info", then checking the "Open using Rosetta" box.

You will need to create a folder called "external" in the project directory. In this directory, insert the NAOqi SDK and libtorch. 

This project currently runs on the x86_64 2.8.5.10 mac version of the NAOqi SDK, which can be downloaded [here](https://support.unitedrobotics.group/en/support/solutions/articles/80001018812-nao-6-downloads) (along with other platform versions). You can also download Choregraphe from there, a useful and simple tool for testing basic functions of the robot.

This project uses the x86_64 2.2.2 mac version of libtorch, which can be downloaded [here](https://download.pytorch.org/libtorch/cpu/) (along with other platform versions). If you use a different version, you need to run the Setupmodels.py file to create a new .pt file with the corresponding pytorch version. This can be downloaded with anaconda via the commands listed [here](https://pytorch.org/get-started/previous-versions/). Make sure to setup a new conda environment for this project. If using an x86_64 version of pytorch on an Apple Silicon mac, you will need to setup a conda environment that uses x86_64 architecture. This is because Conda will try to download arm64 packages despite being in a Rosetta terminal. To do this, ensure that your Conda version is 25 or above, then run the command ```conda create --platform osx-64 --name *name of the environment* python=3.10 *or whatever python version you need for the version you're downloading*"```. When using an apple version, name it "libtorch-mac64", Windows "libtorch-win64" and Linux "libtorch-linux64". This naming can be changed in the CMakeLists.txt file if you wish.

## Build & Run

Navigate to the project directory, then...

Generate build files:

```sh
cmake -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
```

Build project:

```sh
cmake --build ./build
```

Run project:

```sh
./build/main
```

## Useful Resources  

[NAOqi classes](http://doc.aldebaran.com/2-5/cpp-classindex.html)

[Additional class information](http://doc.aldebaran.com/2-5/ref/cpp-api.html)

[NAOqi events](http://doc.aldebaran.com/2-5/naoqi-eventindex.html)

[A technical overview of the NAO robot](http://doc.aldebaran.com/2-5/family/robots/index_robots.html)