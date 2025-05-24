#include "createdlibs/poollib.hpp"
#include <iostream>

int main(const int argc, const char* argv[], const char* envp[]) {

    const char**& command_line_args = argv;
    std::array<bool, ARG_FLAG_COUNT> flags = loop_and_match_arguments(command_line_args, argc);
    std::tm now = poll_local_time();

}
