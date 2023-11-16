#ifndef MORSE_H
#define MORSE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//estrutura do no da arvore
    typedef struct Node {
        char caracteres; //armazenar caracteres
        struct Node* ponto;  //conexão com o proximo no quando há ponto encontrado
        struct Node* traco;  //conexão com o proximo no quando há traço encontrado
    } Node;

//fazer pesquisa por um simbolo na árvore
    const char* searchMorse(Node* raiz, char caracteres) {
    if (raiz == NULL) {
        return NULL;
    }
    if (raiz->caracteres == caracteres) {
        return "";
    }
    const char* esq = searchMorse(raiz->ponto, caracteres);
    if (esq != NULL) {
        char* result = (char*)malloc(strlen(esq) + 2);
        strcpy(result, ".");
        strcat(result, esq);
        return result;
    }
    const char* dir = searchMorse(raiz->traco, caracteres);
    if (dir != NULL) {
        char* result = (char*)malloc(strlen(dir) + 2);
        strcpy(result, "-");
        strcat(result, dir);
        return result;
    }
    return NULL;
}
    // Função para criar um novo nó da árvore
    Node* createNode(char caracteres) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->caracteres = caracteres;
    newNode->ponto = NULL;
    newNode->traco = NULL;
    return newNode;
}

    //inserir um codigo morse na arvore
    void insertMorse(Node* raiz, char* morse, char caracteres) {
    int len = strlen(morse);
    Node* currentNode = raiz;

    for (int i = 0; i < len; i++) {
        if (morse[i] == '.') {
            if (currentNode->ponto == NULL)
                currentNode->ponto = createNode('\0');
            currentNode = currentNode->ponto;
        } else if (morse[i] == '-') {
            if (currentNode->traco == NULL)
                currentNode->traco = createNode('\0');
            currentNode = currentNode->traco;
        }
    }

    currentNode->caracteres = caracteres;
}

    // Função para imprimir a árvore em pré-ordem
    void printTree(Node* raiz, char* codigoMorse, int profundidade) {
    if (raiz == NULL)
        return;

    if (raiz->caracteres != '\0') {
        codigoMorse[profundidade] = '\0';
        printf("%c: %s\n", raiz->caracteres, codigoMorse);
    }

    codigoMorse[profundidade] = '.';
    printTree(raiz->ponto, codigoMorse, profundidade + 1);

    codigoMorse[profundidade] = '-';
    printTree(raiz->traco, codigoMorse, profundidade + 1);

    codigoMorse[profundidade] = '\0';
}

    //converter codigo morse para mensagem de texto
    void convertToText(Node* raiz, char* morse) {
    char* token = strtok(morse, " ");
    while (token != NULL) {
        if (strcmp(token, "/") == 0) {
            printf(" ");
        } else {
            int len = strlen(token);
            Node* currentNode = raiz;

            for (int i = 0; i < len; i++) {
                if (token[i] == '.') {
                    if (currentNode->ponto == NULL) {
                        printf("Caractere inválido encontrado: %s\n", token);
                        return;
                    }
                    currentNode = currentNode->ponto;
                } else if (token[i] == '-') {
                    if (currentNode->traco == NULL) {
                        printf("Caractere inválido encontrado: %s\n", token);
                        return;
                    }
                    currentNode = currentNode->traco;
                }
            }

            printf("%c", currentNode->caracteres);
        }

        token = strtok(NULL, " ");
    }
}

    //converter mensagem de texto para codigo morse
    void convertTextToMorse(Node* raiz, const char* mensagem) {
    if (mensagem == NULL || *mensagem == '\0') {
        return;
    }
    size_t mensagemComprimento = strlen(mensagem);
    for (size_t i = 0; i < mensagemComprimento; i++) {
        char c = toupper((unsigned char)mensagem[i]);
        const char* morse = searchMorse(raiz, c);
        if (morse != NULL) {
            printf("%s ", morse);
        } else {
            printf("/ ", c);
        }
    }
}


#endif