#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USUARIOS 100
#define MAX_NOME 50
#define MAX_SENHA 50

typedef struct {
    char nome[MAX_NOME];
    char senha[MAX_SENHA];
   
} Usuario;

void cadastrarUsuario();
int loginUsuario();
void alterarSenha();
void excluirUsuario();
void carregarUsuarios();
void salvarUsuarios();
void menuCliente();
void areaCliente(int index);

Usuario usuarios[MAX_USUARIOS];
int totalUsuarios = 0;

int main() {
    int opcao, logado = -1;

    carregarUsuarios();

    do {
        printf("\n--- Sistema de Cadastro de Usuários ---\n");
        printf("1. Cadastrar usuário\n");
        printf("2. Login\n");
        printf("3. Alterar senha\n");
        printf("4. Excluir usuário\n");
        printf("5. Sair\n");
        printf("6. Menu do Cliente\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarUsuario();
                break;
            case 2:
                logado = loginUsuario();
                break;
            case 3:
                if (logado != -1) alterarSenha();
                else printf("Você precisa fazer login primeiro!\n");
                break;
            case 4:
                if (logado != -1) excluirUsuario();
                else printf("Você precisa fazer login primeiro!\n");
                break;
            case 5:
                salvarUsuarios();
                printf("Saindo...\n");
                break;
            case 6:
                if (logado != -1) menuCliente(logado);
                else printf("Você precisa fazer login primeiro!\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 5);

    return 0;
}

void cadastrarUsuario() {
    if (totalUsuarios >= MAX_USUARIOS) {
        printf("Limite máximo de usuários atingido!\n");
        return;
    }

    Usuario novoUsuario;

    printf("Digite o nome de usuário: ");
    scanf("%s", novoUsuario.nome);

    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuarios[i].nome, novoUsuario.nome) == 0) {
            printf("Usuário já existe!\n");
            return;
        }
    }

    printf("Digite a senha: ");
    scanf("%s", novoUsuario.senha);

    usuarios[totalUsuarios] = novoUsuario;
    totalUsuarios++;

    printf("Usuário cadastrado com sucesso!\n");
}

int loginUsuario() {
    char nome[MAX_NOME], senha[MAX_SENHA];

    printf("Digite o nome de usuário: ");
    scanf("%s", nome);
    printf("Digite a senha: ");
    scanf("%s", senha);

    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuarios[i].nome, nome) == 0 && strcmp(usuarios[i].senha, senha) == 0) {
            printf("Login realizado com sucesso!\n");
            return i;
        }
    }

    printf("Usuário ou senha incorretos!\n");
    return -1;
}

void alterarSenha() {
    char nome[MAX_NOME], novaSenha[MAX_SENHA];

    printf("Digite o nome de usuário: ");
    scanf("%s", nome);

    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuarios[i].nome, nome) == 0) {
            printf("Digite a nova senha: ");
            scanf("%s", novaSenha);
            strcpy(usuarios[i].senha, novaSenha);
            printf("Senha alterada com sucesso!\n");
            return;
        }
    }

    printf("Usuário não encontrado!\n");
}

void excluirUsuario() {
    char nome[MAX_NOME];

    printf("Digite o nome de usuário a ser excluído: ");
    scanf("%s", nome);

    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuarios[i].nome, nome) == 0) {
            for (int j = i; j < totalUsuarios - 1; j++) {
                usuarios[j] = usuarios[j + 1];
            }
            totalUsuarios--;
            printf("Usuário excluído com sucesso!\n");
            return;
        }
    }

    printf("Usuário não encontrado!\n");
}

void carregarUsuarios() {
    FILE *file = fopen("usuarios.txt", "r");
    if (file == NULL) return;

    while (fscanf(file, "%s %s", usuarios[totalUsuarios].nome, usuarios[totalUsuarios].senha) != EOF) {
        totalUsuarios++;
    }

    fclose(file);
}

void salvarUsuarios() {
    FILE *file = fopen("usuarios.txt", "w");
    if (file == NULL) {
        printf("Erro ao salvar usuários!\n");
        return;
    }

    for (int i = 0; i < totalUsuarios; i++) {
        fprintf(file, "%s %s\n", usuarios[i].nome, usuarios[i].senha);
    }

    fclose(file);
}

void menuCliente(int index) {
    int opcaoCliente;

    do {
        printf("\n--- Menu do Cliente ---\n");
        printf("1. Ver perfil\n");
        printf("2. Acessar área do cliente\n");
        printf("3. Sair do Menu do Cliente\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcaoCliente);

        switch(opcaoCliente) {
            case 1:
                printf("Exibindo perfil do cliente %s...\n", usuarios[index].nome);
                break;
            case 2:
                areaCliente(index);
                break;
            case 3:
                printf("Saindo do Menu do Cliente...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcaoCliente != 3);
}

void areaCliente(int index) {
    int opcaoArea;

    do {
        printf("\n--- Área do Cliente ---\n");
        printf("1. Atualizar informações\n");
        printf("2. Ver saldo (Exemplo)\n");
        printf("3. Voltar ao menu anterior\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcaoArea);

        switch(opcaoArea) {
            case 1:
                printf("Atualizando informações para %s...\n", usuarios[index].nome);
                
                break;
            case 2:
                printf("Exibindo saldo do cliente %s...\n", usuarios[index].nome);
                
                break;
            case 3:
                printf("Voltando ao menu do cliente...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcaoArea != 3);
}
