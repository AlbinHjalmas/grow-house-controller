#include <gui/opconfigsettingsscreen_screen/opConfigSettingsScreenView.hpp>
#include <gui/opconfigsettingsscreen_screen/opConfigSettingsScreenPresenter.hpp>

opConfigSettingsScreenPresenter::opConfigSettingsScreenPresenter(opConfigSettingsScreenView& v)
    : view(v)
{
}

void opConfigSettingsScreenPresenter::activate()
{

}

void opConfigSettingsScreenPresenter::deactivate()
{

}

void opConfigSettingsScreenPresenter::changeHeaterOp(int op)
{
	model->changeHeaterOp(op);
}

void opConfigSettingsScreenPresenter::changeHumiOp(int op)
{
	model->changeHumiOp(op);
}

void opConfigSettingsScreenPresenter::changeLightOp(int op)
{
	model->changeLightOp(op);
}

int opConfigSettingsScreenPresenter::getHeaterOp()
{
	return model->getHeaterOp();
}

int opConfigSettingsScreenPresenter::getHumiOp()
{
	return model->getHumiOp();
}

int opConfigSettingsScreenPresenter::getLightOp()
{
	return model->getLightOp();
}
