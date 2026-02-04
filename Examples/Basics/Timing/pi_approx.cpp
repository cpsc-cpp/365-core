/**
 * @file pi_approx.cpp
 * @brief Approximating Pi via the Leibniz formula.
 * 
 * Iterative vs recursive implementation of the Leibniz formula
 * for approximating Pi.
 * https://en.wikipedia.org/wiki/Leibniz_formula_for_%CF%80
 *
 * Demonstration of how to use std::chrono to measure 
 * execution time. 
 */


#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <cstdint>

using namespace std;

double itr_pi( uint64_t n ) {
    double result {};
    for(uint64_t k = 0; k <= n; k++) {
        result += (k%2 ? -4.0 : 4.0) / (2*k + 1);
    }
    return result;
}

double rec_pi( uint64_t n ) {
    if( n == 0 ) {
        return 4.0;
    } else {
        return (n%2 ? -4.0 : 4.0) / (2*n + 1) + rec_pi(n-1);
    }
}


int main( int argc, char** argv ) {
    if (argc != 2 ) {
        cout << "Usage: " << argv[0] << " " << "n" << endl;
        cout << "  where n is a non-negative integer" << endl;
        return 0;
    }

    try {
        // Convert argument to an integer
        int64_t  num = stoll(argv[1]);
        uint64_t n {};
        if( num < 0 ) {
            cerr << "Error: n must be non-negative" << endl;
            return 0;
        } else {
            n = static_cast<uint32_t>(num);
        }

        // Measure both (iterative and recursive) executions.
        // Each is run once. Duration captures in ns. 

        auto start = chrono::steady_clock::now();
        double itr_result = itr_pi(n);

        // Idle time to see how execution time is affected.
        //this_thread::sleep_for(chrono::milliseconds(10));

        auto end = chrono::steady_clock::now();
        auto itr_time = chrono::duration_cast<chrono::nanoseconds>(end - start);


        start = chrono::steady_clock::now();
        double rec_result = rec_pi(n);

        // Idle time to see how execution time is affected.
        //this_thread::sleep_for(chrono::milliseconds(10));

        end = chrono::steady_clock::now();
        auto rec_time = chrono::duration_cast<chrono::nanoseconds>(end - start);
        
        // Print out results
        cout << "Num terms: " << n << endl;
        cout << "Itr approx: " << setprecision(10) << itr_result << " (" << itr_time.count() << " ns)" << endl;
        cout << "Rec approx: " << setprecision(10) << rec_result << " (" << rec_time.count() << " ns)" << endl;
    } catch( const invalid_argument& e ) {
        cerr << "Error: Invalid input (not a valid number)" << endl;
    } catch( const out_of_range& e) {
        cerr << "Error: Out of range number provided" << endl;
    }

    return 0;
}