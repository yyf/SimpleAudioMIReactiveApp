# SimpleAudioMIReactiveApp
## Intro
A Simple Audio-based MIR Reactive App built using JUCE (http://www.juce.com/) with Essentia (an open-source C++ library for audio analysis and audio-based music information retrieval, http://essentia.upf.edu/) Thanks to Leo Zimmerman's 64-bit example (https://github.com/leozimmerman) and GiantSteps' 32-bit example (https://github.com/GiantSteps/)

This SimpleAudioMIReactiveApp is built using JUCE with Essentia. Essentia is an open-source C++ library for audio analysis and audio-based music information retrieval, developed by the Music and Technology group at Universitat Pompeu Fabra: http://essentia.upf.edu/ I use three parameters to live control the radius of each circle shown in this example. The raw input value from mic is accessible from JUCE’s AudioLiveScrollingDisplay utility file. The other two parameters are rms and energy available from Essentia. There are a lot more algorithms available in Essenita library, http://essentia.upf.edu/documentation/algorithms_overview.html There is also a research paper published at ISMIR 2013: http://mtg.upf.edu/node/2793 


## Setup
To use Essentia in Xcode, you should get Essentia installed on your machine first. Here is the instruction to install Essentia: http://essentia.upf.edu/documentation/installing.html

After you successfully install Essentia, you should configure your xcode build setting as usual: set header search path and library search path

And then drag these libraries to your Xcode project: 
* libavresample.a 
* libessentia.a 
* libtag.dylib
* libsamplerate.a
* libavcodec.a 
* libavformat.a 
* libavutil.a 
* libswresample.a
* libfftw3f.a
* libyaml.a

Finally, include the following in your file, and start making real-time audio reactive visual using audio-based MIR:

* “essentia.h”
* “taglib.h”
* “fftw3.h”
* “essentia/algorithmfactory.h”
* “essentia/essentiamath.h”
* “essentia/pool.h”

* using namespace std;
* using namespace essentia;
* using namespace standard;
