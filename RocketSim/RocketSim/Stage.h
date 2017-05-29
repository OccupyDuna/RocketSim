// Stage object for storing values and functions related to flight tracking

#include <string>
#include <iostream>
using namespace std;

class Stage {
public:
	// Constructor
	Stage(string name, double mass, double altitude, double maxThrust, int numEngines);

	// Set mass
	void setMass(double mass);
	// Get mass
	double getMass();

	// Set altitude
	void setAltitude(double altitude);
	// Get altitude
	double getAltitude();

	// Set max engine thrust
	void setMaxThrust(double maxThrust);

	// Get total thrust
	double getThrust();

	// Set numEngines
	void setNumEngines(int numEngines);
	// Get numEngines
	int getNumEngines();

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
	void dispStageData(double time);

	// Update stage data
	void update(double dt);

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
	double maxThrust; //Thrust per engine
	int numEngines; // Number of engines active
	double throttle; // Throttle of active engines
};
