#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define TOTAL 1000000000LL  /* 1 bilhao de incrementos no total */

long long counter = 0;          /* variavel global compartilhada entre as threads */
long long iters;                /* quantos incrementos cada thread vai fazer */
int usar_mutex = 0;             /* 0 = sem sync (T1), 1 = com mutex (T2) */
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

/* funcao que cada thread executa */
void *worker(void *arg) {
    (void)arg; /* nao usamos o argumento, isso evita warning do compilador */

    if (usar_mutex) {
        /* T2: trava o mutex antes de incrementar, destrava depois */
        for (long long i = 0; i < iters; i++) {
            pthread_mutex_lock(&mutex);
            counter++;
            pthread_mutex_unlock(&mutex);
        }
    } else {
        /* T1: incrementa direto, sem nenhuma protecao */
        for (long long i = 0; i < iters; i++) {
            counter++;
        }
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s <N> <modo: 0=sem_sync 1=mutex>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    usar_mutex = atoi(argv[2]);
    iters = TOTAL / N;  /* divide o trabalho igualmente entre as threads */

    /* cria as N threads */
    pthread_t threads[N];
    for (int i = 0; i < N; i++) {
        pthread_create(&threads[i], NULL, worker, NULL);
    }

    /* espera todas as threads terminarem */
    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    /* imprime apenas o que o relatorio pede */
    printf("Contador final: %lld (esperado: %lld)\n", counter, TOTAL);

    pthread_mutex_destroy(&mutex);
    return 0;
}
