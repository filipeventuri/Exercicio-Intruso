#include "intruso.hpp"

void Intruso::set_senha_vazada(std::string vazou){

std::string _vazou; // string sem espaços
std::string input; // sequencia de numeros
std::string senha; // sequencia de letras
std::map<char,std::string> digitos;

for(int a=0; a < vazou.size() ; a++){
if(vazou[a] != ' ') _vazou+= vazou.substr(a,1);
} // removendo espaços


int a=0;
int b=0;
//cada pair do map representa a letra(A,B,C,D,E) e os dois digitos que ela armazena
while(a<9){
  	input = _vazou.substr(a,2);
  	if(b==0)digitos.insert(std::pair<char,std::string>('A',input));
  	if(b==1)digitos.insert(std::pair<char,std::string>('B',input)); 
  	if(b==2)digitos.insert(std::pair<char,std::string>('C',input)); 
  	if(b==3)digitos.insert(std::pair<char,std::string>('D',input)); 
  	if(b==4)digitos.insert(std::pair<char,std::string>('E',input)); 
  	b++;
	a+=2;
}
//Esse push_back armazenas os maps criados em um vector, para haver a comparação depois
tudo.push_back(digitos);

int c=10;

while(c<16){
	senha += _vazou.substr(c,1);
	c++;
}
senhas.push_back(senha);//armazenei as diferentes sequencias de letras de cada entrada

}

std::string Intruso::crack_senha(){

std::string p;
std::string password;
std::string str;

int n=senhas.size();
int count[n][6];
for(int u=0; u < n; u++){
for(int i=0;i<6;i++){
		count[u][i]=0;
	}
}
int c=0;
int y=0;
for(auto b : tudo){
std::string teste = senhas[c];
for(int a = 0; a<6; a++ ){
	
	count[y][a] = stoi(b[teste[a]]);
		}
	
	c++;
	y++;
	}
	


for(int i=0;i<6;i++){
    for(int u=0; u < n; u++){
		str+= std::to_string(count[u][i]);
	}

	
	for(int i = 0; str[i]!='\0'; i++){
	int contador=0;
	for(int u= 0; str[u]!='\0'; u++){
	if(str[i]==str[u]){ 
	contador++;
	if(contador==n){ p += str.substr(i,1);}
	}
	
	}
	
	
	}
	
	str.clear();
}
if(n==3)password = p.substr(0,1) + ' ' + p.substr(3,1) + ' ' + p.substr(6,1)+ ' ' + p.substr(9,1)+ ' ' + p.substr(12,1)+ ' ' + p.substr(15,1);
if(n==2)password = p.substr(0,1) + ' ' + p.substr(2,1) + ' ' + p.substr(4,1)+ ' ' + p.substr(6,1)+ ' ' + p.substr(8,1)+ ' '+ p.substr(10,1);

return password;  
	}		
