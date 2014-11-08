//admbFunctions.cpp
#include <admodel.h>
#include "wtsConsts.hpp"
#include "admbBasicFunctions.hpp"
using namespace std;

int debugADMBFunctions= 0;
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
 * Converts a dvector (doubles) to an ivector (integers).
 * 
 * @param v - the dvector to convert
 * 
 * @return - the corresponding ivector
 */
ivector wts::to_ivector(_CONST dvector& v){
    ivector iv(v.indexmin(),v.indexmax());
    for (int i=v.indexmin();i<=v.indexmax();i++) iv(i) = floor(v(i));
    return iv;
}
/****************************************************************
* name      : copy                                              *
* purpose   : create a deep copy of a variable                  *
*NOTE: Does not work for ragged arrays                          *
****************************************************************/
dvector wts::copy(_CONST dvector& v){
    ivector bnds = getBounds(v);
    dvector c(bnds(1),bnds(2));
    c = v;
    return c;
}
//-------------------------------------------------------------
dmatrix wts::copy(_CONST dmatrix& v){
    ivector bnds = getBounds(v);
    dmatrix c(bnds(1),bnds(2),bnds(3),bnds(4));
    c = v;
    return c;
}
//-------------------------------------------------------------
d3_array wts::copy(_CONST d3_array& v){
    ivector bnds = getBounds(v);
    d3_array c(bnds(1),bnds(2),bnds(3),bnds(4),bnds(5),bnds(6));
    c = v;
    return c;
}
//-------------------------------------------------------------
d4_array wts::copy(_CONST d4_array& v){
    ivector bnds = getBounds(v);
    d4_array c(bnds(1),bnds(2),bnds(3),bnds(4),bnds(5),bnds(6),bnds(7),bnds(8));
    c = v;
    return c;
}
//-------------------------------------------------------------
d5_array wts::copy(_CONST d5_array& v){
    ivector bnds = getBounds(v);
    d5_array c(bnds(1),bnds(2),bnds(3),bnds(4),bnds(5),bnds(6),bnds(7),bnds(8),bnds(9),bnds(10));
    c = v;
    return c;
}
//-------------------------------------------------------------
d6_array wts::copy(_CONST d6_array& v){
    ivector bnds = getBounds(v);
    d6_array c(bnds(1),bnds(2),bnds(3),bnds(4),bnds(5),bnds(6),bnds(7),bnds(8),bnds(9),bnds(10),bnds(11),bnds(12));
    c = v;
    return c;
}
//-------------------------------------------------------------
d7_array wts::copy(_CONST d7_array& v){
    ivector bnds = getBounds(v);
    d7_array c(bnds(1),bnds(2),bnds(3),bnds(4),bnds(5),bnds(6),bnds(7),bnds(8),bnds(9),bnds(10),bnds(11),bnds(12),bnds(13),bnds(14));
    c = v;
    return c;
}
//-------------------------------------------------------------
dvar_vector wts::copy(_CONST dvar_vector& v){
    RETURN_ARRAYS_INCREMENT();
    ivector bnds = getBounds(v);
    dvar_vector c(bnds(1),bnds(2));
    c = v;
    RETURN_ARRAYS_DECREMENT();
    return c;
}
//-------------------------------------------------------------
dvar_matrix wts::copy(_CONST dvar_matrix& v){
    RETURN_ARRAYS_INCREMENT();
    ivector bnds = getBounds(v);
    dvar_matrix c(bnds(1),bnds(2),bnds(3),bnds(4));
    c = v;
    RETURN_ARRAYS_DECREMENT();
    return c;
}
//-------------------------------------------------------------
dvar3_array wts::copy(_CONST dvar3_array& v){
    RETURN_ARRAYS_INCREMENT();
    ivector bnds = getBounds(v);
    dvar3_array c(bnds(1),bnds(2),bnds(3),bnds(4),bnds(5),bnds(6));
    c = v;
    RETURN_ARRAYS_DECREMENT();
    return c;
}
//-------------------------------------------------------------
dvar4_array wts::copy(_CONST dvar4_array& v){
    RETURN_ARRAYS_INCREMENT();
    ivector bnds = getBounds(v);
    dvar4_array c(bnds(1),bnds(2),bnds(3),bnds(4),bnds(5),bnds(6),bnds(7),bnds(8));
    c = v;
    RETURN_ARRAYS_DECREMENT();
    return c;
}
//-------------------------------------------------------------
dvar5_array wts::copy(_CONST dvar5_array& v){
    RETURN_ARRAYS_INCREMENT();
    ivector bnds = getBounds(v);
    dvar5_array c(bnds(1),bnds(2),bnds(3),bnds(4),bnds(5),bnds(6),bnds(7),bnds(8),bnds(9),bnds(10));
    c = v;
    RETURN_ARRAYS_DECREMENT();
    return c;
}
//-------------------------------------------------------------
dvar6_array wts::copy(_CONST dvar6_array& v){
    RETURN_ARRAYS_INCREMENT();
    ivector bnds = getBounds(v);
    dvar6_array c(bnds(1),bnds(2),bnds(3),bnds(4),bnds(5),bnds(6),bnds(7),bnds(8),bnds(9),bnds(10),bnds(11),bnds(12));
    c = v;
    RETURN_ARRAYS_DECREMENT();
    return c;
}
//-------------------------------------------------------------
dvar7_array wts::copy(_CONST dvar7_array& v){
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
int wts::testEquals(_CONST ivector& i1, _CONST ivector& i2){
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
ivector wts::getBounds(_CONST prevariable& o){
    ivector b(1,1);
    b(1) = 0;
    return(b);
}
/*************************************************
* name      : getBounds                          *
* purpose   : return min, max indices for array  *
*************************************************/
ivector wts::getBounds(_CONST ivector& o){
    ivector b(1,2);
    b(1) = o.indexmin();
    b(2) = o.indexmax();
    return(b);
}
//-------------------------------------------------------------
ivector wts::getBounds(_CONST imatrix& o){
    ivector b(1,4);
    b(1) = o.indexmin();
    b(2) = o.indexmax();
    --(--b(3,4)) = getBounds(o(b(1)));
    return(b);
}
//-------------------------------------------------------------
ivector wts::getBounds(_CONST dvector& o){
    ivector b(1,2);
    b(1) = o.indexmin();
    b(2) = o.indexmax();
    return(b);
}
//-------------------------------------------------------------
ivector wts::getBounds(_CONST dmatrix& o){
    ivector b(1,4);
    b(1) = o.indexmin();
    b(2) = o.indexmax();
    --(--b(3,4)) = getBounds(o(b(1)));
    return(b);
}
//-------------------------------------------------------------
ivector wts::getBounds(_CONST d3_array& o){
    ivector b(1,6);
    b(1) = o.indexmin();
    b(2) = o.indexmax();
    --(--b(3,6)) = getBounds(o(b(1)));
    return(b);
}
//-------------------------------------------------------------
ivector wts::getBounds(_CONST d4_array& o){
    ivector b(1,8);
    b(1) = o.indexmin();
    b(2) = o.indexmax();
    --(--b(3,8)) = getBounds(o(b(1)));
    return(b);
}
//-------------------------------------------------------------
ivector wts::getBounds(_CONST d5_array& o){
    ivector b(1,10);
    b(1) = o.indexmin();
    b(2) = o.indexmax();
    --(--b(3,10)) = getBounds(o(b(1)));
    return(b);
}
//-------------------------------------------------------------
ivector wts::getBounds(_CONST d6_array& o){
    ivector b(1,12);
    b(1) = o.indexmin();
    b(2) = o.indexmax();
    --(--b(3,12)) = getBounds(o(b(1)));
    return(b);
}
//-------------------------------------------------------------
ivector wts::getBounds(_CONST d7_array& o){
    ivector b(1,14);
    b(1) = o.indexmin();
    b(2) = o.indexmax();
    --(--b(3,14)) = getBounds(o(b(1)));
    return(b);
}
//-------------------------------------------------------------
ivector wts::getBounds(_CONST dvar_vector& o){
    if (debugADMBFunctions>0) cout<<"start getBounds(dvar_vector)"<<endl;
    ivector b(1,2);
    b(1) = o.indexmin();
    b(2) = o.indexmax();
    if (debugADMBFunctions>0) cout<<b<<endl;
    if (debugADMBFunctions>0) cout<<"end getBounds(dvar_vector)"<<endl;
    return(b);
}
//-------------------------------------------------------------
ivector wts::getBounds(_CONST dvar_matrix& o){
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
ivector wts::getBounds(_CONST dvar3_array& o){
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
ivector wts::getBounds(_CONST dvar4_array& o){
    ivector b(1,8);
    b(1) = o.indexmin();
    b(2) = o.indexmax();
    --(--b(3,8)) = getBounds(o(b(1)));
    return(b);
}
//-------------------------------------------------------------
ivector wts::getBounds(_CONST dvar5_array& o){
    ivector b(1,10);
    b(1) = o.indexmin();
    b(2) = o.indexmax();
    --(--b(3,10)) = getBounds(o(b(1)));
    return(b);
}
//-------------------------------------------------------------
ivector wts::getBounds(_CONST dvar6_array& o){
    ivector b(1,12);
    b(1) = o.indexmin();
    b(2) = o.indexmax();
    --(--b(3,12)) = getBounds(o(b(1)));
    return(b);
}
//-------------------------------------------------------------
ivector wts::getBounds(_CONST dvar7_array& o){
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
    cout<<"starting permuteDims(d3_array&)"<<endl;
    if ((i2p.indexmax()-i2p.indexmin()+1)!=mxi){
        std::cout<<"Error in d"<<mxi<<"_array permuteDims()"<<endl;
        std::cout<<"i2p must have length "<<mxi<<"."<<endl;
        std::cout<<"i2p = "<<i2p<<endl;
        std::cout<<"Aborting..."<<endl;
        std::exit(-1);
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
    cout<<"finished permuteDims(d3_array&)"<<endl;
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
    cout<<"starting permuteDims(d4_array&)"<<endl;
    if ((i2p.indexmax()-i2p.indexmin()+1)!=mxi){
        std::cout<<"Error in d"<<mxi<<"_array permuteDims()"<<endl;
        std::cout<<"i2p must have length "<<mxi<<"."<<endl;
        std::cout<<"i2p = "<<i2p<<endl;
        std::cout<<"Aborting..."<<endl;
        std::exit(-1);
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
    cout<<"finished permuteDims(d4_array&)"<<endl;
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
    cout<<"starting permuteDims(d5_array&)"<<endl;
    int mxi = 5;
    if ((i2p.indexmax()-i2p.indexmin()+1)!=mxi){
        std::cout<<"Error in d"<<mxi<<"_array permuteDims()"<<endl;
        std::cout<<"i2p must have length "<<mxi<<"."<<endl;
        std::cout<<"i2p = "<<i2p<<endl;
        std::cout<<"Aborting..."<<endl;
        std::exit(-1);
    }
    ivector bnds = getBounds(n_i);
    ivector pbnds(1,2*mxi);
    for (int i=1;i<=mxi;i++) {
        pbnds(2*i2p(i)-1) = bnds(2*i-1);
        pbnds(2*i2p(i))   = bnds(2*i);
    }
    cout<<"bnds  = "<<bnds<<endl;
    cout<<"pbnds = "<<pbnds<<endl;
    d5_array n_p = dimD5array(pbnds); 
    n_p.initialize();
    cout<<"bounds(n_p) = "<<getBounds(n_p)<<endl;
    
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
                        cout<<endl<<"i = "<<i<<endl<<"p = "<<p<<endl;
                        cout<<"n_i[i] = "<<n_i(i[1],i[2],i[3],i[4],i[5])<<endl;
                        n_p(p[1],p[2],p[3],p[4],p[5]) = 
                            n_i(i[1],i[2],i[3],i[4],i[5]);
                        cout<<"n_p[p] = "<<n_p(p[1],p[2],p[3],p[4],p[5])<<endl;
                    }
                    j=4;
                }
                j=3;
            }
            j=2;
        }
        j=1;
    }
    cout<<"finished permuteDims(d5_array&)"<<endl;
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
    cout<<"starting permuteDims(d6_array&)"<<endl;
    if ((i2p.indexmax()-i2p.indexmin()+1)!=mxi){
        std::cout<<"Error in d"<<mxi<<"_array permuteDims()"<<endl;
        std::cout<<"i2p must have length "<<mxi<<"."<<endl;
        std::cout<<"i2p = "<<i2p<<endl;
        std::cout<<"Aborting..."<<endl;
        std::exit(-1);
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
    cout<<"finished permuteDims(d6_array&)"<<endl;
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
    cout<<"starting permuteDims(d7_array&)"<<endl;
    if ((i2p.indexmax()-i2p.indexmin()+1)!=mxi){
        std::cout<<"Error in d"<<mxi<<"_array permuteDims()"<<endl;
        std::cout<<"i2p must have length "<<mxi<<"."<<endl;
        std::cout<<"i2p = "<<i2p<<endl;
        std::cout<<"Aborting..."<<endl;
        std::exit(-1);
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
    cout<<"finished permuteDims(d7_array&)"<<endl;
    return n_p;
}

/*************************************************
* name      : length                             *
* purpose   : return number of elements in array *
*************************************************/
int wts::length(_CONST ivector& o){
    ivector b(1,2);
    b = getBounds(o);
    int i = b(2)-b(1)+1;
    return(i);
}
//-------------------------------------------------------------
int wts::length(_CONST imatrix& o){
    ivector b(1,2);
    b = getBounds(o);
    int i = 1;
    for (int j=1;j<=2;j++) i *= (b(2*j)-b(2*j-1)+1);
    return(i);
}
//-------------------------------------------------------------
int wts::length(_CONST dvector& o){
    ivector b(1,2);
    b = getBounds(o);
    int i = b(2)-b(1)+1;
    return(i);
}
//-------------------------------------------------------------
int wts::length(_CONST dmatrix& o){
    ivector b(1,2);
    b = getBounds(o);
    int i = 1;
    for (int j=1;j<=2;j++) i *= (b(2*j)-b(2*j-1)+1);
    return(i);
}
//-------------------------------------------------------------
int wts::length(_CONST dvar_vector& o){
    ivector b(1,2);
    b = getBounds(o);
    int i = b(2)-b(1)+1;
    return(i);
}
//-------------------------------------------------------------
int wts::length(_CONST dvar_matrix& o){
    ivector b(1,2);
    b = getBounds(o);
    int i = 1;
    for (int j=1;j<=2;j++) i *= (b(2*j)-b(2*j-1)+1);
    return(i);
}
//-------------------------------------------------------------


/*************************************************
* name      : value                              *
* purpose   : return constant version of array   *
*************************************************/
d4_array wts::value(_CONST dvar4_array& o){
    if (debugADMBFunctions>0) cout<<"start value(dvar4_array)"<<endl;
    ivector b = getBounds(o);
    d4_array a(b(1),b(2),b(3),b(4),b(5),b(6),b(7),b(8));
    for (int r=b(1);r<=b(2);r++) a(r) = value(o(r));
    if (debugADMBFunctions>0) cout<<"   end value(dvar4_array)"<<endl;
    return(a);
}
//-------------------------------------------------------------
d5_array wts::value(_CONST dvar5_array& o){
    if (debugADMBFunctions>0) cout<<"start value(dvar5_array)"<<endl;
    ivector b = getBounds(o);
    d5_array a(b(1),b(2),b(3),b(4),b(5),b(6),b(7),b(8),b(9),b(10));
    for (int r=b(1);r<=b(2);r++) a(r) = value(o(r));
    if (debugADMBFunctions>0) cout<<"   end value(dvar5_array)"<<endl;
    return(a);
}
//-------------------------------------------------------------
d6_array wts::value(_CONST dvar6_array& o){
    if (debugADMBFunctions>0) cout<<"start value(dvar6_array)"<<endl;
    ivector b = getBounds(o);
    d6_array a(b(1),b(2),b(3),b(4),b(5),b(6),b(7),b(8),b(9),b(10),b(11),b(12));
    for (int r=b(1);r<=b(2);r++) a(r) = value(o(r));
    if (debugADMBFunctions>0) cout<<"   end value(dvar6_array)"<<endl;
    return(a);
}
//-------------------------------------------------------------
d7_array wts::value(_CONST dvar7_array& o){
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
ivector wts::getIndexVector(_CONST dvector& o) {
    ivector bnds = getBounds(o);
    ivector indx(bnds(1),bnds(2));
    indx.fill_seqadd(bnds(1),1);
    return indx;
}
//-------------------------------------------------------------

ivector wts::getIndexVector(_CONST dvar_vector& o) {
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
bool wts::isActive(_CONST param_init_number& p){return active(p);}
bool wts::isActive(_CONST param_init_vector& p){return active(p);}
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
double wts::variance(_CONST dvector & v) {
    return norm2(v-mean(v))/double(length(v)-1);
}
//-------------------------------------------------------------
dvariable wts::variance(_CONST dvar_vector & v) {
    return norm2(v-mean(v))/double(length(v)-1);
}
    
