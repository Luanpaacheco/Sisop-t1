#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <fcntl.h>

#define TOTAL 1000000000LL  /* 1 bilhao de incrementos no total */
#define SEM_NAME "/sem_duelo"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s <N> <modo: 0=sem_sync 1=semaforo>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    int usar_sem = atoi(argv[2]);
    long long iters = TOTAL / N;  /* cada processo faz essa quantidade de incrementos */

    /* --- cria memoria compartilhada para o contador --- */
    /* shmget reserva um bloco de memoria que todos os processos podem acessar */
    int shmid = shmget(IPC_PRIVATE, sizeof(long long), IPC_CREAT | 0666);
    if (shmid < 0) {
        printf("Erro: shmget falhou\n");
        return 1;
    }

    /* shmat "anexa" a memoria compartilhada no espaco de enderecamento do processo */
    long long *counter = (long long *)shmat(shmid, NULL, 0);
    *counter = 0;  /* inicializa o contador */

    /* --- cria semaforo (so se for P2) --- */
    sem_t *sem = SEM_FAILED;
    if (usar_sem) {
        sem_unlink(SEM_NAME);  /* remove semaforo antigo caso exista */
        /* sem_open cria o semaforo com valor inicial 1 (liberado) */
        sem = sem_open(SEM_NAME, O_CREAT | O_EXCL, 0666, 1);
        if (sem == SEM_FAILED) {
            printf("Erro: sem_open falhou\n");
            return 1;
        }
    }

    /* --- cria os N processos filhos via fork --- */
    for (int i = 0; i < N; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            printf("Erro: fork falhou\n");
            return 1;
        }

        if (pid == 0) {
            /* esse bloco roda apenas no processo filho */

            /* filho precisa se anexar a memoria compartilhada tambem */
            long long *c = (long long *)shmat(shmid, NULL, 0);

            /* filho abre o semaforo (se P2) */
            sem_t *s = SEM_FAILED;
            if (usar_sem) {
                s = sem_open(SEM_NAME, 0);
            }

            if (usar_sem) {
                /* P2: usa semaforo para garantir acesso exclusivo ao contador */
                for (long long j = 0; j < iters; j++) {
                    sem_wait(s);   /* entra na regiao critica */
                    (*c)++;
                    sem_post(s);   /* sai da regiao critica */
                }
                sem_close(s);
            } else {
                /* P1: incrementa sem nenhuma protecao */
                for (long long j = 0; j < iters; j++) {
                    (*c)++;
                }
            }

            shmdt(c);  /* filho se desanexa da memoria compartilhada */
            exit(0);   /* filho termina */
        }
        /* processo pai continua o loop e cria o proximo filho */
    }

    /* pai espera todos os filhos terminarem */
    for (int i = 0; i < N; i++) {
        wait(NULL);
    }

    /* imprime apenas o que o relatorio pede */
    printf("Contador final: %lld (esperado: %lld)\n", *counter, TOTAL);

    /* --- limpeza --- */
    shmdt(counter);
    shmctl(shmid, IPC_RMID, NULL);  /* remove a memoria compartilhada */
    if (usar_sem) {
        sem_close(sem);
        sem_unlink(SEM_NAME);  /* remove o semaforo */
    }

    return 0;
}
