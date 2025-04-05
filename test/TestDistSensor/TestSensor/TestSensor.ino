const int triggerPin = 10, echoPin = 11;
unsigned long duration = 0, distance = 0;

void setup()
{
    pinMode(triggerPin, OUTPUT);
    digitalWrite(triggerPin, LOW);

    pinMode(echoPin, INPUT);
    Serial.begin(9600);
}

void loop()
{
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10); 
    digitalWrite(triggerPin, LOW);        
    duration = pulseIn(echoPin, HIGH, 10000);
    distance = duration * 0.17;
    Serial.print("Distance: ");
    Serial.println(distance);
}