#pragma once

#include <optional>
#include <string>
#include <vector>

class Connection {
    int fd_{-1};
    std::vector<char> buffer_;
    ssize_t bytes_read_{0};
  public:
    explicit Connection(int fd);
    ~Connection();

    Connection(const Connection&) = delete;
    Connection& operator=(const Connection&) = delete;
    Connection(Connection&&) noexcept;
    Connection& operator=(Connection&&) noexcept;

    [[nodiscard]] int fd() const noexcept { return fd_; }
    void close();
    std::optional<std::string_view> handle_read();
    void send_data(const char* data, size_t len);

    static constexpr size_t BUFFER_SIZE = 4096;
};
