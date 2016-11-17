// Sparkfun MicroView Temperature Sensor Experiment 6
// Modified to display both Farenheit and Centigrade
#include <MicroView.h>		// include MicroView library

MicroViewWidget *widget;	// declare widget pointer
char temp_f_str[50], temp_c_str[50];

int sensorPin = A0;		// select the input pin for the temperature sensor
int sensorValue = 0;	// variable to store the value coming from the sensor

void setup() {
	pinMode(sensorPin,INPUT);	// set sensor pin as INPUT
	uView.begin();				// start MicroView
	uView.clear(PAGE);			// clear page
  widget = new MicroViewGauge(32,18,0,100,WIDGETSTYLE0 + WIDGETNOVALUE);    // declare as gauge widget
}

void loop() {
	sensorValue= analogRead(sensorPin);				// read sensor pin value
	float voltage = sensorValue * 5.0;				// voltage at pin in volt
	voltage /= 1024.0; 								// voltage = sensorValue x (5/1024)
	float temperatureC = (voltage - 0.5) * 100 ; 	// C = (voltage - 0.5) x 100
  float temperatureF = (temperatureC * 1.8) + 32;
	widget->setValue(temperatureF);					// set temperature value to the gauge
  sprintf(temp_f_str, "%dF  ", (int)temperatureF);
  sprintf(temp_c_str, "%dC  ", (int)temperatureC);

  uView.setCursor(0,38);                  // position cursor for farenheit
  uView.print(temp_f_str);
  uView.setCursor(32,38);                 // position curor for centigrade
  uView.print(temp_c_str);
	uView.display();								// display gauge tick
}
