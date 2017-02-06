/*
 * Project VibroLight
 * Description:
 * Author: Melissa Labbe
 * Date: 2/4/17
 */

// -----------------------------------------
// Function and Variable with Piezo Vibration Sensor
// -----------------------------------------
// In this example, we're going to register a Particle.variable() with the cloud so that we can read vibration levels from the sensor.

// We're going to start by declaring which pins everything is plugged into.

int piezosensor = A0; // This is where your piezosensor is plugged in.

int analogvalue; // Here we are declaring the integer variable analogvalue, which we will use later to store the value of the piezosensor.


// Next we go into the setup function.

void setup() {

    // First, declare all of our pins. This lets our device know which ones will be used for outputting voltage, and which ones will read incoming voltage.
    pinMode(piezosensor,INPUT);  // Our piezosensor pin is input (reading the piezosensor)

    // We are going to declare a Particle.variable() here so that we can access the value of the piezosensor from the cloud.
    Particle.variable("analogvalue", &analogvalue, INT);
    // This is saying that when we ask the cloud for "analogvalue", this will reference the variable analogvalue in this app, which is an integer variable.

    // We are also going to declare a Particle.function so that we can turn the LED on and off from the cloud.
    //Particle.function("led",ledToggle);
    // This is saying that when we ask the cloud for the function "led", it will employ the function ledToggle() from this app.

}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // check to see what the value of the piezosensor is and store it in the int variable analogvalue
    analogvalue = analogRead(piezosensor);
    delay(100);

}
