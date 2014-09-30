// rFunctions.cpp
// This file has C++ functions for use in writing R-compatible data output.
// WTS 2005-04: adapted from mhp-s-funcs.cpp by Michael Prager  -- December, 2002
#include <admodel.h>
#include <iostream>
#include "wtsConsts.hpp"
#include "admbBasicFunctions.hpp"
#include "admbStringFunctions.hpp"
#include "rFunctions.hpp"

/***********************************************************
 * ADMB FUNCTION to write a matrix as part of an array structure.
 * @param os - stream for output file.
 * @param xx - matrix of data to be written.
 * @return - dims for writing the matrix to an array structure.
 */
adstring wts::Rpr::writeDataToR(ostream& os, _CONST imatrix& xx){
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
 * ADMB FUNCTION to write a matrix as part of an R list.
 * @param os - stream for output file.
 * @param xx - matrix of data to be written.
 * @param dimnames - adstring with dimnames.
 */
void wts::Rpr::writeToR(ostream& os, _CONST imatrix& xx, adstring dimnames){
    os<<"structure(c(";
    adstring dims = Rpr::writeDataToR(os,xx);
    os<<"),"<<endl<<tb<<tb;    
    os<<"dimnames=list("<<dimnames<<"),";
    os<<"dim=c("<<dims<<"))";
}

/***********************************************************
 * ADMB FUNCTION to write a matrix as part of an array structure.
 * @param os - stream for output file.
 * @param xx - matrix of data to be written.
 * @return - dims for writing the matrix to an array structure.
 */
adstring wts::Rpr::writeDataToR(ostream& os, _CONST dmatrix& xx){
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
 * ADMB FUNCTION to write a matrix as part of an R list.
 * @param os - stream for output file.
 * @param xx - matrix of data to be written.
 * @param dimnames - adstring with dimnames.
 */
void wts::Rpr::writeToR(ostream& os, _CONST dmatrix& xx, adstring dimnames){
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
adstring wts::Rpr::writeDataToR(ostream& os, _CONST d3_array& xx){
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
 * ADMB FUNCTION to write a d3_array to stream as an R array.
 * 
 * @param os - stream for output file.
 * @param xx - d3_array to be written.
 * @param dimnames - adstring with dimnames.
 */
void wts::Rpr::writeToR(ostream& os, _CONST d3_array& xx, adstring dimnames){
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
adstring wts::Rpr::writeDataToR(ostream& os, _CONST d4_array& xx){
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
 * ADMB FUNCTION to write a d4_array to stream as an R array.
 * 
 * @param os - stream for output file.
 * @param xx - d4_array to be written.
 * @param dimnames - adstring with dimnames.
 */
void wts::Rpr::writeToR(ostream& os, _CONST d4_array& xx, adstring dimnames){
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
adstring wts::Rpr::writeDataToR(ostream& os, _CONST d5_array& xx){
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
 * ADMB FUNCTION to write a d5_array to stream as an R array.
 * 
 * @param os - stream for output file.
 * @param xx - d5_array to be written.
 * @param dimnames - adstring with dimnames.
 */
void wts::Rpr::writeToR(ostream& os, _CONST d5_array& xx, adstring dimnames){
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
adstring wts::Rpr::writeDataToR(ostream& os, _CONST d6_array& xx){
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
 * ADMB FUNCTION to write a d6_array to stream as an R array.
 * 
 * @param os - stream for output file.
 * @param xx - d6_array to be written.
 * @param dimnames - adstring with dimnames.
 */
void wts::Rpr::writeToR(ostream& os, _CONST d6_array& xx, adstring dimnames){
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
adstring wts::Rpr::writeDataToR(ostream& os, _CONST d7_array& xx){
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
 * ADMB FUNCTION to write a d7_array to stream as an R array.
 * 
 * @param os - stream for output file.
 * @param xx - d7_array to be written.
 * @param dimnames - adstring with dimnames.
 */
void wts::Rpr::writeToR(ostream& os, _CONST d7_array& xx, adstring dimnames){
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
void wts::writeToR(ostream& os, _CONST adstring_array& xx){
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
void wts::writeToR(ostream& os, _CONST ivector& xx){
    int mn = xx.indexmin();
    int mx = xx.indexmax();
    os<<"structure(c(";
    for (int i=mn;i<mx;i++) os<<xx(i)<<cc;  os<<xx(mx)<<"),"<<endl<<tb<<tb;
    os<<"names="<<mn<<":"<<mx<<",dim=c("<<mx-mn+1<<"))";
}

/********************************************************
 * ADMB FUNCTION to write a matrix as part of an R list.
 * @param os - stream for output file.
 * @param xx - matrix of data to be written.
 */
void wts::writeToR(ostream& os, _CONST imatrix& xx){
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
void wts::writeToR(ostream& os, _CONST imatrix& xx, adstring colnames){
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
void wts::writeToR(ostream& os, _CONST imatrix& xx, adstring n1, adstring n2){
    adstring dimnames="c("+n1+")"+cc+"c("+n2+")";
    wts::Rpr::writeToR(os,xx,dimnames);
}
/********************************************************
 * ADMB FUNCTION to write an dvector to file as an R vector
 * @param os - stream for output file.
 * @param xx - dvector to be written.
 */
void wts::writeToR(ostream& os, _CONST dvector& xx){
    int mn = xx.indexmin();
    int mx = xx.indexmax();
    os<<"structure(c(";
    for (int i=mn;i<mx;i++) os<<xx(i)<<cc;  os<<xx(mx)<<"),"<<endl<<tb<<tb;
    os<<"names="<<mn<<":"<<mx<<",dim=c("<<mx-mn+1<<"))";
}

/********************************************************
 * ADMB FUNCTION to write a dvector to file as an R vector
 * @param os    - stream for output file.
 * @param xx    - dvector to be written.
 * @param names - adstring to be written as names for R structure 
 *                (comma-delimited, quoted if necessary)
 */
void wts::writeToR(ostream& os, _CONST dvector& xx, adstring names){
    int mn = xx.indexmin();
    int mx = xx.indexmax();
    os<<"structure(c(";
    for (int i=mn;i<mx;i++) os<<xx(i)<<cc;  os<<xx(mx)<<"),"<<endl<<tb<<tb;
    os<<"names=c("<<names<<"),dim=c("<<mx-mn+1<<"))";
}
/********************************************************
 * ADMB FUNCTION to write a dvector to file as an R vector
 * @param os    - stream for output file.
 * @param xx    - dvector to be written.
 * @param names - adstring_array to be written as names for R structure 
 */
void wts::writeToR(ostream& os, _CONST dvector& xx, adstring_array names){
    int mn = xx.indexmin();
    int mx = xx.indexmax();
    os<<"structure(c(";
    for (int i=mn;i<mx;i++) os<<xx(i)<<cc;  os<<xx(mx)<<"),"<<endl<<tb<<tb;
    os<<"names=c('"; for (int i=mn;i<mx;i++) os<<names(i)<<"','"; os<<names(mx)<<"'))";
}

/***********************************************************
 * ADMB FUNCTION to write a matrix as part of an R list.
 * @param os - stream for output file.
 * @param xx - matrix of data to be written.
 */
void wts::writeToR(ostream& os, _CONST dmatrix& xx){
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
void wts::writeToR(ostream& os, _CONST dmatrix& xx, adstring colnames){
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
void wts::writeToR(ostream& os, _CONST dmatrix& xx, adstring n1, adstring n2){
    adstring dimnames="c("+n1+")"+cc+"c("+n2+")";
    wts::Rpr::writeToR(os,xx,dimnames);
}
/****************************************************************
 * ADMB FUNCTION to write a d5_array to stream as an R structure.
 * 
 * @param os - stream for output file.
 * @param xx - data to be written.
 * @param n1 - ivector of index "names" for 1st (leftmost) index
 * @param n2 - comma-delimited, single-quoted string of names for 2nd index
 */
void wts::writeToR(ostream& os, _CONST dmatrix& xx, _CONST ivector& n1, adstring n2){
    adstring rows = wts::to_qcsv(n1);
    wts::writeToR(os,xx,rows,n2);
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
void wts::writeToR(ostream& os, _CONST d3_array& xx, adstring n1, adstring n2, adstring n3){
    adstring dimnames="c("+n1+")"+cc+"c("+n2+")"+cc+"c("+n3+")";
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
void wts::writeToR(ostream& os, _CONST d4_array& xx, adstring n1, adstring n2, adstring n3, adstring n4){
    adstring dimnames="c("+n1+")"+cc+"c("+n2+")"+cc+"c("+n3+")"+cc+"c("+n4+")";
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
void wts::writeToR(ostream& os, _CONST d5_array& xx, adstring n1, adstring n2, adstring n3, adstring n4, adstring n5){
    adstring dimnames="c("+n1+")"+cc+"c("+n2+")"+cc+"c("+n3+")"+cc+"c("+n4+")"+cc+"c("+n5+")";
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
void wts::writeToR(ostream& os, _CONST d6_array& xx, adstring n1, adstring n2, adstring n3, adstring n4, adstring n5, adstring n6){
    adstring dimnames="c("+n1+")"+cc+"c("+n2+")"+cc+"c("+n3+")"+cc+"c("+n4+")"+cc+"c("+n5+")"+cc+"c("+n6+")";
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
void wts::writeToR(ostream& os, _CONST d7_array& xx, adstring n1, adstring n2, adstring n3, adstring n4, adstring n5, adstring n6, adstring n7){
    adstring dimnames="c("+n1+")"+cc+"c("+n2+")"+cc+"c("+n3+")"+cc+"c("+n4+")"+cc+"c("+n5+")"+cc+"c("+n6+")"+cc+"c("+n7+")";
    wts::Rpr::writeToR(os,xx,dimnames);
}
