#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

typedef struct{
    char nome[50];
    int codigo;
    char cpf[20];
    char email[50];
    char dataNascimento[20];
    char dataCadastro[20];

}Cliente;

typedef struct{
    int numero;
    Cliente cliente;
     int saldo;
     int limite;
     int saldoTotal;
}Conta;


void menu();
void infoCliente(Cliente cliente);
void infoConta(Conta conta);
void criarConta();
void efetuarSaque();
void efetuarDeposito();
void efetuarTansferencia();
void listarContas();
void atualizaSaldoTotal(Conta conta);
void buscarContaPorNumero(int numero);
void sacar(Conta conta, float valor);
void depositar(Conta conta, float valor);
void transferir(Conta conta_origem, Conta conta_destino, float valor);

static contador_contas=0;
static contador_clientes=0;
static Conta contas[50];

int main(){
    menu();

    return 0;
}

void menu(){

}
void infoCliente(Cliente cliente){

}
void infoConta(Conta conta){

}
void criarConta(){

}
void efetuarSaque(){

}
void efetuarDeposito(){

}
void efetuarTansferencia(){

}
void listarContas(){

}
void atualizaSaldoTotal(Conta conta){

}
void buscarContaPorNumero(int numero){

}
void sacar(Conta conta, float valor){

}
void depositar(Conta conta, float valor){

}
void transferir(Conta conta_origem, Conta conta_destino, float valor){

}


