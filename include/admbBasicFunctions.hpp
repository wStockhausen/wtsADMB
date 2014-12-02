// admbFunctions.hpp
// file contains some general ADMB functions
#pragma once
#ifndef ADMBFUNCTIONS_HPP
    #define ADMBFUNCTIONS_HPP

    extern int debugADMBFunctions;
namespace wts{
    
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
     * Returns the min of two (double) numbers.
     * 
     * @param x1
     * @param x2
     * 
     * @return - the min of x1, x2
     */
    double min(double x1,double x2);
    
    /**
     * Converts a dvector (doubles) to an ivector (integers).
     * 
     * @param v - the dvector to convert
     * 
     * @return - the corresponding ivector
     */
    ivector to_ivector(_CONST dvector& v);
    /**
     * Creates a deep copy of a vector. Simple assignment (dvector a=b;) generally
     * creates a shallow copy, so changing a(i) also changes b(i), which may
     * not be what is wanted.
     * 
     * @param v - the original dvector
     * 
     * @return - the deep copy
     */
    dvector  copy(_CONST dvector& v);
    /**
     * Creates a deep copy of a matrix. Simple assignment (dmatrix a=b;) generally
     * creates a shallow copy, so changing a(i,j) also changes b(i,j), which may
     * not be what is wanted.
     * 
     * @param v - the original dmatrix
     * 
     * @return - the deep copy
     */
    dmatrix  copy(_CONST dmatrix& v);
    /**
     * Creates a deep copy of an array. Simple assignment (d3_array a=b;) generally
     * creates a shallow copy, so changing a(i,...) also changes b(i,...), which may
     * not be what is wanted.
     * 
     * @param v - the original d3_array
     * 
     * @return - the deep copy
     */
    d3_array copy(_CONST d3_array& v);
    /**
     * Creates a deep copy of an array. Simple assignment (d4_array a=b;) generally
     * creates a shallow copy, so changing a(i,...) also changes b(i,...), which may
     * not be what is wanted.
     * 
     * @param v - the original d4_array
     * 
     * @return - the deep copy
     */
    d4_array copy(_CONST d4_array& v);
    /**
     * Creates a deep copy of an array. Simple assignment (d5_array a=b;) generally
     * creates a shallow copy, so changing a(i,...) also changes b(i,...), which may
     * not be what is wanted.
     * 
     * @param v - the original d5_array
     * 
     * @return - the deep copy
     */
    d5_array copy(_CONST d5_array& v);
    /**
     * Creates a deep copy of an array. Simple assignment (d6_array a=b;) generally
     * creates a shallow copy, so changing a(i,...) also changes b(i,...), which may
     * not be what is wanted.
     * 
     * @param v - the original d6_array
     * 
     * @return - the deep copy
     */
    d6_array copy(_CONST d6_array& v);
    /**
     * Creates a deep copy of an array. Simple assignment (d7_array a=b;) generally
     * creates a shallow copy, so changing a(i,...) also changes b(i,...), which may
     * not be what is wanted.
     * 
     * @param v - the original d7_array
     * 
     * @return - the deep copy
     */
    d7_array copy(_CONST d7_array& v);
    /**
     * Creates a deep copy of a vector. Simple assignment (dvar_vector a=b;) generally
     * creates a shallow copy, so changing a(i) also changes b(i), which may
     * not be what is wanted.
     * 
     * @param v - the original dvar_vector
     * 
     * @return - the deep copy
     */
    dvar_vector copy(_CONST dvar_vector& v);
    /**
     * Creates a deep copy of a matrix. Simple assignment (dvar_matrix a=b;) generally
     * creates a shallow copy, so changing a(i,...) also changes b(i,...), which may
     * not be what is wanted.
     * 
     * @param v - the original dvar_matrix
     * 
     * @return - the deep copy
     */
    dvar_matrix copy(_CONST dvar_matrix& v);
    /**
     * Creates a deep copy of an array. Simple assignment (dvar3_array a=b;) generally
     * creates a shallow copy, so changing a(i,...) also changes b(i,...), which may
     * not be what is wanted.
     * 
     * @param v - the original dvar3_array
     * 
     * @return - the deep copy
     */
    dvar3_array copy(_CONST dvar3_array& v);
    /**
     * Creates a deep copy of an array. Simple assignment (dvar4_array a=b;) generally
     * creates a shallow copy, so changing a(i,...) also changes b(i,...), which may
     * not be what is wanted.
     * 
     * @param v - the original dvar4_array
     * 
     * @return - the deep copy
     */
    dvar4_array copy(_CONST dvar4_array& v);
    /**
     * Creates a deep copy of an array. Simple assignment (dvar5_array a=b;) generally
     * creates a shallow copy, so changing a(i,...) also changes b(i,...), which may
     * not be what is wanted.
     * 
     * @param v - the original dvar5_array
     * 
     * @return - the deep copy
     */
    dvar5_array copy(_CONST dvar5_array& v);
    /**
     * Creates a deep copy of an array. Simple assignment (dvar6_array a=b;) generally
     * creates a shallow copy, so changing a(i,...) also changes b(i,...), which may
     * not be what is wanted.
     * 
     * @param v - the original dvar6_array
     * 
     * @return - the deep copy
     */
    dvar6_array copy(_CONST dvar6_array& v);
    /**
     * Creates a deep copy of an array. Simple assignment (dvar7_array a=b;) generally
     * creates a shallow copy, so changing a(i,...) also changes b(i,...), which may
     * not be what is wanted.
     * 
     * @param v - the original dvar7_array
     * 
     * @return - the deep copy
     */
    dvar7_array copy(_CONST dvar7_array& v);

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
    int testEquals(_CONST ivector& i1, _CONST ivector& i2);

    /*************************************************
    * name      : getBounds                          *
    * purpose   : return min, max indices for array  *
    *************************************************/
    ivector getBounds(_CONST  prevariable& o);
    ivector getBounds(_CONST  ivector& o);
    ivector getBounds(_CONST  imatrix& o);
    ivector getBounds(_CONST  dvector& o);
    ivector getBounds(_CONST  dmatrix& o);
    ivector getBounds(_CONST  d3_array& o);
    ivector getBounds(_CONST  d4_array& o);
    ivector getBounds(_CONST  d5_array& o);
    ivector getBounds(_CONST  d6_array& o);
    ivector getBounds(_CONST  d7_array& o);
    ivector getBounds(_CONST  dvar_vector& o);
    ivector getBounds(_CONST  dvar_matrix& o);
    ivector getBounds(_CONST  dvar3_array& o);
    ivector getBounds(_CONST  dvar4_array& o);
    ivector getBounds(_CONST  dvar5_array& o);
    ivector getBounds(_CONST  dvar6_array& o);
    ivector getBounds(_CONST  dvar7_array& o);
    
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
    ivector getIndexVector(_CONST dvector& o);
    ivector getIndexVector(_CONST dvar_vector& o);

    /*************************************************
    * name      : length                             *
    * purpose   : return number of elements in array *
    *************************************************/
    int length(_CONST  ivector& o);
    int length(_CONST  imatrix& o);
    int length(_CONST  dvector& o);
    int length(_CONST  dmatrix& o);
    int length(_CONST  dvar_vector& o);
    int length(_CONST  dvar_matrix& o);

    /*************************************************
    * name      : value                              *
    * purpose   : return _CONSTant version of array   *
    *************************************************/
    //-------------------------------------------------------------
    d4_array value(_CONST  dvar4_array& o);
    d5_array value(_CONST  dvar5_array& o);
    d6_array value(_CONST  dvar6_array& o);
    d7_array value(_CONST  dvar7_array& o);

    //delta function    
    int deltafcn(int i, int j);

    /***********************************************************
     * Test if at least one of a set of parameters is          *
     * being estimated in the current phase.                   *
    ***********************************************************/
    bool isActive(_CONST param_init_number& p);
    bool isActive(_CONST param_init_vector& p);
    bool isActive(param_init_number_vector& p);
    bool isActive(param_init_vector_vector& p);

    /********************************************
    * name      : variance                      *
    * purpose   : compute variance of object    *
    ********************************************/
    double variance(_CONST dvector & v);
    dvariable variance(_CONST dvar_vector & v);
} //namespace wts
#endif
