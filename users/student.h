#ifndef STUDENT_H
#define STUDENT_H

#include <bits/stdc++.h>
#include "user.h"

using namespace std;


class student : public user {
public :
    void student_section() ;
    void student_login() ;
    void set_students(string , string ) ;
};

#endif //STUDENT_H
