#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdexcept>

using namespace cv;
using namespace std;

// To make opencv 2.x capatible
#ifndef CV_LOAD_IMAGE_COLOR
	#define CV_LOAD_IMAGE_COLOR IMREAD_COLOR
#endif

#define XMLFILE "lbpcascade_animeface.xml"
#define OUTFILE "out.png"

CascadeClassifier animeface_cascade;

void detect(cv::Mat img)
{
	Mat grayimg;
	
	cvtColor(img, grayimg, COLOR_BGR2GRAY);
	equalizeHist(grayimg, grayimg);

	vector<Rect> faces;
	animeface_cascade.detectMultiScale(grayimg, faces, 1.1, 1, 0, Size(24, 24));
	for(int i = 0; i < faces.size(); ++i)
		rectangle(img, faces[i], Scalar(0, 0, 255));
	
	try {
		imwrite("out.png", img);
	}
	catch (runtime_error& ex) {
		cerr << "Can't save file " << OUTFILE << ": " << ex.what() << endl;
	}
	cout << OUTFILE << " is saved" << endl;
}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		cerr << "usage: detect.py <filename>" << endl;
		exit(-1);
	}

	animeface_cascade.load(XMLFILE);
	if(animeface_cascade.empty())
	{
		cerr << "Can't load " << XMLFILE <<endl;
		cerr << "Please put " << XMLFILE << " in the same dir with the executive file" << endl;
		exit(-1);
	}

	char *filename = argv[1];
	Mat img = imread(filename, CV_LOAD_IMAGE_COLOR);
	if(!img.data)
	{
		cerr << "Could not open " << filename << endl;
		exit(-1);
	}

	detect(img);
	return 0;
}
