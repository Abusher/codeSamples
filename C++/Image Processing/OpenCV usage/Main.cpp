#include <cassert>
#include <fstream>
#include <exception>
#include <iostream>
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2\dnn.hpp>
#include <opencv2\opencv.hpp>
#include "PreLib.h"
#include <ctime>

using namespace std;
using namespace cv;
using namespace DetectText;

void convertToFloatImage(Mat& byteImage, Mat& floatImage)
{
	byteImage.convertTo(floatImage, CV_32FC1, 1 / 255.);
	
}

class FeatureError : public std::exception {
	std::string message;
public:
	FeatureError(const std::string & msg, const std::string & file) {
		std::stringstream ss;
		ss << msg << " " << file;
		message = msg.c_str();
	}
	~FeatureError() throw () {
	}
};

Mat loadByteImage(const char * name) {
	Mat image = imread(name);

	if (image.empty()) {
		return Mat();
	}
	cvtColor(image, image, CV_BGR2RGB);
	return image;
}

int mainTextDetection(int argc, char** argv) {
	Mat byteQueryImage = loadByteImage(argv[1]);
	if (byteQueryImage.empty()) {
		cerr << "couldn't load query image" << endl;
		return -1;
	}
//	Mat output = textDetection(byteQueryImage, atoi(argv[3]));
//	imwrite(argv[2], output);
	system("pause");
	return 0;
}

int main(int argc, char** argv) {
	srand(time(NULL));
	if ((argc != 4)) {
		cerr << "usage: " << argv[0] << " imagefile resultImage darkText" << endl;
		return -1;
	}
	
	return mainTextDetection(argc, argv);

}