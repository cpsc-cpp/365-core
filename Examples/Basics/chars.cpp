/**
 * @file chars.cpp
 * @brief chars and wide chars
 * 
 * Working with character types in C++.
 */


#include <iostream>
#include <string>

#include <locale>
#include <codecvt>

using namespace std;

int main() {
    // Chars can be converted between char types and behave like
    // integers. Beware of the signedness.
    unsigned char uc {255}; // corresponds to 0xFF
    signed char sc {uc};    // What will happen here? Sure we want to do this?
    cout << (int)sc << endl;

    sc = -120;
    uc = sc; // Can go from signed to unsigned
    cout << (int)uc << endl << endl;

    // lower case English alphabet using char
    for(size_t i = 0; i < 26; i++) {
        cout << static_cast<char>('a' + i) << " ";
    }
    cout << endl;

    // lower case Greek alphabet using wchar_t in unicode
    // Need some additional conversions for handling UTF8
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t> > myconv;
    for(size_t i = 0; i < 25; i++) {
        // \u and \U are used to specify 4 and 8 hex digit character codes
        // u, U and L are used as prefixes for wider character literals. 
        wchar_t wc {static_cast<wchar_t>(u'\u03B1' + i)};
        wstring ws(1,wc);
        cout << myconv.to_bytes(ws) << ' ';
    }
    cout << endl << endl;

    // Integer literals can be specified as either decimal, octal or hexadecimal
    u_int8_t d_int {32};
    cout << (d_int == 040) << endl; // initial 0 specifies octal digits
    cout << (d_int == 0x20) << endl << endl; // 0x specified hexadecimal digits

    // Use the suffixes U and L for unsigned and long
    cout << "3U has a size of " << sizeof(3U) << " bytes" << endl;
    cout << "3UL has a size of " << sizeof(3UL) << " bytes" << endl << endl; 
    
    // Use the suffix f or F for floats, otherwise they are interpreted as doubles.
    cout << "3.0 has a size of " << sizeof(3.0) << " bytes" << endl;
    cout << "3.0f has a size of " << sizeof(3.0f) << " bytes" << endl << endl;  

    // And here are some string literals:
    // use prefix R for raw strings, with the string in parentheses.
    // and the prefixes u8, u or U for UTF-8, UTF-16 and UTF-32 strings.
    cout << "This string has a new line\n";
    cout << R"(This is a raw string with a literal \n)" << endl; 
    cout << u8"This string has some cool characters: \U0001F4BB \U0001F600\n\n";
}