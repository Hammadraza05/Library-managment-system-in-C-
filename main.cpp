#include <iostream>
using namespace std;

//  structure for student information
struct Student {
    string name;
    string id;
    string department;
};

// Nested structure for author information
struct Author {
    string name;
    string subject;
};

// Nested structure for book information
struct Book {
    string id;
    string name;
    Author authorInfo;
    string price;
    string dateIssued;
    Student issuedTo;
};

// Library structure with nested structures
struct Library {
    string id;
    Student studentInfo;
    Book bookInfo;
};

// Function to input book details
void inputBookDetails(Library* books, int numBooks) {
    cout << "\n---- Input Book Details ----\n";
    for (int i = 0; i < numBooks; i++) {
        cout << "Enter library id for book #" << i + 1 << ": ";
        cin >> books[i].id;

        // Input student details
        cout << "Enter student name #" << i + 1 << ": ";
        cin.ignore();
        getline(cin, books[i].bookInfo.issuedTo.name);

        cout << "Enter student id #" << i + 1 << ": ";
        cin >> books[i].bookInfo.issuedTo.id;

        // Input author details
        cout << "Enter author name of book #" << i + 1 << ": ";
        cin.ignore();
        getline(cin, books[i].bookInfo.authorInfo.name);

        cout << "Enter author subject #" << i + 1 << ": ";
        getline(cin, books[i].bookInfo.authorInfo.subject);

        // Input book details
        cout << "Enter book name #" << i + 1 << ": ";
        getline(cin, books[i].bookInfo.name);

        cout << "Enter price #" << i + 1 << ": ";
        cin >> books[i].bookInfo.price;

        cout << "Enter date issued #" << i + 1 << ": ";
        cin >> books[i].bookInfo.dateIssued;
    }
}

//  display book details
void displayBookDetails(const Library* books, int numBooks) {
    cout << "\n---- Library Book Details ----\n";
    for (int i = 0; i < numBooks; i++) {
        cout << "Library ID: " << books[i].id << endl;
        cout << "Student Name: " << books[i].bookInfo.issuedTo.name << endl;
        cout << "Student ID: " << books[i].bookInfo.issuedTo.id << endl;
        cout << "Student Department: " << books[i].bookInfo.issuedTo.department << endl;
        cout << "Author Name: " << books[i].bookInfo.authorInfo.name << endl;
        cout << "Author Subject: " << books[i].bookInfo.authorInfo.subject << endl;
        cout << "Book Name: " << books[i].bookInfo.name << endl;
        cout << "Book Price: " << books[i].bookInfo.price << endl;
        cout << "Book Issued Date: " << books[i].bookInfo.dateIssued << endl;
        cout << "--------------------------" << endl;
    }
}

int main() {
    cout << "Enter the number of books in the library: ";
    int numBooks;
    cin >> numBooks;

    Library lib[numBooks]; // static array
    int input;
do {
    cout << "\nEnter 1 to input details\n";
    cout << "Enter 2 to display all details\n";
    cout << "Enter 3 to display details by student ID\n";
    cout << "Enter 4 to quit\n";
    cout << "Choice: ";
    cin >> input;

    switch (input) {
        case 1:
            inputBookDetails(lib, numBooks);
            break;
        case 2:
            displayBookDetails(lib, numBooks);
            break;
        case 3: {
            // gettin details by student ID
            cout << "Enter student ID to display details: ";
            string studentID;
            cin >> studentID;

            for (int i = 0; i < numBooks; i++) {
                if (lib[i].bookInfo.issuedTo.id == studentID) {
                    cout << "\n---- Library Book Details form Student ID " << studentID << " ----\n";
                    cout << "Library ID: " << lib[i].id << endl;
                    cout << "Student Name: " << lib[i].bookInfo.issuedTo.name << endl;
                    cout << "Author Name: " << lib[i].bookInfo.authorInfo.name << endl;
                    cout << "Book Name: " << lib[i].bookInfo.name << endl;
                    cout << "Book Price: " << lib[i].bookInfo.price << endl;
                    cout << "Book Issued Date: " << lib[i].bookInfo.dateIssued << endl;
                    cout << "--------------------------" << endl;
                    break;
                }
            }

            cout << "No books found for student ID " << studentID << endl;
            break;
        }
        case 4:
            cout << "Exiting the program...\n";
            exit(0);
        default:
            cout << "Invalid choice. Please try again.\n";
    }
} while (true);
    return 0;
}
