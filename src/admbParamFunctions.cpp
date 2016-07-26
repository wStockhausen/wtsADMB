#include <admodel.h>
#include "wtsConsts.hpp"
#include "admbBasicFunctions.hpp"
#include "admbStringFunctions.hpp"
#include "admbParamFunctions.hpp"
using namespace std;
/**
 * Changes:
 * 2014-12-02: 1. Changed void jitterParameter(...) functions to return appropriate value
 *                  (double or dvector) because its not yet possible to set parameter values
 *                  outside tpl code.
 * 2014-12-03: 1. Changed to using std namespace
 * 2015-06-15: 1. Centered jitterParameter() functions around input initial value
 * 2016-07-26: 1. Added descr (description) to writeParameter() functions
*/

/**
 * Write parameter information to an output stream.
 * 
 * @param os - output stream to write to
 * @param p - the parameter
 * @param toR - flag (0/1) to write info in R format
 * @param willBeActive - flag (0/1) to write info ONLY IF parameter is or will be active in some phase
 */
void wts::writeParameter(ostream& os, param_init_number& p, int toR, int willBeActive){                        //wts: new
    if (!willBeActive||(willBeActive&&(p.get_phase_start()>0))){
        if (toR){
            os<<p.get_name()<<"=list("<<"type='param_init_number'"<<cc
                                <<"phase="<<p.get_phase_start()<<cc
                                <<"value="<<value(p)
                                <<"),";
        } else {
            os<<1<<cc<<p.get_phase_start()<<cc<<1<<cc<<1<<cc<<"-Inf"<<cc<<"Inf"<<cc<<p;
            os<<cc<<p.get_name()<<cc<<"'param_init_number'"<<endl;
        }
    }
}

/**
 * Write parameter information to an output stream.
 * 
 * @param os - output stream to write to
 * @param p - the parameter
 * @param toR - flag (0/1) to write info in R format
 * @param willBeActive - flag (0/1) to write info ONLY IF parameter is or will be active in some phase
 * @param descr - comma-separated description
 */
void wts::writeParameter(ostream& os, param_init_number& p, int toR, int willBeActive, adstring descr){                        //wts: new
    if (!willBeActive||(willBeActive&&(p.get_phase_start()>0))){
        if (toR){
            os<<p.get_name()<<"=list("<<"type='param_init_number'"<<cc
                                <<"phase="<<p.get_phase_start()<<cc
                                <<"description='"<<descr<<"'"<<cc
                                <<"value="<<value(p)
                                <<"),";
        } else {
            os<<1<<cc<<p.get_phase_start()<<cc<<1<<cc<<1<<cc<<"-Inf"<<cc<<"Inf"<<cc<<p;
            os<<cc<<p.get_name()<<cc<<"'param_init_number'"<<cc<<descr<<endl;
        }
    }
}

/**
 * Write parameter information to an output stream.
 * 
 * @param os - output stream to write to
 * @param p - the parameter
 * @param toR - flag (0/1) to write info in R format
 * @param willBeActive - flag (0/1) to write info ONLY IF parameter is or will be active in some phase
 */
void wts::writeParameter(ostream& os, param_init_bounded_number& p, int toR, int willBeActive){
    if (!willBeActive||(willBeActive&&(p.get_phase_start()>0))){
        if (toR){
            os<<p.get_name()<<"=list("<<"type='param_init_bounded_number'"<<cc
                                <<"phase="<<p.get_phase_start()<<cc
                                <<"bounds=c("<<p.get_minb()<<cc<<p.get_maxb()<<")"<<cc
                                <<"value="<<value(p)
                                <<"),";
        } else {
            os<<1<<cc<<p.get_phase_start()<<cc<<1<<cc<<1<<cc<<p.get_minb()<<cc<<p.get_maxb()<<cc<<p;
            os<<cc<<p.get_name()<<cc<<"'param_init_bounded_number'"<<endl;
        }
    }
    
}

/**
 * Write parameter information to an output stream.
 * 
 * @param os - output stream to write to
 * @param p - the parameter
 * @param toR - flag (0/1) to write info in R format
 * @param willBeActive - flag (0/1) to write info ONLY IF parameter is or will be active in some phase
 * @param descr - comma-separated description
 */
void wts::writeParameter(ostream& os, param_init_bounded_number& p, int toR, int willBeActive, adstring descr){
    if (!willBeActive||(willBeActive&&(p.get_phase_start()>0))){
        if (toR){
            os<<p.get_name()<<"=list("<<"type='param_init_bounded_number'"<<cc
                                <<"phase="<<p.get_phase_start()<<cc
                                <<"bounds=c("<<p.get_minb()<<cc<<p.get_maxb()<<")"<<cc
                                <<"description='"<<descr<<"'"<<cc
                                <<"value="<<value(p)
                                <<"),";
        } else {
            os<<1<<cc<<p.get_phase_start()<<cc<<1<<cc<<1<<cc<<p.get_minb()<<cc<<p.get_maxb()<<cc<<p;
            os<<cc<<p.get_name()<<cc<<"'param_init_bounded_number'"<<cc<<descr<<endl;
        }
    }
    
}

/**
 * Write parameter number_vector information to an output stream.
 * 
 * @param os - output stream to write to
 * @param p - the parameter number_vector
 * @param toR - flag (0/1) to write info in R format
 * @param willBeActive - flag (0/1) to write info ONLY IF parameter number_vector is or will be active in some phase
 */
void wts::writeParameter(ostream& os, param_init_bounded_number_vector& p, int toR, int willBeActive){
    int mn = p.indexmin();
    int mx = p.indexmax();
    for (int i=mn;i<=mx;i++){
        wts::writeParameter(os,p[i],toR,willBeActive);
    }
}

/**
 * Write parameter number_vector information to an output stream.
 * 
 * @param os - output stream to write to
 * @param p - the parameter number_vector
 * @param toR - flag (0/1) to write info in R format
 * @param willBeActive - flag (0/1) to write info ONLY IF parameter number_vector is or will be active in some phase
 * @param descr - comma-separated description
 */
void wts::writeParameter(ostream& os, param_init_bounded_number_vector& p, int toR, int willBeActive, adstring descr){
    int mn = p.indexmin();
    int mx = p.indexmax();
    for (int i=mn;i<=mx;i++){
        wts::writeParameter(os,p[i],toR,willBeActive,descr);
    }
}

/**
 * Write parameter vector information to an output stream.
 * 
 * @param os - output stream to write to
 * @param p - the parameter vector
 * @param toR - flag (0/1) to write info in R format
 * @param willBeActive - flag (0/1) to write info ONLY IF parameter is or will be active in some phase
 */
void wts::writeParameter(ostream& os, param_init_vector& p, int toR, int willBeActive){
    int mn = p.indexmin();
    int mx = p.indexmax();
    if (!willBeActive||(willBeActive&&(p.get_phase_start()>0))){
        if (toR){
            os<<p.get_name()<<"=list("<<"type='param_init_vector'"<<cc
                                <<"dims=c("<<mn<<cc<<mx<<")"<<cc
                                <<"phase="<<p.get_phase_start()<<cc
                                <<"value=c("; {for (int i=mn;i<mx;i++) os<<value(p(i))<<cc;} os<<value(p(mx))<<")";
            os<<"),";
        } else {        
            for (int i=mn;i<=mx;i++) {
                os<< i<<cc<<p.get_phase_start()<<cc<<mn<<cc<<mx<<cc<<"-Inf"<<cc<<"Inf"<<cc<<p(i);
                os<<cc<<p.get_name()<<cc<<"'param_init_vector'"<<endl;
            }
        }
    }
}

/**
 * Write parameter vector information to an output stream.
 * 
 * @param os - output stream to write to
 * @param p - the parameter vector
 * @param toR - flag (0/1) to write info in R format
 * @param willBeActive - flag (0/1) to write info ONLY IF parameter is or will be active in some phase
 * @param descr - comma-separated description
 */
void wts::writeParameter(ostream& os, param_init_vector& p, int toR, int willBeActive, adstring descr){
    int mn = p.indexmin();
    int mx = p.indexmax();
    if (!willBeActive||(willBeActive&&(p.get_phase_start()>0))){
        if (toR){
            os<<p.get_name()<<"=list("<<"type='param_init_vector'"<<cc
                                <<"dims=c("<<mn<<cc<<mx<<")"<<cc
                                <<"phase="<<p.get_phase_start()<<cc
                                <<"description='"<<descr<<"'"<<cc
                                <<"value=c("; {for (int i=mn;i<mx;i++) os<<value(p(i))<<cc;} os<<value(p(mx))<<")";
            os<<"),";
        } else {        
            for (int i=mn;i<=mx;i++) {
                os<< i<<cc<<p.get_phase_start()<<cc<<mn<<cc<<mx<<cc<<"-Inf"<<cc<<"Inf"<<cc<<p(i);
                os<<cc<<p.get_name()<<cc<<"'param_init_vector'"<<cc<<descr<<endl;
            }
        }
    }
}

/**
 * Write parameter vector information to an output stream.
 * 
 * @param os - output stream to write to
 * @param p - the parameter vector
 * @param toR - flag (0/1) to write info in R format
 * @param willBeActive - flag (0/1) to write info ONLY IF parameter is or will be active in some phase
 */
void wts::writeParameter(ostream& os, param_init_bounded_vector& p, int toR, int willBeActive){
    int mn = p.indexmin();
    int mx = p.indexmax();
    if (!willBeActive||(willBeActive&&(p.get_phase_start()>0))){
        if (toR){
            os<<p.get_name()<<"=list("<<"type='param_init_bounded_vector'"<<cc
                                <<"dims=c("<<p.indexmin()<<cc<<p.indexmax()<<")"<<cc
                                <<"phase="<<p.get_phase_start()<<cc
                                <<"bounds=c("<<p.get_minb()<<cc<<p.get_maxb()<<")"<<cc
                                <<"value=c("; {for (int i=mn;i<mx;i++) os<<value(p(i))<<cc;} os<<value(p(mx))<<")";
           os<<"),";
        } else {
            for (int i=mn;i<=mx;i++) {
                os<< i<<cc<<p.get_phase_start()<<cc<<mn<<cc<<mx<<cc<<p.get_minb()<<cc<<p.get_maxb()<<cc<<p(i);
                os<<cc<<p.get_name()<<cc<<"'param_init_bounded_vector'"<<endl;
            }
        }
    }
}

/**
 * Write parameter vector information to an output stream.
 * 
 * @param os - output stream to write to
 * @param p - the parameter vector
 * @param toR - flag (0/1) to write info in R format
 * @param willBeActive - flag (0/1) to write info ONLY IF parameter is or will be active in some phase
 * @param descr - comma-separated description
 */
void wts::writeParameter(ostream& os, param_init_bounded_vector& p, int toR, int willBeActive, adstring descr){
    int mn = p.indexmin();
    int mx = p.indexmax();
    if (!willBeActive||(willBeActive&&(p.get_phase_start()>0))){
        if (toR){
            os<<p.get_name()<<"=list("<<"type='param_init_bounded_vector'"<<cc
                                <<"dims=c("<<p.indexmin()<<cc<<p.indexmax()<<")"<<cc
                                <<"phase="<<p.get_phase_start()<<cc
                                <<"bounds=c("<<p.get_minb()<<cc<<p.get_maxb()<<")"<<cc
                                <<"description='"<<descr<<"'"<<cc
                                <<"value=c("; {for (int i=mn;i<mx;i++) os<<value(p(i))<<cc;} os<<value(p(mx))<<")";
           os<<"),";
        } else {
            for (int i=mn;i<=mx;i++) {
                os<< i<<cc<<p.get_phase_start()<<cc<<mn<<cc<<mx<<cc<<p.get_minb()<<cc<<p.get_maxb()<<cc<<p(i);
                os<<cc<<p.get_name()<<cc<<"'param_init_bounded_vector'"<<cc<<descr<<endl;
            }
        }
    }
}

/**
 * Write parameter vector_vector information to an output stream.
 * 
 * @param os - output stream to write to
 * @param p - the parameter vector_vector
 * @param toR - flag (0/1) to write info in R format
 * @param willBeActive - flag (0/1) to write info ONLY IF parameter is or will be active in some phase
 */
void wts::writeParameter(ostream& os, param_init_bounded_vector_vector& p, int toR, int willBeActive){
    int mn = p.indexmin();
    int mx = p.indexmax();
    for (int i=mn;i<=mx;i++){
        wts::writeParameter(os,p[i],toR,willBeActive);
    }
}

/**
 * Write parameter vector_vector information to an output stream.
 * 
 * @param os - output stream to write to
 * @param p - the parameter vector_vector
 * @param toR - flag (0/1) to write info in R format
 * @param willBeActive - flag (0/1) to write info ONLY IF parameter is or will be active in some phase
 * @param descr - comma-separated description
 */
void wts::writeParameter(ostream& os, param_init_bounded_vector_vector& p, int toR, int willBeActive, adstring descr){
    int mn = p.indexmin();
    int mx = p.indexmax();
    for (int i=mn;i<=mx;i++){
        wts::writeParameter(os,p[i],toR,willBeActive,descr);
    }
}

/**
 * Write parameter vector information to an output stream.
 * 
 * @param os - output stream to write to
 * @param p - the parameter vector
 * @param toR - flag (0/1) to write info in R format
 * @param willBeActive - flag (0/1) to write info ONLY IF parameter is or will be active in some phase
 */
void wts::writeParameter(ostream& os, param_init_bounded_dev_vector& p, int toR, int willBeActive){
    int mn = p.indexmin();
    int mx = p.indexmax();
    if (!willBeActive||(willBeActive&&(p.get_phase_start()>0))){
        if (toR){
            os<<p.get_name()<<"=list("<<"type=param_init_bounded_dev_vector"<<cc
                                <<"dims=c("<<p.indexmin()<<cc<<p.indexmax()<<")"<<cc
                                <<"phase="<<p.get_phase_start()<<cc
                                <<"bounds=c("<<p.get_minb()<<cc<<p.get_maxb()<<")"<<cc
                                <<"value=c("; {for (int i=mn;i<mx;i++) os<<value(p(i))<<cc;} os<<value(p(mx))<<")";
           os<<"),";
        } else {
            for (int i=mn;i<=mx;i++) {
                os<< i<<cc<<p.get_phase_start()<<cc<<mn<<cc<<mx<<cc<<p.get_minb()<<cc<<p.get_maxb()<<cc<<p(i);
                os<<cc<<p.get_name()<<cc<<"'param_init_bounded_dev_vector'"<<endl;
            }
        }
    }
}

/**
 * Write parameter vector information to an output stream.
 * 
 * @param os - output stream to write to
 * @param p - the parameter vector
 * @param toR - flag (0/1) to write info in R format
 * @param willBeActive - flag (0/1) to write info ONLY IF parameter is or will be active in some phase
 * @param descr - comma-separated description
 */
void wts::writeParameter(ostream& os, param_init_bounded_dev_vector& p, int toR, int willBeActive, adstring descr){
    int mn = p.indexmin();
    int mx = p.indexmax();
    if (!willBeActive||(willBeActive&&(p.get_phase_start()>0))){
        if (toR){
            os<<p.get_name()<<"=list("<<"type=param_init_bounded_dev_vector"<<cc
                                <<"dims=c("<<p.indexmin()<<cc<<p.indexmax()<<")"<<cc
                                <<"phase="<<p.get_phase_start()<<cc
                                <<"bounds=c("<<p.get_minb()<<cc<<p.get_maxb()<<")"<<cc
                                <<"description='"<<descr<<"'"<<cc
                                <<"value=c("; {for (int i=mn;i<mx;i++) os<<value(p(i))<<cc;} os<<value(p(mx))<<")";
           os<<"),";
        } else {
            for (int i=mn;i<=mx;i++) {
                os<< i<<cc<<p.get_phase_start()<<cc<<mn<<cc<<mx<<cc<<p.get_minb()<<cc<<p.get_maxb()<<cc<<p(i);
                os<<cc<<p.get_name()<<cc<<"'param_init_bounded_dev_vector'"<<cc<<descr<<endl;
            }
        }
    }
}

/**
 * Jitter the initial parameter (p) value based on the jitter factor (fac).
 * Jittering occurs only if the estimation phase is > 0.
 * 
 * @param p   - the parameter to jitter
 * @param fac - the jitter factor (0-1)
 * @param rng - random number generator object
 * 
 * @return - value for jittered parameter. Must be assigned to p in the tpl code.
 */
double wts::jitterParameter(param_init_number& p, double fac, random_number_generator& rng){ 
    double v = value(p);
    if (p.get_phase_start()>0){//arithmetic jitter
//        cout<<"number:"<<endl;
        double r = rng.better_rand();
        double vp = v+wts::min(1.0,fac)*2.0*(r-0.5);
//        p.set_initial_value(vp);<-doesn't work
//        cout<<"r = "<<r<<cc<<"fac = "<<fac<<cc<<"minf = "<<wts::min(1.0,fac)<<cc<<"vp = "<<vp<<endl;
//        cout<<"orig = "<<v<<cc<<"new  = "<<p<<endl;
        return(vp);
    }
    return(v);
}

/**
 * Jitter the initial parameter (p) value based on the jitter factor (fac).
 * Jittering occurs only if the estimation phase is > 0.
 * 
 * @param p   - the parameter to jitter
 * @param fac - the jitter factor (0-1)
 * @param rng - random number generator object
 * 
 * @return - value for jittered parameter. Must be assigned to p in the tpl code.
 */
double wts::jitterParameter(param_init_bounded_number& p, double fac, random_number_generator& rng){
    double v = value(p);
    cout<<"Starting wts::jitterParameter(param_init_bounded_number& p, double fac, random_number_generator& rng)"<<endl;
    cout<<"name = "<<p.get_name()<<tb<<"phase =  "<<p.get_phase_start()<<endl;
    if (p.get_phase_start()>0){//arithmetic jitter
//        cout<<"bounded number:"<<endl;
        double d = p.get_maxb()-p.get_minb();
        double r = rng.better_rand();
        double vp = min(max(p.get_minb()+0.01*d,v+wts::min(1.0,fac)*(r-0.5)*d),p.get_maxb()-0.01*d);
//        p.set_initial_value(vp);<-doesn't work
        cout<<"r = "<<r<<cc<<"fac = "<<fac<<cc<<"minf = "<<wts::min(1.0,fac)<<cc<<"vp = "<<vp<<endl;
        cout<<"orig = "<<v<<cc<<"lims="<<p.get_minb()<<cc<<p.get_maxb()<<endl;
        return(vp);
    }
    return(v);
}

/**
 * Jitter the initial parameter vector (p) values based on the jitter factor (fac).
 * Jittering occurs only if the estimation phase is > 0.
 * 
 * @param p   - the parameter vector to jitter
 * @param fac - the jitter factor (0-1)
 * @param rng - random number generator object
 * 
 * @return - values for jittered parameter vector. Must be assigned to p in the tpl code.
 */
dvector wts::jitterParameter(param_init_bounded_vector& p, double fac, random_number_generator& rng){
    dvector v = value(p);
    if (p.get_phase_start()>0){//arithmetic jitter
//        cout<<"vector:"<<endl;
        double d = p.get_maxb()-p.get_minb();
        for (int i=p.indexmin();i<=p.indexmax();i++){
            double r = rng.better_rand();
            double vp = min(max(p.get_minb()+0.01*d,v(i)+wts::min(1.0,fac)*(r-0.5)*d),p.get_maxb()-0.01*d);
//            p(i) = vp;<-doesn't work
            v(i) = vp;
//            cout<<"r = "<<r<<cc<<"fac = "<<fac<<cc<<"minf = "<<wts::min(1.0,fac)<<cc<<"vp = "<<vp<<endl;
        }
//        cout<<"orig = "<<p<<endl;
//        cout<<"new  = "<<v<<endl;
//        cout<<"lims="<<p.get_minb()<<cc<<p.get_maxb()<<endl;
    }
    return(v);
}

/**
 * Jitter the initial parameter vector (p) values based on the jitter factor (fac).
 * Jittering occurs only if the estimation phase is > 0.
 * 
 * @param p   - the devs parameter vector to jitter
 * @param fac - the jitter factor (0-1)
 * @param rng - random number generator object
 * 
 * @return - values for jittered parameter vector. Must be assigned to p in the tpl code.
 */
dvector wts::jitterParameter(param_init_bounded_dev_vector& p, double fac, random_number_generator& rng){
    dvector v = value(p);
    if (p.get_phase_start()>0){//arithmetic jitter
//        cout<<"devs vector:"<<endl;
        double d = p.get_maxb()-p.get_minb();
        for (int i=p.indexmin();i<=p.indexmax();i++){
            double r = rng.better_rand();
            double vp = wts::min(wts::max(p.get_minb()+0.01*d,v(i)+wts::min(1.0,fac)*(r-0.5)*d),p.get_maxb()-0.01*d);
//            p(i) = vp;<-doesn't work
            v(i) = vp;
//            cout<<"r = "<<r<<cc<<"fac = "<<fac<<cc<<"minf = "<<wts::min(1.0,fac)<<cc<<"vp = "<<vp<<endl;
        }
//        cout<<"orig = "<<p<<endl;
//        cout<<"new  = "<<v<<endl;
//        cout<<"lims="<<p.get_minb()<<cc<<p.get_maxb()<<endl;
    }
    return(v-mean(v));//make sure vector is a devs vector
}