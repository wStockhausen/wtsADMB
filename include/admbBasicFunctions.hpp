// admbFunctions.hpp
// file contains some general ADMB functions
#pragma once
#ifndef ADMBFUNCTIONS_HPP
    #define ADMBFUNCTIONS_HPP

    extern int debugADMBFunctions;
namespace wts{

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
    * purpose   : return _CONST ant version of array   *
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