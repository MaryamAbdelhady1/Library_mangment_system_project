#include <bits/stdc++.h>
#include "utils.h"
#include <fstream>
using namespace std ;


int get_id(const string file_name) {
    int current_id = 0 ;
    ifstream id ;
    id.open(file_name) ;
    id >> current_id ;
    id.close () ;

    return current_id + 1 ;
}
void update_id(const string file_name , int id ) {
    ofstream cur_professor_id(file_name , ios::trunc ) ;
    cur_professor_id << id ;
    cur_professor_id.close();
}

