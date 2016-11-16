//admbProbFunctions.cpp
#include <admodel.h>
#include "wtsConsts.hpp"
#include "admbBasicFunctions.hpp"
#include "admbProbFunctions.hpp"
using namespace std;
/**
 * Changes:
 * 2014-12-03: 1. Changed to using std namespace
*/
//-------------------------------------------------------------

/****************************************************************
* name      : cdf_normal                                        *
* purpose   : compute cdf of normal distribution                *
*   parameters:                                                 *
*       mu : location parameter (mean)                          *
*       sd:  standard deviation                                 *
*       lb : lower bound                                        *
*       ub : upper bound                                        *
****************************************************************/
double wts::cdf_normal(const double& mu,const double& sd,const double& lb,const double& ub){
//      if (debug20) cout<<endl<<"Compute cdf_normal"<<endl;
    double nf = 0.0;
    if (sd>0) {
        double zn = (lb-mu)/sd;
        double zx = (ub-mu)/sd;
        nf = cumd_norm(zx)-cumd_norm(zn);
    } else {
        if ((lb<=mu)&&(mu<=ub)) nf = 1.0;
    }
    return nf;
}
//-------------------------------------------------------------
dvariable wts::cdf_normal(const dvariable& mu,const double& sd,const double& lb,const double& ub){
    RETURN_ARRAYS_INCREMENT();
//      if (debug20) cout<<endl<<"Compute cdf_normal"<<endl;
    dvariable nf = 0.0;
    if (sd>0) {
        dvariable zn = (lb-mu)/sd;
        dvariable zx = (ub-mu)/sd;
        nf = cumd_norm(zx)-cumd_norm(zn);
    } else {
        if ((lb<=mu)&&(mu<=ub)) nf = 1.0;
    }
    RETURN_ARRAYS_DECREMENT();
    return nf;
}
//-------------------------------------------------------------
dvariable wts::cdf_normal(const dvariable& mu,const dvariable& sd,const double& lb,const double& ub){
    RETURN_ARRAYS_INCREMENT();
//        if (debug20) cout<<endl<<"Compute cdf_normal"<<endl;
    dvariable nf = 0.0;
    if (sd>0) {
        dvariable zn = (lb-mu)/sd;
        dvariable zx = (ub-mu)/sd;
        nf = cumd_norm(zx)-cumd_norm(zn);
    } else {
        if ((lb<=mu)&&(mu<=ub)) nf = 1.0;
    }
    RETURN_ARRAYS_DECREMENT();
    return nf;
}

/****************************************************************
* name      : log_normal_density                                *
* purpose   : compute log of normal distribution                *
*   parameters:                                                 *
*       z: normalized random deviate (z=(x-mu)/sdv)             *
****************************************************************/
//-------------------------------------------------------------
double    wts::log_normal_density(const double& z){
    double d = -0.5*(log(2.0*PI)+square(z));
    return d;
}
//-------------------------------------------------------------
dvariable wts::log_normal_density(const prevariable& z){
    RETURN_ARRAYS_INCREMENT();
    dvariable d = -0.5*(log(2.0*PI)+square(z));
    RETURN_ARRAYS_DECREMENT();
    return d;
}

//-------------------------------------------------------------
dvector wts::log_normal_density(const dvector& z){
    RETURN_ARRAYS_INCREMENT();
    dvector d = -0.5*(log(2.0*PI)+elem_prod(z,z));
    RETURN_ARRAYS_DECREMENT();
    return d;
}

//-------------------------------------------------------------
dvar_vector wts::log_normal_density(const dvar_vector& z){
    RETURN_ARRAYS_INCREMENT();
    dvar_vector d = -0.5*(log(2.0*PI)+elem_prod(z,z));
    RETURN_ARRAYS_DECREMENT();
    return d;
}

/****************************************************************
* name      : log_normal_density                                *
* purpose   : compute log of normal distribution                *
*   parameters:                                                 *
*       x  : value at which to evaluate pdf                     *
*       mu : mean                                               *
*       sdv: standard deviation                                 *
****************************************************************/
//-------------------------------------------------------------
double    wts::log_normal_density(const double& x,const double& mu,const double& sdv){
    double z = (x-mu)/sdv;
    return log_normal_density(z);
}
//-------------------------------------------------------------
dvariable wts::log_normal_density(const prevariable& x,const double& mu,const double& sdv){
    RETURN_ARRAYS_INCREMENT();
    dvariable z = (x-mu)/sdv;
    dvariable d = log_normal_density(z);
    RETURN_ARRAYS_DECREMENT();
    return d;
}
//-------------------------------------------------------------
dvariable wts::log_normal_density(const double& x,const prevariable& mu,const prevariable& sdv){
    RETURN_ARRAYS_INCREMENT();
    dvariable z = (x-mu)/sdv;
    dvariable d = log_normal_density(z);
    RETURN_ARRAYS_DECREMENT();
    return d;
}
//-------------------------------------------------------------
dvariable wts::log_normal_density(const prevariable& x,const prevariable& mu,const prevariable& sdv){
    RETURN_ARRAYS_INCREMENT();
    dvariable z = (x-mu)/sdv;
    dvariable d = log_normal_density(z);
    RETURN_ARRAYS_DECREMENT();
    return d;
}
//-------------------------------------------------------------
dvector wts::log_normal_density(const dvector& x,const double& mu,const double& sdv){
    dvector z = (x-mu)/sdv;
    return log_normal_density(z);
}
//-------------------------------------------------------------
dvar_vector wts::log_normal_density(const dvar_vector& x,const double& mu,const double& sdv){
    RETURN_ARRAYS_INCREMENT();
    dvar_vector z = (x-mu)/sdv;
    dvar_vector d = log_normal_density(z);
    RETURN_ARRAYS_DECREMENT();
    return d;
}

/****************************************************************
* name      : log_lognormal_density                             *
* purpose   : compute log of lognormal distribution             *
*   parameters:                                                 *
*       x  : arithmetic-scale value                             *
*       med: arithmetic-scale median                            *
*       cv: arithmetic-scale cv (stdev(X)/mean(X))              *
****************************************************************/
//-------------------------------------------------------------
double wts::log_lognormal_density(const double& x,const double& med,const double& cv){
    double sdv = sqrt(log(1.0+square(cv)));
    double d = -0.5*log(2.0*PI*square(x*sdv))-0.5*square((log(x)-log(med))/sdv);
    return d;
}
//-------------------------------------------------------------
dvariable wts::log_lognormal_density(const prevariable& x,const double& med,const double& cv){
    RETURN_ARRAYS_INCREMENT();
    double sdv = sqrt(log(1.0+square(cv)));
    dvariable d = -0.5*log(2.0*PI*square(x*sdv))-0.5*square((log(x)-log(med))/sdv);
    RETURN_ARRAYS_DECREMENT();
    return d;
}
//-------------------------------------------------------------
dvariable wts::log_lognormal_density(const double& x,const prevariable& med,const prevariable& cv){
    RETURN_ARRAYS_INCREMENT();
    dvariable sdv = sqrt(log(1.0+square(cv)));
    dvariable d = -0.5*log(2.0*PI*square(x*sdv))-0.5*square((log(x)-log(med))/sdv);
    RETURN_ARRAYS_DECREMENT();
    return d;
}
//-------------------------------------------------------------
dvariable wts::log_lognormal_density(const prevariable& x,const prevariable& med,const prevariable& cv){
    RETURN_ARRAYS_INCREMENT();
    dvariable sdv = sqrt(log(1.0+square(cv)));
    dvariable d = -0.5*log(2.0*PI*square(x*sdv))-0.5*square((log(x)-log(med))/sdv);
    RETURN_ARRAYS_DECREMENT();
    return d;
}
//-------------------------------------------------------------
dvector wts::log_lognormal_density(const dvector& x,const double& med,const double& cv){
    double  sdv = sqrt(log(1.0+square(cv)));
    dvector z = (log(x)-log(med))/sdv;
    dvector d = -0.5*log(2.0*PI)-log(x*sdv)-0.5*elem_prod(z,z);
    return d;
}
//-------------------------------------------------------------
dvar_vector wts::log_lognormal_density(const dvar_vector& x,const double& med,const double& cv){
    RETURN_ARRAYS_INCREMENT();
    double sdv = sqrt(log(1.0+square(cv)));
    dvar_vector z = (log(x)-log(med))/sdv;
    dvar_vector d = -0.5*log(2.0*PI)-log(x*sdv)-0.5*elem_prod(z,z);
    RETURN_ARRAYS_DECREMENT();
    return d;
}

/************************************************************************
* name      : log_gamma_density                                         *
* purpose   : compute log of gamma pdf                                  *
 *                                                                      *
* log_gamma_density(x,r,mu) = r*log(mu)-log_gamma(r)+(r-1)*log(x)-mu*x  *
* gamma(x,r,mu) = (mu^r)/gamma(r) * x^(r-1) * exp(-mu*x)                *
* This is SAME as Gelman et al., Bayesian Data Analysis                 *
*   parameters:                                                         *
*       x : value                                                       *
*       r : location parameter (r = mu*E[x])                            *
*       mu: rate (inverse scale) parameter                              *
************************************************************************/
dvector wts::log_gamma_density(const dvector& xv,const double& r,const double& mu){
    dvector xp = xv+1.0e-10;
    dvector d = r*log(mu)-::gammln(r)+(r-1.0)*log(xp)-mu*xp;
    return d;
}
/************************************************************************
* name      : log_gamma_density                                         *
* purpose   : compute log of gamma pdf                                  *
 *                                                                      *
* log_gamma_density(x,r,mu) = r*log(mu)-log_gamma(r)+(r-1)*log(x)-mu*x  *
* gamma(x,r,mu) = (mu^r)/gamma(r) * x^(r-1) * exp(-mu*x)                *
* This is SAME as Gelman et al., Bayesian Data Analysis                 *
*   parameters:                                                         *
*       x : value                                                       *
*       r : location parameter (r = mu*E[x])                            *
*       mu: rate (inverse scale) parameter                              *
************************************************************************/
dvar_vector wts::log_gamma_density(const dvar_vector& xv,const double& r,const double& mu){
    RETURN_ARRAYS_INCREMENT();
    dvar_vector xp = xv+1.0e-10;
    dvar_vector d = r*log(mu)-::gammln(r)+(r-1.0)*log(xp)-mu*xp;
    RETURN_ARRAYS_DECREMENT();
    return d;
}
/************************************************************************
* name      : log_gamma_density                                         *
* purpose   : compute log of gamma pdf                                  *
 *                                                                      *
* log_gamma_density(x,r,mu) = r*log(mu)-log_gamma(r)+(r-1)*log(x)-mu*x  *
* gamma(x,r,mu) = (mu^r)/gamma(r) * x^(r-1) * exp(-mu*x)                *
* This is SAME as Gelman et al., Bayesian Data Analysis                 *
*   parameters:                                                         *
*       x : value                                                       *
*       r : location parameter (r = mu*E[x])                            *
*       mu: rate (inverse scale) parameter                              *
************************************************************************/
dvar_vector wts::log_gamma_density(const dvector& xv,const prevariable& r,const prevariable& mu){
    //cout<<"Starting log_gamma_density(dvar_vector&, prevariable&, prevariable&)"<<endl;
    RETURN_ARRAYS_INCREMENT();
    dvector xp = xv+1.0e-10;
    dvar_vector d = r*log(mu)-::gammln(r)+(r-1.0)*log(xp)-mu*xp;
    RETURN_ARRAYS_DECREMENT();
    //cout<<"Finished log_gamma_density(dvector&, prevariable&, prevariable&)"<<endl;
    return d;
}
/************************************************************************
* name      : log_gamma_density                                         *
* purpose   : compute log of gamma pdf                                  *
 *                                                                      *
* log_gamma_density(x,r,mu) = r*log(mu)-log_gamma(r)+(r-1)*log(x)-mu*x  *
* gamma(x,r,mu) = (mu^r)/gamma(r) * x^(r-1) * exp(-mu*x)                *
* This is SAME as Gelman et al., Bayesian Data Analysis                 *
*   parameters:                                                         *
*       x : value                                                       *
*       r : location parameter (r = mu*E[x])                            *
*       mu: rate (inverse scale) parameter                              *
************************************************************************/
dvar_vector wts::log_gamma_density(const dvar_vector& xv,const prevariable& r,const prevariable& mu){
    //cout<<"Starting log_gamma_density(dvar_vector&, prevariable&, prevariable&)"<<endl;
    RETURN_ARRAYS_INCREMENT();
    dvar_vector xp = xv+1.0e-10;
    dvar_vector d = r*log(mu)-::gammln(r)+(r-1.0)*log(xp)-mu*xp;
    RETURN_ARRAYS_DECREMENT();
    //cout<<"Finished log_gamma_density(dvar_vector&, prevariable&, prevariable&)"<<endl;
    return d;
}
/************************************************************************
* name      : log_gamma_density                                         *
* purpose   : compute log of gamma pdf                                  *
 *                                                                      *
* log_gamma_density(x,r,mu) = r*log(mu)-log_gamma(r)+(r-1)*log(x)-mu*x  *
* gamma(x,r,mu) = (mu^r)/gamma(r) * x^(r-1) * exp(-mu*x)                *
* This is SAME as Gelman et al., Bayesian Data Analysis                 *
*   parameters:                                                         *
*       x : value                                                       *
*       r : location parameter (r = mu*E[x])                            *
*       mu: rate (inverse scale) parameter                              *
************************************************************************/
dvar_vector wts::log_gamma_density(const dvector& xv,const dvar_vector& r,const dvar_vector& mu){
    //cout<<"Starting log_gamma_density(dvector&, dvar_vector&, dvar_vector&)"<<endl;
    RETURN_ARRAYS_INCREMENT();
    dvector xp = xv+1.0e-10;
    dvar_vector d = elem_prod(r,log(mu))-::gammln(r)+elem_prod((r-1.0),log(xp))-elem_prod(mu,xp);
    RETURN_ARRAYS_DECREMENT();
    //cout<<"Finished log_gamma_density(dvector&, dvar_vector&, dvar_vector&)"<<endl;
    return d;
}
/************************************************************************
* name      : log_gamma_density                                         *
* purpose   : compute log of gamma pdf                                  *
 *                                                                      *
* log_gamma_density(x,r,mu) = r*log(mu)-log_gamma(r)+(r-1)*log(x)-mu*x  *
* gamma(x,r,mu) = (mu^r)/gamma(r) * x^(r-1) * exp(-mu*x)                *
* This is SAME as Gelman et al., Bayesian Data Analysis                 *
*   parameters:                                                         *
*       x : value                                                       *
*       r : location parameter (r = mu*E[x])                            *
*       mu: rate (inverse scale) parameter                              *
************************************************************************/
dvar_vector wts::log_gamma_density(const dvar_vector& xv,const dvar_vector& r,const dvar_vector& mu){
    //cout<<"Starting log_gamma_density(dvar_vector&, dvar_vector&, dvar_vector&)"<<endl;
    RETURN_ARRAYS_INCREMENT();
    dvar_vector xp = xv+1.0e-10;
    dvar_vector d = elem_prod(r,log(mu))-::gammln(r)+elem_prod((r-1.0),log(xp))-elem_prod(mu,xp);
    RETURN_ARRAYS_DECREMENT();
    //cout<<"Finished log_gamma_density(dvar_vector&, dvar_vector&, dvar_vector&)"<<endl;
    return d;
}
/****************************************************************
* name      : drawSampleLognormal                               *
* purpose   : draw sample from Lognormal distribution           *
*   parameters:                                                 *
*       md : location parameter (arithmetic median)             *
*       cv:  coefficient of variation     (sd/mean)             *
****************************************************************/
double wts::drawSampleLognormal(random_number_generator& rng, const double md, const double cv) {
    return md*mfexp(randn(rng)*sqrt(log(1+cv*cv)));
}
/****************************************************************
* name      : drawSampleNegBinomial                             *
* purpose   : draw sample from negative binomial distribution   *
*   parameters:                                                 *
*       mu : location parameter (??)                            *
*       tau:  ??                                                *
****************************************************************/
double wts::drawSampleNegBinomial(random_number_generator& rng, const double mu, const double tau) {
    return randnegbinomial(mu,tau,rng);
}
/****************************************************************
* name      : drawSampleNormal                                  *
* purpose   : draw sample from Normal distribution              *
*   parameters:                                                 *
*       mu : location parameter (mean)                          *
*       sd:  standard deviation                                 *
****************************************************************/
double wts::drawSampleNormal(random_number_generator& rng, const double mu, const double sd) {
    return mu+randn(rng)*sd;
}
/****************************************************************
* name      : drawSamplePoisson                                 *
* purpose   : draw sample from Normal distribution              *
*   parameters:                                                 *
*       lam: rate parameter                                     *
****************************************************************/
double wts::drawSamplePoisson(random_number_generator& rng, const double mu, const double sd) {
    return mu+randn(rng)*sd;
}
/****************************************************************
* name      : drawSampleUniform                                 *
* purpose   : draw sample from Uniform distribution             *
*   parameters:                                                 *
*       lb : lower bound                                        *
*       ub:  upper bound                                        *
****************************************************************/
double wts::drawSampleUniform(random_number_generator& rng, const double lb, const double ub) {
    return lb+randn(rng)*(ub-lb);
}

/**
 * Function to generate a stochastic version of a multinomial probability distribution.
 * Modified from ADMB version to take a reference to a random_number_generator.
 * 
 * @param p   - original multinomial distribution
 * @param ss  - sample size
 * @param rng - reference to a random_number_generator
 * @return - stochastic estimate of distribution
 */
dvector wts::rmvlogistic(const dvector& p, const double& ss, const random_number_generator& rng) {
    int a=p.indexmin();
    int A=p.indexmax();
    dvector y(a,A); y.initialize();
    double tau2 = 1.0/sqrt(ss);
    ivector i = wts::whichIsNE(p, 0.0);
    if (i.allocated()){
        dvector epsilon(i.indexmin(),i.indexmax());
        dvector x(i.indexmin(),i.indexmax());
        epsilon.fill_randn(rng);
        for (int ii=i.indexmin();ii<=i.indexmax();ii++) x(ii)= log(p(i(ii)))+tau2*epsilon(ii);
        x -= mean(x);
        x = exp(x)/sum(exp(x));
        for (int ii=1;ii<=i.indexmax();ii++) {
            y(i(ii)) = x(ii);
        }
    }
    return y;
}

/********************************************
* name      : logPDF_?????                  *
* purpose   : compute ln(pdf(x)) for x      *
*   params: vector of parameters            *
*   consts: vector of constants             *
********************************************/
/*----------------------------------------------------*
*   name      : logPDF_constant                       *
*   returns 0 as log of value for                     *
*   improper constant pdf(x) = 1.                     *
*----------------------------------------------------*/
dvariable wts::logPDF_constant(const prevariable& x,const dvar_vector& params,const dvector& consts){
    RETURN_ARRAYS_INCREMENT();
    dvariable val=0.0;
    RETURN_ARRAYS_DECREMENT();
    return val;
}
// /*---------------------------------------------------*
// *   params = alpha, beta                             *
// *   consts = min, max                                *
// *---------------------------------------------------*/
// dvariable wts::logPDF_beta(prevariable& x,dvar_vector params, dvector& consts){
//     RETURN_ARRAYS_INCREMENT();
//     dvariable alf  = params(1);
//     dvariable bta  = params(2);
//     double A = 0.0;
//     double B = 1.0;
//     if (consts.allocated()) {
//         A = consts(1);
//         B = consts(2);
//     }
//     dvariable y = (y-A)/(B-A);//scale to interval [0,1].
//     dvariable logPDF = log(beta(alf,bta))+(alf-1)*log(x)+(bta-1)*log(1-x);
//     RETURN_ARRAYS_DECREMENT();
//     return logPDF;
// }
/*---------------------------------------------------*
*   pdf(x) = 1/{pi*gamma*[1+((x-x0)/gamma)^2]}       *
*   params = x0, gamma (location, scale)             *
*   consts = none                                    *
*---------------------------------------------------*/
dvariable wts::logPDF_cauchy(const prevariable& x,const dvar_vector& params, const dvector& consts){
    RETURN_ARRAYS_INCREMENT();
    dvariable x0     = params(1);//location param
    dvariable gamma  = params(2);//scale param (>0)
    dvariable logPDF = -(log(PI*gamma)+log(1+square((x-x0)/gamma)));
    RETURN_ARRAYS_DECREMENT();
    return logPDF;
}
/*-------------------------------------------*
* x~Chisquare(nu) w/ nu dof.                 *
*   params = nu (dof)                        *
*   consts = <empty>                         *
*-------------------------------------------*/
dvariable wts::logPDF_chisquare(const prevariable& x,const dvar_vector& params,const  dvector& consts){
    RETURN_ARRAYS_INCREMENT();
    /*---------------------------------------------------*
    * if X~Chisquare(nu) then X~Gamma(r=nu/2,mu=1/2)     *
    *       where mu is the rate (1/scale) parameter.    *
    *---------------------------------------------------*/
    dvariable r  = params(1)/2.0; //k in wikipedia article on gamma pdf
    dvariable mu = 0.5;           //1/theta in wikipedia article on gamma pdf
    dvariable logPDF = log_gamma_density(x,r,mu);//chi-square
    RETURN_ARRAYS_DECREMENT();
    return logPDF;
}
/*-------------------------------------------*
* x~Chisquare(nu) w/ nu dof.                 *
*   params = nu (dof)                        *
*   consts = <empty>                         *
*-------------------------------------------*/
dvar_vector wts::logPDF_chisquare(const dvar_vector& x,const dvar_vector& params,const  dvector& consts){
    RETURN_ARRAYS_INCREMENT();
//    cout<<"Starting logPDF_chisquare(dvar_vector&, dvar_vector, dvector&)"<<endl;
    /*---------------------------------------------------*
    * if X~Chisquare(nu) then X~Gamma(r=nu/2,mu=1/2)     *
    *       where mu is the rate (1/scale) parameter.    *
    *---------------------------------------------------*/
    dvariable r  = params(1)/2.0; //k in wikipedia article on gamma pdf
    dvariable mu = 0.5;           //1/theta in wikipedia article on gamma pdf
    dvar_vector logPDF(x.indexmin(),x.indexmax());
//    cout<<r<<tb<<mu<<x<<endl;
    logPDF = log_gamma_density(x,r,mu);//chi-square
//    cout<<logPDF<<tb<<logPDF.indexmin()<<tb<<logPDF.indexmax()<<endl;
//    cout<<"Finished logPDF_chisquare(dvar_vector&, dvar_vector, dvector&)"<<endl;
    RETURN_ARRAYS_DECREMENT();
    return logPDF;
}
/*---------------------------------------------------*
* X~Chisquare(nu) w/ nu dof.                         *
*   params = <empty>                                 *
*   consts = nu (dof)                                *
*---------------------------------------------------*/
dvariable wts::logPDF_chisqdevs(const prevariable& x,const dvar_vector& params,const  dvector& consts){
    RETURN_ARRAYS_INCREMENT();
    dvariable r  = consts(1)/2.0; //k in wikipedia article on gamma pdf
    dvariable mu = 0.5;           //1/theta in wikipedia article on gamma pdf
    dvariable logPDF = log_gamma_density(x,r,mu);//chi-square
    RETURN_ARRAYS_DECREMENT();
    return logPDF;
}
/*---------------------------------------------------*
* norm2(x/stdev)~Chisquare(nu)                       *
*   params = stdev                                   *
*   consts = <empty>                                 *
*---------------------------------------------------*/
dvariable wts::logPDF_chisqdevs(const dvar_vector& x,const dvar_vector& params,const  dvector& consts){
    RETURN_ARRAYS_INCREMENT();
    dvariable X2 = norm2(x)/square(params(1));
    dvariable r  = (length(x)-1)/2.0; //k in wikipedia article on gamma pdf
    dvariable mu = 0.5;               //1/theta in wikipedia article on gamma pdf
    dvariable logPDF = log_gamma_density(X2,r,mu);//chi-square
//    cout<<logPDF<<tb<<logPDF.indexmin()<<tb<<logPDF.indexmax()<<endl;
//    cout<<"Finished logPDF_chisquare(dvar_vector&, dvar_vector, dvector&)"<<endl;
    RETURN_ARRAYS_DECREMENT();
    return logPDF;
}
/*---------------------------------------------------*
*   pdf(x) = (1/lambda)*exp(-x/lambda)               *
*   params = lambda (scale)                          *
*   consts = none                                    *
*----------------------------------------------------*/
dvariable wts::logPDF_exponential(const prevariable& x,const dvar_vector& params,const dvector& consts){
    RETURN_ARRAYS_INCREMENT();
    dvariable lambda = params(1);//scale param
    dvariable logPDF = -log(lambda)-lambda*x;
    RETURN_ARRAYS_DECREMENT();
    return logPDF;
}
dvar_vector wts::logPDF_exponential(const dvar_vector& x,const dvar_vector& params,const dvector& consts){
    RETURN_ARRAYS_INCREMENT();
    dvariable lambda = params(1);//scale param
    dvar_vector logPDF = -log(lambda)-lambda*x;
    RETURN_ARRAYS_DECREMENT();
    return logPDF;
}
/*----------------------------------------------------------------------*
* name      : logPDF_gamma                                              *
* purpose   : compute log of gamma pdf                                  *
* log_gamma_density(x,r,mu) = r*log(mu)-log_gamma(r)+(r-1)*log(x)-mu*x  *
* gamma(x,r,mu) = (mu^r)/gamma(r) * x^(r-1) * exp(-mu*x)                *
* This is SAME as Gelman et al., Bayesian Data Analysis                 *
*       x : value                                                       *
*       r : shape factor                                                *
*       mu: rate (inverse scale) parameter                              *
* inputs:                                                               *
*   params = r,mu (shape, rate)                                         *
*   consts = <empty>                                                    *
*  OR                                                                   *
*   params = <empty>                                                    *
*   consts = r,mu (shape, rate)                                         *
*-----------------------------------------------------------------------*/
dvariable wts::logPDF_gamma(const prevariable& x,const dvar_vector& params,const dvector& consts){
    RETURN_ARRAYS_INCREMENT();
    dvariable logPDF;
    if (params.indexmax()==2) {
        dvariable r  = params(1); //shape parameter: k in wikipedia article on gamma pdf
        dvariable mu = params(2); //rate parameter : 1/theta in wikipedia article on gamma pdf
        logPDF = log_gamma_density(x,r,mu);
    } else {
        double r  = consts(1); //shape parameter: k in wikipedia article on gamma pdf
        double mu = consts(2); //rate parameter : 1/theta in wikipedia article on gamma pdf
        logPDF = log_gamma_density(x,r,mu);
    }
    RETURN_ARRAYS_DECREMENT();
    return logPDF;
}
dvar_vector wts::logPDF_gamma(const dvar_vector& x,const dvar_vector& params,const dvector& consts){
    RETURN_ARRAYS_INCREMENT();
    dvar_vector logPDF(x.indexmin(),x.indexmax());
    if (params.indexmax()==2) {
        dvariable r  = params(1); //shape parameter: k in wikipedia article on gamma pdf
        dvariable mu = params(2); //rate parameter : 1/theta in wikipedia article on gamma pdf
        logPDF = wts::log_gamma_density(x,r,mu);
    } else {
        double r  = consts(1); //shape parameter: k in wikipedia article on gamma pdf
        double mu = consts(2); //rate parameter : 1/theta in wikipedia article on gamma pdf
        logPDF = log_gamma_density(x,r,mu);
    }
    RETURN_ARRAYS_DECREMENT();
    return logPDF;
}
/*-----------------------------------------------*
* if X~InvChisquare(nu) then Y=1/X~Chisquare(nu) *
*   params = nu (dof)                            *
*   consts = <empty>                             *
*------------------------------------------------*/
dvariable wts::logPDF_invchisquare(const prevariable& x,const dvar_vector& params,const dvector& consts){
    RETURN_ARRAYS_INCREMENT();
    //if X~InvChisquare(r) then 1/X~Chisquare(r)
    dvariable y = 1/x; //y is chisquare-distributed
    dvariable logPDF = logPDF_chisquare(y,params,consts);
    RETURN_ARRAYS_DECREMENT();
    return logPDF;
}
/*---------------------------------------------*
* if X~InvGamma(r,mu) then Y=1/X~Gamma(r,1/mu) *
*   params = r,mu (shape, rate)                *
*   consts = <empty>                           *
*----------------------------------------------*/
dvariable wts::logPDF_invgamma(const prevariable& x,const dvar_vector& params,const dvector& consts){
    RETURN_ARRAYS_INCREMENT();
    //if X~InvGamma(r,mu) then 1/X~Gamma(r,1/mu)
    dvariable y     = 1/x;         //gamma-distributed
    dvariable r     = params(1);   //shape parameter: same as gamma
    dvariable invmu = 1/params(2); //gamma rate parameter: recip of mu
    dvariable logPDF = log_gamma_density(y,r,invmu);
    RETURN_ARRAYS_DECREMENT();
    return logPDF;
}
/*---------------------------------------------------*
*   pdf(x) = sqrt(lambda/(2*pi*x^3))*                *
*                    exp(-(lambda/(2*x))*(x/mu-1)^2) *
*   params = mu, lambda (location, shape)            *
*   consts = none                                    *
*----------------------------------------------------*/
dvariable wts::logPDF_invgaussian(const prevariable& x,const dvar_vector& params,const dvector& consts){
    RETURN_ARRAYS_INCREMENT();
    dvariable mu     = params(1);//location param
    dvariable lambda = params(2);//shape param
    dvariable logPDF = 0.5*(log(lambda)-log(2*PI)-3*log(x))-lambda/(2*x)*square(x/mu-1);
    RETURN_ARRAYS_DECREMENT();
    return logPDF;
}
/*----------------------------------------------------------*
*   pdf(x) =1/x*(2*pi*sigma^2)^-0.5 *                       *
*                     exp(-0.5*((ln(x)-ln(mu))/sigma)^2)    *
*   params = mu, cv (median, cv)                            *
*   consts = none                                           *
*-----------------------------------------------------------*/
dvariable wts::logPDF_lognormal(const prevariable& x,const dvar_vector& params,const dvector& consts){
    RETURN_ARRAYS_INCREMENT();
    dvariable mu     = params(1);                 //median
    dvariable var    = log(1.0+square(params(2)));//log-scale variance
    dvariable logPDF = -log(x)-0.5*(log(2.0*PI)+log(var)+
                                        square(log(x)-log(mu))/var);
//    cout<<"logPDF_lognormal: "<<x<<tb<<params<<tb<<sigma<<tb<<logPDF<<endl;
    RETURN_ARRAYS_DECREMENT();
    return logPDF;
}
/*----------------------------------------------------------*
*   pdf(x) = (2*pi*sigma^2)^-0.5 *                          *
*                     exp(-0.5*((ln(x)-ln(mu))/sigma)^2)    *
*   params = mu, cv (median, cv)                            *
*   consts = none                                           *
*-----------------------------------------------------------*/
dvariable wts::logPDF_logscale_normal(const prevariable& x,const dvar_vector& params,const dvector& consts){
    RETURN_ARRAYS_INCREMENT();
    dvariable mu     = params(1);                 //median
    dvariable var    = log(1.0+square(params(2)));//log-scale variance
    dvariable logPDF = -0.5*(log(2.0*PI)+log(var)+
                                        square(log(x)-log(mu))/var);
//    cout<<"logPDF_logscale_normal: "<<x<<tb<<params<<tb<<sigma<<tb<<logPDF<<endl;
    RETURN_ARRAYS_DECREMENT();
    return logPDF;
}
/*------------------------------------------------------------*
*   pdf(x) = (2*pi*sigma^2)^-0.5 * exp(-0.5*((x-mu)/sigma)^2) *
*   params = mu, sigma (mean, stdev)                          *
*   consts = none                                             *
*-------------------------------------------------------------*/
dvariable wts::logPDF_normal(const prevariable& x,const dvar_vector& params,const dvector& consts){
    RETURN_ARRAYS_INCREMENT();
    dvariable mu     = params(1);//location param
    dvariable sigma  = params(2);//scale param
    dvariable logPDF = -0.5*(log(2.0*PI)+2.0*log(sigma)+square((x-mu)/sigma));
    RETURN_ARRAYS_DECREMENT();
    return logPDF;
}

/**--------------------------------------------------------------------------*\n
 * Calculate log pdf based on a normal distribution for the 1st differences
 * of a vector of values.
 * 
 * pdf(diff(x)) = (2*pi*sigma^2)^-0.5 * exp(-0.5*(((diff(x)-mu)/sigma)^2) \n
 * diff(x) = x(mn+1,mx).shift(1)-x(mn,mx-1);
 * 
 * @param x      - dvar_vector to calculate logPDF with
 * @param params - dvar_vector with elements mu, sigma \n
 * @param consts - none (dvector, but any values are ignored)
 * 
 * @return dvar_vector with elements running x.indexmin() to x.indexmax()-1.
 */
dvar_vector wts::logPDF_AR1_normal(const dvar_vector& x,const dvar_vector& params,const dvector& consts){
    RETURN_ARRAYS_INCREMENT();
    dvariable mu     = params(1);//location param
    dvariable sigma  = params(2);//scale param
    int mn = x.indexmin();
    int mx = x.indexmax();
    dvar_vector tmp; tmp.allocate(x); tmp = x; //make copy because x may be const
    dvar_vector x1 = tmp(mn+1,mx).shift(1)-tmp(mn,mx-1);
    dvar_vector z1 = (x1-mu)/sigma;
    dvar_vector logPDF = -0.5*(log(2.0*PI)+2.0*log(sigma)+elem_prod(z1,z1));
    RETURN_ARRAYS_DECREMENT();
    return logPDF;
}
/**--------------------------------------------------------------------------*\n
 * Calculate log pdf based on a normal distribution for the exponentiated variable
 * 
 * pdf(x) = (2*pi*sigma^2)^-0.5 * exp(-0.5*(((exp(x)-mu)/sigma)^2) \n
  * 
 * @param x      - dvariable to calculate logPDF with
 * @param params - dvar_vector with elements mu, sigma \n
 * @param consts - none (dvector, but any values are ignored)
 * 
 * @return ln-scale pdf as dvariable
 */
dvariable wts::logPDF_expnormal(const prevariable& x, const dvar_vector& params,const dvector& consts){
    RETURN_ARRAYS_INCREMENT();
    dvariable logPDF = -0.5*(log(2.0*PI)+2.0*log(params(2))+square((mfexp(x)-params(1))/params(2)));
    if (isnan(value(logPDF))){
        std::cout<<"got a NAN in wts::logPDF_expnormal()"<<endl;
        std::cout<<"x = "<<x<<endl;
        std::cout<<"params = "<<params<<endl;
    }
    RETURN_ARRAYS_DECREMENT();
    return logPDF;
}
/*-----------------------------------------------------*
* if X~InvChisquare(nu,s^2) then                       *
*    Y=1/X~Gamma(nu/2,nu/2*s^2)                        *
* and                                                  *
*   pdf_InvGamma(X;nu,s^2) =                           *
*       (X^-2)*pdf_Gamma(1/X;alpha=nu/2,beta=nu/2*s^2) *
* inputs:                                              *
*   params = nu (dof), s                               *
*   consts = <empty>                                   *
* or                                                   *
*   params = <empty>                                   *
*   consts = nu (dof), s                               *
*-----------------------------------------------------*/
dvariable wts::logPDF_scaled_invchisquare(const prevariable& x,const dvar_vector& params,const dvector& consts){
    RETURN_ARRAYS_INCREMENT();
    dvariable logPDF;
    dvariable y = 1/x;
    if (params.indexmax()==2){
        dvariable a = params(1)/2;
        dvariable b = (params(1)/2)*square(params(2));
        logPDF = log_gamma_density(y,a,b)-2*log(x);
    } else {
        dvariable a = consts(1)/2;
        dvariable b = (consts(1)/2)*square(consts(2));
        logPDF = log_gamma_density(y,a,b)-2*log(x);
    }
    RETURN_ARRAYS_DECREMENT();
    return logPDF;
}
/*-----------------------------------------------------*
* x = log(1+cv^2)                                      *
* if X~InvChisquare(nu,s^2) then                       *
*    Y=1/X~Gamma(nu/2,nu/2*s^2)                        *
* and                                                  *
*   pdf_InvGamma(X;nu,s^2) =                           *
*       (X^-2)*pdf_Gamma(1/X;scale=nu/2,rate=nu/2*s^2) *
* inputs:                                              *
*   params = nu (dof), CV(s) = sqrt(exp(s^2)-1)        *
*   consts = <empty>                                   *
* or                                                   *
*   params = <empty>                                   *
*   consts = nu (dof), CV(s) = sqrt(exp(s^2)-1)        *
*-----------------------------------------------------*/
dvariable wts::logPDF_scaledCV_invchisquare(const prevariable& cv,const dvar_vector& params,const dvector& consts){
    RETURN_ARRAYS_INCREMENT();
    dvariable logPDF;
    dvariable x = log(1.0+square(cv));
    dvariable y = 1/x;
    if (params.indexmax()==2){
        dvariable a = params(1)/2;
        dvariable b = (params(1)/2)*log(1+square(params(2)));
        logPDF = log_gamma_density(y,a,b)+2*log(y);
    } else {
        dvariable a = consts(1)/2;
        dvariable b = (consts(1)/2)*log(1+square(consts(2)));
        logPDF = log_gamma_density(y,a,b)+2*log(y);
    }
    RETURN_ARRAYS_DECREMENT();
    return logPDF;
}
/*------------------------------------------------------*
*   pdf(x) = gamma((vu+1)/2)/(sqrt(nu*pi)*gamma(nu/2))* *
*               [1+x^2/nu]^(nu+1)/2                     *
*   params = nu (dof)                                   *
*   consts = none                                       *
*-------------------------------------------------------*/
dvariable wts::logPDF_t(const prevariable& x,const dvar_vector& params,const dvector& consts){
    RETURN_ARRAYS_INCREMENT();
    dvariable nu     = params(1);//location param
    dvariable logPDF = gammln((nu+1.0)/2.0)-gammln(nu/2.0)-0.5*log(nu*PI)+
                        (nu+1.0)/2.0*log(1+square(x)/2.0);
    RETURN_ARRAYS_DECREMENT();
    return logPDF;
}

dvariable wts::logSquareWave(const prevariable& x,double min,double max,double m){
    RETURN_ARRAYS_INCREMENT();
    dvariable logSW  = -m*(log(1+mfexp(-(x-min)))+log(1+mfexp(-(max-x))));
    RETURN_ARRAYS_DECREMENT();
    return logSW;
}


/*-------------------------------------------------------------*
*   pdf(x) = f*(2*pi*sigma^2)^-0.5 * exp(-0.5*((x-mu)/sigma)^2)*
*          on interval {min,max} [f is a coefficient so the    *
*          integral from min to max = 1.                       *
*   params = mu, sigma                                         *
*   consts = min, max                                          *
*NOTE: This gives the same value as logPDF_normal since f is a *
*      constant and immaterial to derivative calcs.            *
*-------------------------------------------------------------*/
dvariable wts::logPDF_truncated_normal(const prevariable& x,const dvar_vector& params,const dvector& consts){
    RETURN_ARRAYS_INCREMENT();
    dvariable mu     = params(1);//location param
    dvariable sigma  = params(2);//scale param
    double min = consts(1);
    double max = consts(2);
    dvariable logPDF = -0.5*(log(2.0*PI)+2.0*log(sigma)+square((x-mu)/sigma));//+logSquareWave(x,min,max);
    RETURN_ARRAYS_DECREMENT();
    return logPDF;
}
//-------------------------------------------------------------

/********************************************
* name      : samplePDF_?????               *
* purpose   : draw sample from pdf(x))      *
*   params: vector of parameters            *
*   consts: vector of constants             *
********************************************/
// /*-------------------------------------------------------------*
// * name      : samplePDF_beta                                   *
// * purpose   : draw sample from a beta distribution             *
// *   params:                                                    *
// *     1 alpha : shape parameter (>0)                           *
// *     2 beta  : shape parameter (>0)                           *
// *   consts:                                                    *
// *     1 A : minimum (default=0)                                *
// *     2 B : maximum (default=1)                                *
// *-------------------------------------------------------------*/
// double wts::samplePDF_beta(random_number_generator& rng,dvector& params,dvector& consts){
//     double p   = randu(rng);
//     double alf = params(1);
//     double bta = params(2);
//     double val = betai(alf,bta,p);//TODO: this is ASSUMED to be the inverse beta cdf
//     if (consts.allocated()) val = consts(1)+val*(consts(2)-consts(1));
//     return val;
// }
/*-------------------------------------------------------------*
* name      : samplePDF_cauchy                                 *
* purpose   : draw sample from a cauchy distribution           *
*   params:                                                    *
*     1 x0     : location parameter (real)                     *
*     2 gamma  : scale parameter (>0)                          *
*-------------------------------------------------------------*/
double wts::samplePDF_cauchy(random_number_generator& rng,const dvector& params,const dvector& consts){
    double p  = randu(rng);
    double x0 = params(1);
    double gm = params(2);
    double val = x0+gm*tan(PI*(p-0.5));
    return val;
}
/*-------------------------------------------------------------*
* name      : samplePDF_chisquare                              *
* purpose   : draw sample from a chisquare distribution        *
*   params:                                                    *
*     1 k     : degrees of freedom (integer)                   *
*-------------------------------------------------------------*/
double wts::samplePDF_chisquare(random_number_generator& rng,const dvector& params,const dvector& consts){
    int k = (int)params(1);
    dvector p(1,k);
    p.fill_randn(rng);
    double val = norm2(p);
    return val;
}
/*-------------------------------------------------------------*
* name      : samplePDF_exponential                            *
* purpose   : draw sample from an exponential distribution     *
*   params:                                                    *
*     1 lambda : rate parameter (real)                         *
*-------------------------------------------------------------*/
double wts::samplePDF_exponential(random_number_generator& rng,const dvector& params,const dvector& consts){
    double p  = randu(rng);
    double lm = params(1);
    double val = -log(p)/lm;
    return val;
}
/*-------------------------------------------------------------*
* name      : samplePDF_gamma                                  *
* purpose   : draw sample from a gamma distribution            *
*   params:                                                    *
*     1 r     : shape parameter (>0)                           *
*     2 mu    : rate (inverse scale) parameter (>0)            *
*-------------------------------------------------------------*/
double wts::samplePDF_gamma(random_number_generator& rng,const dvector& params,const dvector& consts){
    double p  = randu(rng);
    double r  = params(1);
    double mu = params(2);
    double val = inv_cumd_gamma(p,r)/mu;//TODO: check inv_cumd_gamma
    return val;
}
/*---------------------------------------------------------------*
* name      : samplePDF_invchisquare                             *
* purpose   : draw sample from an inverse chisquare distribution *
*   params:                                                      *
*     1 k     : degrees of freedom (integer)                     *
*---------------------------------------------------------------*/
double wts::samplePDF_invchisquare(random_number_generator& rng,const dvector& params,const dvector& consts){
    int k = (int)params(1);
    dvector p(1,k);
    p.fill_randn(rng);
    double val = 1.0/norm2(p);
    return val;
}
/*-------------------------------------------------------------*
* name      : samplePDF_invgamma                               *
* purpose   : draw sample from an inverse gamma distribution   *
*   params:                                                    *
*     1 r     : shape parameter (>0)                           *
*     2 mu    : rate parameter (>0)                            *
*-------------------------------------------------------------*/
double wts::samplePDF_invgamma(random_number_generator& rng,const dvector& params,const dvector& consts){
    dvector gparams(1,2);
    gparams(1) = params(1);    //r
    gparams(2) = 1.0/params(2);//1/mu
    double val = 1.0/samplePDF_gamma(rng,gparams,consts);//using Y~Gamma(r,1/mu) -> X=1/Y~InvGamma(r,mu)
    return val;
}
/*---------------------------------------------------------------*
* name      : samplePDF_invgaussian                              *
* purpose   : draw sample from an inverse gaussian distribution  *
*   params:                                                      *
*     1 mu     : location parameter (mean; >0)                   *
*     2 lambda : shape parameter (>0)                            *
*----------------------------------------------------------------*/
double wts::samplePDF_invgaussian(random_number_generator& rng,const dvector& params,const dvector& consts){
    double val = 0.0;
    double n = randn(rng);
    double z = randu(rng);
    double mu = params(1);
    double lm = params(2);
    double x = mu+(square(mu*n)-mu*sqrt((4*mu*lm*square(n))+square(mu*square(n))))/(2*lm);
    if (z<=mu/(mu+x)) val = x; else val = square(mu)/x;
    return val;
}
/*-------------------------------------------------------------*
* name      : samplePDF_lognormal                              *
* purpose   : draw sample from a lognormal distribution        *
*   params:                                                    *
*     1 med : location parameter (median)                      *
*     2 cv  : standard deviation                               *
*-------------------------------------------------------------*/
double wts::samplePDF_lognormal(random_number_generator& rng,const dvector& params,const dvector& consts){
    double med = params(1);
    double sdv = sqrt(log(1+square(params(2))));
    double val =  med*exp(randn(rng)*sdv);
    return val;
}
/*--------------------------------------------------------------*
* name      : samplePDF_1stdiff_normal                          *
* purpose   : draw sample of 1st differences from               *
 * a normal distribution                                        *
*   params:                                                     *
*     1 mu : location parameter (mean)                          *
*     2 sd:  standard deviation                                 *
*--------------------------------------------------------------*/
/**
 * Ideally, this would draw a sample of 1st differences 
 * from a normal distribution. At present, it returns a 
 * vector of 0's. @TODO: fix this!
 * @param n    - length of vector to return
 * @param rng  - random number generator
 * @param params - pdf parameter vector (mean, std dev)
 * @param consts - pdf constants vector (none)
 * 
 * @return dvector of sample values
 */
dvector wts::samplePDF_AR1_normal(int n, random_number_generator& rng,const dvector& params,const dvector& consts){
    double mu = params(1);
    double sd = params(2);
    dvector vals(1,n); vals.initialize();
    return vals;
}
/**
 * Draw a sample from a normal distribution, taking the log.
 * @param rng  - random number generator
 * @param params - pdf parameter vector (mean, std dev)
 * @param consts - pdf constants vector (none)
 * 
 * @return sample value
 */
double wts::samplePDF_expnormal(random_number_generator& rng,const dvector& params,const dvector& consts){
    double val = -1;
    while (val<=0) {val = wts::samplePDF_normal(rng,params,consts);}
    return log(val);
}
/*--------------------------------------------------------------*
* name      : samplePDF_normal                                  *
* purpose   : draw sample from a normal distribution            *
*   params:                                                     *
*     1 mu : location parameter (mean)                          *
*     2 sd:  standard deviation                                 *
*--------------------------------------------------------------*/
double wts::samplePDF_normal(random_number_generator& rng,const dvector& params,const dvector& consts){
    double mu = params(1);
    double sd = params(2);
    return mu+randn(rng)*sd;
}
/*-----------------------------------------------------*
* name      : samplePDF_scaled_invchisquare            *
* purpose   : draw sample from                         *
*               scaled inverse chi-square distribution *
* if X~InvChisquare(nu,sig^2) then                     *
*    Y=1/X~Gamma(nu/2,nu/2*s^2)                        *
* inputs:                                              *
*   params = nu (dof), s                               *
*   consts = <empty>                                   *
* or                                                   *
*   params = <empty>                                   *
*   consts = nu (dof), s                               *
*-----------------------------------------------------*/
double wts::samplePDF_scaled_invchisquare(random_number_generator& rng,const dvector& params,const dvector& consts){
    double p  = randu(rng);
    double r  = params(1)/2;                  //shape factor (=beta in Bayesian Data Analysis, p 575)
    double mu = params(1)/2*square(params(2));//rate (inverse scale) factor (=beta in Bayesian Data Analysis, p 575)
    double val = 1/(inv_cumd_gamma(p,r)/mu);
    return val;
}
/*-----------------------------------------------------*
* name      : samplePDF_scaledCV_invchisquare          *
* purpose   : draw sample from                         *
*               scaled inverse chi-square distribution *
*               as a cv                                *
*------------------------------------------------------*
* cv = sqrt(exp(x)-1)                                  *
* if X~InvChisquare(nu,s^2) then                       *
*    Y=1/X~Gamma(nu/2,nu/2*s^2)                        *
* and                                                  *
*   pdf_InvGamma(X;nu,s^2) =                           *
*       (X^-2)*pdf_Gamma(1/X;scale=nu/2,rate=nu/2*s^2) *
* inputs:                                              *
*   params = nu (dof), CV = sqrt(exp(s^2)-1)           *
*   consts = <empty>                                   *
* or                                                   *
*   params = <empty>                                   *
*   consts = nu (dof), CV = sqrt(exp(s^2)-1)           *
*-----------------------------------------------------*/
double wts::samplePDF_scaledCV_invchisquare(random_number_generator& rng,const dvector& params,const dvector& consts){
    double p  = randu(rng);
    double r  = params(1)/2;                         //shape factor (=beta in Bayesian Data Analysis, p 575)
    double mu = params(1)/2*log(1+square(params(2)));//rate (inverse scale) factor (=beta in Bayesian Data Analysis, p 575)
    double x = 1.0/(inv_cumd_gamma(p,r)/mu);
    double val = sqrt(exp(x)-1.0);                   //cv corresponding to x
    return val;
}
/*--------------------------------------------------------------*
* name      : samplePDF_t                                       *
* purpose   : draw sample from t distribution                   *
*   params:                                                     *
*     1 nu : degrees of freedom                                 *
*--------------------------------------------------------------*/
double wts::samplePDF_t(random_number_generator& rng,const dvector& params,const dvector& consts){
    double nu = params(1);
    double z = randn(rng);
    double v = samplePDF_chisquare(rng,params,consts);
    double val = z/sqrt(v/nu);
    return val;
}

/*--------------------------------------------------------------*
* name      : samplePDF_truncated_normal                        *
* purpose   : draw sample from a truncated normal distribution  *
*             on the open interval (min,max)                    *
*   params:                                                     *
*     1 mu : location parameter (mode of underlying normal)     *
*     2 sd:  scale parameter    (stdv of underlying normal)     *
*   consts:                                                     *
*     1 min : min value                                         *
*     2 max : max value                                         *
*---------------------------------------------------------------*/
double wts::samplePDF_truncated_normal(random_number_generator& rng,const dvector& params,const dvector& consts){
    double val = params(1)+randn(rng)*params(2);
    while ((val<=consts(1))||(val>=consts(2))) {
        val = params(1)+randn(rng)*params(2);
    }
    return val;
}
