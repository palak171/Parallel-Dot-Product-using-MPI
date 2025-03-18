#include <mpi.h>
#include <stdio.h>

#define N 100

int main(int argc, char* argv[]) {
    int rank, size;
    double local_sum = 0, global_sum = 0;
    double A[N], B[N];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int elements_per_proc = N / size;
    for (int i = 0; i < elements_per_proc; i++) {
        A[i] = 1.0;  // Example values
        B[i] = 1.0;
        local_sum += A[i] * B[i];
    }

    MPI_Reduce(&local_sum, &global_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == 0) printf("Dot Product = %lf\n", global_sum);

    MPI_Finalize();
    return 0;
}
