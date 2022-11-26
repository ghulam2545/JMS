#ifndef MEDICINE_HPP
#define MEDICINE_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Date {};

class Medicine {
   public:
    vector<Medicine> m_medcines;

   private:
    Medicine() = default;
    Medicine(const string& name, const string company, const double& price, const Date& manufact,
             const Date& expiry);

    void load();
    void save();

    bool search();

   public:
    string m_name;
    string m_company;
    double m_price;
    Date m_manufact;
    Date m_expiry;
};

#endif