#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <bits/stdc++.h>
#include "user.h"
using namespace std;

class professor : public user {
public :
    void professor_section(int) ;
    int professor_login() ;
    void set_professors(string , string) ;
};
#endif //PROFESSOR_H
