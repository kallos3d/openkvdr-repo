#ifndef KVD_CLI_H
#define KVD_CLI_H

#include "kvd_core.h"
#include <string>
#include <unordered_map>
#include <functional>

class KVDCli {
public:
    KVDCli();
    void start();
private:
    KVDCore renderer;
    std::unordered_map<std::string, std::function<void(const std::string&)>> commands;
    void processCommand(const std::string& input);
};

#endif // KVD_CLI_H
