#include <jni.h>
#include <string>
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"

extern "C" JNIEXPORT jstring JNICALL
Java_com_challenge_netvirta_m1garand8_scanner2_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

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

    // Convert input image to grayscale for HoughCircle aglorithm
    cv::Mat greyImage;
    cv::cvtColor(*image, greyImage, CV_BGR2GRAY);

    std::vector<cv::Vec3f> circles;

    cv::HoughCircles(greyImage, circles, CV_HOUGH_GRADIENT, 2, 20, 450, 60, 0, 0);
    // Argument 1: Input image mode
    // Argument 2: A vector that stores 3 values: x,y and r for each circle.
    // Argument 3: CV_HOUGH_GRADIENT: Detection method.
    // Argument 4: The inverse ratio of resolution.
    // Argument 5: Minimum distance between centers.
    // Argument 6: Upper threshold for Canny edge detector.
    // Argument 7: Threshold for center detection.
    // Argument 8: Minimum radius to be detected. Put zero as default
    // Argument 9: Maximum radius to be detected. Put zero as default

    // Get the number of circles.
    //int numCircles = circles.size();

    return circles.size();
}