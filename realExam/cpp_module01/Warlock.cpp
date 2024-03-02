#include "Warlock.hpp"

Warlock::Warlock() {}

Warlock::Warlock(const Warlock &w)
{
    *this = w;
}

Warlock&    Warlock::operator=(const Warlock &w)
{
    (void)w;

    return *this;
}

Warlock::Warlock(const std::string& _name, const std::string& _title) : _name(_name), _title(_title)
{
    std::cout << this->_name << ": " << "This looks like another boring day." << std::endl; 
}

Warlock::~Warlock()
{
    std::cout << this->_name << ": My job here is done!" << std::endl;
}

const std::string&  Warlock::getName() const
{
    return this->_name;
}

const std::string&  Warlock::getTitle() const
{
    return this->_title;
}

void    Warlock::setTitle(const std::string& title)
{
    this->_title = title;
}

void    Warlock::introduce() const
{
    std::cout << this->_name << ": " << "I am " << this->_name << ", " << this->_title << "!" << std::endl; 
}

void    Warlock::learnSpell(ASpell *as)
{
    Warlock::Iter   it = this->_inven.find(as->getName());

    if (it == this->_inven.end()) {
        this->_inven.insert(Warlock::Pair(as->getName(), as->clone()));        
    }
}

void    Warlock::forgetSpell(std::string spell)
{
    Warlock::Iter   it = this->_inven.find(spell);

    if (it != this->_inven.end()) {
        delete it->second;
        this->_inven.erase(spell);
    }
}

void    Warlock::launchSpell(std::string spell, const ATarget &at)
{
    Warlock::Iter   it = this->_inven.find(spell);

    if (it != this->_inven.end()) {
        at.getHitBySpell(*(it->second));
    }
}