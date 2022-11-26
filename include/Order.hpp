#ifndef ORDER_HPP
#define ORDER_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Date {};

class Item {
   public:
    Item() = default;
    Item(const string& name, const double& price, const int& quant);

    double total_cost();

   private:
    string m_item_name;
    double m_price;
    int m_quantity;
};

class Order : public Item {
   public:
    Order(const int& user_id, const Date& date);

   private:
    int m_user_id;
    Date m_date;
};

#endif