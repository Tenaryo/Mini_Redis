#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>

class PubSubManager {
    std::unordered_map<int, std::unordered_set<std::string>> subscriptions_;
  public:
    size_t subscribe(int fd, std::string channel) {
        subscriptions_[fd].insert(std::move(channel));
        return subscriptions_[fd].size();
    }

    void unsubscribe(int fd) { subscriptions_.erase(fd); }
};
