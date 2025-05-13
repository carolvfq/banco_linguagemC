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
    printf("escolha uma das opçoes:");
    printf("1-Criar conta:\n");
    printf("2-Efetuar saque:\n");
    printf("3-Efetuar deposito:\n");
    printf("4-Efetuar transferencia:\n");
    printf("5-Listar contas:\n");
    
    int opcoes;
    scanf("%d",&opcoes);
    
    switch (opcoes)
    {
    
    case 1:
        criarConta();
        break;
    case 2:
        efetuarSaque();
        break;
    case 3:
        efetuarDeposito();
        break;
    case 4:
        efetuarTansferencia();
        break; 
    case 5:
        listarContas();
        break;    
    
        
    default:
    printf("opcao invalida.\n");
        break;
    }

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


