﻿#include <cv.hpp>
#include <highgui.h>
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <list>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int counter;
Mat backgroundX;



void backgroundSubtraction(VideoCapture cam, int imgwidth, int imgheight, int loRange2[], int hiRange2[])
{
	int loRangeY[3] = { 0,0,124 };
	int hiRangeY[3] = { 190,115,255 };

	namedWindow("jakostam", CV_WINDOW_AUTOSIZE);
	/*createTrackbar("loRange0a", "jakostam", &(loRangeZ[0]), 255);
	createTrackbar("loRange1a", "jakostam", &(loRangeZ[1]), 255);
	createTrackbar("loRange2a", "jakostam", &(loRangeZ[2]), 255);
	createTrackbar("hiRange0a", "jakostam", &(hiRangeZ[0]), 255);
	createTrackbar("hiRange1a", "jakostam", &(hiRangeZ[1]), 255);
	createTrackbar("hiRange2a", "jakostam", &(hiRangeZ[2]), 255);*/
	createTrackbar("loRange0", "jakostam", &(loRangeY[0]), 255);
	createTrackbar("loRange1", "jakostam", &(loRangeY[1]), 255);
	createTrackbar("loRange2", "jakostam", &(loRangeY[2]), 255);
	createTrackbar("hiRange0", "jakostam", &(hiRangeY[0]), 255);
	createTrackbar("hiRange1", "jakostam", &(hiRangeY[1]), 255);
	createTrackbar("hiRange2", "jakostam", &(hiRangeY[2]), 255);
	//VideoCapture cam(0);

	//Mat img; cam >> img;

}
/*
void Background(VideoCapture cam, int imgwidth, int imgheight, int loRange2[], int hiRange2[])
{
	int loRangeX[3] = { 0,0,124 };
	int hiRangeX[3] = { 204,115,255 };

	namedWindow("jakostam", CV_WINDOW_AUTOSIZE);
	createTrackbar("loRange0", "jakostam", &(loRangeX[0]), 255);
	createTrackbar("loRange1", "jakostam", &(loRangeX[1]), 255);
	createTrackbar("loRange2", "jakostam", &(loRangeX[2]), 255);
	createTrackbar("hiRange0", "jakostam", &(hiRangeX[0]), 255);
	createTrackbar("hiRange1", "jakostam", &(hiRangeX[1]), 255);
	createTrackbar("hiRange2", "jakostam", &(hiRangeX[2]), 255);
	VideoCapture camera(0);

	/*if (counter < 1)
	{
		cout << "To pierwsze tło" << endl;
	}*/
/*
	Mat backgroundX;

	if (counter = 1)
	{
		backgroundX = imread("plaza.jpg", CV_LOAD_IMAGE_COLOR);
	}
	if (counter = 2)
	{
		backgroundX = imread("twojastara.jpg", CV_LOAD_IMAGE_COLOR);
	}
	if (counter = 3)
	{
		backgroundX = imread("szczelanina.jpg", CV_LOAD_IMAGE_COLOR);
	}
	if (counter = 4)
	{
		backgroundX = imread("konstytucja.jpg", CV_LOAD_IMAGE_COLOR);
	}
	/*if (counter > 4)
	{
		cout << "To ostatnie tło" << endl;
	}*/

void Background(VideoCapture cam, int imgwidth, int imgheight, int loRange2[], int hiRange2[])
{
	int loRangeX[3] = { 0,0,124 };
	int hiRangeX[3] = { 204,115,255 };

	namedWindow("jakostam", CV_WINDOW_AUTOSIZE);
	createTrackbar("loRange0", "jakostam", &(loRangeX[0]), 255);
	createTrackbar("loRange1", "jakostam", &(loRangeX[1]), 255);
	createTrackbar("loRange2", "jakostam", &(loRangeX[2]), 255);
	createTrackbar("hiRange0", "jakostam", &(hiRangeX[0]), 255);
	createTrackbar("hiRange1", "jakostam", &(hiRangeX[1]), 255);
	createTrackbar("hiRange2", "jakostam", &(hiRangeX[2]), 255);
	VideoCapture camera(0);

	/*if (counter < 1)
	{
		cout << "To pierwsze tło" << endl;
	}*/
/*
	Mat backgroundX;

	if (counter = 1)
	{
		backgroundX = imread("plaza.jpg", CV_LOAD_IMAGE_COLOR);
	}
	if (counter = 2)
	{
		backgroundX = imread("twojastara.jpg", CV_LOAD_IMAGE_COLOR);
	}
	if (counter = 3)
	{
		backgroundX = imread("szczelanina.jpg", CV_LOAD_IMAGE_COLOR);
	}
	if (counter = 4)
	{
		backgroundX = imread("konstytucja.jpg", CV_LOAD_IMAGE_COLOR);
	}
	/*if (counter > 4)
	{
		cout << "To ostatnie tło" << endl;
	}*/



	while (waitKey(30) != 27) {
		Mat frame;
		Mat backgroundScaled;
		Mat frameMask, frameNegMask;
		Mat frameWithMask, backgroundScaledWithMask;
		Mat meinniceplace;
		cam >> frame;
		flip(frame, frame, 1);


		resize(backgroundX, backgroundScaled, { frame.cols, frame.rows });
		cvtColor(frame, frameMask, CV_RGB2HSV);
		inRange(frameMask, Scalar(loRangeX[0], loRangeX[1], loRangeX[2]),
			Scalar(hiRangeX[0], hiRangeX[1], hiRangeX[2]), frameNegMask);

		/*int dilation_size = 2;
		auto structElem = getStructuringElement(MORPH_ELLIPSE,
			Size(2 * dilation_size + 1, 2 * dilation_size + 1),
			Point(dilation_size, dilation_size));
		erode(frameNegMask, frameNegMask, structElem);
		dilate(frameNegMask, frameNegMask, structElem);*/
		
		Mat structuringElement = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));

		bitwise_not(frameNegMask, frameMask); // negation
		frame.copyTo(frameWithMask, frameMask); // copy with mask (keying)
		backgroundScaled.copyTo(backgroundScaledWithMask, frameNegMask);

		meinniceplace = backgroundScaledWithMask + frameWithMask;
		imshow("jakostam", meinniceplace);
	}
}

void Line(VideoCapture cam, int imgwidth, int imgheight, int loRange[], int hiRange[])
{
vector < Point > path, newPath;

while (waitKey(30) != 27)
{
Mat imgOriginal, frame;
cam >> frame;//odczyt następnej klatki
flip(frame, frame, 1);
imgOriginal = frame.clone();
int dilation_size = 2;


auto structElem = getStructuringElement(MORPH_ELLIPSE,
Size(2 * dilation_size + 1, 2 * dilation_size + 1),
Point(dilation_size, dilation_size)); //wypełnianie dziur w obiekcie


cvtColor(frame, frame, COLOR_BGR2HSV);
inRange(frame, Scalar(loRange[0], loRange[1], loRange[2]), Scalar(hiRange[0], hiRange[1], hiRange[2]), frame);
Mat structuringElement = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
morphologyEx(frame, frame, MORPH_CLOSE, structElem);

Moments oMoments = moments(frame);

double dM01 = oMoments.m01;
double dM10 = oMoments.m10;
double dArea = oMoments.m00;

if (dArea > 1000)//Określenie rozmiarów obiektu
{//Wyznaczanie środka obiektu
int x1 = dM10 / dArea;
int y1 = dM01 / dArea;

path.push_back({ x1, y1 });//Dodanie punktu do listy

vector <Point2f> pathN;
approxPolyDP(vector<Point2f>(path.begin(), path.end()), pathN, 40, false);

newPath.clear();
for (auto &point : pathN)
newPath.push_back({ (int)point.x, (int)point.y });

if (newPath.size() >= 4) {
vector < Point > itr(newPath.end() - 4, newPath.end());
int conditions = 0;
int conditions2 = 0;
int conditions3 = 0;
int conditions4 = 0;

if (newPath.size() >= 50) {

	path.clear();

}

double factor = (::abs(itr[0].x - itr[1].x) + ::abs(itr[0].y - itr[1].y)) * 2 / 3;

//Litera Z
if ((::abs(itr[0].x - itr[1].x) > factor) && (::abs(itr[0].y - itr[1].y) < factor)) {
//cout << "Pierwsza linia" << endl;
conditions++;
}
if ((::abs(itr[1].x - itr[2].x) > factor) && (::abs(itr[1].y - itr[2].y) > factor)) {
//cout << "Druga linia" << endl;
conditions++;
}
if ((::abs(itr[2].x - itr[3].x) > factor) && (::abs(itr[2].y - itr[3].y) < factor)) {
//cout << "Trzecia linia" << endl;
conditions++;
}

if (conditions == 3) {
	cout << "Jest Z!!!" << endl;
	counter = 1;
	Background1(cam, 600, 400, loRange, hiRange);

	path.clear();
}
//Litera L
if ((::abs(itr[0].x - itr[1].x) > factor) && (::abs(itr[0].y - itr[1].y) < factor)) {
	//cout << "Pierwsza linia" << endl;
	conditions2++;
}
if ((::abs(itr[1].x - itr[2].x) < factor) && (::abs(itr[1].y - itr[2].y) > factor)) {
	//cout << "Druga linia" << endl;
	conditions2++;
}
if (conditions2 == 2) {
cout << "Jest L!!!" << endl;
counter = 2;
Background2(cam, 600, 400, loRange, hiRange);
path.clear();
}
//Litera N
/*if ((::abs(itr[0].x - itr[1].x) < factor) && (::abs(itr[0].y - itr[1].y) > factor)) {
	//cout << "Pierwsza linia" << endl;
	conditions3++;
}
if ((::abs(itr[1].x - itr[2].x) < factor) && (::abs(itr[1].y - itr[2].y) > factor)) {
	//cout << "Druga linia" << endl;
	conditions3++;
}
if ((::abs(itr[2].x - itr[3].x) < factor) && (::abs(itr[2].y - itr[3].y) > factor)) {
	//cout << "Trzecia linia" << endl;
	conditions3++;
}

if (conditions3 == 3) {
cout << "Jest N!!!" << endl;
counter = 3;
Background3(cam, 600, 400, loRange, hiRange);
path.clear();
}*/

if ((::abs(itr[0].x - itr[1].x) < factor) && (::abs(itr[0].y - itr[1].y) > factor)) {
	//cout << "Pierwsza linia" << endl;
	conditions3++;
}
if ((::abs(itr[1].x - itr[2].x) > factor) && (::abs(itr[1].y - itr[2].y) > factor)) {
	//cout << "Druga linia" << endl;
	conditions3++;
}
if ((::abs(itr[2].x - itr[3].x) > factor) && (::abs(itr[2].y - itr[3].y) > factor)) {
	//cout << "Trzecia linia" << endl;
	conditions3++;
}
/*
if (conditions3 == 3) {
	cout << "Jest P!!!" << endl;
	counter = 3;
	//Background4(cam, 600, 400, loRange, hiRange);
	path.clear();
}*/
}

}

polylines(imgOriginal, { newPath }, false, Scalar(0, 255, 0), 2);

imshow("colourDetection", frame);
imshow("camera", imgOriginal);

}
}

int main()
{
VideoCapture cam(0);

if (cam.isOpened() == false)  //Sprawdzanie czy jest obraz z kamery
{
	cout << "Nie ma obrazu z kamery" << endl;
	return 0;
}

int loRange[3] = { 51,112,113 };
int hiRange[3] = { 76,145,255 };

namedWindow("colourDetection", CV_WINDOW_AUTOSIZE);
createTrackbar("loRange0", "colourDetection", &(loRange[0]),
255);
createTrackbar("loRange1", "colourDetection", &(loRange[1]), 255);
createTrackbar("loRange2", "colourDetection", &(loRange[2]), 255);
createTrackbar("hiRange0", "colourDetection", &(hiRange[0]), 255);
createTrackbar("hiRange1", "colourDetection", &(hiRange[1]), 255);
createTrackbar("hiRange2", "colourDetection", &(hiRange[2]), 255);

Line(cam, 600, 400, loRange, hiRange);

return 0;
}