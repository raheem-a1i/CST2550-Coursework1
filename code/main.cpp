#include <iostream>

class Person {
private:
    string Name;
    string Address;
    string Email;
};

class Librarian : public Person{
private:
    int staffid;
    int salary;
};

class Member : public Person{
private:
    int memberid
    std::vector<Book> booksborrowed;
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