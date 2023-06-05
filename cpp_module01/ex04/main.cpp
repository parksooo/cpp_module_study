/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:19:59 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/05 18:20:00 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    std::string outfile;
    std::string contexts;
    std::ifstream ifs;
    std::ofstream ofs;
    std::string s1;
    std::string s2;
    int s1_len;
    int s2_len;

    if (ac != 4)
    {
        std::cout << "Error of arguments" << std::endl;
        return 1;
    }
    s1 = av[2];
    s2 = av[3];
    s1_len = s1.length();
    s2_len = s2.length();
    if (!std::strlen(av[1]) || !s1_len || !s2_len)
    {
        std::cout << "Invalid Info" << std::endl;
        return 1;
    }
    ifs.open(av[1]);
    if (ifs.fail())
    {
        std::cout << "Fail to open " << av[1] << " check file path" << std::endl;
        return 1;
    }
    outfile = av[1];
    outfile.append(".replace");
    ofs.open(outfile);
    if (ofs.fail())
    {
        std::cout << "Fail to open." << std::endl;
        return 1;
    }
    while(1)
    {
        std::getline(ifs, contexts);
        size_t pos = 0;
        while(1)
        {
            pos = contexts.find(s1, pos);
            if (pos == std::string::npos)
                break ;
            contexts.erase(pos, s1_len);
            contexts.insert(pos, s2);
            pos += s2_len;
        }
        ofs << contexts;
        if (ifs.eof())
            break ;
        ofs << std::endl;
    }
    return 0;
}