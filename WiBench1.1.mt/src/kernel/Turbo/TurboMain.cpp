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
 *          Qi Zheng
 */

#include "TurboMain.h"
int RANDOMSEED;
#define TurboDec

using namespace std;

fsm FSM("rsc.txt");
Interleaver_lte<int,int> EInter;
Interleaver_lte<int,float> DInter;

#ifdef TurboEnc
int main()
{
cout<<"Turbo Encoder"<<endl;
BSPara BS;
BS.initBSPara();
UserPara User(&BS);
TurboEncoder_c TbE(&User);
//FIFO<int> TbEIn(1,TbE.InBufSz);
FIFO<int> TbEOut(1,TbE.OutBufSz);
ReadInputFromFiles(TbE.pInpBuf,(TbE.InBufSz),"TurboEncoderInput");
//GeneRandomInput(TbE.pInpBuf,TbE.InBufSz,"TurboEncoderRandomInput");
//GeneRandomInput(TbE.pInpBuf,TbE.InBufSz);
TbE.TurboEncoding(&TbEOut);
WriteOutputToFiles(&TbEOut,(TbE.OutBufSz),"testTurboEncoderOutput");
//ReadOutput(&TbEOut,(TbE.OutBufSz));
return 0;
}
#endif

#ifdef TurboDec
int main()
{
cout<<"Turbo Decoder"<<endl;
BSPara BS;
BS.initBSPara();
UserPara User(&BS);
TurboDecoder_c TbD(&BS);
//FIFO<float> TbDIn(1,TbD.InBufSz);
FIFO<int> TbDOut(1,TbD.OutBufSz);
ReadInputFromFiles(TbD.pInpBuf,TbD.InBufSz,"TurboDecoderInput");
//GeneRandomInput(TbD.pInpBuf,TbD.InBufSz,"TurboDecoderRandomInput");
//GeneRandomInput(TbD.pInpBuf,TbD.InBufSz);
TbD.TurboDecoding(&TbDOut);
WriteOutputToFiles(&TbDOut,TbD.OutBufSz,"test_TurboDecoder_Output");
//ReadOutput(&TbDOut,TbD.OutBufSz);
pthread_exit(NULL);
return 0;
}
#endif

