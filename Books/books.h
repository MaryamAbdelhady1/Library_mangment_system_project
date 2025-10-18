#ifndef BOOKS_H
#define BOOKS_H

#include <bits/stdc++.h>
using namespace std;


class books {
protected :
    void add_book() ;
public :
    string isb , name , author , price ;
    void display_all_books() ;
    void display_paid_books() ;
    void display_free_books() ;
    void display_prof_books(string) ;
};


#endif
