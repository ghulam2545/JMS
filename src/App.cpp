#include "../include/App.hpp"

void App::run() { call(); }

void App::header() {
    cout << "\n\t*.*.*.*.*.*.*  WELCOME TO JUST MEDICINE STORE  *.*.*.*.*.*.*\n\n";
    auto curr_time = time(nullptr);
    auto now = localtime(&curr_time);
    cout << "\t\t\t\t\t\t\t" << now->tm_mday << '-' << now->tm_mon + 1 << '-' << now->tm_year + 1900
         << "\n\n";
}

void App::proceed() {
    cout << "\n\n";
    cout << "\n\n\n\t\t\t\tHit Any key to proceed! ";
    getch();
}

void App::main_menu() {
    while (true) {
        system("cls");
        header();

        cout << "\t\t\tMAIN MENU\n";
        cout << "\t\t------------------------\n\n";
        cout << "\t\t1. Login\n";
        cout << "\t\t2. Register\n";
        cout << "\t\t3. Forget Password\n";
        cout << "\t\t4. Quit\n";

        cout << "\n\t\tChoose your option ?   ";
        cin >> m_choice;

        if (m_choice == "1" || m_choice == "a")
            ask_login();
        else if (m_choice == "2" || m_choice == "b")
            ask_registration();
        else if (m_choice == "3" || m_choice == "c") {
            cout << "lol\n";
        } else if (m_choice == "4" || m_choice == "d") {
            cout << "\n\n\t\tCLOSING 3 2 1";
            std::this_thread::sleep_for(std::chrono::seconds(3));
            exit(0);
        } else {
            cout << "Invalid choice.\n";
            proceed();
            continue;
        }
    }
}

void App::admin_menu() {
    while (true) {
        system("cls");
        header();
        cout << "\t\t\tADMIN MENU\n";
        cout << "\t\t--------------------------\n\n";
        cout << "\t\t1. Manage Medicine\n";
        cout << "\t\t2. Edit Profile\n";
        cout << "\t\t3. Change Password\n";
        cout << "\t\t4. Logout\n";

        cout << "\n\t\tChoose your option ?   ";
        cin >> m_choice;

        if (m_choice == "1" || m_choice == "a")
            main_menu();
        else if (m_choice == "2" || m_choice == "b")
            main_menu();
        else if (m_choice == "3" || m_choice == "c") {
            cout << "lol\n";
        } else if (m_choice == "4" || m_choice == "d")
            main_menu();
        else {
            cout << "Invalid choice.\n";
            proceed();
            continue;
        }
    }
}

void App::customer_menu() {
    while (true) {
        system("cls");
        header();

        cout << "\t\t\tCUSTOMER MENU\n";
        cout << "\t\t----------------------------\n\n";
        cout << "\t\t1. Buy Medicine\n";
        cout << "\t\t2. View Orders\n";
        cout << "\t\t3. Edit Profile\n";
        cout << "\t\t4. Change Password\n";
        cout << "\t\t5. Logout\n";

        cout << "\n\t\tChoose your option ?   ";
        cin >> m_choice;
        if (m_choice == "1" || m_choice == "a")
            main_menu();
        else if (m_choice == "2" || m_choice == "b")
            main_menu();
        else if (m_choice == "3" || m_choice == "c") {
            main_menu();
        } else if (m_choice == "4" || m_choice == "d") {
            main_menu();
        } else if (m_choice == "5" || m_choice == "e") {
            main_menu();
        } else {
            cout << "Invalid choice.\n";
            proceed();
            continue;
        }
    }
}

void App::ask_login() {
    system("cls");
    header();

    // allow maximum of 3 attemp
    for (int i = 0; i < 3; ++i) {
        cout << "\t\t\tLOGIN CREDENTIAL\n";
        cout << "\t\t----------------------------\n\n";
        string username, password;

        cout << "\t\tUsername:  ";
        cin.ignore();
        getline(cin, username);
        cout << "\t\tPassword:  ";
        cin.ignore();
        getline(cin, password);

        if (login(username, password)) {
            cout << "\n\t\tLogged in as \t"
                 << "\\___ " << username << " ___/.";
            proceed();

            if (user_role(username) == role::r_customer)
                customer_menu();
            else
                admin_menu();
        } else {
            cout << "Incorrect credentials.\n";
        }
    }
    cout << "Maximum allowed attemp exceeded. Returning back to Main Menu.\n";
    proceed();
    main_menu();
}

void App::ask_registration() {
    system("cls");
    header();

    cout << "\t\t\tREGISTRATION CREDENTIAL\n";
    cout << "\t\t--------------------------------------\n\n";
    string name, username, password, c_password;

    cout << "\t\tEnter Your Name:   ";
    cin.ignore();
    getline(cin, name);

    while (true) {
        cout << "\t\tGive a Username:   ";
        cin.ignore();
        getline(cin, username);
        if (!exist(username)) break;

        cout << "Username alredy exist.\n";
        proceed();
    }

    while (true) {
        cout << "\n\t\tEnter Password:    ";
        cin.ignore();
        getline(cin, password);
        cout << "\t\tConfirm Password:  ";
        cin.ignore();
        getline(cin, c_password);

        if (password == c_password) break;
        cout << "\n\n\t\tIncorrect confirm password.";
        proceed();
        system("cls");
        header();
        cout << "\t\t\tREGISTRATION CREDENTIAL\n";
        cout << "\t\t--------------------------------------\n\n";

        cout << "\t\tEnter Your Name:   ";
        cout << name << '\n';
        cout << "\t\tGive a Username:   ";
        cout << username << '\n';
    }

    m_users.push_back(User(role::r_customer, name, username, password));

    cout << "\n\n\t\t";
    cout << (char)toupper(name[0]);
    for (int i = 1; i < name.size(); ++i) {
        if (name[i] == ' ') break;
        cout << name[i];
    }
    cout << "! your registration successful. Thank You.\n";
    proceed();
}

void App::f() {}

void App::call() { admin_menu(); }