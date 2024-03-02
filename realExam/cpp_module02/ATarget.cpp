#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(const std::string& _type) : _type(_type) {}

ATarget::ATarget(const ATarget &at)
{
    *this = at;
}

ATarget&    ATarget::operator=(const ATarget &at)
{
    if (this != &at) {
        this->_type = at.getType();
    }

    return *this;
}

ATarget::~ATarget() {}

const std::string&  ATarget::getType() const
{
    return this->_type;
}

void    ATarget::getHitBySpell(const ASpell &as) const
{
    std::cout << this->_type << " has been " << as.getEffects() << "!" << std::endl;
}