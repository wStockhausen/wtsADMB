#include <admodel.h>
#include "wtsConsts.hpp"
#include "admbStdFunctions.hpp"
using namespace std;

/********************************************
* standardized double functions             *
********************************************/
double wts::none  (double x, const dvector& consts){return  x;        }
double wts::acos  (double x, const dvector& consts){return  ::acos(x);  }
double wts::asin  (double x, const dvector& consts){return  ::asin(x);  }
double wts::atan  (double x, const dvector& consts){return  ::atan(x);  }
double wts::cos   (double x, const dvector& consts){return  ::cos(x);   }
double wts::exp   (double x, const dvector& consts){return  ::mfexp(x); }
double wts::expneg(double x, const dvector& consts){return -::mfexp(x); }
double wts::log   (double x, const dvector& consts){return  ::log(x);   }
double wts::logneg(double x, const dvector& consts){return  ::log(-x);  }
/***********************************************************
logistic
    transform:
        y = min+(max-min)/[1+exp(-x)]
    x range:
        (-Inf,+Inf)
    y range:
        (min, max)
    consts :
        {min, max}
    inverse transform:
        logit(y,{min,max})
***********************************************************/
double wts::logistic(double x, const dvector& consts){
    return consts(1)+(consts(2)-consts(1))/(1+::mfexp(-x));
}

/***********************************************************
logit
    transform:
        y = ln[(x-min)/(max-x)]
    x range:
        (min, max)
    y range:
        (-Inf,+Inf)
    consts :
        {min, max}
    inverse transform:
        logistic(y,{min,max})
***********************************************************/
double wts::logit   (double x, const dvector& consts){
    return ::log((x-consts(1))/(consts(2)-x));
}
double wts::sin   (double x, const dvector& consts){return ::sin(x);   }
double wts::sqrt  (double x, const dvector& consts){return ::sqrt(x);  }
double wts::square(double x, const dvector& consts){return ::square(x);}
double wts::tan   (double x, const dvector& consts){return ::tan(x);   }

/********************************************
* standardized prevariable functions        *
********************************************/
dvariable wts::none  (const prevariable& x, const dvector& consts){RETURN_ARRAYS_INCREMENT();dvariable xp= x;        RETURN_ARRAYS_DECREMENT();return xp;}
dvariable wts::acos  (const prevariable& x, const dvector& consts){RETURN_ARRAYS_INCREMENT();dvariable xp= acos(x);  RETURN_ARRAYS_DECREMENT();return xp;}
dvariable wts::asin  (const prevariable& x, const dvector& consts){RETURN_ARRAYS_INCREMENT();dvariable xp= asin(x);  RETURN_ARRAYS_DECREMENT();return xp;}
dvariable wts::atan  (const prevariable& x, const dvector& consts){RETURN_ARRAYS_INCREMENT();dvariable xp= atan(x);  RETURN_ARRAYS_DECREMENT();return xp;}
dvariable wts::cos   (const prevariable& x, const dvector& consts){RETURN_ARRAYS_INCREMENT();dvariable xp= cos(x);   RETURN_ARRAYS_DECREMENT();return xp;}
dvariable wts::exp   (const prevariable& x, const dvector& consts){RETURN_ARRAYS_INCREMENT();dvariable xp= mfexp(x); RETURN_ARRAYS_DECREMENT();return xp;}
dvariable wts::expneg(const prevariable& x, const dvector& consts){RETURN_ARRAYS_INCREMENT();dvariable xp=-mfexp(x); RETURN_ARRAYS_DECREMENT();return xp;}
dvariable wts::log   (const prevariable& x, const dvector& consts){RETURN_ARRAYS_INCREMENT();dvariable xp= log(x);   RETURN_ARRAYS_DECREMENT();return xp;}
dvariable wts::logneg(const prevariable& x, const dvector& consts){RETURN_ARRAYS_INCREMENT();dvariable xp= log(-x);  RETURN_ARRAYS_DECREMENT();return xp;}
/***********************************************************
logistic
    transform:
        y = min+(max-min)/[1+exp(-x)]
    x range:
        (-Inf,+Inf)
    y range:
        (min, max)
    consts :
        {min, max}
    inverse transform:
        logit(y,{min,max})
***********************************************************/
dvariable wts::logistic(const prevariable& x, const dvector& consts){
    RETURN_ARRAYS_INCREMENT();
    dvariable xp=consts(1)+(consts(2)-consts(1))/(1+mfexp(-x));
    RETURN_ARRAYS_DECREMENT();
    return xp;
}
/***********************************************************
logit
    transform:
        y = ln[(x-min)/(max-x)]
    x range:
        (min, max)
    y range:
        (-Inf,+Inf)
    consts :
        {min, max}
    inverse transform:
        logistic(y,{min,max})
***********************************************************/
dvariable wts::logit(const prevariable& x, const dvector& consts){
    RETURN_ARRAYS_INCREMENT();
    dvariable xp=log((x-consts(1))/(consts(2)-x));
    RETURN_ARRAYS_DECREMENT();
    return xp;
}
dvariable wts::sin   (const prevariable& x, const dvector& consts){RETURN_ARRAYS_INCREMENT();dvariable xp=sin(x);   RETURN_ARRAYS_DECREMENT();return xp;}
dvariable wts::sqrt  (const prevariable& x, const dvector& consts){RETURN_ARRAYS_INCREMENT();dvariable xp=sqrt(x);  RETURN_ARRAYS_DECREMENT();return xp;}
dvariable wts::square(const prevariable& x, const dvector& consts){RETURN_ARRAYS_INCREMENT();dvariable xp=square(x);RETURN_ARRAYS_DECREMENT();return xp;}
dvariable wts::tan   (const prevariable& x, const dvector& consts){RETURN_ARRAYS_INCREMENT();dvariable xp=tan(x);   RETURN_ARRAYS_DECREMENT();return xp;}
