//
// Created by jalen on 2016/9/8.
//

#include <stdio.h>
#include <stdlib.h>
#include <android/log.h>

#include "com_test_ffmjni_MainActivity.h"
#include "libavutil/avutil.h"
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libavfilter/avfilter.h"

static const char *kTAG = "jni";

#define LOGI(...)   ((void)__android_log_print(ANDROID_LOG_INFO, kTAG, __VA_ARGS__))
#define LOGE(...)   ((void)__android_log_print(ANDROID_LOG_ERROR, kTAG, __VA_ARGS__))

/**
 * com.leixiaohua1020.sffmpegandroidhelloworld.MainActivity.avfilterinfo()
 * AVFilter Support Information
 */
JNIEXPORT jstring JNICALL Java_com_test_ffmjni_MainActivity_avfilterinfo(JNIEnv *env, jobject obj)
{
    char info[40000] = { 0 };
    LOGI("avfilter before init");
    avfilter_register_all();
    LOGI("avfilter inited");
    AVFilter *f_temp = (AVFilter *)avfilter_next(NULL);
    LOGI("f_temp->name : %s", f_temp->name);
    while (f_temp != NULL){
        sprintf(info, "%s[%10s]\n", info, f_temp->name);
        f_temp = f_temp->next;  // 雷大神故意把这句漏掉了
    }
    //LOGE("%s", info);

    return (*env)->NewStringUTF(env, info);
}

JNIEXPORT jstring JNICALL Java_com_test_ffmjni_MainActivity_avcodecinfo
 (JNIEnv * env , jobject obj)
 {
    char info[40000] = { 0 };

        av_register_all();

        AVCodec *c_temp = av_codec_next(NULL);

        while(c_temp!=NULL){
            if (c_temp->decode!=NULL){
                sprintf(info, "%s[Dec]", info);
            }
            else{
                sprintf(info, "%s[Enc]", info);
            }
            switch (c_temp->type){
            case AVMEDIA_TYPE_VIDEO:
                sprintf(info, "%s[Video]", info);
                break;
            case AVMEDIA_TYPE_AUDIO:
                sprintf(info, "%s[Audio]", info);
                break;
            default:
                sprintf(info, "%s[Other]", info);
                break;
            }
            sprintf(info, "%s[%10s]\n", info, c_temp->name);


            c_temp=c_temp->next;
        }
        //LOGE("%s", info);

        return (*env)->NewStringUTF(env, info);
 }
JNIEXPORT jstring JNICALL Java_com_test_ffmjni_MainActivity_avformatinfo
 (JNIEnv * env , jobject obj)
 {
    char info[40000] = { 0 };

    av_register_all();

    AVInputFormat *if_temp = av_iformat_next(NULL);
    AVOutputFormat *of_temp = av_oformat_next(NULL);
    //Input
    while(if_temp!=NULL){
        sprintf(info, "%s[In ][%10s]\n", info, if_temp->name);
        if_temp=if_temp->next;
    }
    //Output
    while (of_temp != NULL){
        sprintf(info, "%s[Out][%10s]\n", info, of_temp->name);
        of_temp = of_temp->next;
    }
    //LOGE("%s", info);
    return (*env)->NewStringUTF(env, info);
 }

JNIEXPORT jstring JNICALL Java_com_test_ffmjni_MainActivity_getStringFromNative
 (JNIEnv * env , jobject obj)
 {
  const char *url = "/storage/emulated/0/1.mp4";
    char info[10000] = { 0 };
    sprintf(info, "%s\n", avcodec_configuration());
     return (*env)->NewStringUTF(env, info);
 }