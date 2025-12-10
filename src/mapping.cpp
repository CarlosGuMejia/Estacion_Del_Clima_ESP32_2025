#include "mapping.h"
#include <Arduino.h>

int mapClampInt(int x, int in_min, int in_max, int out_min, int out_max) {
  long v = map(x, in_min, in_max, out_min, out_max);
  if (v < out_min) v = out_min;
  if (v > out_max) v = out_max;
  return (int)v;
}

float mapToPercentFloat(int raw, int rawMin, int rawMax, bool invert) {
  if (rawMax <= rawMin) return 0.0f;
  float p = (float)(raw - rawMin) / (float)(rawMax - rawMin) * 100.0f;
  if (invert) p = 100.0f - p;
  if (p < 0.0f) p = 0.0f;
  if (p > 100.0f) p = 100.0f;
  return p;
}