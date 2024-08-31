#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 100;
const int MAX_USERS = 100;

struct Book {
    int id;
    string title;
    string author;
    bool isIssued;
};

struct User {
    int id;
    string name;
    int issuedBookId;
};

Book books[MAX_BOOKS];
User users[MAX_USERS];
int bookCount = 0;
int userCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        cout << "Book storage is full!\n";
        return;
    }
    cout << "Enter Book ID: ";
    cin >> books[bookCount].id;
    cout << "Enter Book Title: ";
    cin.ignore();
    getline(cin, books[bookCount].title);
    cout << "Enter Book Author: ";
    getline(cin, books[bookCount].author);
    books[bookCount].isIssued = false;
    bookCount++;
    cout << "Book added successfully!\n";
}

void displayBooks() {
    if (bookCount == 0) {
        cout << "No books available in the library.\n";
        return;
    }
    cout << "\nAvailable Books:\n";
    for (int i = 0; i < bookCount; i++) {
        if (!books[i].isIssued) {
            cout << "ID: " << books[i].id 
                 << ", Title: " << books[i].title 
                 << ", Author: " << books[i].author << endl;
        }
    }
}

void issueBook() {
    int bookId, userId;
    cout << "Enter User ID: ";
    cin >> userId;
    cout << "Enter Book ID to issue: ";
    cin >> bookId;

    int bookIndex = -1, userIndex = -1;

    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == bookId) {
            bookIndex = i;
            break;
        }
    }

    for (int i = 0; i < userCount; i++) {
        if (users[i].id == userId) {
            userIndex = i;
            break;
        }
    }

    if (bookIndex == -1) {
        cout << "Book not found.\n";
        return;
    }

    if (userIndex == -1) {
        cout << "User not found.\n";
        return;
    }

    if (books[bookIndex].isIssued) {
        cout << "Book is already issued.\n";
    } else {
        books[bookIndex].isIssued = true;
        users[userIndex].issuedBookId = bookId;
        cout << "Book issued successfully!\n";
    }
}

void returnBook() {
    int userId;
    cout << "Enter User ID: ";
    cin >> userId;

    int userIndex = -1;

    for (int i = 0; i < userCount; i++) {
        if (users[i].id == userId) {
            userIndex = i;
            break;
        }
    }

    if (userIndex == -1) {
        cout << "User not found.\n";
        return;
    }

    int bookId = users[userIndex].issuedBookId;

    if (bookId == -1) {
        cout << "No book to return.\n";
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == bookId) {
            books[i].isIssued = false;
            users[userIndex].issuedBookId = -1;
            cout << "Book returned successfully!\n";
            return;
        }
    }
}

void addUser() {
    if (userCount >= MAX_USERS) {
        cout << "User storage is full!\n";
        return;
    }
    cout << "Enter User ID: ";
    cin >> users[userCount].id;
    cout << "Enter User Name: ";
    cin.ignore();
    getline(cin, users[userCount].name);
    users[userCount].issuedBookId = -1;
    userCount++;
    cout << "User added successfully!\n";
}

void displayUsers() {
    if (userCount == 0) {
        cout << "No users available.\n";
        return;
    }
    cout << "\nUsers:\n";
    for (int i = 0; i < userCount; i++) {
        cout << "ID: " << users[i].id 
             << ", Name: " << users[i].name << endl;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Add User\n";
        cout << "6. Display Users\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                issueBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                addUser();
                break;
            case 6:
                displayUsers();
                break;
            case 7:
                cout << "Exiting the system.\n";
                return 0;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    }
    return 0;
}
