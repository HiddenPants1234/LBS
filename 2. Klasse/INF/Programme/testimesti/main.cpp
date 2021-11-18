#include <iostream>       // std::cout
#include <string>         // std::string
#include <cstddef>        // std::size_t
int count(std::string s, char c)
{
    // Count variable
    int res = 0;

    for (int i=0;i<s.length();i++)

        // checking character in string
        if (s[i] == c)
            res++;

    return res;
}
int main ()
{
    std::string str ("32+56+95+89");
    count(str, '+');
    std::size_t found = str.find_first_of("0123456789");
    while (found!=std::string::npos)
    {
        str[found]=NULL;
        found=str.find_first_of("0123456789",found+1);
    }

    std::cout << str << "\n";

    return 0;
}