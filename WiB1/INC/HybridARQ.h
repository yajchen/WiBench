/*
 * Copyright (c) 2013 The Regents of The University of Michigan
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met: redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer;
 * redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution;
 * neither the name of the copyright holders nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors: Yajing Chen
 *          Jui Wu
 *          Achilleas Anastasopoulos 
 *          Qi Zheng
 */
#pragma once
#include <cmath>
#include <stdexcept>
#include <complex>
#include <iostream>
#include "UserPara.h"
#include "BSPara.h"
#include "FIFO.h"


using namespace std;

class HybridARQ
{
private:
bool PSFlag;
bool BufFlag;


int EncDataLen;

int TxBitsLen;

int NumMaxTrans;

int *pBufferTxBits;

float *pBufferCurrSoftInfo;
float *pCombinedSoftInfo;


public:

int InBufSz[2];
int OutBufSz[2];

    HybridARQ(BSPara *pBS, UserPara* pUser);

    void GetTxBitsFromTxRateMatch(int *pEB);	
    //Store current transmitted pkt bits

    int* GetpBufferTxBits(void) const {return pBufferTxBits;}
    void GetpBufferTxBits(FIFO<int> *pReTransBuf);

    void GetSoftInfoFromRxRateMatch(float *pSI);
    void GetSoftInfoFromRxRateMatch(FIFO<float> *pInpBuf);
 
    void CombineSoftInformation(void);
   
    bool SetReTransmissionFlag(int NumErrBit,int CurTransNum);

    float* GetpCombinedSoftInfo(void) const {return pCombinedSoftInfo;}
    void GetpCombinedSoftInfo(FIFO<float> *pOutBuf);

    ~HybridARQ(void);

};
