#include <opencv2/opencv.hpp>
using namespace cv;

//-----------------------------------------------------------------------------------------------
#define WINDOW_NAME_ORIGINAL "origin pic"  
double m = 0.5;
Mat srcImage, srcImage1;
//-----------------------------------------------------------------------------------------------
int main() {
	srcImage = imread("01.JPG");                          //��Ŀ�ļ����´��ͼƬ01.JPG
	namedWindow(WINDOW_NAME_ORIGINAL, WINDOW_AUTOSIZE);   //��ʾԭʼͼ
	resize(srcImage, srcImage1, Size(), m, m);            //ͼƬ̫�󣬿�����С��ʾ
	imshow(WINDOW_NAME_ORIGINAL, srcImage1);

	waitKey(0);
	return 0;
}
