#include "../../application/interfaces/IExpenseRepository.hpp"
#include <vector>

class InMemoryExpenseRepository : public IExpenseRepository {
public:
  void add(const ExpenseDTO& dto) override { expenses.push_back(dto); }

  std::vector<ExpenseDTO> getAll() override { return expenses; }

private:
  std::vector<ExpenseDTO> expenses;
};
