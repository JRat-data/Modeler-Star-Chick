#include "modelerview.h"
#include "modelerapp.h"
#include "modelerdraw.h"
#include <FL/gl.h>

#include "modelerglobals.h"

class ShipModel : public ModelerView
{
public:
	ShipModel(int x, int y, int w, int h, char *label)
		: ModelerView(x, y, w, h, label) { }

	virtual void draw();
};

ModelerView* createShipModel(int x, int y, int w, int h, char *label)
{
	return new ShipModel(x, y, w, h, label);
}

void ShipModel::draw()
{
	ModelerView::draw();

	// draw the floor
	setAmbientColor(.1f, .1f, .1f);
	setDiffuseColor(COLOR_RED);
	glPushMatrix();
	glTranslated(-5, -0.4, -5);
	drawBox(10, 0.01f, 10);
	glPopMatrix(); 

	setAmbientColor(1.0f, 1.0f, 1.0f);
	setDiffuseColor(COLOR_WHITE);
	glPushMatrix();
	glTranslated(VAL(XPOS), VAL(YPOS), VAL(ZPOS));
	glTranslated(0, ((VAL(JUMP_CROUCH) / 45)), 0);
	glTranslated(0, ((VAL(JUMP_CROUCH) / 45)), 0);

	glRotated(VAL(SHRINK), 0, 0, 0); 
	glRotated(VAL(SPIN), 0, 1, 0);
	glRotated(VAL(ROTATE_Z), 0, 0, 1);
	glRotated(VAL(TILT), 1, 0, 0);
	glRotated(VAL(FLY), 1, 0, 0); 

		// draw cockpit
		glPushMatrix();
		setDiffuseColor(COLOR_GREY);
		glRotated(90, 0, 1, 0);
		glTranslated(0.75, 3.35, -0.25);
		drawCylinder(1, 0.1, 0.1);
		glRotated(90, 0, -1, 0);
		
		glRotated(VAL(COCKPIT), -1, 0, 0);

		glTranslated(0, 0, 0.75); 
		drawTriangle(0.5, 0.75, 0,
			-0.25, 0, -0.75,
			1.25, 0, -0.75);

		glRotated(90, 0, -1, 0);
		glTranslated(-0.5, 0, -0.5);
		drawTriangle(0.5, 0.75, 0,
			-0.25, 0, -0.75,
			1.75, 0, 0);
		drawTriangle(0.5, 0.75, 0,
			-0.25, 0, 0.75,
			1.75, 0, 0);

		glPopMatrix();

		// draw body
		glPushMatrix();
		setDiffuseColor(COLOR_WHITE);
		glTranslated(-0.75, 2.35, -1);
		drawBox(2, 1, 2.5);

		glRotated(180, 0, 0, 1);	// Rotate triangle cause it looked grey on other side
		glTranslated(-1, 0, 5);		// values become a bit weird because of this
		drawTriangle(0, 0, 0.25,
					-1.0, 0, -2.5,
					1.0, 0, -2.5);

		glRotated(90, 0, 0, 1);
		glTranslated(-1, -1, 0);
		drawTriangle(1.0, 1.0, 0.25,
					0, 0, -2.5,
					1.0, 0, -2.5);

		glTranslated(0, 2, 0);
		drawTriangle(1.0, -1.0, 0.25,
					0, 0, -2.5,
					1.0, 0, -2.5);

		//setDiffuseColor(COLOR_BLUE);
		glRotated(90, 0, 0, -1);
		drawTriangle(1.0, 1.0, 0.25,
					0, 0, -2.5,
					2.0, 0, -2.5);
		glPopMatrix();

		// draw thrusters (Body)
		glPushMatrix();

		setDiffuseColor(COLOR_GREY);
		glTranslated(-0.25, 2.85, -1.5);
		drawCylinder(0.5, 0.5, 0.25);
		glTranslated(1, 0, 0);
		drawCylinder(0.5, 0.5, 0.25);

		glPopMatrix();

		// draw right wing
		glPushMatrix();
		glTranslated(-0.75, 2.85, -1);
		setDiffuseColor(COLOR_BLUE);
		glTranslated(-1,0,0.5);
		drawTriangle(1, 0.5, 2,
					1, 0.5, -0.5,
					-2.5, -0.5 + VAL(WING_HEIGHT) + (VAL(FLY)/10) + (-VAL(JUMP_CROUCH) / 20), -1.25);
		glTranslated(0, -0.25, -1);
		drawTriangle(1, 0.75, 0.5,
					1, -0.25, 0.5,
					-2.5, -0.25 + VAL(WING_HEIGHT) + (VAL(FLY)/10) + (-VAL(JUMP_CROUCH) / 20), -0.25);
		glTranslated(0, 0, 2.5);
		drawTriangle(1, 0.75, 0.5,
					1, -0.25, 0.5,
					-2.5, -0.25 + VAL(WING_HEIGHT) + (VAL(FLY)/10) + (-VAL(JUMP_CROUCH) / 20), -2.75);
		glTranslated(0, -0.75, -1.5);
		drawTriangle(1, 0.5, 2,
					1, 0.5, -0.5,
					-2.5, 0.5 + VAL(WING_HEIGHT) + (VAL(FLY)/10) + (-VAL(JUMP_CROUCH) / 20), -1.25);

		glPopMatrix();

		// draw left wing
		glPushMatrix();

		glTranslated(1.25, 2.85, -1);
		setDiffuseColor(COLOR_BLUE);
		glTranslated(1, 0, 1.5);
		drawTriangle(-1, 0.5, -1.5,
					-1, 0.5, 1,
					2.5, -0.5 + VAL(WING_HEIGHT) + (VAL(FLY)/10) + (-VAL(JUMP_CROUCH)/20), -2.25);
		glTranslated(0, -0.25, -2);
		drawTriangle(-1, 0.75, 0.5,
					-1, -0.25, 0.5,
					2.5, -0.25 + VAL(WING_HEIGHT) + (VAL(FLY)/10) + (-VAL(JUMP_CROUCH) / 20), -0.25);
		glTranslated(0, 0, 2.5);
		drawTriangle(-1, 0.75, 0.5,
					-1, -0.25, 0.5,
					2.5, -0.25 + VAL(WING_HEIGHT) + (VAL(FLY)/10) + (-VAL(JUMP_CROUCH) / 20), -2.75);
		glTranslated(0, -0.75, -1.5);
		drawTriangle(-1, 0.5, 2,
					-1, 0.5, -0.5,
					2.5, 0.5 + VAL(WING_HEIGHT) + (VAL(FLY)/10) + (-VAL(JUMP_CROUCH) / 20), -1.25);

		glPopMatrix();

		// draw right leg
		setDiffuseColor(COLOR_GREY);
		glPushMatrix();

		// upper right leg
		glTranslated(-0.25, 2.15, 0);
		glRotated(VAL(URIGHT_LEG), 1, 0, 0);
		glRotated(VAL(UPPER_LEGS), 1, 0, 0);	// made for specific animations
		glRotated(VAL(JUMP_CROUCH), 1, 0, 0);	// for jumping
		glRotated(VAL(MOVE), 1, 0, 0);			// for walking
		drawSphere(0.25);
		glTranslated(-0.2, -0.9, 0.75);
		glRotated(45, -1, 0, 0);
		drawBox(0.35, 1, 0.35);
		glRotated(45, 1, 0, 0);

		// lower right leg
		glTranslated(0.2, 0, 0.25);
		glRotated(VAL(LRIGHT_LEG), 1, 0, 0);
		glRotated(VAL(LOWER_LEGS), 1, 0, 0);	// made for specific animations
		glRotated(-2*VAL(JUMP_CROUCH), 1, 0, 0);	// for jumping
		glRotated(VAL(MOVE), 1, 0, 0);			// for walking
		drawSphere(0.25);
		glTranslated(-0.2, -1, -1.25);
		glRotated(45, 1, 0, 0);
		drawBox(0.35, 1.5, 0.35);
		glRotated(45, -1, 0, 0);

		// right foot
		glTranslated(0.2, -0.25, 0);
		glRotated(VAL(RIGHT_FOOT), 1, 0, 0);
		glRotated(VAL(FEET), 1, 0, 0);			// made for specific animations
		glRotated(VAL(JUMP_CROUCH), 1, 0, 0);	// for jumping
		drawSphere(0.25);
		glTranslated(-0.4, -0.35, -0.25);
		drawBox(0.75, 0.25, 1.5);

		glPopMatrix();

		// draw left leg
		glPushMatrix();

		// upper left leg
		glTranslated(0.75, 2.15, 0);
		glRotated(VAL(ULEFT_LEG), 1, 0, 0);
		glRotated(VAL(UPPER_LEGS), 1, 0, 0);	// made for specific animations
		glRotated(VAL(JUMP_CROUCH), 1, 0, 0);	// for jumping
		glRotated(-VAL(MOVE), 1, 0, 0);			// for walking
		drawSphere(0.25);
		glTranslated(-0.2, -0.9, 0.75);
		glRotated(45, -1, 0, 0);
		drawBox(0.35, 1, 0.35);
		glRotated(45, 1, 0, 0);

		// lower left leg
		glTranslated(0.2, 0, 0.25);
		glRotated(VAL(LLEFT_LEG), 1, 0, 0);
		glRotated(VAL(LOWER_LEGS), 1, 0, 0);	// made for specific animations
		glRotated(-2*VAL(JUMP_CROUCH), 1, 0, 0);	// for jumping
		glRotated(-VAL(MOVE), 1, 0, 0);			// for walking
		drawSphere(0.25);
		glTranslated(-0.2, -1, -1.25);
		glRotated(45, 1, 0, 0);
		drawBox(0.35, 1.5, 0.35);
		glRotated(45, -1, 0, 0);

		// left foot
		glTranslated(0.2, -0.25, 0);
		glRotated(VAL(LEFT_FOOT), 1, 0, 0);
		glRotated(VAL(FEET), 1, 0, 0);			// made for specific animations
		glRotated(VAL(JUMP_CROUCH), 1, 0, 0);	// for jumping
		drawSphere(0.25);
		glTranslated(-0.4, -0.35, -0.25);
		drawBox(0.75, 0.25, 1.5);

		glPopMatrix();

	glPopMatrix();
}

int main()
{
	// Initialize the controls
	// Constructor is ModelerControl(name, minimumvalue, maximumvalue, 
	// stepsize, defaultvalue)
	ModelerControl controls[NUMCONTROLS];
	controls[XPOS] = ModelerControl("X Position", -5, 5, 0.1f, 0);
	controls[YPOS] = ModelerControl("Y Position", 0, 5, 0.1f, 0);
	controls[ZPOS] = ModelerControl("Z Position", -5, 5, 0.1f, 0);
	controls[SPIN] = ModelerControl("Spin", -180, 180, 1, 0);
	controls[ROTATE_Z] = ModelerControl("Rotate Z", -25, 25, 1, 0);
	controls[TILT] = ModelerControl("Tilt", -25, 25, 1, 0);
	controls[COCKPIT] = ModelerControl("Cockpit", 0, 90, 1, 0);
	controls[WING_HEIGHT] = ModelerControl("Wing Height", 0, 2.5, 0.1, 0);
	controls[URIGHT_LEG] = ModelerControl("Upper Right Leg", -45, 45, 1, 0);
	controls[LRIGHT_LEG] = ModelerControl("Lower Right Leg", -90, 90, 1, 0);
	controls[ULEFT_LEG] = ModelerControl("Upper Left Leg", -45, 45, 1, 0);
	controls[LLEFT_LEG] = ModelerControl("Lower Left Leg", -90, 90, 1, 0);
	controls[RIGHT_FOOT] = ModelerControl("Right Foot", -45, 45, 1, 0);
	controls[LEFT_FOOT] = ModelerControl("Left Foot", -45, 45, 1, 0);
	controls[UPPER_LEGS] = ModelerControl("Upper Legs", -45, 45, 1, 0);
	controls[LOWER_LEGS] = ModelerControl("Lower Legs", -90, 90, 1, 0);
	controls[FEET] = ModelerControl("Feet", -45, 45, 1, 0);
	controls[JUMP_CROUCH] = ModelerControl("Jump/Crouch/Land", -45, 45, 1, 0);
	controls[MOVE] = ModelerControl("Move", -45, 45, 1, 0);
	controls[FLY] = ModelerControl("Fly", -10, 10, 1, 0);
	controls[SHRINK] = ModelerControl("Shrink", 0, 80, 1, 0);

	ModelerApplication::Instance()->Init(&createShipModel, controls, NUMCONTROLS);
	return ModelerApplication::Instance()->Run();
}