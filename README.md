# Sisop-t1
resultados
gcc -O0 -Wall -o threads threads.c -lpthread
gcc -O0 -Wall -o processos processos.c -lpthread -lrt
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
