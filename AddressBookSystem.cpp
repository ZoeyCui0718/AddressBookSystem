#include <iostream>
using namespace std;

constexpr auto MAX_CONTACTS = 1000;;

struct Contact {

    string c_name;
    string c_gender;
    int c_age;
    string c_number;
    string c_address;

};

struct Addressbook {

    Contact contactArray[MAX_CONTACTS];
    int b_size;

};

void addPerson(Addressbook* book) {

    if ((*book).b_size == MAX_CONTACTS) {
        cout << "The number of contacts has already reached the maximum." << endl;
        return;
    }
    else {
        // The contact's name
        string name;
        cout << "Name:" << endl;
        cin >> name;
        (*book).contactArray[(*book).b_size].c_name = name;

        // The contact's gender
        string gender;
        cout << "Gender:" << endl;
        cin >> gender;
        (*book).contactArray[(*book).b_size].c_gender = gender;

        // The contact's age
        int age = 0;
        cout << "Age:" << endl;
        cin >> age;
        (*book).contactArray[(*book).b_size].c_age = age;

        // The contact's phone number
        string num;
        cout << "Phone number:" << endl;
        cin >> num;
        (*book).contactArray[(*book).b_size].c_number = num;

        // The contact's address
        string address;
        cout << "Address:" << endl;
        cin >> address;
        (*book).contactArray[(*book).b_size].c_number = address;

        // resize the address book
        (*book).b_size++;

        cout << "Successfully added" << endl;
        system("pause");
        system("cls"); // clear the system and show the menu again
    }

}

void showContacts(Addressbook* book) {

    if ((*book).b_size == 0) {
        cout << "There is no contact" << endl;
    }
    else {

        for (int i = 0; i < (*book).b_size; i++) {
            cout << "Name: " << (*book).contactArray[i].c_name << "\t";
            cout << "Gender: " << (*book).contactArray[i].c_gender << "\t";
            cout << "Age: " << (*book).contactArray[i].c_age << "\t";
            cout << "Phone number : " << (*book).contactArray[i].c_number << "\t";
            cout << "Address : " << (*book).contactArray[i].c_address << endl;
        }

    }

    system("pause");
    system("cls");

}

// To check where the contact is
int c_exists(Addressbook* book, string name) {

    for (int i = 0; i < (*book).b_size; i++) {

        if ((*book).contactArray[i].c_name == name) {
            return i;
        }

    }

    return -1;
}

void deleteContact(Addressbook* book) {

    cout << "The contact's name: " << endl;
    string name;
    cin >> name;

    int c_position = c_exists(book, name);

    if (c_position != -1) {

        for (int i = c_position; i < (*book).b_size; i++) {
            (*book).contactArray[i] = (*book).contactArray[i + 1];
        }

        (*book).b_size--;
        cout << "Successfully deleted" << endl;

    }
    else {
        cout << "Unable to find this contact" << endl;
    }

    system("pause");
    system("cls");

}

void searchContact(Addressbook* book) {

    cout << "Contact's name:" << endl;
    string name;
    cin >> name;

    int c_position = c_exists(book, name);

    if (c_position != -1) {

        cout << "Name: " << (*book).contactArray[c_position].c_name << "\t";
        cout << "Gender: " << (*book).contactArray[c_position].c_gender << "\t";
        cout << "Age: " << (*book).contactArray[c_position].c_age << "\t";
        cout << "Phone number : " << (*book).contactArray[c_position].c_number << "\t";
        cout << "Address : " << (*book).contactArray[c_position].c_address << endl;
    }
    else {
        cout << "Unable to find this contact" << endl;
    }

    system("pause");
    system("cls");

}

void editContact(Addressbook* book) {

    cout << "Contact's name:" << endl;
    string name;
    cin >> name;

    int c_position = c_exists(book, name);

    if (c_position != -1) {

        // The contact's name
        string name;
        cout << "Name:" << endl;
        cin >> name;
        (*book).contactArray[c_position].c_name = name;

        // The contact's gender
        string gender;
        cout << "Gender:" << endl;
        cin >> gender;
        (*book).contactArray[c_position].c_gender = gender;

        // The contact's age
        int age = 0;
        cout << "Age:" << endl;
        cin >> age;
        (*book).contactArray[c_position].c_age = age;

        // The contact's phone number
        string num;
        cout << "Phone number:" << endl;
        cin >> num;
        (*book).contactArray[c_position].c_number = num;

        // The contact's address
        string address;
        cout << "Address:" << endl;
        cin >> address;
        (*book).contactArray[c_position].c_number = address;

        cout << "Successfully edited" << endl;

    }
    else {
        cout << "Unable to find this contact" << endl;
    }

    system("pause");
    system("cls");

}

void clearBook(Addressbook* book) {
    (*book).b_size = 0;

    cout << "Successfully cleared" << endl;

    system("pause");
    system("cls");
}

void showMenu() {

    cout << "1. add new contact" << endl;
    cout << "2. show all contacts" << endl;
    cout << "3. delete the contact" << endl;
    cout << "4. search the contact" << endl;
    cout << "5. edit the contact" << endl;
    cout << "6. clear the address book" << endl;
    cout << "0. quit the system" << endl;

}


int main() {

    Addressbook book;

    book.b_size = 0;

    int select = 0;

    while (true) {

        showMenu();

        cin >> select;

        switch (select) {
        case 1: // add new contact
            addPerson(&book);
            break;
        case 2: // show all contacts
            showContacts(&book);
            break;
        case 3: // delete the contact 
        {
            deleteContact(&book);
            break;
        }
        case 4: // search the contact
            searchContact(&book);
            break;
        case 5: // edit the contact
            editContact(&book);
            break;
        case 6: // clear the address book
            clearBook(&book);
            break;
        case 0: // quit the system
            system("pause");
            return 0;
            break;
        default:
            break;
        }

    }

}