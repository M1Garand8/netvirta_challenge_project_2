//
// Created by M1Garand8 on 1/10/2019.
//

#include "objDetection.h"

extern "C"
JNIEXPORT jint JNICALL
Java_com_challenge_netvirta_m1garand8_scanner2_MainActivity_objectDetectNat(JNIEnv *env,
                                                                            jobject instance,
                                                                            jlong _image,
                                                                            jint threshold) {

    cv::Mat* image = (cv::Mat*) _image;
    if(image == nullptr)
    {
        return 0;
    }

    // Reduce the noise to avoid false circle detection
    cv::GaussianBlur(*image, *image, cv::Size(9, 9), 2, 2);

    // Convert input image to grayscale for HoughCircle aglorithm
    cv::Mat greyImage;
    cv::cvtColor(*image, greyImage, CV_RGB2GRAY);

    std::vector<cv::Vec3f> circles;

    cv::HoughCircles(greyImage, circles, CV_HOUGH_GRADIENT, 2, 50, 100, 40, 60, 80);
    //cv::HoughCircles(greyImage, circles, CV_HOUGH_GRADIENT, 1, greyImage.rows / 8, 200, 100, 20, 30);
    //cv::HoughCircles(greyImage, circles, CV_HOUGH_GRADIENT, 2, 20, 450, 60, 20, 30);
    // Argument 1: Input image mode
    // Argument 2: A vector that stores 3 values: x,y and r for each circle.
    // Argument 3: CV_HOUGH_GRADIENT: Detection method.
    // Argument 4: The inverse ratio of resolution.
    // Argument 5: Minimum distance between centers.
    // Argument 6: Upper threshold for Canny edge detector.
    // Argument 7: Threshold for center detection.
    // Argument 8: Minimum radius to be detected. Put zero as default
    // Argument 9: Maximum radius to be detected. Put zero as default

    /*for(unsigned i = 0; i < circles.size(); ++i)
    {
        cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
        // Circle center
        cv::circle(greyImage, center, 3, cv::Scalar(0, 255, 0), -1, 8, 0);
        // Circle outline
        cv::circle(greyImage, center, radius, cv::Scalar(0, 0, 255), 3, 8, 0);
    }*/

    //cv::imshow("Hough Circle Result", greyImage);

    // Get the number of circles.
    //int numCircles = circles.size();

    return circles.size();
}