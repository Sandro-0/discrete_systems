#include "IIR_filter.h"

// constructors
IIR_filter::IIR_filter(float tau,float Ts)
{
    this->a1 = 0;
    this->a2 = 1;
    this->a0 = -tau/(tau+Ts);
    this->b0 = Ts/(tau+Ts);
    this->y_m1 = 0;
    this->y_m2 = 0;
}
IIR_filter::IIR_filter(float tau,float Ts,float K)
{
    this->a1 = 0;
    this->a2 = 1;
    this->a0 = -tau/(tau+Ts);
    this->b0 = Ts/(tau+Ts);
    this->y_m1 = 0;
    this->y_m2 = 0;
    this->k = K;
}

IIR_filter::IIR_filter(float k, float wb, float D, float Ts) {
    this->b0 = wb*wb*Ts*Ts*k;
    this->a0 = 1.0f+wb*wb*Ts*Ts-2*D*wb*Ts;
    this->a1 = 2.0f*D*wb*Ts-2;
    this->a2 = 1;
    this->y_m1 = 0;
    this->y_m2 = 0;
}


// Methods:

float IIR_filter::eval(float u)
{
    float temp = y_m1;
    this->y_m1 = this->b0*u - this->a0*y_m2 - this->a1*y_m1;
    this->y_m2 = temp;
    return this->y_m1;       // this has to be modified!!!
}


// Deconstructor
IIR_filter::~IIR_filter() {} 