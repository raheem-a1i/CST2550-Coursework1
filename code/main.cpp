#include <iostream>
#include <vector>


class Person {
private:
    std::string Name;
    std::string Address;
    std::string Email;

    public:
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
    std::vector<class ::Book> booksloaned;

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

    std::vector<class::Book> getBooksBorrowed() {
        return booksloaned;
    }

    void setBooksBorrowed(Book book) {
        booksloaned = {book}; 
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

class Date{

};

int main(){
    int choice;
    int num1;
    bool found = false;
    
    const int max_librarian = 5; // Maximum number of librarians
    Librarian* librarians[max_librarian]; // Array to store librarians
    int librariancount = 0;

    std::string name;
    std::string address;
    std::string email;

    do{
        std::cout << "Librarian login\n";
        std::cout << "1. Signup\n";
        std::cout << "2. Login\n";
        std::cout << "3. Exit\n";
        std::cin >> choice;

        switch (choice){
        case 1:
            int StaffID, salary;

            std::cout << "------- Signup -------\n";
            std::cout << "Enter StaffID\n";
            std::cin >> StaffID;
            std::cout << "Enter Name\n";
            std::cin >> name;
            std::cout << "Enter Address\n";
            std::cin >> address;
            std::cout << "Enter Email\n";
            std::cin >> email;
            std::cout << "Enter Salary\n";
            std::cin >> salary;

            librarians[librariancount] = new Librarian(StaffID, name, address, email, salary);
            librariancount++;

            std::cout << "Librarian signed up successfully!\n";

            break;

        case 2:
            std::cout << "------- Login -------\n";
            int staffid;
            std::cout << "Enter StaffID: \n";
            std::cin >> staffid;

            for (int i = 0; i < librariancount; i++)
            {
                if (librarians[i]->getstaffid() == staffid)
                {
                    found = true;
                    std::cout << "Login successful\n";
                    break;
                }
            }

            if (!found)
            {
                std::cout << "No Libraian found\n";
                break;
            }
        case 3:
            std::cout << "------- Exiting -------\n";
            break;

        default:
            std::cout << "Invalid choice\n";
        }
    } while (choice != 3);

    return 0;
}