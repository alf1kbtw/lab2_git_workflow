#include "data_processor.h"
#include <sstream>
#include <algorithm>

ProcessResult process_line(const std::string& line) {
    ProcessResult result;
    result.word_count = 0;
    result.char_count = line.length();
    result.longest_word = "";

  
    std::stringstream ss(line);
    std::string word;

    while (ss >> word) {
        result.word_count++;
        

        if (word.length() > result.longest_word.length()) {
            result.longest_word = word;
        }
    }

    return result;
}