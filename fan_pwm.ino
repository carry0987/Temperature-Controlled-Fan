int sensorPin = A0;
int PWM = 3;
int sensorVal;
int PWMVal;

void setup() {
    //Put your setup code here, to run once:
    pinMode(sensorPin, INPUT);
    pinMode(PWM, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    //Put your main code here, to run repeatedly:
    //This code prints sensor value to the console
    Serial.println(sensorVal);
    delay(1000);

    //Read sensor value and set upper limit cap
    sensorVal = analogRead(sensorPin);
    if(sensorVal >800){
        sensorVal = 800;
    }

    //Map and assign pwm values to the fan output 0 to 255 corresponds to 0 to 100%
    PWMVal = map(sensorVal, 450, 800, 26, 255);

    //Set 450 as out cutout or cut in limit where the fan switches from off to the lower PWM limit
    if(sensorVal <450){
        PWMVal = 0;
    }

    //Write the PWM value to the pwm output pin
    analogWrite(PWM, PWMVal);
}
