#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  0, 0,                  // Button Count, Hat Switch Count
  true, true, true,     // X and Y and Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering


// Yours pins on the Arduino to which you connected your pedals
const int throttle = A0;
const int brake = A1;
const int clutch = A2;

int axisMap[3] = {throttle, brake, clutch}; // maps each axis 
int axisState[3] = {0, 0 , 0}; // stores last value of each axis
int axisMinMax[3][2]; // stores min and max raw input of each axis, to calibrate axes


// calibrates rawInput of each axis to input in range (0, 1023)
void axisCallibration(int axis, int rawInput){
  if (rawInput < axisMinMax[axis][0]){
    axisMinMax[axis][0] = rawInput;
    } else if(rawInput > axisMinMax[axis][1]){
      axisMinMax[axis][1] = rawInput;
    }
}
// sets input in range(0, 1023) to each axis
int setInput(int axis, int rawInput){
  int input = map(rawInput, axisMinMax[axis][0], axisMinMax[axis][1], 1023, 0);
  axisState[axis] = input;
}



void setup() {
  // joystick library setup
  Joystick.begin();
  Joystick.setXAxisRange(0, 1023);
  Joystick.setYAxisRange(0, 1023);
  Joystick.setZAxisRange(0, 1023);

  // fills axisMinMax array with values
  for(int axis = 0; axis < 3; axis++){
    int rawInput = analogRead(axis);
    axisMinMax[axis][0] = rawInput;
    axisMinMax[axis][1] = rawInput;
  }

}

void loop() {
  // for loop for each axis
  for(int axis = 0; axis < 3; axis++){

    // raw input of each axis
    int rawInput = analogRead(axisMap[axis]);

    //calibrates axis value
    axisCallibration(axis, rawInput);

    //updates axisState array with new values;
    setInput(axis, rawInput);
  }

  // sets value of each axis
  Joystick.setXAxis(axisState[0]);
  Joystick.setYAxis(axisState[1]);
  Joystick.setZAxis(axisState[2]);

  delay(20);
}
