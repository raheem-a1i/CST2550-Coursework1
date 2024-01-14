#include <iostream>
#include <vector>
#include "classes.h"

int main()
{
    int choice;
    int choice1;
    int num1;
    bool found = false;

    std::string name;
    std::string address;
    std::string email;

    std::vector<Book>booksloaned;
    std::string filename;
    std::cout << "Enter csv file name";
    std::cin >> filename;
    readbks(filename, booksloaned);

    int StaffID, salary;

    std::cout << "------- Signup for Librarian-------\n";
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

    Librarian librarian(StaffID, salary, name, address, email, 14, 1, 2024);

    std::cout << "Librarian signed up successfully!\n";

    do
    {
        std::cout << "-------- Library ---------\n";
        std::cout << "1. Add a Member\n";
        std::cout << "2. Issue a book\n";
        std::cout << "3. Return a book\n";
        std::cout << "4. Display all books borrowed\n";
        std::cout << "5. Logout\n";
        std::cout << "Enter choice: ";
        std::cin >> choice1;

        switch (choice1)
        {
        case 1:
            int memberID;
            std::cout << "Enter Member ID: ";
            std::cin >> memberID;
            std::cout << "Enter Name: ";
            std::cin >> name;
            std::cout << "Enter Address: ";
            std::cin >> address;
            std::cout << "Enter Email: ";
            std::cin >> email;

            Member *newMember = librarian.addMember(memberID, name, address, email);
            std::cout << "Member added successfully!\n";
            break;
        case 2:
            int memberID;
            int bookID;
            std::cout << "Enter Member ID: ";
            std::cin >> memberID;
            std::cout << "Select Book to Issue (Enter Book ID): ";
            std::cin >> bookID;

            if (booksloaned[bookID].getissue() == 0){
                if (memberID >= 0 && memberID <= librarian.getMembers().size() &&
                    bookID >= 0 && bookID < booksloaned.size()){
                    librarian.issueBook(*librarian.getMembers()[memberID], booksloaned[bookID]);
                    std::cout << "Book issued successfully!\n";
                }
                else{
                    std::cout << "Invalid Member ID or Book Index!\n";
                }
            }
            else{
                std::cout << "Can't Issue Book it is already Issued to someone else\n";
            }
            break;
        case 3:
            int memberID;
            int bookID;
            std::cout << "Enter Member ID: ";
            std::cin >> memberID;
            std::cout << "Select Book to Issue (Enter Book ID): ";
            std::cin >> bookID;

            if (memberID >= 0 && memberID <= librarian.getMembers().size() &&
                bookID >= 0){
                librarian.returnBook(*librarian.getMembers()[memberID], booksloaned[bookID]);
                std::cout << "Book returned successfully!\n";
            }
            else{
                std::cout << "Invalid Member ID or Book Index!\n";
            }
            break;
        case 4:
            int memberID;
            std::cout << "Enter Member ID: ";
            std::cin >> memberID;

            if (memberID >= 0 && memberID <= librarian.getMembers().size()){
                librarian.displayBorrowedBook(*librarian.getMembers()[memberID]);
            }
            else{
                std::cout << "Invalid Member ID!\n";
            }
            break;
        case 5:
            std::cout << "Logging Out. \n";
            break;
        default:
            std::cout << "Invaild choice. \n";
            break;
        }

    } while (choice1 != 5);

    return 0;
}