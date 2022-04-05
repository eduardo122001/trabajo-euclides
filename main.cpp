#include <iostream>
#include <ctime>
using namespace std;
/*
    a y b son NO negativos
    r ≤ b por el teorema de la division OJIto
    Teorema de la Recursividad => funcion recursiva
    Debe funcionar para todos los casos en general
    El minimo valor de a y b es 0 => Correctitud del algoritmo
        si a = 0 entonces mcd es b, y viceversa.
        Pero si ambos son 0 entonces el mcd es 0.
        a y b son NO negativos

 */

int a1,b1;
void Euclides_e (int a, int b, int*mcd, int* x, int* y)
{
    int x1,y1; // x y y primas
    if (b==0) // a.1 + b.0 = a => mcd
    {
        *mcd=a;
        *x=1;
        *y=0;
    }
    else
    {
        Euclides_e(b, a%b, mcd, x, y); // metodo de recursividad
        // Paso recursivo
        x1=*x;
        y1=*y;
        *x=y1;
        *y=x1-(a/b)*y1; // ecuacion => coeficientes uno por uno
    }
    a1=a;
    b1=b;
    // rectifico a y b para poder hallar y prima siguiente

}

int Euclides (int a, int b)
{
    if (b==0)//si b es igual a cero por propiedad: mcd(a,0)=a
    {
        return a;//por ende retornara el mcd: a
    }
    else//
    {
        return Euclides(b, a%b);
    }
}

void MostrarDatos (int a, int b, int x, int y, int mcd)
{
    cout<<"MCD en combinacion lineal"<<endl;
    cout<<a<<"( "<<x<<" ) "<<" + "<<b<<"( "<<y<<" ) "<<" = "<<mcd;
    cout<<endl;
}



int main()
{
    clock_t comienzo;
    int loop=1;
    int m,xs,ys;



    while(loop==true){
    xs=1;
    ys=0;
    cout<<"Digite dos numeros: ";cin>>a1>>b1;

    if (a1<=0 or b1<=0)
    {
        cout<<"Solo numeros positivos. "<<endl;
    }
    else
    {   comienzo=clock();
        m = Euclides(a1, b1);
        for( int i=0; i<100000000; i++ )  ;
        Euclides_e(a1, b1, &m, &xs, &ys);
        printf( "Segundos utilizados: %f s\n", (clock()-comienzo)/(double)CLOCKS_PER_SEC );
        MostrarDatos(a1, b1, xs, ys, m);

    }

    cout<<"Intentar denuevo? SI(1), NO(0):";cin>>loop;
    cout<<endl;
    }
    return 0;
}
