//admbStringFunctions.cpp
#include <admodel.h>
#include "wtsConsts.hpp"
#include "admbStringFunctions.hpp"

/****************************************************************
 * convert vectors to quoted csv string
 ***************************************************************/
/**
 * Convert adstring_array to string of quoted, comma-separated values
 * @param v
 * @return 
 */
adstring wts::to_qcsv(_CONST adstring_array& v){
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
adstring wts::to_qcsv(_CONST ivector& v){
    int mn = v.indexmin();
    int mx = v.indexmax();
    adstring s = qt+str(v(mn))+qt;
    for (int i=mn;i<mx;i++) s = s+cc+qt+str(v(i+1))+qt;
    return s;
}
/**
 * Convert dvector to string of quoted, comma-separated values
 * @param v
 * @return 
 */
adstring wts::to_qcsv(_CONST dvector& v){
    int mn = v.indexmin();
    int mx = v.indexmax();
    adstring s = qt+str(v(mn))+qt;
    for (int i=mn;i<mx;i++) s = s+cc+qt+str(v(i+1))+qt;
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
    allocate(rwmn,rwmx,clmn,clmx);
}

/****************************************************************
* Constructor                                                   *
****************************************************************/
wts::adstring_matrix::adstring_matrix(int rwmn, int rwmx, ivector& clmns, int clmx){
    allocate(rwmn,rwmx,clmns,clmx);
}

/****************************************************************
* Constructor                                                   *
****************************************************************/
wts::adstring_matrix::adstring_matrix(int rwmn, int rwmx, int clmn, ivector& clmxs){
    allocate(rwmn,rwmx,clmn,clmxs);
}

/****************************************************************
* Constructor                                                   *
****************************************************************/
wts::adstring_matrix::adstring_matrix(int rwmn, int rwmx, ivector& clmns, ivector& clmxs){
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
        cout<<"adstring_matrix::allocate("<<rwmn<<","<<rwmx<<")"<<endl;
        cout<<"nAAs = "<<nAAs<<", ppAAs = "<<ppAAs<<endl;
    }
}

void wts::adstring_matrix::allocate(int rwmn, int rwmx, int clmn, int clmx){
    deallocate();
    ivector clmns(rwmn,rwmx); clmns = clmn;
    ivector clmxs(rwmn,rwmx); clmxs = clmx;
    allocate(rwmn,rwmx,clmns,clmxs);
}

void wts::adstring_matrix::allocate(int rwmn, int rwmx, ivector& clmns, int clmx){
    deallocate();
    ivector clmxs(rwmn,rwmx); clmxs = clmx;
    allocate(rwmn,rwmx,clmns,clmxs);
}

void wts::adstring_matrix::allocate(int rwmn, int rwmx, int clmn, ivector& clmxs){
    deallocate();
    ivector clmns(rwmn,rwmx); clmns = clmn;
    allocate(rwmn,rwmx,clmns,clmxs);
}

void wts::adstring_matrix::allocate(int rwmn, int rwmx, ivector& clmns, ivector& clmxs){
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
        cout<<"adstring_matrix::allocate(int rwmn, int rwmx, ivector& clmns, ivector& clmxs)"<<endl;
        cout<<"rwmn, rwmx = "<<rwmn<<", "<<rwmx<<endl;
        cout<<"clmns = "<<clmns<<",  clmxs = "<<clmxs<<endl;
        cout<<"ppAAs = "; for (int r=0;r<nAAs;r++) cout<<ppAAs[r]<<tb; cout<<endl;
    }
}

adstring& wts::adstring_matrix::operator() (_CONST int i, _CONST int j){
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

adstring_array& wts::adstring_matrix::operator() (_CONST int i){
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

adstring_array& wts::adstring_matrix::operator[] (_CONST int i){
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
bool wts::CompareAdstrings::operator() (_CONST adstring& lhs, _CONST adstring& rhs) _CONST {
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
