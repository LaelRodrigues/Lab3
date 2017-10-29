/**
 * @file	menu.cpp
 * @brief	arquivo corpo com a implentacao das funcoes que
 *			manipulacao o menu de uma agencia
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	26/10/2017
 * @data	27/10/2017
 */

#include "agencia.h"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <memory>
using std::make_shared;

/** 
 * @brief Funcao para criacao de uma conta
 * @param agencia Agencia  
 */ 
void menuCriarConta(Agencia& agencia) {
	string numero;
	float saldo, limite;
	limite = 0;
	bool status;
	cout << "Numero da conta: ";
	cin >> numero;
	cout << "Saldo: ";
	cin >> saldo;
	cout << "Especial (1) sim (0) nao: ";
	cin >> status;
	if(status) {
		cout << "Limite: ";
		cin >> limite;
	}
	shared_ptr<Conta> conta = make_shared<Conta> ("1234-5", numero, saldo, status, limite);
 	agencia.criarConta(conta);
}

/** 
 * @brief Funcao para remocao de uma conta
 * @param agencia Agencia  
 */ 
void menuRemoverConta(Agencia& agencia) {
	string numero;
	cout << "Numero: da conta ";
	cin >> numero;
	agencia.removerConta(numero);
}

/** 
 * @brief Funcao para saque em uma conta
 * @param agencia Agencia  
 */ 
void menuSaque(Agencia& agencia) {
	string numero;
	float valor;
	cout << "Numero da conta:";
	cin >> numero;
	cout << "Valor: ";
	cin >> valor;
	agencia.saque(numero, valor);
}

/** 
 * @brief Funcao para deposito em uma conta
 * @param agencia Agencia  
 */ 
void menuDeposito(Agencia& agencia) {
	string numero;
	float valor;
	cout << "Numero da conta: ";
	cin >> numero;
	cout << "Valor: ";
	cin >> valor;
	agencia.deposito(numero, valor);
}

/** 
 * @brief Funcao para transferencia entre duas contas
 * @param agencia Agencia  
 */ 
void menuTransferencia(Agencia& agencia) {
	string numero1;
	string numero2; 
	float valor;
	cout << "Numero da conta1: ";
	cin >> numero1;
	cout << "Numero da conta2: ";
	cin >> numero2;
	cout << "Valor: ";
	cin >> valor;
	agencia.transferencia(numero1, numero2, valor);

}

/** 
 * @brief Funcao para emissao do saldo de uma conta
 * @param agencia Agencia  
 */ 
void menuEmitirSaldo(Agencia& agencia) {
	string numero;
	cout << "Numero da conta: ";
	cin >> numero;
	agencia.imitirSaldo(numero);
}


/** 
 * @brief Funcao para emissao do extrato de uma conta
 * @param agencia Agencia  
 */ 
void menuExtrato(Agencia& agencia) {
	string numero;
	cout << "Numero da conta: ";
	cin >> numero;

	auto lista = agencia.getContas();
	for(auto i = lista.begin(); i != lista.end(); i++) {
		if(numero == (**i).getNumero()) {
			cout << (**i) << endl;
			return;
		}
	}
	cout << "Nao foi possivel imprimir o extrato. Conta inexistente." << endl; 
}
