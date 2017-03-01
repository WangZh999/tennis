#ifndef FUNCTION_DECLARE_H
#define FUNCTION_DECLARE_H


#include "include_all.h"

#define pi (double)3.1415926

#define MIN_SIZE 20

#define R_D (double)(1)

#define maxB   (uchar)100
#define minB   (uchar)0
#define maxG   (uchar)255
#define minG   (uchar)80
#define maxR   (uchar)255
#define minR   (uchar)50

#define maxG_B   (uchar)255
#define minG_B   (uchar)0
#define maxR_B   (uchar)255
#define minR_B   (uchar)0

/*��ȡ��Ե��srcΪ��ͨ����dstΪ��ֵͼ��*/
void edge(Mat &src, Mat &dst);
/*����Ե��Ϣ��������*/
void edge2list(vector<vector<Point>> & contours_des, Mat & img, vector<Vec4i> &hierarchy);
/*����������ȡ��Ϣ��������Ե��ͼ��ķ�ʽ���ֳ���*/
void drawContour(Mat& img, vector<vector<Point>> &contours, int type = 1, Scalar color = Scalar(255));
/*���һ���뾶��Բ�εķ�Χ����ɫ��Ϣ�Ƿ����Ҫ��*/
bool checkColor(Mat * img, Point2i &center, double r_d, double proportion = 0.5);

#endif // !FUNCTION_DECLARE_H

