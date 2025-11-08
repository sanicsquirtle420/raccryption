#include "ractils.hpp"
#include <iostream>

using namespace std ;

vector<string> split_str(string str, string delimiter) {
    vector<string> tokens ;
    size_t start = 0 ;
    size_t end = str.find(delimiter) ;

    while(end != string::npos) {
        tokens.push_back(str.substr(start, end - start)) ;
        start = end + delimiter.length() ;
        end = str.find(delimiter, start) ;
    }
    tokens.push_back(str.substr(start)) ;
    return tokens ;
}

string file_name(string path, int type) {
    vector<string> file_p = split_str(path, "/") ;
    int index = file_p.size() - 1;
    string final_path ;

    size_t e_pos = file_p[index].find("-encrypt") ;
    size_t d_pos = file_p[index].find("-decrypt") ;

    // removing previous "-encrypt" or "-decrypt"
    if(e_pos != string::npos) {
        file_p[index].erase(e_pos, string("-encrypt").length()) ;
    } else if(d_pos != string::npos) {
        file_p[index].erase(d_pos, string("-decrypt").length()) ;
    }

    // building final filename
    vector<string> ext_v = split_str(file_p[index], ".") ;
    string ext = ext_v[ext_v.size() - 1] ;

    for(int i = 0; i < file_p.size() - 1; i++) {
        final_path += file_p[i] + "/" ;
    }

    for(int j = 0; j < ext_v.size(); j++) {
        if(j == ext_v.size() - 1 && type == 0) {
            final_path += "-decrypt." + ext ; 
        } else if(j == ext_v.size() - 1 && type == 1) {
            final_path += "-encrypt." + ext ;
        } else {
            final_path += ext_v[j] ;
        }
    }

    return final_path ;
}

using namespace std ;
