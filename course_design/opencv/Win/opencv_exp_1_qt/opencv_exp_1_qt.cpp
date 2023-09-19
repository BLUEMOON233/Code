#include "opencv_exp_1_qt.h"

opencv_exp_1_qt::opencv_exp_1_qt(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.brightness_slider->setRange(0, 100);
	ui.blur_slider->setRange(1, 20);//���û������ķ�Χ

	cv::Mat ori_image = cv::imread("./lena.jpg"); //��ȡͼƬ
	cv::Mat image; //�������� 
	double brightness_factor = 1; //��������
	int kernel_size = 1; //�˲�����С

	//��ʼ��������
	cv::cvtColor(ori_image, image, cv::COLOR_BGR2RGB);
	image.convertTo(image, -1, brightness_factor, 0);
	QImage qImage(image.data, image.cols, image.rows, image.cols * image.channels(), QImage::Format_RGB888);
	QPixmap pixmap = QPixmap::fromImage(qImage.scaled(ui.image_label->size(), Qt::KeepAspectRatio));
	ui.image_label->setPixmap(pixmap);

	if (!ori_image.empty()) {
		QObject::connect(ui.brightness_slider, &QSlider::valueChanged, [=, &brightness_factor, &kernel_size](int value)mutable {
			brightness_factor = double(value) / 20;//���ݻ�����������������
			cv::cvtColor(ori_image, image, cv::COLOR_BGR2RGB);//��ԭʼͼƬ��BGR��ʽת��ΪRGB��ʽ
			image.convertTo(image, -1, brightness_factor, 0);//�޸�ͼƬ������
			cv::blur(image, image, cv::Size(kernel_size, kernel_size));//ģ������
			QImage qImage(image.data, image.cols, image.rows, image.cols * image.channels(), QImage::Format_RGB888);//��opencv��ʽת��ΪQimage��ʽ
			QPixmap pixmap = QPixmap::fromImage(qImage.scaled(ui.image_label->size(), Qt::KeepAspectRatio));//������С
			ui.image_label->setPixmap(pixmap);//��ͼƬ����Qlabel�ؼ���
			});

		QObject::connect(ui.blur_slider, &QSlider::valueChanged, [=, &brightness_factor, &kernel_size](int value)mutable {
			kernel_size = value;//���ݻ������޸��˲����Ĵ�С
			cv::cvtColor(ori_image, image, cv::COLOR_BGR2RGB);//��ԭʼͼƬ��BGR��ʽת��ΪRGB��ʽ
			image.convertTo(image, -1, brightness_factor, 0);//�޸�ͼƬ������
			cv::blur(image, image, cv::Size(kernel_size, kernel_size));//ģ������
			QImage qImage(image.data, image.cols, image.rows, image.cols * image.channels(), QImage::Format_RGB888);//��opencv��ʽת��ΪQimage��ʽ
			QPixmap pixmap = QPixmap::fromImage(qImage.scaled(ui.image_label->size(), Qt::KeepAspectRatio));//������С
			ui.image_label->setPixmap(pixmap);//��ͼƬ����Qlabel�ؼ���
			});
	}

}

opencv_exp_1_qt::~opencv_exp_1_qt()
{}
