#include "filter.h"

using namespace std;

int main( ) {
    VectorDataSet input{10, 1.0};
    VectorDataSet output{1, 0.0};

    Filter* adder = new ReductionFilter {
        [](double a, double b){return a+b;},
        0.0
    };

    // Example max filter
    //Filter* maxer = new ReductionFilter {
    //    [](double a, double b){return a > b ? a : b;},
    //    0.0
    //};

    adder->filter( input, output );

    cout << input << endl;
    cout << output << endl;
    delete adder;
} 