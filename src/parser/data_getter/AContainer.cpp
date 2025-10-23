#include "AContainer.hpp"

AContainer::AContainer(std::shared_ptr<IType> type, const std::vector<std::string> needs) :
    _value(type), _needs(needs) {}

std::shared_ptr<IType> AContainer::getValue() const
{
    return _value;
}

const std::vector<std::string> &AContainer::getNeeds() const
{
    return _needs;
}

void AContainer::registerContainer(const std::string &containerName, std::shared_ptr<IContainer> newContainer)
{
    if (newContainer.get() == nullptr) {
        return;
    }
    _subContainers.insert(std::pair<std::string, std::shared_ptr<IContainer>>(containerName, newContainer));
}

void AContainer::execContainer(__attribute__((unused)) const nlohmann::json &json)
{

}

void AContainer::execContainer(__attribute__((unused)) nlohmann::json::const_iterator &jsonIterator)
{

}
