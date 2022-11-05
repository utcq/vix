#include <string>
#include <vector>
#include <stdio.h>
#include <iterator>
#include <utility>


#define vxinclude (file)

#ifndef STDH_H_
#define STDH_H_


template <typename T> T invert(T number);
void splittovec(std::string str, std::string splitby, std::vector<std::string>& tokens);
std::vector<std::string> split(std::string stra, std::string splitbya);
void outvec_int(std::vector <int> const &a);
void outvec_str(std::vector <std::string> const &a);
void outvec_char(std::vector <char> const &a);
void outvec_bool(std::vector <bool> const &a);
#endif 

