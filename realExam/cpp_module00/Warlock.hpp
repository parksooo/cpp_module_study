#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <string>

class Warlock {
    private :
            std::string _name;
            std::string _title;

            Warlock();
            Warlock(const Warlock &w);
            Warlock&    operator=(const Warlock &w);

    public  :
            Warlock(const std::string& _name, const std::string& _title);
            ~Warlock();

            const std::string&  getName() const;
            const std::string&  getTitle() const;
            void    setTitle(const std::string& title);
            void    introduce() const;
};
#endif