#include "passserver.h"
#include <iostream>
#include <string>

using namespace cop4530;
using namespace std;

void Menu();

int main() {
    size_t tableSize;
    cout << "Enter preferred hash table capacity: ";
    cin >> tableSize;
    PassServer passServer(tableSize);

    char choice;
    do {
        Menu();
        cin >> choice;
        switch (choice) {
            case 'l': {
                string filename;
                cout << "Enter filename: ";
                cin >> filename;
                if (!passServer.load(filename.c_str())) {
                    cout << "Cannot load from " << filename << endl;
                } else {
                    cout << "Load successful" << endl;
                }
                break;
            }
            case 'a': {
                string user, password;
                cout << "Enter username: ";
                cin >> user;
                cout << "Enter password: ";
                cin >> password;
                if (!passServer.addUser(make_pair(user, password))) {
                    cout << "User already exists or addition failed." << endl;
                } else {
                    cout << "User added." << endl;
                }
                break;
            }
            case 'r': {
                string user;
                cout << "Enter username: ";
                cin >> user;
                if (!passServer.removeUser(user)) {
                    cout << "User not found or removal failed." << endl;
                } else {
                    cout << "User removed." << endl;
                }
                break;
            }
            case 'c': {
                string user, oldPass, newPass;
                cout << "Enter username: ";
                cin >> user;
                cout << "Enter old password: ";
                cin >> oldPass;
                cout << "Enter new password: ";
                cin >> newPass;
                if (!passServer.changePassword(make_pair(user, oldPass), newPass)) {
                    cout << "Password change failed." << endl;
                } else {
                    cout << "Password changed." << endl;
                }
                break;
            }
            case 'f': {
                string user;
                cout << "Enter username: ";
                cin >> user;
                if (passServer.find(user)) {
                    cout << "User '" << user << "' found." << endl;
                } else {
                    cout << "User '" << user << "' not found." << endl;
                }
                break;
            }
            case 'd':
                passServer.dump();
                break;
            case 's':
                cout << "Current size: " << passServer.size() << endl;
                break;
            case 'w': {
                string filename;
                cout << "Enter filename: ";
                cin >> filename;
                if (!passServer.write_to_file(filename.c_str())) {
                    cout << "Write to file failed." << endl;
                } else {
                    cout << "Write successful." << endl;
                }
                break;
            }
            case 'x':
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid option." << endl;
        }
    } while (choice != 'x');

    return 0;
}

void Menu() {
    cout << "\n\n";
    cout << "l - Load From File" << endl;
    cout << "a - Add User" << endl;
    cout << "r - Remove User" << endl;
    cout << "c - Change User Password" << endl;
    cout << "f - Find User" << endl;
    cout << "d - Dump HashTable" << endl;
    cout << "s - HashTable Size" << endl;
    cout << "w - Write to Password File" << endl;
    cout << "x - Exit program" << endl;
    cout << "\nEnter choice : ";
}
