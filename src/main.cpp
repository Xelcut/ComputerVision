#include "tools.h"
#include "tools.cpp"

#include <iostream> 

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

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
