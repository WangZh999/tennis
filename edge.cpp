#include"function_declare.h"

void edge(Mat &src, Mat &dst)
{
	Mat filter_img;
	Mat canny_img;
	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
	Mat out;
	Mat element2 = getStructuringElement(MORPH_RECT, Size(3, 3));
	Mat out2, out3;//out3:阈值分割后的图像；out2

	uchar *dst_data;
	uchar *out_data;

	bilateralFilter(src, filter_img, 5, 70, 70);
	Canny(filter_img, dst, 50, 150);
	threshold(src, out3, THRESHOLD, 255, THRESH_BINARY);
	imshow("threshold", out3);
	for (int i = 0; i < dst.rows; i++)
	{
		dst_data = dst.ptr(i);
		out_data = out3.ptr(i);
		for (int j = 0; j < dst.cols; j++){
			if (dst_data[j] > 100){
				if (out_data[j] == 0){
					dst_data[j] = 0;
				}
			}
		}
	}
	//imshow("canny_just", dst);
	//dilate(dst, out, element);
	//erode(out, out2, element2);
	//Canny(out, dst, 50, 150);
}