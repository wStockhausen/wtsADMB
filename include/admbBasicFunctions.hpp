// admbFunctions.hpp
// file contains some general ADMB functions
#pragma once
#ifndef ADMBFUNCTIONS_HPP

#include <ivector.h>

    #define ADMBFUNCTIONS_HPP

using namespace std;

    extern int debugADMBFunctions;
    bool operator ==(const ivector & i1, const ivector & i2);
    
namespace wts{
    
    
    ivector abs(const ivector& i1);

    /**
     * Convert a vector of values to and ivector of indices corresponding to 
     * the bins defined by a vector of cut points.
     *  
     * @param values - vector of values to bin
     * @param cutPts - vector of cut points to use for binning
     * @param accumLow - flag (0/1) to assign values less than the min cut point to the lowest bin
     * @param accumHigh - flag (0/1) to assign values higher the the max cut point to highest bin
     * 
     * @return - ivector of indices corresponding to the bin assigned to each value
     */
    ivector assignBinIndices(const dvector& values, const dvector& cutPts, int accumLow, int accumHigh);
    
    /**
     * Extracts all values falling between min and max from an ivector
     * @param min
     * @param max
     * @param v
     * @return - ivector
     */
    ivector extractVector(int min, int max, ivector v);
    
    /**
     * Extracts all values falling between min and max from a dvector
     * @param min
     * @param max
     * @param v
     * @return - dvector
     */
    dvector extractVector(double min, double max, dvector v);
    
    /**
     * Compares a dvector to a value and returns an ivector with 1's (0's) where the 
     * condition is true (false).
     * 
     * @param x - the dvector of values to check
     * @param v - the value to compare to
     * 
     * @return an ivector with 1's where 
     */
    ivector gt(const dvector& x, double v);
    
    /**
     * Returns one of two results based on a logical test.
     * 
     * @param test - logical test
     * @param x - returned if test is true
     * @param y - returned if test is false
     * 
     * @return 
     */
    int ifelse(bool test, int x, int y);
    /**
     * Returns one of two results based on a logical test.
     * 
     * @param test - logical test
     * @param x - returned if test is true
     * @param y - returned if test is false
     * 
     * @return 
     */
    double ifelse(bool test, double x, double y);
    /**
     * Returns an ivector representing the results of x[i] == y for
     * each element of x.
     * 
     * @param x - dvector to test
     * @param y - double
     * @return - ivector with same indices as x 
     */
    ivector isEQ(const dvector & x, double y);
    
    /**
     * Returns an ivector representing the indices of x
     * where x[i] == y is true.
     * 
     * @param x - dvector to test
     * @param y - double
     * @return - ivector with indices of x where x[i] == y
     */
    ivector whichIsEQ(const dvector & x, double y);
    
    /**
     * Returns an ivector representing the results of x[i] != y for
     * each element of x.
     * 
     * @param x - dvector to test
     * @param y - double
     * @return - ivector with same indices as x 
     */
    ivector isNE(const dvector & x, double y);
    
    /**
     * Returns an ivector representing the indices of x
     * where x[i] != y is true.
     * 
     * @param x - dvector to test
     * @param y - double
     * @return - ivector with indices of x where x[i] != y
     */
    ivector whichIsNE(const dvector & x, double y);
    
    /**
     * Returns an ivector representing the results of x[i] < y for
     * each element of x.
     * 
     * @param x - dvector to test
     * @param y - double
     * @return - ivector with same indices as x 
     */
    ivector isLT(const dvector & x, double y);
    
    /**
     * Returns an ivector representing the results of x[i] <= y for
     * each element of x.
     * 
     * @param x - dvector to test
     * @param y - double
     * @return - ivector with same indices as x 
     */
    ivector isLE(const dvector & x, double y);
    
    /**
     * Returns an ivector representing the results of x[i] > y for
     * each element of x.
     * 
     * @param x - dvector to test
     * @param y - double
     * @return - ivector with same indices as x 
     */
    ivector isGT(const dvector & x, double y);
    
    /**
     * Returns an ivector representing the results of x[i] >= y for
     * each element of x.
     * 
     * @param x - dvector to test
     * @param y - double
     * @return - ivector with same indices as x 
     */
    ivector isGE(const dvector & x, double y);
    
    /**
     * Returns the max of two (double) numbers.
     * 
     * @param x1
     * @param x2
     * 
     * @return - the max of x1, x2
     */
    double max(double x1,double x2);
    
    /**
     * Returns the max of the array
     * 
     * @param a - d3_array
     * 
     * @return - the maximum value in the array
     */
    double max(d3_array& a);
    
    /**
     * Returns the max of the array
     * 
     * @param a - d4_array
     * 
     * @return - the maximum value in the array
     */
    double max(d4_array& a);
    
    /**
     * Returns the max of the array
     * 
     * @param a - d5_array
     * 
     * @return - the maximum value in the array
     */
    double max(d5_array& a);
    
    /**
     * Returns the max of the array
     * 
     * @param a - d6_array
     * 
     * @return - the maximum value in the array
     */
    double max(d6_array& a);
    
    /**
     * Returns the max of the array
     * 
     * @param a - d7_array
     * 
     * @return - the maximum value in the array
     */
    double max(d7_array& a);

    /**
     * Returns the min of two (double) numbers.
     * 
     * @param x1
     * @param x2
     * 
     * @return - the min of x1, x2
     */
    double min(double x1,double x2);
    
    /**
     * Returns the min of the array
     * 
     * @param a - d3_array
     * 
     * @return - the maximum value in the array
     */
    double min(d3_array& a);
    
    /**
     * Returns the min of the array
     * 
     * @param a - d4_array
     * 
     * @return - the maximum value in the array
     */
    double min(d4_array& a);
    
    /**
     * Returns the min of the array
     * 
     * @param a - d5_array
     * 
     * @return - the maximum value in the array
     */
    double min(d5_array& a);
    
    /**
     * Returns the min of the array
     * 
     * @param a - d6_array
     * 
     * @return - the maximum value in the array
     */
    double min(d6_array& a);
    
    /**
     * Returns the min of the array
     * 
     * @param a - d7_array
     * 
     * @return - the maximum value in the array
     */
    double min(d7_array& a);

    /**
     * Returns the max of two dvariables.
     * 
     * @param x1
     * @param x2
     * 
     * @return - the max of x1, x2
     */
    dvariable max(dvariable x1,dvariable x2);
    
    /**
     * Returns the max of the vector
     * 
     * @param a - dvar_vector
     * 
     * @return - the maximum value in the array
     */
    dvariable max(dvar_vector& a);
    
    /**
     * Returns the max of the matrix
     * 
     * @param a - dvar_matrix
     * 
     * @return - the maximum value in the array
     */
    dvariable max(dvar_matrix& a);
    
    /**
     * Returns the max of the array
     * 
     * @param a - dvar3_array
     * 
     * @return - the maximum value in the array
     */
    dvariable max(dvar3_array& a);
    
    /**
     * Returns the max of the array
     * 
     * @param a - dvar4_array
     * 
     * @return - the maximum value in the array
     */
    dvariable max(dvar4_array& a);
    
    /**
     * Returns the max of the array
     * 
     * @param a - dvar5_array
     * 
     * @return - the maximum value in the array
     */
    dvariable max(dvar5_array& a);
    
    /**
     * Returns the max of the array
     * 
     * @param a - dvar6_array
     * 
     * @return - the maximum value in the array
     */
    dvariable max(dvar6_array& a);
    
    /**
     * Returns the max of the array
     * 
     * @param a - dvar7_array
     * 
     * @return - the maximum value in the array
     */
    dvariable max(dvar7_array& a);

    /**
     * Returns the min of two dvariables.
     * 
     * @param x1
     * @param x2
     * 
     * @return - the min of x1, x2
     */
    dvariable min(dvariable x1,dvariable x2);
    
    /**
     * Returns the min of the vector
     * 
     * @param a - dvar_vector
     * 
     * @return - the maximum value in the array
     */
    dvariable min(dvar_vector& a);
    
    /**
     * Returns the min of the matrix
     * 
     * @param a - dvar_matrix
     * 
     * @return - the maximum value in the array
     */
    dvariable min(dvar_matrix& a);
    
    /**
     * Returns the min of the array
     * 
     * @param a - dvar3_array
     * 
     * @return - the maximum value in the array
     */
    dvariable min(dvar3_array& a);
    
    /**
     * Returns the min of the array
     * 
     * @param a - dvar4_array
     * 
     * @return - the maximum value in the array
     */
    dvariable min(dvar4_array& a);
    
    /**
     * Returns the min of the array
     * 
     * @param a - d5_array
     * 
     * @return - the maximum value in the array
     */
    dvariable min(dvar5_array& a);
    
    /**
     * Returns the min of the array
     * 
     * @param a - dvar6_array
     * 
     * @return - the maximum value in the array
     */
    dvariable min(dvar6_array& a);
    
    /**
     * Returns the min of the array
     * 
     * @param a - dvar7_array
     * 
     * @return - the maximum value in the array
     */
    dvariable min(dvar7_array& a);

    /**
     * Converts a dvector (doubles) to an ivector (integers).
     * 
     * @param v - the dvector to convert
     * 
     * @return - the corresponding ivector
     */
    ivector to_ivector(const dvector& v);
    /**
     * Creates a deep copy of a vector. Simple assignment (dvector a=b;) generally
     * creates a shallow copy, so changing a(i) also changes b(i), which may
     * not be what is wanted.
     * 
     * @param v - the original dvector
     * 
     * @return - the deep copy
     */
    dvector  copy(const dvector& v);
    /**
     * Creates a deep copy of a matrix. Simple assignment (dmatrix a=b;) generally
     * creates a shallow copy, so changing a(i,j) also changes b(i,j), which may
     * not be what is wanted.
     * 
     * @param v - the original dmatrix
     * 
     * @return - the deep copy
     */
    dmatrix  copy(const dmatrix& v);
    /**
     * Creates a deep copy of an array. Simple assignment (d3_array a=b;) generally
     * creates a shallow copy, so changing a(i,...) also changes b(i,...), which may
     * not be what is wanted.
     * 
     * @param v - the original d3_array
     * 
     * @return - the deep copy
     */
    d3_array copy(const d3_array& v);
    /**
     * Creates a deep copy of an array. Simple assignment (d4_array a=b;) generally
     * creates a shallow copy, so changing a(i,...) also changes b(i,...), which may
     * not be what is wanted.
     * 
     * @param v - the original d4_array
     * 
     * @return - the deep copy
     */
    d4_array copy(const d4_array& v);
    /**
     * Creates a deep copy of an array. Simple assignment (d5_array a=b;) generally
     * creates a shallow copy, so changing a(i,...) also changes b(i,...), which may
     * not be what is wanted.
     * 
     * @param v - the original d5_array
     * 
     * @return - the deep copy
     */
    d5_array copy(const d5_array& v);
    /**
     * Creates a deep copy of an array. Simple assignment (d6_array a=b;) generally
     * creates a shallow copy, so changing a(i,...) also changes b(i,...), which may
     * not be what is wanted.
     * 
     * @param v - the original d6_array
     * 
     * @return - the deep copy
     */
    d6_array copy(const d6_array& v);
    /**
     * Creates a deep copy of an array. Simple assignment (d7_array a=b;) generally
     * creates a shallow copy, so changing a(i,...) also changes b(i,...), which may
     * not be what is wanted.
     * 
     * @param v - the original d7_array
     * 
     * @return - the deep copy
     */
    d7_array copy(const d7_array& v);
    /**
     * Creates a deep copy of a vector. Simple assignment (dvar_vector a=b;) generally
     * creates a shallow copy, so changing a(i) also changes b(i), which may
     * not be what is wanted.
     * 
     * @param v - the original dvar_vector
     * 
     * @return - the deep copy
     */
    dvar_vector copy(const dvar_vector& v);
    /**
     * Creates a deep copy of a matrix. Simple assignment (dvar_matrix a=b;) generally
     * creates a shallow copy, so changing a(i,...) also changes b(i,...), which may
     * not be what is wanted.
     * 
     * @param v - the original dvar_matrix
     * 
     * @return - the deep copy
     */
    dvar_matrix copy(const dvar_matrix& v);
    /**
     * Creates a deep copy of an array. Simple assignment (dvar3_array a=b;) generally
     * creates a shallow copy, so changing a(i,...) also changes b(i,...), which may
     * not be what is wanted.
     * 
     * @param v - the original dvar3_array
     * 
     * @return - the deep copy
     */
    dvar3_array copy(const dvar3_array& v);
    /**
     * Creates a deep copy of an array. Simple assignment (dvar4_array a=b;) generally
     * creates a shallow copy, so changing a(i,...) also changes b(i,...), which may
     * not be what is wanted.
     * 
     * @param v - the original dvar4_array
     * 
     * @return - the deep copy
     */
    dvar4_array copy(const dvar4_array& v);
    /**
     * Creates a deep copy of an array. Simple assignment (dvar5_array a=b;) generally
     * creates a shallow copy, so changing a(i,...) also changes b(i,...), which may
     * not be what is wanted.
     * 
     * @param v - the original dvar5_array
     * 
     * @return - the deep copy
     */
    dvar5_array copy(const dvar5_array& v);
    /**
     * Creates a deep copy of an array. Simple assignment (dvar6_array a=b;) generally
     * creates a shallow copy, so changing a(i,...) also changes b(i,...), which may
     * not be what is wanted.
     * 
     * @param v - the original dvar6_array
     * 
     * @return - the deep copy
     */
    dvar6_array copy(const dvar6_array& v);
    /**
     * Creates a deep copy of an array. Simple assignment (dvar7_array a=b;) generally
     * creates a shallow copy, so changing a(i,...) also changes b(i,...), which may
     * not be what is wanted.
     * 
     * @param v - the original dvar7_array
     * 
     * @return - the deep copy
     */
    dvar7_array copy(const dvar7_array& v);

    /****************************************************************
    * name      : IdentityMatrix                                    *
    * purpose   : returns an identity dmatrix with row/col          *
    *               indices running from mn to mx.                  *
    ****************************************************************/
    dmatrix IdentityMatrix(int mn,int mx);

    /****************************************************************
    * name      : testEquals                                        *
    * purpose   : test equality                                     *
    ****************************************************************/
    int testEquals(const ivector& i1, const ivector& i2);

    /*************************************************
    * name      : getBounds                          *
    * purpose   : return min, max indices for array  *
    *************************************************/
    ivector getBounds(const  prevariable& o);
    ivector getBounds(const  ivector& o);
    ivector getBounds(const  imatrix& o);
    ivector getBounds(const  i3_array& o);
    ivector getBounds(const  i4_array& o);
    ivector getBounds(const  i5_array& o);
    ivector getBounds(const  dvector& o);
    ivector getBounds(const  dmatrix& o);
    ivector getBounds(const  d3_array& o);
    ivector getBounds(const  d4_array& o);
    ivector getBounds(const  d5_array& o);
    ivector getBounds(const  d6_array& o);
    ivector getBounds(const  d7_array& o);
    ivector getBounds(const  dvar_vector& o);
    ivector getBounds(const  dvar_matrix& o);
    ivector getBounds(const  dvar3_array& o);
    ivector getBounds(const  dvar4_array& o);
    ivector getBounds(const  dvar5_array& o);
    ivector getBounds(const  dvar6_array& o);
    ivector getBounds(const  dvar7_array& o);
    
    /**
     * Create, dimension and initialize a dmatrix using
     * an ivector.
     * 
     * @param dims - the dimensions (alternating low/high)
     * @return - the dimensioned array
     */
    dmatrix dimDmatrix(ivector& dims);
    
    /**
     * Create, dimension and initialize a d3_array using
     * an ivector.
     * 
     * @param dims - the dimensions (alternating low/high)
     * @return - the dimensioned array
     */
    d3_array dimD3array(ivector& dims);
    
    /**
     * Create, dimension and initialize a d4_array using
     * an ivector.
     * 
     * @param dims - the dimensions (alternating low/high)
     * @return - the dimensioned array
     */
    d4_array dimD4array(ivector& dims);
    
    /**
     * Create, dimension and initialize a d5_array using
     * an ivector.
     * 
     * @param dims - the dimensions (alternating low/high)
     * @return - the dimensioned array
     */
    d5_array dimD5array(ivector& dims);
    
    /**
     * Create, dimension and initialize a d6_array using
     * an ivector.
     * 
     * @param dims - the dimensions (alternating low/high)
     * @return - the dimensioned array
     */
    d6_array dimD6array(ivector& dims);
    
    /**
     * Create, dimension and initialize a d7_array using
     * an ivector.
     * 
     * @param dims - the dimensions (alternating low/high)
     * @return - the dimensioned array
     */
    d7_array dimD7array(ivector& dims);
        
    /**
     * Permute dimensions of a dmatrix. Same as transpose.
     * 
     * @param perm - ivector of length 2 indicating permutation
     * @param n_ij -dmatrix to permute (transpose)
     * 
     * @return dmatrix with permuted dimensions
     */
    dmatrix permuteDims(ivector& perm, dmatrix& n_ij);
    
    /**
     * Permute dimensions of a d3_array.
     * 
     * @param perm - ivector of length 3 indicating permutation
     * @param n_ijk -d3_array to permute
     * 
     * @return d3_array with permuted dimensions
     */
    d3_array permuteDims(ivector& perm, d3_array& n_ijk);
    
    /**
     * Permute dimensions of a d4_array.
     * 
     * @param perm - ivector of length 4 indicating permutation
     * @param n_ijkl -d4_array to permute
     * 
     * @return d4_array with permuted dimensions
     */
    d4_array permuteDims(ivector& perm, d4_array& n_ijkl);
    
    /**
     * Permute dimensions of a d5_array.
     * 
     * @param perm - ivector of length 5 indicating permutation
     * @param n_ijklm -d5_array to permute
     * 
     * @return d5_array with permuted dimensions
     */
    d5_array permuteDims(ivector& perm, d5_array& n_ijklm);
    
    /**
     * Permute dimensions of a d6_array.
     * 
     * @param perm - ivector of length 6 indicating permutation
     * @param n_ijklmn -d6_array to permute
     * 
     * @return d6_array with permuted dimensions
     */
    d6_array permuteDims(ivector& perm, d6_array& n_ijklmn);
    
    /**
     * Permute dimensions of a d7_array.
     * 
     * @param perm - ivector of length 7 indicating permutation
     * @param n_ijklmn -d7_array to permute
     * 
     * @return d7_array with permuted dimensions
     */
    d7_array permuteDims(ivector& perm, d7_array& n_ijklmn);

    /*************************************************
    * name      : getIndexVector                     *
    * purpose   : get vector of indices for vector   *
    *************************************************/
    ivector getIndexVector(const dvector& o);
    ivector getIndexVector(const dvar_vector& o);

    /*************************************************
    * name      : length                             *
    * purpose   : return number of elements in array *
    *************************************************/
    int length(const  ivector& o);
    int length(const  imatrix& o);
    int length(const  dvector& o);
    int length(const  dmatrix& o);
    int length(const  dvar_vector& o);
    int length(const  dvar_matrix& o);

    /*************************************************
    * name      : value                              *
    * purpose   : return constant version of array   *
    *************************************************/
    //-------------------------------------------------------------
//    dvector  value(const  dvar_vector& o);
//    dmatrix  value(const  dvar_matrix& o);
//    d3_array value(const  dvar3_array& o);
    d4_array value(const  dvar4_array& o);
    d5_array value(const  dvar5_array& o);
    d6_array value(const  dvar6_array& o);
    d7_array value(const  dvar7_array& o);

    //delta function    
    int deltafcn(int i, int j);

    /***********************************************************
     * Test if at least one of a set of parameters is          *
     * being estimated in the current phase.                   *
    ***********************************************************/
    bool isActive(const param_init_number& p);
    bool isActive(const param_init_vector& p);
    bool isActive(param_init_number_vector& p);
    bool isActive(param_init_vector_vector& p);

    /********************************************
    * name      : variance                      *
    * purpose   : compute variance of object    *
    ********************************************/
    double variance(const dvector & v);
    dvariable variance(const dvar_vector & v);
    
    /**
     * Create a diagonal matrix from a vector.
     * 
     * @param v - vector defining the diagonal
     * @return - a dmatrix with row/column indices equal to those of v
     */
    dmatrix diag(const dvector& v);
    /**
     * Create a diagonal matrix from a vector.
     * 
     * @param v - vector defining the diagonal
     * @return - a dvar_matrix with row/column indices equal to those of v
     */
    dvar_matrix diag(const dvar_vector& v);
    /**
     * Print a dmatrix.
     * @param a - dmatrix to print
     * @param cout - output stream to print to
     * @param nt - number of tabs to insert
     */
    void print(dmatrix& a, ostream& cout, int nt=0);
    /**
     * Print a d3_array.
     * @param a - d3_array to print
     * @param cout - output stream to print to
     * @param nt - number of tabs to insert
     */
    void print(d3_array& a, ostream& cout, int nt=0);
    /**
     * Print a d4_array.
     * @param a - d4_array to print
     * @param cout - output stream to print to
     * @param nt - number of tabs to insert
     */
    void print(d4_array& a, ostream& cout, int nt=0);
    /**
     * Print a d5_array.
     * @param a - d5_array to print
     * @param cout - output stream to print to
     * @param nt - number of tabs to insert
     */
    void print(d5_array& a, ostream& cout, int nt=0);
    /**
     * Print a dvar_matrix.
     * @param a - dvar_matrix to print
     * @param cout - output stream to print to
     * @param nt - number of tabs to insert
     */
    void print(dvar_matrix& a, ostream& cout, int nt=0);
    /**
     * Print a dvar3_array.
     * @param a - dvar3_array to print
     * @param cout - output stream to print to
     * @param nt - number of tabs to insert
     */
    void print(dvar3_array& a, ostream& cout, int nt=0);
    /**
     * Print a dvar4_array.
     * @param a - dvar4_array to print
     * @param cout - output stream to print to
     * @param nt - number of tabs to insert
     */
    void print(dvar4_array& a, ostream& cout, int nt=0);
    /**
     * Print a dvar5_array.
     * @param a - dvar5_array to print
     * @param cout - output stream to print to
     * @param nt - number of tabs to insert
     */
    void print(dvar5_array& a, ostream& cout, int nt=0);
} //namespace wts
#endif
