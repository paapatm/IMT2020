
#include "bsformula.hpp"
#include <ql/math/distributions/normaldistribution.hpp>
#include <cmath>

using std::sqrt;
using std::exp;
using std::log;

namespace {
    QuantLib::CumulativeNormalDistribution N;
    QuantLib::NormalDistribution n;
}

bsresults bsformula(double S, double K, double T,
                    double r, double sigma, bool call) {
    double d1 = (1/(sigma*sqrt(T))) * (log(S/K) + (r+sigma*sigma/2)*T);
    double d2 = d1 - sigma*sqrt(T);

    bsresults results;
    if (call) {
        results.value = N(d1)*S - N(d2)*K*exp(-r*T);
        results.delta = N(d1);
        results.theta = -(S*n(d1)*sigma)/(2*sqrt(T)) - r*K*exp(-r*T)*N(d2);
    } else {
        results.value = N(-d2)*K*exp(-r*T) -N(-d1)*S;
        results.delta = -N(-d1);
        results.theta = -(S*n(d1)*sigma)/(2*sqrt(T)) + r*K*exp(-r*T)*N(-d2);
    }
    results.gamma = n(d1)/(S*sigma*sqrt(T));
        
    return results;
}

