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
    double none    (double x, const dvector& consts);
    double acos    (double x, const dvector& consts);
    double asin    (double x, const dvector& consts);
    double atan    (double x, const dvector& consts);
    double cos     (double x, const dvector& consts);
    double exp     (double x, const dvector& consts);
    double expneg  (double x, const dvector& consts);
    double log     (double x, const dvector& consts);
    double logneg  (double x, const dvector& consts);
    double logistic(double x, const dvector& consts);
    double logit   (double x, const dvector& consts);
    double sin     (double x, const dvector& consts);
    double sqrt    (double x, const dvector& consts);
    double square  (double x, const dvector& consts);
    double tan     (double x, const dvector& consts);

    /********************************************
    * standardized prevariable functions        *
    ********************************************/
    dvariable none    (const prevariable& x, const dvector& consts);
    dvariable acos    (const prevariable& x, const dvector& consts);
    dvariable asin    (const prevariable& x, const dvector& consts);
    dvariable atan    (const prevariable& x, const dvector& consts);
    dvariable cos     (const prevariable& x, const dvector& consts);
    dvariable exp     (const prevariable& x, const dvector& consts);
    dvariable expneg  (const prevariable& x, const dvector& consts);
    dvariable log     (const prevariable& x, const dvector& consts);
    dvariable logneg  (const prevariable& x, const dvector& consts);
    dvariable logistic(const prevariable& x, const dvector& consts);
    dvariable logit   (const prevariable& x, const dvector& consts);
    dvariable sin     (const prevariable& x, const dvector& consts);
    dvariable sqrt    (const prevariable& x, const dvector& consts);
    dvariable square  (const prevariable& x, const dvector& consts);
    dvariable tan     (const prevariable& x, const dvector& consts);

}

#endif	/* ADMBSTDFUNCTIONS_HPP */

