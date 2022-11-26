#include "../include/Medicine.hpp"

Medicine::Medicine(const string& name, const string company, const double& price,
                   const Date& manufact, const Date& expiry)
    : m_name{name}, m_company{company}, m_price{price}, m_manufact{manufact}, m_expiry{expiry} {}

void Medicine::load() {}

void Medicine::save() {}

bool Medicine::search() {}