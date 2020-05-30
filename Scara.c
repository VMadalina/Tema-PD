#include <stdio.h>
#include <stdlib.h>
/**
O scară are n trepte. O persoană poate urca treptele pășind de pe o
treaptă pe alta sau sărind peste câte o treaptă. Se cere să se determine
numărul de modalități de a urca scara.
**/

//Aflu modalitatile prin care poate urca treptele
int Modalitati (int* rez , int n )
{
    rez[0] = 1;
    rez[1] = 1;
    for ( int i = 2; i <= n; i++)
    {
        rez[i] = 0;
        for ( int j = 1; j <= i; j++)
        {
            if ( j <= 2)
                rez[i] = rez[i] + rez[i-j];
        }
    }
    return rez[n-1];
}

//Aflu cate astfel de modalitati sunt
int NrModalitati ( int* rez , int n)
{
    return Modalitati(rez , n+1 );
}

int main()
{
    FILE* fin = fopen("date.in" , "r");
    FILE* fout = fopen("date.out" , "w");
    int n;
    fscanf(fin , "%d" , &n);
    int* rez = (int *) malloc(n * sizeof(int));
    fprintf(fout , "%d" , NrModalitati(rez , n));
    fclose(fin);
    fclose(fout);
    free(rez);
    return 0;
}
