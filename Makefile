CC     = gcc
CFLAGS = -O0 -Wall

.PHONY: all clean run

all: threads processos

threads: threads.c
	$(CC) $(CFLAGS) -o threads threads.c -lpthread

processos: processos.c
	$(CC) $(CFLAGS) -o processos processos.c -lpthread -lrt

run: all
	@echo "=== T1 - Threads SEM sincronizacao ==="
	@echo "N=2:"; time ./threads 2 0
	@echo "N=4:"; time ./threads 4 0
	@echo "N=8:"; time ./threads 8 0
	@echo ""
	@echo "=== T2 - Threads COM mutex ==="
	@echo "N=2:"; time ./threads 2 1
	@echo "N=4:"; time ./threads 4 1
	@echo "N=8:"; time ./threads 8 1
	@echo ""
	@echo "=== P1 - Processos SEM sincronizacao ==="
	@echo "N=2:"; time ./processos 2 0
	@echo "N=4:"; time ./processos 4 0
	@echo "N=8:"; time ./processos 8 0
	@echo ""
	@echo "=== P2 - Processos COM semaforo ==="
	@echo "N=2:"; time ./processos 2 1
	@echo "N=4:"; time ./processos 4 1
	@echo "N=8:"; time ./processos 8 1

clean:
	rm -f threads processos