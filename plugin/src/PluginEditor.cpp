#include "PluginEditor.h"

#include "PluginProcessor.cpp"
#include "PluginProcessor.h"

AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor(AudioPluginAudioProcessor& p)
    : AudioProcessorEditor(&p), processorRef(p)
{
    addAndMakeVisible(gainSlider);

    gainAttachement = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        processorRef.apvts, "gain", gainSlider);

    gainSlider.setSliderStyle(juce::Slider::LinearBarVertical);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 32, 16);
    gainSlider.setDoubleClickReturnValue(true, 0.0);
    gainSlider.setColour(juce::Slider::ColourIds::rotarySliderFillColourId, juce::Colours::green);

    setSize(350, 450);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor() {}

void AudioPluginAudioProcessorEditor::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colour(233, 255, 204));

    g.setColour(juce::Colours::grey);
    g.setFont(14.0f);
}

void AudioPluginAudioProcessorEditor::resized()
{
    gainSlider.setBounds(200, 150, 32, 98);
}
