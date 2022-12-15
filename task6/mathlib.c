#include "mathlib.h"

float add(float firstVal, float secondVal) {
	
	return firstVal + secondVal;
}

float sub(float firstVal, float secondVal) {

    return firstVal - secondVal;
}

float mul(float firstVal, float secondVal) {

    return firstVal * secondVal;
}

float div(float firstVal, float secondVal) {

    return firstVal / secondVal;
}

float pow2(float value) {

    return value * value;
}

float pow3(float value) {
    
    return value * value * value;
}

float pow4(float value) {
    
    return pow2(value) * pow2(value);
}