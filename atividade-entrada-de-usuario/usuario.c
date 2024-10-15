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

Usuario usuarios[MAX_USUARIOS];
int totalUsuarios = 0;

int main() {
    int opcao, logado = 0;

    carregarUsuarios();

    do {
        printf("\n--- Sistema de Cadastro de Usuários ---\n");
        printf("1. Cadastrar usuário\n");
        printf("2. Login\n");
        printf("3. Alterar senha\n");
        printf("4. Excluir usuário\n");
        printf("5. Sair\n");
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
                if (logado) alterarSenha();
                else printf("Você precisa fazer login primeiro!\n");
                break;
            case 4:
                if (logado) excluirUsuario();
                else printf("Você precisa fazer login primeiro!\n");
                break;
            case 5:
                salvarUsuarios();
                printf("Saindo...\n");
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
            return 1;
        }
    }

    printf("Usuário ou senha incorretos!\n");
    return 0;
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
