#include "ui.h"
#include "data_processor.h"
#include "logger.h"
#include <iostream>
#include <string>

void run_ui(const std::string& path) {
    std::cout << "=== Программа анализа текстовых строк ===" << std::endl;
    std::cout << "Используемый файл/путь: " << path << std::endl;
    std::cout << "Введите строку для анализа (или пустую строку для выхода):" << std::endl;

    while (true) {
        std::cout << "\n> ";
        std::string line;
        std::getline(std::cin, line);

        if (line.empty()) {
            log_message(LogLevel::INFO, "Получена пустая строка. Завершение работы.");
            break;
        }

        log_message(LogLevel::INFO, "Анализ строки: \"" + line + "\"");

        ProcessResult result = process_line(line);

        std::cout << "Результат анализа:" << std::endl;
        std::cout << "  Количество слов: " << result.word_count << std::endl;
        std::cout << "  Всего символов:  " << result.char_count << std::endl;
        std::cout << "  Самое длинное слово: \"" << result.longest_word << "\"" << std::endl;

        log_message(LogLevel::INFO, "Строка успешно обработана.");
    }

    std::cout << "Программа завершена. До свидания!" << std::endl;
}

void run_ui() {
    run_ui("");
}