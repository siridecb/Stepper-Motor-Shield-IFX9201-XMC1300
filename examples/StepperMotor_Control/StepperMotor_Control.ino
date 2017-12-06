#include <IFX9201_XMC1300_StepperMotor.h>

#define DIR_PIN 9
#define STP_PIN 10
#define DIS_PIN 11

const int StepsPerRevolution = 200;  // change this to fit the total number of steps per revolution for your motor

// Stepper motor object
Stepper_motor MyStepperMotor = Stepper_motor(StepsPerRevolution, DIR_PIN, STP_PIN, DIS_PIN);

void setup() {
	// set pins' mode as OUTPUT, set default speed and enable the stepper motor
	MyStepperMotor.begin();

	// set the speed at 10 rpm:
	MyStepperMotor.setSpeed(10);

	// initialize the serial port:
	Serial.begin(9600);
}

void loop() {
	Serial.println("moves 4 revolutions in clockwise direction");
	MyStepperMotor.move_revolution(4);
	delay(1000);

	Serial.println("moves 3 revolutions in counterclockwise direction");
	MyStepperMotor.move_revolution(-3);
	delay(1000);

	Serial.println("moves 180 degree in clockwise direction");
	MyStepperMotor.move_degree(180);
	delay(1000);

	Serial.println("moves 90 degree in counterclockwise direction");
	MyStepperMotor.move_degree(-90);
	delay(1000);

	Serial.println("moves 400 steps in clockwise direction");
	MyStepperMotor.step(400);
	delay(1000);

	Serial.println("moves 200 steps in counterclockwise direction");
	MyStepperMotor.step(-200);
	delay(1000);

	Serial.println("reset the stepper motor to the initial position");
	MyStepperMotor.reset_motor();

	while(1);
}
