#include <bits/stdc++.h>
#include "books.h"
#include "user.h"
#include "utils.h"
#include "professor.h"
#include "student.h"
#include "librarian.h"
#include <fstream>
using namespace std;
unordered_map<int,string> hash_professor_password, hash_professor_name;
unordered_map<int,string> hash_librarian_password, hash_librarian_name;
unordered_map<int,string> hash_student_password, hash_student_name;

char user :: check1() {
    string options[] = { "login" , "sign up" , "exit" } ;
    for (int index = 0 ; index < 3 ; index++ ) {
        cout << "press " << index + 1 << " to " << options[index] << " : \n";
    }

    try {
        char choice ; cin >> choice ;
        if ( !(choice >= '1' && choice <= '3') )
            throw 0 ;

        return choice ;
    }
    catch (int random){
        cout << "Error ! \n" ;
        return check1() ;
    }
}
char user :: check2() {
    string options[] = { "professor" , "librarian" ,"student" } ;
    for (int index = 0 ; index < 3 ; index++ ) {
        cout << "press " << index + 1 << " if you are a " << options[index] << " : \n";
    }

    try {
        char choice ; cin >> choice ;
        if ( !(choice >= '1' && choice <= '3') )
            throw 0 ;

        return choice ;
    }
    catch (int random){
        cout << "Error ! \n" ;
        return check2() ;
    }
}
void user :: display_intro() {

    cout << "Welcome to Your Knowledge Hub ...\n Where Every Book Tells a Story !\n\n" ;
    char choice = check1() ;

    if (choice == '1') {
        user User ;
        User.log_in() ;
    }
    else if (choice == '2') {
        user User ;
        User.sign_up() ;
    }
    else {
        cout << "Thanks for your visiting ! \n"  ;
    }
}
void user :: log_in() {
    char choice = check2() ;

    if ( choice == '1' ) {
        professor Professor ;
        int cur_id = Professor.professor_login() ;
        Professor.professor_section(cur_id) ;
    }
    else if ( choice == '2' ) {
        librarian Librarian ;
        Librarian.librarian_login() ;
        Librarian.librarian_section() ;
    }
    else if (choice == '3'){
        student Student ;
        Student.student_login() ;
        Student.student_section() ;
    }
    else{
        cout << "Error !\n" ;
        log_in() ;
    }
}
void user :: sign_up() {
    char choice = check2() ;

    cout << "Enter your name :" ;
    cin >> name ;
    cout << "Enter your password :" ;
    cin >> password ;

    switch (choice) {
        case '1' : {
            professor Professor ;
            id = get_id("cur_prof_id.txt") ;
            Professor.set_professors(name , password) ;
            break ;
        }
        case '2' : {
            librarian Librarian ;
            id = get_id("cur_lib_id.txt") ;
            Librarian.set_librarian(name , password) ;
            break ;
        }
        case '3' : {
            student Student ;
            id = get_id("cur_st_id.txt") ;
            Student.set_students(name , password) ;
            break ;
        }
    }

    cout << "signed up successfully !\n" ;
    cout << "please keep that your id is : " << id << "\n\n" ;

    display_intro() ;
}
void user :: start() {
    ifstream all_professors_data("all_professors.txt") ;
    string temp1 ;
    while (getline(all_professors_data , temp1)) {
        stringstream ss(temp1) ;
        ss >> id >> password >> name ;
        hash_professor_name[id] = name ;
        hash_professor_password[id] = password ;
    }

    ifstream all_librarian_data("all_librarian.txt") ;
    string temp2 ;
    while (getline(all_librarian_data , temp2)) {
        stringstream ss(temp2) ;
        ss >> id >> password >> name ;
        hash_librarian_name[id] = name ;
        hash_librarian_password[id] = password ;
    }

    ifstream all_students_data("all_students.txt") ;
    string temp3 ;
    while ( getline(all_students_data , temp3) ) {
        stringstream ss(temp3) ;
        ss >> id >> password >> name ;
        hash_student_name[id] = name ;
        hash_student_password[id] = password ;
    }

}