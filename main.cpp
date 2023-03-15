#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Contact {
private:
    string name;
    string email;
    string phone;

public:
    Contact(string name, string email, string phone) {
        this->name = name;
        this->email = email;
        this->phone = phone;
    }

    string getName() {
        return this->name;
    }

    string getEmail() {
        return this->email;
    }

    string getPhone() {
        return this->phone;
    }

    void setName(string name) {
        this->name = name;
    }

    void setEmail(string email) {
        this->email = email;
    }

    void setPhone(string phone) {
        this->phone = phone;
    }
};

class AddressBook {
private:
    vector<Contact*> contacts;

public:
    void addContact(Contact* contact) {
        contacts.push_back(contact);
        cout << "Contact added." << endl;
    }

    void displayContacts() {
        if (contacts.empty()) {
            cout << "There are no contacts to display." << endl;
        } else {
            for (Contact* contact : contacts) {
                cout << "Name: " << contact->getName() << endl;
                cout << "Email: " << contact->getEmail() << endl;
                cout << "Phone: " << contact->getPhone() << endl;
                cout << endl;
            }
        }
    }

    void searchContacts(string searchTerm) {
        bool found = false;

        for (Contact* contact : contacts) {
            if (contact->getName().find(searchTerm) != string::npos) {
                cout << "Name: " << contact->getName() << endl;
                cout << "Email: " << contact->getEmail() << endl;
                cout << "Phone: " << contact->getPhone() << endl;
                cout << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "No contacts found for search term: " << searchTerm << endl;
        }
    }

    void deleteContact(string name) {
        for (vector<Contact*>::iterator it = contacts.begin(); it != contacts.end(); ++it) {
            if ((*it)->getName() == name) {
                contacts.erase(it);
                cout << "Contact deleted." << endl;
                return;
            }
        }

        cout << "No contact found with name: " << name << endl;
    }
};

int main() {
    AddressBook addressBook;

    int choice;
    string name;
    string email;
    string phone;
    string searchTerm;

    do {
        cout << "Address Book" << endl;
        cout << "------------" << endl;
        cout << "1. Add contact" << endl;
        cout << "2. Display contacts" << endl;
        cout << "3. Search contacts" << endl;
        cout << "4. Delete contact" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter email: ";
                cin >> email;
                cout << "Enter phone: ";
                cin >> phone;
                addressBook.addContact(new Contact(name, email, phone));
                break;
            case 2:
                addressBook.displayContacts();
                break;
            case 3:
                cout << "Enter search term: ";
                cin >> searchTerm;
                addressBook.searchContacts(searchTerm);
                break;
            case 4:
                cout << "Enter name of contact to delete: ";
                cin >> name;
                addressBook.deleteContact(name);
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    } while (choice != 5);

    return 0;
}