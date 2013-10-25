include common/makefile.config

KERNEL_LIST := ${shell find $(WiBench_INSTALL_DIR)/src/kernel -type d -print}
APP_LIST := ${shell find $(WiBench_INSTALL_DIR)/src/app -type d -print}
#APP_EXE_LIST := ${shell find $(WiBench_INSTALL_DIR)/build/app -type d -print}

all: kernel app

kernel: 
	cd $(KERNEL_DIR); make;
	cp $(WiBench_INSTALL_DIR)/dep/rsc.txt  $(WiBench_INSTALL_DIR)/build/kernel

app:
	cd $(APP_DIR); make;
	cp $(WiBench_INSTALL_DIR)/dep/rsc.txt  $(WiBench_INSTALL_DIR)/build/app

clean:
	cd $(WiBench_INSTALL_DIR)/build/kernel; rm -rf *;
	cd $(WiBench_INSTALL_DIR)/build/app; rm -rf *;
	cd $(WiBench_INSTALL_DIR)/src/kernel; make clean;
	cd $(WiBench_INSTALL_DIR)/src/app; make clean;
