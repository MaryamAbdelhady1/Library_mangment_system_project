#ifndef USER_H
#define USER_H

#include <bits/stdc++.h>

using namespace std;

extern unordered_map<int,string> hash_professor_password, hash_professor_name;
extern unordered_map<int,string> hash_librarian_password, hash_librarian_name;
extern unordered_map<int,string> hash_student_password, hash_student_name;

class user {
public :
    user() {
    start() ;
}
    int id ; string name , password ;
    void start() ;
    void display_intro() ;
    char check1() ;
    char check2() ;
    void log_in() ;
    void sign_up() ;
};


#endif
