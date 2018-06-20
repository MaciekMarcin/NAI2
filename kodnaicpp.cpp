#include <cv.hpp>
#include <highgui.h>
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <list>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

Mat backgroundX;

/*
void Background(VideoCapture cam, int imgwidth, int imgheight, int loRange2[], int hiRange2[])
{
int loRangeX[3] = { 0,0,124 };
int hiRangeX[3] = { 204,115,255 };
namedWindow("tlo", CV_WINDOW_AUTOSIZE);
createTrackbar("loRange0", "tlo", &(loRangeX[0]), 255);
createTrackbar("loRange1", "tlo", &(loRangeX[1]), 255);
createTrackbar("loRange2", "tlo", &(loRangeX[2]), 255);
createTrackbar("hiRange0", "tlo", &(hiRangeX[0]), 255);
createTrackbar("hiRange1", "tlo", &(hiRangeX[1]), 255);
createTrackbar("hiRange2", "tlo", &(hiRangeX[2]), 255);
VideoCapture cam(0);
*/
//Program z wykładu dla porównania (Też dalej wyrzuca exception na starcie)
void Background1(VideoCapture cam, int imgwidth, int imgheight, int loRange2[], int hiRange2[])
{
	int loRangeX[3] = { 0,0,124 };
	int hiRangeX[3] = { 204,115,255 };

	namedWindow("tlo", CV_WINDOW_AUTOSIZE);
	createTrackbar("loRange0", "tlo", &(loRangeX[0]), 255);
	createTrackbar("loRange1", "tlo", &(loRangeX[1]), 255);
	createTrackbar("loRange2", "tlo", &(loRangeX[2]), 255);
	createTrackbar("hiRange0", "tlo", &(hiRangeX[0]), 255);
	createTrackbar("hiRange1", "tlo", &(hiRangeX[1]), 255);
	createTrackbar("hiRange2", "tlo", &(hiRangeX[2]), 255);
	VideoCapture cam(0);

	Mat backgroundX;

	backgroundX = imread("plaza.jpg", CV_LOAD_IMAGE_COLOR);

	while (waitKey(1) != 27) {
		Mat frame;
		Mat backgroundScaled;
		Mat frameMask, frameNegMask;
		Mat frameWithMask, backgroundScaledWithMask;
		Mat frameN;
		cam >> frame;
		flip(frame, frame, 1);



		resize(backgroundX, backgroundScaled, { frame.cols, frame.rows });
		cvtColor(frame, frameMask, CV_RGB2HSV);
		inRange(frameMask, Scalar(loRangeX[0], loRangeX[1], loRangeX[2]),
			Scalar(hiRangeX[0], hiRangeX[1], hiRangeX[2]), frameNegMask);

		Mat structuringElement = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));

		bitwise_not(frameNegMask, frameMask); // negacja bitów w tablicy
		frame.copyTo(frameWithMask, frameMask); // kopia obrazu z maską
		backgroundScaled.copyTo(backgroundScaledWithMask, frameNegMask);

		frameN = backgroundScaledWithMask + frameWithMask;
		imshow("tlo", frameN);
	}
}

void Background2(VideoCapture cam, int imgwidth, int imgheight, int loRange2[], int hiRange2[])
{
	int a = 10;
	int b = 0;
	int c = 75;

	int d = 255;
	int e = 45;
	int f = 255;

	int loRangeX[3] = { a,b,c };
	int hiRangeX[3] = { d,e,f };

	namedWindow("tlo", CV_WINDOW_AUTOSIZE);
	createTrackbar("loRange0", "tlo", &(loRangeX[0]), 255);
	createTrackbar("loRange1", "tlo", &(loRangeX[1]), 255);
	createTrackbar("loRange2", "tlo", &(loRangeX[2]), 255);
	createTrackbar("hiRange0", "tlo", &(hiRangeX[0]), 255);
	createTrackbar("hiRange1", "tlo", &(hiRangeX[1]), 255);
	createTrackbar("hiRange2", "tlo", &(hiRangeX[2]), 255);
	VideoCapture camera(0);

	int loRangeG[3] = { a,b,c };
	int hiRangeG[3] = { d,e,f };

	namedWindow("kopia", CV_WINDOW_AUTOSIZE);
	createTrackbar("loRange0", "kopia", &(loRangeX[0]), 255);
	createTrackbar("loRange1", "kopia", &(loRangeX[1]), 255);
	createTrackbar("loRange2", "kopia", &(loRangeX[2]), 255);
	createTrackbar("hiRange0", "kopia", &(hiRangeX[0]), 255);
	createTrackbar("hiRange1", "kopia", &(hiRangeX[1]), 255);
	createTrackbar("hiRange2", "kopia", &(hiRangeX[2]), 255);

	int loRangeT[3] = { a,b,c };
	int hiRangeT[3] = { d,e,f };

	namedWindow("dwójka", CV_WINDOW_AUTOSIZE);
	createTrackbar("loRange0", "dwójka", &(loRangeX[0]), 255);
	createTrackbar("loRange1", "dwójka", &(loRangeX[1]), 255);
	createTrackbar("loRange2", "dwójka", &(loRangeX[2]), 255);
	createTrackbar("hiRange0", "dwójka", &(hiRangeX[0]), 255);
	createTrackbar("hiRange1", "dwójka", &(hiRangeX[1]), 255);
	createTrackbar("hiRange2", "dwójka", &(hiRangeX[2]), 255);

	int loRangeH[3] = { a,b,c };
	int hiRangeH[3] = { d,e,f };

	namedWindow("trójka", CV_WINDOW_AUTOSIZE);
	createTrackbar("loRange0", "trójka", &(loRangeX[0]), 255);
	createTrackbar("loRange1", "trójka", &(loRangeX[1]), 255);
	createTrackbar("loRange2", "trójka", &(loRangeX[2]), 255);
	createTrackbar("hiRange0", "trójka", &(hiRangeX[0]), 255);
	createTrackbar("hiRange1", "trójka", &(hiRangeX[1]), 255);
	createTrackbar("hiRange2", "trójka", &(hiRangeX[2]), 255);

	int loRangeQ[3] = { a,b,c };
	int hiRangeQ[3] = { d,e,f };

	namedWindow("czwórka", CV_WINDOW_AUTOSIZE);
	createTrackbar("loRange0", "czwórka", &(loRangeX[0]), 255);
	createTrackbar("loRange1", "czwórka", &(loRangeX[1]), 255);
	createTrackbar("loRange2", "czwórka", &(loRangeX[2]), 255);
	createTrackbar("hiRange0", "czwórka", &(hiRangeX[0]), 255);
	createTrackbar("hiRange1", "czwórka", &(hiRangeX[1]), 255);
	createTrackbar("hiRange2", "czwórka", &(hiRangeX[2]), 255);

	int loRangeP[3] = { a,b,c };
	int hiRangeP[3] = { d,e,f };

	namedWindow("piatka", CV_WINDOW_AUTOSIZE);
	createTrackbar("loRange0", "piatka", &(loRangeX[0]), 255);
	createTrackbar("loRange1", "piatka", &(loRangeX[1]), 255);
	createTrackbar("loRange2", "piatka", &(loRangeX[2]), 255);
	createTrackbar("hiRange0", "piatka", &(hiRangeX[0]), 255);
	createTrackbar("hiRange1", "piatka", &(hiRangeX[1]), 255);
	createTrackbar("hiRange2", "piatka", &(hiRangeX[2]), 255);

	int loRangeK[3] = { a,b,c };
	int hiRangeK[3] = { d,e,f };

	namedWindow("szostka", CV_WINDOW_AUTOSIZE);
	createTrackbar("loRange0", "szostka", &(loRangeX[0]), 255);
	createTrackbar("loRange1", "szostka", &(loRangeX[1]), 255);
	createTrackbar("loRange2", "szostka", &(loRangeX[2]), 255);
	createTrackbar("hiRange0", "szostka", &(hiRangeX[0]), 255);
	createTrackbar("hiRange1", "szostka", &(hiRangeX[1]), 255);
	createTrackbar("hiRange2", "szostka", &(hiRangeX[2]), 255);
	Mat backgroundX;

	backgroundX = imread("costam.jpg", CV_LOAD_IMAGE_COLOR);

	/*
	resize(backgroundX, backgroundScaled, { frame.cols, frame.rows });
	cvtColor(frame, frameMask, CV_RGB2HSV);
	inRange(frameMask, Scalar(loRangeX[0], loRangeX[1], loRangeX[2]),
	Scalar(hiRangeX[0], hiRangeX[1], hiRangeX[2]), frameNegMask);

	Mat structuringElement = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));

	bitwise_not(frameNegMask, frameMask); //negacja bitów w szeregu
	frame.copyTo(frameWithMask, frameMask); // kopia obrazu z maską
	backgroundScaled.copyTo(backgroundScaledWithMask, frameNegMask);

	frameN = backgroundScaledWithMask + frameWithMask;
	Mat kopia = frameN.clone();
	//imshow("jakostam", frameN);
	//destroyWindow("jakostam");
	//imshow("kopia", kopia);
	Mat dwójka = kopia.clone();
	Mat trójka = dwójka.clone();
	Mat czwórka = trójka.clone();
	/*Mat dwójka; kopia.copyTo(dwójka);
	Mat trójka; dwójka.copyTo(trójka);
	Mat czwórka; trójka.copyTo(czwórka);
	Mat piatka = czwórka.clone();
	Mat szostka = piatka.clone();
	imshow("szostka", szostka);
	*/

	while (waitKey(1) != 27) {
		Mat frame;
		Mat backgroundScaled;
		Mat frameMask, frameNegMask;
		Mat frameWithMask, backgroundScaledWithMask;
		Mat frameN;
		cam >> frame;
		flip(frame, frame, 1);


		resize(backgroundX, backgroundScaled, { frame.cols, frame.rows });
		cvtColor(frame, frameMask, CV_RGB2HSV);
		inRange(frameMask, Scalar(loRangeX[0], loRangeX[1], loRangeX[2]),
			Scalar(hiRangeX[0], hiRangeX[1], hiRangeX[2]), frameNegMask);

		Mat structuringElement = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));

		bitwise_not(frameNegMask, frameMask); // negation
		frame.copyTo(frameWithMask, frameMask); // kopia obrazu z maską
		backgroundScaled.copyTo(backgroundScaledWithMask, frameNegMask);

		frameN = backgroundScaledWithMask + frameWithMask;
		Mat kopia = frameN.clone();
		Mat dwójka = kopia.clone();
		Mat trójka = dwójka.clone();
		Mat czwórka = trójka.clone();
		/*Mat dwójka; kopia.copyTo(dwójka);
		Mat trójka; dwójka.copyTo(trójka);
		Mat czwórka; trójka.copyTo(czwórka);*/
		Mat piatka = czwórka.clone();
		Mat szostka = piatka.clone();
		imshow("czwórka", czwórka);
	}
}

void Background3(VideoCapture cam, int imgwidth, int imgheight, int loRange2[], int hiRange2[])
{
	int loRangeX[3] = { 0,0,124 };
	int hiRangeX[3] = { 204,115,255 };

	namedWindow("tlo", CV_WINDOW_AUTOSIZE);
	createTrackbar("loRange0", "tlo", &(loRangeX[0]), 255);
	createTrackbar("loRange1", "tlo", &(loRangeX[1]), 255);
	createTrackbar("loRange2", "tlo", &(loRangeX[2]), 255);
	createTrackbar("hiRange0", "tlo", &(hiRangeX[0]), 255);
	createTrackbar("hiRange1", "tlo", &(hiRangeX[1]), 255);
	createTrackbar("hiRange2", "tlo", &(hiRangeX[2]), 255);
	VideoCapture camera(0);

	Mat backgroundX;

	backgroundX = imread("szczelanina.jpg", CV_LOAD_IMAGE_COLOR);

	while (waitKey(1) != 27) {
		Mat frame;
		Mat backgroundScaled;
		Mat frameMask, frameNegMask;
		Mat frameWithMask, backgroundScaledWithMask;
		Mat frameN;
		cam >> frame;
		flip(frame, frame, 1);


		resize(backgroundX, backgroundScaled, { frame.cols, frame.rows });
		cvtColor(frame, frameMask, CV_RGB2HSV);
		inRange(frameMask, Scalar(loRangeX[0], loRangeX[1], loRangeX[2]),
			Scalar(hiRangeX[0], hiRangeX[1], hiRangeX[2]), frameNegMask);

		Mat structuringElement = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));

		bitwise_not(frameNegMask, frameMask); 
		frame.copyTo(frameWithMask, frameMask); 
		backgroundScaled.copyTo(backgroundScaledWithMask, frameNegMask);

		frameN = backgroundScaledWithMask + frameWithMask;
		imshow("tlo", frameN);
	}
}

void Background4(VideoCapture cam, int imgwidth, int imgheight, int loRange2[], int hiRange2[])
{
	int a = 10;
	int b = 0;
	int c = 75;

	int d = 255;
	int e = 45;
	int f = 255;

	int loRangeX[3] = { a,b,c };
	int hiRangeX[3] = { d,e,f };

	namedWindow("tlo", CV_WINDOW_AUTOSIZE);
	createTrackbar("loRange0", "tlo", &(loRangeX[0]), 255);
	createTrackbar("loRange1", "tlo", &(loRangeX[1]), 255);
	createTrackbar("loRange2", "tlo", &(loRangeX[2]), 255);
	createTrackbar("hiRange0", "tlo", &(hiRangeX[0]), 255);
	createTrackbar("hiRange1", "tlo", &(hiRangeX[1]), 255);
	createTrackbar("hiRange2", "tlo", &(hiRangeX[2]), 255);
	VideoCapture camera(0);

	int loRangeG[3] = { a,b,c };
	int hiRangeG[3] = { d,e,f };

	namedWindow("kopia", CV_WINDOW_AUTOSIZE);
	createTrackbar("loRange0", "kopia", &(loRangeX[0]), 255);
	createTrackbar("loRange1", "kopia", &(loRangeX[1]), 255);
	createTrackbar("loRange2", "kopia", &(loRangeX[2]), 255);
	createTrackbar("hiRange0", "kopia", &(hiRangeX[0]), 255);
	createTrackbar("hiRange1", "kopia", &(hiRangeX[1]), 255);
	createTrackbar("hiRange2", "kopia", &(hiRangeX[2]), 255);

	int loRangeT[3] = { a,b,c };
	int hiRangeT[3] = { d,e,f };

	namedWindow("dwójka", CV_WINDOW_AUTOSIZE);
	createTrackbar("loRange0", "dwójka", &(loRangeX[0]), 255);
	createTrackbar("loRange1", "dwójka", &(loRangeX[1]), 255);
	createTrackbar("loRange2", "dwójka", &(loRangeX[2]), 255);
	createTrackbar("hiRange0", "dwójka", &(hiRangeX[0]), 255);
	createTrackbar("hiRange1", "dwójka", &(hiRangeX[1]), 255);
	createTrackbar("hiRange2", "dwójka", &(hiRangeX[2]), 255);

	int loRangeH[3] = { a,b,c };
	int hiRangeH[3] = { d,e,f };

	namedWindow("trójka", CV_WINDOW_AUTOSIZE);
	createTrackbar("loRange0", "trójka", &(loRangeX[0]), 255);
	createTrackbar("loRange1", "trójka", &(loRangeX[1]), 255);
	createTrackbar("loRange2", "trójka", &(loRangeX[2]), 255);
	createTrackbar("hiRange0", "trójka", &(hiRangeX[0]), 255);
	createTrackbar("hiRange1", "trójka", &(hiRangeX[1]), 255);
	createTrackbar("hiRange2", "trójka", &(hiRangeX[2]), 255);

	int loRangeQ[3] = { a,b,c };
	int hiRangeQ[3] = { d,e,f };

	namedWindow("czwórka", CV_WINDOW_AUTOSIZE);
	createTrackbar("loRange0", "czwórka", &(loRangeX[0]), 255);
	createTrackbar("loRange1", "czwórka", &(loRangeX[1]), 255);
	createTrackbar("loRange2", "czwórka", &(loRangeX[2]), 255);
	createTrackbar("hiRange0", "czwórka", &(hiRangeX[0]), 255);
	createTrackbar("hiRange1", "czwórka", &(hiRangeX[1]), 255);
	createTrackbar("hiRange2", "czwórka", &(hiRangeX[2]), 255);

	int loRangeP[3] = { a,b,c };
	int hiRangeP[3] = { d,e,f };

	namedWindow("piatka", CV_WINDOW_AUTOSIZE);
	createTrackbar("loRange0", "piatka", &(loRangeX[0]), 255);
	createTrackbar("loRange1", "piatka", &(loRangeX[1]), 255);
	createTrackbar("loRange2", "piatka", &(loRangeX[2]), 255);
	createTrackbar("hiRange0", "piatka", &(hiRangeX[0]), 255);
	createTrackbar("hiRange1", "piatka", &(hiRangeX[1]), 255);
	createTrackbar("hiRange2", "piatka", &(hiRangeX[2]), 255);

	int loRangeK[3] = { a,b,c };
	int hiRangeK[3] = { d,e,f };

	namedWindow("szostka", CV_WINDOW_AUTOSIZE);
	createTrackbar("loRange0", "szostka", &(loRangeX[0]), 255);
	createTrackbar("loRange1", "szostka", &(loRangeX[1]), 255);
	createTrackbar("loRange2", "szostka", &(loRangeX[2]), 255);
	createTrackbar("hiRange0", "szostka", &(hiRangeX[0]), 255);
	createTrackbar("hiRange1", "szostka", &(hiRangeX[1]), 255);
	createTrackbar("hiRange2", "szostka", &(hiRangeX[2]), 255); 



	Mat backgroundX;

	backgroundX = imread("konstytucja.jpg", CV_LOAD_IMAGE_COLOR);


	while (waitKey(30) != 27) {
		Mat frame;
		Mat backgroundScaled;
		Mat frameMask, frameNegMask;
		Mat frameWithMask, backgroundScaledWithMask;
		Mat frameN;
		cam >> frame;
		flip(frame, frame, 1);

		resize(backgroundX, backgroundScaled, { frame.cols, frame.rows });
		cvtColor(frame, frameMask, CV_RGB2HSV);
		inRange(frameMask, Scalar(loRangeX[0], loRangeX[1], loRangeX[2]),
			Scalar(hiRangeX[0], hiRangeX[1], hiRangeX[2]), frameNegMask);

		Mat structuringElement = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));

		bitwise_not(frameNegMask, frameMask); //negacja bitów w szeregu
		frame.copyTo(frameWithMask, frameMask); // kopia obrazu z maską
		backgroundScaled.copyTo(backgroundScaledWithMask, frameNegMask);

		frameN = backgroundScaledWithMask + frameWithMask;
		Mat kopia = frameN.clone();
		//imshow("jakostam", frameN);
		//destroyWindow("jakostam");
		//imshow("kopia", kopia);
		Mat dwójka = kopia.clone();
		Mat trójka = dwójka.clone();
		Mat czwórka = trójka.clone();
		/*Mat dwójka; kopia.copyTo(dwójka);
		Mat trójka; dwójka.copyTo(trójka);
		Mat czwórka; trójka.copyTo(czwórka);*/
		Mat piatka = czwórka.clone();
		Mat szostka = piatka.clone();
		imshow("szostka", szostka);

		while (waitKey(1) == 27)
		{
			//exit(EXIT_FAILURE);
			break;
		}
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
			Point(dilation_size, dilation_size)); //wypełnianie w obiektach


		cvtColor(frame, frame, COLOR_BGR2HSV); // Tu sie wywala
		inRange(frame, Scalar(loRange[0], loRange[1], loRange[2]), Scalar(hiRange[0], hiRange[1], hiRange[2]), frame);
		Mat structuringElement = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
		morphologyEx(frame, frame, MORPH_CLOSE, structElem); // Tu też

		Moments oMoments = moments(frame);

		double dM01 = oMoments.m01;
		double dM10 = oMoments.m10;
		double dArea = oMoments.m00;

		if (dArea > 1000)//Określenie rozmiarów obiektu
		{//Wyznaczanie środka obiektu
			int x1 = dM10 / dArea;
			int y1 = dM01 / dArea;

			//Sposób wykorzystania Moments() znalezniony na githubie Microcontrolerandmore

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

				if (newPath.size() >= 25) {

					path.clear();

				}

				double stala = (::abs(itr[0].x - itr[1].x) + ::abs(itr[0].y - itr[1].y)) * 0.5; 
				// X albo Y muszą być 0 albo/też musi być jakiś mnożnik gdzie M < 1. Problem jednak byłby gdyby były wartości X i Y ujemne w układzie.
					//Litera Z
				if ((::abs(itr[0].x - itr[1].x) > stala) && (::abs(itr[0].y - itr[1].y) < stala)) {
					//cout << "Pierwsza linia" << endl;
					conditions++;
				}
				if ((::abs(itr[1].x - itr[2].x) > stala) && (::abs(itr[1].y - itr[2].y) > stala)) {
					//cout << "Druga linia" << endl;
					conditions++;
				}
				if ((::abs(itr[2].x - itr[3].x) > stala) && (::abs(itr[2].y - itr[3].y) < stala)) {
					//cout << "Trzecia linia" << endl;
					conditions++;
				}

				if (conditions == 3) {
					cout << "Jest Z!!!" << endl;
					Background4(cam, 600, 400, loRange, hiRange);

					path.clear();
				}
				/*
				 Zakomentowana bo wychwytuje ją momentalnie wśród szumu
				 //Litera L
				 if ((::abs(itr[0].x - itr[1].x) > stala) && (::abs(itr[0].y - itr[1].y) < stala)) {
				 //cout << "Pierwsza linia" << endl;
				 conditions2++;
				 }
				 if ((::abs(itr[1].x - itr[2].x) < stala) && (::abs(itr[1].y - itr[2].y) > stala)) {
				 //cout << "Druga linia" << endl;
				 conditions2++;
				 }
				 if (conditions2 == 2) {
				 cout << "Jest L!!!" << endl;
				 Background4(cam, 600, 400, loRange, hiRange);
				 path.clear();
				 }
				 */
				 //Litera N
				if ((::abs(itr[0].x - itr[1].x) < stala) && (::abs(itr[0].y - itr[1].y) > stala)) {
					//cout << "Pierwsza linia" << endl;
					conditions3++;
				}
				if ((::abs(itr[1].x - itr[2].x) < stala) && (::abs(itr[1].y - itr[2].y) > stala)) {
					//cout << "Druga linia" << endl;
					conditions3++;
				}
				if ((::abs(itr[2].x - itr[3].x) < stala) && (::abs(itr[2].y - itr[3].y) > stala)) {
					//cout << "Trzecia linia" << endl;
					conditions3++;
				}

				if (conditions3 == 3) {
					cout << "Jest N!!!" << endl;
					//Background3(cam, 600, 400, loRange, hiRange);
					path.clear();
					break;
				}

				//Litera U
				if ((::abs(itr[0].x - itr[1].x) < stala) && (::abs(itr[0].y - itr[1].y) > stala)) {
					//cout << "Pierwsza linia" << endl;
					conditions4++;
				}
				if ((::abs(itr[1].x - itr[2].x) < stala) && (::abs(itr[1].y - itr[2].y) < stala)) {
					//cout << "Druga linia" << endl;
					conditions4++;
				}
				if ((::abs(itr[2].x - itr[3].x) < stala) && (::abs(itr[2].y - itr[3].y) > stala)) {
					//cout << "Trzecia linia" << endl;
					conditions4++;
				}

				if (conditions4 == 3) {
					cout << "Jest U" << endl;
					Background4(cam, 600, 400, loRange, hiRange);
					path.clear();
				}
			}

		}

		polylines(imgOriginal, { newPath }, false, Scalar(0, 255, 0), 2);

		imshow("colourDetection", frame); //to sie wywalało
		imshow("camera", imgOriginal); //i to też
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
	
	int loRange[3] = { 20,70,26 };
	int hiRange[3] = { 44,98,66 };

	namedWindow("colourDetection", CV_WINDOW_AUTOSIZE);
	createTrackbar("loRange0", "colourDetection", &(loRange[0]),
		255);
	createTrackbar("loRange1", "colourDetection", &(loRange[1]), 255);
	createTrackbar("loRange2", "colourDetection", &(loRange[2]), 255);
	createTrackbar("hiRange0", "colourDetection", &(hiRange[0]), 255);
	createTrackbar("hiRange1", "colourDetection", &(hiRange[1]), 255);
	createTrackbar("hiRange2", "colourDetection", &(hiRange[2]), 255);

	Line(cam, 600, 400, loRange, hiRange);
	/* Nieudana próba sendInput Shift + F5 podczas zamykania programu (Co i tak by nie pomogło bo to szłoby do programu, a nie visual studia)
	INPUT input;
	WORD vkey = VK_F5; // see link below
	input.type = INPUT_KEYBOARD;
	input.ki.wScan = MapVirtualKey(vkey, MAPVK_VK_TO_VSC);
	input.ki.time = 0;
	input.ki.dwExtraInfo = 0;
	input.ki.wVk = vkey;
	input.ki.dwFlags = 0; // there is no KEYEVENTF_KEYDOWN
	SendInput(1, &input, sizeof(INPUT));
	input.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &input, sizeof(INPUT));*/

	return 0;
}