//
// Created by jalen on 2016/9/8.
//

#include <stdio.h>
#include <stdlib.h>

#include "com_test_ffmjni_MainActivity.h"
#include "libavutil/avutil.h"
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"


JNIEXPORT jstring JNICALL Java_com_test_ffmjni_MainActivity_getStringFromNative
 (JNIEnv * env , jobject obj)
 {
  const char *url = "/storage/emulated/0/1.mp4";
/*
  av_register_all();

  AVFormatContext *pFormatCtx = NULL;
  int ret = avformat_open_input(&pFormatCtx, url, NULL, NULL);

  ret = avformat_find_stream_info(pFormatCtx, NULL);
  int streamNum = pFormatCtx->nb_streams;


  char wd[512];

  sprintf(wd, "AVCODEC VERSION %u\n, streamNum[%d]"
    , avcodec_version()
    , streamNum
    );
  return (*env)->NewStringUTF(env, url);
  */
    char info[10000] = { 0 };
    sprintf(info, "%s\n", avcodec_configuration());
     return (*env)->NewStringUTF(env, info);
 }