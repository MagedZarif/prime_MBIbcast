#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <math.h>


int is_prime(int n)
{
    int i;
    if (n < 2)
    {
        return 0;
    }
    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int count_primes(int lower, int upper)
{
    int i, count = 0;
    for (i = lower; i < upper; i++)
    {
        if (is_prime(i))
        {
            count++;
        }
    }
    return count;
}



int main(int argc, char *argv[])
{
    int x, y, p, rank, tag = 0;
    int subrange_size, lower, upper, count, total_count;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        printf("Enter lower bound number: ");
        scanf("%d", &x);
        printf("Enter upper bound number: ");
        scanf("%d", &y);

        subrange_size = ceil((double)(y - x) / p);


        MPI_Bcast(&x, 1, MPI_INT, 0, MPI_COMM_WORLD);
        MPI_Bcast(&subrange_size, 1, MPI_INT, 0, MPI_COMM_WORLD);
    }
    else

    {

        MPI_Bcast(&x, 1, MPI_INT, 0, MPI_COMM_WORLD);
        MPI_Bcast(&subrange_size, 1, MPI_INT, 0, MPI_COMM_WORLD);
    }


    lower = x + rank * subrange_size;
    upper = lower + subrange_size;

    if (rank == p - 1)
    {
        upper = y;
    }


    count = count_primes(lower, upper);


    MPI_Reduce(&count, &total_count, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        printf("Total count of prime numbers between %d and %d is %d\n", x, y, total_count);
    }

    MPI_Finalize();
    return 0;
}
#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <math.h>


int is_prime(int n)
{
    int i;
    if (n < 2)
    {
        return 0;
    }
    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int count_primes(int lower, int upper)
{
    int i, count = 0;
    for (i = lower; i < upper; i++)
    {
        if (is_prime(i))
        {
            count++;
        }
    }
    return count;
}



int main(int argc, char *argv[])
{
    int x, y, p, rank, tag = 0;
    int subrange_size, lower, upper, count, total_count;




    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) 

    {
        printf("Enter lower bound number: ");
        scanf("%d", &x);
        printf("Enter upper bound number: ");
        scanf("%d", &y);

        subrange_size = ceil((double)(y - x) / p);


        MPI_Bcast(&x, 1, MPI_INT, 0, MPI_COMM_WORLD);

        MPI_Bcast(&subrange_size, 1, MPI_INT, 0, MPI_COMM_WORLD);
    }
    else

    {

        MPI_Bcast(&x, 1, MPI_INT, 0, MPI_COMM_WORLD);

        MPI_Bcast(&subrange_size, 1, MPI_INT, 0, MPI_COMM_WORLD);
    }


    lower = x + rank * subrange_size;
    upper = lower + subrange_size;

    if (rank == p - 1)
    {
        upper = y;
    }


    count = count_primes(lower, upper);


    MPI_Reduce(&count, &total_count, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        printf("Total count of prime numbers between %d and %d is %d\n", x, y, total_count);
    }

    MPI_Finalize();
    return 0;
}
