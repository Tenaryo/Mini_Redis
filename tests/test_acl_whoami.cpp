#include "../src/handler/command_handler.hpp"
#include "../src/protocol/resp_parser.hpp"
#include "../src/server/server_config.hpp"
#include "../src/store/store.hpp"
#include <cassert>
#include <iostream>
#include <string>

void test_acl_whoami_returns_default() {
    Store store;
    ServerConfig config;
    CommandHandler handler(store, config);

    std::string input = "*2\r\n$3\r\nACL\r\n$6\r\nWHOAMI\r\n";
    auto response = handler.process(input);

    assert(response == "$7\r\ndefault\r\n");

    std::cout << "\u2713 Test passed: ACL WHOAMI returns 'default' as bulk string\n";
}

int main() {
    std::cout << "Running ACL WHOAMI tests...\n\n";

    test_acl_whoami_returns_default();

    std::cout << "\n\u2713 All tests passed!\n";
    return 0;
}
