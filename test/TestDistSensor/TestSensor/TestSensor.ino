void setup()
{

    pinMode(trigPin, OUTPUT); // Définit le trigPin comme sortie
    pinMode(echoPin, INPUT); // Définit le echoPin comme entrée
    Serial.begin(9600); // Commence la communication série
}

void loop()
{ // Efface le trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2); // Met le trigPin à l'état HIGH pendant 10 microsecondes
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);        // Lit le echoPin, renvoie le temps de trajet de l'onde sonore en microsecondes
    duration = pulseIn(echoPin, HIGH); // Calcul de la distance
    distance = duration * 0.034 / 2;   // La vitesse du son est d'environ 0.034 cm par microseconde
    // Affiche la distance sur le moniteur série
    Serial.print("Distance: ");
    Serial.println(distance);
}