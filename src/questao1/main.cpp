/**
 * @file	main.cpp
 * @brief	arquivo de teste das classe Produto, Fruta, Roupa
 *			e Bebida e das funcao de manipulacao de arquivo
 *			manipulacao de arquivos 
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	25/10/2017
 * @data	26/10/2017
 */

#include <iostream>
#include <vector>
#include <memory>
#include <typeinfo>
#include "produto.h"
#include "fruta.h"
#include "roupa.h"
#include "bebida.h"
#include "arquivo.h"

using namespace std;

/** @brief Funcao Principal */
int main(int argc, char const *argv[]) {

	vector<shared_ptr<Produto>> lista;
	string nomeArquivo = "Dados.dat";
	ifstream entrada(nomeArquivo);
	verificaArquivo(entrada);
	
	cout << "Cadastrando produtos..." << endl;
	int quantProdutos;
	string buffer;
	quantProdutos = 0;

	while(getline(entrada, buffer)){
		quantProdutos++;
	}

	entrada.clear();
	entrada.seekg(0, entrada.beg);

	LerDados(entrada, lista, quantProdutos);

	int opcao;
	shared_ptr<Produto> prod;
	while(true) {
		cout << endl << "-----------Operacoes-----------" << endl;
		cout << "(1) Cadastro" << endl;
		cout << "(2) Remocao" << endl;
		cout << "(3) Venda " << endl;
		cout << "(4) Listar" << endl;
		cout << "(0) Sair" << endl;
		cout << "opcao: ";
		cin >> opcao;

		switch(opcao) {
			case 1:
			{	
				int cont = 0;
				int tipo;
				string cod, descricao;
				double preco;
				cout << "---------Produtos-------" << endl;
				cout << "(1) Fruta" << endl;
				cout << "(2) Roupa" << endl;
				cout << "(3) Bebida" << endl;
				cout << "Tipo: ";
				cin >> tipo;
				if(tipo < 1 || tipo > 3) {
					cout << "Valor invalido." << endl;
					break;
				}
				cout << endl << "Codigo: ";
				cin >> cod;
				cout << "Descricao: ";
				cin >> descricao;
				cout << "Preco: ";
				cin >> preco;
				if(tipo == 1) {
					string data;
					int validade;
					cout << "Data do lote: ";
					cin >> data;
					cout << "Validade: ";
					cin >> validade;
					prod = make_shared<Fruta>(cod, descricao, preco, data, validade);
				}
				else if(tipo == 2) {
					string marca, tamanho;
					char sexo;
					cout << "Marca: ";
					cin >> marca;
					cout << "Sexo: ";
					cin >> sexo;
					cout << "Tamanho: ";
					cin >> tamanho;
					prod = make_shared<Roupa>(cod, descricao, preco, marca, sexo, tamanho);
				}
				else {
					int teor_alcoolico;
					cout << "Teor alcoolico: ";
					cin >> teor_alcoolico;
					prod = make_shared<Bebida>(cod, descricao, preco, teor_alcoolico);
				}
				for(auto i = lista.begin(); i != lista.end(); i++) {
					if(cod == (**i).getCodBarras()) {
						cout << endl << "Nao foi possivel Adicionar, produto ja cadastrado." << endl;
						cont++;
						break;
					}
				}
				if(cont == 1) break;
				lista.push_back(prod);
				break;
			}

			case 2:
			{
				string cod;
				cout << "Codigo: ";
				cin >> cod;
				for(auto i = lista.begin(); i != lista.end(); i++) {
					if(cod == (**i).getCodBarras()) {
						cout << endl << "Produto removido." << endl;
						break;
					}
				}
				cout << "Nao foi possivel remover, produto inexistente." << endl;
				break;
			}

			case 3:
			{
				int op = 1;
				while(op) {
					int quant, cont;
					cont = 0;
					double total = 0.0;
					string descricao;
					cout << "Nome e quantidade: ";
					cin >> descricao >> quant; 
					for(auto i = lista.begin(); i != lista.end(); i++) {
						if(descricao == (**i).getDescricao()) {
							total += (**i).getPreco() * quant;
							cont++;
							break;
						}
					}
					if(cont == 0) {
						cout << "Produto inexistente, nome do produto e invalido." << endl;
					}
					else {
						cout << "(1) comprar e (0) calcular: ";
						cin >> op;
						if(op == 0) {
							cout << endl << "Total a pagar = R$ " << total << endl;
						}						
					}
				}
				break;

			}
			case 4: 
			{
				cout << endl << "		Lista de Produtos		" << endl;
				cout << endl << "-----------Frutas-----------" << endl;
				for (auto i = lista.begin(); i != lista.end(); ++i) {	
					
					if(typeid(**i) == typeid(Fruta))
					cout << (**i) << endl;
				}
				cout << endl << "-----------Roupas-----------" << endl;
				for (auto i = lista.begin(); i != lista.end(); ++i) {	
					
					if(typeid(**i) == typeid(Roupa)){
						cout << (**i) << endl;
					}
				}

				cout << endl << "-----------Bebidas-----------" << endl;
				for (auto i = lista.begin(); i != lista.end(); ++i) {	
					
					if(typeid(**i) == typeid(Bebida)){
						cout << (**i) << endl;
					}
				}
				break;
			}
			case 0:
			{
				cout << "Programa finalizado." << endl;
				return 0;
			}
			default: 
			{
				cout << "Valor invalido." << endl;
				break;
			}
		}
	}
}