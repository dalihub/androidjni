MODULE_NAME = dali
LOCAL_DIR = $(CURDIR)
SRC_PATH := $(LOCAL_DIR)/../..
NDK_PROJECT_PATH = null
NDK_OUT = $(LOCAL_DIR)/obj
NDK_LIBS_OUT = $(LOCAL_DIR)/lib
NDK_APPLICATION_MK = $(LOCAL_DIR)/Application.mk
include $(ANDROID_NDK)/build/core/build-local.mk

.PHONY: headers
headers:
	mkdir -p $(LOCAL_DIR)/include/dali/public-api
	mkdir -p $(LOCAL_DIR)/include/dali/devel-api
	mkdir -p $(LOCAL_DIR)/include/dali/integration-api/adaptors
	mkdir -p $(LOCAL_DIR)/include/dali-toolkit/public-api
	mkdir -p $(LOCAL_DIR)/include/dali-toolkit/devel-api
	(cd $(SRC_PATH)/dali-core/dali/public-api ; find . -name "*.h" | xargs cp --parents -t  $(LOCAL_DIR)/include/dali/public-api )
	(cd $(SRC_PATH)/dali-core/dali/devel-api ; find . -name "*.h" | xargs cp --parents -t  $(LOCAL_DIR)/include/dali/devel-api )
	(cd $(SRC_PATH)/dali-core/dali/integration-api ; find . -name "*.h" | xargs cp --parents -t $(LOCAL_DIR)/include/dali/integration-api )
	cp  $(SRC_PATH)/dali-adaptor/dali/dali.h ./include/dali/
	(cd $(SRC_PATH)/dali-adaptor/dali/public-api ; find . -name "*.h" | xargs cp --parents -t $(LOCAL_DIR)/include/dali/public-api )
	(cd $(SRC_PATH)/dali-adaptor/dali/devel-api ; find . -name "*.h" | xargs cp --parents -t $(LOCAL_DIR)/include/dali/devel-api )
	(cd $(SRC_PATH)/dali-adaptor/dali/integration-api ; find . -name "*.h" | xargs cp --parents -t $(LOCAL_DIR)/include/dali/integration-api/adaptors )
	cp  $(SRC_PATH)/dali-toolkit/dali-toolkit/dali-toolkit.h ./include/dali-toolkit/
	(cd $(SRC_PATH)/dali-toolkit/dali-toolkit/public-api ; find . -name "*.h" | xargs cp --parents -t $(LOCAL_DIR)/include/dali-toolkit/public-api )
	(cd $(SRC_PATH)/dali-toolkit/dali-toolkit/devel-api ; find . -name "*.h" | xargs cp --parents -t $(LOCAL_DIR)/include/dali-toolkit/devel-api )


