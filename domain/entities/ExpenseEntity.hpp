#pragma once
#include <chrono>
#include <stdexcept>
#include <string>

class ExpenseEntity {
public:
  ~ExpenseEntity() = default;

  ExpenseEntity(double amount, const std::string& category,
                const std::string& description,
                std::chrono::system_clock::time_point date)
      : amount(amount), category(category), description(description),
        date(date) {

    if (amount <= 0.0) {
      throw std::invalid_argument(ERROR_AMOUNT_ZERO_OR_NEGATIVE);
    }

    if (category.empty()) {
      throw std::invalid_argument(ERROR_CATEGORY_EMPTY);
    }

    if (description.empty()) {
      throw std::invalid_argument(ERROR_DESCRIPTION_EMPTY);
    }

    if (description.size() > 200) {
      throw std::invalid_argument(ERROR_DESCRIPTION_TOO_LONG);
    }

    auto now = std::chrono::system_clock::now();
    if (date > now) {
      throw std::invalid_argument(ERROR_DATE_IN_FUTURE);
    }
  }

  double getAmount() const { return amount; }
  std::string getCategory() const { return category; }
  std::string getDescription() const { return description; }
  std::chrono::system_clock::time_point getDate() const { return date; }

private:
  double amount;
  std::string category;
  std::string description;
  std::chrono::system_clock::time_point date;

  static constexpr const char* ERROR_AMOUNT_ZERO_OR_NEGATIVE =
      "Amount must be greater than zero.";
  static constexpr const char* ERROR_CATEGORY_EMPTY =
      "Category must not be empty.";
  static constexpr const char* ERROR_DESCRIPTION_EMPTY =
      "Description must not be empty.";
  static constexpr const char* ERROR_DESCRIPTION_TOO_LONG =
      "Description must not exceed 200 characters.";
  static constexpr const char* ERROR_DATE_IN_FUTURE =
      "Date cannot be in the future.";
};
