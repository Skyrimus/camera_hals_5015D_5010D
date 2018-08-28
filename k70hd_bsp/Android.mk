LOCAL_PATH:= $(call my-dir)
ifeq ($(MTK_PROJECT), k70hd_bsp)
include $(call all-makefiles-under,$(LOCAL_PATH))
endif
