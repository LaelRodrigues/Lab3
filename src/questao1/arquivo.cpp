/**
 * @file	arquivo.cpp
 * @brief	arquivo corpo com a implentacao das funcoes para 
 *			manipulacao de arquivos 
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	25/10/2017
 * @date	29/10/2017
 */


#include "arquivo.h"

#include <cstdlib>
using std::atoi;

#include <string>
using std::getline;
using std::string;
using std::stof;

#include "produto.h"

/**
 * @brief	Funcao que verifica se o arquivo e valido
 * @param 	arquivo Stream de entrada 
 */
void verificaArquivo(ifstream& arquivo) {
	if (arquivo.bad() || !arquivo || (arquivo.is_open() == 0)) {
		cout << "Erro ao abrir o arquivo." << endl;
		cout << "Programa finalizado." << endl;
		exit(1);
	}
}

/**
 * @brief	Funcao que Ler os dados do arquivo de entrada
 * @param 	lista Lista de produtos
 * @param 	arquivo Stream de entrada 
 * @param 	tam Tamanho da lista de produtos 
 */
void LerDados(ifstream& arquivo, vector<shared_ptr<Produto>>& lista, int tam) {

	string aux, tipo, codigo, descricao, s_preco;
	double preco;
	int cont;
	shared_ptr<Produto> prod;

	for(int i = 0; i < tam; i++) {
		cont = 0;
		getline(arquivo, tipo, ' ');
		getline(arquivo, codigo, ';');
		getline(arquivo, descricao, ';');
		getline(arquivo, s_preco, ';');
		preco = stof(s_preco.c_str());
		if(tipo == "Fruta") {
			string data, s_validade, aux;
			getline(arquivo, data, ';');
			getline(arquivo, s_validade, ';');
			int validade = stoi(s_validade);
			prod = make_shared<Fruta>(codigo, descricao, preco, data, validade);
			for(auto i = lista.begin() ; i != lista.end(); i++) {
				if((**i) == *prod) {
					cout << "Não foi possivel Adicionar, produto ja cadastrado!!" << endl;
					cont++;
					break;
				}
			}
			if(cont == 0){
				cout << "Produto cadastrado." << endl;
				lista.push_back(prod);
			}
			getline(arquivo, aux);
		}

		else if(tipo == "Roupa") {
			string marca, s_sexo, tamanho, aux;
			getline(arquivo, marca, ';');
			getline(arquivo, s_sexo, ';');
			char sexo = s_sexo[0];
			getline(arquivo, tamanho, ';');
			prod = make_shared<Roupa>(codigo, descricao, preco, marca, sexo, tamanho);
			for(auto i = lista.begin() ; i != lista.end(); i++) {
				if((**i) == *prod) {
					cout << "Não foi possivel Adicionar, produto ja cadastrado!!" << endl;
					cont++;
					break;
				}
			}
			if(cont == 0){
				cout << "Produto cadastrado." << endl;
				lista.push_back(prod);
			}
			getline(arquivo, aux);

		}
		else if(tipo == "Bebida") {
			string s_teor_alcoolico, aux;
			getline(arquivo, s_teor_alcoolico, ';');
			int teor_alcoolico = stoi(s_teor_alcoolico);
			prod = make_shared<Bebida>(codigo, descricao, preco, teor_alcoolico);
			for(auto i = lista.begin() ; i != lista.end(); i++) {
				if((**i) == *prod) {
					cout << "Não foi possivel Adicionar, produto ja cadastrado!!" << endl;
					cont++;
					break;
				}
			}			
			if(cont == 0) {
				cout << "Produto cadastrado." << endl;
				lista.push_back(prod);
			}
			getline(arquivo, aux);
		}
	}
}
	
