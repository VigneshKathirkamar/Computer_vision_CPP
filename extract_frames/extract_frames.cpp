#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/opencv.hpp>
#include<iostream>
#include<string>
int main()
{
    cv::VideoCapture video("/home/vignesh/222.mp4");
    std::cout<<"Hiiiii \n";
    int count = 0;

    if (!video.isOpened()) return -1;
    cv::Mat frame;

    while (video.read(frame))
    {
        count+=1;
        cv::imshow("Video",frame);
        cv::imwrite("/home/vignesh/cpp/extract_frames/extracted_frames_30/frame_"+ std::to_string(count)+".jpeg",frame);
        
        if (cv::waitKey(30) >= 0)
        {
            break;
        }

    }
    return 0;
}