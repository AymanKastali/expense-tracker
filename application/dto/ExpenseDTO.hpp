#pragma once
#include <chrono>
#include <string>

class ExpenseDTO {
public:
  ~ExpenseDTO() = default;

  double amount;
  std::string category;
  std::string description;
  std::chrono::system_clock::time_point date;

  ExpenseDTO(){};

  ExpenseDTO(double amount, const std::string& category,
             const std::string& description,
             std::chrono::system_clock::time_point date)
      : amount(amount), category(category), description(description),
        date(date) {}
};
