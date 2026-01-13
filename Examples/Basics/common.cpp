#include <iostream>
#include "common.h"

using namespace std;

void print_record(const Record* rd) {
    cout << "Got a pointer to: ";
 
    // For a pointer to a struct, members can be 
    // accessed via the '->' operator.
    // We can also use pointer dereferencing '*'.
    // 
    // The following is for instructional purposes, 
    // best to avoid mixed usage of '->' and '*'. 
    cout << "{" << rd->name 
        << ", " << rd->id << ", " 
        << (*rd).province[0] << (*rd).province[1] << "}" << endl;
}

// pass via reference
void print_record(const Record& rd) {
    cout << "Got a reference to: ";
    cout << "{" << rd.name 
        << ", " << rd.id << ", " 
        << rd.province[0] << rd.province[1] << "}" << endl;
}

void print_record_value(Record rd) {
    cout << "Got a copy of: ";
    cout << "{" << rd.name << ", " << rd.id << ", " 
        << rd.province[0] << rd.province[1] << "}" << endl;
}

int32_t convert_my_int(const MyInt* i) {
    return i->val + (i->sign ? -128 : 0);
}
