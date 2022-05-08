/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/settingsscreen_screen/settingsScreenViewBase.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

settingsScreenViewBase::settingsScreenViewBase()  :
    buttonCallback(this, &settingsScreenViewBase::buttonCallbackHandler)
{
    image1.setXY(0, 0);
    image1.setBitmap(Bitmap(BITMAP_BACKGROUND_ID));

    settingsHomeBtn.setPosition(420, 106, 60, 60);
    settingsHomeBtn.setBitmaps(Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID), Bitmap(BITMAP_DARK_ICONS_HOME_32_ID), Bitmap(BITMAP_DARK_ICONS_HOME_32_ID));
    settingsHomeBtn.setIconXY(14, 15);
    settingsHomeBtn.setAction(buttonCallback);

    setTempHumiBtn.setPosition(45, 16, 360, 60);
    setTempHumiBtn.setBitmaps(Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_LARGE_ID), Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_LARGE_PRESSED_ID));
    setTempHumiBtn.setLabelText(TypedText(T_TEXTID8));
    setTempHumiBtn.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255,255,255));
    setTempHumiBtn.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255,255,255));
    setTempHumiBtn.setAction(buttonCallback);

    setOutputConfigBtn.setPosition(45, 76, 360, 60);
    setOutputConfigBtn.setBitmaps(Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_LARGE_ID), Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_LARGE_PRESSED_ID));
    setOutputConfigBtn.setLabelText(TypedText(T_TEXTID13));
    setOutputConfigBtn.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255,255,255));
    setOutputConfigBtn.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255,255,255));
    setOutputConfigBtn.setAction(buttonCallback);

    setDateTimeBtn.setPosition(45, 196, 360, 60);
    setDateTimeBtn.setBitmaps(Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_LARGE_ID), Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_LARGE_PRESSED_ID));
    setDateTimeBtn.setLabelText(TypedText(T_TEXTID14));
    setDateTimeBtn.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255,255,255));
    setDateTimeBtn.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255,255,255));
    setDateTimeBtn.setAction(buttonCallback);

    setDayNightBtn.setPosition(45, 136, 360, 60);
    setDayNightBtn.setBitmaps(Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_LARGE_ID), Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_LARGE_PRESSED_ID));
    setDayNightBtn.setLabelText(TypedText(T_TEXTID15));
    setDayNightBtn.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255,255,255));
    setDayNightBtn.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255,255,255));
    setDayNightBtn.setAction(buttonCallback);
    add(image1);
    add(settingsHomeBtn);
    add(setTempHumiBtn);
    add(setOutputConfigBtn);
    add(setDateTimeBtn);
    add(setDayNightBtn);
}

void settingsScreenViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &settingsHomeBtn)
    {
        //settingsHomeBtnClicked
        //When settingsHomeBtn clicked change screen to mainScreen
        //Go to mainScreen with slide screen transition towards West
        application().gotomainScreenScreenSlideTransitionWest();
    }
    else if (&src == &setTempHumiBtn)
    {
        //setTempHumiBtnClicked
        //When setTempHumiBtn clicked change screen to tempHumiSettingsScreen
        //Go to tempHumiSettingsScreen with slide screen transition towards East
        application().gototempHumiSettingsScreenScreenSlideTransitionEast();
    }
    else if (&src == &setOutputConfigBtn)
    {
        //setOutputConfigBtnClicked
        //When setOutputConfigBtn clicked change screen to opConfigSettingsScreen
        //Go to opConfigSettingsScreen with slide screen transition towards East
        application().gotoopConfigSettingsScreenScreenSlideTransitionEast();
    }
    else if (&src == &setDateTimeBtn)
    {
        //setDateTimeBtnClicked
        //When setDateTimeBtn clicked change screen to dateTimeSettingsScreen
        //Go to dateTimeSettingsScreen with slide screen transition towards East
        application().gotodateTimeSettingsScreenScreenSlideTransitionEast();
    }
    else if (&src == &setDayNightBtn)
    {
        //setDayNightBtnClicked
        //When setDayNightBtn clicked change screen to dayNightSettingsScreen
        //Go to dayNightSettingsScreen with slide screen transition towards East
        application().gotodayNightSettingsScreenScreenSlideTransitionEast();
    }
}