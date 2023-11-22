#pragma once
#include<opencv2/opencv.hpp>

struct Video {
	Video(std::string file_path);
	~Video();
	std::vector<cv::Mat> get_frame();

	cv::VideoCapture data;
	bool isOpened = false;
};


class Fatigue_Detection {
public:
	bool init_system(std::string file_path);
	cv::Mat get_frame(int index, int sel = 0);
	cv::Mat face_detection(int index);
	//cv::Mat dis_detection(int index);
	cv::Mat edge_detection(int index);
	cv::Mat eye_detection(int index);
	cv::Mat mouth_detection(int index);

	std::vector<cv::Mat> detection(int index);

	double get_FPS();
	int get_frameCnt();
	double get_duration();
	double get_blink_per_second(int index = -1);
	bool get_is_yawning(int index = -1);

private:
	/*��ʼ����Ƶָ�룬ʹ�����ͷ�*/
	Video* video = nullptr;
	/*����ʶ�������ֱ��Ӧ�������۲����첿*/
	cv::CascadeClassifier faceCascade;
	cv::CascadeClassifier eyeCascade;
	cv::CascadeClassifier mouthCascade;
	/*��ȡ����Ƶ���ԣ���ϵͳ��ÿ����10֡����*/
	double FPS = 0.0;
	int frameCnt = 0;
	double duration = 0.0;
	/*Ԥ���沿��׽��ͼ�������ӳ�ʶ�𣬶�׼֡λ*/
	cv::Rect lstFace = cv::Rect(0, 0, 200, 200);
	cv::Rect lstMouth = cv::Rect(0, 0, 1, 1);
	cv::Rect lstEye = cv::Rect(0, 0, 1, 1);

	bool eyes_check = true;
	int mouth_cnt = 0;
	/*ԭʼ֡��originfps*/
	std::vector<cv::Mat> frames_ori;
	/*����ʶ���֡��10fps*/
	std::vector<cv::Mat> frames;

	std::vector<cv::Mat> frames_mouth;
	std::vector<cv::Mat> frames_eyes;
	std::vector<double> bps;
	std::vector<bool> yawn;
	/*���֡*/
	//std::vector<cv::Mat> frames_dis;
	
	std::queue<int> blink;
	int blink_cnt = 0;
	double blink_per_second = 0.0;

	const double tar_fps = 10;
};