#include <bits/stdc++.h>
#include "librarian.h"
#include "user.h"
#include "books.h"
#include "utils.h"
#include <fstream>

using namespace std;
void librarian :: librarian_section() {

    while (true) {
        string options[] = {
            "display all books" , "display paid books" , "display free books"
            , "display all students" , "display all professors" , "display a specific author's books"
            , "add book" , "logout"
        } ;
        for (int index = 0 ; index < 8 ; index++ ) {
            cout << "press " << index + 1 << " to " << options[index] << " : \n" ;
        }

        char choice ; cin >> choice ;
        switch (choice) {
            case '1' :
                display_all_books() ;
                break ;
            case '2' :
                display_paid_books() ;
                break ;
            case '3' :
                display_free_books() ;
                break ;
            case '4' :
                display_all_users("all_students.txt") ;
                break ;
            case '5' :
                display_all_users("all_professors.txt") ;
                break ;
            case '6' :
                cout << "Enter Author/Professor id :\n" ;
                int professor_id ; cin >> professor_id ;
                if (hash_professor_name[professor_id] == "" ) {
                    cout << "Not valid id !\n" ;
                }
                else {
                    display_prof_books(hash_professor_name[professor_id]) ;
                }
                break ;
            case '7' :
                add_book() ;
                break ;

            case '8' :
                display_intro() ;
                return ;
            default :
                cout << "Error !\n" ;
        }
    }
}
void librarian :: set_librarian(string name , string password) {
    ofstream all_librarians_data ;
    all_librarians_data.open("all_librarian.txt" , ios :: app );

    int librarian_id = get_id("cur_lib_id.txt") ;
    all_librarians_data << librarian_id << " " << password << " " << name << endl;
    all_librarians_data.close();

    hash_librarian_name[librarian_id] = name ;
    hash_librarian_password[librarian_id] = password ;

    update_id("cur_lib_id.txt" , librarian_id ) ;
}
void librarian::display_all_users(const string file_name) {
    ifstream all_users_data(file_name) ;

    user User ;
    string temp ;
    if ( all_users_data.is_open() ) {
        vector<tuple<int,string,string>>data ;

        int distance1 = 5 , distance2 = 5 , distance3 = 5 ;
        while (getline(all_users_data, temp)) {
            stringstream ss(temp) ;
            ss >> User.id >> User.password >> User.name ;
            data.push_back({User.id, User.password, User.name}) ;
            distance2 = max(distance2 , (int)User.password.size() ) ;
            distance3 = max(distance3 , (int)User.name.size() ) ;
        }
        all_users_data.close();

        cout << setw(distance1) << "id" << "|" ;
        cout << setw(distance2) << "password" << "|" ;
        cout << setw(distance3) << "name" << '\n' ;
        cout << string(distance1 + distance2 + distance3 + 5 , '-') << '\n' ;

        for (int index = 0 ; index < data.size() ; index++) {
            cout << setw(distance1) << get<0>(data[index]) << "|" ;
            cout << setw(distance2) << get<1>(data[index]) << "|" ;
            cout << setw(distance3) << get<2>(data[index]) << '\n' ;
        }
    }
    else {
        cout << "No data available yet !\n" ;
    }
}
void librarian :: librarian_login() {
    cout << "Enter your id :" ;
    cin >> id ;

    cout << "Enter your password :" ;
    cin >> password ;

    try {
        if ( hash_librarian_password[id] != password )
            throw 0 ;

        cout << "Hello Mr." << hash_librarian_name[id] << " !\n\n" ;
    }
    catch (int i) {
        cout << "Invalid user ! \n" ;
        cout << "press (1) to try again :\n" ;
        cout << "press (2) to back :\n" ;

        char choice ; cin >> choice ;
        switch (choice) {
            case '1':
                librarian_login() ;
                break ;
            case '2' :
                display_intro() ; ;
                break ;
            default :
                cout << "Error !" ;
                librarian_login() ;
        }
    }
}