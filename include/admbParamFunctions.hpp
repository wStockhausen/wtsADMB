/* 
 * File:   admbParamFunctions.hpp
 * Author: WilliamStockhausen
 *
 * Created on June 2, 2014, 8:28 AM
 */

#ifndef ADMBPARAMFUNCTIONS_HPP
#define	ADMBPARAMFUNCTIONS_HPP

namespace wts{
    /**
     * Write parameter information to an output stream.
     * 
     * @param os - output stream to write to
     * @param p - the parameter
     * @param toR - flag (0/1) to write info in R format
     * @param willBeActive - flag (0/1) to write info ONLY IF parameter is or will be active in some phase
     */
    void writeParameter(std::ostream& os, param_init_number& p, int toR, int willBeActive);
    
    /**
     * Write parameter information to an output stream.
     * 
     * @param os - output stream to write to
     * @param p - the parameter
     * @param toR - flag (0/1) to write info in R format
     * @param willBeActive - flag (0/1) to write info ONLY IF parameter is or will be active in some phase
     */
    void writeParameter(std::ostream& os, param_init_bounded_number& p, int toR, int willBeActive);
    
    /**
     * Write parameter vector information to an output stream.
     * 
     * @param os - output stream to write to
     * @param p - the parameter vector
     * @param toR - flag (0/1) to write info in R format
     * @param willBeActive - flag (0/1) to write info ONLY IF parameter is or will be active in some phase
     */
    void writeParameter(std::ostream& os, param_init_vector& p, int toR, int willBeActive);
    
    /**
     * Write parameter vector information to an output stream.
     * 
     * @param os - output stream to write to
     * @param p - the parameter vector
     * @param toR - flag (0/1) to write info in R format
     * @param willBeActive - flag (0/1) to write info ONLY IF parameter is or will be active in some phase
     */
    void writeParameter(std::ostream& os, param_init_bounded_vector& p, int toR, int willBeActive);
    
    /**
     * Write parameter vector information to an output stream.
     * 
     * @param os - output stream to write to
     * @param p - the parameter vector
     * @param toR - flag (0/1) to write info in R format
     * @param willBeActive - flag (0/1) to write info ONLY IF parameter is or will be active in some phase
     */
    void writeParameter(std::ostream& os, param_init_bounded_dev_vector& p, int toR, int willBeActive);
    
    /**
     * Jitter the initial parameter (p) value based on the jitter factor (fac).
     * 
     * @param p   - the parameter to jitter
     * @param fac - the jitter factor (0-1)
     * @param rng - random number generator object
     */
    void jitterParameter(param_init_number& p, double fac, random_number_generator& rng);
    
    /**
     * Jitter the initial parameter (p) value based on the jitter factor (fac).
     * 
     * @param p   - the parameter to jitter
     * @param fac - the jitter factor (0-1)
     * @param rng - random number generator object
     */
    void jitterParameter(param_init_bounded_number& p, double fac, random_number_generator& rng);
    
    /**
     * Jitter the initial parameter vector (p) values based on the jitter factor (fac).
     * 
     * @param p   - the parameter vector to jitter
     * @param fac - the jitter factor (0-1)
     * @param rng - random number generator object
     */
    void jitterParameter(param_init_bounded_vector& p, double fac, random_number_generator& rng);
    
    /**
     * Jitter the initial parameter vector (p) values based on the jitter factor (fac).
     * 
     * @param p   - the parameter to jitter
     * @param fac - the jitter factor (0-1)
     * @param rng - random number generator object
     */
    void jitterParameter(param_init_bounded_dev_vector& p, double fac, random_number_generator& rng);
}

#endif	/* ADMBPARAMFUNCTIONS_HPP */

