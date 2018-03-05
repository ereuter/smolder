

/*  Smolder Effect
 *  Eric Reuter
 *   
 *  This code generates a smoldering fire lighting effect to be used with orange LEDs.  A random brightness 
 *  level is selected, along with a random interval of time to get there from the current level.  
 *  Once the level is reached, reset() is called, and a new level/interval are generated.  
 *  Constraints for brightness (0 to 255) and interval length (in ms) are defined at the top.
 *  Code is non-blocking, using millis() for timing.  Just call it in the loop.
 */

#define LED 11             // Defines pin for output.  Must be capable of PWM.
#define minBright 80
#define maxBright 255
#define minInterval 80
#define maxInterval 1000

int oldLevel;
int newLevel = maxBright;
int dt = 10;
int dir = 1;              // 0 = decreasing brightness, 1 = increasing brightness
int level = minBright;
int interval;
long lastTime = millis();


void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  smolder();
}

void reset(){
  oldLevel = newLevel;
  newLevel = random(minBright, maxBright);
  interval = random(minInterval, maxInterval);
  dt = interval/(abs(newLevel-oldLevel)+1);    // +1 needed to avoid potential divide by 0
  dir = ((newLevel > oldLevel) ? 1 : 0);
}

void smolder(){
  if ((millis() - lastTime) >= dt){
      lastTime = millis();  
      switch(dir){
        case 0:{ 
          level -= 1;
          analogWrite(LED, level);
          if (level <= newLevel){
            reset();
          }
          break;
        }
        case 1:{
          level += 1;
          analogWrite(LED, level);
          if (level >= newLevel){
            reset();
          }
          break;
        }
      }
    }
}
