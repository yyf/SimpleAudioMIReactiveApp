/*
 ==============================================================================
 
 This file was auto-generated!
 
 ==============================================================================
 */

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "AudioLiveScrollingDisplay.h"



#if _WIN32
#include <gl/glut.h>
#elif __APPLE__
#include <GLUT/glut.h>
#endif

//==============================================================================
/*
 This component lives inside our window, and this is where you should put all
 your controls and content.
 */
class MainContentComponent   : public OpenGLAppComponent
{
public:
    
    float r1 = 0.0f, r2 = 0.0f, r3 = 0.0f;
    
    
    const float DEG_2_RAD = M_PI/180;
    
    //==============================================================================
    MainContentComponent()
    {
        setSize (800, 800);
        deviceManager.initialise(1, 0, 0, true);
        addAndMakeVisible (MicInputVisualWidget);
        deviceManager.addAudioCallback (&MicInputVisualWidget);
    }
    
    ~MainContentComponent()
    {
        shutdownOpenGL();
        deviceManager.removeAudioCallback (&MicInputVisualWidget);
    }
    
    void initialise() override
    {
    }
    
    void shutdown() override
    {
    }
    
    void render() override
    {
        OpenGLHelpers::clear (Colours::black);
        
        r1 = MicInputVisualWidget.get_sample();
        r2 = MicInputVisualWidget.get_rms();
        r3 = MicInputVisualWidget.get_energy();
        
        
        glLineWidth(2.0);
        glColor4f(0.67, 0.84, 0.90, 0.9);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable( GL_LINE_SMOOTH );
        glHint( GL_LINE_SMOOTH_HINT, GL_NICEST );
        
        glBegin(GL_LINE_LOOP);
        for (int i=0; i < 360; i++)
        {
            float DEG_IN_RAD = i*DEG_2_RAD;
            glVertex2f(r1*cos(DEG_IN_RAD), r1*sin(DEG_IN_RAD));
        }
        glEnd();
        
        
        glColor4f(0.17, 0.84, 0.90, 0.9);
        glBegin(GL_LINE_LOOP);
        for (int i=0; i < 360; i++)
        {
            float DEG_IN_RAD = i*DEG_2_RAD;
            glVertex2f(r2*cos(DEG_IN_RAD), r2*sin(DEG_IN_RAD));
        }
        glEnd();
        
        glColor4f(0.67, 0.84, 0.10, 0.9);
        glBegin(GL_LINE_LOOP);
        for (int i=0; i < 360; i++)
        {
            float DEG_IN_RAD = i*DEG_2_RAD;
            glVertex2f(r3*cos(DEG_IN_RAD), r3*sin(DEG_IN_RAD));
        }
        glEnd();
    }
    
    void paint (Graphics& g) override
    {
        // You can add your component specific drawing code here!
        // This will draw over the top of the openGL background.
    }
    
    void resized() override
    {
        // This is called when the MainContentComponent is resized.
        // If you add any child components, this is where you should
        // update their positions.
        
        Rectangle<int> area (getLocalBounds());
        MicInputVisualWidget.setBounds (area.removeFromTop (80).reduced (8));
    }
    
    void mouseDown (const MouseEvent& e) override
    {
        mouseDrag (e);
        //std::cout << "Check sample value = " << mapping_variable << std::endl;
    }
    
    
private:
    //==============================================================================
    
    // private member variables
    LiveScrollingAudioDisplay MicInputVisualWidget;
    AudioDeviceManager deviceManager;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()    { return new MainContentComponent(); }


#endif  // MAINCOMPONENT_H_INCLUDED
