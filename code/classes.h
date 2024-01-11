#ifndef _CLASSES_H_
#define _CLASSES_H_
#include <iostream>
#include <vector>
#include <string>

struct Date {
    int month;
    int day;
    int year;
};

class Book;

class Person {
private:
    std::string Name;
    std::string Address;
    std::string Email;

    public:
    Person() {}
    Person(std::string name, std::string address, std::string email){
        Name = name;
        Address = address;
        Email = email;
    }
    void setName(std::string name){
        Name = name;
    }
    std::string getName(){
        return Name;
    }
    void setAddress(std::string address){
        Address = address;
    }
    std::string getAddress(){
        return Address;
    }
    void setEmail(std::string email){
        Email = email;
    }
    std::string getEmail(){
        return Email;
    }
};

class Librarian : public Person{
private:
    int StaffId;
    int Salary;

    public:
    Librarian() {}

    Librarian(int StaffId, std::string Name, std::string Address, std::string Email, int Salary){
        setName(Name);
        setAddress(Address);
        setEmail(Email);
        this->StaffId = StaffId;
        this->Salary = Salary;
    }

    void addMenber() {

    }
    void issueBook(int memberID, int bookID){

    }
    void returnBook(int memberID, int bookID){

    }
    void displayBorrowedBook(int memberID){

    }
    void calcFine(int memberID){
        
    }
    void setstaffid(int staffid){
        StaffId = staffid;
    }
    int getstaffid(){
        return StaffId;
    }
    void setsalary(int salary){
        Salary = salary;
    }
    int getsalary(){
        return Salary;
    }
};

class Member : public Person{
private:
    int memberID;
    std::vector<Book> booksloaned;

public:
    Member(int memberID, std::string name, std::string address, std::string email){
        setName(name);
        setAddress(address);
        setEmail(email);
        this->memberID = memberID;
    }

    int getMemberID(){
        return memberID;
    }

    std::vector<Book> getBooksBorrowed() {
        return booksloaned;
    }

    void setBooksBorrowed(Book &b){
        booksloaned.push_back(b);
    }
};

class Book{
    private:
    int bookID;
    std::string bookName;
    std::string authorFirstName;
    std::string authorLastName;
    std::string bookType;
    Date dueDate;
    Member *borrower;

    public:
    Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName)
        : bookID(bookID), bookName(bookName), authorFirstName(authorFirstName), authorLastName(authorLastName), borrower(nullptr) {}

    int getbookID(){
        return bookID;
    }

    std::string getbookName(){
        return bookName;
    }

    std::string getauthorFirstName(){
        return authorFirstName;
    }

    std::string getauthorLastName(){
        return authorLastName;
    }

    Date getDueDate() {
        return dueDate;
    }

    void setDueDate(Date newDueDate) {
        dueDate = newDueDate;
    }

    void returnBook(){

    }

    void borrowBook(Member &member, Date newDueDate){
        
    }

};


#endif