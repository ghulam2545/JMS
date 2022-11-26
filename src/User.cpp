#include "../include/User.hpp"

#include <iostream>
#include <string>

User::User(role r, const string& name, const string& user, const string& pass)
    : m_role{r}, m_name{name}, m_username{user}, m_password{pass} {}

// void User::load() {}

// void User::save() {}

bool User::login(const std::string& username, const std::string& password) {
    // for (auto& curr : m_users) {
    //     if (username == curr.m_username && password == curr.m_password) return true;
    // }
    // return false;
    return true;
}

bool User::exist(const string& username) {
    for (auto& curr : m_users) {
        if (username == curr.m_username) return true;
    }
    return false;
}

bool User::edit_profile() {
    cout << "\t\t\tPROFILE EDITING\n";
    cout << "\t\t--------------------------------------\n\n";
    string username, password, c_password;

    while (true) {
        cout << "\t\tGive New Username:   ";
        cin >> username;
        if (!exist(username)) break;

        cout << "user alredy exit\n";
    }

    while (true) {
        cout << "\n\t\tEnter New Password:    ";
        cin >> password;
        cout << "\t\tConfirm New Password:  ";
        cin >> c_password;

        if (password == c_password) break;
        cout << "inc";
    }

    cout << "eidt sucess\n";
    return true;
}

bool User::update_password() {
    cout << "\t\t\tPASSWORD UPDATE\n";
    cout << "\t\t--------------------------------------\n\n";
    string password, c_password;

    while (true) {
        cout << "\n\t\tEnter New Password:    ";
        cin >> password;
        cout << "\t\tConfirm New Password:  ";
        cin >> c_password;

        if (password == c_password) break;
        cout << "inc";
    }
}

User::role User::user_role(const string& username) {
    for (auto& curr : m_users) {
        if (username == curr.m_username) return curr.m_role;
    }
    return role::r_customer;
}