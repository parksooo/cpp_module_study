#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(std::string _name, std::string _effects) : _name(_name), _effects(_effects)
{ 
}

ASpell::ASpell(const ASpell &as)
{
    *this = as;
}

ASpell::~ASpell() {}

ASpell& ASpell::operator=(const ASpell &as)
{
    if (this != &as) {
        this->_name = as.getName();
        this->_effects = as.getEffects();
    }

    return *this;
}

const std::string&  ASpell::getName() const
{
    return this->_name;
}

const std::string&  ASpell::getEffects() const
{
    return this->_effects;
}

void    ASpell::launch(const ATarget &at) const
{
    at.getHitBySpell(*this);
}

