/* 
 * File:   admbStringFunctions.hpp
 * Author: william.stockhausen
 *
 * Created on November 26, 2013, 12:34 PM
 */

#ifndef ADMBSTRINGFUNCTIONS_HPP
#define	ADMBSTRINGFUNCTIONS_HPP

#include <admodel.h>

using namespace std;

namespace wts{
    /**
     * Convert adstring_array to string of quoted, comma-separated values. Individual
     * array elements are single-quoted.
     * 
     * @param v - adstring_array to convert to quoted csv string
     * @return  - the quoted csv string 
     */
    adstring to_qcsv(_CONST adstring_array& v);
    
    /**
     * Convert ivector to string of quoted, comma-separated values. Individual
     * array elements are single-quoted.
     * 
     * @param v - vector to convert to quoted csv string
     * @return  - the quoted csv string 
     */
    adstring to_qcsv(_CONST ivector& v);
    
    /**
     * Convert dvector to string of quoted, comma-separated values. Individual
     * array elements are single-quoted.
     * 
     * @param v - vector to convert to quoted csv string
     * @return  - the quoted csv string 
     */
    adstring to_qcsv(_CONST dvector& v);
    
    /**
     * Find index in adstring_array matching a test string.
     * 
     * @param s - test string to locate
     * @param v - adstring_array in which to locate s
     * @return - index in v corresponding to string matching s
     */
    int which(adstring& s, adstring_array& v);
    int which(const char * s, adstring_array& v);

    /****************************************************************
    * name      : adstring_matrix                                   *
    * purpose   : functionality for (possibly ragged) matrix of     *
    *               of adstrings                                    *
    ****************************************************************/
    class adstring_matrix {
        public:
            static bool debug;
        protected:
            int nAAs;      //number of "rows"
            int idxmn;     //min (row) index
            ivector clmns; //min column indices
            ivector clmxs; //max column indices
            adstring_array** ppAAs;
        protected:
            void allocate(int rwmn, int rwmx);
        public:
            adstring_matrix();
            adstring_matrix(int rwmn, int rwmx, int clmn, int clmx);
            adstring_matrix(int rwmn, int rwmx, int clmn, ivector& clmxs);
            adstring_matrix(int rwmn, int rwmx, ivector& clmns, int clmx);
            adstring_matrix(int rwmn, int rwmx, ivector& clmns, ivector& clmxs);
            ~adstring_matrix(){deallocate();}
            bool allocated(){return (ppAAs!=0);}
            bool allocated(int rw){if ((ppAAs)&&(idxmn<=rw)&&(rw-idxmn<nAAs)){return (ppAAs[rw-idxmn]!=0);} return false;}
            void allocate(int rwmn, int rwmx, int clmn, int clmx);
            void allocate(int rwmn, int rwmx, ivector& clmns, int clmx);
            void allocate(int rwmn, int rwmx, int clmn, ivector& clmxs);
            void allocate(int rwmn, int rwmx, ivector& clmns, ivector& clmxs);
            void deallocate(void);
            adstring& operator() (_CONST int i, _CONST int j);
            adstring_array& operator() (_CONST int i);
            adstring_array& operator[] (_CONST int i);
            int indexmin(){return idxmn;}
            int indexmax(){return idxmn+nAAs;}
            int size(){return nAAs;}
            void to_lower(){for (int i=0;i<nAAs;i++) (*ppAAs[i]).to_lower();}
            void read(cifstream & is);
            void write(ostream & os);
            friend cifstream & operator>> (cifstream & is, adstring_matrix & obj){obj.read(is); return is;}
            friend ostream & operator<< (ostream & os, adstring_matrix & obj){obj.write(os); return os;}
    };

    /****************************************************************
    * name      : CompareAdstrings                                  *
    * purpose   : Class with member function to determine if        *
    *               lhs < rhs for input adstrings lhs, rhs          *
    ****************************************************************/
    class CompareAdstrings {
        public:
            static bool debug;
            bool operator() (_CONST adstring& lhs, _CONST adstring& rhs) const;
    };
}

#endif	/* ADMBSTRINGFUNCTIONS_HPP */

