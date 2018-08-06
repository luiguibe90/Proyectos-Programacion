#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;

int buscaenteros(int m[][100],int *pf,int *pc){
    int b;
    printf("\tBUSCAR EN MATRIZ\n");
    printf("\nIngrese numero que desea buscar\n");
    scanf("%d",&b);
    for(int i=0;i<*pf;i++){
        for(int j=0;j<*pc;j++){
            if(m[i][j]==b){
                printf("\nSe encontro el numero %d en la posicion [%d][%d]\n",b,i,j);
            }
        }
    }
return 0;
}
void contar(char *t){
    int z,e=0,v=0,c=0;
    fflush(stdin);
    printf("\nLa frase ingresada es: %s \n",t);
    z=strlen(t);
    tolower(*t);
    while(*t){ //conteo de vocales
        switch(*t){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u': v++;
        }*t++;
    }printf("\n hay %d vocales. \n",v);
    printf("\nla longitud de la cadena es %d\n",z);
}
int orden(int num[],int n){
    int aux;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(num[i]>num[j]){
                aux=num[i];
                num[i]=num[j];
                num[j]=aux;
            }
        }
    }
    printf("\nLos numeros ordenados son:\n");
        for (int i=0;i<n;i++){
            printf("%d-",num[i]);
        }
return 0 ;
}
int fact(int n){
    fflush(stdin);
    if(n==0) return 1;
    else return n*fact(n-1);
}

int main(){
    int o;

     do{
            //menu
        system("cls");
        fflush(stdin);//para liberar memoria
        printf("\tPROGRAMA RESUMEN\n");
        printf("\t\tMENU\n");
        printf("\n1.- Matrices:");
        printf("\n2.-Busqueda Lineal:");
        printf("\n3.-Conteo De Vocales:");
        printf("\n4.-Ordenamiento:");
        printf("\n5.-Funciones Recursivas:");
        printf("\n6.-SALIR:");

        printf("\nQue Opcion Desea:");
        scanf("%d",&o);

      switch (o)
      {
        case 1:
        {
               int f,c,om,*pf,*pc, matriz[100][100];
                pf=&f;
                pc=&c;
                    system("cls");
                    printf("\t MATRICES\n");
                    printf("\nIngrese valores para la matriz\n");
                    printf("\nCuantas Filas desea? :");
                    scanf("%d",pf);
                    printf("\nCuantas columnas desea? :");
                    scanf("%d",pc);
                    for(int i=0;i<*pf;i++){
                            for(int j=0;j<*pc;j++){
                                 fflush(stdin);
                                printf("\nIngrese numero para [%d][%d]: ",i,j);
                                scanf("%d",&matriz[i][j]);
                            }
                    }
                    system("cls");
                    printf("\nLA MATRIZ INGRESADA ES:\n");
                    for(int i=0;i<*pf;i++){
                            for(int j=0;j<*pc;j++){
                                fflush(stdin);
                                printf("%d ",matriz[i][j]);
                            }printf("\n");
                    }
                    printf("\nDesea buscar un numero en la matriz:?   1=si: 0=no\n");
                    scanf("%d",&om);
                    if(om==1){
                        buscaenteros(matriz,pf,pc);
                    }system("pause");

        break;
        }//aqui se cierra el case1
        case 2:
        {
            int t=0,numero=0 ,datoentero=0;
             cout<< "Ingresa el tamano del arreglo"<<endl;
            cin>> t ;
            int a[t];
            cout<< "Los numeros randomicos en desorden son: "<<endl;
            srand(time(NULL));

            for (int i=0;i<t;i++){
                numero=rand()%(100);
                a[i]=numero;
                cout<<numero<<endl;
            }


            cout<< "\nIngresa el numero aleatorio de la pantalla del que deseas la posicion "<<endl;
		cin>> datoentero ;
		printf("dato es %d",datoentero);
		system("pause");
		for (int j=0;j<t;j++){
			if (a[j]==datoentero){
				printf("\nEl numero se encuentra en la posicion: %d\n",j);

			}

		}

        system("pause");

        break;
        }//aqui se cierra el case2
        case 3:
        {

             char text[60],*t;
            t=&text[0];
            system("cls");
            printf("\t CONTADOR DE VOCALES Y CONSONANTES\n");
            printf("\n Ingrese texto: ");
            fflush(stdin);
            gets(t);
            contar(t);
            system("pause");
            system("cls");

        break;
        }//aqui se cierra el case3
        case 4:
        {
                 int n,num[20];
                system("cls");
                printf("\tORDENAMIENTO\n");
                printf("Cuantos numeros desea ingresar: ");
                scanf("%d",&n);
                for(int i=0;i<n;i++){
                        fflush(stdin);
                    printf("\nIngrese Numero %d: ",(i+1));
                    scanf("%d",&num[i]);
                }
                printf("\nLos numeros ingresados son:\n");
                for (int i=0;i<n;i++){
                    fflush(stdin);
                    printf("%d-",num[i]);
                }
                orden(num,n);
                system("pause");
                system("cls");
        break;
        }//aqui se cierra el case4
        case 5:
        {
                 int op,*o,n;
                    o=&op;
                    do{
                        fflush(stdin);
                        system("cls");
                        printf("\t FUNCIONES RECUSIVAS\n\n\n");
                        printf("\t menu\n");
                        printf("\n1.-Factorial");
                        printf("\n2.-Salir");
                        printf("\nQue desea hacer? ");
                        fflush(stdin);
                        scanf("%d",o);
                        system("cls");
                    }while(*o!=2);
                    switch (*o)
                    {

                        case 1:
                            fflush(stdin);
                            printf("\ningrese un numero: ");
                            scanf("%d",&n);
                            fflush(stdin);
                            printf("\nel factorial de %d es %d\n",n,fact(n));
                            system("pause");
                        break;
                        case 2:
                        break;
                    }

        break;
        }//aqui se cierra el case5
        case 6:
        break;
    }//aqui se cierra el switch
    }while(o!=6);//aqui se cierra el do while
return 0;
}
