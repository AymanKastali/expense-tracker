#pragma once
#include "../interfaces/IExpensePresenter.hpp"
#include <ctime>
#include <iostream>

class ConsoleExpensePresenter : public IExpensePresenter {
public:
  void present(const std::vector<ExpenseDTO>& expenses) override {
    if (expenses.empty()) {
      std::cout << "No expenses found.\n";
      return;
    }

    for (const auto& e : expenses) {
      std::time_t t = std::chrono::system_clock::to_time_t(e.date);

      std::cout << "- " << e.amount << ", " << e.category << ", "
                << e.description << ", " << std::ctime(&t);
    }
  }

  ~ConsoleExpensePresenter() override = default;
};
