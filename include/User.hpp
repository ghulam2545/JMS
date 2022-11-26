#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User {
   public:
    vector<User> m_users;
    enum role { r_adming, r_customer };

    User() = default;
    User(role r, const string& name, const string& user, const string& pass);

    // void load();
    // void save();

    bool login(const string& username, const string& password);
    bool exist(const string& username);
    role user_role(const string& username);
    bool edit_profile();
    bool update_password();

   private:
    int m_unique_id;
    role m_role;
    string m_name;
    string m_username;
    string m_password;
};

#endif