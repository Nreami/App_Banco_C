#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

    //Caio Vinicius Freire Pereira 20220623
    //Maria Eduarda Menuzzo 20230848
    //Nathan Phelipe Gimenes Pinto 20231436
    //Nicollas Reami 20230868

void login(){
    const char login1[50] = "pipoca";   //cria a string constante login1 e a da o valor "pipoca"
    const int senha  = 1609;    //cria a constante inteira senha e a da o valor 1609
    char login2[50];    //cria a variavel string login2
    int senha2; //cria a variavel inteira senha2
    printf("Digite seu login\n");   //pede ao usuario que digite seu login
    scanf("%s", &login2);   //le o login do usuário e o armazena na variavel login2
    printf("Digite sua senha\n");   //pede que o usuario informe sua senha
    scanf("%d", &senha2);   //le a senha informada pelo usuario e a armazena na variavel senha2
    if(strcmp(login1,login2) != 0 || senha != senha2){  //compara o login2 com a constante login e a senha2 com a constante senha, caso o login ou a senha estejam diferentes, o programa é encerrado
        printf("Login ou senha incorreto!\n"); //informa ao usuario que esta incorreto
        exit(1);    //finaliza o programa
    }else if(strcmp(login1, login2) == 0 && senha == senha2){   //compara o login2 com a constante login e a senha2 com a constante senha, caso o login e a senha estejam de acordo, o programa segue sendo executado
        printf("Logado na conta!\n");   //informa ao usuario que ele está logado na conta
    }
}

int main(){
    int i = 0;  //variavel criada para que o "while" seja finalizado caso o usuário digite "5"
    login();            //puxa a função de login criada logo acima
    float depositou,retirado, investimento, rmensal, conta, saque, saldo;  //variáveis utilizadas no programa
    int menu;   //variável utilizada para que seja o menu no switch case
    while (i==0){   //while utilizado para dar continuidade no programa e fazer com que ele seja finalizado caso o usuário deseje
        printf("\nMenu\n1. Deposito\n2. Saque\n3. Saldo\n4. Calculadora de investimento\n5. Sair\n");   //opções do menu
        scanf("%d", &menu); //le a escolha do usuário
        switch (menu){  //switch case utilizado para determinar o que o usuario deseja
            case 1: //caso o usuario digite 1..
                printf("Digite o valor que deseja depositar em sua conta: ");   //perguntar o valor que o usuario deseja depositar
                scanf("%f", &depositou);    //le o valor que o usuario deseja depositar
                printf("Foi adicionado %.2f em sua conta.\n", depositou);   //comunica ao usuario o valor depositado
                saldo = saldo + depositou;  //comando utilizado para atualizar o valor de saldo
                break; //finaliza o case 1
            case 2: //caso o usuario digite 2...
                printf("Digite o valor que deseja retirar de sua conta: "); //pergunta ao usuario o valor que ele deseja retirar da conta
                scanf("%f", &retirado); //le o valor que o usuario deseja retirar
                if(retirado > saldo){ //caso o valor que o usuario deseja retirar seja menor do que ele tem em saldo dar erro
                    printf("Nao foi possivel realizar esta operacao. Saldo menor que valor que deseja retirar.\n");
                    continue;
                }
                saldo -= retirado; //comando utilizado para atualizar o valor de saldo
                printf("Foi sacado %.2f de sua conta.\n", retirado); //informa ao usuario o valor que foi retirado
                break;  //finaliza o case 2
            case 3: //caso o usuario digite 3...
                printf("O usuario tem %.2f em sua conta.\n", saldo); //informa ao usuario o valor existente na conta
                break;  //finaliza o case 3
            case 4: //caso o usuário digite 4...
                printf("Digite o investimento: ");  //pergunta ao usuario o valor a ser investido
                scanf("%f", &investimento); //le o valor a ser investido
                printf("Digite a rentabilidade mensal em %: "); //pergunta ao usuario qual sera a rentabilidade mensal
                scanf("%f", &rmensal);  //le qual sera a rentabilidade mensal
                printf("Retorno mensal $: %.2f\n", investimento * (rmensal*1.0e-2)); //informa ao usuario o retorno mensal
                printf("Retorno anual $: %.2f\n", (investimento * (rmensal*1.0e-2))*12);    //inroma ao usuario o retorno anual
                printf("Total investido : %.2f / Rentabilidade: %.2f / Total: %.2f\n", investimento, (investimento * (rmensal*1.0e-2))*12, investimento + (investimento * (rmensal*1.0e-2))*12);    //retorna ao usuario o total investido, a rentabilidade e o total
                break;  //finaliza o case 4
            case 5: //caso o usuario digite 5...
                i++;    //é adicionado +1 a variável i e o programa é encerrado
                break;  //finaliza case 5
            default:    //caso o usuario escolha uma opção não existente
                printf("Opcao invalida. Tente novamente.\n"); //caso usuário escolha uma opção diferente das disponibilizadas aparece esta mensagem
        }
    }
    return 0;   //retorna caso tenha ocorrido algum erro durante o programa é executado
}
