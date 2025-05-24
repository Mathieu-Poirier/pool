#include <chrono>
#include <ctime>
#include <iostream>
#include <array>
#include <cstring>
#pragma once

inline constexpr int MAX_ARGS = 10;

enum ArgFlags {
    DEBUG_FLAG,
    VERBOSE_FLAG,
    HELP_FLAG,
    ARG_FLAG_COUNT
};


/**
 * @brief Returns struct with tm_min, tm_hour, tm_mday, tm_wday, tm_year
 * 
 * @return std::tm 
 */
inline std::tm poll_local_time() {
    using clock = std::chrono::system_clock;
    std::chrono::time_point<std::chrono::system_clock> now = clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm local_tm = *std::localtime(&now_c);  
    return local_tm;
}

// TODO: Should actually return a tuple (flags, job)
inline std::array<bool, ARG_FLAG_COUNT> loop_and_match_arguments(const char** _command_line_args, int arg_count) {
    std::array<bool, ARG_FLAG_COUNT> flags = {false};

    // TODO: Edit for actual flags passed in
    for (int i = 0; i < arg_count and i < MAX_ARGS; ++i) {
        if (strcmp(_command_line_args[i], "--debug") == 0) {
            flags[DEBUG_FLAG] = true;
        } else if (strcmp(_command_line_args[i], "--verbose") == 0) {
            flags[VERBOSE_FLAG] = true;
        } else if (strcmp(_command_line_args[i], "--help") == 0) {
            flags[HELP_FLAG] = true;
        }
    }

    return flags;
}
