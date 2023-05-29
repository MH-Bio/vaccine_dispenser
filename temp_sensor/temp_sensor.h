#ifndef temp_sensor_h
#define temp_sensor_h

class temp_sensor{
private:
	double external_temp; // external temp in faranheight
	double internal_temp; // used for internal temp in faranheight
	double internal_temp_celcius; // internal temp in celcius
	double voltage;
	
public:
	temp_sensor(int analog_pin);
	void update_internal_temp(double internal_temp_celcius);
	void update_external_temp(double external_temp, double voltage);
	double getInternalTemperature();
	double getExternalTemperature;
};

#endif