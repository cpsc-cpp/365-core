template <typename S> class complex { // S is the main type
    S re, im;
public:
    // default constructor
    complex() : re{}, im{} {}

    // template constructor, can define here or outside
    template <typename T> complex( T real, T imag=0 ) : re{real}, im{imag} {}
    
    // default copy constructor
    complex( const complex&) = default;
    
    // template copy constructor, can define here or outside
    template <typename T> complex( const complex<T>& );

    S real() const {return re;}
    S imag() const {return im;}

};

template <typename S>
template <typename T> 
complex<S>::complex( const complex<T>& c ) : re{c.real()}, im{c.imag()} {}

using namespace std;

int main() {
    complex<float> cf; // default construction
    //complex<float> fd{1.0}; // template constructor, narrowing double-to-float conversion

    complex<double> cd{cf}; // uses float-to-double conversion
    complex<float> ef {cd};
    return 0;
}
