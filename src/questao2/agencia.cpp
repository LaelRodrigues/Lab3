/**
 * @file	agencia.cpp
 * @brief	Implemencao dos metodos da classe Agencia
 *			para representar um agencia
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	28/10/2017
 * @date	28/10/2017
 */

#include <iomanip>
#include "agencia.h"

#include <memory>
using std::make_shared;

#include <iostream>
using std::cout;
using std::endl;

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
		if(numeroConta == ((**i).getNumero())) {
			shared_ptr<Movimentacao> movimentacao = make_shared<Movimentacao>("Saque", valor, debito);
			if((**i).getStatus() == true) {
				if(valor <= 0){
					cout << "Nao é realizar saques de valores negativos ou nulo." << endl;
					return;
				}
				else if(valor <= (**i).getSaldo()) {
					cout << "Saque realizado..." << endl;
					(**i).setSaldo((**i).getSaldo()-valor);
					(**i).setMovimentacoes(movimentacao);
					return;
				}
				else if(valor > (**i).getSaldo() && valor <= ((**i).getSaldo() + (**i).getLimiteDisp())) {
					cout << "Saque realizado..." << endl;
					cout << "Limite: " << (**i).getLimiteDisp() << endl;
					cout << "saldo: " << (**i).getSaldo() << endl;
					(**i).setLimiteDisp((**i).getLimiteDisp() - (valor-(**i).getSaldo()));
					cout << "Limite: " << (**i).getLimite() << endl;
					(**i).setSaldo(0);
					cout << "Limite: " << (**i).getLimiteDisp() << endl;

					(**i).setMovimentacoes(movimentacao);
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
				else if(valor <= (**i).getSaldo()) {
					cout << "Saque realizado..." << endl;
					(**i).setSaldo((**i).getSaldo()-valor);
					(**i).setMovimentacoes(movimentacao);
					return;
				}
				else  {
					cout << "Nao foi possivel sacar, valor do saque eh maior que o saldo." << endl;
					return;
				}
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
		if(numeroConta == ((**i).getNumero())) {
			shared_ptr<Movimentacao> movimentacao = make_shared<Movimentacao>("Desposito", valor, credito);
			cout << "aaa" << endl;
			if((**i).getStatus() == true) {
				cout << "eiii" << endl;
				if(valor <= 0) {
					cout << "Nao é realizar Desposito de valores negativos ou nulo." << endl;
					return;
				}
				else if((**i).getSaldo() > 0) {
					cout << "Desposito realizado..." << endl;
					(**i).setSaldo((**i).getSaldo()+valor);
					(**i).setMovimentacoes(movimentacao);
					return;
				}
				else if((**i).getSaldo() == 0 && valor >= (**i).getLimite()) {
					cout << "Desposito realizado..." << endl;
					float aux = (**i).getLimite() - (**i).getLimiteDisp();
					(**i).setLimiteDisp((**i).getLimiteDisp() + aux);
					cout << "valor: " << valor << endl;
					cout << "aux: " << aux << endl;
					(**i).setSaldo(valor-aux);
					(**i).setMovimentacoes(movimentacao);
					return;
				}
				else if((**i).getSaldo() == 0 && valor < (**i).getLimite()) {
					if(valor > ((**i).getLimite() - (**i).getLimiteDisp())) {
						cout << "Desposito realizado..." << endl;
						float aux = (**i).getLimite() - (**i).getLimiteDisp();
						(**i).setLimiteDisp((**i).getLimiteDisp() + aux);
						(**i).setSaldo(valor-aux);
						(**i).setMovimentacoes(movimentacao);
					}
					else if(valor < ((**i).getLimite() - (**i).getLimiteDisp())) {
						cout << "Desposito realizado..." << endl;
						(**i).setLimiteDisp((**i).getLimiteDisp() + valor);
						(**i).setMovimentacoes(movimentacao);
						return;
					}
				}
			}
			else if((**i).getStatus() == false) {
				if(valor <= 0) {
					cout << "Nao é realizar Desposito de valores negativos ou nulo." << endl;
					return;
				}
				else {
					cout << "Desposito realizado..." << endl;
					(**i).setSaldo((**i).getSaldo()+valor);
					(**i).setMovimentacoes(movimentacao);
					return;
				}
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
		if(numeroConta1 == ((**i).getNumero())) {
			shared_ptr<Movimentacao> movimentacao1 = make_shared<Movimentacao>("Trasferencia", valor, debito);
			shared_ptr<Movimentacao> movimentacao2 = make_shared<Movimentacao>("Trasferencia", valor, credito);
			if((**i).getStatus() == true) {
				if(valor <= 0) {
					cout << "Nao é realizar Trasferencias de valores negativos ou nulo." << endl;
				}
				else if(valor <= (**i).getSaldo()) {
					for(auto j = contas.begin(); j != contas.end(); j++) {
						if(numeroConta2 == ((**j).getNumero())) {
							if((**i).getStatus() == true) {
								if((**j).getSaldo() > 0) {
									cout << "Trasferencia realizada..." << endl;
									(**i).setSaldo((**i).getSaldo() - valor);
									(**j).setSaldo((**i).getSaldo() + valor);
									(**i).setMovimentacoes(movimentacao1);
									(**j).setMovimentacoes(movimentacao2);
									return;
								}
								else if((**j).getSaldo() == 0 && valor >= (**j).getLimite()) {
									cout << "Trasferencia realizada..." << endl;
									(**i).setSaldo((**i).getSaldo() - valor);
									float aux = (**j).getLimite() - (**j).getLimiteDisp();
									(**j).setLimiteDisp((**i).getLimiteDisp() + aux);
									(**j).setSaldo(valor-aux);
									(**i).setMovimentacoes(movimentacao1);
									(**j).setMovimentacoes(movimentacao2);
									return;
								}
								else if((**j).getSaldo() == 0 && valor < (**j).getLimite()) {
									if(valor > ((**j).getLimite() - (**j).getLimiteDisp())) {
										cout << "Trasferencia realizada..." << endl;
										(**i).setSaldo((**i).getSaldo() - valor);
										float aux = (**j).getLimite() - (**j).getLimiteDisp();
										(**j).setLimiteDisp((**j).getLimiteDisp() + aux);
										(**j).setSaldo(valor-aux);
										(**i).setMovimentacoes(movimentacao1);
										(**j).setMovimentacoes(movimentacao2);
										return;
									}
									else if(valor < ((**j).getLimite() - (**j).getLimiteDisp())) {
										cout << "Trasferencia realizada..." << endl;
										(**i).setSaldo((**i).getSaldo() - valor);
										(**j).setLimiteDisp((**j).getLimiteDisp() + valor);
										(**i).setMovimentacoes(movimentacao1);
										(**j).setMovimentacoes(movimentacao2);
										return;
									}
								}
							}
							else {
								cout << "Trasferencia realizada..." << endl;
								(**i).setSaldo((**i).getSaldo() - valor);
								(**j).setSaldo((**j).getSaldo()+valor);
								(**i).setMovimentacoes(movimentacao1);
								(**j).setMovimentacoes(movimentacao2);
								return;
							}
						}
					}
					cout << "Erro, conta 2 inexistente" << endl;
					return;
				}
				else if(valor > (**i).getSaldo() && valor <= ((**i).getSaldo() + (**i).getLimiteDisp())) {
					for(auto j = contas.begin(); j != contas.end(); j++) {
						if(numeroConta2 == ((**j).getNumero())) {
							if((**i).getStatus() == true) {
								if((**j).getSaldo() > 0) {
									cout << "Trasferencia realizada..." << endl;
									(**i).setLimiteDisp((**i).getLimiteDisp() - (valor-(**i).getSaldo()));
									(**j).setSaldo((**j).getSaldo() + valor);
									(**i).setSaldo(0);
									(**i).setMovimentacoes(movimentacao1);
									(**j).setMovimentacoes(movimentacao2);
									return;
								}
								else if((**j).getSaldo() == 0 && valor >= (**j).getLimite()) {
									cout << "Trasferencia realizada..." << endl;
									(**i).setLimiteDisp((**i).getLimiteDisp() - (valor-(**i).getSaldo()));
									float aux = (**j).getLimite() - (**j).getLimiteDisp();
									(**j).setLimiteDisp((**j).getLimiteDisp() + aux);
									(**j).setSaldo(valor-aux);
									(**i).setSaldo(0);
									(**i).setMovimentacoes(movimentacao1);
									(**j).setMovimentacoes(movimentacao2);
									return;
								}
								else if((**j).getSaldo() == 0 && valor < (**j).getLimite()) {
									if(valor > ((**j).getLimite() - (**j).getLimiteDisp())) {
										cout << "Trasferencia realizada..." << endl;
										(**i).setLimiteDisp((**i).getLimiteDisp() - (valor-(**i).getSaldo()));
										float aux = (**j).getLimite() - (**j).getLimiteDisp();
										(**j).setSaldo((**j).getSaldo() + aux);
										(**j).setLimiteDisp((**j).getLimiteDisp() + aux);
										(**j).setSaldo(valor-aux);
										(**i).setSaldo(0);
										(**i).setMovimentacoes(movimentacao1);
										(**j).setMovimentacoes(movimentacao2);
										return;
									}
									else if(valor < ((**j).getLimite() - (**j).getLimiteDisp())) {
										cout << "Trasferencia realizada..." << endl;
										(**i).setLimiteDisp((**i).getLimiteDisp() - (valor-(**i).getSaldo()));
										(**j).setLimiteDisp((**j).getLimiteDisp() + valor);
										(**i).setSaldo(0);
										(**i).setMovimentacoes(movimentacao1);
										(**j).setMovimentacoes(movimentacao2);
										return;
									}
								}
							}
							else {
								cout << "Trasferencia realizada..." << endl;
								(**i).setLimiteDisp((**i).getLimiteDisp() - (valor-(**i).getSaldo()));
								(**j).setSaldo( (**j).getSaldo() + valor);
								(**i).setSaldo(0);
								(**i).setMovimentacoes(movimentacao1);
								(**j).setMovimentacoes(movimentacao2);
								return;
							}
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
						if((**j).getStatus() == true) {
							if((**j).getSaldo() > 0) {
								cout << "Trasferencia realizada..." << endl;
								(**i).setSaldo((**i).getSaldo() - valor);
								(**j).setSaldo((**i).getSaldo() + valor);
								(**i).setMovimentacoes(movimentacao1);
								(**j).setMovimentacoes(movimentacao2);
								return;
							}
							else if((**j).getSaldo() == 0 && valor >= (**j).getLimite()) {
								cout << "Trasferencia realizada..." << endl;
								(**i).setSaldo((**i).getSaldo() - valor);
								(**j).setSaldo((**i).getSaldo() + valor);
								float aux = (**j).getLimite() - (**j).getLimiteDisp();
								(**j).setLimiteDisp((**i).getLimiteDisp() + aux);
								(**j).setSaldo(valor-aux);
								(**i).setMovimentacoes(movimentacao1);
								(**j).setMovimentacoes(movimentacao2);
								return;
							}
							else if((**j).getSaldo() == 0 && valor < (**j).getLimite()) {
								if(valor > ((**j).getLimite() - (**j).getLimiteDisp())) {
									cout << "Trasferencia realizada..." << endl;
									(**i).setSaldo((**i).getSaldo() - valor);
									(**j).setSaldo((**i).getSaldo() + valor);
									float aux = (**j).getLimite() - (**j).getLimiteDisp();
									(**j).setLimiteDisp((**j).getLimiteDisp() + aux);
									(**j).setSaldo(valor-aux);
									(**i).setMovimentacoes(movimentacao1);
									(**j).setMovimentacoes(movimentacao2);
									return;
								}
								else if(valor < ((**j).getLimite() - (**j).getLimiteDisp())) {
									cout << "Trasferencia realizada..." << endl;
									(**i).setSaldo((**i).getSaldo() - valor);
									(**j).setSaldo((**i).getSaldo() + valor);
									(**j).setLimiteDisp((**j).getLimiteDisp() + valor);
									(**i).setMovimentacoes(movimentacao1);
									(**j).setMovimentacoes(movimentacao2);
									return;
								}
							}
						}
						else {
							cout << "Trasferencia realizada..." << endl;
							(**i).setSaldo((**i).getSaldo() - valor);
							(**j).setSaldo((**j).getSaldo()+valor);
							(**i).setMovimentacoes(movimentacao1);
							(**j).setMovimentacoes(movimentacao2);
							return;
						}
					}
				}
				else {
					cout << "Nao foi possivel sacar, valor do saque eh maior que o saldo." << endl;
					return;
				}
			}
		}
	}
	cout << "Erro conta1 inexistente." << endl;
}

/** @param numeroConta Numero da conta */
void Agencia::imitirSaldo(string numeroConta) {
	int cont = 0;
	for(auto i = contas.begin(); i != contas.end(); i++) {
		if(numeroConta == ((**i).getNumero())) {
			cout << "Saldo = " << (**i).getSaldo() << endl;
			cont++;
		}
	}
}
