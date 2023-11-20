//-----------------------------------------------------------------------------
#include <stdio.h>
#define MAKSKS 10
#define MAKSCCK 15

struct kisi {
    char *isim;
    int degumtarihi;
    enum cinsiyet_tipi {erkek, kadin} cinsiyet;
    union {
        int ahbtarihi;
        char *ksoyadi;
    } cbil;
    struct kisi *baba, *ana, *es, *cocuklar[MAKSCCK];
} kisiler[MAKSKS];

union cifdg {
    char c;
    int i;
    float f;
    double d;
    int *g;
}   bd = {'A'};

int main()
{
    /// yukarýdaki tanýtýcý sözcükler deðiþken ya da donksiyon deðillerdir (typedef olmasaydý öyle olacaktý)
    typedef unsigned short int kisa;
    typedef char *kdizisi, *kdfonk(char*, char*);
    typedef struct {float ger, im; } kompleks;
    typedef int vektor[7], matriks[8][6];
    typedef enum {yanlis, dogru} mantiksal;

    kisa i = 18, j = 18, k = 18;    /// unsigned short int i ,j, k;
    kdizisi s1, s2;                 /// char *s1, *s2
    kdfonk strcpy;                  /// char strcpy(char*, char*)
    kompleks z[5];                  /// struct{float ger, im;} z[5]
    vektor a[25];                    /// int a[8][6];
 //   matriks a;
    mantiksal m1, md = dogru, my = yanlis;

    printf("%zu %zu %zu %zu %zu (Note: All values are byte)\n", sizeof i, sizeof a, sizeof s1, sizeof z[3], sizeof 1.0);
    printf("%zu %zu %zu %zu %zu new = %zu (Note: All values are byte)\n", sizeof(int), sizeof(float), sizeof(double), sizeof(int*), sizeof(kompleks[3]), sizeof(a[1]));
    printf("%zu %zu %zu %zu %zu (Note: All values are byte)\n", sizeof(vektor), sizeof(long[4]), sizeof(struct{char *c; vektor v[5];}), sizeof *s1, sizeof(a[1]));
    printf("%zu\n", sizeof(signed int));
    /// %zu dönüþüm tanýmlamasý beklenen argümanýn size_t boyutunda olduðunu belirtir.
    // size_t

    /// union (Birlikler)
    // 5 adet yerpaylaþýmlý ðyeden oluþan bd birlik deðiþkeni tanýmlandý..


    printf("new == %zu\n", sizeof(bd));
    //bd.c = 't';
    bd.d = 9.8696044011;

    printf("%f\n", bd.d);

  //  printf("%f\n", bd.d);
  //printf("%d\n", bd.i);

    return 0;
}
