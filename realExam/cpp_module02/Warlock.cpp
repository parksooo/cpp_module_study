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

Warlock::Warlock(const std::string& _name, const std::string& _title) : _name(_name), _title(_title), _book(new SpellBook())
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
    this->_book->learnSpell(as);
}

void    Warlock::forgetSpell(std::string spell)
{
    this->_book->forgetSpell(spell);
}

void    Warlock::launchSpell(std::string spell, const ATarget &at)
{

    ASpell* as = this->_book->createSpell(spell);

    if (as) {
        as->launch(at);

        delete as;
    }
}