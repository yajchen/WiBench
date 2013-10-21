C = gcc
CC = g++
UTILPATH = ../Util/
INCPATH = ../INC/

SRC = $(UTILPATH)BSPara.cpp ../Channel/Channel.cpp ../ModDemod/Demodulation.cpp ../ScrambDescramb/Descramble.cpp ../Equalizer/Equalizer_s.cpp $(UTILPATH)GeneralFunc.cpp LTESys.cpp $(UTILPATH)FIFO.cpp ../Turbo/fsm.cpp $(UTILPATH)gauss.cpp ../Turbo/Interleaver_lte.cpp $(UTILPATH)matrix.cpp ../ModDemod/Modulation.cpp ../RateMatcher/RxRateMatch.cpp ../SCFDMA/SCFDMADemodulation.cpp ../SCFDMA/SCFDMAModulation.cpp ../ScrambDescramb/Scramble.cpp ../RateMatcher/SubblockInterleaver_lte.cpp ../SubCarrierMapDemap/SubCarrierDemap.cpp ../SubCarrierMapDemap/SubCarrierMap.cpp ../TransformPreDec/TransformDecoder.cpp ../TransformPreDec/TransformPrecoder.cpp ../Turbo/TurboDecoder_c.cpp ../Turbo/TurboEncoder_c.cpp ../RateMatcher/TxRateMatch.cpp $(UTILPATH)UserPara.cpp
EXE = ltesys0.out

hSRC = $(UTILPATH)BSPara.cpp ../Channel/Channel.cpp ../ModDemod/Demodulation.cpp ../ScrambDescramb/Descramble.cpp ../Equalizer/Equalizer_s.cpp ../HybARQ/HybridARQ.cpp $(UTILPATH)GeneralFunc.cpp LTESysHARQ.cpp $(UTILPATH)FIFO.cpp ../Turbo/fsm.cpp $(UTILPATH)gauss.cpp ../Turbo/Interleaver_lte.cpp $(UTILPATH)matrix.cpp ../ModDemod/Modulation.cpp ../RateMatcher/RxRateMatch.cpp ../SCFDMA/SCFDMADemodulation.cpp ../SCFDMA/SCFDMAModulation.cpp ../ScrambDescramb/Scramble.cpp ../RateMatcher/SubblockInterleaver_lte.cpp ../SubCarrierMapDemap/SubCarrierDemap.cpp ../SubCarrierMapDemap/SubCarrierMap.cpp ../TransformPreDec/TransformDecoder.cpp ../TransformPreDec/TransformPrecoder.cpp ../Turbo/TurboDecoder_c.cpp ../Turbo/TurboEncoder_c.cpp ../RateMatcher/TxRateMatch.cpp $(UTILPATH)UserPara.cpp
hEXE = ltesysHarq0.out

lte: $(SRC)
	$(CC) $(SRC) -I $(INCPATH) -o $(EXE) -lfftw3f -O3

lteHarq: $(hSRC)
	$(CC) $(hSRC) -I $(INCPATH) -o $(hEXE) -lfftw3f -O3

clean:
	rm $(EXE) $(hEXE) -rf
