/**
 * @file test.cpp
 * @date 27 Feb 2022
 * @author Yury Loshmanov
 */
#include <iostream>
#include <gtest/gtest.h>

#include "../include/ConfigParser.hpp"


TEST(ConfigParser, PostgresqlURL) {
    system(
            "echo '{\n"
            "  \"PostgresqlURL\": \"jdbc:postgresql://localhost:5432/postgres\"\n"
            "}' > .config_parser_postgreqlurl"
    );

    ConfigParser configParser(".config_parser_postgreqlurl");
    auto url = configParser.getPostgresqlURL();

    system("rm -rf .config_parser_postgreqlurl");

    ASSERT_EQ(url, "jdbc:postgresql://localhost:5432/postgres");
}
