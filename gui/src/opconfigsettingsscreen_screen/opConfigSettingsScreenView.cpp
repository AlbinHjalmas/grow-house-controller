#include <gui/opconfigsettingsscreen_screen/opConfigSettingsScreenView.hpp>

opConfigSettingsScreenView::opConfigSettingsScreenView()
{

}

void opConfigSettingsScreenView::setupScreen()
{
	op1HeaterBtn.forceState(false);
	op2HeaterBtn.forceState(false);
	op3HeaterBtn.forceState(false);
	op1HumiBtn.forceState(false);
	op2HumiBtn.forceState(false);
	op3HumiBtn.forceState(false);
	op1LightBtn.forceState(false);
	op2LightBtn.forceState(false);
	op3LightBtn.forceState(false);

	switch (presenter->getHeaterOp()) {
	case 1:
		op1HeaterBtn.forceState(true);
		break;
	case 2:
		op2HeaterBtn.forceState(true);
		break;
	case 3:
		op3HeaterBtn.forceState(true);
		break;
	}

	switch (presenter->getHumiOp()) {
	case 1:
		op1HumiBtn.forceState(true);
		break;
	case 2:
		op2HumiBtn.forceState(true);
		break;
	case 3:
		op3HumiBtn.forceState(true);
		break;
	}

	switch (presenter->getLightOp()) {
	case 1:
		op1LightBtn.forceState(true);
		break;
	case 2:
		op2LightBtn.forceState(true);
		break;
	case 3:
		op3LightBtn.forceState(true);
		break;
	}
}

void opConfigSettingsScreenView::tearDownScreen()
{

}

void opConfigSettingsScreenView::op1HeaterBtnClicked()
{
	// Check if button was deselected
	if (!op1HeaterBtn.getState()) {
		presenter->changeHeaterOp(0); // The heater is disconnected
	}
	else if(!(op2HeaterBtn.getState() || op3HeaterBtn.getState() || op1HumiBtn.getState() || op1LightBtn.getState()))
	{
		presenter->changeHeaterOp(1);
	}
	else
	{
		op1HeaterBtn.forceState(false);
	}
}

void opConfigSettingsScreenView::op1HumiBtnClicked()
{
	// Check if button was deselected
	if (!op1HumiBtn.getState()) {
		presenter->changeHumiOp(0); // The heater is disconnected
	}
	else if (!(op1HeaterBtn.getState() || op1LightBtn.getState() || op2HumiBtn.getState() || op3HumiBtn.getState()))
	{
		presenter->changeHumiOp(1);
	}
	else
	{
		op1HumiBtn.forceState(false);
	}
}

void opConfigSettingsScreenView::op1LightBtnClicked()
{
	// Check if button was deselected
	if (!op1LightBtn.getState()) {
		presenter->changeLightOp(0); // The Light is disconnected
	}
	else if (!(op1HeaterBtn.getState() || op1HumiBtn.getState() || op2LightBtn.getState() || op3LightBtn.getState()))
	{
		presenter->changeLightOp(1);
	}
	else
	{
		op1LightBtn.forceState(false);
	}
}

void opConfigSettingsScreenView::op2HeaterBtnClicked()
{
	// Check if button was deselected
	if (!op2HeaterBtn.getState()) {
		presenter->changeHeaterOp(0); // The heater is disconnected
	}
	else if (!(op1HeaterBtn.getState() || op3HeaterBtn.getState() || op2HumiBtn.getState() || op2LightBtn.getState()))
	{
		presenter->changeHeaterOp(2);
	}
	else
	{
		op2HeaterBtn.forceState(false);
	}
}

void opConfigSettingsScreenView::op2HumiBtnClicked()
{
	// Check if button was deselected
	if (!op2HumiBtn.getState()) {
		presenter->changeHumiOp(0); // The heater is disconnected
	}
	else if (!(op2HeaterBtn.getState() || op2LightBtn.getState() || op1HumiBtn.getState() || op3HumiBtn.getState()))
	{
		presenter->changeHumiOp(2);
	}
	else
	{
		op2HumiBtn.forceState(false);
	}
}

void opConfigSettingsScreenView::op2LightBtnClicked()
{
	// Check if button was deselected
	if (!op2LightBtn.getState()) {
		presenter->changeLightOp(0); // The light is disconnected
	}
	else if (!(op2HeaterBtn.getState() || op2HumiBtn.getState() || op1LightBtn.getState() || op3LightBtn.getState()))
	{
		presenter->changeLightOp(2);
	}
	else
	{
		op2LightBtn.forceState(false);
	}
}

void opConfigSettingsScreenView::op3HeaterBtnClicked()
{
	// Check if button was deselected
	if (!op3HeaterBtn.getState()) {
		presenter->changeHeaterOp(0); // The heater is disconnected
	}
	else if (!(op2HeaterBtn.getState() || op1HeaterBtn.getState() || op3HumiBtn.getState() || op3LightBtn.getState()))
	{
		presenter->changeHeaterOp(3);
	}
	else
	{
		op3HeaterBtn.forceState(false);
	}
}

void opConfigSettingsScreenView::op3HumiBtnClicked()
{
	// Check if button was deselected
	if (!op3HumiBtn.getState()) {
		presenter->changeHumiOp(0); // The heater is disconnected
	}
	else if (!(op3HeaterBtn.getState() || op3LightBtn.getState() || op2HumiBtn.getState() || op1HumiBtn.getState()))
	{
		presenter->changeHumiOp(3);
	}
	else
	{
		op3HumiBtn.forceState(false);
	}
}

void opConfigSettingsScreenView::op3LightBtnClicked()
{
	// Check if button was deselected
	if (!op3LightBtn.getState()) {
		presenter->changeLightOp(0); // The heater is disconnected
	}
	else if (!(op3HeaterBtn.getState() || op3HumiBtn.getState() || op1LightBtn.getState() || op2LightBtn.getState()))
	{
		presenter->changeLightOp(3);
	}
	else
	{
		op3LightBtn.forceState(false);
	}
}
