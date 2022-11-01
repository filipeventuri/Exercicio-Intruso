#include "intruso.hpp"

void Intruso::set_senha_vazada(std::string vazou){
	
std::string _vazou; // string sem espaços
std::string input; // sequencia de numeros
std::string senha; // sequencia de letras

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
	senha += _vazou[c];
	c++;
}
senhas.push_back(senha);//armazenei as diferentes sequencias de letras de cada entrada

}

std::string Intruso::crack_senha(){
   
	int n=1;
	std::string omega=senhas[0]; //primeira string(senha) de letras que o usuario do caixa eletronico digitou
	std::map<char,std::string> delta=tudo[0]; //a codificao definida pra essa primeira senha
	std::string result=""; //string com a resposta
	/*for(auto a = delta.cbegin(); a!=delta.cend(); a++){
	    std::cout<<a->first<<' '<<a->second<<std::endl;
	}*/
	//repare que o while abaixo so pega a partir da segunda entrada, logo não vai have o caso de comparar a primeira entrada com ela mesma
	
	if(senhas.size()==3){
	
		std::string comparar;
		std::string comparado;
		std::string comparante;
		
		std::string x = senhas[1]; // senha digitada da segunda entrada
		std::map<char,std::string> y = tudo[1]; //codificacoes da segunda entrada
		std::string r = senhas[2]; // senha digitada da terceira entrada
		std::map<char,std::string> t = tudo[2]; //codificacoes da terceira entrada
		
		
		for(int i=0; i<6; i++){ 
			
		comparar = delta[omega[i]];//string com os dois numeros do char i (conteúdo do second. do map)
		comparado = y[x[i]];//string com os dois numeros do char i (conteúdo do second. do map)
		comparante = t[r[i]];//string com dois numeros do char i (conteúdo do second. do map)
		
		if(comparar[0]==comparado[0] || comparar[0]==comparado[1] ){
			if(comparar[0]==comparante[0] || comparar[0]==comparante[1]){
			result += comparar.substr(0,1);
			result += ' ';
			
			}
		}else if(comparar[1]==comparado[0] || comparar[1]==comparado[1]){
			if(comparar[1]==comparante[0] || comparar[1]==comparante[1]){
			result += comparar.substr(1,1);
			result += ' ';
			
			}
	    }//esses if acima serviram pra comparar os digito numero i da primeira senha com o digito numero i da segunda senha e da terceira
		
		}//esse for serve pra descobrir cada digito da senha de 6 digitos
		
}else if(senhas.size()==2){
	
	std::string comparar;
	std::string comparado;
	
	std::string x = senhas[1]; // senha digitada da segunda entrada
	std::map<char,std::string> y = tudo[1]; //codificacoes da segunda entrada
	
	for(int i=0; i<6; i++){ 
			
	comparar = delta[omega[i]];//string com os dois numeros do char i (conteúdo do second. do map)
	comparado = y[x[i]];//string com os dois numeros do char i (conteúdo do second. do map)
	if(comparar[0]==comparado[0] || comparar[0]==comparado[1]){
			result += comparar.substr(0,1);
			result += ' ';
			
	}else if(comparar[1]==comparado[0] || comparar[1]==comparado[1]){
			result += comparar.substr(1,1);
			result += ' ';
		
	}
	
	}// esse for serviu para comparar descobrir cada digito tomando como parametro a primeira senha em relação as demais
}
	//obs esse resultado só vai estar correto se tiverem no maximo 2 entradas
	return result;
}