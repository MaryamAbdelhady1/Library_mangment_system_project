#include <bits/stdc++.h>
#include "books.h"
#include <fstream>
using namespace std;

void books :: display_all_books() {
    ifstream book_file("all_books.txt") ;

    string temp ;
    if ( book_file.is_open() ) {

        vector<vector<string>>data ;
        int distance1 = 5 , distance2 = 5 , distance3 = 5 , distance4 = 5 ;
        while (getline(book_file, temp)) {
            stringstream ss(temp) ;
            ss >> isb >> name >> author >> price ;
            data.push_back({isb , name , author , price } ) ;
            distance1 = max(distance1 , (int)isb.size()) ;
            distance2 = max(distance2 , (int)name.size()) ;
            distance3 = max(distance3 , (int)author.size()) ;
            distance4 = max(distance4 , (int)price.size()) ;
        }
        book_file.close();

        cout << setw(distance1) << "isb" << "|" ;
        cout << setw(distance2) << "name" << "|" ;
        cout << setw(distance3) << "author" << "|" ;
        cout << setw(distance4) << "price" << "\n"  ;
        cout << string(distance1 + distance2 + distance3 + distance4 + 5 , '-' ) << '\n' ;


        for (int index = 0 ; index < data.size() ; index++) {
            isb = data[index][0] ; name = data[index][1] ; author = data[index][2] ; price = data[index][3] ;
            cout << setw(distance1) << isb << "|" ;
            cout << setw(distance2) << name << "|" ;
            cout << setw(distance3) << author << "|" ;
            cout << setw(distance4) << price << "\n" ;
        }
    }
    else {
        cout << "No data available yet !\n" ;
    }

}
void books :: display_paid_books() {
    ifstream book_file("all_books.txt") ;

    string temp ;
    if ( book_file.is_open() ) {

        vector<vector<string>>data ;
        int distance1 = 5 , distance2 = 5 , distance3 = 5 , distance4 = 5 ;
        while (getline(book_file, temp)) {
            stringstream ss(temp) ;
            ss >> isb >> name >> author >> price ;
            if ( price == "free!" ) continue ;
            data.push_back({isb , name , author , price } ) ;
            distance1 = max(distance1 , (int)isb.size()) ;
            distance2 = max(distance2 , (int)name.size()) ;
            distance3 = max(distance3 , (int)author.size()) ;
            distance4 = max(distance4 , (int)price.size()) ;
        }
        book_file.close();

        cout << setw(distance1) << "isb" << "|" ;
        cout << setw(distance2) << "name" << "|" ;
        cout << setw(distance3) << "author" << "|" ;
        cout << setw(distance4) << "price" << "\n"  ;
        cout << string(distance1 + distance2 + distance3 + distance4 + 5 , '-' ) << '\n' ;


        for (int index = 0 ; index < data.size() ; index++) {
            isb = data[index][0] ; name = data[index][1] ; author = data[index][2] ; price = data[index][3] ;
            cout << setw(distance1) << isb << "|" ;
            cout << setw(distance2) << name << "|" ;
            cout << setw(distance3) << author << "|" ;
            cout << setw(distance4) << price << "\n" ;
        }
    }
    else {
        cout << "No data available yet !\n" ;
    }
}
void books :: display_free_books() {
    ifstream book_file("all_books.txt") ;

    string temp ;
    if ( book_file.is_open() ) {

        vector<vector<string>>data ;
        int distance1 = 5 , distance2 = 5 , distance3 = 5 , distance4 = 5 ;
        while (getline(book_file, temp)) {
            stringstream ss(temp) ;
            ss >> isb >> name >> author >> price ;
            if ( price == "free!" ) continue ;
            data.push_back({isb , name , author , price } ) ;
            distance1 = max(distance1 , (int)isb.size()) ;
            distance2 = max(distance2 , (int)name.size()) ;
            distance3 = max(distance3 , (int)author.size()) ;
            distance4 = max(distance4 , (int)price.size()) ;
        }
        book_file.close();

        cout << setw(distance1) << "isb" << "|" ;
        cout << setw(distance2) << "name" << "|" ;
        cout << setw(distance3) << "author" << "|" ;
        cout << setw(distance4) << "price" << "\n"  ;
        cout << string(distance1 + distance2 + distance3 + distance4 + 5 , '-' ) << '\n' ;


        for (int index = 0 ; index < data.size() ; index++) {
            isb = data[index][0] ; name = data[index][1] ; author = data[index][2] ; price = data[index][3] ;
            cout << setw(distance1) << isb << "|" ;
            cout << setw(distance2) << name << "|" ;
            cout << setw(distance3) << author << "|" ;
            cout << setw(distance4) << price << "\n" ;
        }
    }
    else {
        cout << "No data available yet !\n" ;
    }
}
void books :: display_prof_books(string prof_name) {
    ifstream book_file("all_books.txt") ;

    string temp ;
    if ( book_file.is_open() ) {

        vector<vector<string>>data ;
        int distance1 = 5 , distance2 = 5 , distance3 = 5 , distance4 = 5 ;
        while (getline(book_file, temp)) {
            stringstream ss(temp) ;
            ss >> isb >> name >> author >> price ;
            if ( author != prof_name ) continue ;
            data.push_back({isb , name , author , price } ) ;
            distance1 = max(distance1 , (int)isb.size()) ;
            distance2 = max(distance2 , (int)name.size()) ;
            distance3 = max(distance3 , (int)author.size()) ;
            distance4 = max(distance4 , (int)price.size()) ;
        }
        book_file.close();

        cout << setw(distance1) << "isb" << "|" ;
        cout << setw(distance2) << "name" << "|" ;
        cout << setw(distance3) << "author" << "|" ;
        cout << setw(distance4) << "price" << "\n"  ;
        cout << string(distance1 + distance2 + distance3 + distance4 + 5 , '-' ) << '\n' ;


        for (int index = 0 ; index < data.size() ; index++) {
            isb = data[index][0] ; name = data[index][1] ; author = data[index][2] ; price = data[index][3] ;
            cout << setw(distance1) << isb << "|" ;
            cout << setw(distance2) << name << "|" ;
            cout << setw(distance3) << author << "|" ;
            cout << setw(distance4) << price << "\n" ;
        }
    }
    else {
        cout << "No data available yet !\n" ;
    }
}
int get_isb() {
    int current = 0 ;
    ifstream current_number_of_books ;
    current_number_of_books.open("cur_books.txt") ;
    current_number_of_books >> current ;
    current_number_of_books.close();

    current++ ;
    ofstream cur_number_of_books1("cur_books.txt" , ios::trunc ) ;
    cur_number_of_books1 << current ;
    cur_number_of_books1.close();

    return current ;
}
void books::add_book() {
    int new_isb = get_isb() ;
    cout << "Enter book name :\n" ;
    cin >> name ;
    cout << "Enter author\n" ;
    cin >> author ;
    cout << "Enter price\n" ;
    cin >> price ;

    ofstream all_books_data ;
    all_books_data.open("all_books.txt" , ios::app ) ;
    all_books_data << new_isb << " " << name << " " << author << " " << price << '\n' ;
    all_books_data.close();
}

