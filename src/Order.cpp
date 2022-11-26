#include "../include/Order.hpp"

Item::Item(const string& name, const double& price, const int& quant)
    : m_item_name{name}, m_price{price}, m_quantity{quant} {}

double Item::total_cost() { return m_quantity * m_price; }

Order::Order(const int& user_id, const Date& date) : m_user_id{user_id}, m_date{date} {}