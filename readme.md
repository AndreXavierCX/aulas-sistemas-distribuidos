-- compilar
    <br>
    gcc <nomedoarquivo.c> -o <nomequevocequer> -fopenmp
    <br>
    ex: gcc somaVetor.c -o somaVetor -fopenmp
    <br>
    <br>
-- executar
    <br>
    ./<nomeArquivo.>
    <br>
    ex: ./somaVetor
    <br>
    <br>
-- definir o número threads
    <br>
    export OMP_NUM_THREADS=<numerodeThreads.>
    <br>
    ex: export OMP_NUM_THREADS=8
    <br>
    <br>
