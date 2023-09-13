#include <iostream>
#include <opencv2/opencv.hpp>

void exp_1() {
	cv::Mat pic = cv::imread("lena.jpg"); //���뵱ǰĿ¼����Ϊlena��jpg��ʽͼƬ��������Ϊpic��Mat��������
	cv::namedWindow("output", cv::WINDOW_AUTOSIZE); //����ͼƬ��ʾ�Զ�������С�Ĵ���
	cv::imshow("output", pic); //��ʾ����pic
	cv::waitKey(0); //�ȴ���������
	cv::imwrite("lena_copy.jpg", pic); //������picд�뵱ǰĿ¼����Ϊlena_copy��jpg��ʽ�ļ���
}

void exp_2() {
	cv::Mat pic = cv::imread("lena.jpg");
	//������ʽ1:(ʹ��.at<>()����)
	for (int y = 0; y < pic.rows; ++y) {
		for (int x = 0; x < pic.cols; ++x) {
			cv::Vec3b pixel = pic.at<cv::Vec3b>(y, x); // ��ȡ����ֵ
			//std::cout << pixel << '\n';
		}
	}
	//������ʽ2:(ʹ��ָ���������)
	// ָ���һ�е���������
	for (cv::Vec3b* pixelPtr = pic.ptr<cv::Vec3b>(0); pixelPtr != pic.ptr<cv::Vec3b>(pic.rows); pixelPtr += pic.step1()) {
		for (int x = 0; x < pic.cols; ++x) {
			cv::Vec3b& pixel = pixelPtr[x]; // ��ȡ����ֵ
			//std::cout << pixel << '\n';
		}
	}
	//������ʽ3:(ʹ�õ�������������)
	for (cv::Mat_<cv::Vec3b>::iterator it = pic.begin<cv::Vec3b>(); it != pic.end<cv::Vec3b>(); ++it) {
		cv::Vec3b& pixel = (*it); // ��ȡ����ֵ
		//std::cout << pixel << '\n';
	}
}

void exp_3() {
	cv::Mat pic = cv::imread("lena.jpg", 0); //����Ҷ�ͼƬ��
	cv::Mat enhanced_pic;
	cv::equalizeHist(pic, enhanced_pic); //����ֱ��ͼ���⻯�㷨�ԻҶ�ͼƬ������ǿ��
	cv::imshow("enhanced_lena", enhanced_pic); //��ʾֱ��ͼ���⻯�㷨��ǿ��Ҷ�ͼƬ��
	double alpha = 1.5;
	enhanced_pic = pic * alpha; //��ʾ���ԻҶ���ǿ��
	cv::imshow("lena", enhanced_pic); //��ʾ���ԻҶ���ǿͼƬ��
	cv::waitKey(0);
}

void exp_4() { //Spicy and Salted lena
	cv::Mat pic = cv::imread("lena.jpg");
	int numNoisePoints = 300; //���ý����������ص������
	for (int i = 0; i < numNoisePoints; i++) {
		int x = rand() % pic.cols; // ������ɺ�����
		int y = rand() % pic.rows; // �������������
		if (rand() % 2 == 0) { // ���ѡ���������ͣ�������
			pic.at<cv::Vec3b>(y, x) = cv::Vec3b(0, 0, 0); // ��ӽ���������ɫ���أ�
		}
		else {
			pic.at<cv::Vec3b>(y, x) = cv::Vec3b(255, 255, 255); // �������������ɫ���أ�
		}
	}
	cv::namedWindow("Spicy and Salted Lena", cv::WINDOW_NORMAL); 
	cv::imshow("Spicy and Salted Lena", pic); //��ʾ���뽷���������ͼƬ
	cv::waitKey(0);
}

void exp_5() {
	cv::Mat ori_pic = cv::imread("lena.jpg"); //����ʶ�ͼƬ��
	double alpha = 1.5; //�������ӡ�
	cv::Mat bri_pic = ori_pic * alpha; //ʵ�ֲ�ɫͼƬ������
	cv::namedWindow("origin picture", cv::WINDOW_NORMAL);
	cv::imshow("origin picture", ori_pic); //��ʾԭͼƬ
	cv::namedWindow("brightened picture", cv::WINDOW_NORMAL);
	cv::imshow("brightened picture", bri_pic); //��ʾ������ͼƬ
	cv::waitKey(0);
}

int main(int argc, const char* argv[]) {
	//exp_1();
	//exp_2();
	//exp_3();
	//exp_4();
	exp_5();
	return 0;
}
