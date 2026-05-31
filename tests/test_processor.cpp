#include <gtest/gtest.h>
#include "data_processor.h"

// Пример теста (студенты должны дописать свои тесты)
TEST(ProcessorTest, EmptyLine) {
    ProcessResult res = process_line("");
    EXPECT_EQ(res.word_count, 0);
    EXPECT_EQ(res.char_count, 0);
    EXPECT_TRUE(res.longest_word.empty());
}

// TODO: добавить тесты для строк с одним словом,
// с несколькими словами, с ведущими/конечными пробелами и т.д.