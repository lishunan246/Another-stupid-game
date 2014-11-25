#include "Controller.h"

Controller::Controller()
{
}

Controller::~Controller()
{
}

void Controller::setControllerListener(ControllerListener* controllerListener)
{
	this->m_controllerListener = controllerListener;
}
