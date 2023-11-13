#include<iostream>
#include<opencv2/opencv.hpp>

cv::Mat Erode(cv::Mat& image, cv::Mat S, int sel) {
	cv::Mat ret = image.clone();
	//תΪ��ֵͼ��
	for (int r = 0; r < image.rows; r++) for (int c = 0; c < image.cols; c++) {
		if (image.at<uchar>(r, c) <= 159) image.at<uchar>(r, c) = 0;
		else image.at<uchar>(r, c) = 255;
	}
	int S_H = S.rows / 2, S_W = S.cols / 2;
	//��ʴ��������Դͼ�����Ը�����Ϊ���ĵĽṹԪ������ֵȫ��������򷵻�true�����򷵻�false
	auto erode = [&](int r, int c) -> bool {
		for (int y = 0; y < S.rows; y++) {
			for (int x = 0; x < S.cols; x++) {
				if (S.at<uchar>(y, x) == sel) continue;
				if (image.at<uchar>(r + y, c + x) != S.at<uchar>(y, x))
					return false;
			}
		}
		return true;
		};
	for (int r = S_H; r < image.rows - S_H; r++) {
		for (int c = S_W; c < image.cols - S_W; c++) {
			int tar = erode(r - S_H, c - S_W);
			if (tar) {
				ret.at<uchar>(r, c) = 255 - sel;
			}
			else ret.at<uchar>(r, c) = sel;
		}
	}
	return ret;
}

cv::Mat Dilate(cv::Mat& image, cv::Mat& S_t, int sel) {
	cv::Mat ret = image.clone();
	cv::Mat S = S_t.clone();
	//ͼ����
	int width = S.cols;
	int height = S.rows;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width / 2; x++) {
			uchar pixel1 = S_t.at<uchar>(y, x);
			uchar pixel2 = S_t.at<uchar>(y, width - x - 1);
			S.at<uchar>(y, x) = pixel2;
			S.at<uchar>(y, width - x - 1) = pixel1;
		}
	}
	//תΪ��ֵͼ��
	for (int r = 0; r < image.rows; r++) for (int c = 0; c < image.cols; c++) {
		if (image.at<uchar>(r, c) <= 159) image.at<uchar>(r, c) = 0;
		else image.at<uchar>(r, c) = 255;
	}

	int S_H = S.rows / 2, S_W = S.cols / 2;
	//��ʴ��������Դͼ�����Ը�����Ϊ���ĵĽṹԪ������ֵȫ��������򷵻�true�����򷵻�false
	auto erode = [&](int r, int c) -> bool {
		for (int y = 0; y < S.rows; y++) {
			for (int x = 0; x < S.cols; x++) {
				if (S.at<uchar>(y, x) == sel) continue;
				if (image.at<uchar>(r + y, c + x) == S.at<uchar>(y, x))
					return true;
			}
		}
		return false;
		};
	for (int r = S_H; r < image.rows - S_H; r++) {
		for (int c = S_W; c < image.cols - S_W; c++) {
			int tar = erode(r - S_H, c - S_W);
			if (tar) {
				ret.at<uchar>(r, c) = 255 - sel;
			}
			else ret.at<uchar>(r, c) = sel;
		}
	}
	return ret;
}

cv::Mat Open(cv::Mat& image, cv::Mat& S, int sel) {
	//����ԭͼ���Ƚ��и�ʴ�����ٽ�����������
	cv::Mat ret = image.clone();
	ret = Erode(ret, S, sel);
	ret = Dilate(ret, S, sel);
	return ret;
}

cv::Mat Close(cv::Mat& image, cv::Mat& S, int sel) {
	//����ԭͼ���Ƚ������������ٽ��и�ʴ����
	cv::Mat ret = image.clone();
	ret = Dilate(ret, S, sel);
	ret = Erode(ret, S, sel);
	return ret;
}

cv::Mat Skeletonization(cv::Mat& image, cv::Mat S, int sel) {
	cv::Mat ret = image.clone();
	cv::Mat now = image.clone();
	//��ʼ�����ؾ���
	for (int r = 0; r < ret.rows; r++) {
		for (int c = 0; c < ret.cols; c++) {
			ret.at<uchar>(r, c) = 0;
		}
	}

	int lst = -1;
	for (int i = 0; i < 1000; i++) {
		//��ͼ����и�ʴ����
		cv::Mat image_erode = Erode(now, S, sel);
		//��ѯ��ǰͼ�����ص�ҶȲ�Ϊ0�ĵ�����
		int cnt = cv::countNonZero(image_erode);
		//�����������仯ʱ������ʴ���������ԭͼ�������ı䣬�������
		if (cnt == lst) break;
		lst = cnt;
		cv::Mat image_open = Dilate(image_erode, S, sel);
		//����ͼ�������һ������ͼ���ȥ��������ͼ��
		ret += (now - image_open);
		//���²���ͼ��
		now = image_erode;
	}
	return ret;
}

cv::Mat get_image_edge(cv::Mat& image, cv::Mat S, int sel) {
	//��ͼ�������ʴ����
	cv::Mat image_erode = Erode(image, S, 0);
	//ԭͼ���ȥ��ʴ����
	cv::Mat image_edge = image - image_erode;
	return image_edge;
}


int main() {
	//cv::Mat circle = cv::imread("./circle.png", 0);
	//cv::Mat cells = cv::imread("./cells.png", 0);
	//cv::Mat cells_erode = Erode(cells, circle, 255);

	//cv::namedWindow("circle", cv::WINDOW_NORMAL);
	//cv::imshow("circle", circle);
	//cv::namedWindow("cells", cv::WINDOW_NORMAL);
	//cv::imshow("cells", cells);
	//cv::namedWindow("cells_erode", cv::WINDOW_NORMAL);
	//cv::imshow("cells_erode", cells_erode);

	//cv::Mat circle = cv::imread("./circle.png", 0);
	//cv::Mat cells = cv::imread("./cells.png", 0);
	//cv::Mat cells_dilate = Dilate(cells, circle, 255);
	//cv::namedWindow("circle", cv::WINDOW_NORMAL);
	//cv::imshow("circle", circle);
	//cv::namedWindow("cells", cv::WINDOW_NORMAL);
	//cv::imshow("cells", cells);
	//cv::namedWindow("cells_dilate", cv::WINDOW_NORMAL);
	//cv::imshow("cells_dilate", cells_dilate);

	//cv::Mat circle = cv::imread("./circle.png", 0);
	//cv::Mat cells = cv::imread("./cells.png", 0);
	//cv::Mat cells_open = Open(cells, circle, 255);
	//cv::namedWindow("cells", cv::WINDOW_NORMAL);
	//cv::imshow("cells", cells);
	//cv::namedWindow("cells_open", cv::WINDOW_NORMAL);
	//cv::imshow("cells_open", cells_open);

	//cv::Mat circle = cv::imread("./circle.png", 0);
	//cv::Mat cells = cv::imread("./cells.png", 0);
	//cv::Mat cells_close = Close(cells, circle, 255);

	//cv::namedWindow("cells", cv::WINDOW_NORMAL);
	//cv::imshow("cells", cells);
	//cv::namedWindow("cells_close", cv::WINDOW_NORMAL);
	//cv::imshow("cells_close", cells_close);

	//cv::Mat sztx = cv::imread("./shuzituxiang.png", 0);
	//cv::Mat rec = cv::imread("./rec.png", 0);

	//cv::Mat sztx_edge = get_image_edge(sztx, rec, 0);
	//cv::namedWindow("sztx", cv::WINDOW_NORMAL);
	//cv::imshow("sztx", sztx);
	//cv::namedWindow("sztx_edge", cv::WINDOW_NORMAL);
	//cv::imshow("sztx_edge", sztx_edge);
	//cv::Mat sztx_skeleton = Skeletonization(sztx, rec, 0);
	//cv::namedWindow("sztx", cv::WINDOW_NORMAL);
	//cv::imshow("sztx", sztx);
	//cv::namedWindow("sztx_skeleton", cv::WINDOW_NORMAL);
	//cv::imshow("sztx_skeleton", sztx_skeleton);

	cv::Mat noise = cv::imread("./noise.png", 0);
	cv::Mat fixed = cv::imread("./fixed.png", 0);

	//��ͼ���Ƚ��п�����
	cv::Mat final = Open(noise, fixed, 255);
	//�ٶ�ͼ����б�����
	final = Close(final, fixed, 255);

	cv::namedWindow("noise", cv::WINDOW_NORMAL);
	cv::imshow("noise", noise);
	cv::namedWindow("final", cv::WINDOW_NORMAL);
	cv::imshow("final", final);


	cv::waitKey(0);
	return 0;
}