/*  Smolder Effect
 *  Eric Reuter
 *   
 *  This code generates a smoldering fire lighting effect to be used with orange LEDs.  A random brightness 
 *  level is selected, along with a random interval of time to get there from the current level.  
 *  Once the level is reached, reset() is called, and a new level/interval are generated.  
 *  Constraints for brightness (0 to 255) and interval length (in ms) are defined at the top.
 *  Code is non-blocking, using millis() for timing.  Just call it in the loop.
 */
