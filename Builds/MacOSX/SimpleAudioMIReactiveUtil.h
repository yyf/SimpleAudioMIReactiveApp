//
//  SimpleAudioMIReactiveUtil.h
//  SimpleAudioMIReactiveApp
//
//  Created by YYF on 7/1/15.
//  Modified from ofxAudioAnalyzer by leozimmerman: https://github.com/leozimmerman/ofxAudioAnalyzer
//  More info: http://essentia.upf.edu/documentation/howto_streaming_extractor.html
//

#ifndef __SimpleAudioMIReactiveApp__SimpleAudioMIReactiveUtil__
#define __SimpleAudioMIReactiveApp__SimpleAudioMIReactiveUtil__

#pragma once

#include <iostream>
#include "essentia/algorithmfactory.h"
#include "essentia/essentiamath.h"
#include "essentia/pool.h"

using namespace essentia;
using namespace standard;
using namespace std;

class SimpleAudioMIReactiveUtil
{
public:
    
    bool doRms, doEnergy, doPower;
    
    void setup(int bufferSize, int sampleRate);
    void exit();
    void analyze(float * iBuffer, int bufferSize);
    
    // getter
    float getRms(){return rms_f;}
    float getEnergy(){return energy_f;}
    float getPower(){return power_f;}
    
private:
    
    int sr;
    vector<float> spectrum_f;
    float rms_f, energy_f, power_f;

    Algorithm* spectrum;
    Algorithm* rms;
    Algorithm* energy;
    Algorithm* power;
    Algorithm* dcremoval;
    
    Real rmsValue;
    Real powerValue;
    Real energyValue;

    vector<Real> spec;
    vector<Real> audioBuffer;
    vector<Real> audioBuffer_dc;
};

#endif /* defined(__SimpleAudioMIReactiveApp__SimpleAudioMIReactiveUtil__) */
