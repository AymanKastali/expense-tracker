#include "frameworks/console/ConsoleApp.hpp"
#include "frameworks/controllers/ConsoleExpenseController.hpp"
#include "frameworks/presentation/ConsoleExpensePresenter.hpp"
#include "infrastructure/repositories/InMemoryExpenseRepository.hpp"
#include <memory>

int main() {
  auto repository = std::make_shared<InMemoryExpenseRepository>();
  auto presenter = std::make_shared<ConsoleExpensePresenter>();

  AddExpenseUseCase addUseCase(repository);
  GetAllExpensesUseCase getAllUseCase(repository);

  ConsoleExpenseController controller(addUseCase, getAllUseCase);
  ConsoleApp app(controller, presenter);

  app.run();
}
