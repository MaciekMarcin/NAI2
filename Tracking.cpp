
#include <cv.hpp>
#include <highgui.h>
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <list>
/*
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	VideoCapture cap(0);

	if (cap.isOpened() == false)
	{
		return 0;
	}

	namedWindow("colourDetection", CV_WINDOW_AUTOSIZE); 

	//kolor limonkowy
	int iLowH = 34;
	int iHighH = 72;
	int iLowS = 90;
	int iHighS = 206;
	int iLowV = 84;
	int iHighV = 255;

	//Create trackbars in "Control" window
	createTrackbar("LowH", "colourDetection", &iLowH, 179);
	createTrackbar("HighH", "colourDetection", &iHighH, 179);
	createTrackbar("LowS", "colourDetection", &iLowS, 255); 
	createTrackbar("HighS", "colourDetection", &iHighS, 255);
	createTrackbar("LowV", "colourDetection", &iLowV, 255);
	createTrackbar("HighV", "colourDetection", &iHighV, 255);

	int iLastX = -1;
	int iLastY = -1;
	int dilation_size = 10;

	//Capture a temporary image from the camera
	Mat imgTmp;
	cap.read(imgTmp);

	//Create a black image with the size as the camera output
	Mat imgLines = Mat::zeros(imgTmp.size(), CV_8UC3);;
	
	auto structElem = getStructuringElement(MORPH_ELLIPSE,
		Size(2 * dilation_size + 1, 2 * dilation_size + 1),
		Point(dilation_size, dilation_size)); //wype³nianie

	while (true)
	{
		Mat imgOriginal;

		bool bSuccess = cap.read(imgOriginal); // read a new frame from video

		if (!bSuccess) //if not success, break loop
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}

		Mat imgHSV;

		cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Konwersja z BGR do HSV

		Mat imgThresholded;

		inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image

		morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, structElem);

		//Calculate the moments of the thresholded image
		Moments oMoments = moments(imgThresholded);

		double dM01 = oMoments.m01;
		double dM10 = oMoments.m10;
		double dArea = oMoments.m00;

		// if the area <= 10000, I consider that the there are no object in the image and it's because of the noise, the area is not zero 
		if (dArea > 100)//rozmiar obiektu
		{
			//Wyznaczanie œrodka obiektu
			int posX = dM10 / dArea;
			int posY = dM01 / dArea;
			int count;

			if (iLastX >= 0 && iLastY >= 0 && posX >= 0 && posY >= 0)
			{
				//Draw a red line from the previous point to the current point
				vector<cv::Point>pointList;
				//pointList.push_back({ Point(0, 0) });
				//for (unsigned i = 0; i <= pointList.size(); i++) {
					line(imgLines, Point(posX, posY), Point(iLastX, iLastY), Scalar(0, 255, 0), 8);
						//pointList.push_back({ Point(posX, posY) });

					//cout << "Cords = " << Point(iLastX, iLastY) << endl;

					//cout << "Liczba = " << pointList.size()%10 << endl;

			//}

			iLastX = posX;
			iLastY = posY;
		}

		flip(imgThresholded, imgThresholded, 1);
		imshow("colourDetection", imgThresholded); //Obraz z kolorem
		imgOriginal = imgOriginal + imgLines;
		flip(imgOriginal, imgOriginal, 1);
		imshow("cameraImage", imgOriginal); //Obraz z kamery

		if (waitKey(1) == 27)
		{
			break;
		}
	}

	return 0;
}*/


using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	VideoCapture cap(0);

	if (cap.isOpened() == false)
	{
		return 0;
	}

	namedWindow("colourDetection", CV_WINDOW_AUTOSIZE);

	//kolor limonkowy
	int iLowH = 34;
	int iHighH = 72;
	int iLowS = 90;
	int iHighS = 206;
	int iLowV = 84;
	int iHighV = 255;

	//Create trackbars in "Control" window
	createTrackbar("LowH", "colourDetection", &iLowH, 179);
	createTrackbar("HighH", "colourDetection", &iHighH, 179);
	createTrackbar("LowS", "colourDetection", &iLowS, 255);
	createTrackbar("HighS", "colourDetection", &iHighS, 255);
	createTrackbar("LowV", "colourDetection", &iLowV, 255);
	createTrackbar("HighV", "colourDetection", &iHighV, 255);

	int iLastX = -1;
	int iLastY = -1;
	int dilation_size = 10;

	//Capture a temporary image from the camera
	Mat imgTmp;
	cap.read(imgTmp);

	//Create a black image with the size as the camera output
	Mat imgLines = Mat::zeros(imgTmp.size(), CV_8UC3);;

	auto structElem = getStructuringElement(MORPH_ELLIPSE,
		Size(2 * dilation_size + 1, 2 * dilation_size + 1),
		Point(dilation_size, dilation_size)); //wype³nianie

	while (true)
	{
		Mat imgOriginal;

		bool bSuccess = cap.read(imgOriginal); // read a new frame from video

		if (!bSuccess) //if not success, break loop
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}

		Mat imgHSV;

		cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Konwersja z BGR do HSV

		Mat imgThresholded;

		inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image

		morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, structElem);

		//Calculate the moments of the thresholded image
		Moments oMoments = moments(imgThresholded);

		double dM01 = oMoments.m01;
		double dM10 = oMoments.m10;
		double dArea = oMoments.m00;

		// if the area <= 10000, I consider that the there are no object in the image and it's because of the noise, the area is not zero 
		if (dArea > 100)
		{
			//calculate the position of the ball
			int posX = dM10 / dArea;
			int posY = dM01 / dArea;
			int count;

			if (iLastX >= 0 && iLastY >= 0 && posX >= 0 && posY >= 0)
			{
				//Draw a red line from the previous point to the current point
				vector<cv::Point>pointList;
				pointList.push_back({ Point(posX, posY) });
				for (unsigned i = 0; i < pointList.size(); i++) {
					line(imgLines, Point(posX, posY), Point(iLastX, iLastY), Scalar(0, 255, 0), 8);
					//pointList.push_back({ Point(posX, posY) });
					//cout << "Cords = " << Point(iLastX, iLastY) << endl;

					//cout << "Liczba = " << pointList.size() << endl;

					//system("CLS");
				}
				/*
				for (auto vec : pointList)
					cout << vec << endl;
				*/	

			}

			iLastX = posX;
			iLastY = posY;
		}

		flip(imgThresholded, imgThresholded, 1);
		imshow("colourDetection", imgThresholded); //Obraz z kolorem
		imgOriginal = imgOriginal + imgLines;
		flip(imgOriginal, imgOriginal, 1);
		imshow("cameraImage", imgOriginal); //Obraz z kamery

		if (waitKey(1) == 27)
		{
			break;
		}
	}

	return 0;
}
