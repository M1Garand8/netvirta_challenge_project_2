//
// Created by M1Garand8 on 1/10/2019.
//

#ifndef SCANNER2_OBJDETECTION_H
#define SCANNER2_OBJDETECTION_H

#include <jni.h>
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"

extern "C"
JNIEXPORT jint JNICALL
Java_com_challenge_netvirta_m1garand8_scanner2_MainActivity_objectDetectNat(JNIEnv *env,
                                                                            jobject instance,
                                                                            jlong _image,
                                                                            jint threshold);

#endif //SCANNER2_OBJDETECTION_H
