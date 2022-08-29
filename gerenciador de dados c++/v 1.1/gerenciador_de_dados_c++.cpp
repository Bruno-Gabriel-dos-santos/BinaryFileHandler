// gerenciador_de_dados_c++.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include "leitura_e_gravacao_de_dados.cpp"
#include <windows.h>

using namespace std;

int main()
{
    


    

    //tempo para a thead
    dados_classe_autoalocavel[0].func_leitura_de_dados_Vec_Char("a.txt");
    Sleep(1000);
    cout << dados_classe_autoalocavel[0].numero_da_classe<<endl;
    cout<< dados_classe_autoalocavel[0].disponibilidade<<endl;
    cout << dados_classe_autoalocavel[0].tamanho_total_classe << endl;
    cout << dados_classe_autoalocavel[0].vetor_char_da_classe.at(0) << endl;
    dados_classe_autoalocavel[0].func_limpeza_total_dos_dados();
    dados_classe_autoalocavel[0].func_gravacao_de_dados_binario("b.txt");


    return 0;
}
