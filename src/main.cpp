#include <iostream> 
#include <stdio.h>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int loadCamera() {
  Mat frame;
  VideoCapture cap;

  int deviceID = 0;
  int apiID = cv::CAP_ANY;

  cap.open(deviceID, apiID);
  if (!cap.isOpened()) {
    std::cerr << "Could not open camera\n";
    return -1;
  }

  std::cout << "Start grabbing" << std::endl;
  for (;;) {
    cap.read(frame);
    if (frame.empty()) {
      std::cerr << "Blank Frame Grabbed!";
      break;
    }

    imshow("Live", frame);
    if (waitKey(5) >= 0) {
      break;
    }
  }
}

int main() {
  loadCamera();
  return 0;
}

int loadImage() {
  std::string image_path = samples::findFile("images/Image.jpg");
  Mat img = imread(image_path, IMREAD_COLOR);

  if (img.empty()) {
    std::cout << "Could not find image at: " << image_path << std::endl;
    return 1;
  }

  imshow("Display window", img);
  int k = waitKey(0);

  if (k == 's') {
    imwrite("images/Image.jpg", img);
  }
}
