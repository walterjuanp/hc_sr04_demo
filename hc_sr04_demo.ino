/* HC-SR04 demo application */// Echo Pinconst int TRIG_PIN = 7;// Trigger Pinconst int ECHO_PIN = 8;// From datasheet, the ranging distanceis 2cm – 400cm (116 - 23200 us pulse)const unsigned int MAX_DIST = 23200;const unsigned int MIN_DIST = 116;// Duration used to calculate distancelong pulse_width, distance_cm, distance_inch; void setup() {    // We'll use the serial monitor to view the sensor output    Serial.begin(9600);    // The Trigger pin will tell the sensor to range find    pinMode(TRIG_PIN, OUTPUT);    pinMode(ECHO_PIN, INPUT);    // Initial state    digitalWrite(TRIG_PIN, LOW);}void loop() {    // Trigger/Echo pin cycle is used to determine the distance of the nearest object by bouncing soundwaves off of it    // Basically we need 10 microseconds pulse, the 2 microsends is for security dealy    digitalWrite(TRIG_PIN, LOW);     delayMicroseconds(2);     digitalWrite(TRIG_PIN, HIGH);    delayMicroseconds(10);      digitalWrite(TRIG_PIN, LOW);    pulse_width = pulseIn(ECHO_PIN, HIGH);        // The constants are found in the datasheet, and calculated from the assumed speed of sound in air at sea level (~340 m/s).    distance_cm = pulse_width/58.0;    distance_inch = pulse_width/148.2;        // Print out results    if ( pulse_width > MAX_DIST ) {        Serial.println("Out of range");    } else {        Serial.print(pulse_width);        Serial.print(" -> ");        Serial.print(distance_cm);        Serial.print(" cm \t");        Serial.print(distance_inch);        Serial.println(" in");    }        // Delay 100 milliseconds before next reading.    delay(100);}