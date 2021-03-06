#ifndef MYLNF_H_INCLUDED
#define MYLNF_H_INCLUDED

#include <JuceHeader.h>

class MyLNF : public LookAndFeel_V4
{
public:
    MyLNF();

    Typeface::Ptr getTypefaceForFont(const Font&) override;

    void drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height,
                           float sliderPos, float rotaryStartAngle,
                           float rotaryEndAngle, juce::Slider& slider) override;

    void drawToggleButton (Graphics& g, ToggleButton& button,
                           bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override;

    void createTabTextLayout (const TabBarButton& button, float length, float depth,
                              Colour colour, TextLayout& textLayout);
    void drawTabButton (TabBarButton& button, Graphics& g, bool isMouseOver, bool isMouseDown) override;

    void drawLinearSlider (Graphics& g, int x, int y, int width, int height,
                           float sliderPos, float minSliderPos, float maxSliderPos,
                           const Slider::SliderStyle style, Slider& slider) override;

    Slider::SliderLayout getSliderLayout (Slider& slider) override;
    Label* createSliderTextBox (Slider& slider) override;

private:
    std::unique_ptr<Drawable> knob = Drawable::createFromImageData (BinaryData::knob_svg, BinaryData::knob_svgSize);
    std::unique_ptr<Drawable> pointer = Drawable::createFromImageData (BinaryData::pointer_svg, BinaryData::pointer_svgSize);

    Typeface::Ptr roboto;
    Typeface::Ptr robotoBold;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MyLNF)
};


class ComboBoxLNF : public MyLNF
{
public:
    ComboBoxLNF() {}

    void drawComboBox (Graphics& g, int width, int height, bool, int, int, int, int, ComboBox& box) override;
    void positionComboBoxText (ComboBox& box, Label& label) override;

    void drawPopupMenuItem (Graphics& g, const Rectangle<int>& area,
        const bool isSeparator, const bool isActive,
        const bool isHighlighted, const bool /*isTicked*/,
        const bool hasSubMenu, const String& text,
        const String& shortcutKeyText,
        const Drawable* icon, const Colour* const textColourToUse) override
    {
        LookAndFeel_V4::drawPopupMenuItem (g, area, isSeparator, isActive,
            isHighlighted, false /*isTicked*/, hasSubMenu, text,
            shortcutKeyText, icon, textColourToUse);
    }

private:

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ComboBoxLNF)
};


#endif // MYLNF_H_INCLUDED
