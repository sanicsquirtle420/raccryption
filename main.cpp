#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include "src/keyword.cpp"

using namespace std ;

int main(int argc, char* argv[]) {
    Keyword k ;
    ifstream file(argv[1]) ;
    string line ;

    ofstream fi("txt_files/juno-encrypt.txt") ;
    while(getline(file, line)) {
        fi << k.encrypt(argv[2], line) << "\n" ;
    }

    file.close() ;
    return 0 ;
}