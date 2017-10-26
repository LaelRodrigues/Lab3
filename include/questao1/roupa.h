/**
 * @file	roupa.h
 * @brief	Definicao da classe Roupa para representar uma roupa
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	25/10/2017
 * @data	25/10/2017
 */


#ifndef _ROUPA_H_
#define _ROUPA_H_

#include "produto.h"

/**
 * @class 	Roupa roupa.h
 * @brief	Classe que representa uma roupa
 * @details Atributos da roupa: codigo, descricao,
 *			preco, marca, sexo e tamanho
 */

class Roupa : public Produto
{
public:

	/** @brief Construtor padrao */
	Roupa();

	/** @brief Construtor parametrizado */
	Roupa(std::string _codigo, std::string _descricao, short _preco, 
			std::string _marca, char _sexo, std::string _tamanho);
	/** @brief Destrutor padrao */
	~Roupa();

private:

	std::string marca; 			/**< Marca da roupa */
	char sexo;					/**< Sexo da roupa */
	std::string tamanho;		/**< Tamanho da roupa*/

public:
	/** @brief Retorna a marca da roupa */
	std::string getMarca();

	/** @brief Retorna o sexo da roupa */
	char getSexo();

	/** @brief Retorna o tamanho da roupas */
	std::string getTamanho();
	
	/** @brief Modifica a marca da roupa */
	void setMarca(std::string _marca);

	/** @brief Modifica o sexo da roupa */
	void setSexo(char _sexo);

	/** @brief Modifica o tamanho da roupa */
	void setTamanho(std::string _tamanho);

private:
	/** @brief Metodo para imprimir os dados de uma bebida */
	std::ostream& print(std::ostream &o) const;
};

#endif