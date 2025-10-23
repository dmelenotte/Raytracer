#ifndef __ACONTAINER__
    #define __ACONTAINER__

#include "IContainer.hpp"

class AContainer : public IContainer {
    public:
        AContainer(std::shared_ptr<IType> type, const std::vector<std::string> needs);
        ~AContainer() = default;
        std::shared_ptr<IType> getValue() const;
        const std::vector<std::string> &getNeeds() const;
        void registerContainer(const std::string &containerName, std::shared_ptr<IContainer> newContainer);
        void execContainer(const nlohmann::json &json);
        void execContainer(nlohmann::json::const_iterator &jsonIterator);
    protected:
        std::shared_ptr<IType> _value;
        std::vector<std::string> _needs;
        std::map<std::string, std::shared_ptr<IContainer>> _subContainers;
};

#endif
