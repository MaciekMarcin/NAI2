/*
#include <cv.hpp>
#include <highgui.h>
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <list>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{

	void line(VideoCapture cap, int imgwidth, int imgheight, int loRange[], int hiRange[]);
	{

		VideoCapture cap(0);

		if (cap.isOpened() == false)
		{
			return 0;
		}

		vector < Point > path, smoothedPath;

		//kolor limonkowy
		int loRange[3] = { 34,72,90 };
		int hiRange[3] = { 206,84,255 };

		namedWindow("colourDetection", CV_WINDOW_AUTOSIZE);
		createTrackbar("loRange0", "colourDetection", &(loRange[0]), 255);
		createTrackbar("loRange1", "colourDetection", &(loRange[1]), 255);
		createTrackbar("loRange2", "colourDetection", &(loRange[2]), 255);
		createTrackbar("hiRange0", "colourDetection", &(hiRange[0]), 255);
		createTrackbar("hiRange1", "colourDetection", &(hiRange[1]), 255);
		createTrackbar("hiRange2", "colourDetection", &(hiRange[2]), 255);

		line(0, 600, 400, loRange, hiRange);

		int dilation_size = 4;

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
			bool bSuccess = cap.read(imgOriginal); //odczyt obrazu z kamery

			Mat imgHSV;
			cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Konwersja z BGR do HSV

			Mat imgThresholded;
			inRange(imgHSV, Scalar(loRange[0], loRange[1], loRange[2]), Scalar(hiRange[0], hiRange[1], hiRange[2]), imgThresholded); //Threshold the image

			morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, structElem);
			Moments oMoments = moments(imgThresholded);			//Calculate the moments of the thresholded image

			double dM01 = oMoments.m01;
			double dM10 = oMoments.m10;
			double dArea = oMoments.m00;

			//Wyznaczenie rozmiaru obiektu
			if (dArea > 100)
			{
				//Obliczanie œrodka obiektu
				int pX = dM10 / dArea;
				int pY = dM01 / dArea;

				path.push_back({ pX, pY });

				vector <Point2f> pathSmooth;
				approxPolyDP(vector<Point2f>(path.begin(), path.end()), pathSmooth, 40, false);

				smoothedPath.clear();
				for (auto &point : pathSmooth)														//kopia wyg³adzonej lini do wektora punktów (¿eby póŸniej wyœwietliæ na jego podstawie linie)
					smoothedPath.push_back({ (int)point.x, (int)point.y });

				if (smoothedPath.size() >= 4) {
					vector < Point > itr(smoothedPath.end() - 4, smoothedPath.end());
					int conditions = 0;
					double factor = (::abs(itr[0].x - itr[1].x) + ::abs(itr[0].y - itr[1].y)) * 2 / 3;


					if ((::abs(itr[0].x - itr[1].x) > factor) && (::abs(itr[0].y - itr[1].y) < factor)) {
						conditions++;
					}
					if ((::abs(itr[1].x - itr[2].x) > factor) && (::abs(itr[1].y - itr[2].y) > factor)) {
						conditions++;
					}
					if ((::abs(itr[2].x - itr[3].x) > factor) && (::abs(itr[2].y - itr[3].y) < factor)) {
						conditions++;
					}

					if (conditions == 3) {
						cout << "Jest Z!!!" << endl;
						path.clear();
					}
				}
			}

			polylines(imgOriginal, { smoothedPath }, false, Scalar(0, 255, 0), 3);
			flip(imgThresholded, imgThresholded, 1);
			imshow("colourDetection", imgThresholded); //Obraz z kolorem
			imgOriginal = imgOriginal + imgLines;
			flip(imgOriginal, imgOriginal, 1);
			imshow("cameraImage", imgOriginal); //Obraz z kamery
			//line(imgLines, Point(pX, pY), Point(LastX, LastY), Scalar(0, 255, 0), 8);

			if (waitKey(1) == 27)
			{
				break;
			}
		}
	}

	return 0;
}
*/