// rFunctions.cpp
// This file has C++ functions for use in writing R-compatible data output.
// WTS 2005-04: adapted from mhp-s-funcs.cpp by Michael Prager  -- December, 2002
#include <admodel.h>
#include <iostream>
#include "wtsConsts.hpp"
#include "admbBasicFunctions.hpp"
#include "admbStringFunctions.hpp"
#include "rFunctions.hpp"
using namespace std;
/**
 * Changes:
 * 2014-12-03: 1. Changed to using std namespace
 * 2015-03-02: 1. Added wts::Rpr::writeDataToR(...) functions for dvector
 * 2019-06-05: 1. Added wts::Rpr::writeDataToR(...) functions for ivector
 *             2. Revised wts::writeToR(...) functions for dvector and ivector
 *                  to write 100 or fewer entries per text line.
*/

/***********************************************************
 * ADMB FUNCTION to write a ivector as part of an R array structure.
 * @param os - stream for output file.
 * @param xx - ivector of data to be written.
 * @return - dims for writing the ivector to an R array structure.
 */
adstring wts::Rpr::writeDataToR(ostream& os, const ivector& xx){
    ivector bds = wts::getBounds(xx);
    int ctr = 1;
    for (int i=bds(1);i<bds(2);i++)  {
        os<<xx(i)<<cc;
        if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
    }
    os<<xx(bds(2));
    adstring dim = str(bds(2)-bds(1)+1);
    return dim;
}

/***********************************************************
 * ADMB FUNCTION to write an imatrix as part of an array structure.
 * @param os - stream for output file.
 * @param xx - imatrix of data to be written.
 * @return - dims for writing the matrix to an array structure.
 */
adstring wts::Rpr::writeDataToR(ostream& os, const imatrix& xx){
    ivector bds = wts::getBounds(xx);
    int ctr = 1;
    for (int j=bds(3);j<bds(4);j++) {
        for (int i=bds(1);i<=bds(2);i++)  {
            os<<xx(i,j)<<cc;
            if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
        }
    }
    for (int i=bds(1);i<bds(2);i++)  {
        os<<xx(i,bds(4))<<cc;
        if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
    }
    os<<xx(bds(2),bds(4));
    adstring dim = str(bds(2)-bds(1)+1)+cc+
                   str(bds(4)-bds(3)+1);
    return dim;
}
/***********************************************************
 * ADMB FUNCTION to write an imatrix as part of an R list.
 * @param os - stream for output file.
 * @param xx - matrix of data to be written.
 * @param dimnames - adstring with dimnames.
 */
void wts::Rpr::writeToR(ostream& os, const imatrix& xx, adstring dimnames){
    os<<"structure(c(";
    adstring dims = Rpr::writeDataToR(os,xx);
    os<<"),"<<endl<<tb<<tb;    
    os<<"dimnames=list("<<dimnames<<"),";
    os<<"dim=c("<<dims<<"))";
}

/***********************************************************
 * ADMB FUNCTION to write a dvector as part of an R array structure.
 * @param os - stream for output file.
 * @param xx - dvector of data to be written.
 * @return - dims for writing the dvector to an R array structure.
 */
adstring wts::Rpr::writeDataToR(ostream& os, const dvector& xx){
    ivector bds = wts::getBounds(xx);
    int ctr = 1;
    for (int i=bds(1);i<bds(2);i++)  {
        os<<xx(i)<<cc;
        if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
    }
    os<<xx(bds(2));
    adstring dim = str(bds(2)-bds(1)+1);
    return dim;
}

/***********************************************************
 * ADMB FUNCTION to write a dvector as an R array structure.
 * @param os - stream for output file.
 * @param xx - dvector of data to be written.
 * @param dimnames - adstring with dimnames.
 */
void wts::Rpr::writeToR(ostream& os, const dvector& xx, adstring dimnames){
    os<<"structure(c(";
    adstring dims = Rpr::writeDataToR(os,xx);
    os<<"),"<<endl<<tb<<tb;    
    os<<"dimnames=list("<<dimnames<<"),";
    os<<"dim=c("<<dims<<"))";
}

/***********************************************************
 * ADMB FUNCTION to write a dmatrix as an R array structure.
 * @param os - stream for output file.
 * @param xx - dmatrix of data to be written.
 * @return - dims for writing the dmatrix to an R array structure.
 */
adstring wts::Rpr::writeDataToR(ostream& os, const dmatrix& xx){
    ivector bds = wts::getBounds(xx);
    int ctr = 1;
    for (int j=bds(3);j<bds(4);j++) {
        for (int i=bds(1);i<=bds(2);i++)  {
            os<<xx(i,j)<<cc;
            if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
        }
    }
    for (int i=bds(1);i<bds(2);i++)  {
        os<<xx(i,bds(4))<<cc;
        if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
    }
    os<<xx(bds(2),bds(4));
    adstring dim = str(bds(2)-bds(1)+1)+cc+
                   str(bds(4)-bds(3)+1);
    return dim;
}

/***********************************************************
 * ADMB FUNCTION to write a dmatrix as an R array structure.
 * @param os - stream for output file.
 * @param xx - dmatrix of data to be written.
 * @param dimnames - adstring with dimnames.
 */
void wts::Rpr::writeToR(ostream& os, const dmatrix& xx, adstring dimnames){
    os<<"structure(c(";
    adstring dims = Rpr::writeDataToR(os,xx);
    os<<"),"<<endl<<tb<<tb;    
    os<<"dimnames=list("<<dimnames<<"),";
    os<<"dim=c("<<dims<<"))";
}

/***********************************************************
 * ADMB FUNCTION to write a d3_array to stream as part of an R array structure.
 * 
 * @param os - stream for output file.
 * @param xx - d3_array to be written.
 * @return - dims for completing the writing the d3_array as an array structure
 */
adstring wts::Rpr::writeDataToR(ostream& os, const d3_array& xx){
    ivector bds = wts::getBounds(xx);
    int ctr = 1;
    for (int k=bds(5);k<bds(6);k++) {
        for (int j=bds(3);j<=bds(4);j++) {
            for (int i=bds(1);i<=bds(2);i++)  {
                os<<xx(i,j,k)<<cc;
                if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
            }
        }
    }
    for (int j=bds(3);j<bds(4);j++) {
        for (int i=bds(1);i<=bds(2);i++)  {
            os<<xx(i,j,bds(6))<<cc;
            if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
        }
    }
    for (int i=bds(1);i<bds(2);i++)  {
        os<<xx(i,bds(4),bds(6))<<cc;
        if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
    }            
    os<<xx(bds(2),bds(4),bds(6));
    adstring dim = str(bds(2)-bds(1)+1)+cc+
                   str(bds(4)-bds(3)+1)+cc+
                   str(bds(6)-bds(5)+1);
    return dim;
}
/***********************************************************
 * ADMB FUNCTION to write a dvar3_array to stream as part of an R array structure.
 * 
 * @param os - stream for output file.
 * @param xx - dvar3_array to be written.
 * @return - dims for completing the writing the d3_array as an array structure
 */
adstring wts::Rpr::writeDataToR(ostream& os, const dvar3_array& xx){
    ivector bds = wts::getBounds(xx);
    int ctr = 1;
    for (int k=bds(5);k<bds(6);k++) {
        for (int j=bds(3);j<=bds(4);j++) {
            for (int i=bds(1);i<=bds(2);i++)  {
                os<<value(xx(i,j,k))<<cc;
                if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
            }
        }
    }
    for (int j=bds(3);j<bds(4);j++) {
        for (int i=bds(1);i<=bds(2);i++)  {
            os<<value(xx(i,j,bds(6)))<<cc;
            if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
        }
    }
    for (int i=bds(1);i<bds(2);i++)  {
        os<<value(xx(i,bds(4),bds(6)))<<cc;
        if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
    }            
    os<<value(xx(bds(2),bds(4),bds(6)));
    adstring dim = str(bds(2)-bds(1)+1)+cc+
                   str(bds(4)-bds(3)+1)+cc+
                   str(bds(6)-bds(5)+1);
    return dim;
}

/***********************************************************
 * ADMB FUNCTION to write a d3_array to stream as an R array.
 * 
 * @param os - stream for output file.
 * @param xx - d3_array to be written.
 * @param dimnames - adstring with dimnames.
 */
void wts::Rpr::writeToR(ostream& os, const d3_array& xx, adstring dimnames){
    os<<"structure(c(";
    adstring dims = wts::Rpr::writeDataToR(os,xx);
    os<<"),"<<endl<<tb<<tb;    
    os<<"dimnames=list("<<dimnames<<"),";
    os<<"dim=c("<<dims<<"))";
}
/***********************************************************
 * ADMB FUNCTION to write a dvar3_array to stream as an R array.
 * 
 * @param os - stream for output file.
 * @param xx - dvar3_array to be written.
 * @param dimnames - adstring with dimnames.
 */
void wts::Rpr::writeToR(ostream& os, const dvar3_array& xx, adstring dimnames){
    os<<"structure(c(";
    adstring dims = wts::Rpr::writeDataToR(os,xx);
    os<<"),"<<endl<<tb<<tb;    
    os<<"dimnames=list("<<dimnames<<"),";
    os<<"dim=c("<<dims<<"))";
}

/***********************************************************
 * ADMB FUNCTION to write a d4_array to stream as part of an R array structure.
 * 
 * @param os - stream for output file.
 * @param xx - d4_array to be written.
 * @return - dims for completing the writing the d4_array as an array structure
 */
adstring wts::Rpr::writeDataToR(ostream& os, const d4_array& xx){
    ivector bds = wts::getBounds(xx);
    int ctr = 1;
    for (int l=bds(7);l<bds(8);l++) {
        for (int k=bds(5);k<=bds(6);k++) {
            for (int j=bds(3);j<=bds(4);j++) {
                for (int i=bds(1);i<=bds(2);i++)  {
                    os<<xx(i,j,k,l)<<cc;
                    if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
                }
            }
        }
    }
    for (int k=bds(5);k<bds(6);k++) {
        for (int j=bds(3);j<=bds(4);j++) {
            for (int i=bds(1);i<=bds(2);i++)  {
                os<<xx(i,j,k,bds(8))<<cc;
                if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
            }
        }
    }
    for (int j=bds(3);j<bds(4);j++) {
        for (int i=bds(1);i<=bds(2);i++)  {
            os<<xx(i,j,bds(6),bds(8))<<cc;
            if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
        }
    }
    for (int i=bds(1);i<bds(2);i++)  {
        os<<xx(i,bds(4),bds(6),bds(8))<<cc;
        if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
    }            
    os<<xx(bds(2),bds(4),bds(6),bds(8));
    adstring dim = str(bds(2)-bds(1)+1)+cc+
                   str(bds(4)-bds(3)+1)+cc+
                   str(bds(6)-bds(5)+1)+cc+
                   str(bds(8)-bds(7)+1);
    return dim;
}
/***********************************************************
 * ADMB FUNCTION to write a dvar4_array to stream as part of an R array structure.
 * 
 * @param os - stream for output file.
 * @param xx - d4_array to be written.
 * @return - dims for completing the writing the d4_array as an array structure
 */
adstring wts::Rpr::writeDataToR(ostream& os, const dvar4_array& xx){
    ivector bds = wts::getBounds(xx);
    int ctr = 1;
    for (int l=bds(7);l<bds(8);l++) {
        for (int k=bds(5);k<=bds(6);k++) {
            for (int j=bds(3);j<=bds(4);j++) {
                for (int i=bds(1);i<=bds(2);i++)  {
                    os<<value(xx(i,j,k,l))<<cc;
                    if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
                }
            }
        }
    }
    for (int k=bds(5);k<bds(6);k++) {
        for (int j=bds(3);j<=bds(4);j++) {
            for (int i=bds(1);i<=bds(2);i++)  {
                os<<value(xx(i,j,k,bds(8)))<<cc;
                if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
            }
        }
    }
    for (int j=bds(3);j<bds(4);j++) {
        for (int i=bds(1);i<=bds(2);i++)  {
            os<<value(xx(i,j,bds(6),bds(8)))<<cc;
            if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
        }
    }
    for (int i=bds(1);i<bds(2);i++)  {
        os<<value(xx(i,bds(4),bds(6),bds(8)))<<cc;
        if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
    }            
    os<<value(xx(bds(2),bds(4),bds(6),bds(8)));
    adstring dim = str(bds(2)-bds(1)+1)+cc+
                   str(bds(4)-bds(3)+1)+cc+
                   str(bds(6)-bds(5)+1)+cc+
                   str(bds(8)-bds(7)+1);
    return dim;
}

/***********************************************************
 * ADMB FUNCTION to write a d4_array to stream as an R array.
 * 
 * @param os - stream for output file.
 * @param xx - d4_array to be written.
 * @param dimnames - adstring with dimnames.
 */
void wts::Rpr::writeToR(ostream& os, const d4_array& xx, adstring dimnames){
    os<<"structure(c(";
    adstring dims = Rpr::writeDataToR(os,xx);
    os<<"),"<<endl<<tb<<tb;    
    os<<"dimnames=list("<<dimnames<<"),";
    os<<"dim=c("<<dims<<"))";
}
/***********************************************************
 * ADMB FUNCTION to write a dvar4_array to stream as an R array.
 * 
 * @param os - stream for output file.
 * @param xx - dvar4_array to be written.
 * @param dimnames - adstring with dimnames.
 */
void wts::Rpr::writeToR(ostream& os, const dvar4_array& xx, adstring dimnames){
    os<<"structure(c(";
    adstring dims = Rpr::writeDataToR(os,xx);
    os<<"),"<<endl<<tb<<tb;    
    os<<"dimnames=list("<<dimnames<<"),";
    os<<"dim=c("<<dims<<"))";
}

/***********************************************************
 * ADMB FUNCTION to write a d5_array to stream as part of an R array structure.
 * 
 * @param os - stream for output file.
 * @param xx - d5_array to be written.
 * @return - dims for completing the writing the d5_array as an array structure
 */
adstring wts::Rpr::writeDataToR(ostream& os, const d5_array& xx){
    ivector bds = wts::getBounds(xx);
    int ctr = 1;
    for (int m=bds(9);m<bds(10);m++) {
        for (int l=bds(7);l<=bds(8);l++) {
            for (int k=bds(5);k<=bds(6);k++) {
                for (int j=bds(3);j<=bds(4);j++) {
                    for (int i=bds(1);i<=bds(2);i++)  {
                        os<<xx(i,j,k,l,m)<<cc;
                        if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
                    }
                }
            }
        }
    }
    for (int l=bds(7);l<bds(8);l++) {
        for (int k=bds(5);k<=bds(6);k++) {
            for (int j=bds(3);j<=bds(4);j++) {
                for (int i=bds(1);i<=bds(2);i++)  {
                    os<<xx(i,j,k,l,bds(10))<<cc;
                    if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
                }
            }
        }
    }
    for (int k=bds(5);k<bds(6);k++) {
        for (int j=bds(3);j<=bds(4);j++) {
            for (int i=bds(1);i<=bds(2);i++)  {
                os<<xx(i,j,k,bds(8),bds(10))<<cc;
                if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
            }
        }
    }
    for (int j=bds(3);j<bds(4);j++) {
        for (int i=bds(1);i<=bds(2);i++)  {
            os<<xx(i,j,bds(6),bds(8),bds(10))<<cc;
            if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
        }
    }
    for (int i=bds(1);i<bds(2);i++)  {
        os<<xx(i,bds(4),bds(6),bds(8),bds(10))<<cc;
        if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
    }            
    os<<xx(bds(2),bds(4),bds(6),bds(8),bds(10));
    adstring dim = str(bds(2)-bds(1)+1)+cc+
                   str(bds(4)-bds(3)+1)+cc+
                   str(bds(6)-bds(5)+1)+cc+
                   str(bds(8)-bds(7)+1)+cc+
                   str(bds(10)-bds(9)+1);
    return dim;
}
/***********************************************************
 * ADMB FUNCTION to write a dvar5_array to stream as part of an R array structure.
 * 
 * @param os - stream for output file.
 * @param xx - dvar5_array to be written.
 * @return - dims for completing the writing the d5_array as an array structure
 */
adstring wts::Rpr::writeDataToR(ostream& os, const dvar5_array& xx){
    ivector bds = wts::getBounds(xx);
    int ctr = 1;
    for (int m=bds(9);m<bds(10);m++) {
        for (int l=bds(7);l<=bds(8);l++) {
            for (int k=bds(5);k<=bds(6);k++) {
                for (int j=bds(3);j<=bds(4);j++) {
                    for (int i=bds(1);i<=bds(2);i++)  {
                        os<<value(xx(i,j,k,l,m))<<cc;
                        if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
                    }
                }
            }
        }
    }
    for (int l=bds(7);l<bds(8);l++) {
        for (int k=bds(5);k<=bds(6);k++) {
            for (int j=bds(3);j<=bds(4);j++) {
                for (int i=bds(1);i<=bds(2);i++)  {
                    os<<value(xx(i,j,k,l,bds(10)))<<cc;
                    if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
                }
            }
        }
    }
    for (int k=bds(5);k<bds(6);k++) {
        for (int j=bds(3);j<=bds(4);j++) {
            for (int i=bds(1);i<=bds(2);i++)  {
                os<<value(xx(i,j,k,bds(8),bds(10)))<<cc;
                if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
            }
        }
    }
    for (int j=bds(3);j<bds(4);j++) {
        for (int i=bds(1);i<=bds(2);i++)  {
            os<<value(xx(i,j,bds(6),bds(8),bds(10)))<<cc;
            if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
        }
    }
    for (int i=bds(1);i<bds(2);i++)  {
        os<<value(xx(i,bds(4),bds(6),bds(8),bds(10)))<<cc;
        if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
    }            
    os<<value(xx(bds(2),bds(4),bds(6),bds(8),bds(10)));
    adstring dim = str(bds(2)-bds(1)+1)+cc+
                   str(bds(4)-bds(3)+1)+cc+
                   str(bds(6)-bds(5)+1)+cc+
                   str(bds(8)-bds(7)+1)+cc+
                   str(bds(10)-bds(9)+1);
    return dim;
}

/***********************************************************
 * ADMB FUNCTION to write a d5_array to stream as an R array.
 * 
 * @param os - stream for output file.
 * @param xx - d5_array to be written.
 * @param dimnames - adstring with dimnames.
 */
void wts::Rpr::writeToR(ostream& os, const d5_array& xx, adstring dimnames){
    os<<"structure(c(";
    adstring dims = Rpr::writeDataToR(os,xx);
    os<<"),"<<endl<<tb<<tb;    
    os<<"dimnames=list("<<dimnames<<"),";
    os<<"dim=c("<<dims<<"))";
}
/***********************************************************
 * ADMB FUNCTION to write a dvar5_array to stream as an R array.
 * 
 * @param os - stream for output file.
 * @param xx - dvar5_array to be written.
 * @param dimnames - adstring with dimnames.
 */
void wts::Rpr::writeToR(ostream& os, const dvar5_array& xx, adstring dimnames){
    os<<"structure(c(";
    adstring dims = Rpr::writeDataToR(os,xx);
    os<<"),"<<endl<<tb<<tb;    
    os<<"dimnames=list("<<dimnames<<"),";
    os<<"dim=c("<<dims<<"))";
}

/***********************************************************
 * ADMB FUNCTION to write a d6_array to stream as part of an R array structure.
 * 
 * @param os - stream for output file.
 * @param xx - d6_array to be written.
 * @return - dims for completing the writing the d6_array as an array structure
 */
adstring wts::Rpr::writeDataToR(ostream& os, const d6_array& xx){
    ivector bds = wts::getBounds(xx);
    int ctr = 1;
    for (int n=bds(11);n<bds(12);n++) {
        for (int m=bds(9);m<=bds(10);m++) {
            for (int l=bds(7);l<=bds(8);l++) {
                for (int k=bds(5);k<=bds(6);k++) {
                    for (int j=bds(3);j<=bds(4);j++) {
                        for (int i=bds(1);i<=bds(2);i++)  {
                            os<<xx(i,j,k,l,m,n)<<cc;
                            if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
                        }
                    }
                }
            }
        }
    }
    for (int m=bds(9);m<bds(10);m++) {
        for (int l=bds(7);l<=bds(8);l++) {
            for (int k=bds(5);k<=bds(6);k++) {
                for (int j=bds(3);j<=bds(4);j++) {
                    for (int i=bds(1);i<=bds(2);i++)  {
                        os<<xx(i,j,k,l,m,bds(12))<<cc;
                        if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
                    }
                }
            }
        }
    }
    for (int l=bds(7);l<bds(8);l++) {
        for (int k=bds(5);k<=bds(6);k++) {
            for (int j=bds(3);j<=bds(4);j++) {
                for (int i=bds(1);i<=bds(2);i++)  {
                    os<<xx(i,j,k,l,bds(10),bds(12))<<cc;
                    if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
                }
            }
        }
    }
    for (int k=bds(5);k<bds(6);k++) {
        for (int j=bds(3);j<=bds(4);j++) {
            for (int i=bds(1);i<=bds(2);i++)  {
                os<<xx(i,j,k,bds(8),bds(10),bds(12))<<cc;
                if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
            }
        }
    }
    for (int j=bds(3);j<bds(4);j++) {
        for (int i=bds(1);i<=bds(2);i++)  {
            os<<xx(i,j,bds(6),bds(8),bds(10),bds(12))<<cc;
            if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
        }
    }
    for (int i=bds(1);i<bds(2);i++)  {
        os<<xx(i,bds(4),bds(6),bds(8),bds(10),bds(12))<<cc;
        if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
    }            
    os<<xx(bds(2),bds(4),bds(6),bds(8),bds(10),bds(12));
    adstring dim = str( bds(2) -  bds(1)+1)+cc+
                   str( bds(4) -  bds(3)+1)+cc+
                   str( bds(6) -  bds(5)+1)+cc+
                   str( bds(8) -  bds(7)+1)+cc+
                   str(bds(10) -  bds(9)+1)+cc+
                   str(bds(12) - bds(11)+1);
    return dim;
}
/***********************************************************
 * ADMB FUNCTION to write a dvar6_array to stream as part of an R array structure.
 * 
 * @param os - stream for output file.
 * @param xx - dvar6_array to be written.
 * @return - dims for completing the writing the d6_array as an array structure
 */
adstring wts::Rpr::writeDataToR(ostream& os, const dvar6_array& xx){
    ivector bds = wts::getBounds(xx);
    int ctr = 1;
    for (int n=bds(11);n<bds(12);n++) {
        for (int m=bds(9);m<=bds(10);m++) {
            for (int l=bds(7);l<=bds(8);l++) {
                for (int k=bds(5);k<=bds(6);k++) {
                    for (int j=bds(3);j<=bds(4);j++) {
                        for (int i=bds(1);i<=bds(2);i++)  {
                            os<<value(xx(i,j,k,l,m,n))<<cc;
                            if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
                        }
                    }
                }
            }
        }
    }
    for (int m=bds(9);m<bds(10);m++) {
        for (int l=bds(7);l<=bds(8);l++) {
            for (int k=bds(5);k<=bds(6);k++) {
                for (int j=bds(3);j<=bds(4);j++) {
                    for (int i=bds(1);i<=bds(2);i++)  {
                        os<<value(xx(i,j,k,l,m,bds(12)))<<cc;
                        if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
                    }
                }
            }
        }
    }
    for (int l=bds(7);l<bds(8);l++) {
        for (int k=bds(5);k<=bds(6);k++) {
            for (int j=bds(3);j<=bds(4);j++) {
                for (int i=bds(1);i<=bds(2);i++)  {
                    os<<value(xx(i,j,k,l,bds(10),bds(12)))<<cc;
                    if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
                }
            }
        }
    }
    for (int k=bds(5);k<bds(6);k++) {
        for (int j=bds(3);j<=bds(4);j++) {
            for (int i=bds(1);i<=bds(2);i++)  {
                os<<value(xx(i,j,k,bds(8),bds(10),bds(12)))<<cc;
                if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
            }
        }
    }
    for (int j=bds(3);j<bds(4);j++) {
        for (int i=bds(1);i<=bds(2);i++)  {
            os<<value(xx(i,j,bds(6),bds(8),bds(10),bds(12)))<<cc;
            if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
        }
    }
    for (int i=bds(1);i<bds(2);i++)  {
        os<<value(xx(i,bds(4),bds(6),bds(8),bds(10),bds(12)))<<cc;
        if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
    }            
    os<<value(xx(bds(2),bds(4),bds(6),bds(8),bds(10),bds(12)));
    adstring dim = str( bds(2) -  bds(1)+1)+cc+
                   str( bds(4) -  bds(3)+1)+cc+
                   str( bds(6) -  bds(5)+1)+cc+
                   str( bds(8) -  bds(7)+1)+cc+
                   str(bds(10) -  bds(9)+1)+cc+
                   str(bds(12) - bds(11)+1);
    return dim;
}

/***********************************************************
 * ADMB FUNCTION to write a d6_array to stream as an R array.
 * 
 * @param os - stream for output file.
 * @param xx - d6_array to be written.
 * @param dimnames - adstring with dimnames.
 */
void wts::Rpr::writeToR(ostream& os, const d6_array& xx, adstring dimnames){
    os<<"structure(c(";
    adstring dims = Rpr::writeDataToR(os,xx);
    os<<"),"<<endl<<tb<<tb;    
    os<<"dimnames=list("<<dimnames<<"),";
    os<<"dim=c("<<dims<<"))";
}
/***********************************************************
 * ADMB FUNCTION to write a dvar6_array to stream as an R array.
 * 
 * @param os - stream for output file.
 * @param xx - dvar6_array to be written.
 * @param dimnames - adstring with dimnames.
 */
void wts::Rpr::writeToR(ostream& os, const dvar6_array& xx, adstring dimnames){
    os<<"structure(c(";
    adstring dims = Rpr::writeDataToR(os,xx);
    os<<"),"<<endl<<tb<<tb;    
    os<<"dimnames=list("<<dimnames<<"),";
    os<<"dim=c("<<dims<<"))";
}

/***********************************************************
 * ADMB FUNCTION to write a d7_array to stream as part of an R array structure.
 * 
 * @param os - stream for output file.
 * @param xx - d7_array to be written.
 * @return - dims to complete writing the d7_array as an array structure
 */
adstring wts::Rpr::writeDataToR(ostream& os, const d7_array& xx){
    ivector bds = wts::getBounds(xx);
    int ctr = 1;
    for (int o=bds(13);o<bds(14);o++) {
        for (int n=bds(11);n<=bds(12);n++) {
            for (int m=bds(9);m<=bds(10);m++) {
                for (int l=bds(7);l<=bds(8);l++) {
                    for (int k=bds(5);k<=bds(6);k++) {
                        for (int j=bds(3);j<=bds(4);j++) {
                            for (int i=bds(1);i<=bds(2);i++)  {
                                os<<xx(i,j,k,l,m,n,o)<<cc;
                                if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
                            }
                        }
                    }
                }
            }
        }
    }
    for (int n=bds(11);n<bds(12);n++) {
        for (int m=bds(9);m<=bds(10);m++) {
            for (int l=bds(7);l<=bds(8);l++) {
                for (int k=bds(5);k<=bds(6);k++) {
                    for (int j=bds(3);j<=bds(4);j++) {
                        for (int i=bds(1);i<=bds(2);i++)  {
                            os<<xx(i,j,k,l,m,n,bds(14))<<cc;
                            if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
                        }
                    }
                }
            }
        }
    }
    for (int m=bds(9);m<bds(10);m++) {
        for (int l=bds(7);l<=bds(8);l++) {
            for (int k=bds(5);k<=bds(6);k++) {
                for (int j=bds(3);j<=bds(4);j++) {
                    for (int i=bds(1);i<=bds(2);i++)  {
                        os<<xx(i,j,k,l,m,bds(12),bds(14))<<cc;
                        if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
                    }
                }
            }
        }
    }
    for (int l=bds(7);l<bds(8);l++) {
        for (int k=bds(5);k<=bds(6);k++) {
            for (int j=bds(3);j<=bds(4);j++) {
                for (int i=bds(1);i<=bds(2);i++)  {
                    os<<xx(i,j,k,l,bds(10),bds(12),bds(14))<<cc;
                    if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
                }
            }
        }
    }
    for (int k=bds(5);k<bds(6);k++) {
        for (int j=bds(3);j<=bds(4);j++) {
            for (int i=bds(1);i<=bds(2);i++)  {
                os<<xx(i,j,k,bds(8),bds(10),bds(12),bds(14))<<cc;
                if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
            }
        }
    }
    for (int j=bds(3);j<bds(4);j++) {
        for (int i=bds(1);i<=bds(2);i++)  {
            os<<xx(i,j,bds(6),bds(8),bds(10),bds(12),bds(14))<<cc;
            if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
        }
    }
    for (int i=bds(1);i<bds(2);i++)  {
        os<<xx(i,bds(4),bds(6),bds(8),bds(10),bds(12),bds(14))<<cc;
        if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
    }            
    os<<xx(bds(2),bds(4),bds(6),bds(8),bds(10),bds(12),bds(14));
    adstring dim = str( bds(2) -  bds(1)+1)+cc+
                   str( bds(4) -  bds(3)+1)+cc+
                   str( bds(6) -  bds(5)+1)+cc+
                   str( bds(8) -  bds(7)+1)+cc+
                   str(bds(10) -  bds(9)+1)+cc+
                   str(bds(12) - bds(11)+1)+cc+
                   str(bds(14) - bds(13)+1);
    return dim;
}
/***********************************************************
 * ADMB FUNCTION to write a dvar7_array to stream as part of an R array structure.
 * 
 * @param os - stream for output file.
 * @param xx - d7_array to be written.
 * @return - dims to complete writing the d7_array as an array structure
 */
adstring wts::Rpr::writeDataToR(ostream& os, const dvar7_array& xx){
    ivector bds = wts::getBounds(xx);
    int ctr = 1;
    for (int o=bds(13);o<bds(14);o++) {
        for (int n=bds(11);n<=bds(12);n++) {
            for (int m=bds(9);m<=bds(10);m++) {
                for (int l=bds(7);l<=bds(8);l++) {
                    for (int k=bds(5);k<=bds(6);k++) {
                        for (int j=bds(3);j<=bds(4);j++) {
                            for (int i=bds(1);i<=bds(2);i++)  {
                                os<<value(xx(i,j,k,l,m,n,o))<<cc;
                                if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
                            }
                        }
                    }
                }
            }
        }
    }
    for (int n=bds(11);n<bds(12);n++) {
        for (int m=bds(9);m<=bds(10);m++) {
            for (int l=bds(7);l<=bds(8);l++) {
                for (int k=bds(5);k<=bds(6);k++) {
                    for (int j=bds(3);j<=bds(4);j++) {
                        for (int i=bds(1);i<=bds(2);i++)  {
                            os<<value(xx(i,j,k,l,m,n,bds(14)))<<cc;
                            if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
                        }
                    }
                }
            }
        }
    }
    for (int m=bds(9);m<bds(10);m++) {
        for (int l=bds(7);l<=bds(8);l++) {
            for (int k=bds(5);k<=bds(6);k++) {
                for (int j=bds(3);j<=bds(4);j++) {
                    for (int i=bds(1);i<=bds(2);i++)  {
                        os<<value(xx(i,j,k,l,m,bds(12),bds(14)))<<cc;
                        if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
                    }
                }
            }
        }
    }
    for (int l=bds(7);l<bds(8);l++) {
        for (int k=bds(5);k<=bds(6);k++) {
            for (int j=bds(3);j<=bds(4);j++) {
                for (int i=bds(1);i<=bds(2);i++)  {
                    os<<value(xx(i,j,k,l,bds(10),bds(12),bds(14)))<<cc;
                    if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
                }
            }
        }
    }
    for (int k=bds(5);k<bds(6);k++) {
        for (int j=bds(3);j<=bds(4);j++) {
            for (int i=bds(1);i<=bds(2);i++)  {
                os<<value(xx(i,j,k,bds(8),bds(10),bds(12),bds(14)))<<cc;
                if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
            }
        }
    }
    for (int j=bds(3);j<bds(4);j++) {
        for (int i=bds(1);i<=bds(2);i++)  {
            os<<value(xx(i,j,bds(6),bds(8),bds(10),bds(12),bds(14)))<<cc;
            if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
        }
    }
    for (int i=bds(1);i<bds(2);i++)  {
        os<<value(xx(i,bds(4),bds(6),bds(8),bds(10),bds(12),bds(14)))<<cc;
        if (++ctr>100){os<<endl<<tb<<tb; ctr=0;}
    }            
    os<<value(xx(bds(2),bds(4),bds(6),bds(8),bds(10),bds(12),bds(14)));
    adstring dim = str( bds(2) -  bds(1)+1)+cc+
                   str( bds(4) -  bds(3)+1)+cc+
                   str( bds(6) -  bds(5)+1)+cc+
                   str( bds(8) -  bds(7)+1)+cc+
                   str(bds(10) -  bds(9)+1)+cc+
                   str(bds(12) - bds(11)+1)+cc+
                   str(bds(14) - bds(13)+1);
    return dim;
}

/***********************************************************
 * ADMB FUNCTION to write a d7_array to stream as an R array.
 * 
 * @param os - stream for output file.
 * @param xx - d7_array to be written.
 * @param dimnames - adstring with dimnames.
 */
void wts::Rpr::writeToR(ostream& os, const d7_array& xx, adstring dimnames){
    os<<"structure(c(";
    adstring dims = Rpr::writeDataToR(os,xx);
    os<<"),"<<endl<<tb<<tb;    
    os<<"dimnames=list("<<dimnames<<"),";
    os<<"dim=c("<<dims<<"))";
}
/***********************************************************
 * ADMB FUNCTION to write a dvar7_array to stream as an R array.
 * 
 * @param os - stream for output file.
 * @param xx - d7_array to be written.
 * @param dimnames - adstring with dimnames.
 */
void wts::Rpr::writeToR(ostream& os, const dvar7_array& xx, adstring dimnames){
    os<<"structure(c(";
    adstring dims = Rpr::writeDataToR(os,xx);
    os<<"),"<<endl<<tb<<tb;    
    os<<"dimnames=list("<<dimnames<<"),";
    os<<"dim=c("<<dims<<"))";
}

/********************************************************
 * ADMB FUNCTION to write an adstring_array to file as an R vector
 * @param os - stream for output file.
 * @param xx - adstring_array to be written.
 */
void wts::writeToR(ostream& os, const adstring_array& xx){
    int mn = xx.indexmin();
    int mx = xx.indexmax();
    os<<"structure(c(";
    for (int i=mn;i<mx;i++) os<<qt<<xx(i)<<qt<<cc;  os<<qt<<xx(mx)<<qt<<"),"<<endl<<tb<<tb;
    os<<"names="<<mn<<":"<<mx<<",dim=c("<<mx-mn+1<<"))";
}

/********************************************************
 * ADMB FUNCTION to write an ivector to file as an R vector
 * @param os - stream for output file.
 * @param xx - ivector to be written.
 */
void wts::writeToR(ostream& os, const ivector& xx){
    int mn = xx.indexmin();
    int mx = xx.indexmax();
    os<<"structure(c(";
//    for (int i=mn;i<mx;i++) os<<xx(i)<<cc;  os<<xx(mx)<<"),";
    wts::Rpr::writeDataToR(os,xx); os<<"),";
    os<<"names="<<mn<<":"<<mx<<",dim=c("<<mx-mn+1<<"))";
}

/********************************************************
 * ADMB FUNCTION to write a matrix as part of an R list.
 * @param os - stream for output file.
 * @param xx - matrix of data to be written.
 */
void wts::writeToR(ostream& os, const imatrix& xx){
    int mnI = xx.indexmin();
    int mxI = xx.indexmax();
    int mnJ = xx(mnI).indexmin();
    int mxJ = xx(mnJ).indexmax();
    adstring dimnames=str(mnI)+":"+str(mxI)+cc+str(mnJ)+":"+str(mxJ);
    wts::Rpr::writeToR(os,xx,dimnames);
}

/********************************************************
 * ADMB FUNCTION to write a matrix as part of an R list.
 * @param os - stream for output file.
 * @param xx - matrix of data to be written.
 * @param colnames - comma-delimited, single-quoted string of column names
 */
void wts::writeToR(ostream& os, const imatrix& xx, adstring colnames){
    int mnI = xx.indexmin();
    int mxI = xx.indexmax();
    adstring dimnames=str(mnI)+":"+str(mxI)+cc+"c("+colnames+")";
    wts::Rpr::writeToR(os,xx,dimnames);
}

/********************************************************
 * ADMB FUNCTION to write a matrix as part of an R list.
 * @param os - stream for output file.
 * @param xx - matrix of data to be written.
 * @param n1 - comma-delimited, single-quoted string of names for 1st (leftmost) index
 * @param n2 - comma-delimited, single-quoted string of names for 2nd index
 */
void wts::writeToR(ostream& os, const imatrix& xx, adstring n1, adstring n2){
    adstring dimnames=n1+cc+n2;
    wts::Rpr::writeToR(os,xx,dimnames);
}
/********************************************************
 * ADMB FUNCTION to write an dvector to file as an R vector
 * @param os - stream for output file.
 * @param xx - dvector to be written.
 */
void wts::writeToR(ostream& os, const dvector& xx){
    int mn = xx.indexmin();
    int mx = xx.indexmax();
    os<<"structure(c(";
//    for (int i=mn;i<mx;i++) os<<xx(i)<<cc;  os<<xx(mx)<<"),";
    wts::Rpr::writeDataToR(os,xx); os<<"),";
    os<<"names="<<mn<<":"<<mx<<",dim=c("<<mx-mn+1<<"))";
}

/********************************************************
 * ADMB FUNCTION to write a dvector to file as an R vector
 * @param os    - stream for output file.
 * @param xx    - dvector to be written.
 * @param names - adstring to be written as names for R structure 
 *                (comma-delimited, quoted if necessary). If names contains
 *                an equal sign, it will be used to specify the dimnames
 *                for the structure.
 */
void wts::writeToR(ostream& os, const dvector& xx, adstring names){
    if (names.pos("=")>0){
        //names specifies dimnames as well as element names
        wts::Rpr::writeToR(os,xx,names);
    } else {
        //names only specifies element names, not dimnames
        int mn = xx.indexmin();
        int mx = xx.indexmax();
        os<<"structure(c(";
//        for (int i=mn;i<mx;i++) os<<xx(i)<<cc;  os<<xx(mx)<<"),";
        wts::Rpr::writeDataToR(os,xx); os<<"),";
        os<<"names=c("<<names<<"),dim=c("<<mx-mn+1<<"))";
    }
}
/********************************************************
 * ADMB FUNCTION to write a dvector to file as an R vector
 * @param os    - stream for output file.
 * @param xx    - dvector to be written.
 * @param names - adstring_array to be written as names for R structure 
 */
void wts::writeToR(ostream& os, const dvector& xx, adstring_array names){
    int mn = xx.indexmin();
    int mx = xx.indexmax();
    os<<"structure(c(";
//    for (int i=mn;i<mx;i++) os<<xx(i)<<cc;  os<<xx(mx)<<"),";
    wts::Rpr::writeDataToR(os,xx); os<<"),";
    os<<"names=c('"; for (int i=mn;i<mx;i++) os<<names(i)<<"','"; os<<names(mx)<<"'))";
}

/***********************************************************
 * ADMB FUNCTION to write a matrix as part of an R list.
 * @param os - stream for output file.
 * @param xx - matrix of data to be written.
 */
void wts::writeToR(ostream& os, const dmatrix& xx){
    int mnI = xx.indexmin();
    int mxI = xx.indexmax();
    int mnJ = xx(mnI).indexmin();
    int mxJ = xx(mnJ).indexmax();
    adstring dimnames=str(mnI)+":"+str(mxI)+cc+str(mnJ)+":"+str(mxJ);
    wts::Rpr::writeToR(os,xx,dimnames);
}

/***********************************************************
 * ADMB FUNCTION to write a matrix as part of an R list.
 * @param os - stream for output file.
 * @param xx - matrix of data to be written.
 * @param colnames - comma-delimited, single-quoted string of column names
 */
void wts::writeToR(ostream& os, const dmatrix& xx, adstring colnames){
    int mnI = xx.indexmin();
    int mxI = xx.indexmax();
    adstring dimnames=str(mnI)+":"+str(mxI)+cc+"c("+colnames+")";
    wts::Rpr::writeToR(os,xx,dimnames);
}

/***********************************************************
 * ADMB FUNCTION to write a matrix as part of an R list.
 * @param os - stream for output file.
 * @param xx - matrix of data to be written.
 * @param n1 - comma-delimited, single-quoted string of names for 1st (leftmost) index
 * @param n2 - comma-delimited, single-quoted string of names for 2nd index
 */
void wts::writeToR(ostream& os, const dmatrix& xx, adstring n1, adstring n2){
    adstring dimnames=n1+cc+n2;
    wts::Rpr::writeToR(os,xx,dimnames);
}
/****************************************************************
 * ADMB FUNCTION to write a d3_array to stream as an R structure.
 * 
 * @param os - stream for output file.
 * @param xx - data to be written.
 * @param n1 - comma-delimited, single-quoted string of names for 1st (leftmost) index
 * @param n2 - comma-delimited, single-quoted string of names for 2nd index
 * @param n3 - comma-delimited, single-quoted string of names for 3rd index
 */
void wts::writeToR(ostream& os, const d3_array& xx, adstring n1, adstring n2, adstring n3){
    adstring dimnames=n1+cc+n2+cc+n3;
    wts::Rpr::writeToR(os,xx,dimnames);
}
/****************************************************************
 * ADMB FUNCTION to write a dvar3_array to stream as an R structure.
 * 
 * @param os - stream for output file.
 * @param xx - data to be written.
 * @param n1 - comma-delimited, single-quoted string of names for 1st (leftmost) index
 * @param n2 - comma-delimited, single-quoted string of names for 2nd index
 * @param n3 - comma-delimited, single-quoted string of names for 3rd index
 */
void wts::writeToR(ostream& os, const dvar3_array& xx, adstring n1, adstring n2, adstring n3){
    adstring dimnames=n1+cc+n2+cc+n3;
    wts::Rpr::writeToR(os,xx,dimnames);
}
/****************************************************************
 * ADMB FUNCTION to write a d4_array to stream as an R structure.
 * 
 * @param os - stream for output file.
 * @param xx - data to be written.
 * @param n1 - comma-delimited, single-quoted string of names for 1st (leftmost) index
 * @param n2 - comma-delimited, single-quoted string of names for 2nd index
 * @param n3 - comma-delimited, single-quoted string of names for 3rd index
 * @param n4 - comma-delimited, single-quoted string of names for 4th index
  */
void wts::writeToR(ostream& os, const d4_array& xx, adstring n1, adstring n2, adstring n3, adstring n4){
    adstring dimnames=n1+cc+n2+cc+n3+cc+n4;
    wts::Rpr::writeToR(os,xx,dimnames);
}
/****************************************************************
 * ADMB FUNCTION to write a dvar4_array to stream as an R structure.
 * 
 * @param os - stream for output file.
 * @param xx - data to be written.
 * @param n1 - comma-delimited, single-quoted string of names for 1st (leftmost) index
 * @param n2 - comma-delimited, single-quoted string of names for 2nd index
 * @param n3 - comma-delimited, single-quoted string of names for 3rd index
 * @param n4 - comma-delimited, single-quoted string of names for 4th index
  */
void wts::writeToR(ostream& os, const dvar4_array& xx, adstring n1, adstring n2, adstring n3, adstring n4){
    adstring dimnames=n1+cc+n2+cc+n3+cc+n4;
    wts::Rpr::writeToR(os,xx,dimnames);
}
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
void wts::writeToR(ostream& os, const d5_array& xx, adstring n1, adstring n2, adstring n3, adstring n4, adstring n5){
    adstring dimnames=n1+cc+n2+cc+n3+cc+n4+cc+n5;
    wts::Rpr::writeToR(os,xx,dimnames);
}
/****************************************************************
 * ADMB FUNCTION to write a dvar5_array to stream as an R structure.
 * 
 * @param os - stream for output file.
 * @param xx - data to be written.
 * @param n1 - comma-delimited, single-quoted string of names for 1st (leftmost) index
 * @param n2 - comma-delimited, single-quoted string of names for 2nd index
 * @param n3 - comma-delimited, single-quoted string of names for 3rd index
 * @param n4 - comma-delimited, single-quoted string of names for 4th index
 * @param n5 - comma-delimited, single-quoted string of names for 5th index
 */
void wts::writeToR(ostream& os, const dvar5_array& xx, adstring n1, adstring n2, adstring n3, adstring n4, adstring n5){
    adstring dimnames=n1+cc+n2+cc+n3+cc+n4+cc+n5;
    wts::Rpr::writeToR(os,xx,dimnames);
}
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
 * @param n6 - comma-delimited, single-quoted string of names for 6th index
 */
void wts::writeToR(ostream& os, const d6_array& xx, adstring n1, adstring n2, adstring n3, adstring n4, adstring n5, adstring n6){
    adstring dimnames=n1+cc+n2+cc+n3+cc+n4+cc+n5+cc+n6;
    wts::Rpr::writeToR(os,xx,dimnames);
}
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
 * @param n6 - comma-delimited, single-quoted string of names for 6th index
 */
void wts::writeToR(ostream& os, const dvar6_array& xx, adstring n1, adstring n2, adstring n3, adstring n4, adstring n5, adstring n6){
    adstring dimnames=n1+cc+n2+cc+n3+cc+n4+cc+n5+cc+n6;
    wts::Rpr::writeToR(os,xx,dimnames);
}
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
 * @param n7 - comma-delimited, single-quoted string of names for 7th index
 */
void wts::writeToR(ostream& os, const d7_array& xx, adstring n1, adstring n2, adstring n3, adstring n4, adstring n5, adstring n6, adstring n7){
    adstring dimnames=n1+cc+n2+cc+n3+cc+n4+cc+n5+cc+n6+cc+n7;
    wts::Rpr::writeToR(os,xx,dimnames);
}
/****************************************************************
 * ADMB FUNCTION to write a dvar7_array to stream as an R structure.
 * 
 * @param os - stream for output file.
 * @param xx - data to be written.
 * @param n1 - comma-delimited, single-quoted string of names for 1st (leftmost) index
 * @param n2 - comma-delimited, single-quoted string of names for 2nd index
 * @param n3 - comma-delimited, single-quoted string of names for 3rd index
 * @param n4 - comma-delimited, single-quoted string of names for 4th index
 * @param n5 - comma-delimited, single-quoted string of names for 5th index
 * @param n6 - comma-delimited, single-quoted string of names for 6th index
 * @param n7 - comma-delimited, single-quoted string of names for 7th index
 */
void wts::writeToR(ostream& os, const dvar7_array& xx, adstring n1, adstring n2, adstring n3, adstring n4, adstring n5, adstring n6, adstring n7){
    adstring dimnames=n1+cc+n2+cc+n3+cc+n4+cc+n5+cc+n6+cc+n7;
    wts::Rpr::writeToR(os,xx,dimnames);
}
