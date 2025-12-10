#pragma once

int mapClampInt(int x, int in_min, int in_max, int out_min, int out_max);
float mapToPercentFloat(int raw, int rawMin, int rawMax, bool invert=false);