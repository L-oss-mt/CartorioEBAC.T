#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o de memoria 
#include <locale.h> //biblioteca de aloca��o de texto por regi�o 
#include <string.h> //biblioteca responsasavel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usuarios no sistema 
{  
    //inicio cria��o de variaveis/string  
    char arquivo[40]; 
	char cpf[40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis/string
	
	printf("Digite o Cpf a ser cadastrado: "); //coletando informa��o do usuario
	scanf("%s",cpf); //%s refere-se a string
  
	strcpy(arquivo, cpf);//responsavel por c�piar os valores das string
	  
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salvo o valor da variavel 
	fclose(file);// fechar o arquivo
	    
	    file = fopen(arquivo, "a");
	    fprintf(file,",");
	    fclose(file);
	    
	    printf("Digite o nome a ser cadastrado: ");
	    scanf("%s",nome);
	    
	    file = fopen(arquivo, "a");
	    fprintf(file,nome);
	    fclose(file);
	    
	    file = fopen(arquivo, "a");
	    fprintf(file,",");
	    fclose(file);
	    
	    printf("Digite o sobrenome a ser cadastrado: ");
	    scanf("%s",sobrenome);
	    
	    file = fopen(arquivo, "a");
	    fprintf(file,sobrenome);
	    fclose(file);
	    
	    file = fopen(arquivo, "a");
	    fprintf(file,",");
	    fclose(file);
	    
	    printf("Digite o cargo a ser cadastrado: ");
	    scanf("%s",cargo);
	    
	    file = fopen(arquivo, "a");
	    fprintf(file,cargo);
	    fclose(file);
	    
	    system("pause");
	    
	    
}
	    

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //definindo Linguagem

	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s,", cpf);

	FILE *file;
	file = fopen(cpf,"r");

	if(file == NULL)	
	{
	    printf("Arquivo n�o localizado!.\n");
	}
		
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEsse s�o dos dados do usu�rio: ");
		printf("%s",conteudo);
		printf("\n\n");
	}	
	fclose(file);
	system("pause");
	
	}


int deletar()
{
	   char cpf [40];
	   
	    printf("Digite o CPF a ser deletado:\n");
	    scanf("%s", cpf);
	    
	    remove(cpf);
	    
	    FILE *file;
	    file = fopen(cpf, "r");
	    
	    if(file == NULL)
	    {
	    	printf("Usuario n�o cadastrado!.\n");
	    	system("pause");
		}
		
		fclose(file);
		system("pause");
		
		
		
}
        
int main ()
{

	  int opcao=0; //Difinindo as variaveis 
	  int x=1;
	  char senhadigitada[10]="a";
	
	  printf("\tCart�rio de Registro EBAC\t\n\n");
	  printf("Login do Adiminstrador!\n\nDigite sua senha:");
	  scanf("%s",senhadigitada);
	
	 if(senhadigitada[10] == "admin")
     {
	
	    for(laco=1;laco=1;)
	    {
			
	          setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem 
	
	          printf("\tCart�rio de Registro EBAC\t\n\n"); //inicio do menu
	          printf("Escolha a Op��o Desejada:\n\n");
	          printf("\t1 - Cadastro de Nomes\n\n");
	          printf("\t2 - Consulta de Nomes\n\n");
	          printf("\t3 - Deletar Nomes\n\n");
	          printf("\t4 - Sair do Sistema\n\n");
	          printf("Op��o: "); //fim do menu 
	      
	
	          scanf("%D", &opcao); //Armazenando a escolha do usu�rio 
	
	          system("cls");
	      
	          switch(opcao)
	       {
	    	     case 1: 
	             registro();
	             break;
		    
		         case 2:
		         consulta();
	          	 break;
	      	
	      	     case 3:
	      	     deletar();
		         break;
		    
		         case 4:
		         printf("Obrigado por utilizar o sistema!\n");
	      	     return 0;
		         break;
		    
		         default:
		         printf("Est� op��o n�o est� disponivel\n");
		         system("pause");
		         break;
		   } //fim da sele��o
       } 
     }

    else
        printf("Senhra incorreta!");
}
