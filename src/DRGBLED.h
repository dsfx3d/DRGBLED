#ifndef DRGBLEDH
#define DRGBLED_H

#include "Arduino.h"

class DRGBLED
{
public:
  DRGBLED();
  DRGBLED(int rPin, int gPin, int bPin);
  //
  void setColor(float r, float g, float b);
  //
  void transColor(float r, float g, float b);
  //
  void setTransTime(int t);
  //
  void setTransSteps(int s);

private:
  int rpin;
  int gpin;
  int bpin;
  float time;
  int steps;

  float red;
  float green;
  float blue;

  float cleanVal(float val, float diff, float target);
};

#endif
