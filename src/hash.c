#include <stdio.h>
#include <string.h>
#include <stdint.h>

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


int main(int argc, char *argv[]) {
    char hash[65];
    if (argc == 2)
    {
//        printf("%s, %zu\n", argv[1], strlen(argv[1]));
//        system(prog);
        compute_hash(argv[1], hash);
        printf("%s", hash);
    }
    else
    {
        printf("Error, usage: %s <string>\n", argv[0]);
        return -1;
    }

    return 0;
}
