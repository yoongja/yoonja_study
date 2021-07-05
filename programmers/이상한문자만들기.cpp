#include <string> 
#include <vector> 
using namespace std; 
string solution(string s) { 
    int ch=0; 
    for( int i = 0 ; i < s.length() ; i++ ){ 
        if (s[i]==' ') { 
        ch=0; 
            continue; 
    } 
     if ( ch % 2 == 0) { 
         if (s[i]>= 'a' && s[i] <= 'z') 
             s[i] = s[i]-'a'+'A'; 
     } 
        else { 
            if (s[i]>= 'A' && s[i] <= 'Z') 
                s[i] = s[i]-'A'+'a'; 
        } 
        ch++; 
    } 
    return s; 
}