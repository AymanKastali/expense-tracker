#pragma once
#include "../../domain/entities/ExpenseEntity.hpp"
#include "../dto/ExpenseDTO.hpp"

class ExpenseMapper {
public:
  ExpenseMapper() = default;
  ~ExpenseMapper() = default;

  static ExpenseEntity toEntity(const ExpenseDTO& dto) {
    return ExpenseEntity(dto.amount, dto.category, dto.description, dto.date);
  }

  static ExpenseDTO toDTO(const ExpenseEntity& entity) {
    return ExpenseDTO(entity.getAmount(), entity.getCategory(),
                      entity.getDescription(), entity.getDate());
  }
};
