#include <iostream>

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
    int memberid;
};

int main(){
    int choice = 0;

    do{
        std::cout << "Librarian login\n";
        std::cout << "1. Login\n";
        std::cout << "2. Signup\n";
        std::cout << "3. Exit\n";
        std::cin >> choice;

        switch (choice){
            case 1:
            std::cout << "Login --";
            break;

            case 2:
            std::cout << "Signup --";
            break;

            case 3:
            std::cout << "Exiting . . .";
            break;

            default:
            std::cout << "Invalid \n";
        }
    } while (choice != 3);
    
    return 0;
}