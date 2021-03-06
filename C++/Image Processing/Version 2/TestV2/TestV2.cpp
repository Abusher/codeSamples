#include <cmath>
#include <time.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/dnn.hpp>
#include <opencv/cv.hpp>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <array>
#include <list>
#include "Parabola.h"
#include "Edge.h"
#include "lib.h"
using namespace std;
using namespace cv;
using namespace vor;

double w = 600;

int main() {
	namedWindow("test", CV_WINDOW_AUTOSIZE);
	Mat img = Mat::zeros(w,w, CV_8UC3);
	Voronoi * v = new Voronoi();
	Vertices * ver = new Vertices();
	Vertices * dir = new Vertices();
	Edges * edg;

	srand(time(NULL));

	for (int i = 0; i<50; i++)
	{
		ver->push_back(new Point2d(w * (double)rand() / (double)RAND_MAX, w * (double)rand() / (double)RAND_MAX));
		circle(img,*ver->back(),2,Scalar(0,0,255));
	}
	cout << "asd" << endl;
	int t = clock();
	edg = v->GetEdges(ver, w, w);

	std::cout << "voronois done!\n"<< (double)(clock()-t)/1000<<endl;
	
	for (vor::Edges::iterator i = edg->begin(); i != edg->end(); ++i)
	{
		line(img, *(*i)->start, *(*i)->end, Scalar(244, 0, 0));
		cv::waitKey(1);
		cv::imshow("test", img);
		
	}
	
	system("pause");
	
	
	
	return 0;
}