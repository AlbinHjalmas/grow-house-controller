/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/mainscreen_screen/mainScreenViewBase.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

mainScreenViewBase::mainScreenViewBase()  :
    buttonCallback(this, &mainScreenViewBase::buttonCallbackHandler)
{
    background.setXY(0, 0);
    background.setBitmap(Bitmap(BITMAP_BACKGROUND_ID));

    mainSettingsBtn.setPosition(420, 46, 60, 60);
    mainSettingsBtn.setBitmaps(Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID), Bitmap(BITMAP_DARK_ICONS_SETTINGS_32_ID), Bitmap(BITMAP_DARK_ICONS_SETTINGS_32_ID));
    mainSettingsBtn.setIconXY(14, 14);
    mainSettingsBtn.setAction(buttonCallback);

    mainStatsBtn.setPosition(420, 106, 60, 60);
    mainStatsBtn.setBitmaps(Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID), Bitmap(BITMAP_DARK_ICONS_INFO_32_ID), Bitmap(BITMAP_DARK_ICONS_INFO_32_ID));
    mainStatsBtn.setIconXY(14, 14);

    mainPowerBtn.setPosition(420, 166, 60, 60);
    mainPowerBtn.setBitmaps(Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID), Bitmap(BITMAP_DARK_ICONS_POWER_32_ID), Bitmap(BITMAP_DARK_ICONS_POWER_32_ID));
    mainPowerBtn.setIconXY(15, 15);
    mainPowerBtn.setAction(buttonCallback);

    textArea1.setXY(236, 28);
    textArea1.setColor(touchgfx::Color::getColorFrom24BitRGB(255,255,255));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(TypedText(T_TEXTID1));
    textArea1.setAlpha(63);

    textArea1_1.setXY(65, 28);
    textArea1_1.setColor(touchgfx::Color::getColorFrom24BitRGB(255,255,255));
    textArea1_1.setLinespacing(0);
    textArea1_1.setTypedText(TypedText(T_TEXTID3));
    textArea1_1.setAlpha(63);

    manualOverrideBtn.setPosition(177, 144, 96, 38);
    manualOverrideBtn.setBitmaps(Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_ROUND_SMALL_BUTTON_OFF_ID), Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_ROUND_SMALL_BUTTON_ON_ID));
    manualOverrideBtn.setAction(buttonCallback);

    textArea1_1_1.setXY(169, 124);
    textArea1_1_1.setColor(touchgfx::Color::getColorFrom24BitRGB(255,255,255));
    textArea1_1_1.setLinespacing(0);
    textArea1_1_1.setTypedText(TypedText(T_TEXTID31));
    textArea1_1_1.setAlpha(63);

    textArea1_1_1_1.setPosition(65, 189, 112, 20);
    textArea1_1_1_1.setColor(touchgfx::Color::getColorFrom24BitRGB(255,255,255));
    textArea1_1_1_1.setLinespacing(0);
    textArea1_1_1_1.setTypedText(TypedText(T_TEXTID32));
    textArea1_1_1_1.setAlpha(63);

    textArea1_1_1_2.setPosition(169, 189, 112, 20);
    textArea1_1_1_2.setColor(touchgfx::Color::getColorFrom24BitRGB(255,255,255));
    textArea1_1_1_2.setLinespacing(0);
    textArea1_1_1_2.setTypedText(TypedText(T_TEXTID33));
    textArea1_1_1_2.setAlpha(63);

    textArea1_1_1_3.setPosition(273, 188, 112, 20);
    textArea1_1_1_3.setColor(touchgfx::Color::getColorFrom24BitRGB(255,255,255));
    textArea1_1_1_3.setLinespacing(0);
    textArea1_1_1_3.setTypedText(TypedText(T_TEXTID34));
    textArea1_1_1_3.setAlpha(63);

    humidifierOpBtn.setPosition(73, 210, 96, 38);
    humidifierOpBtn.setBitmaps(Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_ROUND_SMALL_BUTTON_OFF_ID), Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_ROUND_SMALL_BUTTON_ON_ID));
    humidifierOpBtn.setAction(buttonCallback);

    lightOpBtn.setPosition(177, 210, 96, 38);
    lightOpBtn.setBitmaps(Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_ROUND_SMALL_BUTTON_OFF_ID), Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_ROUND_SMALL_BUTTON_ON_ID));
    lightOpBtn.setAction(buttonCallback);

    heaterOpBtn.setPosition(281, 209, 96, 38);
    heaterOpBtn.setBitmaps(Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_ROUND_SMALL_BUTTON_OFF_ID), Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_ROUND_SMALL_BUTTON_ON_ID));
    heaterOpBtn.setAction(buttonCallback);

    currHumiTxtArea.setPosition(47, 48, 154, 58);
    currHumiTxtArea.setColor(touchgfx::Color::getColorFrom24BitRGB(40,230,50));
    currHumiTxtArea.setLinespacing(0);
    currHumiTxtArea.setTypedText(TypedText(T_CURRHUMITXTID));
    currHumiTxtAreaBuffer[0] = 0;
    currHumiTxtArea.setWildcard(currHumiTxtAreaBuffer);

    currTempTxtArea.setPosition(230, 48, 154, 58);
    currTempTxtArea.setColor(touchgfx::Color::getColorFrom24BitRGB(40,230,50));
    currTempTxtArea.setLinespacing(0);
    currTempTxtArea.setTypedText(TypedText(T_CURRTEMPTXTID));
    currTempTxtAreaBuffer[0] = 0;
    currTempTxtArea.setWildcard(currTempTxtAreaBuffer);

    dateTxt.setPosition(296, 0, 179, 23);
    dateTxt.setColor(touchgfx::Color::getColorFrom24BitRGB(40,230,50));
    dateTxt.setLinespacing(0);
    dateTxt.setTypedText(TypedText(T_TEXTID102));
    dateTxt.setAlpha(111);
    dateTxtBuffer[0] = 0;
    dateTxt.setWildcard(dateTxtBuffer);
    add(background);
    add(mainSettingsBtn);
    add(mainStatsBtn);
    add(mainPowerBtn);
    add(textArea1);
    add(textArea1_1);
    add(manualOverrideBtn);
    add(textArea1_1_1);
    add(textArea1_1_1_1);
    add(textArea1_1_1_2);
    add(textArea1_1_1_3);
    add(humidifierOpBtn);
    add(lightOpBtn);
    add(heaterOpBtn);
    add(currHumiTxtArea);
    add(currTempTxtArea);
    add(dateTxt);
}

void mainScreenViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &mainSettingsBtn)
    {
        //mainSettingsBtnClicked
        //When mainSettingsBtn clicked change screen to settingsScreen
        //Go to settingsScreen with slide screen transition towards East
        application().gotosettingsScreenScreenSlideTransitionEast();
    }
    else if (&src == &mainStatsBtn)
    {

    }
    else if (&src == &mainPowerBtn)
    {
        //mainPowerBtnClicked
        //When mainPowerBtn clicked call virtual function
        //Call mainPowerBtnClicked
        mainPowerBtnClicked();

        //Interaction5
        //When mainPowerBtn clicked change screen to Screen1
        //Go to Screen1 with no screen transition
        application().gotoScreen1ScreenNoTransition();
    }
    else if (&src == &manualOverrideBtn)
    {
        //Interaction1
        //When manualOverrideBtn clicked call virtual function
        //Call manualOverrideBtnClicked
        manualOverrideBtnClicked();
    }
    else if (&src == &humidifierOpBtn)
    {
        //Interaction2
        //When humidifierOpBtn clicked call virtual function
        //Call humidifierOpBtnClicked
        humidifierOpBtnClicked();
    }
    else if (&src == &lightOpBtn)
    {
        //Interaction3
        //When lightOpBtn clicked call virtual function
        //Call lightOpBtnClicked
        lightOpBtnClicked();
    }
    else if (&src == &heaterOpBtn)
    {
        //Interaction4
        //When heaterOpBtn clicked call virtual function
        //Call heaterOpBtnClicked
        heaterOpBtnClicked();
    }
}