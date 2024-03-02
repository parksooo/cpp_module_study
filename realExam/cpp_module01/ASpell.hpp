#ifndef ASPELL_HPP
# define ASPELL_HPP

class ATarget;

# include <iostream>
# include <string>
# include "ATarget.hpp"


class ASpell {
    private :
            std::string _name;
            std::string _effects;

    public  :
            ASpell();
            ASpell(std::string _name, std::string _effects);
            ASpell(const ASpell &as);
            virtual ~ASpell();

            ASpell& operator=(const ASpell &as);
            const std::string&  getName() const;
            const std::string&  getEffects() const;
            virtual ASpell* clone() const = 0;
            void    launch(const ATarget &at) const;
};          
#endif