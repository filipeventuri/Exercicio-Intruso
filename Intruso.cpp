#include "Intruso"

void Intruso::set_senha_vaza(std::string vazou){
  
std::string filtro;
std::string t;
int b=0;

//abaixo estou excluindo os espaços
while(int i=0; i!=29; i++){if(vazou[i]!=' ') filtro+=vazou[i];}

//abaixo estou armazenando cada par de numeros em strings e associando às 5 primeiras letras do alfabeto 
for(int a=0; a<9; a+2){
  
t = filtro[a]+filtro[a+1];
  
file.insert(std::pair<char,std::string>(41+b,t));

b++;

}
  
//abaixo estou armazenando cada entrada em um vector
date.push_back(file);

}