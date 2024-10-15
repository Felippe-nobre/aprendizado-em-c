#include <stdio.h>
#include <string.h>

typedef struct 
{
   char Nome[50];
   float Preco;
   int Quantidade;
}Produto;

typedef struct 
{
    int Id;
    Produto Produtos[99];
    float Total;
}Pedido;


int main(){
    int status = 1, id = 0, c;
    Pedido Pedidos[99];

    while (status){
    printf("\e[1;1H\e[2J");

        printf("1 - Novo pedido");
        printf("\n2 - Lista de pedido");
        printf("\n3 - Sair");
        printf("\nescolha uma opecao: ");
        int opecoes;
        scanf("%d", &opecoes);

        switch (opecoes)
        {
        case 1:
        printf("\e[1;1H\e[2J");
           
            printf(" pedido Id: %d \n", id + 1);
            printf("-------------------------------------------");
             Pedidos[id]. Id = id;
            
            float total = 0;

            for (int i = 0; i < 99; i++)
            {
                 while((c = getchar()) != '\n' && c != EOF);


                printf("\nDigite o nome do produto: ");
                char nome[50];
                fgets(nome, sizeof(nome), stdin);

                printf("\nDigite o preco do produto: ");
                float preco;
                scanf("%f", &preco);

                printf("\nDigite o quantidade do produto: ");
                int quantidade;
                scanf("%d", &quantidade);
                Produto produto = {.Preco = preco, .Quantidade = quantidade};
                strcpy(produto.Nome, nome);
                Pedidos[id].Produtos[i] = produto;

                total += preco * quantidade;

                printf("\nVoce deseja adicionar mais produtos? [y/n]");
                char novoProduto;
                scanf(" %c", &novoProduto);
                if (novoProduto != 'y')
                {
                    break;
                }
                
                printf("-------------------------------------------");
            }
            Pedidos[id].Total = total;
            id++;
            break;

        case 2:
        printf("\e[1;1H\e[2J");
            for (int i = 0; i < id; i++)
            {
                printf("\nPedidos Id: %d", i + 1);
               for (int j = 0; j < 99; j++)
               {
                printf("\n==================================\n");
                printf("\n#Produto %d", j + 1);

                printf("\nProdutos nome: %s", Pedidos[i].Produtos[j].Nome);
                printf("\nProdutos preco: %.f",Pedidos[i].Produtos[j].Preco); 
                printf("\nProdutos quantidade: %d",Pedidos[i].Produtos[j].Quantidade);  

                if (Pedidos[i].Produtos[j + 1].Quantidade == 0)
                {
                    break;
                }
                
               }
               printf("\n==================================\n");
               printf("\nTotal: %.f", Pedidos[i].Total);
                printf("\n==================================\n");
               
            }
            printf("\nPressione uma tecla para continuar...");
             while((c = getchar()) != '\n' && c != EOF);
            getchar();
            
            break;

        case 3:

        status = 0;

            break;    

        
        
        }
    }
    

return 0;
}