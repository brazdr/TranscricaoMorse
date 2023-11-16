#include "Morse.h"

int main() {
   
    //construir a arvore morse
    Node* raiz = createNode('\0');
    // Inserir símbolos Morse
    insertMorse(raiz, ".-", 'A');
    insertMorse(raiz, "-...", 'B');
    insertMorse(raiz, "-.-.", 'C');
    insertMorse(raiz, "-..", 'D');
    insertMorse(raiz, ".", 'E');
    insertMorse(raiz, "..-.", 'F');
    insertMorse(raiz, "--.", 'G');
    insertMorse(raiz, "....", 'H');
    insertMorse(raiz, "..", 'I');
    insertMorse(raiz, ".---", 'J');
    insertMorse(raiz, "-.-", 'K');
    insertMorse(raiz, ".-..", 'L');
    insertMorse(raiz, "--", 'M');
    insertMorse(raiz, "-.", 'N');
    insertMorse(raiz, "---", 'O');
    insertMorse(raiz, ".--.", 'P');
    insertMorse(raiz, "--.-", 'Q');
    insertMorse(raiz, ".-.", 'R');
    insertMorse(raiz, "...", 'S');
    insertMorse(raiz, "-", 'T');
    insertMorse(raiz, "..-", 'U');
    insertMorse(raiz, "...-", 'V');
    insertMorse(raiz, ".--", 'W');
    insertMorse(raiz, "-..-", 'X');
    insertMorse(raiz, "-.--", 'Y');
    insertMorse(raiz, "--..", 'Z');
    insertMorse(raiz, "-----", '0');
    insertMorse(raiz, ".----", '1');
    insertMorse(raiz, "..---", '2');
    insertMorse(raiz, "...--", '3');
    insertMorse(raiz, "....-", '4');
    insertMorse(raiz, ".....", '5');
    insertMorse(raiz, "-....", '6');
    insertMorse(raiz, "--...", '7');
    insertMorse(raiz, "---..", '8');
    insertMorse(raiz, "----.", '9');

    //imprimir a arvore
    printf("\nArvore Morse: \n");
    char codigoMorse[100];
    printTree(raiz, codigoMorse, 0);
    printf("\n");

    // Converter de texto para Morse
    char message[100];
    FILE* file = fopen("codifica.in", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    printf("Mensagens originais:\n");
    while (fgets(message, sizeof(message), file) != NULL) {
        message[strcspn(message, "\n")] = '\0';
        printf("%s\n", message);
        printf("Mensagem convertida: ");
        convertTextToMorse(raiz, message);
        printf("\n");
    }
    fclose(file);

    // Converter de Morse para texto
     char morse[100];
    file = fopen("decodifica.in", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    printf("Mensagens originais em codigo Morse:\n");
    while (fgets(morse, sizeof(morse), file) != NULL) {
        morse[strcspn(morse, "\n")] = '\0';
        printf("%s\n", morse);
        printf("Mensagem convertida: ");
        convertToText(raiz, morse);
        printf("\n");
    }
    fclose(file);

    return 0;
}

