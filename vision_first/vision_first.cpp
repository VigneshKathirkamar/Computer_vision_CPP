#include <opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include <iostream>

int main( int argc, char** argv )
{
    cv::Mat image;
    int rotation = 10;
    image = cv::imread("index.png",cv::IMREAD_COLOR);
    cv::Point2f center((image.cols - 1) / 2.0, (image.rows - 1) / 2.0);
    cv::Mat rotation_matrix = getRotationMatrix2D(center, rotation, 1.0);
    cv::Mat rotated_image;
    cv::warpAffine(image, rotated_image, rotation_matrix, image.size());
    if(! image.data)
        {
            std::cout<<"Could not open file" << std::endl;
            return -1;
        }   
    //cv::namedWindow("My image", cv::WINDOW_AUTOSIZE);
    cv::imshow("My image", image);
    cv::imshow("Rotated image",rotated_image);
    cv::waitKey(0);
    return 0;
}