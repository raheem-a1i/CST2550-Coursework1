#include <iostream>
#include <vector>
#include "classes.h"

int main(){
    int choice;
    int choice1;
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
        std::cout << "Enter choice: ";
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

                    std::cout << "1. Add a Member\n";
                    std::cout << "2. Issue a book\n";
                    std::cout << "3. Return a book\n";
                    std::cout << "4. Display all books borrowed\n";
                    std::cout << "5. Logout\n";
                    std::cout << "Enter choice: ";
                    std::cin >> choice1;

                    switch (choice1){
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    
                    default:
                        break;
                    }
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