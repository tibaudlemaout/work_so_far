/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** NoTest
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../ai/ParsingArgs.hpp"
#include "../ai/Encryption.hpp"

Test(parse_args, valid_args) {
    char *av[] = {"./zappy_ai", "-p", "8080", "-n", "MyApp", "-h", "MyMachine"};
    AI::Config config = parse_args(7, av);
    cr_assert_eq(config.port, 8080);
    cr_assert_str_eq(config.name.c_str(), "MyApp");
    cr_assert_str_eq(config.machine_name.c_str(), "MyMachine");
}

Test(parse_args, invalid_args) {
    char *av[] = {"./zappy_ai", "-x", "8080"};
    cr_expect_throw(parse_args(3, av), std::invalid_argument);
}

Test(verify_config, valid_config) {
    AI::Config config;
    config.port = 8080;
    config.name = "MyApp";
    config.machine_name = "MyMachine";
    verify_config(config);  // Should not throw
}

Test(verify_config, invalid_config) {
    AI::Config config;
    config.port = -1;
    config.name = "";
    config.machine_name = "";
    cr_expect_throw(verify_config(config), std::invalid_argument);
}

Test(encrypt_decrypt_tests, test_encrypt) {
    std::string input = "abc";
    std::string expected_output = "bcd";
    cr_assert_eq(AI::encrypt(input), expected_output, "La fonction encrypt ne fonctionne pas correctement");
}

Test(encrypt_decrypt_tests, test_decrypt) {
    std::string input = "bcd";
    std::string expected_output = "abc";
    cr_assert_eq(AI::decrypt(input), expected_output, "La fonction decrypt ne fonctionne pas correctement");
}

Test(encrypt_decrypt_tests, test_encrypt_decrypt) {
    std::string input = "abc";
    std::string encrypted = AI::encrypt(input);
    std::string decrypted = AI::decrypt(encrypted);
    cr_assert_eq(decrypted, input, "La combinaison des fonctions encrypt et decrypt ne donne pas la chaîne originale");
}