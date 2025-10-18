#include <bits/stdc++.h>
#include "professor.h"
#include "books.h"
#include "utils.h"
#include "user.h"
#include <fstream>
using namespace std;
void professor :: professor_section(int current_id) {
    string options[] = {"display all books" , "display your books"
       , "logout" } ;

    while (true) {
        for (int index = 0 ; index < 3 ; index++) {
            cout << "press " << index + 1 << " to " << options[index] << " : \n" ;
        }

        books book ;
        char p ; cin >> p ;
        switch (p) {
            case '1' :
                book.display_all_books() ;
                break ;
            case '2' :
                book.display_prof_books(hash_professor_name[current_id]) ;
                break ;
            case '3' :
                display_intro() ;
                return ;

            default :
                cout << "Error !\n" ;
                professor_section(current_id) ;
        }
    }
}
void professor :: set_professors(string name , string password) {
    ofstream all_professors_data ;
    all_professors_data.open("all_professors.txt" , ios :: app) ;

    int professor_id = get_id("cur_prof_id.txt") ;
    all_professors_data << professor_id << " " << password << " " << name << endl;
    all_professors_data.close();

    hash_professor_name[professor_id] = name ;
    hash_professor_password[professor_id] = password ;

    update_id("cur_prof_id.txt" , professor_id );
}
int professor :: professor_login() {
    cout << "Enter your id :" ;
    cin >> id ;

    cout << "Enter your password :" ;
    cin >> password ;

    try {
        if ( hash_professor_password[id] != password )
            throw 0 ;

        cout << "Hello Dr." << hash_professor_name[id] << " !\n\n" ;
        return id ;
    }
    catch (int i) {
        cout << "Invalid user ! \n" ;
        cout << "press (1) to try again :\n" ;
        cout << "press (2) to back :\n" ;

        char p ; cin >> p ;
        switch (p) {
            case '1':
                professor_login() ;
                break ;
            case '2' :
                display_intro() ;
                break ;
            default :
                cout << "Error !" ;
                professor_login() ;
        }
    }
}