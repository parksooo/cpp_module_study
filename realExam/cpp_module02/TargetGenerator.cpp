#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {}

TargetGenerator::TargetGenerator(const TargetGenerator &tg)
{
    *this = tg;
}

TargetGenerator&    TargetGenerator::operator=(const TargetGenerator &tg)
{
    (void)tg;

    return *this;
}

void    TargetGenerator::learnTargetType(ATarget *at)
{
    TargetGenerator::Iter it = this->_targets.find(at->getType());

    if (it == this->_targets.end()) {
        this->_targets.insert(TargetGenerator::Pair(at->getType(), at));
    }
}

void    TargetGenerator::forgetTargetType(const std::string &target)
{
    TargetGenerator::Iter it = this->_targets.find(target);

    if (it != this->_targets.end()) {
        delete it->second;
        this->_targets.erase(target);
    }
}

ATarget*    TargetGenerator::createTarget(const std::string &target)
{
    TargetGenerator::Iter it = this->_targets.find(target);

    if (it != this->_targets.end()) {
        return it->second->clone();
    }
    return NULL;
}