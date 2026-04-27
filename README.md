# Sisop-t1 — O Duelo de Contextos (Processos vs. Threads)

**Disciplina:** Sistemas Operacionais – 2026/I | Luan Pacheco, Samuel Bitdinger e Heitor | **PUCRS**

---

## Como rodar

**Requisitos:** Linux com `gcc` e `make` instalados.

```bash
# 1. Instalar dependências (caso necessário)
sudo apt install gcc make -y

# 2. Compilar e rodar todos os experimentos
make run
```

---

## Resultados

### T1 — Threads SEM sincronização

| N | Contador final | Esperado | Tempo real |
|---|---------------|----------|------------|
| 2 | 501.354.753 | 1.000.000.000 | 4.77s |
| 4 | 293.959.391 | 1.000.000.000 | 9.15s |
| 8 | 150.445.621 | 1.000.000.000 | 8.29s |

### T2 — Threads COM mutex

| N | Contador final | Esperado | Tempo real |
|---|---------------|----------|------------|
| 2 | 1.000.000.000 | 1.000.000.000 | 34.68s |
| 4 | 1.000.000.000 | 1.000.000.000 | 36.23s |
| 8 | 1.000.000.000 | 1.000.000.000 | 40.36s |

### P1 — Processos SEM sincronização

| N | Contador final | Esperado | Tempo real |
|---|---------------|----------|------------|
| 2 | 639.830.471 | 1.000.000.000 | 3.42s |
| 4 | 270.312.162 | 1.000.000.000 | 3.66s |
| 8 | 190.338.440 | 1.000.000.000 | 3.75s |

### P2 — Processos COM semáforo

| N | Contador final | Esperado | Tempo real |
|---|---------------|----------|------------|
| 2 | 1.000.000.000 | 1.000.000.000 | 32.79s |
| 4 | 1.000.000.000 | 1.000.000.000 | 4m13.26s |
| 8 | 1.000.000.000 | 1.000.000.000 | 3m53.63s |

### Resultado cru no terminal

=== T1 - Threads SEM sincronizacao ===
N=2:
Contador final: 501354753 (esperado: 1000000000)
9.53user 0.00system 0:04.77elapsed 199%CPU (0avgtext+0avgdata 1728maxresident)k
0inputs+0outputs (0major+84minor)pagefaults 0swaps
N=4:
Contador final: 293959391 (esperado: 1000000000)
35.88user 0.00system 0:09.15elapsed 392%CPU (0avgtext+0avgdata 1728maxresident)k
0inputs+0outputs (0major+89minor)pagefaults 0swaps
N=8:
Contador final: 150445621 (esperado: 1000000000)
64.03user 0.00system 0:08.29elapsed 771%CPU (0avgtext+0avgdata 1856maxresident)k
0inputs+0outputs (0major+97minor)pagefaults 0swaps

=== T2 - Threads COM mutex ===
N=2:
Contador final: 1000000000 (esperado: 1000000000)
31.34user 36.38system 0:34.68elapsed 195%CPU (0avgtext+0avgdata 1728maxresident)k
0inputs+0outputs (0major+84minor)pagefaults 0swaps
N=4:
Contador final: 1000000000 (esperado: 1000000000)
49.85user 80.68system 0:36.23elapsed 360%CPU (0avgtext+0avgdata 1728maxresident)k
0inputs+0outputs (0major+89minor)pagefaults 0swaps
N=8:
Contador final: 1000000000 (esperado: 1000000000)
63.81user 223.35system 0:40.36elapsed 711%CPU (0avgtext+0avgdata 1860maxresident)k
0inputs+0outputs (0major+98minor)pagefaults 0swaps

=== P1 - Processos SEM sincronizacao ===
N=2:
Contador final: 639830471 (esperado: 1000000000)
6.84user 0.00system 0:03.42elapsed 199%CPU (0avgtext+0avgdata 1632maxresident)k
0inputs+0outputs (0major+137minor)pagefaults 0swaps
N=4:
Contador final: 270312162 (esperado: 1000000000)
13.93user 0.00system 0:03.66elapsed 380%CPU (0avgtext+0avgdata 1632maxresident)k
0inputs+0outputs (0major+188minor)pagefaults 0swaps
N=8:
Contador final: 190338440 (esperado: 1000000000)
27.81user 0.00system 0:03.75elapsed 741%CPU (0avgtext+0avgdata 1632maxresident)k
0inputs+0outputs (0major+287minor)pagefaults 0swaps

=== P2 - Processos COM semaforo ===
N=2:
Contador final: 1000000000 (esperado: 1000000000)
23.51user 40.84system 0:32.79elapsed 196%CPU (0avgtext+0avgdata 1728maxresident)k
0inputs+0outputs (0major+163minor)pagefaults 0swaps
N=4:
Contador final: 1000000000 (esperado: 1000000000)
142.98user 690.74system 4:13.26elapsed 329%CPU (0avgtext+0avgdata 1728maxresident)k
0inputs+0outputs (0major+220minor)pagefaults 0swaps
N=8:
Contador final: 1000000000 (esperado: 1000000000)
230.14user 1357.32system 3:53.63elapsed 679%CPU (0avgtext+0avgdata 1728maxresident)k
0inputs+0outputs (0major+350minor)pagefaults 0swaps
