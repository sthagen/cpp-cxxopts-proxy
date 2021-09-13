#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <array>
#include <string>
#include <sstream>

#include <doctest/doctest.h>

#include <cxxopts.hpp>


TEST_SUITE ("Example derived tests.") {
    TEST_CASE ("First test case.") {
        /* Example snippet:
         *
         * cxxopts::Options options("App", "One line description of the commandline app");
         * options.add_options()
         *     ("h,help", "Show help")
         *     ("d,debug", "Enable debugging")
         *     ("f,file", "File name", cxxopts::value<std::string>());
         *
         * auto result = options.parse(argc, argv);
         */
        cxxopts::Options options("App", "One line description of the commandline app");
        options.add_options()
            ("h,help", "Show help")
            ("d,debug", "Enable debugging")
            ("f,file", "File name", cxxopts::value<std::string>());

        char helpRequest[] = "-h";    // make a non-const char array
        char *argv[] = { helpRequest, NULL };
        int argc = 1;
        auto result = options.parse(argc1, argv);
            REQUIRE(result);
    }

    TEST_CASE ("Second test case.") {
        /* Example snippet:
         *
         * cxxopts::Options options("App", "One line description of the commandline app");
         * options.add_options()
         *     ("h,help", "Show help")
         *     ("d,debug", "Enable debugging")
         *     ("f,file", "File name", cxxopts::value<std::string>());
         *
         * auto result = options.parse(argc, argv);
         *
         * if (result["help"].as<bool>()) {
         *     std::cout << options.help() << std::endl;
         *     return 0;
         * }
         */
        cxxopts::Options options("App", "One line description of the commandline app");
        options.add_options()
            ("h,help", "Show help")
            ("d,debug", "Enable debugging")
            ("f,file", "File name", cxxopts::value<std::string>());

        char debugRequest[] = "-d";    // make a non-const char array
        char *argv[] = { debugRequest, NULL };
        int argc = 1;
        auto result = options.parse(argc1, argv);
            REQUIRE(result);
    }

    TEST_CASE ("Third test case.") {
        /* Example snippet:
         *
         * cxxopts::Options options("App", "One line description of the commandline app");
         * options.add_options()
         *     ("h,help", "Show help")
         *     ("d,debug", "Enable debugging")
         *     ("f,file", "File name", cxxopts::value<std::string>());
         *
         * auto result = options.parse(argc, argv);
         *
         * for (auto arg: result.arguments()) {
         *     std::cout << "option: " << arg.key() << ": " << arg.value() << std::endl;
         * }
         */
        cxxopts::Options options("App", "One line description of the commandline app");
        options.add_options()
            ("h,help", "Show help")
            ("d,debug", "Enable debugging")
            ("f,file", "File name", cxxopts::value<std::string>());

        char fileRequest[] = "-f=foo";    // make a non-const char array
        char *argv[] = { fileRequest, NULL };
        int argc = 1;
        auto result = options.parse(argc1, argv);
        for (auto arg: result.arguments()) {
            REQUIRE(arg.key());
            check(arg.value() == "foo");
        }
    }
}
