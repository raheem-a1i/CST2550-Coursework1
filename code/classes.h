#ifndef _CLASSES_H_
#define _CLASSES_H_
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <limits>

struct Date
{
    int month;
    int day;
    int year;
};

class Book;

class Person
{
private:
    std::string Name;
    std::string Address;
    std::string Email;

public:
    Person() {}
    Person(std::string name, std::string address, std::string email)
    {
        Name = name;
        Address = address;
        Email = email;
    }
    void setName(std::string name)
    {
        Name = name;
    }
    std::string getName()
    {
        return Name;
    }
    void setAddress(std::string address)
    {
        Address = address;
    }
    std::string getAddress()
    {
        return Address;
    }
    void setEmail(std::string email)
    {
        Email = email;
    }
    std::string getEmail()
    {
        return Email;
    }
};

class Librarian : public Person
{
private:
    int StaffId;
    int Salary;

    Date today;
    std::vector<Member *> members;

public:
    Librarian() {}

    Librarian(int staffid, int salary, std::string name, std::string address, std::string email, int day, int mon, int year) : Person(name, address, email){
        StaffId = staffid;
        Salary = salary;

        today = {day,mon,year};
    }

    Member *addMember(int m, std::string n, std::string addr, std::string mail){
        Member *newMember = new Member(m, n, addr, mail);
        members.push_back(newMember);
        return newMember;
    }
    std::vector<Member*>& getMembers() {
        return members;
    }
    void issueBook(Member &x,  Book &b){
        if (b.getissue()){
            std::cout << "Book already issued";
            return;
        }
        x.setBooksBorrowed(b);
        Date temp = {today.day + 3, today.month, today.year};
        b.borrowBook(temp);
        // setting due date for 3 days later
        // not working
    }
    void returnBook(Member &x, Book b){
        x.removeBookBorrowed(b);
        b.returnBook();
    }
    void displayBorrowedBook(Member &x){
        std::cout << "Displaying Books for " << x.getName()<<": \n";
        x.displayBooks();
    }
    //could not get to work
    void calcFine(Member x)
    {
        int fine;
        std::vector<Book> bks;
        bks = x.getBooksBorrowed();
        Date dueDate;

        std::cout << "\nThe Total Fine for " << x.getName() << " is: " << fine << "\n";
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

class Member : public Person
{
private:
    int memberID;
    std::vector<Book> booksloaned;

public:
    Member(int memberid, std::string name, std::string address, std::string email) : Person(name, address, email){
        memberID = memberid;
    }

    int getMemberID(){
        return memberID;
    }

    void setMemberID(int mid){
        memberID = mid;
    }

    std::vector<Book> getBooksBorrowed(){
        return booksloaned;
    }

    void setBooksBorrowed(Book &b){
        booksloaned.push_back(b);
    }

    void removeBookBorrowed(Book &b){
        auto iter = find(booksloaned.begin(), booksloaned.end(), b);
        if (iter != booksloaned.end()){
            booksloaned.erase(iter);
            std::cout << "Book removed from the Issued: " << b.getbookName() << "\n";
        }
        else{
            std::cout << "Book not found in the Issued: " << b.getbookName() << "\n";
        }
    }

    void displayBooks(){
        for (int i = 0; i < booksloaned.size(); ++i){
            std::cout << "Book ID: " << booksloaned[i].getbookID();
            std::cout << "Book Name: " << booksloaned[i].getbookName();
            std::cout << "Page Count: " << booksloaned[i].getPageCount();
            std::cout << "Author: " << booksloaned[i].getauthorFirstName() << " " << booksloaned[i].getauthorLastName();
            std::cout << "Book Type: " << booksloaned[i].getbookType() << "\n";
        }
    }
};

class Book
{
private:
    std::string bookID;
    std::string bookName;
    std::string authorFirstName;
    std::string authorLastName;
    std::string bookType;
    Date dueDate;
    Person borrower;
    std::string pageCount;
    int issued;

public:
    Book() {issued = 0;}
    Book(std::string bookid, std::string name, std::string firstName, std::string lastName, std::string booktype, std::string page)
    {
        bookID = bookid;
        bookName = name;
        authorFirstName = firstName;
        authorLastName = lastName;
        bookType = booktype;
        pageCount = page;
    }

    std::string getbookID()
    {
        return bookID;
    }

    std::string getbookName()
    {
        return bookName;
    }

    std::string getauthorFirstName()
    {
        return authorFirstName;
    }

    std::string getauthorLastName()
    {
        return authorLastName;
    }

    std::string getPageCount()
    {
        return pageCount;
    }

    std::string getbookType(){
        return bookType;
    }

    void setBookID(std::string bookid){
        bookID = bookid;
    }
    void setBookName(std::string name){
        bookName = name;
    }
    void setPageCount(std::string pages){
        pageCount = pages;
    }
    void setAuthorFirstName(std::string firstName){
        authorFirstName = firstName;
    }
    void setAuthorLastName(std::string lastName){
        authorLastName = lastName;
    }
    void setBookType(std::string type){
        bookType = type;
    }

    void setissue(){
        if(issued){
            issued = 0;
        }else{
            issued = 1;
        }
    }

    int getissue(){
        return issued;
    }

    void setDueDate(Date d){
        dueDate = d;
    }

    Date getDueDate(){
        return dueDate;
    }

    bool operator==(const Book &other) const{
        return bookID == other.bookID;
    }

    void setDueDate(Date newDueDate){
        dueDate = newDueDate;
    }

    void returnBook(){
        //clearing the duedate
        dueDate = {0, 0, 0};

        if (!borrower.getName().empty())
        {
            std::cout << "Book returned by " << borrower.getName() << "\n";
            borrower.setName("");
            setissue();
        }
        else
        {
            std::cout << "Book is not currently borrowed. \n";
        }
    }

    void borrowBook(Date y){
        dueDate = y;
        setissue();
    }
};

//read the csv file
//get the postion of each header. 
void readbks(const std::string &filename, std::vector<Book> &books){

    std::ifstream file(filename);

    if (!file.is_open()){
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;

    while (getline(file, line)){
        size_t pos = 0;
        size_t start = 0;
        std::vector<std::string> fields;
        bool flg = false;

        while (pos < line.length()){

            if (line[pos] == '"'){
                flg = !flg; 
                pos++;
                continue;
            }

            if (!flg && line[pos] == ','){
                fields.push_back(line.substr(start, pos - start));
                start = pos + 1;
            }

            pos++;
        }

        fields.push_back(line.substr(start));

        if (fields.size() == 6){
            Book book;
            book.setBookID(fields[0]);
            book.setBookName(fields[1]);
            book.setPageCount(fields[2]);
            book.setAuthorFirstName(fields[3]);
            book.setAuthorLastName(fields[4]);
            book.setBookType(fields[5]);

            books.push_back(book);
        }
    }

    file.close();
}

#endif