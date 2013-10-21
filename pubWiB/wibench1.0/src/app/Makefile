include ../../common/makefile.config

#ALLFILE_LIST := ${shell find $(WiBench_INSTALL_DIR)/src/kernel -type d -print}
#KERNEL_LIST := $(filter-out $(WiBench_INSTALL_DIR)/src/kernel, $(ALLFILE_LIST))
ALLFILE_LIST := ${sort ${dir ${wildcard $(WiBench_INSTALL_DIR)/src/app/*/}}}
APP_LIST := $(filter-out $(WiBench_INSTALL_DIR)/src/app/, $(ALLFILE_LIST))


all:
	for app in $(APP_LIST); do \
	  cd $$app; \
	  make; \
	  cd ..; \
	  done;

clean:
	for app in $(APP_LIST); do \
	  cd $$app; \
	  make clean; \
	  cd ..; \
	  done;

