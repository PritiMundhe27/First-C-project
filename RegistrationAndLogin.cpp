#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//Objective: To create registration and login form.
class data {
    string userName, email, password;
    string searchName, searchPass, searchEmail;
    fstream file;
public:
    void login();
    void signUp();
    void forgotPassword();
};

int main() {
    data obj;
    char choice;
    cout << "\n1-Login";
    cout << "\n2- Sign-Up";
    cout << "\n3- Forgot password";
    cout << "\n4- Exit";
    cout << "\n Enter your choice: ";
    cin >> choice;
    cin.ignore(); // To consume the newline character left in the input buffer
    switch (choice) {
    case '1':
        obj.login();
        break;
    case '2':
        obj.signUp();
        break;
    case '3':
        obj.forgotPassword();
        break;
    case '4':
        return 0;
    default:
        cout << "invalid selection";
    }
    return 0;
}

void data::signUp() {
    cout << "\n Enter your username: ";
    getline(cin, userName);
    cout << "\n Enter your email: ";
    getline(cin, email);
    cout << "\n Enter your password: ";
    getline(cin, password);
    file.open("loginData.txt", ios::out | ios::app);
    file << userName << "*" << email << "*" << password << endl;
    file.close();
}

void data::login() {
    cout << "---LOGIN---" << endl;
    cout << "Enter your user name: ";
    getline(cin, searchName);
    cout << "Enter your password: ";
    getline(cin, searchPass);
    file.open("loginData.txt", ios::in);
    while (!file.eof()) {
        getline(file, userName, '*');
        getline(file, email, '*');
        getline(file, password);
        if (userName == searchName && password == searchPass) {
            cout << "\n Account login successful...!!";
            cout << "\n Username: " << userName << endl;
            cout << "\n Email: " << email << endl;
            file.close();
            return;
        }
    }
    cout << "Username or password is incorrect...!";
    file.close();
}

void data::forgotPassword() {
    cout << "\n Enter your userName:";
    getline(cin, searchName);
    cout << "\n Enter your email: ";
    getline(cin, searchEmail);
    file.open("loginData.txt", ios::in);
    while (!file.eof()) {
        getline(file, userName, '*');
        getline(file, email, '*');
        getline(file, password);
        if (userName == searchName && email == searchEmail) {
            cout << "\n Account found..!!";
            cout << "\n Your password: " << password << endl;
            file.close();
            return;
        }
    }
    cout << "Account not found..!!" << endl;
    file.close();
}
