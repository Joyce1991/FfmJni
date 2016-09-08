LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
 
LOCAL_MODULE := ovsplayer
LOCAL_LDLIBS := \
 -lm \
 -ljnigraphics \
 -landroid \
 -llog \
 -lz \
 
LOCAL_SHARED_LIBRARIES := libavformat libavcodec libswscale libavutil
 
LOCAL_SRC_FILES := \
 C:/Users/jalen/StudioProjects/FfmJni/app/src/main/jni/ovsplayer.c \
 
LOCAL_C_INCLUDES += C:/Users/jalen/StudioProjects/FfmJni/app/src/main/jni
LOCAL_C_INCLUDES += C:/Users/jalen/StudioProjects/FfmJni/app/src/debug/jni
 
include $(BUILD_SHARED_LIBRARY)
$(call import-module,ffmpeg/android/arm)