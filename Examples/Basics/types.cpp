/**
 * @file types.cpp
 * @brief Basic types in C++
 * 
 * Sizes and ranges of basic types in C++.
 */


#include <iostream>
#include <climits>
#include <limits>
#include <cfloat>
#include <cstdint>

using namespace std;

int main() {
    cout << endl;
    cout << "Sizes (in bytes) and ranges of various types for this implementation" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << endl;

    cout << "bool:\t\t\t" << sizeof(bool) << endl;
    cout << endl;

    cout << "char:\t\t\t" << sizeof(char) << "\t" << "[" << CHAR_MIN << ", " << CHAR_MAX << "]" << endl;
    cout << "unsigned char:\t\t" << sizeof(unsigned char) << "\t" << "[ " << ", " << UCHAR_MAX << "]" << endl;
    cout << "signed char:\t\t" << sizeof(signed char) << "\t" << "[" << SCHAR_MIN << ", " << SCHAR_MAX << "]" << endl; 
    cout << endl; 

    cout << "Wider characters:" << endl;
    cout << "wchar_t:\t\t" << sizeof(wchar_t) << "\t" << "[" << static_cast<int>(numeric_limits<wchar_t>::min()) << ", " << static_cast<int>(numeric_limits<wchar_t>::max()) << "]" << endl;
    cout << "char16_t:\t\t" << sizeof(char16_t) << "\t" << "[" << numeric_limits<char16_t>::min() << ", " << numeric_limits<char16_t>::max() << "]" << endl;
    cout << "char32_t:\t\t" << sizeof(char32_t) << "\t" << "[" << numeric_limits<char32_t>::min() << ", " << numeric_limits<char32_t>::max() << "]" << endl;
    cout << endl;
  

    cout << "int:\t\t\t" << sizeof(int) << "\t" << "[" << INT_MIN << ", " << INT_MAX << "]" << endl;
    cout << "unsigned int:\t\t" << sizeof(unsigned int) << "\t" << "[ " << ", " << UINT_MAX << "]" << endl;
    cout << endl;

    cout << "short:\t\t\t" << sizeof(short) << "\t" << "[" << SHRT_MIN << ", " << SHRT_MAX << "]" << endl;
    cout << "unsigned short:\t\t" << sizeof(unsigned short) << "\t" << "[ " << ", " << USHRT_MAX << "]" << endl;
    cout << endl;

    cout << "long:\t\t\t" << sizeof(long) << "\t" << "[" << LONG_MIN << ", " << LONG_MAX << "]" << endl;
    cout << "unsigned long:\t\t" << sizeof(unsigned long) << "\t" << "[ " << ", " << ULONG_MAX << "]" << endl;
    cout << endl;

    cout << "long long:\t\t" << sizeof(long long) << "\t" << "[" << LLONG_MIN << ", " << LLONG_MAX << "]" << endl;
    cout << "unsigned long long:\t" << sizeof(unsigned long long) << "\t" << "[ " << ", " << ULLONG_MAX << "]" << endl;
    cout << endl;

    
    cout << "For floating-point types, the min and max are for the positive range" << endl; 
    cout << "float:\t\t\t" << sizeof(float) << "\t" << "[" << FLT_MIN << ", " << FLT_MAX << "]" << endl;
    cout << "double:\t\t\t" << sizeof(double) << "\t" << "[" << DBL_MIN << ", " << DBL_MAX << "]" << endl;
    cout << "long double:\t\t" << sizeof(long double) << "\t" << "[" << LDBL_MIN << ", " << LDBL_MAX << "]" << endl;
    cout << endl;

    cout << "Fixed width integers are defined in <cstdint>" << endl;
    cout << "int8_t:\t\t\t" << sizeof(int8_t) << "\t" << "[" << static_cast<int>(numeric_limits<int8_t>::min()) << ", " << static_cast<int>(numeric_limits<int8_t>::max()) << "]" << endl;
    cout << "int16_t:\t\t" << sizeof(int16_t) << "\t" << "[" << numeric_limits<int16_t>::min() << ", " << numeric_limits<int16_t>::max() << "]" << endl;
    cout << "int32_t:\t\t" << sizeof(int32_t) << "\t" << "[" << numeric_limits<int32_t>::min() << ", " << numeric_limits<int32_t>::max() << "]" << endl;
    cout << "int64_t:\t\t" << sizeof(int64_t) << "\t" << "[" << numeric_limits<int64_t>::min() << ", " << numeric_limits<int64_t>::max() << "]" << endl;
    cout << endl;

    cout << "uint8_t:\t\t" << sizeof(uint8_t) << "\t" << "[" << static_cast<int>(numeric_limits<uint8_t>::min()) << ", " << static_cast<int>(numeric_limits<uint8_t>::max()) << "]" << endl;
    cout << "uint16_t:\t\t" << sizeof(uint16_t) << "\t" << "[" << numeric_limits<uint16_t>::min() << ", " << numeric_limits<uint16_t>::max() << "]" << endl;
    cout << "uint32_t:\t\t" << sizeof(uint32_t) << "\t" << "[" << numeric_limits<uint32_t>::min() << ", " << numeric_limits<uint32_t>::max() << "]" << endl;
    cout << "uint64_t:\t\t" << sizeof(uint64_t) << "\t" << "[" << numeric_limits<uint64_t>::min() << ", " << numeric_limits<uint64_t>::max() << "]" << endl;

    return 0;
}





