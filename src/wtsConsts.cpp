#include <iostream>
#include <admodel.h>
#include "wtsConsts.hpp"
using namespace std;

const adstring cc = ", ";
const adstring qt = "'";
const adstring tb = "   ";

const int OFF = 0;
const int ON  = 1;
const adstring STR_OFF = "OFF";
const adstring STR_ON  = "ON";

const int INT_FALSE = 0;
const int INT_TRUE  = 1;
const adstring STR_FALSE = "FALSE";
const adstring STR_TRUE  = "TRUE";


int wts::getOnOffType(adstring s){
    s.to_upper();
    if (s==STR_OFF) return OFF;
    if (s==STR_ON ) return ON;
    cout<<"Unrecognized OnOffType '"<<s<<"'"<<endl;
    return -1;
}
adstring wts::getOnOffType(int i){
    if (i==OFF) return STR_OFF;
    if (i==ON ) return STR_ON;
    cout<<"Unrecognized OnOffType '"<<i<<"'"<<endl;
    return adstring("");
}

int wts::getBooleanType(adstring s){
    s.to_upper();
    if (s==STR_FALSE) return INT_FALSE; else
    if (s==STR_TRUE)  return INT_TRUE;  else
    cout<<"Unrecognized BooleanType '"<<s<<"'"<<endl;
    return -1;
}
adstring wts::getBooleanType(int i){
    if (i==INT_FALSE) return STR_FALSE; else
    if (i==INT_TRUE)  return STR_TRUE;  else
    cout<<"Unrecognized BooleanType '"<<i<<"'"<<endl;
    return adstring("");
}
