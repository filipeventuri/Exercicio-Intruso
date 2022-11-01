#ifndef INTRUSO_HPP
#define INTRUSO_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>

class Intruso{

    private:
      std::map<char,std::string> digitos;
	  std::vector<std::map<char, std::string> > tudo;
	  std::vector<std::string> senhas;
	  std::vector<char> result;
    public:
      Intruso()=default;
      void set_senha_vazada(std::string vazou);
      std::string crack_senha();
};

#endif