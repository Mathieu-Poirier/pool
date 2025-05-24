#include <gtest/gtest.h>
#include <createdlibs/poollib.hpp>
#include <ctime>
#include <chrono>

TEST(TimeTest, poll_local_time) {
    // Get system time
    std::time_t now = std::time(nullptr);

    // Convert now to local time (as tm)
    std::tm* system_tm = std::localtime(&now);

    // Poll your custom time function
    std::tm custom_tm = poll_local_time();

    // Compare selected fields
    EXPECT_EQ(custom_tm.tm_min, system_tm->tm_min);
    EXPECT_EQ(custom_tm.tm_hour, system_tm->tm_hour);
    EXPECT_EQ(custom_tm.tm_mday, system_tm->tm_mday);
    EXPECT_EQ(custom_tm.tm_mon, system_tm->tm_mon);
    EXPECT_EQ(custom_tm.tm_year, system_tm->tm_year);
}

// TEST(SampleTest, BasicAssertions) {
//     EXPECT_EQ(1, 1);
// }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
