#include <admodel.h>
#include "wtsConsts.hpp"
#include "admbStdFunctions.hpp"
using namespace std;

/********************************************
* standardized double functions             *
********************************************/
double wts::none  (double x, _CONST dvector& consts){return  x;        }
double wts::acos  (double x, _CONST dvector& consts){return  ::acos(x);  }
double wts::asin  (double x, _CONST dvector& consts){return  ::asin(x);  }
double wts::atan  (double x, _CONST dvector& consts){return  ::atan(x);  }
double wts::cos   (double x, _CONST dvector& consts){return  ::cos(x);   }
double wts::exp   (double x, _CONST dvector& consts){return  ::mfexp(x); }
double wts::expneg(double x, _CONST dvector& consts){return -::mfexp(x); }
double wts::log   (double x, _CONST dvector& consts){return  ::log(x);   }
double wts::logneg(double x, _CONST dvector& consts){return  ::log(-x);  }
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
double wts::logistic(double x, _CONST dvector& consts){
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
double wts::logit   (double x, _CONST dvector& consts){
    return ::log((x-consts(1))/(consts(2)-x));
}
double wts::sin   (double x, _CONST dvector& consts){return ::sin(x);   }
double wts::sqrt  (double x, _CONST dvector& consts){return ::sqrt(x);  }
double wts::square(double x, _CONST dvector& consts){return ::square(x);}
double wts::tan   (double x, _CONST dvector& consts){return ::tan(x);   }

/********************************************
* standardized prevariable functions        *
********************************************/
dvariable wts::none  (_CONST prevariable& x, _CONST dvector& consts){RETURN_ARRAYS_INCREMENT();dvariable xp= x;        RETURN_ARRAYS_DECREMENT();return xp;}
dvariable wts::acos  (_CONST prevariable& x, _CONST dvector& consts){RETURN_ARRAYS_INCREMENT();dvariable xp= acos(x);  RETURN_ARRAYS_DECREMENT();return xp;}
dvariable wts::asin  (_CONST prevariable& x, _CONST dvector& consts){RETURN_ARRAYS_INCREMENT();dvariable xp= asin(x);  RETURN_ARRAYS_DECREMENT();return xp;}
dvariable wts::atan  (_CONST prevariable& x, _CONST dvector& consts){RETURN_ARRAYS_INCREMENT();dvariable xp= atan(x);  RETURN_ARRAYS_DECREMENT();return xp;}
dvariable wts::cos   (_CONST prevariable& x, _CONST dvector& consts){RETURN_ARRAYS_INCREMENT();dvariable xp= cos(x);   RETURN_ARRAYS_DECREMENT();return xp;}
dvariable wts::exp   (_CONST prevariable& x, _CONST dvector& consts){RETURN_ARRAYS_INCREMENT();dvariable xp= mfexp(x); RETURN_ARRAYS_DECREMENT();return xp;}
dvariable wts::expneg(_CONST prevariable& x, _CONST dvector& consts){RETURN_ARRAYS_INCREMENT();dvariable xp=-mfexp(x); RETURN_ARRAYS_DECREMENT();return xp;}
dvariable wts::log   (_CONST prevariable& x, _CONST dvector& consts){RETURN_ARRAYS_INCREMENT();dvariable xp= log(x);   RETURN_ARRAYS_DECREMENT();return xp;}
dvariable wts::logneg(_CONST prevariable& x, _CONST dvector& consts){RETURN_ARRAYS_INCREMENT();dvariable xp= log(-x);  RETURN_ARRAYS_DECREMENT();return xp;}
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
dvariable wts::logistic(_CONST prevariable& x, _CONST dvector& consts){
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
dvariable wts::logit(_CONST prevariable& x, _CONST dvector& consts){
    RETURN_ARRAYS_INCREMENT();
    dvariable xp=log((x-consts(1))/(consts(2)-x));
    RETURN_ARRAYS_DECREMENT();
    return xp;
}
dvariable wts::sin   (_CONST prevariable& x, _CONST dvector& consts){RETURN_ARRAYS_INCREMENT();dvariable xp=sin(x);   RETURN_ARRAYS_DECREMENT();return xp;}
dvariable wts::sqrt  (_CONST prevariable& x, _CONST dvector& consts){RETURN_ARRAYS_INCREMENT();dvariable xp=sqrt(x);  RETURN_ARRAYS_DECREMENT();return xp;}
dvariable wts::square(_CONST prevariable& x, _CONST dvector& consts){RETURN_ARRAYS_INCREMENT();dvariable xp=square(x);RETURN_ARRAYS_DECREMENT();return xp;}
dvariable wts::tan   (_CONST prevariable& x, _CONST dvector& consts){RETURN_ARRAYS_INCREMENT();dvariable xp=tan(x);   RETURN_ARRAYS_DECREMENT();return xp;}
