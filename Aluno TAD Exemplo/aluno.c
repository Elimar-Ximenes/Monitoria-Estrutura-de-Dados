#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Definição da estrutura de dados Aluno
struct aluno{
    int matricula;
    char nome[100];
    int idade;
    float nota1;
    float nota2;
    float notaFinal;
    int quantFaltas;
};
typedef struct aluno Aluno;

// Função para criar um novo aluno
Aluno* criarAluno(int matricula, const char* nome, int idade, float nota1, float nota2, int quantFaltas) {
    Aluno* aluno = (Aluno*) malloc(sizeof(Aluno));
    if (aluno != NULL) {
        aluno->matricula = matricula;
        strcpy(aluno->nome, nome);
        //aluno->nome[sizeof(aluno->nome) - 1] = '\0'; // Garantir que a string de nome esteja terminada corretamente
        aluno->idade = idade;
        aluno->nota1 = nota1;
        aluno->nota2 = nota2;
        aluno->quantFaltas=quantFaltas;
    }
    return aluno;
}
//verifica a situação das faltas
void situacaoFaltas(Aluno * aluno){
	if(aluno->quantFaltas>8){
		printf("Aluno Reprovado por falta!\n");
	}else{
		printf("Aluno Aprovado por falta!\n");
	}
}
//verifica a situação das notas aluno
void imprimirSituacaonota(Aluno* aluno){
	float media = (aluno->nota1=aluno->nota2)/2;
	if(media<7 && media>=4){
		printf("Aluno necessita fazer a Avaliacao Final!\n");
	}else if(media>=7){
		printf("Aluno Aprovado por nota!\n");
	}else{
		printf("Aluno Reprovado por nota!\n");
	}
}
//função verifica quem é o mais velho
void maisVelho(Aluno* aluno1, Aluno* aluno2){
	if(aluno1->idade > aluno2->idade){
		printf("O aluno mais velho: %s\n", aluno1->nome);
	}else{
		printf("O aluno mais velho: %s\n", aluno2->nome);
	}
}
//Função para calcular a media 
float calcularMedia(Aluno * aluno) {
	float media = (aluno->nota1+aluno->nota2)/2;
	return media;
}
//função para imprimir um aluno específico
void imprimiAluno(Aluno * aluno){
        printf("\tDados do aluno:\n");
        printf("Matricula: %d\n", aluno->matricula);
        printf("Nome: %s\n", aluno->nome);
        printf("Idade: %d anos\n", aluno->idade);
        printf("Nota 1: %.2f\n", aluno->nota1);
        printf("Nota 2: %.2f\n", aluno->nota2);
        printf("Quantidade Faltas: %d\n", aluno->quantFaltas);
        printf("Situacao Media: ");
        imprimirSituacaonota(aluno);
        printf("Situacao Faltas: ");
        situacaoFaltas(aluno);
        printf("\n");
}
//imprimir todos os alunos, tem como parametros um vetor de alunos e a quantidade que vai imprimir
void imprimiTodos(Aluno * turma[], int quant){
	int i=0;
	for(i=0; i<quant;i++){
			printf("\tDados do aluno:\n");
		    printf("Matricula: %d\n", turma[i]->matricula);
		    printf("Nome: %s\n", turma[i]->nome);
		    printf("Idade: %d anos\n", turma[i]->idade);
		    printf("Nota 1: %.2f\n", turma[i]->nota1);
		    printf("Nota 2: %.2f\n", turma[i]->nota2);
		    printf("Quantidade Faltas: %d\n", turma[i]->quantFaltas);
		    printf("Situacao Media: ");
		    imprimirSituacaonota(turma[i]);
		    printf("Situacao Faltas: ");
		    situacaoFaltas(turma[i]);
		    printf("\n");
		
	}
}
// Função para liberar a memória alocada para um vetor de alunos
void liberarTurma(Aluno** turma, int numAlunos) {
	int i=0;
    for (i = 0; i < numAlunos; i++) {
        free(turma[i]);
    }
    free(turma);
}

int main() {
    // Exemplo de uso de um vetor de alunos com ponteiros
    int numAlunos = 2; // Número de alunos na turma

    // Alocar memória para o vetor de ponteiros para alunos
    Aluno** turma = (Aluno**) malloc(numAlunos * sizeof(Aluno*));
    if (turma == NULL) {
        printf("Erro ao alocar memÃ³ria para o vetor de alunos.\n");
        return 1;
    }

    // Criar alunos e armazenar os ponteiros no vetor
    turma[0] = criarAluno(1001, "Joao", 20, 7.5, 8.0,2);
    turma[1] = criarAluno(1002, "Maria", 22, 5.5, 6.0,3);

    // Imprimir dados dos alunos, com sua situação de média e faltas
	imprimiTodos(turma, numAlunos);
    //Recebe dois alunos e retorna o mais velho
    maisVelho(turma[0],turma[1]);
    
    free(turma); // Liberar a memória alocada para o vetor de ponteiros para alunos

    return 0;
}


