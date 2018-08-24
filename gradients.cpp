#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

class Device {
    float maxIntensity;
    float minIntensity;
    int dimensions;
  public:
    void set_values (float,float, int);
};

void Device::set_values (float min, float max, int dim) {
	maxIntensity = max;
	maxIntensity = min;
	dimensions = dim;
}

Mat readBitmapFromImage(string imageName) {
	Mat image;
    image = imread(imageName.c_str(), CV_LOAD_IMAGE_GRAYSCALE); // Read the file

    if(image.empty()) // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl;
    }
    return image;
}

Mat resizeBitmap(Mat bitmap, float newRows, float newCols){
	// width and height in pixels
	Size size(newRows,newCols);
    cout <<  size << "SIZE" << std::endl;	
    cout <<  bitmap.size() << "MAT" << std::endl;

    Mat dst;//dst image
	resize(bitmap,dst,size);
	return dst;
}



int main(int argc, char** argv)
{
    string imageName("using.png"); // by default
    if( argc > 1)
    {
        imageName = argv[1];
    }

    Mat bmp = readBitmapFromImage(imageName);

    imwrite("result.png", resizeBitmap(bmp,150,150));
    return 0;
}