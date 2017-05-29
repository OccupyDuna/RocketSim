// Stage object for storing values and functions related to flight tracking

#include <string>
#include <iostream>
#include "Stage.h"
using namespace std;

// Constructor
Stage::Stage(string nameInput, double mass, double altitude, double maxThrust, int numEngines)
{
	name = nameInput;
	velocity = 0;
	acceleration = 0;
	throttle = 1;
	setMass(mass);
	setAltitude(altitude);
	force = 0;
	acceleration = 0;
	setMaxThrust(maxThrust);
	setNumEngines(numEngines);
}

// Set mass
void Stage::setMass(double newMass)
{
	mass = newMass;
}
// Get mass
double Stage::getMass()
{
	return mass;
}

// Set altitude
void Stage::setAltitude(double newAltitude)
{
	altitude = newAltitude;
}
// Get altitude
double Stage::getAltitude()
{
	return altitude;
}

// Set Max Thrust
void Stage::setMaxThrust(double newMaxThrust)
{
	maxThrust = newMaxThrust;
}

double Stage::getThrust()
{
	return numEngines*throttle*maxThrust;
}

// Set numEngines
void Stage::setNumEngines(int newNumEngines)
{
	numEngines = newNumEngines;
}
// Get numEngines
int Stage::getNumEngines()
{
	return numEngines;
}

// Set throttle
void Stage::setThrottle(double newThrottle)
{
	throttle = newThrottle;
}
// Get throttle
double Stage::getThrottle()
{
	return throttle;
}

// Get net force on stage
double Stage::getForce()
{
	return (numEngines*throttle*maxThrust) - (mass*9.81);
}

// Set net acceleration on stage
void Stage::setAcceleration()
{
	//cout << "Force:\t" << getForce() << "\nMass:\t" << mass << endl;
	acceleration = getForce()/mass;
}
void Stage::setAcceleration(double newAcceleration)
{
	acceleration = newAcceleration;
}
// Get net Acceleration 
double Stage::getAcceleration()
{
	Stage::setAcceleration();
	//cout << acceleration << "\n" << endl;
	return acceleration;
}

// Display stage data
void Stage::dispStageData(double time)
{
	cout << "The time is:\t\tT+" << time << "\ts\n"
		<< name << " mass is:\t\t" << mass << "\t\tkg\n" 
		<< name << " altitude is:\t\t" << altitude << "\t\tm\n"
		<< name << " velocity is at:\t\t" << velocity << "\t\tm/s\n"
		<< name << " acceleration is:\t" << acceleration << "\t\tm/s/s\n"
		<< name << " throttle is at:\t\t" << throttle << "\t\t%\n"
		<< "+---------------------------------------------------------+"
		<< endl;
}

// Update stage data
void Stage::update(double dt)
{
	mass = mass;
	acceleration = getAcceleration();
	altitude = altitude + velocity * dt + 0.5 * acceleration * dt * dt; // Has to come before velocity bc velocity update makes incorrect
	velocity = velocity + acceleration * dt;
}


// Set velocity
void Stage::setVelocity(double newVelocity)
{
	velocity = newVelocity;
}

double Stage::getVelocity()
{
	return velocity;
}