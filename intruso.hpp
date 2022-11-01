#ifndef INTRUSO_HPP
#define INTRUSO_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>

class Intruso{

    private:
      std::vector<std::map<char, std::string> > tudo;
	  std::vector<std::string> senhas;
      
    public:
      Intruso()=default;
      void set_senha_vazada(std::string vazou);
      std::string crack_senha();
};

#endif