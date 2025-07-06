#pragma once
#include "../../application/dto/ExpenseDTO.hpp"
#include <vector>

class IExpensePresenter {
public:
  virtual ~IExpensePresenter() = default;
  virtual void present(const std::vector<ExpenseDTO>& expenses) = 0;
};
