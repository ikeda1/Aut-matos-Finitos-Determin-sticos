/*
Grupo:
Guilherme Shigueo Kumagae- 32041111
Lucas Kenzo Akiyama - 32025165
Pedro Henrique Ikeda - 32016344
*/

/* == ANOTAÇÕES ==

Para números de ponto flutuante, os números terminados apenas em . também foram considerados corretos:
Exemplo: 15. é aceito como um número de ponto flutuante

Sequências de dois sinais seguidos no início da palavra são rejeitados
Exemplo: ++10 é rejeitado

*/

#include <stdio.h>

#define REJECT 0
#define ACCEPT_INT 1
#define ACCEPT_FLOAT 2


int scanner(char word[], int size)
{
    char c;
    int index = 0;

    // Estado inicial Q0
    q0: 
        // Variável que guarda a letra a ser analisada
        c = word[index];

        // Verifica se é final da palavra
        if (index == size) return REJECT;

        switch (c)
        {
        // Se a letra for um sinal
        case '+': case '-':
            index++;
            goto q4;
        
        // Se a letra for um número
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            index++;
            goto q1;
        
        case ',': case'.': case'a': case'b': case'c': case'd': case'e': case'f': case'g': case'h': case'i': case'j': case'k': case'l': case'm': case'n': case'o': case'p': case'q': case'r': case's': case't': case'u': case'v': case'w': case'x': case'y': case'z':
            goto q3;

        default:
            goto q3;
        
        }

    // Estado final Q1
    q1:
        // Variável que guarda a letra a ser analisada
        c = word[index];

        // Verifica se é final da palavra
        if (index == size) return ACCEPT_INT;

        switch (c)
        {
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            index++;
            goto q1;

        case '.':
            index++;
            goto q2;

        case ',': case'+': case'-': case'a': case'b': case'c': case'd': case'e': case'f': case'g': case'h': case'i': case'j': case'k': case'l': case'm': case'n': case'o': case'p': case'q': case'r': case's': case't': case'u': case'v': case'w': case'x': case'y': case'z':
            goto q3;

        default:
            goto q3;
        }

    // Estado final Q2
    q2:
        // Variável que guarda a letra a ser analisada
        c = word[index];

        // Verifica se é final da palavra
        if (index == size) return ACCEPT_FLOAT;

        switch(c)
        {
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            index++;
            goto q2;

        case',': case'.': case'+': case'-': case'a': case'b': case'c': case'd': case'e': case'f': case'g': case'h': case'i': case'j': case'k': case'l': case'm': case'n': case'o': case'p': case'q': case'r': case's': case't': case'u': case'v': case'w': case'x': case'y': case'z': 
            goto q3;

        default:
            goto q3;
        }

    // Estado Q4
    q4:
        c = word[index];
        switch (c)
        {
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            index++;
            goto q1;

        case',': case'.': case'+': case'-': case'a': case'b': case'c': case'd': case'e': case'f': case'g': case'h': case'i': case'j': case'k': case'l': case'm': case'n': case'o': case'p': case'q': case'r': case's': case't': case'u': case'v': case'w': case'x': case'y': case'z': 
            goto q3;

        default:
            goto q3;
        }
        
    // Estado de Poço
    q3:
        return REJECT;
}

int main()
{
    // Variável que armazena a palavra a ser testada
    char word[] = "+5005.97";

    // Tamanho da palavra
    int size = strlen(word);
    
    // Armazena o resultado do AFD
    int result = scanner(word, size);

    // Imprime o resutlado para o usuario
    switch (result)
    {
    case 0:
        printf("<ERRO>\n");
        break;
    case 1:
        printf("<INTEIRO>\n");
        break;
    case 2:
        printf("<P.FLUTUANTE>\n");
        break;

    default:
        break;
    }

    return 0;
}