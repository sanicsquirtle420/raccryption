#include <string>
#include <cstring>
#include <iostream>
#include <bits/stdc++.h>
#include "src/keyword.cpp"
#include "src/ractils.hpp"

using namespace std ;

int main(int argc, char* argv[]) {
    int enc ;
    Keyword k ;
    string line ;
    ifstream file(argv[2]) ;

    if(strcmp(argv[1], "-e") == 0 || strcmp(argv[1], "--encrypt") == 0) {
        enc = 1 ;
    } else if(strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "--decrypt")  == 0) {
        enc = 0 ;
    } else {
        cout << "ERROR: No valid flags were set at argv[1]" << endl ;
        cout << "\traccryption [-e, -d] [FILE] [KEY]" << endl ;
        return 1 ;
    }

    if(argc > 3) {
        if(enc) {
            ofstream fi(file_name(argv[2], enc)) ;
            while(getline(file, line)) {
                fi << k.encrypt(argv[3], line) << "\n" ;
            }
        } else {
            ofstream fi(file_name(argv[2], enc)) ;
            while(getline(file, line)) {
                fi << k.decrypt(argv[3], line) << "\n" ;
            }
        }
    } else {
        cout << "ERROR: Key not set at argv[3]" << endl ;
        cout << "\traccryption [-e, -d] [FILE] [KEY]" << endl ;
        return 1 ;
    }

    file.close() ;
    return 0 ;
}