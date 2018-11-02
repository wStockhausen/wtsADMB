//admbFunctions.cpp
#include <iostream>
#include <limits>
#include <admodel.h>
#include "wtsConsts.hpp"
#include "admbBasicFunctions.hpp"
using namespace std;

int debugADMBFunctions= 0;
    
/**
 * Convert a vector of values to and ivector of indices corresponding to 
 * the bins defined by a vector of equally-spaced cut points.
 *  
 * @param values - vector of values to bin
 * @param cutPts - vector of equally-spaced cut points to use for binning
 * @param accumLo - flag (0/1) to assign values less than the min cut point to the lowest bin
 * @param accumHi - flag (0/1) to assign values higher the the max cut point to highest bin
 * 
 * @return - ivector of indices with the bin assigned to each value
 * 
 * @details Values smaller than the lowest cutpoint will be assigned to 0 if accumLo is false (=0) 
 * or to 1 (the lowest bin) if accumLo is true (>0). Values larger than the highest cutpoint will 
 * be assigned to nBins+1 if accumHi is false (=0), or to nBins (the largest bin) if accumHi is true (>0), 
 * where nBins is the number of bins defined by the cutpoints. 
 * 
 */
ivector wts::assignBinIndices(const dvector& values, const dvector& cutPts, int accumLo, int accumHi){  
    int nBins = cutPts.size()-1;
    double binSize = cutPts(2)-cutPts(1);//bin size assumed equal for all bins
    dvector dv = (values-cutPts(1))/binSize;
    ivector iv = wts::to_ivector(dv)+1;
    if (accumLo) {accumLo = 1;}     else {accumLo = 0;}
    if (accumHi) {accumHi = nBins;} else {accumHi = nBins+1;}
    for (int i=iv.indexmin();i<=iv.indexmax();i++){
        if (iv(i)<1)     {iv(i) = accumLo;} else
        if (iv(i)>nBins) {iv(i) = accumHi;} 
    }
    return iv;
}

/**
 * Extracts all values falling between min and max from an ivector
 * @param min
 * @param max
 * @param v
 * @return - ivector
 */
ivector wts::extractVector(int min, int max, ivector v){
    int n = 0;
    for (int i=v.indexmin();i<=v.indexmax();i++){
        if ((min<=v(i))&&(v(i)<=max)) n++;
    }
    ivector r(1,n);
    n = 0;
    for (int i=v.indexmin();i<=v.indexmax();i++){
        if ((min<=v(i))&&(v(i)<=max)) r(++n) = v(i);
    }
    return(r);
}

/**
 * Extracts all values falling between min and max from a dvector
 * @param min
 * @param max
 * @param v
 * @return - dvector
 */
dvector wts::extractVector(double min, double max, dvector v){
    int n = 0;
    for (int i=v.indexmin();i<=v.indexmax();i++){
        if ((min<=v(i))&&(v(i)<=max)) n++;
    }
    dvector r(1,n);
    n = 0;
    for (int i=v.indexmin();i<=v.indexmax();i++){
        if ((min<=v(i))&&(v(i)<=max)) r(++n) = v(i);
    }
    return(r);
}

/**
 * Compares a dvector to a value and returns an ivector with 1's (0's) where the 
 * x(i) > v is true (false).
 * 
 * @param x - the dvector of values to check
 * @param v - the value to compare to
 * 
 * @return an ivector with 1's where x(i) > v is true, 0's where false
 */
ivector wts::gt(const dvector& x, double v){
    ivector r(x.indexmin(),x.indexmax());
    for (int i=x.indexmin();i<=x.indexmax();i++) if (x(i)>v) r(i) = 1; else r(i) = 0;
    return r;
}

/**
 * Returns one of two results based on a logical test.
 * 
 * @param test - logical test
 * @param x - returned if test is true
 * @param y - returned if test is false
 * 
 * @return 
 */
int wts::ifelse(bool test, int x, int y){
    int r=0;
    if (test) r=x; else r=y;
    return r;
}
/**
 * Returns one of two results based on a logical test.
 * 
 * @param test - logical test
 * @param x - returned if test is true
 * @param y - returned if test is false
 * 
 * @return 
 */
double wts::ifelse(bool test, double x, double y){
    double r=0.0;
    if (test) r=x; else r=y;
    return r;
}
/**
 * Returns an ivector representing the results of x[i] == y for
 * each element of x.
 * 
 * @param x - dvector to test
 * @param y - double
 * @return - ivector with same indices as x 
 */
ivector wts::isEQ(const dvector & x, double y){
    ivector r(x.indexmin(),x.indexmax());
    for (int i=x.indexmin();i<=x.indexmax();i++) r(i) = (x(i)==y);
    return r;
}
    
    /**
     * Returns an ivector representing the indices of x
     * where x[i] == y is true.
     * 
     * @param x - dvector to test
     * @param y - double
     * @return - ivector with indices of x where x[i] == y
     */
ivector wts::whichIsEQ(const dvector & x, double y){
    ivector r = wts::isEQ(x,y);
    int sr = sum(r);
    ivector ii;
    if (sr){
        ii.allocate(1,sum(r));
        int ctr = 0;
        for (int i=x.indexmin();i<=x.indexmax();i++) {
            if (r(i)) ii(++ctr)=i;
        }
    }
    return ii;
}
    
/**
 * Returns an ivector representing the results of x[i] != y for
 * each element of x.
 * 
 * @param x - dvector to test
 * @param y - double
 * @return - ivector with same indices as x 
 */
ivector wts::isNE(const dvector & x, double y){
    ivector r(x.indexmin(),x.indexmax());
    for (int i=x.indexmin();i<=x.indexmax();i++) r(i) = (x(i)!=y);
    return r;
}
    
/**
 * Returns an ivector representing the indices of x
 * where x[i] != y is true.
 * 
 * @param x - dvector to test
 * @param y - double
 * @return - ivector with indices of x where x[i] != y
 */
ivector wts::whichIsNE(const dvector & x, double y){
    ivector r = wts::isNE(x,y);
    int sr = sum(r);
    ivector ii;
    if (sr){
        ii.allocate(1,sum(r));
        int ctr = 0;
        for (int i=x.indexmin();i<=x.indexmax();i++) {
            if (r(i)) ii(++ctr)=i;
        }
    }
    return ii;
}

/**
 * Returns an ivector representing the results of x[i] < y for
 * each element of x.
 * 
 * @param x - dvector to test
 * @param y - double
 * @return - ivector with same indices as x 
 */
ivector wts::isLT(const dvector & x, double y){
    ivector r(x.indexmin(),x.indexmax());
    for (int i=x.indexmin();i<=x.indexmax();i++) r(i) = (x(i)<y);
    return r;
}

/**
 * Returns an ivector representing the results of x[i] <= y for
 * each element of x.
 * 
 * @param x - dvector to test
 * @param y - double
 * @return - ivector with same indices as x 
 */
ivector wts::isLE(const dvector & x, double y){
    ivector r(x.indexmin(),x.indexmax());
    for (int i=x.indexmin();i<=x.indexmax();i++) r(i) = (x(i)<=y);
    return r;
}

/**
 * Returns an ivector representing the results of x[i] > y for
 * each element of x.
 * 
 * @param x - dvector to test
 * @param y - double
 * @return - ivector with same indices as x 
 */
ivector wts::isGT(const dvector & x, double y){
    ivector r(x.indexmin(),x.indexmax());
    for (int i=x.indexmin();i<=x.indexmax();i++) r(i) = (x(i)>y);
    return r;
}

/**
 * Returns an ivector representing the results of x[i] >= y for
 * each element of x.
 * 
 * @param x - dvector to test
 * @param y - double
 * @return - ivector with same indices as x 
 */
ivector wts::isGE(const dvector & x, double y){
    ivector r(x.indexmin(),x.indexmax());
    for (int i=x.indexmin();i<=x.indexmax();i++) r(i) = (x(i)>=y);
    return r;
}

/**
 * Returns the max of two (double) numbers.
 * 
 * @param x1
 * @param x2
 * 
 * @return - the max of x1, x2
 */
double wts::max(double x1,double x2){
    if (x1<x2) return x2;
    return x1;
}
    
/**
 * Returns the maximum of the array
 * 
 * @param a - d3_array
 * 
 * @return - the maximum value in the array
 */
double wts::max(d3_array& a){
    double m = -std::numeric_limits<double>::infinity();
    for (int i=a.indexmin();i<=a.indexmax();i++){
        m = wts::max(m,max(a(i)));//admb max function for dmatrix
    }
    return m;
}

/**
 * Returns the maximum of the array
 * 
 * @param a - d4_array
 * 
 * @return - the maximum value in the array
 */
double wts::max(d4_array& a){
    double m = -std::numeric_limits<double>::infinity();
    for (int i=a.indexmin();i<=a.indexmax();i++){
        m = wts::max(m,wts::max(a(i)));
    }
    return m;
}

/**
 * Returns the maximum of the array
 * 
 * @param a - d5_array
 * 
 * @return - the maximum value in the array
 */
double wts::max(d5_array& a){
    double m = -std::numeric_limits<double>::infinity();
    for (int i=a.indexmin();i<=a.indexmax();i++){
        m = wts::max(m,wts::max(a(i)));
    }
    return m;
}

/**
 * Returns the maximum of the array
 * 
 * @param a - d6_array
 * 
 * @return - the maximum value in the array
 */
double wts::max(d6_array& a){
    double m = -std::numeric_limits<double>::infinity();
    for (int i=a.indexmin();i<=a.indexmax();i++){
        m = wts::max(m,wts::max(a(i)));
    }
    return m;
}

/**
 * Returns the maximum of the array
 * 
 * @param a - d7_array
 * 
 * @return - the maximum value in the array
 */
double wts::max(d7_array& a){
    double m = -std::numeric_limits<double>::infinity();
    for (int i=a.indexmin();i<=a.indexmax();i++){
        m = wts::max(m,wts::max(a(i)));
    }
    return m;
}

/**
 * Returns the min of two (double) numbers.
 * 
 * @param x1
 * @param x2
 * 
 * @return - the min of x1, x2
 */
double wts::min(double x1,double x2){
    if (x1<x2) return x1;
    return x2;
}
    
/**
 * Returns the minimum of the array
 * 
 * @param a - d3_array
 * 
 * @return - the minimum value in the array
 */
double wts::min(d3_array& a){
    double m = -std::numeric_limits<double>::infinity();
    for (int i=a.indexmin();i<=a.indexmax();i++){
        m = wts::min(m,min(a(i)));//admb min function for dmatrix
    }
    return m;
}

/**
 * Returns the minimum of the array
 * 
 * @param a - d4_array
 * 
 * @return - the minimum value in the array
 */
double wts::min(d4_array& a){
    double m = -std::numeric_limits<double>::infinity();
    for (int i=a.indexmin();i<=a.indexmax();i++){
        m = wts::min(m,wts::min(a(i)));
    }
    return m;
}

/**
 * Returns the minimum of the array
 * 
 * @param a - d5_array
 * 
 * @return - the minimum value in the array
 */
double wts::min(d5_array& a){
    double m = -std::numeric_limits<double>::infinity();
    for (int i=a.indexmin();i<=a.indexmax();i++){
        m = wts::min(m,wts::min(a(i)));
    }
    return m;
}

/**
 * Returns the minimum of the array
 * 
 * @param a - d6_array
 * 
 * @return - the minimum value in the array
 */
double wts::min(d6_array& a){
    double m = -std::numeric_limits<double>::infinity();
    for (int i=a.indexmin();i<=a.indexmax();i++){
        m = wts::min(m,wts::min(a(i)));
    }
    return m;
}

/**
 * Returns the minimum of the array
 * 
 * @param a - d7_array
 * 
 * @return - the minimum value in the array
 */
double wts::min(d7_array& a){
    double m = -std::numeric_limits<double>::infinity();
    for (int i=a.indexmin();i<=a.indexmax();i++){
        m = wts::min(m,wts::min(a(i)));
    }
    return m;
}

/**
 * Returns the max of two (dvariable) numbers.
 * 
 * @param x1
 * @param x2
 * 
 * @return - the max of x1, x2
 */
dvariable wts::max(dvariable x1, dvariable x2){
    if (x1<x2) return x2;
    return x1;
}
    
/**
 * Returns the maximum of the vector
 * 
 * @param a - dvar_vector
 * 
 * @return - the maximum value in the array
 */
dvariable wts::max(dvar_vector& a){
    RETURN_ARRAYS_INCREMENT();
    dvariable m = -std::numeric_limits<dvariable>::infinity();
    for (int i=a.indexmin();i<=a.indexmax();i++){
        m = wts::max(m,a(i));
    }
    RETURN_ARRAYS_DECREMENT();
    return m;
}

/**
 * Returns the maximum of the array
 * 
 * @param a - dvar_matrix
 * 
 * @return - the maximum value in the array
 */
dvariable wts::max(dvar_matrix& a){
    RETURN_ARRAYS_INCREMENT();
    dvariable m = -std::numeric_limits<dvariable>::infinity();
    for (int i=a.indexmin();i<=a.indexmax();i++){
        m = wts::max(m,max(a(i)));
    }
    RETURN_ARRAYS_DECREMENT();
    return m;
}

/**
 * Returns the maximum of the array
 * 
 * @param a - dvar3_array
 * 
 * @return - the maximum value in the array
 */
dvariable wts::max(dvar3_array& a){
    RETURN_ARRAYS_INCREMENT();
    dvariable m = -std::numeric_limits<dvariable>::infinity();
    for (int i=a.indexmin();i<=a.indexmax();i++){
        m = wts::max(m,max(a(i)));//admb max function for dmatrix
    }
    RETURN_ARRAYS_DECREMENT();
    return m;
}

/**
 * Returns the maximum of the array
 * 
 * @param a - dvar4_array
 * 
 * @return - the maximum value in the array
 */
dvariable wts::max(dvar4_array& a){
    RETURN_ARRAYS_INCREMENT();
    dvariable m = -std::numeric_limits<dvariable>::infinity();
    for (int i=a.indexmin();i<=a.indexmax();i++){
        m = wts::max(m,wts::max(a(i)));
    }
    RETURN_ARRAYS_DECREMENT();
    return m;
}

/**
 * Returns the maximum of the array
 * 
 * @param a - dvar5_array
 * 
 * @return - the maximum value in the array
 */
dvariable wts::max(dvar5_array& a){
    RETURN_ARRAYS_INCREMENT();
    dvariable m = -std::numeric_limits<dvariable>::infinity();
    for (int i=a.indexmin();i<=a.indexmax();i++){
        m = wts::max(m,wts::max(a(i)));
    }
    RETURN_ARRAYS_DECREMENT();
    return m;
}

/**
 * Returns the maximum of the array
 * 
 * @param a - dvar6_array
 * 
 * @return - the maximum value in the array
 */
dvariable wts::max(dvar6_array& a){
    RETURN_ARRAYS_INCREMENT();
    dvariable m = -std::numeric_limits<dvariable>::infinity();
    for (int i=a.indexmin();i<=a.indexmax();i++){
        m = wts::max(m,wts::max(a(i)));
    }
    RETURN_ARRAYS_DECREMENT();
    return m;
}

/**
 * Returns the maximum of the array
 * 
 * @param a - dvar7_array
 * 
 * @return - the maximum value in the array
 */
dvariable wts::max(dvar7_array& a){
    RETURN_ARRAYS_INCREMENT();
    dvariable m = -std::numeric_limits<dvariable>::infinity();
    for (int i=a.indexmin();i<=a.indexmax();i++){
        m = wts::max(m,wts::max(a(i)));
    }
    RETURN_ARRAYS_DECREMENT();
    return m;
}

/**
 * Returns the min of two (dvariable) numbers.
 * 
 * @param x1
 * @param x2
 * 
 * @return - the min of x1, x2
 */
dvariable wts::min(dvariable x1,dvariable x2){
    if (x1<x2) return x1;
    return x2;
}
    
/**
 * Returns the minimum of the vector
 * 
 * @param a - dvar_vector
 * 
 * @return - the minimum value in the array
 */
dvariable wts::min(dvar_vector& a){
    RETURN_ARRAYS_INCREMENT();
    dvariable m = -std::numeric_limits<dvariable>::infinity();
    for (int i=a.indexmin();i<=a.indexmax();i++){
        m = wts::min(m,a(i));
    }
    RETURN_ARRAYS_DECREMENT();
    return m;
}

/**
 * Returns the minimum of the array
 * 
 * @param a - dvar_matrix
 * 
 * @return - the minimum value in the array
 */
dvariable wts::min(dvar_matrix& a){
    RETURN_ARRAYS_INCREMENT();
    dvariable m = -std::numeric_limits<dvariable>::infinity();
    for (int i=a.indexmin();i<=a.indexmax();i++){
        m = wts::min(m,min(a(i)));
    }
    RETURN_ARRAYS_DECREMENT();
    return m;
}

/**
 * Returns the minimum of the array
 * 
 * @param a - dvar3_array
 * 
 * @return - the minimum value in the array
 */
dvariable wts::min(dvar3_array& a){
    RETURN_ARRAYS_INCREMENT();
    dvariable m = -std::numeric_limits<dvariable>::infinity();
    for (int i=a.indexmin();i<=a.indexmax();i++){
        m = wts::min(m,min(a(i)));//admb min function for dmatrix
    }
    RETURN_ARRAYS_DECREMENT();
    return m;
}

/**
 * Returns the minimum of the array
 * 
 * @param a - dvar4_array
 * 
 * @return - the minimum value in the array
 */
dvariable wts::min(dvar4_array& a){
    RETURN_ARRAYS_INCREMENT();
    dvariable m = -std::numeric_limits<dvariable>::infinity();
    for (int i=a.indexmin();i<=a.indexmax();i++){
        m = wts::min(m,wts::min(a(i)));
    }
    RETURN_ARRAYS_DECREMENT();
    return m;
}

/**
 * Returns the minimum of the array
 * 
 * @param a - dvar5_array
 * 
 * @return - the minimum value in the array
 */
dvariable wts::min(dvar5_array& a){
    RETURN_ARRAYS_INCREMENT();
    dvariable m = -std::numeric_limits<dvariable>::infinity();
    for (int i=a.indexmin();i<=a.indexmax();i++){
        m = wts::min(m,wts::min(a(i)));
    }
    RETURN_ARRAYS_DECREMENT();
    return m;
}

/**
 * Returns the minimum of the array
 * 
 * @param a - dvar6_array
 * 
 * @return - the minimum value in the array
 */
dvariable wts::min(dvar6_array& a){
    RETURN_ARRAYS_INCREMENT();
    dvariable m = -std::numeric_limits<dvariable>::infinity();
    for (int i=a.indexmin();i<=a.indexmax();i++){
        m = wts::min(m,wts::min(a(i)));
    }
    RETURN_ARRAYS_DECREMENT();
    return m;
}

/**
 * Returns the minimum of the array
 * 
 * @param a - dvar7_array
 * 
 * @return - the minimum value in the array
 */
dvariable wts::min(dvar7_array& a){
    RETURN_ARRAYS_INCREMENT();
    dvariable m = -std::numeric_limits<dvariable>::infinity();
    for (int i=a.indexmin();i<=a.indexmax();i++){
        m = wts::min(m,wts::min(a(i)));
    }
    RETURN_ARRAYS_DECREMENT();
    return m;
}

/**
 * Converts a dvector (doubles) to an ivector (integers).
 * 
 * @param v - the dvector to convert
 * 
 * @return - the corresponding ivector
 */
ivector wts::to_ivector(const dvector& v){
    ivector iv(v.indexmin(),v.indexmax());
    for (int i=v.indexmin();i<=v.indexmax();i++) iv(i) = floor(v(i));
    return iv;
}
/****************************************************************
* name      : copy                                              *
* purpose   : create a deep copy of a variable                  *
*NOTE: Does not work for ragged arrays                          *
****************************************************************/
dvector wts::copy(const dvector& v){
    ivector bnds = getBounds(v);
    dvector c(bnds(1),bnds(2));
    c = v;
    return c;
}
//-------------------------------------------------------------
dmatrix wts::copy(const dmatrix& v){
    ivector bnds = getBounds(v);
    dmatrix c(bnds(1),bnds(2),bnds(3),bnds(4));
    c = v;
    return c;
}
//-------------------------------------------------------------
d3_array wts::copy(const d3_array& v){
    ivector bnds = getBounds(v);
    d3_array c(bnds(1),bnds(2),bnds(3),bnds(4),bnds(5),bnds(6));
    c = v;
    return c;
}
//-------------------------------------------------------------
d4_array wts::copy(const d4_array& v){
    ivector bnds = getBounds(v);
    d4_array c(bnds(1),bnds(2),bnds(3),bnds(4),bnds(5),bnds(6),bnds(7),bnds(8));
    c = v;
    return c;
}
//-------------------------------------------------------------
d5_array wts::copy(const d5_array& v){
    ivector bnds = getBounds(v);
    d5_array c(bnds(1),bnds(2),bnds(3),bnds(4),bnds(5),bnds(6),bnds(7),bnds(8),bnds(9),bnds(10));
    c = v;
    return c;
}
//-------------------------------------------------------------
d6_array wts::copy(const d6_array& v){
    ivector bnds = getBounds(v);
    d6_array c(bnds(1),bnds(2),bnds(3),bnds(4),bnds(5),bnds(6),bnds(7),bnds(8),bnds(9),bnds(10),bnds(11),bnds(12));
    c = v;
    return c;
}
//-------------------------------------------------------------
d7_array wts::copy(const d7_array& v){
    ivector bnds = getBounds(v);
    d7_array c(bnds(1),bnds(2),bnds(3),bnds(4),bnds(5),bnds(6),bnds(7),bnds(8),bnds(9),bnds(10),bnds(11),bnds(12),bnds(13),bnds(14));
    c = v;
    return c;
}
//-------------------------------------------------------------
dvar_vector wts::copy(const dvar_vector& v){
    RETURN_ARRAYS_INCREMENT();
    ivector bnds = getBounds(v);
    dvar_vector c(bnds(1),bnds(2));
    c = v;
    RETURN_ARRAYS_DECREMENT();
    return c;
}
//-------------------------------------------------------------
dvar_matrix wts::copy(const dvar_matrix& v){
    RETURN_ARRAYS_INCREMENT();
    ivector bnds = getBounds(v);
    dvar_matrix c(bnds(1),bnds(2),bnds(3),bnds(4));
    c = v;
    RETURN_ARRAYS_DECREMENT();
    return c;
}
//-------------------------------------------------------------
dvar3_array wts::copy(const dvar3_array& v){
    RETURN_ARRAYS_INCREMENT();
    ivector bnds = getBounds(v);
    dvar3_array c(bnds(1),bnds(2),bnds(3),bnds(4),bnds(5),bnds(6));
    c = v;
    RETURN_ARRAYS_DECREMENT();
    return c;
}
//-------------------------------------------------------------
dvar4_array wts::copy(const dvar4_array& v){
    RETURN_ARRAYS_INCREMENT();
    ivector bnds = getBounds(v);
    dvar4_array c(bnds(1),bnds(2),bnds(3),bnds(4),bnds(5),bnds(6),bnds(7),bnds(8));
    c = v;
    RETURN_ARRAYS_DECREMENT();
    return c;
}
//-------------------------------------------------------------
dvar5_array wts::copy(const dvar5_array& v){
    RETURN_ARRAYS_INCREMENT();
    ivector bnds = getBounds(v);
    dvar5_array c(bnds(1),bnds(2),bnds(3),bnds(4),bnds(5),bnds(6),bnds(7),bnds(8),bnds(9),bnds(10));
    c = v;
    RETURN_ARRAYS_DECREMENT();
    return c;
}
//-------------------------------------------------------------
dvar6_array wts::copy(const dvar6_array& v){
    RETURN_ARRAYS_INCREMENT();
    ivector bnds = getBounds(v);
    dvar6_array c(bnds(1),bnds(2),bnds(3),bnds(4),bnds(5),bnds(6),bnds(7),bnds(8),bnds(9),bnds(10),bnds(11),bnds(12));
    c = v;
    RETURN_ARRAYS_DECREMENT();
    return c;
}
//-------------------------------------------------------------
dvar7_array wts::copy(const dvar7_array& v){
    RETURN_ARRAYS_INCREMENT();
    ivector bnds = getBounds(v);
    dvar7_array c(bnds(1),bnds(2),bnds(3),bnds(4),bnds(5),bnds(6),bnds(7),bnds(8),bnds(9),bnds(10),bnds(11),bnds(12),bnds(13),bnds(14));
    c = v;
    RETURN_ARRAYS_DECREMENT();
    return c;
}

/****************************************************************
* name      : IdentityMatrix                                    *
* purpose   : returns an identity dmatrix with row/col          *
*               indices running from mn to mx.                  *
****************************************************************/
dmatrix wts::IdentityMatrix(int mn,int mx){
    dmatrix m(mn,mx); m.initialize(); 
    for (int i=mn;i<=mx;i++) m(i,i)=1.0; 
    return m;
}

/****************************************************************
* name      : testEquals                                        *
* purpose   : test equality                                     *
****************************************************************/
int wts::testEquals(const ivector& i1, const ivector& i2){
    int mn = i1.indexmin();
    if (mn!=i2.indexmin()) return 0;
    int mx = i1.indexmax();
    if (mx!=i2.indexmax()) return 0;
    int rs = mn;
    while ((rs)&&(rs<=mn)) {
        if (i1(rs)==i2(rs)) rs++; else return 0;
    }
    return 1;
}

/*************************************************
* name      : getBounds                          *
* purpose   : return min, max indices for array  *
*************************************************/
ivector wts::getBounds(const prevariable& o){
    ivector b(1,1);
    b(1) = 0;
    return(b);
}
/*************************************************
* name      : getBounds                          *
* purpose   : return min, max indices for array  *
*************************************************/
ivector wts::getBounds(const ivector& o){
    ivector b(1,2);
    b(1) = o.indexmin();
    b(2) = o.indexmax();
    return(b);
}
//-------------------------------------------------------------
ivector wts::getBounds(const imatrix& o){
    ivector b(1,4);
    b(1) = o.indexmin();
    b(2) = o.indexmax();
    --(--b(3,4)) = getBounds(o(b(1)));
    return(b);
}
//-------------------------------------------------------------
ivector wts::getBounds(const dvector& o){
    ivector b(1,2);
    b(1) = o.indexmin();
    b(2) = o.indexmax();
    return(b);
}
//-------------------------------------------------------------
ivector wts::getBounds(const dmatrix& o){
    ivector b(1,4);
    b(1) = o.indexmin();
    b(2) = o.indexmax();
    --(--b(3,4)) = getBounds(o(b(1)));
    return(b);
}
//-------------------------------------------------------------
ivector wts::getBounds(const d3_array& o){
    ivector b(1,6);
    b(1) = o.indexmin();
    b(2) = o.indexmax();
    --(--b(3,6)) = getBounds(o(b(1)));
    return(b);
}
//-------------------------------------------------------------
ivector wts::getBounds(const d4_array& o){
    ivector b(1,8);
    b(1) = o.indexmin();
    b(2) = o.indexmax();
    --(--b(3,8)) = getBounds(o(b(1)));
    return(b);
}
//-------------------------------------------------------------
ivector wts::getBounds(const d5_array& o){
    ivector b(1,10);
    b(1) = o.indexmin();
    b(2) = o.indexmax();
    --(--b(3,10)) = getBounds(o(b(1)));
    return(b);
}
//-------------------------------------------------------------
ivector wts::getBounds(const d6_array& o){
    ivector b(1,12);
    b(1) = o.indexmin();
    b(2) = o.indexmax();
    --(--b(3,12)) = getBounds(o(b(1)));
    return(b);
}
//-------------------------------------------------------------
ivector wts::getBounds(const d7_array& o){
    ivector b(1,14);
    b(1) = o.indexmin();
    b(2) = o.indexmax();
    --(--b(3,14)) = getBounds(o(b(1)));
    return(b);
}
//-------------------------------------------------------------
ivector wts::getBounds(const dvar_vector& o){
    if (debugADMBFunctions>0) cout<<"start getBounds(dvar_vector)"<<endl;
    ivector b(1,2);
    b(1) = o.indexmin();
    b(2) = o.indexmax();
    if (debugADMBFunctions>0) cout<<b<<endl;
    if (debugADMBFunctions>0) cout<<"end getBounds(dvar_vector)"<<endl;
    return(b);
}
//-------------------------------------------------------------
ivector wts::getBounds(const dvar_matrix& o){
    if (debugADMBFunctions>0) cout<<"start getBounds(dvar_matrix)"<<endl;
    ivector b(1,4);
    b(1) = o.indexmin();
    b(2) = o.indexmax();
    --(--b(3,4)) = getBounds(o(b(1)));
    if (debugADMBFunctions>0) cout<<b<<endl;
    if (debugADMBFunctions>0) cout<<"end getBounds(dvar_matrix)"<<endl;
    return(b);
}
//-------------------------------------------------------------
ivector wts::getBounds(const dvar3_array& o){
    if (debugADMBFunctions>0) cout<<"start getBounds(dvar3_array)"<<endl;
    ivector b(1,6);
    b(1) = o.indexmin();
    b(2) = o.indexmax();
    --(--b(3,6)) = getBounds(o(b(1)));
    if (debugADMBFunctions>0) cout<<b<<endl;
    if (debugADMBFunctions>0) cout<<"end getBounds(dvar3_array)"<<endl;
    return(b);
}
//-------------------------------------------------------------
ivector wts::getBounds(const dvar4_array& o){
    ivector b(1,8);
    b(1) = o.indexmin();
    b(2) = o.indexmax();
    --(--b(3,8)) = getBounds(o(b(1)));
    return(b);
}
//-------------------------------------------------------------
ivector wts::getBounds(const dvar5_array& o){
    ivector b(1,10);
    b(1) = o.indexmin();
    b(2) = o.indexmax();
    --(--b(3,10)) = getBounds(o(b(1)));
    return(b);
}
//-------------------------------------------------------------
ivector wts::getBounds(const dvar6_array& o){
    ivector b(1,12);
    b(1) = o.indexmin();
    b(2) = o.indexmax();
    --(--b(3,12)) = getBounds(o(b(1)));
    return(b);
}
//-------------------------------------------------------------
ivector wts::getBounds(const dvar7_array& o){
    ivector b(1,14);
    b(1) = o.indexmin();
    b(2) = o.indexmax();
    --(--b(3,14)) = getBounds(o(b(1)));
    return(b);
}

/**
 * Create, dimension and initialize a dmatrix using
 * an ivector.
 * 
 * @param dims - the dimensions (alternating low/high)
 * @return - the dimensioned array
 */
dmatrix wts::dimDmatrix(ivector& dims){
    dmatrix a(dims[1],dims[2],dims[3],dims[4]);
    return(a);
}

/**
 * Create, dimension and initialize a d3_array using
 * an ivector.
 * 
 * @param dims - the dimensions (alternating low/high)
 * @return - the dimensioned array
 */
d3_array wts::dimD3array(ivector& dims){
    d3_array a(dims[1],dims[2],dims[3],dims[4],dims[5],dims[6]);
    return(a);
}

/**
 * Create, dimension and initialize a d4_array using
 * an ivector.
 * 
 * @param dims - the dimensions (alternating low/high)
 * @return - the dimensioned array
 */
d4_array wts::dimD4array(ivector& dims){
    d4_array a(dims[1],dims[2],dims[3],dims[4],
               dims[5],dims[6],dims[7],dims[8]);
    return(a);
}

/**
 * Create, dimension and initialize a d5_array using
 * an ivector.
 * 
 * @param dims - the dimensions (alternating low/high)
 * @return - the dimensioned array
 */
d5_array wts::dimD5array(ivector& dims){
    d5_array a(dims[1],dims[2],dims[3],dims[4],dims[5],dims[6],
               dims[7],dims[8],dims[9],dims[10]);
    return(a);
}

/**
 * Create, dimension and initialize a d6_array using
 * an ivector.
 * 
 * @param dims - the dimensions (alternating low/high)
 * @return - the dimensioned array
 */
d6_array wts::dimD6array(ivector& dims){
    d6_array a(dims[1],dims[2],dims[3],dims[4],dims[5],dims[6],
               dims[7],dims[8],dims[9],dims[10],dims[11],dims[12]);
    return(a);
}

/**
 * Create and dimension a d7_array using an ivector.
 * 
 * @param dims - the dimensions (alternating low/high)
 * @return - the dimensioned array
 */
d7_array wts::dimD7array(ivector& dims){
    d7_array a(dims[1],dims[2],dims[3],dims[4],dims[5],dims[6],dims[7],dims[8],
               dims[9],dims[10],dims[11],dims[12],dims[13],dims[14]);
    return(a);
}

/**
 * Permute dimensions of a dmatrix--really just a transpose.
 * 
 * @param perm - ivector indicating permutation
 * @param n_ij -dmatrix to permute
 * 
 * @return dmatrix with permuted dimensions
 */
dmatrix wts::permuteDims(ivector& i2p, dmatrix& n_i){
    return trans(n_i);
}

/**
 * Permute dimensions of a d3_array.
 * 
 * @param perm - ivector indicating permutation
 * @param n_ijk -d3_array to permute
 * 
 * @return d3_array with permuted dimensions
 */
d3_array wts::permuteDims(ivector& i2p, d3_array& n_i){
    int mxi = 3;
//    cout<<"starting permuteDims(d3_array&)"<<endl;
    if ((i2p.indexmax()-i2p.indexmin()+1)!=mxi){
        cout<<"Error in d"<<mxi<<"_array permuteDims()"<<endl;
        cout<<"i2p must have length "<<mxi<<"."<<endl;
        cout<<"i2p = "<<i2p<<endl;
        cout<<"Aborting..."<<endl;
        exit(-1);
    }
    ivector bnds = getBounds(n_i);
    ivector pbnds(1,2*mxi);
    for (int i=1;i<=mxi;i++) {
        pbnds(2*i2p(i)-1) = bnds(2*i-1);
        pbnds(2*i2p(i))   = bnds(2*i);
    }
    d3_array n_p = dimD3array(pbnds); 
    n_p.initialize();
    
    ivector i(1,mxi);//index vector for original array
    ivector p(1,mxi);//permuted index vector {p[i2p[j]] = i[j]}
    
    int j;
    j = 1;
    for (i[j]=bnds(2*j-1);i[j]<=bnds(2*j);i[j]++){
        p[i2p[j]] = i[j];
        j=2;
        for (i[j]=bnds(2*j-1);i[j]<=bnds(2*j);i[j]++){
            p[i2p[j]] = i[j];
            j=3;
            for (i[j]=bnds(2*j-1);i[j]<=bnds(2*j);i[j]++){
                p[i2p[j]] = i[j];
                n_p(p[1],p[2],p[3]) = 
                    n_i(i[1],i[2],i[3]);
            }
            j=2;
        }
        j=1;
    }
//    cout<<"finished permuteDims(d3_array&)"<<endl;
    return n_p;
}

/**
 * Permute dimensions of a d4_array.
 * 
 * @param perm - ivector indicating permutation
 * @param n_ijkl -d4_array to permute
 * 
 * @return d4_array with permuted dimensions
 */
d4_array wts::permuteDims(ivector& i2p, d4_array& n_i){
    int mxi = 4;
//    cout<<"starting permuteDims(d4_array&)"<<endl;
    if ((i2p.indexmax()-i2p.indexmin()+1)!=mxi){
        cout<<"Error in d"<<mxi<<"_array permuteDims()"<<endl;
        cout<<"i2p must have length "<<mxi<<"."<<endl;
        cout<<"i2p = "<<i2p<<endl;
        cout<<"Aborting..."<<endl;
        exit(-1);
    }
    ivector bnds = getBounds(n_i);
    ivector pbnds(1,2*mxi);
    for (int i=1;i<=mxi;i++) {
        pbnds(2*i2p(i)-1) = bnds(2*i-1);
        pbnds(2*i2p(i))   = bnds(2*i);
    }
    d4_array n_p = dimD4array(pbnds); 
    n_p.initialize();
    
    ivector i(1,mxi);//index vector for original array
    ivector p(1,mxi);//permuted index vector {p[i2p[j]] = i[j]}
    
    int j;
    j = 1;
    for (i[j]=bnds(2*j-1);i[j]<=bnds(2*j);i[j]++){
        p[i2p[j]] = i[j];
        j=2;
        for (i[j]=bnds(2*j-1);i[j]<=bnds(2*j);i[j]++){
            p[i2p[j]] = i[j];
            j=3;
            for (i[j]=bnds(2*j-1);i[j]<=bnds(2*j);i[j]++){
                p[i2p[j]] = i[j];
                j=4;
                for (i[j]=bnds(2*j-1);i[j]<=bnds(2*j);i[j]++){
                    p[i2p[j]] = i[j];
                    n_p(p[1],p[2],p[3],p[4]) = 
                        n_i(i[1],i[2],i[3],i[4]);
                }
                j=3;
            }
            j=2;
        }
        j=1;
    }
//    cout<<"finished permuteDims(d4_array&)"<<endl;
    return n_p;
}

/**
 * Permute dimensions of a d5_array.
 * 
 * @param perm - ivector indicating permutation
 * @param n_ijklmn -d5_array to permute
 * 
 * @return d5_array with permuted dimensions
 */
d5_array wts::permuteDims(ivector& i2p, d5_array& n_i){
//    cout<<"starting permuteDims(d5_array&)"<<endl;
    int mxi = 5;
    if ((i2p.indexmax()-i2p.indexmin()+1)!=mxi){
        cout<<"Error in d"<<mxi<<"_array permuteDims()"<<endl;
        cout<<"i2p must have length "<<mxi<<"."<<endl;
        cout<<"i2p = "<<i2p<<endl;
        cout<<"Aborting..."<<endl;
        exit(-1);
    }
    ivector bnds = getBounds(n_i);
    ivector pbnds(1,2*mxi);
    for (int i=1;i<=mxi;i++) {
        pbnds(2*i2p(i)-1) = bnds(2*i-1);
        pbnds(2*i2p(i))   = bnds(2*i);
    }
//    cout<<"bnds  = "<<bnds<<endl;
//    cout<<"pbnds = "<<pbnds<<endl;
    d5_array n_p = dimD5array(pbnds); 
    n_p.initialize();
//    cout<<"bounds(n_p) = "<<getBounds(n_p)<<endl;
    
    ivector i(1,mxi);//index vector for original array
    ivector p(1,mxi);//permuted index vector {p[i2p[j]] = i[j]}
    
    int j;
    j = 1;
    for (i[j]=bnds(2*j-1);i[j]<=bnds(2*j);i[j]++){
        p[i2p[j]] = i[j];
        j=2;
        for (i[j]=bnds(2*j-1);i[j]<=bnds(2*j);i[j]++){
            p[i2p[j]] = i[j];
            j=3;
            for (i[j]=bnds(2*j-1);i[j]<=bnds(2*j);i[j]++){
                p[i2p[j]] = i[j];
                j=4;
                for (i[j]=bnds(2*j-1);i[j]<=bnds(2*j);i[j]++){
                    p[i2p[j]] = i[j];
                    j=5;
                    for (i[j]=bnds(2*j-1);i[j]<=bnds(2*j);i[j]++){
                        p[i2p[j]] = i[j];
//                        cout<<endl<<"i = "<<i<<endl<<"p = "<<p<<endl;
//                        cout<<"n_i[i] = "<<n_i(i[1],i[2],i[3],i[4],i[5])<<endl;
                        n_p(p[1],p[2],p[3],p[4],p[5]) = 
                            n_i(i[1],i[2],i[3],i[4],i[5]);
//                        cout<<"n_p[p] = "<<n_p(p[1],p[2],p[3],p[4],p[5])<<endl;
                    }
                    j=4;
                }
                j=3;
            }
            j=2;
        }
        j=1;
    }
//    cout<<"finished permuteDims(d5_array&)"<<endl;
    return n_p;
}

/**
 * Permute dimensions of a d6_array.
 * 
 * @param perm - ivector indicating permutation
 * @param n_ijklmn -d6_array to permute
 * 
 * @return d6_array with permuted dimensions
 */
d6_array wts::permuteDims(ivector& i2p, d6_array& n_i){
    int mxi = 6;
//    cout<<"starting permuteDims(d6_array&)"<<endl;
    if ((i2p.indexmax()-i2p.indexmin()+1)!=mxi){
        cout<<"Error in d"<<mxi<<"_array permuteDims()"<<endl;
        cout<<"i2p must have length "<<mxi<<"."<<endl;
        cout<<"i2p = "<<i2p<<endl;
        cout<<"Aborting..."<<endl;
        exit(-1);
    }
    ivector bnds = getBounds(n_i);
    ivector pbnds(1,2*mxi);
    for (int i=1;i<=mxi;i++) {
        pbnds(2*i2p(i)-1) = bnds(2*i-1);
        pbnds(2*i2p(i))   = bnds(2*i);
    }
    d6_array n_p = dimD6array(pbnds); 
    n_p.initialize();
    
    ivector i(1,mxi);//index vector for original array
    ivector p(1,mxi);//permuted index vector {p[i2p[j]] = i[j]}
    
    int j;
    j = 1;
    for (i[j]=bnds(2*j-1);i[j]<=bnds(2*j);i[j]++){
        p[i2p[j]] = i[j];
        j=2;
        for (i[j]=bnds(2*j-1);i[j]<=bnds(2*j);i[j]++){
            p[i2p[j]] = i[j];
            j=3;
            for (i[j]=bnds(2*j-1);i[j]<=bnds(2*j);i[j]++){
                p[i2p[j]] = i[j];
                j=4;
                for (i[j]=bnds(2*j-1);i[j]<=bnds(2*j);i[j]++){
                    p[i2p[j]] = i[j];
                    j=5;
                    for (i[j]=bnds(2*j-1);i[j]<=bnds(2*j);i[j]++){
                        p[i2p[j]] = i[j];
                        j=6;
                        for (i[j]=bnds(2*j-1);i[j]<=bnds(2*j);i[j]++){
                            p[i2p[j]] = i[j];
                            n_p(p[1],p[2],p[3],p[4],p[5],p[6]) = 
                                n_i(i[1],i[2],i[3],i[4],i[5],i[6]);
                        }
                        j=5;
                    }
                    j=4;
                }
                j=3;
            }
            j=2;
        }
        j=1;
    }
//    cout<<"finished permuteDims(d6_array&)"<<endl;
    return n_p;
}

/**
 * Permute dimensions of a d7_array.
 * 
 * @param perm - ivector indicating permutation
 * @param n_ijklmn -d7_array to permute
 * 
 * @return d7_array with permuted dimensions
 */
d7_array wts::permuteDims(ivector& i2p, d7_array& n_i){
    int mxi = 7;
//    cout<<"starting permuteDims(d7_array&)"<<endl;
    if ((i2p.indexmax()-i2p.indexmin()+1)!=mxi){
        cout<<"Error in d"<<mxi<<"_array permuteDims()"<<endl;
        cout<<"i2p must have length "<<mxi<<"."<<endl;
        cout<<"i2p = "<<i2p<<endl;
        cout<<"Aborting..."<<endl;
        exit(-1);
    }
    ivector bnds = getBounds(n_i);
    ivector pbnds(1,2*mxi);
    for (int i=1;i<=mxi;i++) {
        pbnds(2*i2p(i)-1) = bnds(2*i-1);
        pbnds(2*i2p(i))   = bnds(2*i);
    }
//    d7_array n_p = dimD7array(pnds); //<-doesn't compile because d7 does not have a copy constructor
    d7_array n_p(pbnds[1],pbnds[2],pbnds[3],pbnds[4],pbnds[5],pbnds[6],pbnds[7],pbnds[8],
                 pbnds[9],pbnds[10],pbnds[11],pbnds[12],pbnds[13],pbnds[14]);
    n_p.initialize();
    
    ivector i(1,mxi);//index vector for original array
    ivector p(1,mxi);//permuted index vector {p[i2p[j]] = i[j]}
    
    int j;
    j = 1;
    for (i[j]=bnds(2*j-1);i[j]<=bnds(2*j);i[j]++){
        p[i2p[j]] = i[j];
        j=2;
        for (i[j]=bnds(2*j-1);i[j]<=bnds(2*j);i[j]++){
            p[i2p[j]] = i[j];
            j=3;
            for (i[j]=bnds(2*j-1);i[j]<=bnds(2*j);i[j]++){
                p[i2p[j]] = i[j];
                j=4;
                for (i[j]=bnds(2*j-1);i[j]<=bnds(2*j);i[j]++){
                    p[i2p[j]] = i[j];
                    j=5;
                    for (i[j]=bnds(2*j-1);i[j]<=bnds(2*j);i[j]++){
                        p[i2p[j]] = i[j];
                        j=6;
                        for (i[j]=bnds(2*j-1);i[j]<=bnds(2*j);i[j]++){
                            p[i2p[j]] = i[j];
                            j=7;
                            for (i[j]=bnds(2*j-1);i[j]<=bnds(2*j);i[j]++){
                                p[i2p[j]] = i[j];
                                n_p(p[1],p[2],p[3],p[4],p[5],p[6],p[7]) = 
                                    n_i(i[1],i[2],i[3],i[4],i[5],i[6],i[7]);
                            }
                            j=6;
                        }
                        j=5;
                    }
                    j=4;
                }
                j=3;
            }
            j=2;
        }
        j=1;
    }
//    cout<<"finished permuteDims(d7_array&)"<<endl;
    return n_p;
}

/*************************************************
* name      : length                             *
* purpose   : return number of elements in array *
*************************************************/
int wts::length(const ivector& o){
    ivector b(1,2);
    b = getBounds(o);
    int i = b(2)-b(1)+1;
    return(i);
}
//-------------------------------------------------------------
int wts::length(const imatrix& o){
    ivector b(1,2);
    b = getBounds(o);
    int i = 1;
    for (int j=1;j<=2;j++) i *= (b(2*j)-b(2*j-1)+1);
    return(i);
}
//-------------------------------------------------------------
int wts::length(const dvector& o){
    ivector b(1,2);
    b = getBounds(o);
    int i = b(2)-b(1)+1;
    return(i);
}
//-------------------------------------------------------------
int wts::length(const dmatrix& o){
    ivector b(1,2);
    b = getBounds(o);
    int i = 1;
    for (int j=1;j<=2;j++) i *= (b(2*j)-b(2*j-1)+1);
    return(i);
}
//-------------------------------------------------------------
int wts::length(const dvar_vector& o){
    ivector b(1,2);
    b = getBounds(o);
    int i = b(2)-b(1)+1;
    return(i);
}
//-------------------------------------------------------------
int wts::length(const dvar_matrix& o){
    ivector b(1,2);
    b = getBounds(o);
    int i = 1;
    for (int j=1;j<=2;j++) i *= (b(2*j)-b(2*j-1)+1);
    return(i);
}
//-------------------------------------------------------------

///**
// * Returns the value of a dvar_vector as a dvector.
// * 
// * @param o - the dvar_vector
// * @return - a dvector
// */
//dvector wts::value(const dvar_vector& o){
//    if (debugADMBFunctions>0) cout<<"start value(dvar_vector)"<<endl;
//    if (debugADMBFunctions>0) cout<<"end value(dvar_vector)"<<endl;
//    return(::value(o));
//}
///**
// * Returns the value of a dvar_matrix as a dmatrix.
// * 
// * @param o - the dvar_matrix
// * @return - a dmatrix
// */
//dmatrix wts::value(const dvar_matrix& o){
//    if (debugADMBFunctions>0) cout<<"start value(dvar_matrix)"<<endl;
//    if (debugADMBFunctions>0) cout<<"end value(dvar_matrix)"<<endl;
//    return(::value(o));
//}
///**
// * Returns the value of a dvar3_array as a d3_array.
// * 
// * @param o - the dvar3_array
// * @return - a d3_array
// */
//d3_array wts::value(const dvar3_array& o){
//    if (debugADMBFunctions>0) cout<<"start value(dvar3_array)"<<endl;
//    if (debugADMBFunctions>0) cout<<"end value(dvar3_array)"<<endl;
//    return(::value(o));
//}

/**
 * Returns the value of a dvar4_array as a d4_array.
 * 
 * @param o - the dvar4_array
 * @return - a d4_array
 */
d4_array wts::value(const dvar4_array& o){
    if (debugADMBFunctions>0) cout<<"start value(dvar4_array)"<<endl;
    ivector b = getBounds(o);
    d4_array a(b(1),b(2),b(3),b(4),b(5),b(6),b(7),b(8));
    for (int r=b(1);r<=b(2);r++) a(r) = value(o(r));
    if (debugADMBFunctions>0) cout<<"   end value(dvar4_array)"<<endl;
    return(a);
}
/**
 * Returns the value of a dvar3_array as a d5_array.
 * 
 * @param o - the dvar5_array
 * @return - a d5_array
 */
d5_array wts::value(const dvar5_array& o){
    if (debugADMBFunctions>0) cout<<"start value(dvar5_array)"<<endl;
    ivector b = getBounds(o);
    d5_array a(b(1),b(2),b(3),b(4),b(5),b(6),b(7),b(8),b(9),b(10));
    for (int r=b(1);r<=b(2);r++) a(r) = value(o(r));
    if (debugADMBFunctions>0) cout<<"   end value(dvar5_array)"<<endl;
    return(a);
}
/**
 * Returns the value of a dvar6_array as a d6_array.
 * 
 * @param o - the dvar6_array
 * @return - a d6_array
 */
d6_array wts::value(const dvar6_array& o){
    if (debugADMBFunctions>0) cout<<"start value(dvar6_array)"<<endl;
    ivector b = getBounds(o);
    d6_array a(b(1),b(2),b(3),b(4),b(5),b(6),b(7),b(8),b(9),b(10),b(11),b(12));
    for (int r=b(1);r<=b(2);r++) a(r) = value(o(r));
    if (debugADMBFunctions>0) cout<<"   end value(dvar6_array)"<<endl;
    return(a);
}
/**
 * Returns the value of a dvar3_array as a d7_array.
 * 
 * @param o - the dvar7_array
 * @return - a d7_array
 */
d7_array wts::value(const dvar7_array& o){
    if (debugADMBFunctions>0) cout<<"start value(dvar7_array)"<<endl;
    ivector b = getBounds(o);
    d7_array a(b(1),b(2),b(3),b(4),b(5),b(6),b(7),b(8),b(9),b(10),b(11),b(12),b(13),b(14));
    for (int r=b(1);r<=b(2);r++) a(r) = value(o(r));
    if (debugADMBFunctions>0) cout<<"   end value(dvar7_array)"<<endl;
    return(a);
}
//-------------------------------------------------------------

/*************************************************
* name      : getIndexVector                     *
* purpose   : get indices for vector             *
*************************************************/
ivector wts::getIndexVector(const dvector& o) {
    ivector bnds = getBounds(o);
    ivector indx(bnds(1),bnds(2));
    indx.fill_seqadd(bnds(1),1);
    return indx;
}
//-------------------------------------------------------------

ivector wts::getIndexVector(const dvar_vector& o) {
    ivector bnds = getBounds(o);
    ivector indx(bnds(1),bnds(2));
    indx.fill_seqadd(bnds(1),1);
    return indx;
}
//-------------------------------------------------------------

//delta function    
int wts::deltafcn(int i, int j){return (i==j);}

/******************************************************
 * Tests if a parameter is currently being estimated. *
******************************************************/
bool wts::isActive(const param_init_number& p){return active(p);}
bool wts::isActive(const param_init_vector& p){return active(p);}
bool wts::isActive(param_init_number_vector& p){
    bool res = false;
    for (int i=p.indexmin();i<=p.indexmax();i++) res = res||active(p(i));
    return res;
}
bool wts::isActive(param_init_vector_vector& p){
    bool res = false;
    for (int i=p.indexmin();i<=p.indexmax();i++) res = res||active(p(i));
    return res;
}

/********************************************
* name      : variance                      *
* purpose   : compute variance of object    *
********************************************/
double wts::variance(const dvector & v) {
    return norm2(v-mean(v))/double(length(v)-1);
}
//-------------------------------------------------------------
dvariable wts::variance(const dvar_vector & v) {
    return norm2(v-mean(v))/double(length(v)-1);
}
       
/**
 * Create a diagonal matrix from a vector.
 * 
 * @param v - vector defining the diagonal
 * @return - a dmatrix with row/column indices equal to those of v
 */
dmatrix wts::diag(const dvector& v){
    int mn = v.indexmin();
    int mx = v.indexmax();
    dmatrix m(mn,mx,mn,mx); 
    m.initialize();
    for (int i=mn;i<=mx;i++) m(i,i) = v(i);
    return m;
}
/**
 * Create a diagonal matrix from a vector.
 * 
 * @param v - vector defining the diagonal
 * @return - a dvar_matrix with row/column indices equal to those of v
 */
dvar_matrix wts::diag(const dvar_vector& v){
    RETURN_ARRAYS_INCREMENT();
    int mn = v.indexmin();
    int mx = v.indexmax();
    dvar_matrix m(mn,mx,mn,mx); 
    m.initialize();
    for (int i=mn;i<=mx;i++) m(i,i) = v(i);
    RETURN_ARRAYS_DECREMENT();
    return m;
}
/**
 * Print a dmatrix.
 * @param a - dmatrix to print
 * @param cout - output stream to print to
 * @param nt - number of tabs to insert
 */
void wts::print(dmatrix& a, ostream& cout, int nt){
    for (int i=a.indexmin(); i<=a.indexmax(); i++){
        for (int t=1;t<=nt;t++) cout<<tb; cout<<i<<": ";
        cout<<a(i)<<endl;
    }
}
/**
 * Print a d3_array.
 * @param a - d3_array to print
 * @param cout - output stream to print to
 * @param nt - number of tabs to insert
 */
void wts::print(d3_array& a, ostream& cout, int nt){
    for (int i=a.indexmin(); i<=a.indexmax(); i++){
        for (int t=1;t<=nt;t++) cout<<tb; cout<<i<<": "<<endl;
        wts::print(a(i),cout,nt+1);
    }
}
/**
 * Print a d4_array.
 * @param a - d4_array to print
 * @param cout - output stream to print to
 * @param nt - number of tabs to insert
 */
void wts::print(d4_array& a, ostream& cout, int nt){
    for (int i=a.indexmin(); i<=a.indexmax(); i++){
        for (int t=1;t<=nt;t++) cout<<tb; cout<<i<<": "<<endl;
        wts::print(a(i),cout,nt+1);
    }
}
/**
 * Print a d5_array.
 * @param a - d5_array to print
 * @param cout - output stream to print to
 * @param nt - number of tabs to insert
 */
void wts::print(d5_array& a, ostream& cout, int nt){
    for (int i=a.indexmin(); i<=a.indexmax(); i++){
        for (int t=1;t<=nt;t++) cout<<tb; cout<<i<<": "<<endl;
        wts::print(a(i),cout,nt+1);
    }
}
