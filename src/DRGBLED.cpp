#include "Arduino.h"
#include "DRGBLED.h"

DRGBLED::DRGBLED(int rPin, int gPin, int bPin)
{
  rpin = rPin;
  gpin = gPin;
  bpin = bPin;
  pinMode(rpin, OUTPUT);
  pinMode(gpin, OUTPUT);
  pinMode(bpin, OUTPUT);

  red = green = blue = 0;
  time = 500;
  steps = 100;
}

void DRGBLED::setTransTime(int t)
{
  time = t;
}

void DRGBLED::setTransSteps(int s)
{
  steps = s;
}

void DRGBLED::setColor(float r, float g, float b)
{
  analogWrite(rpin, int(r));
  analogWrite(gpin, int(g));
  analogWrite(bpin, int(b));
  red = r;
  green = g;
  blue = b;
}

void DRGBLED::transColor(float r, float g, float b)
{
  float dr = (r - red) / steps;
  float dg = (g - green) / steps;
  float db = (b - blue) / steps;

  int delayed = time / steps;

  for (int i = 0; i < 100; i++)
  {
    float nr = cleanVal(red, dr, r);
    float ng = cleanVal(green, dg, g);
    float nb = cleanVal(blue, db, b);
    setColor(nr, ng, nb);
    delay(delayed);
  }
}

float DRGBLED::cleanVal(float val, float diff, float target)
{
  val = val + diff;
  if ((diff > 0 && val > target) || (diff < 0 && val < target))
  {
    return target;
  }
  else
  {
    return val;
  }
}
