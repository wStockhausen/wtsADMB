//admbStringFunctions.cpp
#include <admodel.h>
#include "wtsConsts.hpp"
#include "admbStringFunctions.hpp"
using namespace std;
/**
 * Changes:
 * 2014-12-03: 1. Changed to using std namespace
 * 2015-02-27: 1. Added to_csv(...) functions to provide strings with unquoted elements
 * 2015-03-01: 1. Added strg(double) function 
 * 2015-03-02: 1. Added replace(...) function 
*/
    
/**
 * Create an adstring by replacing all instances of s in adstring a with r. 
 * 
 * @param s
 * @param r
 * @param a
 * @return 
 */
adstring wts::replace(char s, char r, const adstring& a){
    adstring tmp; tmp = a;
    int p = tmp.pos(s);
    while (p>0){
        tmp[p] = r;
        p = tmp.pos(s);
    }
    return tmp;
}

/**
 * Function to format a double using 'g'-type fprmatting in sprintf().
 * 
 * @param d
 * @return g-formatted adstring representation of d
 */
adstring wts::strg(double d){
    char  buffer[50];
    sprintf(buffer,"%g",d);
    adstring tmp(buffer);
    return tmp;
}
    
/****************************************************************
 * convert vectors to unquoted csv string
 ***************************************************************/
/**
 * Convert adstring_array to string of unquoted, comma-separated values
 * @param v
 * @return 
 */
adstring wts::to_csv(const adstring_array& v){
    int mn = v.indexmin();
    int mx = v.indexmax();
    adstring s = v(mn);
    for (int i=mn;i<mx;i++) s = s+cc+v(i+1);
    return s;
}
/**
 * Convert ivector to string of unquoted, comma-separated values
 * @param v
 * @return 
 */
adstring wts::to_csv(const ivector& v){
    int mn = v.indexmin();
    int mx = v.indexmax();
    adstring s = str(v(mn));
    for (int i=mn;i<mx;i++) s = s+cc+str(v(i+1));
    return s;
}
/**
 * Convert dvector to string of unquoted, comma-separated values
 * @param v - dvector to format as csv string
 * @param g - flag to use sprintf "g" format for output (if 1) or admb standard (if 0)
 * @return 
 */
adstring wts::to_csv(const dvector& v, int g){
    int mn = v.indexmin();
    int mx = v.indexmax();
    adstring s;
    if (g){
        s = strg(v(mn));
        for (int i=mn;i<mx;i++) s = s+cc+strg(v(i+1));
    } else {
        s = str(v(mn));
        for (int i=mn;i<mx;i++) s = s+cc+str(v(i+1));
    }
    return s;
}

/****************************************************************
 * convert vectors to quoted csv string
 ***************************************************************/
/**
 * Convert adstring_array to string of quoted, comma-separated values
 * @param v
 * @return 
 */
adstring wts::to_qcsv(const adstring_array& v){
    int mn = v.indexmin();
    int mx = v.indexmax();
    adstring s = qt+v(mn)+qt;
    for (int i=mn;i<mx;i++) s = s+cc+qt+v(i+1)+qt;
    return s;
}
/**
 * Convert ivector to string of quoted, comma-separated values
 * @param v
 * @return 
 */
adstring wts::to_qcsv(const ivector& v){
    int mn = v.indexmin();
    int mx = v.indexmax();
    adstring s = qt+str(v(mn))+qt;
    for (int i=mn;i<mx;i++) s = s+cc+qt+str(v(i+1))+qt;
    return s;
}
/**
 * Convert dvector to string of quoted, comma-separated values
 * @param v - dvector to format as quoted csv string
 * @param g - flag to use sprintf "g" format for output (if 1) or admb standard (if 0)
 * @return 
 */
adstring wts::to_qcsv(const dvector& v, int g){
    int mn = v.indexmin();
    int mx = v.indexmax();
    adstring s;
    if (g){
        s = qt+strg(v(mn))+qt;
        for (int i=mn;i<mx;i++) s = s+cc+qt+strg(v(i+1))+qt;
    } else {
        s = qt+str(v(mn))+qt;
        for (int i=mn;i<mx;i++) s = s+cc+qt+str(v(i+1))+qt;
    }
    return s;
}

int wts::which(adstring& s, adstring_array& v){
//    cout<<"string to match = '"<<s<<"'"<<endl;
//    cout<<"choices: "<<tb; for (int i=v.indexmin();i<=v.indexmax(); i++) cout<<v(i)<<tb; cout<<endl;
    int idx = v.indexmax();
    while (v.indexmin()<=idx){
//        cout<<"testing '"<<s<<"' = '"<<v(idx)<<endl;
        if (v(idx)==s) break;
        idx--;
    }
    if (idx<v.indexmin()) idx = min(idx,0);
//    cout<<"returning "<<idx<<endl;
    return idx;
}

int wts::which(const char * s, adstring_array& v){
    adstring sp=s;
    return wts::which(sp,v);
}

/****************************************************************
* name      : adstring_matrix                                   *
* purpose   : functionality for (possibly ragged) matrix of     *
*               of adstrings                                    *
****************************************************************/
bool wts::adstring_matrix::debug = false;
/****************************************************************
* Constructor                                                   *
****************************************************************/
wts::adstring_matrix::adstring_matrix(){
    nAAs = 0;
    idxmn = 0;
    ppAAs = 0;
}

/****************************************************************
* Constructor                                                   *
****************************************************************/
wts::adstring_matrix::adstring_matrix(int rwmn, int rwmx, int clmn, int clmx){
    nAAs = 0;
    idxmn = 0;
    ppAAs = 0;
    allocate(rwmn,rwmx,clmn,clmx);
}

/****************************************************************
* Constructor                                                   *
****************************************************************/
wts::adstring_matrix::adstring_matrix(int rwmn, int rwmx, ivector& clmns, int clmx){
    nAAs = 0;
    idxmn = 0;
    ppAAs = 0;
    allocate(rwmn,rwmx,clmns,clmx);
}

/****************************************************************
* Constructor                                                   *
****************************************************************/
wts::adstring_matrix::adstring_matrix(int rwmn, int rwmx, int clmn, ivector& clmxs){
    nAAs = 0;
    idxmn = 0;
    ppAAs = 0;
    allocate(rwmn,rwmx,clmn,clmxs);
}

/****************************************************************
* Constructor                                                   *
****************************************************************/
wts::adstring_matrix::adstring_matrix(int rwmn, int rwmx, ivector& clmns, ivector& clmxs){
    nAAs = 0;
    idxmn = 0;
    ppAAs = 0;
    allocate(rwmn,rwmx,clmns,clmxs);
}

/****************************************************************
* Constructor                                                   *
****************************************************************/
void wts::adstring_matrix::deallocate(void){
    if (ppAAs) {
        for (int r=0;r<nAAs;r++){
            delete ppAAs[r]; ppAAs[r]=0;
        }
        delete[] ppAAs; ppAAs = 0;
    }
    nAAs  = 0;
    idxmn = 0;
}

void wts::adstring_matrix::allocate(int rwmn, int rwmx){
    if (debug) cout<<"starting adstring_matrix::allocate("<<rwmn<<","<<rwmx<<")"<<endl;
    deallocate();
    nAAs = rwmx-rwmn+1;
    if (nAAs<0) {
        nAAs = 0;
    } else {
        idxmn = rwmn;
        ppAAs = new adstring_array*[nAAs];
        for (int r=0;r<nAAs;r++) ppAAs[r] = 0;
    }
    if (debug){
        cout<<"finished adstring_matrix::allocate("<<rwmn<<","<<rwmx<<")"<<endl;
        cout<<"nAAs = "<<nAAs<<", ppAAs = "<<ppAAs<<endl;
    }
}

void wts::adstring_matrix::allocate(int rwmn, int rwmx, int clmn, int clmx){
    if (debug) cout<<"starting adstring_matrix::allocate("<<rwmn<<","<<rwmx<<","<<clmn<<","<<clmx<<")"<<endl;
    deallocate();
    ivector clmns(rwmn,rwmx); clmns = clmn;
    ivector clmxs(rwmn,rwmx); clmxs = clmx;
    allocate(rwmn,rwmx,clmns,clmxs);
    if (debug) cout<<"finished adstring_matrix::allocate("<<rwmn<<","<<rwmx<<","<<clmn<<","<<clmx<<")"<<endl;
}

void wts::adstring_matrix::allocate(int rwmn, int rwmx, ivector& clmns, int clmx){
    if (debug) cout<<"starting adstring_matrix::allocate("<<rwmn<<","<<rwmx<<","<<clmns<<","<<clmx<<")"<<endl;
    deallocate();
    ivector clmxs(rwmn,rwmx); clmxs = clmx;
    allocate(rwmn,rwmx,clmns,clmxs);
    if (debug) cout<<"finished adstring_matrix::allocate("<<rwmn<<","<<rwmx<<","<<clmns<<","<<clmx<<")"<<endl;
}

void wts::adstring_matrix::allocate(int rwmn, int rwmx, int clmn, ivector& clmxs){
    if (debug) cout<<"starting adstring_matrix::allocate("<<rwmn<<","<<rwmx<<","<<clmn<<","<<clmxs<<")"<<endl;
    deallocate();
    ivector clmns(rwmn,rwmx); clmns = clmn;
    allocate(rwmn,rwmx,clmns,clmxs);
    if (debug) cout<<"finished adstring_matrix::allocate("<<rwmn<<","<<rwmx<<","<<clmn<<","<<clmxs<<")"<<endl;
}

void wts::adstring_matrix::allocate(int rwmn, int rwmx, ivector& clmns, ivector& clmxs){
    if (debug) cout<<"starting adstring_matrix::allocate("<<rwmn<<","<<rwmx<<endl<<clmns<<endl<<clmxs<<")"<<endl;
    allocate(rwmn,rwmx);
    if (rwmn!=clmns.indexmin()){
        cout<<"Error in adstring_matrix::allocate(int rwmn, int rwmx, ivector& clmns, ivector& clmxs)"<<endl;
        cout<<"min row index ("<<rwmn<<"must equal min min-columns index ("<<clmns.indexmin()<<")"<<endl;
        exit(0);
    }
    if (rwmn!=clmxs.indexmin()){
        cout<<"Error in adstring_matrix::allocate(int rwmn, int rwmx, ivector& clmns, ivector& clmxs)"<<endl;
        cout<<"min row index ("<<rwmn<<"must equal min max-columns index ("<<clmxs.indexmin()<<")"<<endl;
        exit(0);
    }
    if (rwmx!=clmns.indexmax()){
        cout<<"Error in adstring_matrix::allocate(int rwmn, int rwmx, ivector& clmns, ivector& clmxs)"<<endl;
        cout<<"max row index ("<<rwmn<<"must equal max min-columns index ("<<clmns.indexmax()<<")"<<endl;
        exit(0);
    }
    if (rwmx!=clmxs.indexmax()){
        cout<<"Error in adstring_matrix::allocate(int rwmn, int rwmx, ivector& clmns, ivector& clmxs)"<<endl;
        cout<<"max row index ("<<rwmx<<"must equal max max-columns index ("<<clmxs.indexmax()<<")"<<endl;
        exit(0);
    }
    this->clmns.allocate(rwmn,rwmx);
    this->clmxs.allocate(rwmn,rwmx);
    this->clmns = clmns;
    this->clmxs = clmxs;
    //note that the following means ppAAs[r] COULD BE 0 for some r even though adstring_arrays have been allocated
    //for other vlaues of r.  Thus need to check that ppAAs[r] is not a null ptr before accessing it.
    for (int r=0;r<nAAs;r++) if (clmns(r+rwmn)<=clmxs(r+rwmn)) ppAAs[r] = new adstring_array(clmns(r+rwmn),clmxs(r+rwmn));
    if (debug){
        cout<<"finished adstring_matrix::allocate(int rwmn, int rwmx, ivector& clmns, ivector& clmxs)"<<endl;
        cout<<"rwmn, rwmx = "<<rwmn<<", "<<rwmx<<endl;
        cout<<"clmns = "<<clmns<<",  clmxs = "<<clmxs<<endl;
        cout<<"ppAAs = "; for (int r=0;r<nAAs;r++) cout<<ppAAs[r]<<tb; cout<<endl;
    }
}

adstring& wts::adstring_matrix::operator() (const int i, const int j){
    if (ppAAs){
        if ((idxmn<=i)&&(i-idxmn<nAAs)&&(ppAAs[i-idxmn])){
            if ((clmns(i)<=j)&&(j<=clmxs(i))){
                return (*(ppAAs[i-idxmn]))(j);
            } else {
                cout<<"Attempting illegal access in adstring_matrix::("<<i<<","<<j<<")"<<endl;
                cout<<"Column index is invalid! Limits are "<<clmns(i)<<","<<clmxs(i)<<"."<<endl;
            }
        } else {
            cout<<"Attempting illegal access in adstring_matrix::("<<i<<","<<j<<")"<<endl;
            cout<<"Row index is invalid! Limits are "<<idxmn<<","<<idxmn+nAAs<<"."<<endl;
        }
    } else {
        cout<<"Attempting illegal access in adstring_matrix::("<<i<<","<<j<<")"<<endl;
        cout<<"Matrix is not allocated! nAAs = "<<nAAs<<", ppAAs = "<<ppAAs<<endl;
    }
    adstring* ptr = new adstring();
    return *ptr;
}

adstring_array& wts::adstring_matrix::operator() (const int i){
    if (ppAAs){
        if ((idxmn<=i)&&(i-idxmn<nAAs)&&(ppAAs[i-idxmn])) {
            return *(ppAAs[i-idxmn]);
        } else {
            cout<<"Attempting illegal access in adstring_matrix::("<<i<<")"<<endl;
            cout<<"Row index is invalid! Limits are "<<idxmn<<","<<idxmn+nAAs<<"."<<endl;
        }
    } else {
        cout<<"Attempting illegal access in adstring_matrix::("<<i<<")"<<endl;
        cout<<"Matrix is not allocated!"<<endl;
    }
    adstring_array* ptr = new adstring_array();
    return *ptr;
}

adstring_array& wts::adstring_matrix::operator[] (const int i){
    if (ppAAs){
        if ((idxmn<=i)&&(i-idxmn<nAAs)&&(ppAAs[i-idxmn])) {
            return *(ppAAs[i-idxmn]);
        } else {
            cout<<"Attempting illegal access in adstring_matrix::("<<i<<")"<<endl;
            cout<<"Row index is invalid! Limits are "<<idxmn<<","<<idxmn+nAAs<<"."<<endl;
        }
    } else {
        cout<<"Attempting illegal access in adstring_matrix::("<<i<<")"<<endl;
        cout<<"Matrix is not allocated!"<<endl;
    }
    adstring_array* ptr = new adstring_array();
    return *ptr;
}

void wts::adstring_matrix::read(cifstream & is){
    if (ppAAs){
        for (int r=0;r<nAAs;r++){
            if (allocated(r)) is>>(*(ppAAs[r]));
        }
    }
}

void wts::adstring_matrix::write(ostream & os){
    if (ppAAs){
        for (int r=0;r<nAAs;r++){
            for (int c=clmns(r+idxmn);c<=clmxs(r+idxmn);c++){
                os<<(*(ppAAs[r]))(c)<<tb;
            }
            if (r<(nAAs-1)) os<<endl<<tb;
        }
    }
}

/****************************************************************
* name      : CompareAdstrings                                  *
* purpose   : Class with member function to determine if       *
*               lhs < rhs for input adstrings lhs, rhs          *
****************************************************************/
bool wts::CompareAdstrings::debug = false;
bool wts::CompareAdstrings::operator() (const adstring& lhs, const adstring& rhs) const {
    if (debug) cout<<"CompareAdstrings::('"<<lhs<<"','"<<rhs<<"'): "<<&lhs<<"; "<<&rhs<<endl;
    int nl = lhs.size(); int nr = rhs.size();
    int nz = nr;//compare characters over min string size (assume rhs is shorter)
    if (nl<nr) nz = nl;
    int i = 1;
    bool cont = true;//flag to continue checking
    if (debug) cout<<"CompareAdstrings: "<<lhs<<" < "<<rhs<<"; "<<nl<<", "<<nr<<endl;
    while (cont&&(i<=nz)) {
        cont = (lhs(i)==rhs(i));
        if (debug) cout<<lhs(i)<<" == "<<rhs(i)<<" ?: "<<cont<<endl;
        i++;
    }
    if (debug) cout<<"i: "<<i<<", cont = "<<cont<<endl;
    if (!cont) {
        cont = lhs(i-1)<rhs(i-1);//equality failed above, so which is it?
    } else {
        //comparison was equal up to end of shorter string.
        //set shorter string < longer string
        if (nl<nr) {
            cont = true;//rhs is longer than lhs, so lhs<rhs
        } else {
            cont = false;
        }
    }
    if (debug) cout<<"CompareAdstrings: "<<lhs<<" < "<<rhs<<" ? "<<cont<<endl;
    return cont;
}
