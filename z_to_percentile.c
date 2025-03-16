#include <math.h>
#define SQRT2 1.4142135623730951f

float z_to_percentile (float z)
{
    return (1 + erff(z / SQRT2)) * 50;
}
