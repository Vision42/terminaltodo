//
// Created by philipp on 25.05.25.
//

#include <gtest/gtest.h>
#include "Services/Formatter.h"

TEST(FormatterTest, FormatsLessThanOneMinute) {
    using namespace std::chrono;
    EXPECT_EQ(Formatter::formatMicroseconds(seconds(5)), "00:05");
    EXPECT_EQ(Formatter::formatMicroseconds(seconds(59)), "00:59");
}

TEST(FormatterTest, FormatsExactMinutes) {
    using namespace std::chrono;
    EXPECT_EQ(Formatter::formatMicroseconds(minutes(1)), "01:00");
    EXPECT_EQ(Formatter::formatMicroseconds(minutes(10)), "10:00");
}

TEST(FormatterTest, FormatsMixedMinutesAndSeconds) {
    using namespace std::chrono;
    EXPECT_EQ(Formatter::formatMicroseconds(minutes(2) + seconds(30)), "02:30");
    EXPECT_EQ(Formatter::formatMicroseconds(minutes(12) + seconds(5)), "12:05");
}

TEST(FormatterTest, FormatsZero) {
    using namespace std::chrono;
    EXPECT_EQ(Formatter::formatMicroseconds(microseconds(0)), "00:00");
}
