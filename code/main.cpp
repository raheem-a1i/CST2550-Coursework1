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
    int staffid;
    int salary;
};

class Member : public Person{
private:
    int memberid;
    //std::vector<Book> booksborrowed;
};

int main(){
    int number = 0;

    std::cout << "Librarian login\n";
    std::cout << "1. Login\n";
    std::cout << "2. Signup\n";
    std::cin >> number;
    if (number == 1){
        std::cout << "Login\n";

        std::cout << "Enter your staff id:\n";

        std::cout << "Enter your password:\n";
    }
    else if (number == 2){
        std::cout << "Enter your name:\n";

        std::cout << "Enter your address:\n";

        std::cout << "Enter your email:\n";

        std::cout << "Enter your staff id:\n";

        std::cout << "Enter your password:\n";

        std::cout << "Enter your salary:\n";
    }else{
        std::cout << "Invaild input\n";
    }
    return 0;
}