#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdint.h>

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

void rgl(rg *u, rg *w, char *v
) {
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
    int found = 0;


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
    long keyspace = get_keyspace(alphabet, size);
    int index[size];

    char candidate[size];

    for (int i = 0; i < size; ++i)
    {
        index[i] = 0;
    }
    int j;
    int k;
#pragma omp parallel for private(candidate, index, j, k) shared(found)
    for (long i = 0; i < keyspace; ++i)
    {
        if (found == 0)
        {
            for (k = 1; k <= size; ++k)
            {
                strcpy(candidate, "");
                for (j = k - 1; j >= 0; --j)
                {
                    index[j] = (int) ((i / (int) pow(len, j)) % len);
//                printf("%d\n", index[j]);
                    sprintf(candidate, "%s%c", candidate, alphabet[index[j]]);
                }
//                printf("candidate: %s-%u\n", candidate, adler32(&candidate, k));
                char candidateHash[65] = {0};
                compute_hash(candidate, candidateHash);
//                printf("1:%s-%s\n", candidate, candidateHash);
            if (strcmp(candidateHash, secret) == 0)
//                if (doHash(candidate, k) == hash)
                {
                    printf("Secret found: **%s**\n", candidate);
                    found = 1;
                }
            }
        }
    }

    if (found == 0)
    {
        printf("Password not found :(");
    }
    return 0;
}
