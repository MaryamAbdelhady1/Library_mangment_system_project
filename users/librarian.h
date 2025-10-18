#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include <bits/stdc++.h>
#include "user.h"
#include "books.h"

using namespace std;


class librarian : public user , protected books {
protected :
    void display_all_users(const string) ;
public :
    void set_librarian(string , string ) ;
    void librarian_section() ;
    void librarian_login() ;
};
#endif
