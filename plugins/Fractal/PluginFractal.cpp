#define SFML_STATIC
#include "PluginFractal.hpp"
#include <iostream>
START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------

DistrhoPluginFractal::DistrhoPluginFractal()
    : Plugin(kParameterCount, 1, 0), // 1 program, 0 states
      fInputVolume(1.0f),
      OutIndex(0),
      InCount(0),
      ReadWrite(false),
      EnvOld(0.0f)
{
}

// -----------------------------------------------------------------------
// Init

void DistrhoPluginFractal::initParameter(uint32_t index, Parameter& parameter)
{
    parameter.hints      = kParameterIsAutomable;
    parameter.ranges.min = -90.0f;
    parameter.ranges.max = 30.0f;

    parameter.name       = "Input Vol";
    parameter.symbol     = "ipvolume";
    parameter.ranges.def = -0.0f;
    parameter.unit = "db";
    
}

void DistrhoPluginFractal::initProgramName(uint32_t index, String& programName)
{
    if (index != 0)
        return;

    programName = "Default";
}

// -----------------------------------------------------------------------
// Internal data

float DistrhoPluginFractal::getParameterValue(uint32_t index) const
{
    switch(index)
    {
    case kParameterInputVolume:
        return fInputVolume;
    default:
        return 0.0f;
    }
}

void DistrhoPluginFractal::setParameterValue(uint32_t index, float value)
{
    switch(index)
    {
    case kParameterInputVolume:
        fInputVolume = value;
        break;
    }
}

void DistrhoPluginFractal::loadProgram(uint32_t index)
{
    if (index != 0)
        return;

    fInputVolume    = 1.0f;
}

// -----------------------------------------------------------------------
// Process

void DistrhoPluginFractal::activate()
{
    //std::memset(CycleBuffer, 0, sizeof(float)*BUFFER_SIZE);
    OutIndex = 0;
    InCount = 0;
    ReadWrite = false;
    EnvOld = 0.0f;
    running = true;
    GUIthread = std::thread(fractal_main, &running, &synth);
}

void DistrhoPluginFractal::deactivate(){
	running = false;
	GUIthread.join();
}

void DistrhoPluginFractal::run(const float** inputs, float** outputs, uint32_t frames)
{
   // const float* in  =  inputs[0];
   // /**/  float* out = outputs[0];

   // for (uint32_t i=0; i<frames; ++i)
   //     *out++ = DoProcess(*in++);

    // get the left and right audio inputs

    const float* in1  =  inputs[0];
    float* out1 = outputs[0];
    const float* in2  =  inputs[1];
    float* out2 = outputs[1];

    synth.onGetData(out1, out2, frames);
    return;

}


Plugin* createPlugin()
{
    return new DistrhoPluginFractal();
}

// -----------------------------------------------------------------------

END_NAMESPACE_DISTRHO
