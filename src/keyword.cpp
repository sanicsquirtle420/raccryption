#include <algorithm>
#include <iostream>
#include <iterator>
#include <cctype>
#include <vector>
#include <string>

using namespace std ;

class Keyword {
    private: 
        vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
            'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
            'w', 'x', 'y', 'z'} ;
    public:
        string encrypt(string key, string text) {
            string ans = "" ;
            vector<char> a = alphabet ;
            for(int i = key.size() - 1; i >= 0 ; i--) {
                char juno = tolower(static_cast<unsigned char>(key[i])) ;
                auto iter = find(a.begin(), a.end(), juno) ;
                if(iter != a.end()) {
                    a.erase(iter) ;
                    a.insert(a.begin(), juno) ;
                }
            }

            for(int i = 0; i < text.size(); i++) {
                char kiriko = tolower(static_cast<unsigned char>(text[i])) ;
                auto iter = find(alphabet.begin(), alphabet.end(), kiriko) ;
                if(iter != alphabet.end()) {
                    int k = distance(alphabet.begin(), iter) ;
                    ans += a[k] ;
                }
                else {
                    ans += text[i] ;
                }
            }
            return ans ;
        }

        string decrypt(string key, string text) {
            string ans = "" ;
            vector<char> a = alphabet ;
            for(int i = key.size() - 1; i >= 0 ; i--) {
                char juno = tolower(static_cast<unsigned char>(key[i])) ;
                auto iter = find(a.begin(), a.end(), juno) ;
                if(iter != a.end()) {
                    a.erase(iter) ;
                    a.insert(a.begin(), juno) ;
                }
            }

            for(int i = 0; i < text.size(); i++) {
                char kiriko = tolower(static_cast<unsigned char>(text[i])) ;
                auto iter = find(a.begin(), a.end(), kiriko) ;
                if(iter != a.end()) {
                    int k = distance(a.begin(), iter) ;
                    ans += alphabet[k] ;
                }
                else {
                    ans += text[i] ;
                }
            }
            return ans ;
        }
} ;