//admbStringFunctions.cpp
#include <admodel.h>
#include "wtsConsts.hpp"
#include "admbFileFunctions.hpp"
using namespace std;

/**
 * Return the path separator
 * @return 
 */
adstring wts::pathSeparator() {
    #ifdef _WIN32
        return "\\";
    #else
        return "/";
    #endif
}    

/**
 * 
 * @param path
 * @return 
 */
adstring wts::getParentFolder(const adstring& path){
    cout<<"in getparentFolder()"<<endl;
    adstring tmp; tmp = path;
    adstring sep = wts::pathSeparator();
    //cout<<"path = '"<<tmp<<"'. sep = '"<<sep<<"'"<<endl;
    int n = tmp.size();
    int i = n;
    while((i>0)&&(tmp(i,i)!=sep)){
        //cout<<i<<" "<<tmp[i]<<endl;
        i--;
    }
    adstring parent = "";
    if (i>1) parent = tmp(1,i-1);
    //cout<<"parent = '"<<parent<<"'"<<endl;
    return parent;
}

/**
 * 
 * @param path
 * @return 
 */
adstring wts::getParentFolder(cifstream& is){
    return wts::getParentFolder(is.get_file_name());
}

/**
 * 
 * @param path1
 * @param path2
 * @return 
 */
adstring wts::concatenateFilePaths(const adstring& path1, const adstring& path2){
    adstring tmp1; tmp1 = path1;
    adstring tmp2; tmp2 = path2;
    if (tmp1=="") tmp1=".";
    return tmp1+pathSeparator()+tmp2;
}
