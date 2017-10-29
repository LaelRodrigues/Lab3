/**
 * @file	agencia.cpp
 * @brief	Implemencao dos metodos da classe Agencia
 *			para representar um agencia
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	29/10/2017
 * @date	29/10/2017
 */

#include <iomanip>
#include "agencia.h"
#include "contacorrente.h"
#include "poupanca.h"

#include <memory>
using std::make_shared;

#include <iostream>
using std::cout;
using std::endl;

#include <typeinfo>  

//Construtor padrao
Agencia::Agencia() {}

//Destrutor padrao
Agencia::~Agencia() {}

/**
 * @param _numeroAgencia Numero da agencia
 * @param _contas Lista de contas da agencia
 */
Agencia::Agencia(string _numeroAgencia, vector<shared_ptr<Conta>> _contas) {
	numeroAgencia = _numeroAgencia;
	contas = _contas;
}

/** @return O numero da agencia */
string Agencia::getNumeroAgencia(){
	return numeroAgencia;
}

/** @param _numeroAgencia Numero da agencia */
void Agencia::setNumeroAgencia(string _numeroAgencia) {
	numeroAgencia = _numeroAgencia;
}

/** @return As contas cadastradas na agencia */
vector<shared_ptr<Conta>> Agencia::getContas() {
	return contas;
}

/** 
 * @details Caso a conta a ser adicionado já pertenca
 *			a lista, o programa exibe uma mensagem de erro
 *			e encerra a funcao 
 * @param conta Conta
 */

void Agencia::criarConta(shared_ptr<Conta> conta) {
	for(auto i = contas.begin(); i != contas.end(); i++) {
		if((*conta) == (**i)) {
			cout << "Erro no cadastramento, conta ja existe." << endl;
			return;
		}
	}
	cout << "Conta adicionada..." << endl;
	contas.push_back(conta);
}

/** 
 * @details Caso a conta a ser removida nao pertenca 
 *			a lista, o programa exibe uma mensagem de erro 
 * @param numeroConta Numero da conta
 */
void Agencia::removerConta(string numeroConta) {
	for(auto i = contas.begin(); i != contas.end(); i++) {
		if(numeroConta == ((**i).getNumero())) {
			cout << "Conta removida..." << endl;
			contas.erase(i);
			return;
		}
	}
	cout << "Erro na remocao, conta inexistente." << endl;
}
/**
 * @param numeroConta Numero da conta
 * @param valor Valor do saque
 */

void Agencia::saque(string numeroConta, float valor) {
	for(auto i = contas.begin(); i != contas.end(); i++) {
		shared_ptr<Movimentacao> movimentacao = make_shared<Movimentacao>("Saque", valor, debito);
		if((numeroConta == (**i).getNumero()) && (typeid(**i) == typeid(ContaCorrente))) {
			shared_ptr<ContaCorrente> c = std::dynamic_pointer_cast<ContaCorrente>(*i);
			if((*c).getStatus() == true) {
				if(valor <= 0){
					cout << "Nao é realizar saques de valores negativos ou nulo." << endl;
					return;
				}
				else if(valor <= (*c).getSaldo()) {
					cout << "Saque realizado..." << endl;
					(*c).setSaldo((*c).getSaldo()-valor);
					(*c).setMovimentacoes(movimentacao);
					return;
				}
				else if(valor > (*c).getSaldo() && valor <= ((*c).getSaldo() + (*c).getLimiteDisp())) {
					cout << "Saque realizado..." << endl;
					cout << "Limite: " << (*c).getLimiteDisp() << endl;
					cout << "saldo: " << (*c).getSaldo() << endl;
					(*c).setLimiteDisp((*c).getLimiteDisp() - (valor-(*c).getSaldo()));
					cout << "Limite: " << (*c).getLimite() << endl;
					(*c).setSaldo(0);
					cout << "Limite: " << (*c).getLimiteDisp() << endl;

					(*c).setMovimentacoes(movimentacao);
					return;
				}
				else  {
					cout << "Nao foi possivel sacar, valor do saque eh maior que o saldo mais limte." << endl;
					return;
				}
			}
			else {
				if(valor <= 0){
					cout << "Nao é realizar saques de valores negativos ou nulo." << endl;
					return;
				}
				else if(valor <= (*c).getSaldo()) {
					cout << "Saque realizado..." << endl;
					(*c).setSaldo((*c).getSaldo()-valor);
					(*c).setMovimentacoes(movimentacao);
					return;
				}
				else  {
					cout << "Nao foi possivel sacar, valor do saque eh maior que o saldo." << endl;
					return;
				}
			}
		}
		else if(numeroConta == (**i).getNumero() && typeid(**i) == typeid(ContaPoupanca)) {
			shared_ptr<ContaPoupanca> p = std::dynamic_pointer_cast<ContaPoupanca>(*i);
			if(valor <= 0){
				cout << "Nao é realizar saques de valores negativos ou nulo." << endl;
				return;
			}
			else if(valor <= (*p).getSaldo()) {
				cout << "Saque realizado..." << endl;
				(*p).setSaldo((*p).getSaldo()-valor);
				(*p).setMovimentacoes(movimentacao);
				return;
			}
			else  {
				cout << "Nao foi possivel sacar, valor do saque eh maior que o saldo." << endl;
				return;
			}	
		}
	}
	cout << "Erro, Conta inexistente." << endl;
}

/**
 * @param numeroConta Numero da conta
 * @param valor Valor do deposito
 */
void Agencia::deposito(string numeroConta, float valor) {
	for(auto i = contas.begin(); i != contas.end(); i++) {
		shared_ptr<Movimentacao> movimentacao = make_shared<Movimentacao>("Desposito", valor, credito);
		if(numeroConta == (**i).getNumero() && typeid(**i) == typeid(ContaCorrente)) {
			shared_ptr<ContaCorrente> c = std::dynamic_pointer_cast<ContaCorrente>(*i);
			if((*c).getStatus() == true) {
				cout << "eiii" << endl;
				if(valor <= 0) {
					cout << "Nao é realizar Desposito de valores negativos ou nulo." << endl;
					return;
				}
				else if((*c).getSaldo() > 0) {
					cout << "Desposito realizado..." << endl;
					(*c).setSaldo((*c).getSaldo()+valor);
					(*c).setMovimentacoes(movimentacao);
					return;
				}
				else if((*c).getSaldo() == 0 && valor >= (*c).getLimite()) {
					cout << "Desposito realizado..." << endl;
					float aux = (*c).getLimite() - (*c).getLimiteDisp();
					(*c).setLimiteDisp((*c).getLimiteDisp() + aux);
					cout << "valor: " << valor << endl;
					cout << "aux: " << aux << endl;
					(*c).setSaldo(valor-aux);
					(*c).setMovimentacoes(movimentacao);
					return;
				}
				else if((*c).getSaldo() == 0 && valor < (*c).getLimite()) {
					if(valor > ((*c).getLimite() - (*c).getLimiteDisp())) {
						cout << "Desposito realizado..." << endl;
						float aux = (*c).getLimite() - (*c).getLimiteDisp();
						(*c).setLimiteDisp((*c).getLimiteDisp() + aux);
						(*c).setSaldo(valor-aux);
						(*c).setMovimentacoes(movimentacao);
					}
					else if(valor <= ((*c).getLimite() - (*c).getLimiteDisp())) {
						cout << "Desposito realizado..." << endl;
						(*c).setLimiteDisp((*c).getLimiteDisp() + valor);
						(*c).setMovimentacoes(movimentacao);
						return;
					}
				}
			}
			else if((*c).getStatus() == false) {
				if(valor <= 0) {
					cout << "Nao é realizar Desposito de valores negativos ou nulo." << endl;
					return;
				}
				else {
					cout << "Desposito realizado..." << endl;
					(*c).setSaldo((*c).getSaldo()+valor);
					(*c).setMovimentacoes(movimentacao);
					return;
				}
			}		
		}
		else if(numeroConta == (**i).getNumero() && typeid(**i) == typeid(ContaPoupanca)) {
			shared_ptr<ContaPoupanca> p = std::dynamic_pointer_cast<ContaPoupanca>(*i);
			if(valor <= 0) {
				cout << "Nao é realizar Desposito de valores negativos ou nulo." << endl;
				return;
			}
			else {
				cout << "Desposito realizado..." << endl;
				(*p).setSaldo((*p).getSaldo()+valor);
				(*p).setMovimentacoes(movimentacao);
				return;
			}
		}			
	}
	cout << "Erro, Conta inexistente." << endl;
}

/**
 * @param numeroConta1 Numero da primeira conta
 * @param numeroConta2 Numero da segunda conta
 * @param valor Valor da trasferencia
 */
void Agencia::transferencia(string numeroConta1, string numeroConta2, float valor) {
	for(auto i = contas.begin(); i != contas.end(); i++) {
		shared_ptr<Movimentacao> movimentacao1 = make_shared<Movimentacao>("Trasferencia", valor, debito);
		shared_ptr<Movimentacao> movimentacao2 = make_shared<Movimentacao>("Trasferencia", valor, credito);
		if(numeroConta1 == (**i).getNumero() && typeid(**i) == typeid(ContaCorrente)) {
			shared_ptr<ContaCorrente> c1 = std::dynamic_pointer_cast<ContaCorrente>(*i);
			if((*c1).getStatus() == true) {
				if(valor <= 0) {
					cout << "Nao é realizar Trasferencias de valores negativos ou nulo." << endl;
				}
				else if(valor <= (*c1).getSaldo()) {
					for(auto j = contas.begin(); j != contas.end(); j++) {
						if(numeroConta2 == (**j).getNumero() && typeid(**j) == typeid(ContaCorrente)) {
							shared_ptr<ContaCorrente> c2 = std::dynamic_pointer_cast<ContaCorrente>(*j);
							if((*c2).getStatus() == true) {
								if((*c2).getSaldo() > 0) {
									cout << "Trasferencia realizada..." << endl;
									(*c1).setSaldo((*c1).getSaldo() - valor);
									(*c2).setSaldo((*c2).getSaldo() + valor);
									(*c1).setMovimentacoes(movimentacao1);
									(*c2).setMovimentacoes(movimentacao2);
									return;
								}
								else if((*c2).getSaldo() == 0 && valor >= (*c2).getLimite()) {
									cout << "Trasferencia realizada..." << endl;
									(*c1).setSaldo((*c1).getSaldo() - valor);
									float aux = (*c2).getLimite() - (*c2).getLimiteDisp();
									(*c2).setLimiteDisp((*c2).getLimiteDisp() + aux);
									(*c2).setSaldo(valor-aux);
									(*c1).setMovimentacoes(movimentacao1);
									(*c2).setMovimentacoes(movimentacao2);
									return;
								}
								else if((*c2).getSaldo() == 0 && valor < (*c2).getLimite()) {
									if(valor > ((*c2).getLimite() - (*c2).getLimiteDisp())) {
										cout << "Trasferencia realizada..." << endl;
										(*c1).setSaldo((*c1).getSaldo() - valor);
										float aux = (*c2).getLimite() - (*c2).getLimiteDisp();
										(*c2).setLimiteDisp((*c2).getLimiteDisp() + aux);
										(*c2).setSaldo(valor-aux);
										(*c1).setMovimentacoes(movimentacao1);
										(*c2).setMovimentacoes(movimentacao2);
										return;
									}
									else if(valor <= ((*c2).getLimite() - (*c2).getLimiteDisp())) {
										cout << "Trasferencia realizada..." << endl;
										(*c1).setSaldo((*c1).getSaldo() - valor);
										(*c2).setLimiteDisp((*c2).getLimiteDisp() + valor);
										(*c1).setMovimentacoes(movimentacao1);
										(*c2).setMovimentacoes(movimentacao2);
										return;
									}
								}
							}
							else {
								cout << "Trasferencia realizada..." << endl;
								(*c1).setSaldo((*c1).getSaldo() - valor);
								(*c2).setSaldo((*c2).getSaldo() + valor);
								(*c1).setMovimentacoes(movimentacao1);
								(*c2).setMovimentacoes(movimentacao2);
								return;
							}
						}
						else if(numeroConta2 == (**j).getNumero() && typeid(**j) == typeid(ContaPoupanca)) {
							shared_ptr<ContaPoupanca> p1 = std::dynamic_pointer_cast<ContaPoupanca>(*j);
							cout << "Trasferencia realizada..." << endl;
							(*c1).setSaldo((*c1).getSaldo() - valor);
							(*p1).setSaldo((*p1).getSaldo()+valor);
							(*c1).setMovimentacoes(movimentacao1);
							(*p1).setMovimentacoes(movimentacao2);
							return;
						}
					}
					cout << "Erro, conta 2 inexistente" << endl;
					return;
				}
				else if(valor > (*c1).getSaldo() && valor <= ((*c1).getSaldo() + (*c1).getLimiteDisp())) {
					for(auto j = contas.begin(); j != contas.end(); j++) {
						if(numeroConta2 == (**j).getNumero() && typeid(**j) == typeid(ContaCorrente)) {
							shared_ptr<ContaCorrente> c2 = std::dynamic_pointer_cast<ContaCorrente>(*j);
							if((*c2).getStatus() == true) {
								if((*c2).getSaldo() > 0) {
									cout << "Trasferencia realizada..." << endl;
									(*c1).setLimiteDisp((*c1).getLimiteDisp() - (valor-(*c1).getSaldo()));
									(*c2).setSaldo((*c2).getSaldo() + valor);
									(*c1).setSaldo(0);
									(*c1).setMovimentacoes(movimentacao1);
									(*c2).setMovimentacoes(movimentacao2);
									return;
								}
								else if((*c2).getSaldo() == 0 && valor >= (*c2).getLimite()) {
									cout << "Trasferencia realizada..." << endl;
									(*c1).setLimiteDisp((*c1).getLimiteDisp() - (valor-(*c1).getSaldo()));
									float aux = (*c2).getLimite() - (*c2).getLimiteDisp();
									(*c2).setLimiteDisp((*c2).getLimiteDisp() + aux);
									(*c2).setSaldo(valor-aux);
									(*c1).setSaldo(0);
									(*c1).setMovimentacoes(movimentacao1);
									(*c2).setMovimentacoes(movimentacao2);
									return;
								}
								else if((*c2).getSaldo() == 0 && valor < (*c2).getLimite()) {
									if(valor > ((*c2).getLimite() - (*c2).getLimiteDisp())) {
										cout << "Trasferencia realizada..." << endl;
										(*c1).setLimiteDisp((*c1).getLimiteDisp() - (valor-(*c1).getSaldo()));
										float aux = (*c2).getLimite() - (*c2).getLimiteDisp();
										(*c2).setLimiteDisp((*c2).getLimiteDisp() + aux);
										(*c2).setSaldo(valor-aux);
										(*c1).setSaldo(0);
										(*c1).setMovimentacoes(movimentacao1);
										(*c2).setMovimentacoes(movimentacao2);
										return;
									}
									else if(valor <= ((*c2).getLimite() - (*c2).getLimiteDisp())) {
										cout << "Trasferencia realizada..." << endl;
										(*c1).setLimiteDisp((*c1).getLimiteDisp() - (valor-(*c1).getSaldo()));
										(*c2).setLimiteDisp((*c2).getLimiteDisp() + valor);
										(*c1).setSaldo(0);
										(*c1).setMovimentacoes(movimentacao1);
										(*c2).setMovimentacoes(movimentacao2);
										return;
									}
								}
							}
							else {
								cout << "Trasferencia realizada..." << endl;
								(*c1).setLimiteDisp((*c1).getLimiteDisp() - (valor-(*c1).getSaldo()));
								(*c2).setSaldo((*c2).getSaldo() + valor);
								(*c1).setSaldo(0);
								(*c1).setMovimentacoes(movimentacao1);
								(*c2).setMovimentacoes(movimentacao2);
								return;
							}
						}
						else if(numeroConta2 == (**j).getNumero() && typeid(**j) == typeid(ContaPoupanca)) {
							cout << "Trasferencia realizada..." << endl;
							shared_ptr<ContaPoupanca> p1 = std::dynamic_pointer_cast<ContaPoupanca>(*j);
							(*c1).setLimiteDisp((*c1).getLimiteDisp() - (valor-(*c1).getSaldo()));
							(*p1).setSaldo((*p1).getSaldo() + valor);
							(*c1).setSaldo(0);
							(*c1).setMovimentacoes(movimentacao1);
							(*p1).setMovimentacoes(movimentacao2);
							return;
						}
					}
					cout << "Erro, conta 2 inexistente." << endl;
					return;
				}
				else  {
					cout << "Nao foi possivel sacar, valor do saque eh maior que o saldo mais limte." << endl;
					return;
				}
			}
			else {
				if(valor <= (**i).getSaldo()) {
					for(auto j = contas.begin(); j != contas.end(); j++) {
						if(numeroConta2 == (**j).getNumero() && typeid(**j) == typeid(ContaCorrente)) {
							shared_ptr<ContaCorrente> c2 = std::dynamic_pointer_cast<ContaCorrente>(*j);
							if((*c2).getStatus() == true) {
								if((*c2).getSaldo() > 0) {
									cout << "Trasferencia realizada..." << endl;
									(*c1).setSaldo((*c1).getSaldo() - valor);
									(*c2).setSaldo((*c2).getSaldo() + valor);
									(*c1).setMovimentacoes(movimentacao1);
									(*c2).setMovimentacoes(movimentacao2);
									return;
								}
								else if((*c2).getSaldo() == 0 && valor >= (*c2).getLimite()) {
									cout << "Trasferencia realizada..." << endl;
									(*c1).setSaldo((*c1).getSaldo() - valor);
									float aux = (*c2).getLimite() - (*c2).getLimiteDisp();
									(*c2).setLimiteDisp((*c2).getLimiteDisp() + aux);
									(*c2).setSaldo(valor-aux);
									(*c1).setMovimentacoes(movimentacao1);
									(*c2).setMovimentacoes(movimentacao2);
									return;
								}
								else if((*c2).getSaldo() == 0 && valor < (*c2).getLimite()) {
									if(valor > ((*c2).getLimite() - (*c2).getLimiteDisp())) {
										cout << "Trasferencia realizada..." << endl;
										(*c1).setSaldo((*c1).getSaldo() - valor);
										float aux = (*c2).getLimite() - (*c2).getLimiteDisp();
										(*c2).setLimiteDisp((*c2).getLimiteDisp() + aux);
										(*c2).setSaldo(valor-aux);
										(*c1).setMovimentacoes(movimentacao1);
										(*c2).setMovimentacoes(movimentacao2);
										return;
									}
									else if(valor <= ((*c2).getLimite() - (*c2).getLimiteDisp())) {
										cout << "Trasferencia realizada..." << endl;
										(*c1).setSaldo((*c1).getSaldo() - valor);
										(*c2).setLimiteDisp((*c2).getLimiteDisp() + valor);
										(*c1).setMovimentacoes(movimentacao1);
										(*c2).setMovimentacoes(movimentacao2);
										return;
									}
								}
							}
							else {
								cout << "Trasferencia realizada..." << endl;
								(*c1).setSaldo((*c1).getSaldo() - valor);
								(*c2).setSaldo((*c2).getSaldo()+valor);
								(*c1).setMovimentacoes(movimentacao1);
								(*c2).setMovimentacoes(movimentacao2);
								return;
							}
						}
						else if(numeroConta2 == (**j).getNumero() && typeid(**j) == typeid(ContaPoupanca)) {
							cout << "Trasferencia realizada..." << endl;
							shared_ptr<ContaPoupanca> p1 = std::dynamic_pointer_cast<ContaPoupanca>(*j);
							(*c1).setSaldo((*c1).getSaldo() - valor);
							(*p1).setSaldo((*p1).getSaldo()+valor);
							(*c1).setMovimentacoes(movimentacao1);
							(*p1).setMovimentacoes(movimentacao2);
							return;
						}
					}
					cout << "Erro, conta 2 inexistente." << endl;
					return;
				}
				else {
					cout << "Nao foi possivel sacar, valor do saque eh maior que o saldo." << endl;
					return;
				}
			}
		}
		else if(numeroConta1 == (**i).getNumero() && typeid(**i) == typeid(ContaPoupanca)) {
			shared_ptr<ContaPoupanca> p1 = std::dynamic_pointer_cast<ContaPoupanca>(*i);
			if(valor <= (*p1).getSaldo()) {
				for(auto j = contas.begin(); j != contas.end(); j++) {
					if(numeroConta2 == (**j).getNumero() && typeid(**j) == typeid(ContaCorrente)) {
						shared_ptr<ContaCorrente> c1 = std::dynamic_pointer_cast<ContaCorrente>(*j);
						if((*c1).getStatus() == true) {
							if((*c1).getSaldo() > 0) {
								cout << "Trasferencia realizada..." << endl;
								(*p1).setSaldo((*p1).getSaldo() - valor);
								(*c1).setSaldo((*c1).getSaldo() + valor);
								(**i).setMovimentacoes(movimentacao1);
								(**j).setMovimentacoes(movimentacao2);
								return;
							}
							else if((*c1).getSaldo() == 0 && valor >= (*c1).getLimite()) {
								cout << "Trasferencia realizada..." << endl;
								(*p1).setSaldo((*p1).getSaldo() - valor);
								float aux = (*c1).getLimite() - (*c1).getLimiteDisp();
								(*c1).setLimiteDisp((*c1).getLimiteDisp() + aux);
								(*c1).setSaldo(valor-aux);
								(*p1).setMovimentacoes(movimentacao1);
								(*c1).setMovimentacoes(movimentacao2);
								return;
							}
							else if((*c1).getSaldo() == 0 && valor < (*c1).getLimite()) {
								if(valor > ((*c1).getLimite() - (*c1).getLimiteDisp())) {
									cout << "Trasferencia realizada..." << endl;
									(*p1).setSaldo((*p1).getSaldo() - valor);
									float aux = (*c1).getLimite() - (*c1).getLimiteDisp();
									(*c1).setLimiteDisp((*c1).getLimiteDisp() + aux);
									(*c1).setSaldo(valor-aux);
									(*p1).setMovimentacoes(movimentacao1);
									(*c1).setMovimentacoes(movimentacao2);
									return;
								}
								else if(valor <= ((*c1).getLimite() - (*c1).getLimiteDisp())) {
									cout << "Trasferencia realizada..." << endl;
									(*p1).setSaldo((*p1).getSaldo() - valor);
									(*c1).setLimiteDisp((*c1).getLimiteDisp() + valor);
									(*p1).setMovimentacoes(movimentacao1);
									(*c1).setMovimentacoes(movimentacao2);
									return;
								}
							}
						}
						else {
							cout << "Trasferencia realizada..." << endl;
							(*p1).setSaldo((*p1).getSaldo() - valor);
							(*c1).setSaldo((*c1).getSaldo()+valor);
							(*p1).setMovimentacoes(movimentacao1);
							(*c1).setMovimentacoes(movimentacao2);
							return;
						}
					}
					else if(numeroConta2 == (**j).getNumero() && typeid(**j) == typeid(ContaPoupanca)) {
						cout << "Trasferencia realizada..." << endl;
						shared_ptr<ContaPoupanca> p2 = std::dynamic_pointer_cast<ContaPoupanca>(*j);
						(*p1).setSaldo((*p1).getSaldo() - valor);
						(*p2).setSaldo((*p2).getSaldo()+valor);
						(*p1).setMovimentacoes(movimentacao1);
						(*p2).setMovimentacoes(movimentacao2);
						return;
					}
				}
				cout << "Erro, conta 2 inexistente." << endl;
				return;
			}
			else {
				cout << "Nao foi possivel sacar, valor do saque eh maior que o saldo." << endl;
				return;
			}
		}
	}
	cout << "Erro conta1 inexistente." << endl;
}

/** @param numeroConta Numero da conta */
void Agencia::imitirSaldo(string numeroConta) {
	for(auto i = contas.begin(); i != contas.end(); i++) {
		if(numeroConta == ((**i).getNumero())) {
			cout << "Saldo = " << (**i).getSaldo() << endl;
		}
	}
}
