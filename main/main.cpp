#include "playground.hpp"
#include "spdlog/spdlog.h"

int main(int argc, char* argv[]) {
    spdlog::set_level(spdlog::level::debug);
    spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");

    spdlog::info("Hello, cpp learning notes.");
}