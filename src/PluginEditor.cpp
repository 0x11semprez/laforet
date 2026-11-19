#include "PluginEditor.h"

#include "PluginProcessor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor(AudioPluginAudioProcessor& p)
    : AudioProcessorEditor(&p), processorRef(p)
{
    juce::ignoreUnused(processorRef);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    addAndMakeVisible(gainSlider);
    gainSlider.setSliderStyle(juce::Slider::Rotary);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 64, 32);
    gainSlider.setRange(-24.0, 24.0, 0.1);
    gainSlider.setDoubleClickReturnValue(true, 0.0);
    gainSlider.setColour(juce::Slider::ColourIds::rotarySliderFillColourId, juce::Colours::green);
    setSize(350, 450);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor() {}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint(juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(juce::Colour(233, 255, 204));

    g.setColour(juce::Colours::grey);
    g.setFont(14.0f);
}

void AudioPluginAudioProcessorEditor::resized()
{
    gainSlider.setBounds(64, 64, 175, 225);
}
