LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_CFLAGS += -fPIE  
LOCAL_LDFLAGS += -fPIE -pie
LOCAL_MODULE    := binary

LOCAL_SRC_FILES := s.c

include $(BUILD_EXECUTABLE)