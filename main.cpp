/*
*
* -------------------------------------------------------------------------------------- -
*
*                   Multiple Face Detection
*
*-------------------------------------------------------------------------------------- -
*
* Hi, this a multiple face detection using OpenCV libraries.
*
* -------------------------------------------------------------------------------------- -
*
* Controls :
*	- Esc : end the program
*
*-------------------------------------------------------------------------------------- -
*
*Author : Dominik Panzarella
*
*Date : 25.06.2023
*
*Version : 1.0.1
*
*-------------------------------------------------------------------------------------- -

*/

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace std;
using namespace cv;


int main()
{
    VideoCapture video_capture(0);

    CascadeClassifier facedetect;
    Mat frame;
    facedetect.load("haarcascade_frontalface_default.xml");


    if (!video_capture.open(0)) {
        return 0;
    }
    
    while (true) {
        video_capture.read(frame);
        

        vector<Rect> faces;
        facedetect.detectMultiScale(frame, faces, 1.3, 5);

        cout << faces.size() << endl;

        for (int i = 0; i < faces.size(); i++) {
            rectangle(frame, faces[i].tl(), faces[i].br(), Scalar(50, 50, 255), 3);
            rectangle(frame, Point(0, 0), Point(250, 70), Scalar(50, 50, 255), FILLED);
            putText(frame, to_string(faces.size()) + " Face Found", Point(10, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 255, 255), 1);
        }

        imshow("Image", frame);
        waitKey(1);

        const int esc_key = 27;
        if (cv::waitKey(10) == esc_key) {
            break;
        }
    }
    destroyAllWindows();
    video_capture.release();
    return 0;
}