/* 
 * File:   wtsConsts.hpp
 * Author: WilliamStockhausen
 *
 * Created on November 26, 2013, 9:53 AM
 */

#ifndef WTSCONSTS_HPP
#define	WTSCONSTS_HPP


    extern const adstring cc;//comma
    extern const adstring qt;//quote
    extern const adstring tb;//2 spaces

    extern const int OFF;
    extern const int ON;
    extern const adstring STR_OFF;
    extern const adstring STR_ON;
        
    extern const int INT_FALSE;
    extern const int INT_TRUE;
    extern const adstring STR_FALSE;
    extern const adstring STR_TRUE;
    
namespace wts{    
    int getOnOffType(adstring s);
    adstring getOnOffType(int i);
        
    int getBooleanType(adstring s);
    adstring getBooleanType(int i);
}    

#endif	/* WTSCONSTS_HPP */

