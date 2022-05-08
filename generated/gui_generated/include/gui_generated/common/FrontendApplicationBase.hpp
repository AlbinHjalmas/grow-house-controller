/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef FRONTENDAPPLICATIONBASE_HPP
#define FRONTENDAPPLICATIONBASE_HPP

#include <mvp/MVPApplication.hpp>
#include <gui/model/Model.hpp>

class FrontendHeap;

class FrontendApplicationBase : public touchgfx::MVPApplication
{
public:
    FrontendApplicationBase(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplicationBase() { }

    // mainScreen
    void gotomainScreenScreenNoTransition();

    void gotomainScreenScreenSlideTransitionWest();


    // settingsScreen
    void gotosettingsScreenScreenSlideTransitionEast();

    void gotosettingsScreenScreenSlideTransitionWest();


    // tempHumiSettingsScreen
    void gototempHumiSettingsScreenScreenSlideTransitionEast();


    // dateTimeSettingsScreen
    void gotodateTimeSettingsScreenScreenSlideTransitionEast();


    // dayNightSettingsScreen
    void gotodayNightSettingsScreenScreenSlideTransitionEast();


    // opConfigSettingsScreen
    void gotoopConfigSettingsScreenScreenSlideTransitionEast();


    // Screen1
    void gotoScreen1ScreenNoTransition();

protected:
    touchgfx::Callback<FrontendApplicationBase> transitionCallback;
    FrontendHeap& frontendHeap;
    Model& model;

    // mainScreen
    void gotomainScreenScreenNoTransitionImpl();

    void gotomainScreenScreenSlideTransitionWestImpl();


    // settingsScreen
    void gotosettingsScreenScreenSlideTransitionEastImpl();

    void gotosettingsScreenScreenSlideTransitionWestImpl();


    // tempHumiSettingsScreen
    void gototempHumiSettingsScreenScreenSlideTransitionEastImpl();


    // dateTimeSettingsScreen
    void gotodateTimeSettingsScreenScreenSlideTransitionEastImpl();


    // dayNightSettingsScreen
    void gotodayNightSettingsScreenScreenSlideTransitionEastImpl();


    // opConfigSettingsScreen
    void gotoopConfigSettingsScreenScreenSlideTransitionEastImpl();


    // Screen1
    void gotoScreen1ScreenNoTransitionImpl();
};

#endif // FRONTENDAPPLICATIONBASE_HPP