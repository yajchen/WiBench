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

#include "HybridARQ.h"

HybridARQ::HybridARQ(BSPara *pBS,UserPara *pUser)
{
PSFlag = (*pBS).ProcessingStatusFlag;
BufFlag=(*pBS).BufferSizeFlag;

int DataLength = (*pBS).DataLengthPerUser;
int Rate=3;
int LastBlockLen=(DataLength%6144);
int NumBlock=(DataLength-LastBlockLen)/6144+1;
EncDataLen=(NumBlock-1)*(6144*Rate+12)+1*(LastBlockLen*Rate+12);

int NumLayer=(*pUser).NumLayer;
int NInfoBits=(*pUser).NInfoBits;
TxBitsLen=NumLayer*NInfoBits;

NumMaxTrans = 2;

pBufferTxBits=new int[TxBitsLen];

//pBufferPrevSoftInfo=new float[EncDataLen];
pBufferCurrSoftInfo=new float[EncDataLen];
pCombinedSoftInfo=new float[EncDataLen];

for(int i=0;i<EncDataLen;i++)
{*(pCombinedSoftInfo+i)=(float)0;}

InBufSz[0]=1;InBufSz[1]=EncDataLen;
OutBufSz[0]=1;OutBufSz[1]=EncDataLen;
if(BufFlag)
{
  cout<<"Rx::HARQ"<<endl;
  cout<<"Input buffer size is "<<"{"<<InBufSz[0]<<" , "<<InBufSz[1]<<"}"<<"  float"<<endl;
  cout<<"Output buffer size is "<<"{"<<OutBufSz[0]<<" , "<<OutBufSz[1]<<"}"<<"  float"<<endl; 
}
else
{}

}

void HybridARQ::GetTxBitsFromTxRateMatch(int *pEB)
{
  if(PSFlag){cout<<"HARQ: GetTxBitsFromTXRM"<<endl;}
  for(int i=0;i<TxBitsLen;i++)
  {
    *(pBufferTxBits+i)=*(pEB+i);
  }
  if(PSFlag){cout<<"HARQ: GetTxBitsFromTXRM Completed"<<endl;}
}

void HybridARQ::GetpBufferTxBits(FIFO<int> *pReTransBuf)
{bool WriteFlag = (*pReTransBuf).Write(pBufferTxBits);}

void HybridARQ::GetSoftInfoFromRxRateMatch(float *pSI)
{
  if(PSFlag){cout<<"HARQ:GetSoftInfoFromRxRM"<<endl;}
    for(int i=0;i<EncDataLen;i++)
    {
      *(pBufferCurrSoftInfo+i)=*(pSI+i);
    }
  if(PSFlag){cout<<"HARQ:GetSoftInfoFromRxRM Completed"<<endl;}
}

void HybridARQ::GetSoftInfoFromRxRateMatch(FIFO<float> *pInpBuf)
{
  if(PSFlag){cout<<"HARQ:GetSoftInfoFromRxRM"<<endl;}
  bool ReadFlag = (*pInpBuf).Read(pBufferCurrSoftInfo);
  if(ReadFlag){}
  else{cout<<"failed to read from previous buffer"<<endl;}
  if(PSFlag){cout<<"HARQ:GetSoftInfoFromRxRM Completed"<<endl;}
}

bool HybridARQ::SetReTransmissionFlag(int NumErrBit,int CurTransNum)
{
  if(CurTransNum>=NumMaxTrans){return false;}
  else
  {
    if(NumErrBit==0){return false;}
    else{return true;}
  }
}
void HybridARQ::CombineSoftInformation()
{
  if(PSFlag){cout<<"HARQ:CombineSoftInfo"<<endl;}
  for(int i=0;i<EncDataLen;i++)
  {
      (*(pCombinedSoftInfo+i)) += (*(pBufferCurrSoftInfo+i));
  }
  if(PSFlag){cout<<"HARQ:CombineSoftInfo Completed"<<endl;}
}

void HybridARQ::GetpCombinedSoftInfo(FIFO<float> *pOutBuf)
{bool WriteFlag = (*pOutBuf).Write(pCombinedSoftInfo);}

HybridARQ::~HybridARQ(void)
{
  delete[] pBufferTxBits;

  delete[] pBufferCurrSoftInfo;
//  delete[] pBufferPrevSoftInfo;
  delete[] pCombinedSoftInfo;
}
