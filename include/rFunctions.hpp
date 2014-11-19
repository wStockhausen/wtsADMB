// rFunctions.hpp
// This file has C++ functions for use in writing R-compatible data output.
// WTS 2005-04: adapted from mhp-s-funcs.cpp by Michael Prager  -- December, 2002
#pragma once
#ifndef __HPP_RFUNCTIONS__
#define __HPP_RFUNCTIONS__

using namespace std;

namespace wts{
    namespace Rpr{
        /**
         * ADMB FUNCTION to write a matrix as part of an array structure.
         * @param os - stream for output file.
         * @param xx - matrix of data to be written.
         * @return - dims for writing the matrix to an array structure.
         */
        adstring writeDataToR(ostream& os, _CONST imatrix& xx);
        /**
         * ADMB FUNCTION to write a matrix as part of an R list.
         * @param os - stream for output file.
         * @param xx - matrix of data to be written.
         * @param dimnames - adstring with dimnames.
         */
         void writeToR(ostream& os, _CONST imatrix& xx, adstring dimnames);
        /**
         * ADMB FUNCTION to write a matrix as part of an array structure.
         * @param os - stream for output file.
         * @param xx - matrix of data to be written.
         * @return - dims for writing the matrix to an array structure.
         */
        adstring writeDataToR(ostream& os, _CONST dmatrix& xx);
        /**
         * ADMB FUNCTION to write a matrix as part of an R list.
         * @param os - stream for output file.
         * @param xx - matrix of data to be written.
         * @param dimnames - adstring with dimnames.
         */
        void writeToR(ostream& os, _CONST dmatrix& xx, adstring dimnames);
        //===========================================================================================
        // ADMB FUNCTION to write a d3_array as part of an array structure
        // ----------Arguments----------
        // os   stream for output file.
        // xx   d3_array to be written.
        // ----------Value--------------
        // dim  dims for writing the matrix to an array structure
        adstring writeDataToR(ostream& os, _CONST d3_array& xx);    
        //===========================================================================================
        // ADMB FUNCTION to write a d3_array as part of an R list
        // ----------Arguments----------
        // os       stream for output file.
        // xx       d3_array to be written.
        // dimnames adstring with dimnames.
        void writeToR(ostream& os, _CONST d3_array& xx, adstring dimnames);

        //===========================================================================================
        // ADMB FUNCTION to write a d4_array as part of an array structure
        // ----------Arguments----------
        // os   stream for output file.
        // xx   d4_array to be written.
        // ----------Value--------------
        // dim    dims for writing the d4_array to an array structure
        adstring writeDataToR(ostream& os, _CONST d4_array& xx);
        
        //===========================================================================================
        // ADMB FUNCTION to write a d4_array as part of an R list
        // ----------Arguments----------
        // os       stream for output file.
        // xx       d4_array to be written.
        // dimnames adstring with dimnames.
        void writeToR(ostream& os, _CONST d4_array& xx, adstring dimnames);
        
        /***********************************************************
         * ADMB FUNCTION to write a d5_array to stream as part of an R array structure.
         * 
         * @param os - stream for output file.
         * @param xx - d5_array to be written.
         * @return - dims for completing the writing the d5_array as an array structure
         */
        adstring writeDataToR(ostream& os, _CONST d5_array& xx);

        /***********************************************************
         * ADMB FUNCTION to write a d5_array to stream as an R array.
         * 
         * @param os - stream for output file.
         * @param xx - d5_array to be written.
         * @param dimnames - adstring with dimnames.
         */
        void writeToR(ostream& os, _CONST d5_array& xx, adstring dimnames);
        
        /***********************************************************
         * ADMB FUNCTION to write a d6_array as part of an R array structure
         * @param os - stream for output file.
         * @param xx - d6_array to be written.
         * @return - dims for completing the writing the d5_array as an array structure
         */
        adstring writeDataToR(ostream& os, _CONST d6_array& xx);

        /***********************************************************
         * ADMB FUNCTION to write a d6_array as part of an R list.
         * @param os - stream for output file.
         * @param xx - d6_array to be written.
         * @param dimnames - adstring with dimnames.
         */
        void writeToR(ostream& os, _CONST d6_array& xx, adstring dimnames);
        
        /***********************************************************
         * ADMB FUNCTION to write a d7_array as part of an R array structure
         * @param os - stream for output file.
         * @param xx - d7_array to be written.
         * @return - dims for completing the writing the d7_array as an array structure
         */
        adstring writeDataToR(ostream& os, _CONST d7_array& xx);

        /***********************************************************
         * ADMB FUNCTION to write a d7_array as part of an R list.
         * @param os - stream for output file.
         * @param xx - d7_array to be written.
         * @param dimnames - adstring with dimnames.
         */
        void writeToR(ostream& os, _CONST d7_array& xx, adstring dimnames);
    }//namespace Rpr

    /*********************************************************
     * ADMB FUNCTION to write an adstring_array to file as an R character vector
     * @param os - stream for output file.
     * @param xx - adstring_array to be written.
     */
    void writeToR(ostream& os, _CONST adstring_array& xx);
    /********************************************************
     * ADMB FUNCTION to write an ivector to file as an R vector
     * @param os - stream for output file.
     * @param xx - ivector to be written.
     */
    void writeToR(ostream& os, _CONST ivector& xx);
    /**
     * ADMB FUNCTION to write a matrix as part of an R list.
     * @param os - stream for output file.
     * @param xx - matrix of data to be written.
     */
    void writeToR(ostream& os, _CONST imatrix& xx);
    /**
     * ADMB FUNCTION to write a matrix as part of an R list.
     * @param os - stream for output file.
     * @param xx - matrix of data to be written.
     * @param colnames - comma-delimited, single-quoted string of column names
     */
    void writeToR(ostream& os, _CONST imatrix& xx, adstring colnames);
    /**
     * ADMB FUNCTION to write a matrix as part of an R list.
     * @param os - stream for output file.
     * @param xx - matrix of data to be written.
     * @param n1 - comma-delimited, single-quoted string of names for 1st (leftmost) index
     * @param n2 - comma-delimited, single-quoted string of names for 2nd index
     */
    void writeToR(ostream& os, _CONST imatrix& xx, adstring n1, adstring n2);
    /********************************************************
     * ADMB FUNCTION to write a dvector to file as an R vector
     * @param os - stream for output file.
     * @param xx - dvector to be written.
     */
    void writeToR(ostream& os, _CONST dvector& xx);
    /********************************************************
     * ADMB FUNCTION to write a dvector to file as an R vector
     * @param os    - stream for output file.
     * @param xx    - dvector to be written.
     * @param names - adstring to be written as names for R structure 
     *                (comma-delimited, quoted if necessary)
     */
    void writeToR(ostream& os, _CONST dvector& xx, adstring names);
    /********************************************************
     * ADMB FUNCTION to write a dvector to file as an R vector
     * @param os    - stream for output file.
     * @param xx    - dvector to be written.
     * @param names - adstring_array to be written as names for R structure 
     */
    void writeToR(ostream& os, _CONST dvector& xx, adstring_array names);
    /**
     * ADMB FUNCTION to write a matrix as part of an R list.
     * @param os - stream for output file.
     * @param xx - matrix of data to be written.
     */
    void writeToR(ostream& os, _CONST dmatrix& xx);
    /**
     * ADMB FUNCTION to write a matrix as part of an R list.
     * @param os - stream for output file.
     * @param xx - matrix of data to be written.
     * @param colnames - comma-delimited, single-quoted string of column names
     */
    void writeToR(ostream& os, _CONST dmatrix& xx, adstring colnames);
    /**
     * ADMB FUNCTION to write a matrix as part of an R list.
     * @param os - stream for output file.
     * @param xx - matrix of data to be written.
     * @param n1 - comma-delimited, single-quoted string of names for 1st (leftmost) index
     * @param n2 - comma-delimited, single-quoted string of names for 2nd index
     */
    void writeToR(ostream& os, _CONST dmatrix& xx, adstring n1, adstring n2);
//    //===========================================================================================
//    // ADMB FUNCTION to write a matrix as part of an R list
//    // ----------Arguments----------
//    // os  stream for output file.
//    // xx  matrix of data to be written.
//    // n1  ivector to use as names for 1st (leftmost; row) index
//    // n2  comma-delimited, single-quoted string of names for 2nd (column) index
//    void writeToR(ostream& os, _CONST dmatrix& xx, _CONST ivector& n1, adstring n2);
    //===========================================================================================
    // ADMB FUNCTION to write a d3_array as part of an R list
    // ----------Arguments----------
    // os  stream for output file.
    // xx  data to be written.
    // n1  comma-delimited, single-quoted string of names for 1st (leftmost) index
    // n2  comma-delimited, single-quoted string of names for 2nd index
    // n3  comma-delimited, single-quoted string of names for 3rd index
    void writeToR(ostream& os, _CONST d3_array& xx, adstring n1, adstring n2, adstring n3);
    //===========================================================================================
    // ADMB FUNCTION to write a d4_array as part of an R list
    // ----------Arguments----------
    // os  stream for output file.
    // xx  data to be written.
    // n1  comma-delimited, single-quoted string of names for 1st (leftmost) index
    // n2  comma-delimited, single-quoted string of names for 2nd index
    // n3  comma-delimited, single-quoted string of names for 3rd index
    // n4  comma-delimited, single-quoted string of names for 4th index
    void writeToR(ostream& os, _CONST d4_array& xx, adstring n1, adstring n2, adstring n3, adstring n4);
    /****************************************************************
     * ADMB FUNCTION to write a d5_array to stream as an R structure.
     * 
     * @param os - stream for output file.
     * @param xx - data to be written.
     * @param n1 - comma-delimited, single-quoted string of names for 1st (leftmost) index
     * @param n2 - comma-delimited, single-quoted string of names for 2nd index
     * @param n3 - comma-delimited, single-quoted string of names for 3rd index
     * @param n4 - comma-delimited, single-quoted string of names for 4th index
     * @param n5 - comma-delimited, single-quoted string of names for 5th index
     */
    void writeToR(ostream& os, _CONST d5_array& xx, adstring n1, adstring n2, adstring n3, adstring n4, adstring n5);
    /****************************************************************
     * ADMB FUNCTION to write a d6_array to stream as an R structure.
     * 
     * @param os - stream for output file.
     * @param xx - data to be written.
     * @param n1 - comma-delimited, single-quoted string of names for 1st (leftmost) index
     * @param n2 - comma-delimited, single-quoted string of names for 2nd index
     * @param n3 - comma-delimited, single-quoted string of names for 3rd index
     * @param n4 - comma-delimited, single-quoted string of names for 4th index
     * @param n5 - comma-delimited, single-quoted string of names for 5th index
     * @param n5 - comma-delimited, single-quoted string of names for 6th index
     */
    void writeToR(ostream& os, _CONST d6_array& xx, adstring n1, adstring n2, adstring n3, adstring n4, adstring n5, adstring n6);
    /****************************************************************
     * ADMB FUNCTION to write a d7_array to stream as an R structure.
     * 
     * @param os - stream for output file.
     * @param xx - data to be written.
     * @param n1 - comma-delimited, single-quoted string of names for 1st (leftmost) index
     * @param n2 - comma-delimited, single-quoted string of names for 2nd index
     * @param n3 - comma-delimited, single-quoted string of names for 3rd index
     * @param n4 - comma-delimited, single-quoted string of names for 4th index
     * @param n5 - comma-delimited, single-quoted string of names for 5th index
     * @param n6 - comma-delimited, single-quoted string of names for 6th index
     * @param n7 - comma-delimited, single-quoted string of names for 67th index
     */
    void writeToR(ostream& os, _CONST d7_array& xx, adstring n1, adstring n2, adstring n3, adstring n4, adstring n5, adstring n6, adstring n7);
} //namespace wts
#endif
