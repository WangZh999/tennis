#include"function_declare.h"

void edge2list(vector<vector<Point>>& contours_dst, Mat & img, vector<Vec4i>& hierarchy)
{
	vector<vector<Point> > contours_src;
	findContours(img, contours_src, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_NONE);
	for (int i = 0; i < contours_src.size(); i++)
	{
		//������Ե��Ϣ��ֻ���泤�ȴ�����Сֵ�ñ�Ե��
		if ((hierarchy[i][3] == -1) && (contours_src[i].size() > MIN_SIZE)) {
			vector<Point>points;
			for (int k = 0; k < contours_src[i].size(); k++) {
			//ȡ����Ե�ϵĵ�
				points.push_back(contours_src[i][k]);
			}

			//�����Ե�ϵĵ㵽Ŀ��������
			contours_dst.push_back(points);
			points.clear();
		}
	}
}

void drawContour(Mat & img, vector<vector<Point>>&contours,int type, Scalar color)
{
	//for (int i = 0; i < contours.size(); i++)
	//{
	//	for (int k = 0; k < contours[i].size(); k++) {
	//		circle(img, contours[i][k], 0, color);
	//	}
	//}
	for (size_t i = 0; i< contours.size(); i++)
	{
		drawContours(img, contours, (int)i, color, type, 8);
		//drawContours(img, contours, (int)i, color, 1, 8);
	}
}