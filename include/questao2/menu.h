/**
 * @file	menu.h
 * @brief	arquivo de cabecalho com as definicoes das funcoes
 *			para manipulacao do menu de uma agencia
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	26/10/2017
 * @data	27/10/2017
 */

#ifndef MENU_H
#define MENU_H


/** 
 * @brief Menu para criacao de uma conta
 * @param agencia Agencia  
 */ 
void menuCriarConta(Agencia& agencia);

/** 
 * @brief Funcao para remocao de uma conta
 * @param agencia Agencia  
 */ 
void menuRemoverConta(Agencia& agencia);

/** 
 * @brief Funcao para saque em uma conta
 * @param agencia Agencia  
 */ 
void menuSaque(Agencia& agencia);

/** 
 * @brief Funcao para deposito em uma conta
 * @param agencia Agencia  
 */ 
void menuDeposito(Agencia& agencia);

/** 
 * @brief Funcao para transferencia entre duas contas
 * @param agencia Agencia  
 */ 
void menuTransferencia(Agencia& agencia);

/** 
 * @brief Funcao para emissao do saldo de uma conta
 * @param agencia Agencia  
 */ 
void menuEmitirSaldo(Agencia& agencia);

/** 
 * @brief Funcao para emissao do extrato de uma conta
 * @param agencia Agencia  
 */ 
void menuExtrato(Agencia& agencia);

#endif