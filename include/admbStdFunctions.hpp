/* 
 * File:   admbStdFunctions.hpp
 * Author: WilliamStockhausen
 *
 * Created on November 27, 2013, 7:08 AM
 */

#ifndef ADMBSTDFUNCTIONS_HPP
#define	ADMBSTDFUNCTIONS_HPP

class dvariable;
class dvector;
class prevariable;

namespace wts {
    /********************************************
    * standardized double functions             *
    ********************************************/
    double none    (double x, _CONST dvector& consts);
    double acos    (double x, _CONST dvector& consts);
    double asin    (double x, _CONST dvector& consts);
    double atan    (double x, _CONST dvector& consts);
    double cos     (double x, _CONST dvector& consts);
    double exp     (double x, _CONST dvector& consts);
    double expneg  (double x, _CONST dvector& consts);
    double log     (double x, _CONST dvector& consts);
    double logneg  (double x, _CONST dvector& consts);
    double logistic(double x, _CONST dvector& consts);
    double logit   (double x, _CONST dvector& consts);
    double sin     (double x, _CONST dvector& consts);
    double sqrt    (double x, _CONST dvector& consts);
    double square  (double x, _CONST dvector& consts);
    double tan     (double x, _CONST dvector& consts);

    /********************************************
    * standardized prevariable functions        *
    ********************************************/
    dvariable none    (_CONST prevariable& x, _CONST dvector& consts);
    dvariable acos    (_CONST prevariable& x, _CONST dvector& consts);
    dvariable asin    (_CONST prevariable& x, _CONST dvector& consts);
    dvariable atan    (_CONST prevariable& x, _CONST dvector& consts);
    dvariable cos     (_CONST prevariable& x, _CONST dvector& consts);
    dvariable exp     (_CONST prevariable& x, _CONST dvector& consts);
    dvariable expneg  (_CONST prevariable& x, _CONST dvector& consts);
    dvariable log     (_CONST prevariable& x, _CONST dvector& consts);
    dvariable logneg  (_CONST prevariable& x, _CONST dvector& consts);
    dvariable logistic(_CONST prevariable& x, _CONST dvector& consts);
    dvariable logit   (_CONST prevariable& x, _CONST dvector& consts);
    dvariable sin     (_CONST prevariable& x, _CONST dvector& consts);
    dvariable sqrt    (_CONST prevariable& x, _CONST dvector& consts);
    dvariable square  (_CONST prevariable& x, _CONST dvector& consts);
    dvariable tan     (_CONST prevariable& x, _CONST dvector& consts);

}

#endif	/* ADMBSTDFUNCTIONS_HPP */

