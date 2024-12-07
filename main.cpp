#include <iostream>
#include "contact_list.h"
using namespace std;

    int main() {
        bool over = false;
        vector<Contact> contacts;
        initialize(contacts);
        int option;
        while (!over) {
            cout << "\n1. Add contact\n2. Show all contacts\n3. Search contact\n4. Leave\n\nOption: ";
            cin >> option;

            cout << endl;

            switch (option) {
                case 1:
                    add_contact(contacts);
                    break;
                case 2:
                    show_contacts(contacts);
                    break;
                case 3: {
                    string name;
                    cout << "Enter the first name of the contact you want to search: ";
                    cin >> name;
                    SearchContact(contacts, name);
                    break;
                }
                case 4:
                    over = true;
                    cout << "Have a nice day!\n";
                    break;
                default:
                    cout << "Option not available, please try again!\n";
            }
        }
    }
