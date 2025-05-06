#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <string>
#include <fstream>

class Replace
{
    private :

        std::string s1;
        std::string s2;
        std::string oldFile;
    
    public :

        Replace(std::string s1, std::string s2, std::string oldFile);
        ~Replace();
        int process();

};

#endif
