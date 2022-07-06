#include <stdio.h>
#include <string.h>
#include <stdlib.h>    
#include <locale.h>
#include <windows.h>

//ESTRUTURA DO SISTEMA 
typedef struct{
    int codigo;
    char nome[30];   
}Produto;

//VARIÁVEIS UTILIZADAS  
int opcao;
static int entradaProduto = 0;
static Produto produtos[50];      
static int codigoProduto = 0;  

//PRÓTOIPO DA FUNÇÃO UTILIZADA
void cadastro();
void listar();
void excluir();
void editar();
void layout();


int main(){
    setlocale(LC_ALL,"Portuguese");
    
    int menu_nav;
	//MENU DE NAVEGAÇÃO 
    do{
       	
		layout();
		
		printf("\t\t\t\t\t\t=========================");
        printf("\n\t\t\t\t\t\t|  CONTROLE DE ESTOQUE  |\n");
        printf("\t\t\t\t\t\t=========================\n\n");
        
        printf("\t\t\t1 - CADASTRAR PRODUTO\n");
        printf("\t\t\t2 - LISTAR PRODUTO\n");
        printf("\t\t\t3 - EXCLUIR PRODUTO\n");
        printf("\t\t\t4 - EDITAR PRODUTO\n");
        printf("\t\t\t5 - SAIR \n");
        printf("\n\n\t\t\tOPCAO: ");
        scanf("%d", &opcao);
      	system("cls");
	   	getchar();
        
        
        //COMANDO DE ESCOLHA COM SWITCH CASE
        switch(opcao){
        	
            case 1:
            	layout();
            	cadastro();
            	system("cls");
              break;
            case 2:
            	layout();
              	listar();
              	break;
            case 3:
            	layout();
              	excluir();
              	break;
            case 4:
            	layout();
              	editar();
              	break;  	
            case 5:
            	layout();	
              	printf("\t\t\t \t\t   OBRIGADO, E VOLTE SEMPRE!\n\n \t \t\t\t\t\tCRUD CRIADO POR:\n \t\t\t\t\t\ --> EDIVAN SILVA\n\t\t\t\t\t --> GUILHERME BARATA. \n");
              	sleep (3);
              	exit (0);
            default:
            	layout();
              	printf ("\t\t\t\t\t\t OPCAO INVALIDA.\n\n");
              	sleep (0);
              	break;
        }
        
        
    }while(menu_nav != 5);

}

//FUNÇÕES UTILIZADAS   
void layout(){
	printf("\t\t\t===================================================================\n");
    printf("\t\t\t|\t\t\t SUPERMERCADO TEM DE NADA   \t\t  |\n");
    printf("\t\t\t===================================================================\n\n");
}
//FUNÇÃO PARA CADASTRAR PRODUTOS
void cadastro(){
	printf("\t\t\t\t\t\t#########################\n");
	printf ("\t\t\t\t\t\t#  CADASTRO DE PRODUTO  #\n");
    printf("\t\t\t\t\t\t#########################\n");
    
    printf("\t\t\tNOME DO PRODUTO: ");
    fgets(produtos[entradaProduto].nome, 30, stdin);
    
    printf("\t\t\tPRODUTO CADASTRADO.\n");
    produtos[entradaProduto].codigo = (codigoProduto + 1);
    entradaProduto++;
    codigoProduto++;
    
    sleep(1);
    system("cls");
}
//FUNÇÃO PARA MOSTRAR OS PRODUTOS CADASTRADOS
void listar(){
		
    if (entradaProduto > 0){
    	printf("\t\t\t\t\t\t#####################\n");
        printf("\t\t\t\t\t\t# LISTA DE PRODUTOS #\n");
        printf("\t\t\t\t\t\t#####################\n");
        int i;
        for(i = 0; i < entradaProduto; i++){
        	printf("\t\t\t_____________________________\n\n");
            printf("\t\t\t\t CODIGO: %i\t\t\n",produtos[i].codigo);
            printf("\t\t\t\t NOME: %s \t\t\n",produtos[i].nome);
            printf("\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            sleep (1);
        }
      sleep(1);

    }
    else{
        printf("\t\t\t\t\t AINDA NÃO TEMOS PRODUTOS CADASTRADOS.\n\n");
        sleep(1);
        
    }
   
}
//FUNÇÃO UTILIZADA PARA ECLUIR UM INTEM CADASTRADO
void excluir(){
    printf("\t\t\t\t\t\t#####################\n");
    printf("\t\t\t\t\t\t#  EXCLUIR PRODUTO #\n\n");
    printf("\t\t\t\t\t\t#####################\n");
    
    int codigo, i;
    printf("\t\t\t\tDIGITE O CODIGO DO PRODUTO QUE DESEJA EXCLUIR: \n");
    scanf("%d", &codigo);
    
    for(i = 0; i < entradaProduto; i++){
        if (produtos[i].codigo == codigo){
	            produtos[i] = produtos[i + 1];
	            produtos[i - 1];
	            entradaProduto--;
	            printf ("\n\t\t\t\tO PRODUTO %d FOI APAGADO\n", codigo);
            	sleep (1);
            
       	 }
    }
    
    printf("\t\t\t\tPRODUTO NAO ENCONTRADO\n");
    sleep(1);

}
//FUNÇÃO UTILIZADA PARA EDITAR UM PRODUTO CADASTRADO
void editar(){
	printf("\t\t\t\t\t\t######################\n");
	printf("\t\t\t\t\t\t#   EDITAR PRODUTO   #\n");
	printf("\t\t\t\t\t\t######################\n\n");
    int codigo, i; 
    printf("\t\t\t\t INFORME O CODIGO DO PRODUTO PARA SER EDITADO: ");
    scanf("%d", &codigo);
    
    for(i = 0; i < entradaProduto; i++){
        if(produtos[i].codigo == codigo){
            printf("\t\t\tINFORME O NOVO NOME DO PRODUTO: ");
            setbuf(stdin,0);
            fgets(produtos[i].nome,30,stdin);
            printf("\t\t\tPRODUTO EDITADO COM SUCESSO!\n");
            sleep(1);
            main();
        }
    }
    
    printf("\t\t\t\tPRODUTO NAO ENCONTRADO\n");
    sleep(1);

}


