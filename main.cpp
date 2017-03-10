#include"function_declare.h"


using namespace cv;
void main()
{
	vector<vector<cv::Point> >  contours_dst;
	vector<Vec4i> hierarchy;

	vector<vector<cv::Point> >  contours_dst2;
	vector<Vec4i> hierarchy2;
	Mat src = imread("ball.jpg", 0);
	imshow("src", src);
	Mat edge_img(src.rows,src.cols,CV_8UC1,Scalar(0));
	Mat edge_img2(src.rows, src.cols, CV_8UC1, Scalar(0));
	Mat list_filled_img(src.rows, src.cols, CV_8UC1,Scalar(0));
	Mat list_img(src.rows, src.cols, CV_8UC1, Scalar(0));
	Mat list_img2(src.rows, src.cols, CV_8UC1, Scalar(0));

	edge(src, edge_img);
	imshow("edge", edge_img);
	edge2list(contours_dst, edge_img, hierarchy);
	drawContour(list_filled_img, contours_dst);
	namedWindow("list");
	imshow("list", list_filled_img);
	/*Canny(list_filled_img, edge_img2, 100, 200);

	edge2list(contours_dst2, edge_img2, hierarchy2);
	drawContour(list_img, contours_dst2);
	imshow("list2", list_img);*/

	waitKey();
}