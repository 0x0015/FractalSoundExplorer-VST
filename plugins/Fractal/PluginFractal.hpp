#ifndef DISTRHO_PLUGIN_NODE_PLUGIN_HPP_INCLUDED
#define DISTRHO_PLUGIN_NODE_PLUGIN_HPP_INCLUDED

#include "DistrhoPlugin.hpp"
#include "Main.hpp"
#include <thread>
#define BUFFER_SIZE 11025

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------

class DistrhoPluginFractal : public Plugin
{
public:
    enum Parameters {
        kParameterInputVolume,
        kParameterCount
    };

    DistrhoPluginFractal();

protected:
    // -------------------------------------------------------------------
    // Information

    const char* getLabel() const noexcept override
    {
        return "Node Plugin";
    }

    const char* getDescription() const override
    {
        return "A node graph of more simple effects to give more interesting resuls.";
    }

    const char* getMaker() const noexcept override
    {
        return "0x15";
    }

    const char* getHomePage() const override
    {
        return "https://github.com/0x0015/VSTPlugin";
    }

    const char* getLicense() const noexcept override
    {
        return "N/A";
    }

    uint32_t getVersion() const noexcept override
    {
        return d_version(0, 1, 0);
    }

    int64_t getUniqueId() const noexcept override
    {
        return d_cconst('O', 'X', 'I', 'S');
    }

    // -------------------------------------------------------------------
    // Init

    void initParameter(uint32_t index, Parameter& parameter) override;
    void initProgramName(uint32_t index, String& programName) override;

    // -------------------------------------------------------------------
    // Internal data

    float getParameterValue(uint32_t index) const override;
    void  setParameterValue(uint32_t index, float value) override;
    void  loadProgram(uint32_t index) override;

    // -------------------------------------------------------------------
    // Process

    void activate() override;
    void deactivate() override;
    void run(const float** inputs, float** outputs, uint32_t frames) override;

    // -------------------------------------------------------------------

private:
    float fInputVolume;
    bool running = true;
    std::thread GUIthread;
    Synth synth;
    //std::vector<audioNode*> nodes;
    //audioNodeInput* inputNode1;
    //audioNodeOutput* outputNode1;
    //audioNodeInput* inputNode2;
    //audioNodeOutput* outputNode2;
    //float CycleBuffer[BUFFER_SIZE]; // buffer to store the cycle in
    int OutIndex;                   // index for playing the buffer
    int InCount;                    // counts how many samples we've recorded
    bool ReadWrite;                 // 0=read, 1=write
    float EnvOld;                   // last (input) sample - used to determine zero-crossings

    //float DoProcess(float a);

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DistrhoPluginFractal)
};

// -----------------------------------------------------------------------

END_NAMESPACE_DISTRHO

#endif  // DISTRHO_PLUGIN_NODE_PLUGIN_HPP_INCLUDED
