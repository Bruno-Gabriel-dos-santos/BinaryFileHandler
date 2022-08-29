#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <fstream>


int incrementador_numero_da_classe = 0;

void thread_leitura_de_dados(std::string nome_do_arquivo, int numero_classe);
void thread_gravacao_de_dados(std::string nome_do_arquivo, int numero_classe,long long int tamanho_total_da_classe );


class modelo_EntradaSaida_dado_autoalocavel {

public:
	long long int tamanho_total_classe = 0;
	int numero_da_classe = 0;
	int disponibilidade = 1;
	std::vector<unsigned char>vetor_char_da_classe;
	modelo_EntradaSaida_dado_autoalocavel() {
		this->numero_da_classe = incrementador_numero_da_classe;
		incrementador_numero_da_classe++;
	};
	void func_leitura_de_dados_Vec_Char(std::string nome_do_arquivo) {
		if (disponibilidade==1) {
			disponibilidade = 0;
			std::thread t1(thread_leitura_de_dados, nome_do_arquivo,this->numero_da_classe);
			t1.join();
		}
	};
	void func_gravacao_de_dados_binario(std::string nome_do_arquivo) {
		if (disponibilidade == 1) {
			disponibilidade = 0;
			std::thread t2(thread_gravacao_de_dados, nome_do_arquivo, this->numero_da_classe,this->tamanho_total_classe);
			t2.join();
		}
	
	};

private:



};
modelo_EntradaSaida_dado_autoalocavel* dados_classe_autoalocavel = new modelo_EntradaSaida_dado_autoalocavel[1000];

void thread_leitura_de_dados(std::string nome_do_arquivo, int numero_classe) {
	std::cout << "oi da thread 0" << std::endl;

	long long int incrementador = 0;

	std::ifstream arquivo(nome_do_arquivo.c_str(), std::ios::binary);
	while (!arquivo.eof()) {

		dados_classe_autoalocavel[numero_classe].vetor_char_da_classe.push_back(arquivo.get());

		incrementador++;

	}

	arquivo.close();


	incrementador--;
	dados_classe_autoalocavel[numero_classe].disponibilidade = 1;
	dados_classe_autoalocavel[numero_classe].tamanho_total_classe = incrementador;

}

void thread_gravacao_de_dados(std::string nome_do_arquivo, int numero_classe, long long int tamanho_total_da_classe) {

	long long int tam_total = tamanho_total_da_classe;
	long long int incrementador = 0;

	std::ofstream arquivo(nome_do_arquivo.c_str(), std::ios::binary | std::ios::app);

	while (tam_total != 0) {


		arquivo << dados_classe_autoalocavel[numero_classe].vetor_char_da_classe.at(incrementador);
		incrementador++;
		tam_total--;

	}
	incrementador = 0;


	arquivo.close();

	dados_classe_autoalocavel[numero_classe].disponibilidade = 1;

}