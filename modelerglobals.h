#ifndef _MODELER_GLOBALS_H
#define _MODELER_GLOBALS_H

#ifndef M_PI
#define M_PI 3.141592653589793238462643383279502
#endif

// This is a list of the controls for the SampleModel
// We'll use these constants to access the values 
// of the controls from the user interface.
enum SampleModelControls
{ 
	XPOS, YPOS, ZPOS, SPIN, ROTATE_Z, TILT, COCKPIT, WING_HEIGHT, URIGHT_LEG, LRIGHT_LEG, ULEFT_LEG,
	LLEFT_LEG, RIGHT_FOOT, LEFT_FOOT, FEET, UPPER_LEGS, LOWER_LEGS, JUMP_CROUCH, MOVE, FLY, SHRINK, NUMCONTROLS
};

// Colors
#define COLOR_RED		1.0f, 0.0f, 0.0f
#define COLOR_GREEN		0.0f, 1.0f, 0.0f
#define COLOR_BLUE		0.0f, 0.0f, 1.0f
#define COLOR_LPURPLE	0.87f, 0.58f, 0.98f
#define COLOR_WHITE		1.0f, 1.0f, 1.0f
#define COLOR_GREY		0.25f, 0.25f, 0.25f

// We'll be getting the instance of the application a lot; 
// might as well have it as a macro.
#define VAL(x) (ModelerApplication::Instance()->GetControlValue(x))

#endif