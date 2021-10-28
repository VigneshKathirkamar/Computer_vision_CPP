#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/opencv.hpp>
#include<iostream>
#include<string>
int main(int argc, char **argv)
{
    //cv::VideoCapture video("/home/vignesh/222.mp4");
    cv::VideoCapture video(argv[1]);
    int count = 0;

    if (!video.isOpened()) return -1;
    cv::Mat frame;

    while (video.read(frame))
    {
        count+=1;
        std::string folder = argv[2];
        cv::imshow("Video",frame);
        cv::imwrite(folder+"/frame_"+ std::to_string(count)+".jpeg",frame);
        
        if (cv::waitKey(30) >= 0)
        {
            break;
        }

    }
    return 0;
}