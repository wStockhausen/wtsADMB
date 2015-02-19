    /** 
     * File:   admbProbFunctions.hpp
     * Author: William Stockhausen
     *
     * Created on November 26, 2013, 2:53 PM
     */

#ifndef ADMBPROBFUNCTIONS_HPP
#define	ADMBPROBFUNCTIONS_HPP
namespace wts{
    /****************************************************************
    * name      : log_normal_density                                *
    * purpose   : compute log of normal distribution                *
    *   parameters:                                                 *
    *       z: normalized random deviate (z=(x-mu)/sdv              *
    ****************************************************************/
    double      log_normal_density(const double& z);
    dvariable   log_normal_density(const prevariable& z);
    dvector     log_normal_density(const dvector& z);
    dvar_vector log_normal_density(const dvar_vector& z);
    /****************************************************************
    * name      : log_normal_density                                *
    * purpose   : compute log of normal distribution                *
    *   parameters:                                                 *
    *       x  : arithmetic-scale value                             *
    *       mu : mean                                               *
    *       sdv: standard deviation                                 *
    ****************************************************************/
    double      log_normal_density(const double& x,     const double& mu,const double& sdv);
    dvariable   log_normal_density(const prevariable& x,const double& mu,const double& sdv);
    dvariable   log_normal_density(const double& x,     const prevariable& mu,const prevariable& sdv);
    dvariable   log_normal_density(const prevariable& x,const prevariable& mu,const prevariable& sdv);
    dvector     log_normal_density(const dvector& x,    const double& mu,const double& sdv);
    dvar_vector log_normal_density(const dvar_vector& x,const double& mu,const double& sdv);

    /****************************************************************
    * name      : log_lognormal_density                             *
    * purpose   : compute log of lognormal distribution             *
    *   parameters:                                                 *
    *       x  : arithmetic-scale value                             *
    *       med: arithmetic-scale median                            *
    *       sdv: log-scale standard deviation                       *
    ****************************************************************/
    double      log_lognormal_density(const double& x,     const double& med,const double& sdv);
    dvariable   log_lognormal_density(const prevariable& x,const double& med,const double& sdv);
    dvariable   log_lognormal_density(const double& x,     const prevariable& med,const prevariable& sdv);
    dvariable   log_lognormal_density(const prevariable& x,const prevariable& med,const prevariable& sdv);
    dvector     log_lognormal_density(const dvector& x,    const double& med,const double& sdv);
    dvar_vector log_lognormal_density(const dvar_vector& x,const double& med,const double& sdv);

/************************************************************************
* name      : log_gamma_density                                         *
* purpose   : compute log of gamma pdf                                  *
* log_gamma_density(x,r,mu) = r*log(mu)-log_gamma(r)+(r-1)*log(x)-mu*x  *
* gamma(x,r,mu) = (mu^r)/gamma(r) * x^(r-1) * exp(-mu*x)                *
* This is SAME as Gelman et al., Bayesian Data Analysis                 *
*   parameters:                                                         *
*       x : value                                                       *
*       r : shape factor                                                *
*       mu: rate (inverse scale) parameter                              *
************************************************************************/
    dvector     log_gamma_density(const dvector& x,    const double& r,   const double& mu);
    dvar_vector log_gamma_density(const dvar_vector& x,const double& r,   const double& mu);
    dvar_vector log_gamma_density(const dvar_vector& x,const dvariable& r,const dvariable& mu);

    /****************************************************************
    * name      : cdf_normal                                        *
    * purpose   : compute cdf of normal distribution                *
    *   parameters:                                                 *
    *       mu : location parameter (mean)                          *
    *       sd:  standard deviation                                 *
    *       lb : lower bound                                        *
    *       ub : upper bound                                        *
    ****************************************************************/
    //-------------------------------------------------------------
    double cdf_normal(   const double& mu,   const double& sd,   const double& lb,const double& ub);
    dvariable cdf_normal(const dvariable& mu,const double& sd,   const double& lb,const double& ub);
    dvariable cdf_normal(const dvariable& mu,const dvariable& sd,const double& lb,const double& ub);

    /****************************************************************
    * name      : drawSampleLognormal                               *
    * purpose   : draw sample from Lognormal distribution           *
    *   parameters:                                                 *
    *       md : location parameter (arithmetic median)             *
    *       cv:  coefficient of variation     (sd/mean)             *
    ****************************************************************/
    double drawSampleLognormal(random_number_generator& rng, const double md, const double cv);
    /****************************************************************
    * name      : drawSampleNegBinomial                             *
    * purpose   : draw sample from negative binomial distribution   *
    *   parameters:                                                 *
    *       mu : location parameter (??)                            *
    *       tau:  ??                                                *
    ****************************************************************/
    double drawSampleNegBinomial(random_number_generator& rng, const double mu, const double tau);
    /****************************************************************
    * name      : drawSampleNormal                                  *
    * purpose   : draw sample from Normal distribution              *
    *   parameters:                                                 *
    *       mu : location parameter (mean)                          *
    *       sd:  standard deviation                                 *
    ****************************************************************/
    double drawSampleNormal(random_number_generator& rng, const double mu, const double sd);
    /****************************************************************
    * name      : drawSamplePoisson                                 *
    * purpose   : draw sample from Normal distribution              *
    *   parameters:                                                 *
    *       lam: rate parameter                                     *
    ****************************************************************/
    double drawSamplePoisson(random_number_generator& rng, const double mu, const double sd);
    /****************************************************************
    * name      : drawSampleUniform                                 *
    * purpose   : draw sample from Uniform distribution             *
    *   parameters:                                                 *
    *       lb : lower bound                                        *
    *       ub:  upper bound                                        *
    ****************************************************************/
    double drawSampleUniform(random_number_generator& rng, const double lb, const double ub);

    /**
     * Function to generate a stochastic version of a multinomial probability distribution.
     * Modified from ADMB version to take a reference to a random_number_generator.
     * 
     * @param p   - original multinomial distribution
     * @param ss  - sample size
     * @param rng - reference to a random_number_generator
     * @return - stochastic estimate of distribution
     */
    dvector rmvlogistic(const dvector& p, const double& ss, const random_number_generator& rng);
    
    dvariable logSquareWave(const prevariable& x,double min,double max,double m=100.0);


/********************************************
* name      : logPDF_?????                  *
* purpose   : compute ln(pdf(x)) for x      *
*   params: vector of parameters            *
*   consts: vector of constants             *
********************************************/
dvariable logPDF_constant    (const prevariable& x,const dvar_vector& params,const dvector& consts);
//dvariable logPDF_beta        (prevariable& x,dvar_vector params,dvector& consts);
dvariable logPDF_cauchy      (const prevariable& x,const dvar_vector& params,const dvector& consts);
/*-------------------------------------------*
* x~Chisquare(nu) w/ nu dof.                 *
*   params = nu (dof)                        *
*   consts = <empty>                         *
*-------------------------------------------*/
dvariable logPDF_chisquare(const prevariable& x,const dvar_vector& params,const dvector& consts);
dvar_vector logPDF_chisquare(const dvar_vector& x,const dvar_vector& params,const dvector& consts);
/*---------------------------------------------------*
* X~Chisquare(nu) w/ nu dof.                         *
*   params = <empty>                                 *
*   consts = nu (dof)                                *
*---------------------------------------------------*/
dvariable logPDF_chisqdevs(const prevariable& x,const dvar_vector& params, const dvector& consts);
/*---------------------------------------------------*
* norm2(x/stdev)~Chisquare(nu)                       *
*   params = stdev                                   *
*   consts = <empty>                                 *
*---------------------------------------------------*/
dvariable logPDF_chisqdevs(const dvar_vector& x,const dvar_vector& params, const dvector& consts);
/*---------------------------------------------------*
*   pdf(x) = (1/lambda)*exp(-x/lambda)               *
*   params = lambda (scale)                          *
*   consts = none                                    *
*----------------------------------------------------*/
dvariable   logPDF_exponential(const prevariable& x,const dvar_vector& params,const dvector& consts);
dvar_vector logPDF_exponential(const dvar_vector& x,const dvar_vector& params,const dvector& consts);
/*----------------------------------------------------------------------*
* name      : log_gamma_density                                         *
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
dvariable   logPDF_gamma(const prevariable& x,const dvar_vector& params,const dvector& consts);
dvar_vector logPDF_gamma(const dvar_vector& x,const dvar_vector& params,const dvector& consts);

dvariable logPDF_invchisquare       (const prevariable& x,const dvar_vector& params,const dvector& consts);
dvariable logPDF_invgamma           (const prevariable& x,const dvar_vector& params,const dvector& consts);
dvariable logPDF_invgaussian        (const prevariable& x,const dvar_vector& params,const dvector& consts);
dvariable logPDF_lognormal          (const prevariable& x,const dvar_vector& params,const dvector& consts);
dvariable logPDF_logscale_normal    (const prevariable& x,const dvar_vector& params,const dvector& consts);
dvariable logPDF_normal             (const prevariable& x,const dvar_vector& params,const dvector& consts);
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
dvariable logPDF_scaled_invchisquare(const prevariable& x,const dvar_vector& params,const dvector& consts);
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
dvariable logPDF_scaledCV_invchisquare(const prevariable& cv,const dvar_vector& params, const dvector& consts);
/*------------------------------------------------------*
*   pdf(x) = gamma((vu+1)/2)/(sqrt(nu*pi)*gamma(nu/2))* *
*               [1+x^2/nu]^(nu+1)/2                     *
*   params = nu (dof)                                   *
*   consts = none                                       *
*-------------------------------------------------------*/
dvariable logPDF_t(const prevariable& x,const dvar_vector& params,const dvector& consts);
/*-------------------------------------------------------------*
*   pdf(x) = f*(2*pi*sigma^2)^-0.5 * exp(-0.5*((x-mu)/sigma)^2)*
*          on interval {min,max} [f is a coefficient so the    *
*          integral from min to max = 1.                       *
*   params = mu, sigma                                         *
*   consts = min, max                                          *
*NOTE: This gives the same value as logPDF_normal since f is a *
*      constant and immaterial to derivative calcs.            *
*-------------------------------------------------------------*/
dvariable logPDF_truncated_normal(const prevariable& x,const dvar_vector& params,const dvector& consts);
/*--------------------------------------------------------------------------*\n
*   pdf(diff(x)) = f*(2*pi*sigma^2)^-0.5 * exp(-0.5*(((diff(x)-mu)/sigma)^2) \n
*   params = mu, sigma \n
*   consts = min, max  \n
*NOTE: This gives the same value as logPDF_normal since f is a \n
*      constant and immaterial to derivative calcs.            \n
*----------------------------------------------------------------------------*/
dvar_vector logPDF_1stdiff_normal(const dvar_vector& x,const dvar_vector& params,const dvector& consts);


    /********************************************
    * name      : samplePDF_?????               *
    * purpose   : draw sample from pdf(x))      *
    *   params: vector of parameters            *
    *   consts: vector of constants             *
    ********************************************/
//    double samplePDF_beta        (random_number_generator& rng,dvector& params,dvector& consts);
    double samplePDF_cauchy             (random_number_generator& rng,const dvector& params,const dvector& consts);
    double samplePDF_chisquare          (random_number_generator& rng,const dvector& params,const dvector& consts);
    double samplePDF_exponential        (random_number_generator& rng,const dvector& params,const dvector& consts);
    double samplePDF_gamma              (random_number_generator& rng,const dvector& params,const dvector& consts);
    double samplePDF_invchisquare       (random_number_generator& rng,const dvector& params,const dvector& consts);
    double samplePDF_invgamma           (random_number_generator& rng,const dvector& params,const dvector& consts);
    double samplePDF_invgaussian        (random_number_generator& rng,const dvector& params,const dvector& consts);
    double samplePDF_lognormal          (random_number_generator& rng,const dvector& params,const dvector& consts);
    double samplePDF_normal             (random_number_generator& rng,const dvector& params,const dvector& consts);
    double samplePDF_scaled_invchisquare(random_number_generator& rng,const dvector& params,const dvector& consts);
    double samplePDF_scaledCV_invchisquare(random_number_generator& rng,const dvector& params,const dvector& consts);
    double samplePDF_t                  (random_number_generator& rng,const dvector& params,const dvector& consts);
    double samplePDF_truncated_normal   (random_number_generator& rng,const dvector& params,const dvector& consts);
    
    dvector samplePDF_1stdiff_normal     (int n,random_number_generator& rng,const dvector& params,const dvector& consts);

}
#endif	/* ADMBPROBFUNCTIONS_HPP */

