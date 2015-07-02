//
//  SimpleAudioMIReactiveUtil.cpp
//  SimpleAudioMIReactiveApp
//
//  Created by YYF on 7/1/15.
//  Modified from ofxAudioAnalyzer by leozimmerman: https://github.com/leozimmerman/ofxAudioAnalyzer
//  More info: http://essentia.upf.edu/documentation/howto_streaming_extractor.html
//

#include "SimpleAudioMIReactiveUtil.h"


void SimpleAudioMIReactiveUtil::setup(int bufferSize, int sampleRate){
    sr = sampleRate;
    doRms = doEnergy = doPower = true;
    audioBuffer.resize(bufferSize);
    essentia::init();
    
    AlgorithmFactory& factory = AlgorithmFactory::instance();
    rms = factory.create("RMS");
    energy = factory.create("Energy");
    power = factory.create("InstantPower");
    dcremoval = factory.create("DCRemoval", "sampleRate", sr);

    dcremoval->input("signal").set(audioBuffer);
    dcremoval->output("signal").set(audioBuffer_dc);
    rms->input("array").set(audioBuffer_dc);
    rms->output("rms").set(rmsValue);
    energy->input("array").set(audioBuffer_dc);
    energy->output("energy").set(energyValue);
    power->input("array").set(audioBuffer_dc);
    power->output("power").set(powerValue);
}

//--------------------------------------------------------------
void SimpleAudioMIReactiveUtil::exit(){
    delete dcremoval;
    delete rms;
    delete energy;
    delete power;
    essentia::shutdown();
}

//--------------------------------------------------------------
void SimpleAudioMIReactiveUtil::analyze(float * iBuffer, int bufferSize){
    
    vector <float> fBuffer;
    fBuffer.resize(bufferSize);
    memcpy(&fBuffer[0], iBuffer, sizeof(float) * bufferSize);
    for (int i=0; i<bufferSize;i++){
        audioBuffer[i] = (Real) fBuffer[i];
    }
    
    dcremoval->compute();
    if(doRms) rms->compute();
    if(doEnergy) energy->compute();
    if(doPower)power->compute();
    
    for (int i=0; i<spec.size(); i++)
        spectrum_f[i] = log10((float) spec[i]);
    
    if(doRms) rms_f = (float) rmsValue;
    else rms_f = 0.0;
    
    if(doEnergy) energy_f = (float) energyValue;
    else energy_f = 0.0;
    
    if(doPower) power_f = (float) powerValue;
    else power_f = 0.0;

}



