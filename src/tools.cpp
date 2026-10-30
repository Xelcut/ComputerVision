#include "tools.h"

#include <iostream>

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

