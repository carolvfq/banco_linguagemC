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
     float saldo;
     float limite;
     float saldoTotal;
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

static int contador_contas=0;
static int contador_clientes=0;
static Conta contas[50];

int main(){
    menu();

    return 0;
}

void menu(){
    printf("---------------------------------\n");
    printf("--------------BANCO--------------\n");
    printf("---------------------------------\n");
    printf("escolha uma das opçoes:\n");
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
    printf("Nome:%s\n CPF:%s\nNumero:%d\n Saldo:%f\n Limite:%f\n  Saldo Total:%f\n",conta.cliente.nome,conta.cliente.cpf,conta.numero,conta.saldo,conta.limite,conta.saldoTotal);

}
void criarConta(){
 Cliente cliente;
 char dia[3];
 char mes[3];
 char ano[3];
 char data_cadastro[20];
 time_t t = time(NULL);
struct tm tm = *localtime(&t);
    // dia
   if(tm.tm_mday <10){
    sprintf(dia, "0%d", tm.tm_mday);

 }
   else{
    sprintf(dia, "%d", tm.tm_mday);
   }

   //mês
   if((tm.tm_mon +1)< 10){
    sprintf(dia, "0%d", tm.tm_mon + 1);
   }

   else{
    sprintf(dia, "%d", tm.tm_mon + 1);
   }
   //ano
   sprintf(dia, "%d", tm.tm_year + 1900); //pq a biblioteca diminui 1900 do ano , então precisa repor

  // concatenar tudo

  strcpy(data_cadastro,"");
  strcat(data_cadastro, "/");
  strcat(data_cadastro, mes);
  strcat(data_cadastro, "/");
  strcat(data_cadastro, ano);
  strcat(data_cadastro, "\0");
  strcpy(cliente.dataCadastro, data_cadastro);


 //criar conta 

 contas[contador_contas].numero= contador_contas + 1;
 contas[contador_contas].cliente=cliente;
 contas[contador_contas].saldo=0.0;
 contas[contador_contas].limite=0.0;
 contas[contador_contas].saldoTotal= 0.0;
 contador_contas++;

 Sleep(4000);

 printf("Informe os dados do cliente:\n");
 cliente.codigo= contador_clientes + 1;

 printf("Nome do cliente:");
 fgets(cliente.nome,50,stdin);

 printf("CPF:");
 fgets(cliente.cpf,20,stdin);


 printf("Email:");
 fgets(cliente.email,50,stdin);


 printf("Data de nascimento:");
 fgets(cliente.dataNascimento,20,stdin);

 contador_clientes ++;

}
void efetuarSaque() {
    if (contador_contas > 0) {
        int numero;
        printf("Digite o numero da conta: ");
        scanf("%d", &numero);

        Conta conta = buscarContaPorNumero(numero);

        if (conta.numero == numero) {
            float valor;
            printf("Informe o valor do saque: ");
            scanf("%f", &valor);  

            sacar(conta, valor);
        } else {
            printf("Conta nao encontrada\n");
        }
    } else {
        printf("Ainda não há nenhuma conta criada\n");
    }

    Sleep(2000);
    menu();
}

void efetuarDeposito(){
if (contador_contas > 0) {
        int numero;
        printf("Digite o numero da conta: ");
        scanf("%d", &numero);

        Conta conta = buscarContaPorNumero(numero);

        if (conta.numero == numero) {
            float valor;
            printf("Informe o valor para deposito: ");
            scanf("%f", &valor);  

            depositar(conta, valor);
        } else {
            printf("Conta nao encontrada\n");
        }
    } else {
        printf("Ainda não há nenhuma conta criada\n");
    }

    Sleep(2000);
    menu();

}
void efetuarTansferencia() {
    if (contador_contas > 0) {
        int numero_o;
        int numero_d;
        printf("Digite o numero da sua conta:\n");
        scanf("%d", &numero_o);

        Conta conta_o = buscarContaPorNumero(numero_o);

        if (conta_o.numero == numero_o) {
            printf("Digite o numero da conta destino:\n");
            scanf("%d", &numero_d);

            Conta conta_d = buscarContaPorNumero(numero_d);

            if (conta_d.numero == numero_d) {
                float valor;
                printf("Informe o valor para a transferencia: ");
                scanf("%f", &valor);

                transferir(conta_o, conta_d, valor);
            } else {
                printf("A conta destino nao foi encontrada\n");
            }
        } else {
            printf("A sua conta nao foi encontrada\n");
        }
    } else {
        printf("Ainda não há nenhuma conta criada\n");
    }

    Sleep(2000);
    menu();
}

void listarContas(){
    if(contador_contas> 0){
        for(int i = 0 ; i < contador_contas; i++){
        infoConta(contas[i]);
        printf("\n");
        Sleep(1000);
        }

}
else{ 
 printf("Ainda não há nenhuma conta criada\n");
}

Sleep(2000);
menu();
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
    if(valor > 0 && conta.saldoTotal >= valor){
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
    if(valor > 0 ){
        for(int i=0; i < contador_contas;i++){
            if(contas[i].numero ==conta.numero ){
                contas[i].saldo= contas[i].saldo + valor;
                contas[i].saldoTotal=atualizaSaldoTotal(contas[i]);
                    printf("deposito realizado com sucesso!\n");
                
               
                }

            }
        }
    else{
        printf(" o Saque nao foi realizado");
    }
}

void transferir(Conta conta_origem, Conta conta_destino, float valor){
    if(valor > 0 && conta_origem.saldoTotal >= valor){
        for(int co=0; co< contador_contas;co++){
            if(contas[co].numero ==conta_origem.numero  ){
                for(int cd=0; cd < contador_contas;cd++){
                    if(contas[cd].numero ==conta_destino.numero ){
                        if(valor < contas[co].saldo){
                            contas[co].saldo=contas[co].saldo - valor;
                            contas[cd].saldo=contas[cd].saldo + valor;
                            contas[co].saldoTotal=atualizaSaldoTotal(contas[co]);
                            contas[cd].saldoTotal=atualizaSaldoTotal(contas[cd]);
                            printf("a transferencia foi  realizado com sucesso!\n");
                        }
                        else{
                            float restante = contas[co].saldo - valor;
                            contas[co].limite= contas[co].limite + restante;
                            contas[co].saldo=0.0;
                            contas[cd].saldo=contas[cd].saldo + valor;
                            contas[co].saldoTotal=atualizaSaldoTotal(contas[co]);
                            contas[cd].saldoTotal=atualizaSaldoTotal(contas[cd]);
                            printf("a transferencia foi  realizado com sucesso!\n");

                        }

                    
                    }

                }

            }


        }
    }
    else{
        printf("a transferencia nao foi realizada com sucesso\n");
    }
}













    