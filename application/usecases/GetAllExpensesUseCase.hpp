#pragma once
#include "../dto/ExpenseDTO.hpp"
#include "../interfaces/IExpenseRepository.hpp"
#include <memory>
#include <vector>

class GetAllExpensesUseCase {
public:
  explicit GetAllExpensesUseCase(std::shared_ptr<IExpenseRepository> repository)
      : repository(std::move(repository)) {}

  std::vector<ExpenseDTO> execute() { return repository->getAll(); }

private:
  std::shared_ptr<IExpenseRepository> repository;
};
