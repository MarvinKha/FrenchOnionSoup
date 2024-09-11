#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PluginEditor::PluginEditor(PluginProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

    setSize (500, 500);
    setResizable(true, true);

    dist.setSliderStyle(juce::Slider::Rotary);
    dist.setRange(0.0f,1.0f,0.01f);
    dist.setValue(0.0f);
    dist.setTextBoxStyle(juce::Slider::TextBoxBelow,false,50,20);


    dist.onValueChange = [this] {audioProcessor.distAmount->setValueNotifyingHost(dist.getValue());};

    addAndMakeVisible(dist);
}

PluginEditor::~PluginEditor()
{


}

//==============================================================================
void PluginEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(juce::Colours::red.withSaturation(0.2f).withBrightness(0.35f));
}

void PluginEditor::resized()
{
    auto bounds = getLocalBounds();
    dist.setBounds(bounds);

}
