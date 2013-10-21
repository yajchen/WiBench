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
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include <complex>
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include "gauss.h"
#include "FIFO.h"
#include "BSPara.h"
#include "UserPara.h"
#include "matrix.h"
#include "Modulation.h"
#include "Demodulation.h"
#include "TxRateMatch.h"
#include "RxRateMatch.h"
#include "TurboEncoder_c.h"
#include "TurboDecoder_c.h"
#include "Scramble.h"
#include "Descramble.h"
#include "Channel.h"
#include "SubCarrierMap.h"
#include "SubCarrierDemap.h"
#include "TransformPrecoder.h"
#include "TransformDecoder.h"
#include "Equalizer_s.h"
#include "SCFDMAModulation.h"
#include "SCFDMADemodulation.h"
#include "GeneralFunc.h"

#define NSTD 1
#define MAXRUN 8
#define MaxInfoPktSz 6144

