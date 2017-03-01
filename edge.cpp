#include"function_declare.h"

void edge(Mat &src, Mat &dst)
{
	Mat filter_img;
	Mat canny_img;
	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
	Mat out;
	Mat element2 = getStructuringElement(MORPH_RECT, Size(3, 3));
	Mat out2;

	bilateralFilter(src, filter_img, 5, 70, 70);
	Canny(filter_img, dst, 50, 150);
	imshow("canny_just", dst);
	dilate(dst, out, element);
	erode(out, out2, element2);
	Canny(out, dst, 50, 150);
}