#include <stdio.h>
#include <stdlib.h>


//returnez maximul intre doua numere
int max (int a, int b)
{
    if (a > b)
        return a;
    return b;
}


//Creez o matrice care imi memoreaza lungimea maxima
int SubCom (int** M, int* A, int* B, int na, int nb)
{
    for (int i = 0; i <= na; i++)
    {
        for (int j = 0; j <= nb; j++)
        {
            if (i == 0 || j == 0)
                M[i][j] = 0;
            else if (A[i] == B[j])
                M[i][j] = M[i-1][j-1] + 1;
            else
                M[i][j] = max(M[i-1][j], M[i][j-1]);
        }
    }

    return M[na][nb];
}

int main()
{
    FILE *fin = fopen("date.in", "r");
    FILE *fout = fopen("date.out", "w");
    int na, nb;
    fscanf(fin, "%d %d", &na, &nb);


    int *A = (int *) malloc ( (na + 1) * sizeof(int));
    for (int i = 1; i <= na; i++)
        fscanf(fin, "%d", &A[i]);

    int *B = (int *) malloc ( (nb + 1) * sizeof(int));
    for (int i = 1; i <= nb; i++)
        fscanf(fin, "%d", &B[i]);


    int **M = (int **) malloc( (na + 1) * sizeof(int *));
    for (int i = 0; i <= na; i++)
        M[i] = (int *) malloc( (nb + 1) * sizeof(int));

    fprintf(fout, "%d\n", SubCom(M, A, B, na, nb)); //afisam nr de elemente ale subsirului

    int k = M[na][nb];
    if (k == 0) //daca nu eista un subsir afisam un mesaj corespunzator
    {
        fprintf(fout, "In sirul dat nu exista un subsir comun.");
    }
    else //afisam elementele subsirului comun
    {
        int* sol= (int *) malloc(k * sizeof(int));
        int i = na;
        int j = nb;
        while (i > 0 && j > 0)
        {
            if( A[i] == B[j] )
            {
                sol[k-1] = A[i];
                i--;
                j--;
                k--;
            }
            else if (M[i-1][j] > M[i][j-1])
                i--;
            else
                j--;
        }
        for (i=0; i<M[na][nb]; i++)
            fprintf(fout, "%d ", sol[i]);
        free(sol);
    }

    fclose(fin);
    fclose(fout);
    free(A);
    free(B);
    for (int i = 0; i <= na; i++)
        free(M[i]);
    free(M);
    return 0;
}
