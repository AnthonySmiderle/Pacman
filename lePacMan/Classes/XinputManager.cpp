#include "XinputManager.h"


DevitoCult::XinputController DevitoCult::XinputManager::controllers[4];
DevitoCult::XinputManager::XinputManager()
{
	//sets system controllers to the appropriate indext
	for (int index = 0; index < 4; index++) {
		controllers[index].setControllerIndex(index);
	}
}

bool DevitoCult::XinputManager::controllerConnected(int index)
{
	if (index < 0 || index >= 4)
		return false;
	XINPUT_STATE connected;
	return XInputGetState(index,&connected) == ERROR_SUCCESS;
}

//returns a controller at a given index
DevitoCult::XinputController * DevitoCult::XinputManager::getController(int index)
{
	if(index >=0 && index < 4)
	return &controllers[index];
	return nullptr;
}

//updates all controllers
void DevitoCult::XinputManager::update()
{

	for (int index = 0; index < 4; index++) {
		if (controllerConnected(index)) {
			controllers[index].update();
		}
	}

}

void DevitoCult::XinputController::setControllerIndex(int index)
{
	this->index = index;
}

void DevitoCult::XinputController::update()
{
	//check the state of the controller
	if (index >= 0 && index < 4) {
		XInputGetState(index, &state);
	}
}

void DevitoCult::XinputController::deadZoneSticks(float dz)
{
	deadZoneStick = dz;
}

void DevitoCult::XinputController::deadZoneTriggers(float dz)
{
	deadZoneTrigger = dz;
}

float DevitoCult::XinputController::getLStickDirection()
{
	float x = (float)state.Gamepad.sThumbLX / 32768,
		y = (float)state.Gamepad.sThumbLX / 32767;
	return sqrt(x*x + y * y);
}

void DevitoCult::XinputController::updateSticks(Stick sticks[2])
{
	//LEFT STICK
	float x = (float)state.Gamepad.sThumbLX / 32768,
		y = (float)state.Gamepad.sThumbLX / 32767;

	//check the direction of the L stick
	if (sqrt(x*x + y * y) > deadZoneStick) {


		//the hardcoded numbers are just converting the float value returned into a number that goes from -1 to 1
		if (state.Gamepad.sThumbLX < 0)
			sticks[0].x = (float)state.Gamepad.sThumbLX / 32768;//conver to a float from 1 -> 1;
		else
			sticks[0].x = (float)state.Gamepad.sThumbLX / 32767;

		if (state.Gamepad.sThumbLY < 0)
			sticks[0].y = (float)state.Gamepad.sThumbLY / 32768;//conver to a float from 1 -> 1;
		else
			sticks[0].y = (float)state.Gamepad.sThumbLY / 32767;

	}
	else {

		sticks[0].x = 0.0f;
		sticks[0].y = 0.0f;

	}
	x = (float)state.Gamepad.sThumbRX / 32768,
		y = (float)state.Gamepad.sThumbRX / 32767;


	if (sqrt(x*x + y * y) > deadZoneStick) {
		//RIGHT STICK
		if (state.Gamepad.sThumbRX < 0)
			sticks[1].x = (float)state.Gamepad.sThumbRX / 32768;//conver to a float from -1 -> 1;
		else
			sticks[1].x = (float)state.Gamepad.sThumbRX / 32767;

		if (state.Gamepad.sThumbRY < 0)
			sticks[1].y = (float)state.Gamepad.sThumbRY / 32768;//conver to a float from -1 -> 1;
		else
			sticks[1].y = (float)state.Gamepad.sThumbRY / 32767;
	}

	else {

		sticks[1].x = 0.0f;
		sticks[1].y = 0.0f;

	}
}

void DevitoCult::XinputController::getTriggers(Triggers & triggers)
{
	float l = (float)state.Gamepad.bLeftTrigger / 255, r = (float)state.Gamepad.bRightTrigger / 255;
	triggers = Triggers{ l < deadZoneTrigger ? 0 : l,r < deadZoneTrigger ? 0 : r };//converts byte to a number from 0 to 1
}

bool DevitoCult::XinputController::isButtonPressed(int button)
{
	return button & state.Gamepad.wButtons;//bitwise &, checks if button and wButtons are equal
}

bool DevitoCult::XinputController::isButtonReleased(int button)
{
	return !isButtonPressed(button);
}

void DevitoCult::XinputController::setVibration(float left, float right)
{
	///https://lcmccauley.wordpress.com/tag/xinput-vibration/

	//zero memory is a windows macro that initializes a lot of their stuff
	//such as xinput states
	ZeroMemory(&vibration, sizeof(XINPUT_VIBRATION));

	//again, converts a number to a number between 0 and 1
	vibration.wLeftMotorSpeed = int(left*65535.0f);
	vibration.wRightMotorSpeed = int(right*65535.0f);

	XInputSetState(index, &vibration);
}

bool DevitoCult::XinputController::isVibrating()
{
	if (vibration.wLeftMotorSpeed > 0.0f || vibration.wRightMotorSpeed > 0.0f)
		return true;
	return false;
}
