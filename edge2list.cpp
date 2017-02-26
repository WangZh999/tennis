#include"function_declare.h"

void edge2list(vector<vector<Point>>& contours_dst, Mat & img, vector<Vec4i> hierarchy)
{
	vector<vector<Point>> contours_src;
	findContours(img, contours_src, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_NONE);
	for (int i = 0; i < contours_src.size(); i++)
	{
		//遍历边缘信息，只保存长度大于最小值得边缘；
		if ((hierarchy[i][3] == -1) && (contours_src[i].size() > MIN_SIZE)) {
			vector<Point>points;
			for (int k = 0; k < contours_src[i].size(); k++) {
			//取出边缘上的点
				points.push_back(contours_src[i][k]);
			}

			//保存边缘上的点到目标向量；
			contours_dst.push_back(points);
			points.clear();
		}
	}
}

void drawContour(Mat img, vector<vector<Point>>contours, Scalar color)
{
	for (int i = 0; i < contours.size(); i++)
	{
		drawContours(img, contours, i, color);
	}
}