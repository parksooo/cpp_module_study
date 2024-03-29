#ifndef ATARGET_HPP
# define ATARGET_HPP

class ASpell;

# include <iostream>
# include <string>
# include "ASpell.hpp"

class ATarget {
    private :
            std::string _type;

    public  :
            ATarget();
            ATarget(const std::string& _type);
            ATarget(const ATarget &at);
            virtual ~ATarget();

            ATarget&    operator=(const ATarget &at);
            const std::string& getType() const;
            virtual ATarget*    clone() const = 0;
            void getHitBySpell(const ASpell &as) const;
};
#endif