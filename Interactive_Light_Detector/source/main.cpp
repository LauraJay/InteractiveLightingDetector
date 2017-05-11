#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <time.h> 


using namespace cv;
using namespace std;

void On_click(int state, void *pointer)
{
	printf("Check!");
}


void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
	if (event == EVENT_LBUTTONDOWN)
	{
		cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
	}
	else if (event == EVENT_RBUTTONDOWN)
	{
		cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
	}
	else if (event == EVENT_MBUTTONDOWN)
	{
		cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
	}
	else if (event == EVENT_MOUSEMOVE)
	{
		cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;

	}
}

int main(int argc, char** argv)
{
	
	// Read image from file 
	Mat img = imread("lena.tif");

	//if fail to read the image
	if (img.empty())
	{
		cout << "Error loading the image" << endl;
		return -1;
	}
	//Create a window
	namedWindow("My Window", CV_WINDOW_NORMAL);
	char* nameb1 = "button1";
	cv::createButton(nameb1, On_click, nameb1, CV_CHECKBOX, 1);
	//set the callback function for any mouse event
	setMouseCallback("My Window", CallBackFunc, NULL);

	//show the image
	imshow("My Window", img);

	// Wait until user press some key
	waitKey(0);

	return 0;

}

