#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> //biblioteca de alocação de espaço de memoria 
#include <locale.h> //biblioteca de alocação de texto por região 
#include <string.h> //biblioteca responsasavel por cuidar das string

int registro() //Função responsavel por cadastrar os usuarios no sistema 
{  
    //inicio criação de variaveis/string  
    char arquivo[40]; 
	char cpf[40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis/string
	
	printf("Digite o Cpf a ser cadastrado: "); //coletando informação do usuario
	scanf("%s",cpf); //%s refere-se a string
  
	strcpy(arquivo, cpf);//responsavel por cópiar os valores das string
	  
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
	    printf("Arquivo não localizado!.\n");
	}
		
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEsse são dos dados do usuário: ");
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
	    	printf("Usuario não cadastrado!.\n");
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
	
	  printf("\tCartório de Registro EBAC\t\n\n");
	  printf("Login do Adiminstrador!\n\nDigite sua senha:");
	  scanf("%s",senhadigitada);
	
	 if(senhadigitada[10] == "admin")
     {
	
	    for(laco=1;laco=1;)
	    {
			
	          setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem 
	
	          printf("\tCartório de Registro EBAC\t\n\n"); //inicio do menu
	          printf("Escolha a Opção Desejada:\n\n");
	          printf("\t1 - Cadastro de Nomes\n\n");
	          printf("\t2 - Consulta de Nomes\n\n");
	          printf("\t3 - Deletar Nomes\n\n");
	          printf("\t4 - Sair do Sistema\n\n");
	          printf("Opção: "); //fim do menu 
	      
	
	          scanf("%D", &opcao); //Armazenando a escolha do usuário 
	
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
		         printf("Está opção não está disponivel\n");
		         system("pause");
		         break;
		   } //fim da seleção
       } 
     }

    else
        printf("Senhra incorreta!");
}
