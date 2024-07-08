#define RED 9
#define YELLOW 10
#define GREEN 11

#define CHANGE_MIN 30000 // in millis; 30 seconds
#define CHANGE_MAX 50000 // in millis; 50 seconds
#define YELLOW_INTERVAL 7000 // in millis; 7 seconds

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop()
{
  digitalWrite(RED, HIGH);
  delay(randomDelay()); // stay red for a bit

  digitalWrite(RED, LOW); // red light over, turn off
  digitalWrite(GREEN, HIGH); // green light
  delay(randomDelay()); // stay green for a bit

  digitalWrite(GREEN, LOW); // time to let other cars by, turn off
  digitalWrite(YELLOW, HIGH); // slow down!
  delay(YELLOW_INTERVAL); // yellow transitions at a fixed time
  digitalWrite(YELLOW, LOW);  // time to stop, turn off yellow, restart loop
}

int randomDelay()
{
  // return a random number between
  // CHANGE_MIN and CHANGE_MAX
  return CHANGE_MIN + (rand() % CHANGE_MAX);
}


