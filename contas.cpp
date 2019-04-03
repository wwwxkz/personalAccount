#include "pch.h"
#include <iostream>
using namespace std;

// VARS --------------------------------------------------------------------------------------------------------
// OPERAÇÕES GERAIS
int total = 0;
// CONTA 1
int corrente = 0;
int gastos = 0;
// CONTA 2
int poupanca = 0;


// FUNÇÕES -----------------------------------------------------------------------------------------------------
// FUNÇÃO DE DEPOSITO
void deposito(int valueDeposited)
{
	// divide o valor nas contas conforme determinado
	poupanca += valueDeposited * 20 / 100;
	valueDeposited = valueDeposited - valueDeposited * 20 / 100;

	corrente += valueDeposited;
	valueDeposited = 0;
}

// FUNÇÃO DE SALARIO
void salario(int valueSalario)
{
	// divide o valor nas contas conforme determinado
	gastos += 400;
	valueSalario = valueSalario - 400;

	poupanca += valueSalario * 20 / 100;
	valueSalario = valueSalario - valueSalario * 20 / 100;

	corrente += valueSalario;
	valueSalario = 0;
}

// FUNÇÃO DE RETIRADA
void retirada(int valueQueSeraRetirado)
{}

// FUNÇÃO DE TRANSFERENCIA
void transferencia(int valueTransf, int de, int para)
{}

// MAIN -------------------------------------------------------------------------------------------------------
int main()
{
	// MENU
	int ur;
	while(true)
	{
		cout << "\n\n MENU \n 1 deposito \n 2 retirada \n 3 transferencia \n 4 total \n 5 corrente \n 6 salario \n :: ";
		cin >> ur;

		if(ur == 1)
		{
			int rdeposito;
			cout << "Qual o valor que sera depositado: ";
			cin >> rdeposito;
			deposito(rdeposito);
		}
		if (ur == 2)
		{
			int rretirada;
			cout << "Qual o valor da retirada: ";
			cin >> rretirada;
			retirada(rretirada);
		}
		if (ur == 3) 
		{
			int rtransferencia;
			int rdaconta;
			int rparaconta;
			cout << "Qual o valor da transferencia: ";
			cin >> rtransferencia;
			cout << "De qual conta o valor sera retirado: ";
			cin >> rdaconta;
			cout << "Para qual conta o valor sera enviado: ";
			cin >> rparaconta;
			transferencia(rtransferencia, rdaconta, rparaconta);
		}
		if (ur == 4) 
		{
			int rtotal = corrente + poupanca + gastos;
			cout << "Corrente: " << corrente << " Poupanca: " << poupanca << " Gastos: " << gastos << "\nTotal: " << rtotal;
		}
		if (ur == 5) 
		{
			cout << "Conta corrente: " << corrente;
		}
		if (ur == 6)
		{
			int rsalario;
			cout << "Valor do salario recebido: ";
			cin >> rsalario;
			salario(rsalario);
		}
	}

}

