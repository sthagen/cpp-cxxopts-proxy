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

        char help_request[] = "-h";
        char *argv[] = {help_request, NULL};
        int argc = sizeof(argv) / sizeof(char*) - 1;
        // auto result = options.parse(argc, argv);
        //    REQUIRE(result);
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

        char debug_request[] = "-d";
        char *argv[] = {debug_request, NULL};
        int argc = sizeof(argv) / sizeof(char*) - 1;
        // auto result = options.parse(argc, argv);
        //    REQUIRE(result);
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

        char file_request[] = "-f";
        char file_argument[] = "foo";
        char *argv[] = {file_request, file_argument, NULL};
        int argc = sizeof(argv) / sizeof(char*) - 1;
        // auto result = options.parse(argc, argv);
        // for (auto arg: result.arguments()) {
        //     REQUIRE(arg.key());
        //     check(arg.value() == "foo");
        // }
    }
}
