C = gcc
CC = g++
UTILPATH = ../Util/
INCPATH = ../INC/
SRC = $(UTILPATH)BSPara.cpp $(UTILPATH)FIFO.cpp $(UTILPATH)gauss.cpp $(UTILPATH)matrix.cpp $(UTILPATH)UserPara.cpp $(UTILPATH)GeneralFunc.cpp SubCarrierMapDemapMain.cpp SubCarrierDemap.cpp  SubCarrierMap.cpp
EXE = SCMapDemap.out

all: $(SRC)
	$(CC) $(SRC) -I $(INCPATH) -o $(EXE) -O3

clean:
	rm $(EXE) -rf
