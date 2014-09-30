#include <admodel.h>
#include "wtsConsts.hpp"
#include "admbBasicFunctions.hpp"
#include "admbParamFunctions.hpp"

/**
 * Write parameter information to an output stream.
 * 
 * @param os - output stream to write to
 * @param p - the parameter
 * @param toR - flag (0/1) to write info in R format
 * @param willBeActive - flag (0/1) to write info ONLY IF parameter is or will be active in some phase
 */
void wts::writeParameter(std::ostream& os, param_init_number& p, int toR, int willBeActive){                        //wts: new
    if (!willBeActive||(willBeActive&&(p.get_phase_start()>0))){
        if (toR){
            os<<p.get_name()<<"=list("<<"type='param_init_number'"<<cc
                                <<"phase="<<p.get_phase_start()<<cc
                                <<"value="<<value(p)
                                <<"),";
        } else {
            os<<1<<cc<<p.get_phase_start()<<cc<<1<<cc<<1<<cc<<"-Inf"<<cc<<"Inf"<<cc<<p<<cc<<p.get_name()<<cc<<"'param_init_number'"<<std::endl;
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
void wts::writeParameter(std::ostream& os, param_init_bounded_number& p, int toR, int willBeActive){
    if (!willBeActive||(willBeActive&&(p.get_phase_start()>0))){
        if (toR){
            os<<p.get_name()<<"=list("<<"type='param_init_bounded_number'"<<cc
                                <<"phase="<<p.get_phase_start()<<cc
                                <<"bounds=c("<<p.get_minb()<<cc<<p.get_maxb()<<")"<<cc
                                <<"value="<<value(p)
                                <<"),";
        } else {
            os<<1<<cc<<p.get_phase_start()<<cc<<1<<cc<<1<<cc<<p.get_minb()<<cc<<p.get_maxb()<<cc<<p<<cc<<p.get_name()<<cc<<"'param_init_bounded_number'"<<std::endl;
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
void wts::writeParameter(std::ostream& os, param_init_vector& p, int toR, int willBeActive){
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
            for (int i=mn;i<=mx;i++) os<< i<<cc<<p.get_phase_start()<<cc<<mn<<cc<<mx<<cc<<"-Inf"<<cc<<"Inf"<<cc<<p(i)<<cc<<p.get_name()<<cc<<"'param_init_vector'"<<std::endl;
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
void wts::writeParameter(std::ostream& os, param_init_bounded_vector& p, int toR, int willBeActive){
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
            for (int i=mn;i<=mx;i++) os<< i<<cc<<p.get_phase_start()<<cc<<mn<<cc<<mx<<cc<<p.get_minb()<<cc<<p.get_maxb()<<cc<<p(i)<<cc<<p.get_name()<<cc<<"'param_init_bounded_vector'"<<std::endl;
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
void wts::writeParameter(std::ostream& os, param_init_bounded_dev_vector& p, int toR, int willBeActive){
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
            for (int i=mn;i<=mx;i++) os<< i<<cc<<p.get_phase_start()<<cc<<mn<<cc<<mx<<cc<<p.get_minb()<<cc<<p.get_maxb()<<cc<<p(i)<<cc<<p.get_name()<<cc<<"'param_init_bounded_dev_vector'"<<std::endl;
        }
    }
}

/**
 * Jitter the initial parameter (p) value based on the jitter factor (fac).
 * 
 * @param p   - the parameter to jitter
 * @param fac - the jitter factor (0-1)
 * @param rng - random number generator object
 */
void wts::jitterParameter(param_init_number& p, double fac, random_number_generator& rng){ 
    if (p.get_phase_start()>0){//arithmetic jitter
//        cout<<"number:"<<endl;
        double v = value(p);
        double r = rng.better_rand();
        double vp = v+wts::min(1.0,fac)*2.0*(r-0.5);
        p.set_initial_value(vp);
//        cout<<"r = "<<r<<cc<<"fac = "<<fac<<cc<<"minf = "<<wts::min(1.0,fac)<<cc<<"vp = "<<vp<<endl;
//        cout<<"orig = "<<v<<cc<<"new  = "<<p<<endl;
    }
}

/**
 * Jitter the initial parameter (p) value based on the jitter factor (fac).
 * 
 * @param p   - the parameter to jitter
 * @param fac - the jitter factor (0-1)
* @param rng - random number generator object
 */
void wts::jitterParameter(param_init_bounded_number& p, double fac, random_number_generator& rng){
    if (p.get_phase_start()>0){//arithmetic jitter
//        cout<<"bounded number:"<<endl;
        double v = value(p);
        double d = p.get_maxb()-p.get_minb();
        double r = rng.better_rand();
        double vp = p.get_minb()+0.5*d+wts::min(1.0,fac)*(r-0.5)*d;
        p.set_initial_value(vp);
//        cout<<"r = "<<r<<cc<<"fac = "<<fac<<cc<<"minf = "<<wts::min(1.0,fac)<<cc<<"vp = "<<vp<<endl;
//        cout<<"orig = "<<v<<cc<<"new  = "<<p<<cc<<"lims="<<p.get_minb()<<cc<<p.get_maxb()<<endl;
    }
}

/**
 * Jitter the initial parameter vector (p) values based on the jitter factor (fac).
 * 
 * @param p   - the parameter vector to jitter
 * @param fac - the jitter factor (0-1)
 * @param rng - random number generator object
 */
void wts::jitterParameter(param_init_bounded_vector& p, double fac, random_number_generator& rng){
    if (p.get_phase_start()>0){//arithmetic jitter
//        cout<<"vector:"<<endl;
        dvector v = value(p);
        double d = p.get_maxb()-p.get_minb();
        for (int i=p.indexmin();i<=p.indexmax();i++){
            double r = rng.better_rand();
            double vp = p.get_minb()+0.5*d+wts::min(1.0,fac)*(r-0.5)*d;
            p(i) = vp;
//            cout<<"r = "<<r<<cc<<"fac = "<<fac<<cc<<"minf = "<<wts::min(1.0,fac)<<cc<<"vp = "<<vp<<endl;
//            cout<<"orig = "<<v[i]<<cc<<"new  = "<<p[i]<<cc<<"lims="<<p.get_minb()<<cc<<p.get_maxb()<<endl;
        }
    }
}

/**
 * Jitter the initial parameter vector (p) values based on the jitter factor (fac).
 * 
 * @param p   - the parameter vector to jitter
 * @param fac - the jitter factor (0-1)
 * @param rng - random number generator object
 */
void wts::jitterParameter(param_init_bounded_dev_vector& p, double fac, random_number_generator& rng){
    if (p.get_phase_start()>0){//arithmetic jitter
//        cout<<"devs vector:"<<endl;
        dvector v = value(p);
        double d = p.get_maxb()-p.get_minb();
        for (int i=p.indexmin();i<=p.indexmax();i++){
            double r = rng.better_rand();
            double vp = p.get_minb()+0.5*d+wts::min(1.0,fac)*(r-0.5)*d;
            p(i) = vp;
//            cout<<"r = "<<r<<cc<<"fac = "<<fac<<cc<<"minf = "<<wts::min(1.0,fac)<<cc<<"vp = "<<vp<<endl;
//            cout<<"orig = "<<v[i]<<cc<<"new  = "<<p[i]<<cc<<"lims="<<p.get_minb()<<cc<<p.get_maxb()<<endl;
        }
    }
}