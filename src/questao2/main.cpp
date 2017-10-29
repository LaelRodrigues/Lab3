/**
 * @file	main.cpp
 * @brief	arquivo de teste para simular um agencia
 *			bancaria
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	28/10/2017
 * @data	28/10/2017
 */

#include "conta.h"
#include "movimentacao.h"
#include "agencia.h"
#include "menu.h"

#include <memory>
using std::make_shared;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

/** @brief Funcao Principal */
int main() {

	Agencia agencia;

	int opcao;
	while(true) {
		cout << endl << "-----------Operacoes Bancarias----------" << endl;
		cout << "(1) Criacao" << endl;
		cout << "(2) Remocao" << endl;
		cout << "(3) Saque" << endl;
		cout << "(4) Deposito" << endl;
		cout << "(5) Emissao de saldo" << endl;
		cout << "(6) Extrato" << endl;
		cout << "(7) Transferencia" << endl;
		cout << "(0) Sair" << endl;
		cout << "opcao: ";
		cin >> opcao;

		switch(opcao) {
			case 1:
				menuCriarConta(agencia);
				break;

			case 2:
				menuRemoverConta(agencia);
				break;

			case 3:
				menuSaque(agencia);
				break;

			case 4:
				menuDeposito(agencia);
				break;

			case 5:
				menuEmitirSaldo(agencia);
				break;

			case 6:
				menuExtrato(agencia);
				break;

			case 7:
				menuTransferencia(agencia);
				break;

			case 0: {
				cout << "Programa Finalizado." << endl;
				return 0;
			}
			default:
				cout << "Valor invalido" << endl;
				break;
		}
	}
}