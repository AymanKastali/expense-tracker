#pragma once
#include "../../domain/entities/ExpenseEntity.hpp"
#include "../dto/ExpenseDTO.hpp"
#include "../interfaces/IExpenseRepository.hpp"
#include "../mappers/ExpenseMapper.hpp"
#include <memory>

class AddExpenseUseCase {
public:
  explicit AddExpenseUseCase(std::shared_ptr<IExpenseRepository> repository)
      : repository(std::move(repository)) {}

  void execute(const ExpenseDTO& dto) {
    ExpenseEntity entity = ExpenseMapper::toEntity(dto);

    repository->add(dto);
  }

private:
  std::shared_ptr<IExpenseRepository> repository;
};
