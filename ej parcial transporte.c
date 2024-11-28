/* La empresa Corrientes Transporta S.A.  se dedica a la prestaci´no de servicios de mensajería y paquetería.
Desea controlar  los viajes realizados por sus 25 vehículos, para lo cual se ingresan los datos de dichos vehículos:
-Cod (int 1001 y 1025)
-Capacidad max en kilos a transportar (real entre 100 y 10000)
En un segundo lote de datos se ingresan por cada viaje realizado en el mes, el siguiente detalle:
Cod vehiculo,
Peso total de mercaderia transportada (real mayor a 0)

Se debe rechazar el viaje cuando se supere el maximo de cada vehiculo.
Dentro del mes un veiculo puede hacer varios viajes, uno o ninguno. La finalizacion de la carga es cod vehiculo =0.
SE PIDE
a) INformar la cantidad de viajes rechazados pro cada uno de los vehiculos
b) Informar los kilos transportados por cada vehiculo con el siguiente diseño
c) Informar el codigo de vehiculo que ha realizado la manoer cantidad de viajes, dentro d los q realizaron. Informar si hay mas de uno.

*/
#include <stdio.h>
#include <stdlib.h>

int ValidarDato(int lim_inf,int lim_sup,int fin);
float ValidarKilos(float lim_inf, float lim_sup);
float MayorA(float lim_inf);
int BuscoMinimo(int vec[],int ce);
void BuscoIgual(int vec[], int ce, int nro,int despl);
void MostrarVector(int vec[],int ce,int despl);
void MostrarVector_Reales(float vec[],int ce,int despl);


int main()
{
    int cod_vehiculo,cant_vehiculos=0,min_viajes=0,vec_cantViajesRechazados[25]= {0}, vec_cantViajesRealizados[25]= {0};
    float vec_capacidadMax[25],vec_transportada[25];

    printf("\n INGRESE CODIGO DE VEHICULO [1001 A 1025, 0 PARA TERMINAR]:\n");
    cod_vehiculo=ValidarDato(1001,1025,0);

    while(cod_vehiculo!=0&& cant_vehiculos<25)
    {
        printf("\nINGRESE CAPACIDAD DE TRANSPORTE [KILOS, numero real >100]:\n");
        /*Max_kilos_transp=ValidarKilos(100,10000); ? se ingresan todos los valores max?*/
        vec_capacidadMax[cod_vehiculo-1001]=ValidarKilos(100,10000);

        printf("\nINGRESE PESO TOTAL DE MERCADERIA TRANSPORTADA:\n");
        vec_transportada[cod_vehiculo-1001]+=MayorA(0);

        if(vec_capacidadMax[cod_vehiculo-1001]<vec_transportada[cod_vehiculo-1001])
        {
            vec_cantViajesRechazados[cod_vehiculo-1001]++;
        }
        else
        {
            vec_cantViajesRealizados[cod_vehiculo-1001]++;
        }

        cant_vehiculos++;
        printf("\n INGRESE CODIGO DE VEHICULO [1001 A 1025, 0 PARA TERMINAR]:\n");
        cod_vehiculo=ValidarDato(1001,1025,0);

    }

    if(cant_vehiculos>0)
    {
        printf("******************PUNTO A*******************************");
        printf("\nCANTIDAD DE VIAJES RECHAZADOS POR VEHICULO\n\tVEHICULO\t\tCANT. RECHAZOS\t\n:");
        MostrarVector(vec_cantViajesRechazados,cant_vehiculos,1001); /* aun no declaraste la funcion mostrar*/


        printf("******************PUNTO B*******************************");
        printf("\nCANTIDAD DE KILOS TRANSPORTADOS POR VEHICULO\n\tVEHICULO\t\tCANT. KILOS\t\n:");
        MostrarVector_Reales(vec_transportada,cant_vehiculos,1001); /* aun no declaraste la funcion mostrar*/

        printf("******************PUNTO C*******************************");
        printf("\nCOD. VEHICULO/S CON MENOR CANTIDAD DE VIAJES\nCOD VEHICULO\t\tCANT.VIAJES\n:");
        min_viajes=BuscoMinimo(vec_cantViajesRealizados,25);
        BuscoIgual(vec_cantViajesRealizados,25,min_viajes,1001);
    }


    system("pause");
    return 0;
}

int ValidarDato(int lim_inf,int lim_sup, int fin)
{
    int dato, band=0;
    do
    {
        if(band==0)
        {
            scanf("\n%d",&dato);
        }
        else
        {
            printf("\nERROR. Reingrese dato. Debe ser menor a %d y mayor a %d.\n",lim_sup,lim_inf);
            scanf("\n%d",&dato);
        }
    }
    while((dato<lim_inf||dato>lim_sup)&&dato!=fin);
    return dato;
}

float ValidarKilos(float lim_inf, float lim_sup)
{
    int dato,band=0;
    do
    {
        if(band==0)
        {
            scanf("\n%f",&dato);
        }
        else
        {
            printf("\nERROR. Reingrese dato. Debe ser menor a %f y mayor a %f.\n",lim_sup,lim_inf);
            scanf("\n%f",&dato);
        }
    }
    while(dato<lim_inf||dato>lim_sup);
    return dato;
}

float MayorA(float lim_inf)
{
    int dato,band=0;
    do
    {
        if(band==0)
        {
            scanf("\n%d",&dato);
        }
        else
        {
            printf("\nERROR. Reingrese dato. Debe ser mayor a %f\n",lim_inf);
            scanf("\n%f",&dato);
        }
    }
    while(dato<lim_inf);
    return dato;
}

int BuscoMinimo(int vec[],int ce)
{
    int i,min,band=0;
    for (i=0; i<ce; i++)
    {
        if(vec[i]!=0)
        {
            if(band==0||vec[i]>min)
                min=vec[i];
            band=1;
        }
    }
    return min;
}

void BuscoIgual(int vec[], int ce, int nro,int despl)
{
    int i, band=0;
    for (i=0; i<ce; i++)
    {
        if(vec[i] == nro)
            printf ("\t%d", i+despl);
    }
}

void MostrarVector(int vec[],int ce,int despl)
{
    int i;
    for (i=0; i<ce; i++)
    {
        if(vec[i]!=0)
            printf ("\n%d", i+despl,vec[i]);
    }
}

void MostrarVector_Reales(float vec[],int ce,int despl)
{
    int i;
    for (i=0; i<ce; i++)
    {
        if(vec[i]!=0)
            printf ("\n%d", i+despl,vec[i]);
    }
}
