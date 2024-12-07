#ifndef CONTACT_LIST
#define CONTACT_LIST
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

ofstream fout("contact.list", ios::app);
ifstream fin("contact.list");

struct Contact{
    string first_name;
    string last_name;
    string number;
    string email;
};

void initialize(vector<Contact>& contacts){
    Contact contact;
    while (fin >> contact.first_name >> contact.last_name >> contact.number >> contact.email)
        contacts.push_back(contact);
}

void save_contacts(const vector<Contact>& contacts) {
    fout.close();
    fout.open("contact.list", ios::trunc);
    for (const auto &contact: contacts) {
        fout << contact.first_name  << " " << contact.last_name << " " << contact.number << " " << contact.email << endl;
    }
}

void add_contact(vector<Contact> &contacts) {
    Contact contact;
    cout << "Enter new contact first name: ";
    cin >> contact.first_name;
    cout << "Enter new contact last name: ";
    cin >> contact.last_name;
    cout << "Enter new contact phone number: ";
    cin >> contact.number;
    cout << "Enter new contact email: ";
    cin >> contact.email;
    contacts.push_back(contact);
    save_contacts(contacts);
    cout << "\nContact successfully added!\n";
}

void show_contacts(const vector<Contact> &contacts) {
    bool Showed = false;
    for (const auto &contact: contacts) {
        cout << "\nContact first name: " << contact.first_name << endl;
        cout << "Contact last name: " << contact.last_name << endl;
        cout << "Contact phone number: " << contact.number << endl;
        cout << "Contact email: " << contact.email << "\n\n";
        Showed = true;
    }
    if (Showed) cout << "All contacts showed!\n";
    else cout << "You have no contacts yet!\n";
}

void SearchContact(const vector<Contact> &contacts, const string &first_name) {
    bool showed = false;
    int i = 0;
    for (const auto &contact: contacts)
        if (contact.first_name == first_name) {
            cout << "\nContact name: " << contact.first_name << endl;
            cout << "Contact last name: " << contact.last_name << endl;
            cout << "Contact phone number: " << contact.number << endl;
            cout << "Contact email: " << contact.email << "\n";
            showed = true;
            i++;
        }
    if (!showed) cout << "\nContact not found, try again!\n";
    if (i > 1) cout << "\n! You have " << i << " contacts with the same first name !\n";
    if (showed && i <= 1) cout << "\n";
}

#endif