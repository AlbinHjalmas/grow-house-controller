/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/opconfigsettingsscreen_screen/opConfigSettingsScreenViewBase.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

opConfigSettingsScreenViewBase::opConfigSettingsScreenViewBase()  :
    buttonCallback(this, &opConfigSettingsScreenViewBase::buttonCallbackHandler)
{
    image5.setXY(0, 0);
    image5.setBitmap(Bitmap(BITMAP_BACKGROUND_ID));

    opConfigHomeBtn.setPosition(60, 0, 60, 60);
    opConfigHomeBtn.setBitmaps(Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID), Bitmap(BITMAP_DARK_ICONS_HOME_32_ID), Bitmap(BITMAP_DARK_ICONS_HOME_32_ID));
    opConfigHomeBtn.setIconXY(14, 15);
    opConfigHomeBtn.setAction(buttonCallback);

    opConfigBackBtn.setPosition(0, 0, 60, 60);
    opConfigBackBtn.setBitmaps(Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID), Bitmap(BITMAP_DARK_ICONS_BACK_ARROW_32_ID), Bitmap(BITMAP_DARK_ICONS_BACK_ARROW_32_ID));
    opConfigBackBtn.setIconXY(21, 14);
    opConfigBackBtn.setAction(buttonCallback);

    op1HeaterBtn.setPosition(151, 96, 96, 38);
    op1HeaterBtn.setBitmaps(Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_SMALL_BUTTON_OFF_ID), Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_SMALL_BUTTON_ON_ID));
    op1HeaterBtn.setAction(buttonCallback);

    op3LightBtn.setPosition(343, 172, 96, 38);
    op3LightBtn.setBitmaps(Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_SMALL_BUTTON_OFF_ID), Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_SMALL_BUTTON_ON_ID));
    op3LightBtn.setAction(buttonCallback);

    op3HumiBtn.setPosition(247, 172, 96, 38);
    op3HumiBtn.setBitmaps(Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_SMALL_BUTTON_OFF_ID), Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_SMALL_BUTTON_ON_ID));
    op3HumiBtn.setAction(buttonCallback);

    op3HeaterBtn.setPosition(151, 172, 96, 38);
    op3HeaterBtn.setBitmaps(Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_SMALL_BUTTON_OFF_ID), Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_SMALL_BUTTON_ON_ID));
    op3HeaterBtn.setAction(buttonCallback);

    op2LightBtn.setPosition(343, 134, 96, 38);
    op2LightBtn.setBitmaps(Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_SMALL_BUTTON_OFF_ID), Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_SMALL_BUTTON_ON_ID));
    op2LightBtn.setAction(buttonCallback);

    op2HumiBtn.setPosition(247, 134, 96, 38);
    op2HumiBtn.setBitmaps(Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_SMALL_BUTTON_OFF_ID), Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_SMALL_BUTTON_ON_ID));
    op2HumiBtn.setAction(buttonCallback);

    op2HeaterBtn.setPosition(151, 134, 96, 38);
    op2HeaterBtn.setBitmaps(Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_SMALL_BUTTON_OFF_ID), Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_SMALL_BUTTON_ON_ID));
    op2HeaterBtn.setAction(buttonCallback);

    op1LightBtn.setPosition(343, 96, 96, 38);
    op1LightBtn.setBitmaps(Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_SMALL_BUTTON_OFF_ID), Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_SMALL_BUTTON_ON_ID));
    op1LightBtn.setAction(buttonCallback);

    op1HumiBtn.setPosition(247, 96, 96, 38);
    op1HumiBtn.setBitmaps(Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_SMALL_BUTTON_OFF_ID), Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_SMALL_BUTTON_ON_ID));
    op1HumiBtn.setAction(buttonCallback);

    textArea1_1.setPosition(156, 62, 86, 23);
    textArea1_1.setColor(touchgfx::Color::getColorFrom24BitRGB(255,255,255));
    textArea1_1.setLinespacing(0);
    textArea1_1.setTypedText(TypedText(T_TEXTID57));
    textArea1_1.setAlpha(90);

    textArea1_2.setPosition(30, 180, 115, 23);
    textArea1_2.setColor(touchgfx::Color::getColorFrom24BitRGB(255,255,255));
    textArea1_2.setLinespacing(0);
    textArea1_2.setTypedText(TypedText(T_TEXTID58));
    textArea1_2.setAlpha(90);

    textArea1_3.setPosition(30, 142, 115, 21);
    textArea1_3.setColor(touchgfx::Color::getColorFrom24BitRGB(255,255,255));
    textArea1_3.setLinespacing(0);
    textArea1_3.setTypedText(TypedText(T_TEXTID59));
    textArea1_3.setAlpha(90);

    textArea1_4.setPosition(30, 104, 115, 25);
    textArea1_4.setColor(touchgfx::Color::getColorFrom24BitRGB(255,255,255));
    textArea1_4.setLinespacing(0);
    textArea1_4.setTypedText(TypedText(T_TEXTID60));
    textArea1_4.setAlpha(90);

    textArea1_5.setPosition(348, 62, 86, 23);
    textArea1_5.setColor(touchgfx::Color::getColorFrom24BitRGB(255,255,255));
    textArea1_5.setLinespacing(0);
    textArea1_5.setTypedText(TypedText(T_TEXTID61));
    textArea1_5.setAlpha(90);

    textArea1_6.setPosition(252, 62, 86, 23);
    textArea1_6.setColor(touchgfx::Color::getColorFrom24BitRGB(255,255,255));
    textArea1_6.setLinespacing(0);
    textArea1_6.setTypedText(TypedText(T_TEXTID62));
    textArea1_6.setAlpha(90);
    add(image5);
    add(opConfigHomeBtn);
    add(opConfigBackBtn);
    add(op1HeaterBtn);
    add(op3LightBtn);
    add(op3HumiBtn);
    add(op3HeaterBtn);
    add(op2LightBtn);
    add(op2HumiBtn);
    add(op2HeaterBtn);
    add(op1LightBtn);
    add(op1HumiBtn);
    add(textArea1_1);
    add(textArea1_2);
    add(textArea1_3);
    add(textArea1_4);
    add(textArea1_5);
    add(textArea1_6);
}

void opConfigSettingsScreenViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &opConfigHomeBtn)
    {
        //opConfigHomeBtnClicked
        //When opConfigHomeBtn clicked change screen to mainScreen
        //Go to mainScreen with slide screen transition towards West
        application().gotomainScreenScreenSlideTransitionWest();
    }
    else if (&src == &opConfigBackBtn)
    {
        //opConfigBackBtnClicked
        //When opConfigBackBtn clicked change screen to settingsScreen
        //Go to settingsScreen with slide screen transition towards West
        application().gotosettingsScreenScreenSlideTransitionWest();
    }
    else if (&src == &op1HeaterBtn)
    {
        //op1HeaterBtnClicked
        //When op1HeaterBtn clicked call virtual function
        //Call op1HeaterBtnClicked
        op1HeaterBtnClicked();
    }
    else if (&src == &op3LightBtn)
    {
        //op3LightBtnClicked
        //When op3LightBtn clicked call virtual function
        //Call op3LightBtnClicked
        op3LightBtnClicked();
    }
    else if (&src == &op3HumiBtn)
    {
        //op3HumiBtnClicked
        //When op3HumiBtn clicked call virtual function
        //Call op3HumiBtnClicked
        op3HumiBtnClicked();
    }
    else if (&src == &op3HeaterBtn)
    {
        //op3HeaterBtnClicked
        //When op3HeaterBtn clicked call virtual function
        //Call op3HeaterBtnClicked
        op3HeaterBtnClicked();
    }
    else if (&src == &op2LightBtn)
    {
        //op2LightBtnClicked
        //When op2LightBtn clicked call virtual function
        //Call op2LightBtnClicked
        op2LightBtnClicked();
    }
    else if (&src == &op2HumiBtn)
    {
        //op2HumiBtnClicked
        //When op2HumiBtn clicked call virtual function
        //Call op2HumiBtnClicked
        op2HumiBtnClicked();
    }
    else if (&src == &op2HeaterBtn)
    {
        //op2HeaterBtnClicked
        //When op2HeaterBtn clicked call virtual function
        //Call op2HeaterBtnClicked
        op2HeaterBtnClicked();
    }
    else if (&src == &op1LightBtn)
    {
        //op1LightBtnClicked
        //When op1LightBtn clicked call virtual function
        //Call op1LightBtnClicked
        op1LightBtnClicked();
    }
    else if (&src == &op1HumiBtn)
    {
        //op1HumiBtnClicked
        //When op1HumiBtn clicked call virtual function
        //Call op1HumiBtnClicked
        op1HumiBtnClicked();
    }
}
