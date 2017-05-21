// Stage object for storing values and functions related to flight tracking

#include <string>
#include <iostream>
using namespace std;

class Stack {
public:
	// Constructor
	Stack(string name, double mass, double altitude, double thrust);

	// Set mass
	void setMass(double mass);
	// Get mass
	double getMass();

	// Set altitude
	void setAltitude(double altitude);
	// Get altitude
	double getAltitude();

	// Set max engine thrust
	void setThrust(double thrust);

	// Set throttle
	void setThrottle(double throttle);
	// Get throttle
	double getThrottle();

	// Get net Force on stage
	double getForce();

	// Set accleration on stage
	void setAcceleration();
	void setAcceleration(double acceleration);
	// Get acceleration of stage
	double getAcceleration();

	// Display stage data
	void dispStackData(double time);

	// Update stage data
	void update(double dt, double thrust);

	// Set velocity
	void setVelocity(double velocity);
	double getVelocity();

private:
	string name;
	double mass; // Mass of stage in kg
	double altitude; // Altitude of stage in m
	double velocity; // Velocity of stage in m/s
	double acceleration; // Acceleration of stage in m/s/s
	double force;
	double thrust; //Thrust per engine
	int numEngines; // Number of engines active
	double throttle; // Throttle of active engines
};
