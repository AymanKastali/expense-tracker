#pragma once

#include "../../application/dto/ExpenseDTO.hpp"
#include "../controllers/ConsoleExpenseController.hpp"
#include "../interfaces/IExpensePresenter.hpp"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

constexpr const char* APP_TITLE = "Expense Tracker (Console)";
constexpr const char* PROMPT_COMMAND = "\nEnter command (add, getall, quit): ";
constexpr const char* PROMPT_AMOUNT = "Amount: ";
constexpr const char* PROMPT_CATEGORY = "Category: ";
constexpr const char* PROMPT_DESCRIPTION = "Description: ";
constexpr const char* PROMPT_DATE =
    "Date (YYYY-MM-DD, leave empty for today): ";
constexpr const char* MSG_EXPENSE_ADDED = "Expense added successfully.\n";
constexpr const char* MSG_INVALID_DATE = "Invalid date format.";
constexpr const char* MSG_UNKNOWN_COMMAND = "Unknown command.\n";
constexpr const char* MSG_GOODBYE = "Goodbye!\n";
constexpr const char* MSG_ERROR_PREFIX = "Error: ";

constexpr const char* ADD_COMMAND = "add";
constexpr const char* GET_ALL_COMMAND = "getall";
constexpr const char* QUIT_COMMAND = "quit";

class ConsoleApp {
public:
  ConsoleApp(ConsoleExpenseController& controller,
             std::shared_ptr<IExpensePresenter> presenter)
      : controller(controller), presenter(std::move(presenter)) {}

  void run() {
    std::string command;
    std::cout << APP_TITLE << '\n';

    while (true) {
      std::cout << PROMPT_COMMAND;
      std::getline(std::cin, command);

      if (command == QUIT_COMMAND) {
        break;
      } else if (command == ADD_COMMAND) {
        try {
          ExpenseDTO dto = collectExpenseInput();
          controller.addExpense(dto);
          std::cout << MSG_EXPENSE_ADDED;
        } catch (const std::exception& ex) {
          std::cerr << MSG_ERROR_PREFIX << ex.what() << '\n';
        }
      } else if (command == GET_ALL_COMMAND) {
        auto expenses = controller.getAllExpenses();
        presenter->present(expenses);
      } else {
        std::cout << MSG_UNKNOWN_COMMAND;
      }
    }

    std::cout << MSG_GOODBYE;
  }

private:
  ExpenseDTO collectExpenseInput() {
    std::string amountStr, category, description, dateStr;
    double amount;
    std::chrono::system_clock::time_point date;

    std::cout << PROMPT_AMOUNT;
    std::getline(std::cin, amountStr);
    amount = std::stod(amountStr);

    std::cout << PROMPT_CATEGORY;
    std::getline(std::cin, category);

    std::cout << PROMPT_DESCRIPTION;
    std::getline(std::cin, description);

    std::cout << PROMPT_DATE;
    std::getline(std::cin, dateStr);

    if (dateStr.empty()) {
      date = std::chrono::system_clock::now();
    } else {
      std::tm tm = {};
      std::istringstream ss(dateStr);
      ss >> std::get_time(&tm, "%Y-%m-%d");
      if (ss.fail()) {
        throw std::invalid_argument(MSG_INVALID_DATE);
      }
      date = std::chrono::system_clock::from_time_t(std::mktime(&tm));
    }

    return ExpenseDTO(amount, category, description, date);
  }

  ConsoleExpenseController& controller;
  std::shared_ptr<IExpensePresenter> presenter;
};
