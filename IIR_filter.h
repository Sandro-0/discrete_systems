#pragma once
#include <stdint.h>

/* class IIR-filter
Constructors:
...(float tau,float Ts)             // 1st order LP-filter in ZOH trafo
...(float tau, float Ts, float K)   // "        "          with gain K

methods:
reset(void)         // sets internal vars to zero
eval(float u)       // make one step iteration with input u
operator: (float)   // calls "eval" 

*/
class IIR_filter
{
public:
    IIR_filter(float tau,float ts);
    IIR_filter(float,float,float);
    IIR_filter(float k, float wb, float D, float Ts);
    virtual ~IIR_filter();
    float eval(float);
    float operator()(float u){
            return eval((float)u);
         }
private:
    float a0, a1, a2, b0, k;
    float y_m1 = 0, y_m2;
};