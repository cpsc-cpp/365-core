#ifndef COMMON_H
#define COMMON_H

#include <cstdint>

// Due to the way members are aligned, order of members can 
// affect struct size.
struct TupleA { char a; int value; char b; };
struct TupleB { int value; char a; char b; };

struct Record {
    const char* name; // this is a pointer to a C-style string 
    unsigned int id;  
    char province[2]; // In C++-11, size of array needs to be specified
};

struct MyInt {
    unsigned int val: 7;
    bool sign: 1; // sign bit
};

// pass via a pointer
void print_record(const Record* rd);

// pass via a reference
void print_record(const Record& rd);

void print_record_value(Record rd);
int32_t convert_my_int(const MyInt* i);


#endif