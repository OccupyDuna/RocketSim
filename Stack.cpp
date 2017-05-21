// Stage object for storing values and functions related to flight tracking

#include <string>
#include <iostream>
#include "Stack.h"
using namespace std;

// Constructor
Stack::Stack(string nameInput, double mass, double altitude, double thrust)
{
	name = nameInput;
	velocity = 0;
	acceleration = 0;
	throttle = 1;
	setMass(mass);
	setAltitude(altitude);
	force = 0;
	acceleration = 0;
	setThrust(thrust);
}

// Set mass
void Stack::setMass(double newMass)
{
	mass = newMass;
}
// Get mass
double Stack::getMass()
{
	return mass;
}

// Set altitude
void Stack::setAltitude(double newAltitude)
{
	altitude = newAltitude;
}
// Get altitude
double Stack::getAltitude()
{
	return altitude;
}

// Set Max Thrust
void Stack::setThrust(double newThrust)
{
	thrust = newThrust;
}

// Set throttle
void Stack::setThrottle(double newThrottle)
{
	throttle = newThrottle;
}
// Get throttle
double Stack::getThrottle()
{
	return throttle;
}

// Get net force on stage
double Stack::getForce()
{
	return (thrust) - (mass*9.81);
}

// Set net acceleration on stage
void Stack::setAcceleration()
{
	//cout << "Force:\t" << getForce() << "\nMass:\t" << mass << endl;
	acceleration = getForce()/mass;
}
void Stack::setAcceleration(double newAcceleration)
{
	acceleration = newAcceleration;
}
// Get net Acceleration 
double Stack::getAcceleration()
{
	Stack::setAcceleration();
	//cout << acceleration << "\n" << endl;
	return acceleration;
}

// Display stage data
void Stack::dispStackData(double time)
{
	cout << "The time is:\t\tT+" << time << "\ts\n"
		<< name << " mass is:\t\t" << mass << "\t\tkg\n" 
		<< name << " altitude is:\t\t" << altitude << "\t\tm\n"
		<< name << " velocity is at:\t\t" << velocity << "\t\tm/s\n"
		<< name << " acceleration is:\t" << acceleration << "\t\tm/s/s\n"
		<< name << " throttle is at:\t\t" << throttle << "\t\t%\n"
		<< name << " thrust is at:\t\t" << thrust << "\t\t%\n"
		<< "+---------------------------------------------------------+"
		<< endl;
}

// Update stage data
void Stack::update(double dt, double newThrust)
{
	mass = mass;
	thrust = newThrust;
	acceleration = getAcceleration();
	altitude = altitude + velocity * dt + 0.5 * acceleration * dt * dt; // Has to come before velocity bc velocity update makes incorrect
	velocity = velocity + acceleration * dt;
}


// Set velocity
void Stack::setVelocity(double newVelocity)
{
	velocity = newVelocity;
}

double Stack::getVelocity()
{
	return velocity;
}