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

#include "ModDemodMain.h"
#define Demod
int RANDOMSEED;
using namespace std;

#ifdef Mod
int main()
{
cout<<"Modulation"<<endl;
BSPara BS;
BS.initBSPara();
UserPara User(&BS);
Modulation Md(&User);
//FIFO<int> MdIn(1,Md.InBufSz);
FIFO<complex<float> > MdOut(1,Md.OutBufSz);
ReadInputFromFiles(Md.pInpBuf,(Md.InBufSz),"ModulationInput");
//GeneRandomInput(Md.pInpBuf,Md.InBufSz,"ModulationRandomInput");
//GeneRandomInput(Md.pInpBuf,Md.InBufSz);
Md.Modulating(&MdOut);
WriteOutputToFiles(&MdOut,(Md.OutBufSz),"testModulationRandomOutputReal","testModulationRandomOutputImag");
//ReadOutput(&MdOut,(Md.OutBufSz));
return 0;
}
#endif

#ifdef Demod
int main()
{
cout<<"Demodulation"<<endl;
BSPara BS;
BS.initBSPara();
UserPara User(&BS);
Demodulation Dmd(&BS);
//FIFO<complex<float> > DmdIn(1,Dmd.InBufSz);
FIFO<float> DmdOut(1,Dmd.OutBufSz);
float awgn_sigma = 0.193649;//this value is for the standard input  see "AWGNSigma"
ReadInputFromFiles(Dmd.pInpBuf,(Dmd.InBufSz),"DemodulationInputReal","DemodulationInputImag");
//GeneRandomInput(Dmd.pInpBuf,Dmd.InBufSz,"DemodulationRandomInputReal","DemodulationRandomInputImag");
//GeneRandomInput(Dmd.pInpBuf,Dmd.InBufSz);
Dmd.Demodulating(&DmdOut,awgn_sigma);
WriteOutputToFiles(&DmdOut,(Dmd.OutBufSz),"testDemodulationOutput");
//ReadOutput(&DmdOut,(Dmd.OutBufSz));
return 0;
}
#endif

