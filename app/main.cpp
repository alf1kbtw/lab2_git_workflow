#include "ui.h"
#include "logger.h"
#include <iostream>
#include <string>
#include <cstdlib>

void run_ui();

int main() {
  
    std::system("chcp 65001 > nul");

    log_init(); 

    std::string path;
    std::cout << "Введите путь к текстовому файлу: ";
    std::getline(std::cin, path);

    if (path.empty()) {
        log_message(LogLevel::ERROR, "Путь не указан");
        return 1;
    }

  
    run_ui(); 
    // Финал работы
    return 0;
}