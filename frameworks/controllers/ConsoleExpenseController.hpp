#pragma once
#include "../../application/dto/ExpenseDTO.hpp"
#include "../../application/usecases/AddExpenseUseCase.hpp"
#include "../../application/usecases/GetAllExpensesUseCase.hpp"

class ConsoleExpenseController {
public:
  ConsoleExpenseController(AddExpenseUseCase& addUseCase,
                           GetAllExpensesUseCase& getAllUseCase)
      : addUseCase(addUseCase), getAllUseCase(getAllUseCase) {}

  void addExpense(const ExpenseDTO& dto) { addUseCase.execute(dto); }

  std::vector<ExpenseDTO> getAllExpenses() { return getAllUseCase.execute(); }

private:
  AddExpenseUseCase& addUseCase;
  GetAllExpensesUseCase& getAllUseCase;
};
