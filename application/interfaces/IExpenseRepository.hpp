#pragma once
#include "../dto/ExpenseDTO.hpp"
#include <vector>

class IExpenseRepository {
public:
  virtual ~IExpenseRepository() = default;
  virtual void add(const ExpenseDTO& dto) = 0;
  virtual std::vector<ExpenseDTO> getAll() = 0;
};
