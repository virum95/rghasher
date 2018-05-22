#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdint.h>
#include <mpi.h>

#define MIN 4
#define MAX 4
//#define ALPHA "1234567890ABCDEFGHIJKLMNÑOPQRSTUVWXYZabcdefghijklmnñopqrstuvwxyz"
#define ALPHA "abcdefghijklmnopqrstuvwxyz"
//#define SECRET "2990e0c0316c9cf51dbc38df4fd50d780fbf3564cbfb3734c3acfd56a7161ed79c99c406420c48bb00930a71884f3acc9febeaddcc2791fc9484b9a60d0b0ba8"
#define SECRET "6385374830"

#define rg uint32_t // NO WARRANTY
#define rgp(a) for(c=0;c<(a);c++)
#define rgn w[c*13]^=s;u[16+c]^=s;

void rgf(rg *a, rg *b) {
    rg m = 19, A[19], x, o = 13, c, y, r = 0;
    rgp(12)
        b[c + c % 3 * o] ^= a
        [c + 1];
    rgp(m)
    {
        r = (c + r) & 31;
        y = c * 7;
        x = a[y++ % m];
        x ^= a[y % m] | ~a[(y + 1) % m];
        A[c] = x
                       >> r | x << (32 - r);
    }
    for (y = 39; y--; b[y + 1] = b[y])
        a[y % m] = A[y % m] ^ A[(y + 1) % m] ^ A[(y
                                                  + 4) % m];
    *a ^= 1;
    rgp(3)a[c + o] ^= b[c * o] = b[c * o + o];
}

void rgl(rg *u, rg *w, char *v) {
    rg s, q, c, x;
    rgp(40)w[c] = u[c % 19] = 0;
    for (;; rgf(u, w))
    {
        rgp(3)
        {
            for (s = q = 0; q
                            < 4;)
            {
                x = (uint32_t) *v++;
                s |= (x ? 255 & x : 1) << 8 * q++;
                if (!x)
                {
                    rgn;
                    rgp(17)rgf(u, w);
                    return;
                }
            }
            rgn;
        }
    }
}

rg rgi(rg *m, rg *b, rg *a) {
    if (*a & 2)rgf(m, b);
    return m[*a ^= 3];
}

/* Example of API usage, non-Golfed (also public domain) */

void compute_hash(char * candidate, char * hash) {
    uint32_t belt[40], mill[19], c, j, phase = 2;
    char str[10];
    /* Seed random number generator */
    rgl(mill, belt, candidate);
    /* Show in hex first 256 bits of PRNG */
    for (c = 0; c < 8; c++)
    {
        j = rgi(mill, belt, &phase); /* Get number from PRNG */
        /* This isn't needed for good numbers, but test vector
         * compatibility needs an endian swap on little-endian
         * (x86) machines */
        j = (j << 24 |
             (j & 0xff00) << 8 |
             (j & 0xff0000) >> 8 |
             j >> 24);
        snprintf(str, sizeof(str), "%08x"
                ""
                "", j);
        strcat(hash, str);
    }

}

void eh(MPI_Comm *comm, int *err){
  printf("handling" );
  return;
}

long get_keyspace(char *alpha, int max) {
    long size = 1;
    for (int i = 0; i < max; ++i)
    {
        size = size * strlen(alpha);
    }
    return size;
}

int main(int argc, char *argv[]) {

    if (argc == 1)
    {
        printf("Enter a value.\n");
        return 1;
    }
    char *avalue = NULL;
    char *svalue = NULL;
    char *alphabet;
    int size;
    int rank, pSize;


    int ch;
    while ((ch = getopt(argc, argv, "a:d:s:")) != -1)
    {
        switch (ch)
        {
            case 'a':
                avalue = optarg;
                break;
            case 's':
                svalue = optarg;
                break;
            case 'd':
                printf("Option d selected %s\n", optarg);
                break;
            default:
                printf("Insert a command.\n");
        }
    }

    alphabet = avalue != NULL ? strdup(avalue) : ALPHA;
    size = svalue != NULL ? atoi(svalue) : MAX;
    char secret[65] = {0};
    if (optind > argc)
    {
        strcpy(secret, SECRET);
    }
    else
    {
        strcpy(secret, argv[optind]);
    }

    int len = (int) strlen(alphabet);
    long keyspace;
    int index[size];
    int *subset;
    char candidate[size];
    long partition;
//    MPI_Errhandler newerr;


    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&pSize);

    /*MPI_Comm_create_errhandler( eh, &newerr );
    MPI_Comm_set_errhandler( MPI_COMM_WORLD, newerr );
    MPI_Comm_call_errhandler( MPI_COMM_WORLD, MPI_ERR_OTHER );*/
    keyspace = get_keyspace(alphabet, size);
    partition = keyspace/(pSize);

    int test[keyspace];
    subset = malloc(sizeof(int)*partition);
    char *message;


    if(rank == 0){
      for (int i = 0; i < size; ++i)
      {
        index[i] = 0;
      }
      for(int i = 0; i < keyspace; i++){
        test[i] = i;
      }
    }

    int k;
    int j;


    //if(rank == 0){
      MPI_Scatter(&test, partition, MPI_INT, subset, partition, MPI_INT, 0, MPI_COMM_WORLD);
    /*}else{
      MPI_Scatter(MPI_IN_PLACE, partition, MPI_LONG, subset, partition, MPI_LONG, 0, MPI_COMM_WORLD);
    }*/


    /*if(rank == 0){
      MPI_Recv(message, size, MPI_CHAR, MPI_ANY_SOURCE, 7 ,MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      message[size]='\0';
      printf("%s\n", message);
      MPI_Abort(MPI_COMM_WORLD, MPI_SUCCESS);
    }else{*/

    for (long i = subset[0]; i < subset[partition-1]; ++i)
    {

            for (k = 1; k <= size; ++k)
            {
                strcpy(candidate, "");
                for (j = k - 1; j >= 0; --j)
                {
                    index[j] = (int) ((i / (int) pow(len, j)) % len);
                    //printf("%d\n", index[j]);
                    sprintf(candidate, "%s%c", candidate, alphabet[index[j]]);
                }
                //printf("candidate: %s-%u\n", candidate, adler32(&candidate, k));
                char candidateHash[65] = {0};
                compute_hash(candidate, candidateHash);
                //printf("1:%s-%s\n", candidate, candidateHash);
            if (strcmp(candidateHash, secret) == 0){
                    printf("Secret found: **%s**\n", candidate);
                    MPI_Abort(MPI_COMM_WORLD, MPI_SUCCESS);
                    //MPI_Send(candidate, size, MPI_CHAR, 0, 7, MPI_COMM_WORLD);
                    //MPI_Allreduce(&found, &globalFound, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
                    //printf("%d\n", globalFound );
                }
            }


    }
//}

    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();

    return 0;
}
