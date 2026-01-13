#include "data.h"

class Filter {
public:
    virtual void filter(const DataSet& input, DataSet& output ) const = 0;
    virtual ~Filter() = default;
};

class ReductionFilter : public Filter {
    double (*reduce)(double, double);
    double initial = 0;
    
public:
    ReductionFilter( decltype(reduce) op, double init ) 
        : reduce{op}, initial{init} {}
    
    void filter( const DataSet& input, DataSet& output ) const override {
        double result = initial;
        for( size_t i = 0; i < input.getSize(); i++ ) {
            result = reduce(result, input[i]);
        } 
        output[0] = result;
    }     
};