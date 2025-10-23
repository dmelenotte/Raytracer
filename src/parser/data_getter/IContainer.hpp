#ifndef __ICONTAINER__
    #define __ICONTAINER__

#include "types/IType.hpp"

#include <vector>
#include <string>
#include <memory>

#include <nlohmann/json.hpp>

class IContainer {
    public:
        IContainer() = default;
        virtual ~IContainer() = default;
        virtual std::shared_ptr<IType> getValue() const = 0;
        virtual const std::vector<std::string> &getNeeds() const = 0;
        virtual void registerContainer(const std::string &containerName, std::shared_ptr<IContainer> newContainer) = 0;
        virtual void execContainer(const nlohmann::json &json) = 0;
        virtual void execContainer(nlohmann::json::const_iterator &jsonIterator) = 0;
};

#endif
