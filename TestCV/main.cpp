#include <iostream>
#include <opencv2/opencv.hpp>

#define OPENCV_LIB_VERSION "412"
#ifdef _DEBUG
	#define OPENCV_LIB_SUFFIX "d"
#else
	#define OPENCV_LIB_SUFFIX ""
#endif
#pragma comment(lib, "opencv_world" OPENCV_LIB_VERSION OPENCV_LIB_SUFFIX)

int main() {
	
	auto mat = cv::Mat(cv::Size(800, 600), CV_8UC3);
	
	int cnt = 0;

	while (true) {
		int b = cnt & 0x1 ? 255 : 0;
		int g = cnt & 0x2 ? 255 : 0;
		int r = cnt & 0x4 ? 255 : 0;
		auto color = cv::Scalar(b, g, r);
		std::cout << color << std::endl;

		mat = color;
		cv::imshow("WINDOW", mat);
		int key = cv::waitKey(1000);
		if (key == 0x1b) {
			break;
		}
		cnt++;
	}

	return 0;

}
