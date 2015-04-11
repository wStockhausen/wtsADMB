/* 
 * File:   admbFileFunctions.hpp
 * Author: WilliamStockhausen
 *
 * Created on April 10, 2015, 2:44 PM
 */

#ifndef ADMBFILEFUNCTIONS_HPP
#define	ADMBFILEFUNCTIONS_HPP

#include <admodel.h>

using namespace std;

namespace wts{
    /**
     * Return the path separator
     * @return 
     */
    adstring pathSeparator();
    
    /**
     * 
     * @param path
     * @return 
     */
    adstring getParentFolder(const adstring& path);
    
    /**
     * 
     * @param is
     * @return 
     */
    adstring getParentFolder(cifstream& is);
    
    /**
     * 
     * @param path1
     * @param path2
     * @return 
     */
    adstring concatenateFilePaths(const adstring& path1, const adstring& path2);
}//namespace wts


#endif	/* ADMBFILEFUNCTIONS_HPP */

