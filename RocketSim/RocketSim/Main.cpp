//John Gilleran
// Main for rocket simulation program

#include <iostream>
#include <string>
#include "Stage.h"
#include "Stack.h"

int main() 
{
// Initialize simulation
	// Welcome message
	cout << "Welcome to RocketSim!" << "\n+---------------------------------------------------------+" << endl;

	// Set simulation parameters
	double sampleRate = 100; // Rate of simulation 'frames' in Hz
	double dt = 1 / sampleRate;
	double tStart = 0;
	double tEnd = 20;
	double time = tStart;

// Create objects for stage 1, stage 2 and payload
	double startingAlt = 0;
	// Stage 1 initial conditions
	double stage1TWR = 3;
	double stage1Mass = 1000;
	double stage1Thrust = stage1TWR*stage1Mass*9.81;
	int stage1EngineNum = 1;
	// Stage 2 initial conditions
	double stage2TWR = 1;
	double stage2Mass = 100;
	double stage2Thrust = stage2TWR*stage2Mass*9.81;
	int stage2EngineNum = 1;
	// Payload initial conditions
	double payloadTWR = 0;
	double payloadMass = 50;
	double payloadThrust = payloadTWR*payloadMass*9.81;
	int payloadEngineNum = 0;

	Stage stage1("Stage 1", stage1Mass, startingAlt, stage1Thrust, stage1EngineNum);
	Stage stage2("Stage 2", stage2Mass, startingAlt, stage2Thrust, stage2EngineNum);
	Stage payload("Payload", payloadMass, startingAlt, payloadThrust, payloadEngineNum);

// Create stack object
	double stackMass = stage1Mass + stage2Mass + payloadMass;
	Stack rocket("Rocket", stackMass, startingAlt, stage1Thrust*stage1EngineNum);
	rocket.dispStackData(time);

	// Display intial values of created objects
	stage1.dispStageData(time);
	stage2.dispStageData(time);

	// Run simulation
	int toggle = 1;
	double apogee = rocket.getAltitude();
	double apogeeTime = tStart;
	double maxVelocity = 0;
	double maxVelocityTime = tStart;
	int count = 0;

	while (time <= tEnd)
	{
		// Update time
		time = time + dt;
		count = count + 1;

		// Update values of objects after 1 timestep
		stage1.update(dt);
		rocket.update(dt, stage1.getThrust());
		
		if (time >= 5)
		{
			if (toggle == 1)
			{
				stage1.setThrottle(0);
				toggle = 0;
			}
		}
		if (time != tStart)
		{
			if (rocket.getAltitude() <= 0)
			{
				rocket.setAcceleration(0);
				rocket.setAltitude(0);
				rocket.setVelocity(0);
				cout << "Break at T+" << time << endl;
				break;
			}
		}

		// Track flight data
		if (rocket.getAltitude() > apogee)
		{
			apogee = rocket.getAltitude();
			apogeeTime = time;

		}
		if (rocket.getVelocity() > maxVelocity)
		{
			maxVelocity = rocket.getVelocity();
			maxVelocityTime = time;
		}


		// Display update results
		if (count == sampleRate)
		{
			rocket.dispStackData(time);
			count = 0;
		}

		//Testing
		//cout << time << endl;

	}

	// Report simulation results
	cout << "\n+---------------------------------------------------------+" <<
		"\nApogee was " << apogee << "m and occurred at T+" << apogeeTime << "s.\n"
		<< "Max velocity was " << maxVelocity << "m/s and occurred at T+" << maxVelocityTime
		<< "s.\n" << endl;

	//// Display updates values of created objects
	//stage1.dispStageData(time);
	//stage2.dispStageData(time);
	cout << "Thanks for using RocketSim!" << endl;
}