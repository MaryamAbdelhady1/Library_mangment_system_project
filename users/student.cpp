#include <bits/stdc++.h>
#include "student.h"
#include "user.h"
#include "books.h"
#include "utils.h"
#include <fstream>
using namespace std;
void student :: student_section() {
    student s ;

    bool flag = true ;
    while (flag) {
        string options[] = {"display all books" , "display paid books" , "display free books"
        , "logout" } ;

        for (int index = 0 ; index < 4 ; index++) {
            cout << "press " << index + 1 << " to " << options[index] << " : \n" ;
        }

        books book ;
        char choice ; cin >> choice ;
        switch (choice) {
            case '1':
                book.display_all_books() ;
                break ;
            case '2':
                book.display_paid_books() ;
                break ;
            case '3' :
                book.display_free_books() ;
                break ;
            case '4' :
                display_intro() ;
                return ;

            default :
                cout << "Error !\n" ;
                student_section() ;
        }
    }
}
void student :: set_students(string name , string password ) {
    ofstream all_students_data ;
    all_students_data.open("all_students.txt" , ios :: app );

    int student_id = get_id("cur_st_id.txt") ;
    all_students_data << student_id << " " << password << " " << name << endl;
    all_students_data.close();

    hash_student_name[student_id] = name ;
    hash_student_password[student_id] = password ;

    update_id("cur_st_id.txt" , student_id ) ;
}

void student :: student_login() {
    cout << "Enter your id :" ;
    cin >> id ;

    cout << "Enter your password :" ;
    cin >> password ;

    try {
        if ( hash_student_password[id] != password )
            throw 0 ;

        cout << "Hello " << hash_student_name[id] << " !\n\n" ;
    }
    catch (int i) {
        cout << "Invalid user ! \n" ;
        cout << "press (1) to try again :\n" ;
        cout << "press (2) to back :\n" ;

        char choice ; cin >> choice ;
        switch (choice) {
            case '1':
                student_login() ;
                break ;
            case '2' :
                display_intro() ;
                break ;
            default :
                cout << "Error !" ;
                student_login() ;
        }
    }
}