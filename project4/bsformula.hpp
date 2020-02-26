
#ifndef bsformula_hpp
#define bsformula_hpp

struct bsresults {
    double value;
    double delta;
    double gamma;
    double theta;
};

bsresults bsformula(double S, double K, double T,
                    double r, double sigma, bool call);


#endif
