#include "Intruso.hpp"

void Intruso::set_senha_vazada(std::string vazou){
	
std::string _vazou; // string sem espaços
std::string input; // sequencia de numeros
std::string senha; // sequencia de letras

for(int a=0; a < vazou.size() ; a++){
if(vazou[a] != ' ') _vazou+=vazou[a];
} // removendo espaços

int a=0;
int b=0;
//cada pair do map representa a letra(A,B,C,D,E) e os dois digitos que ela armazena
while(a<9){
	input = _vazou[a]+_vazou[a+1];
	digitos.insert(std::pair<char,std::string>(41+b ,input)); 
	b++;
	a+=2;
}
//Esse push_back armazenas os maps criados em um vector, para haver a comparação depois
tudo.push_back(digitos);

int c=10;

while(c<15){
	senha += _vazou[c];
	c++;
}
senhas.push_back(senha);//armazenei as diferentes sequencias de letras de cada entrada
	
}

std::string Intruso::crack_senha(){
	
}
