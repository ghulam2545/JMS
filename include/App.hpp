#ifndef APP_HPP
#define APP_HPP

#include <conio.h>

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <thread>

#include "../include/User.hpp"
using namespace std;

class App : public User {
   public:
    void header();
    void proceed();
    void run();

    void main_menu();
    void admin_menu();
    void customer_menu();

    void ask_login();
    void ask_registration();

    void f();

    void call();

   private:
    string m_choice;
};

#endif