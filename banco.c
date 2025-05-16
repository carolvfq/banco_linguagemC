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
float atualizaSaldoTotal(Conta conta);
Conta buscarContaPorNumero(int numero);
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
    printf("---------------------------------");
    printf("--------------BANCO--------------");
    printf("---------------------------------");
    printf("escolha uma das opçoes:");
    printf("1-Criar conta\n");
    printf("2-Efetuar saque\n");
    printf("3-Efetuar deposito\n");
    printf("4-Efetuar transferencia\n");
    printf("5-Listar contas\n");
    printf("6-Sair do sistema\n");
    
    int opcoes;
    scanf("%d",&opcoes);
    getchar();
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
    case 6:
        listarContas();
        Sleep(2000);
        exit(0);
        menu();
        break;  
        
    default:
    printf("opcao invalida.\n");
        Sleep(2000);
        break;
    }

}
void infoCliente(Cliente cliente){
    printf("Nome: %s\n Codigo:%d\n CPF:  %s\n email:%s\n Data de nascimento %s\n Data do cadastro: %s\n", cliente.nome, cliente.codigo, cliente.cpf, cliente.email,cliente.dataNascimento,cliente.dataCadastro );
}
void infoConta(Conta conta){
    printf("Nome:%s\n CPF:%s\nNumero:%d\n Saldo:%d\n Limite:%d\n  Saldo Total:%d\n",conta.cliente.nome,conta.cliente.cpf,conta.numero,conta.saldo,conta.saldoTotal);

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
float atualizaSaldoTotal(Conta conta){
    return conta.saldo + conta.limite;

}
Conta buscarContaPorNumero(int numero){
     Conta C;
    if(contador_contas>0){
        for(int i=0 ; i < contador_contas;i++){
             if(contas[i].numero == numero){
                 C=contas[i];
             }
        }
    }
    return C;
}
void sacar(Conta conta, float valor){
    if(valor > 0 && conta.saldoTotal > 0){
        for(int i=0; i < contador_contas;i++){
            if(contas[i].numero ==conta.numero ){
                if(valor < contas[i].saldo){
                    contas[i].saldo=contas[i].saldo - valor;
                    contas[i].saldoTotal=atualizaSaldoTotal(contas[i]);
                    printf("saque realizado com sucesso!\n");
                }
                else{
                    float restante = contas[i].saldo - valor;
                    contas[i].limite= contas[i].limite + restante;
                    contas[i].saldo=0.0;
                    contas[i].saldoTotal=atualizaSaldoTotal(contas[i]);
                    printf("saque realizado com sucesso!\n");
                }

            }
        }
        

    }
    else{
        printf(" o Saque nao foi realizado");
    }

}
void depositar(Conta conta, float valor){

}
void transferir(Conta conta_origem, Conta conta_destino, float valor){

}


