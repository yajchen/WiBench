include ../../../common/makefile.config

SRC = fsm.cpp Interleaver_lte.cpp TurboDecoder_c.cpp TurboEncoder_c.cpp TurboMain.cpp 
SRC += $(UTIL_DIR)/BSPara.cpp $(UTIL_DIR)/FIFO.cpp $(UTIL_DIR)/gauss.cpp $(UTIL_DIR)/matrix.cpp $(UTIL_DIR)/UserPara.cpp $(UTIL_DIR)/GeneralFunc.cpp 

EXE = Turbo.out

all: 
	$(CXX) $(SRC) $(CXXFLAGS) -pthread -o $(EXE)
	cp $(EXE) $(KERNEL_BUILD_DIR)	

clean:
	rm -rf $(EXE) *.o
