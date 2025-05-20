//Kauê Silva Matheus - RM561675 (case 2)
//Caique Baptistella de Vicente Albertino - RM564747 (case 1)
//Arthur da Silva Alencar - RM563684 (case 4)
//João Pedro de Moura Albino - RM565323 (case 3)

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void calcularFibonacci(int numero);
void calcularFatoriais(int limite, unsigned long long resultado[]);
int verificar_palindromo(const char *palavra);
int contemSubstring(const char *stringPrincipal, const char *substring);

int main() {
    int opcao;
    
    printf("\n===== MENU DE EXERCICIOS =====\n");
    printf("\n1 - Sequencia de Fibonacci;\n2 - Fatoriais;\n3 - Verificar Palindromo;\n4 - Verificar Substring.\n");
    printf("\nDigite um numero de 1 a 4: ");
    scanf("%d", &opcao);
    getchar();

    switch(opcao) {
        case 1: {
            printf("\nVoce escolheu a opcao de Fibonacci\n");
            int numero;
            printf("Quantos termos da sequencia de Fibonacci deseja? ");
            scanf("%d", &numero);
            getchar();
            
            if (numero < 1) {
                printf("Numero invalido! Digite um valor positivo.\n");
                break;
            }
            
            calcularFibonacci(numero);
            break;
        }
        case 2: {
            printf("\nVoce escolheu a opcao de Fatoriais\n");
            int numero;
            printf("\nEscolha um numero de 1 a 20: ");
            scanf("%d", &numero);
            getchar();
        
            if (numero < 1 || numero > 20) {
                printf("Numero invalido! Digite um valor entre 1 e 20.\n");
                break;
            }

            unsigned long long fatoriais[numero];
            calcularFatoriais(numero, fatoriais);

            printf("\nFatoriais calculados:\n");
            for (int i = 0; i < numero; i++) {
                printf("%d! = %llu\n", i + 1, fatoriais[i]);
            }
            break;
        }
        case 3: {
            printf("Voce escolheu a opcao de verificar Palindromo\n");
            char palavra[101];
            int eh_palindromo;

            printf("Digite uma palavra (sem espaços, ate 100 letras): ");
            scanf("%100s", palavra); 
            getchar();
    
            eh_palindromo = verificar_palindromo(palavra);
    
            if (eh_palindromo) {
                printf("\"%s\" e um palindromo!\n", palavra);
            } else {
                printf("\"%s\" nao e um palindromo.\n", palavra);
            }
            break;
        }
        case 4: {
            char stringPrincipal[100], substring[100];
            
            printf("Digite a string principal (max 99 caracteres): ");
            scanf(" %99[^\n]", stringPrincipal);
            getchar();
        
            printf("Digite a substring a ser buscada (max 99 caracteres): ");
            scanf("%99[^\n]", substring);
            getchar();
        
            if (contemSubstring(stringPrincipal, substring)) {
                printf("\nA substring \"%s\" ESTA contida na string principal.\n", substring);
            } else {
                printf("\nA substring \"%s\" NAO esta contida na string principal.\n", substring);
            }
            break;
        }
        default: {
            printf("Opcao invalida! Digite um numero entre 1 e 4.\n");
        }
    }

    return 0;
}


void calcularFibonacci(int numero) {
    unsigned long long fib[numero];
    fib[0] = 0;
    if (numero > 1) {
        fib[1] = 1;
    }

    for (int i = 2; i < numero; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    printf("Os %d primeiros termos da sequencia de Fibonacci: \n", numero);
    for (int i = 0; i < numero; i++) {
        printf("%llu ", fib[i]);
    }
    printf("\n");
}

void calcularFatoriais(int limite, unsigned long long resultado[]) {
    resultado[0] = 1;
    for (int i = 2; i <= limite; i++) {
        resultado[i - 1] = resultado[i - 2] * i;
    }
}

int verificar_palindromo(const char *palavra) {
    int i, j;
    int tamanho = strlen(palavra);
    
    for (i = 0, j = tamanho - 1; i < j; i++, j--) {
        if (tolower(palavra[i]) != tolower(palavra[j])) {
            return 0;
        }
    }
    return 1;
}

int contemSubstring(const char *stringPrincipal, const char *substring) {
    int lenPrincipal = strlen(stringPrincipal);
    int lenSub = strlen(substring);
    
    for (int i = 0; i <= lenPrincipal - lenSub; i++) {
        int j;
        for (j = 0; j < lenSub; j++) {
            if (tolower(stringPrincipal[i + j]) != tolower(substring[j])) {
                break;
            }
        }
        if (j == lenSub) {
            return 1;
        }
    }
    return 0;
}
