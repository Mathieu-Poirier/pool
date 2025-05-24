#include <chrono>
#include <ctime>
#pragma once

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

