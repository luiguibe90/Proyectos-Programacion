//Registro clientes del Gimnasio

#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>


using namespace std;

void CrearCuenta();
void bajaCliente();
void modificarCliente();
void listarClientes();
void menuPrincipal();
void detallesCliente();
void mostarRegistro(char codigo []);



void pausa();
void error();

void menuPrincipal()
{
    int opcion;
    do
    {
        cout<<"\t\t\t\t***Registro de Usuarios Gimnasio***\t\t\t\t\n\n";
        cout<<"1. Crear Ficha De Inscripcion\n";
        cout<<"2. Listar Clientes Inscritos\n";
        cout<<"3. Salir\n\n";
        cout<<"Opci\242n: ";
        cin>>opcion;
        system("cls");
        switch(opcion)
        {
        default:
            cout<<"Ha ingresado una opci\242n no valida!\n\n";
            break;

        case 1:
            CrearCuenta();
            break;

        case 2:
            listarClientes();
            break;

        case 3:
            cout<<"GRACIAS POR USAR EL PROGRAMA";
            break;
        }
    }
    while(opcion!=3);
}

void CrearCuenta()
{

     char nombre[30];
    char domicilio[30];
    char celular[20];
    char FechaPago[30];
    char codigoCliente[30];

    ofstream escritura;
    ifstream verificador;
    char auxCodigo[30];
    bool coincidencia=false;
    verificador.open("clientes.txt",ios::in);
    //verificador.open("clientes.txt",ios::in)
    escritura.open("clientes.txt",ios::app);
    if(escritura.is_open()&&verificador.is_open())
    {
        cout<<"\t\t\t\t***Crear Cueta Bancaria***\t\t\t\t\n\n";
        fflush(stdin);
        cout<<"Ingresar numero  de Cuenta: ";
        cin.getline(auxCodigo,31);
        if(strcmp(auxCodigo,"")==0)
            do
            {
                cout<<"c\242digo de cuenta no v\240lido!, intentalo nuevamente: ";
                cin.getline(auxCodigo,30);
            }
            while(strcmp(auxCodigo,"")==0);
        do
        {
            verificador.seekg(0);
            verificador>>codigoCliente;
            while(!verificador.eof())
            {
                verificador>>nombre>>domicilio>>celular>>FechaPago;


                if(strcmp(codigoCliente,auxCodigo)==0)
                {
                    coincidencia=true;
                    cout<<"\n\nYa existe una cuenta con ese c\242digo!\n\n";
                    cout<<"El cuenta con ese c\242digo es: "<<nombre<<"\n\n";
                    cout<<"Ingresa una cuenta v\240lida!: ";
                    cin.getline(auxCodigo,30);
                    if(strcmp(auxCodigo,"")==0)
                        do
                        {
                            cout<<"\nc\242digo de cliente no v\240lido!, intentalo nuevamente: ";
                            cin.getline(auxCodigo,30);
                        }
                        while(strcmp(auxCodigo,"")==0);

                    break;
                }

                verificador>>codigoCliente;
            }

            if(verificador.eof()&&strcmp(auxCodigo,codigoCliente)!=0)
                coincidencia=false;

        }
        while(coincidencia==true);
        system("cls");
        strcpy(codigoCliente,auxCodigo);
        cout<<"\t\t\t\t***Dar de alta un cliente***\t\t\t\t\n\n";
        cout<<"Ingresa el c\242digo del cliente: ";
        cout<<codigoCliente;
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el nombre del cliente: ";
        cin.getline(nombre,30);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el domicilio del cliente: ";
        cin.getline(domicilio,30);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el n\243mero de telefono del cliente: ";
        cin.getline(celular,20);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa la fecha de inscripci\242n del cliente: ";
        cin.getline(FechaPago,30);
        cout<<"\n\n";

        escritura<<codigoCliente<<"\n\n"<<nombre<<"\n\n"<<domicilio<<"\n\n"<<celular
                 <<"\n\n"<<FechaPago<<"\n\n";

        cout<<"El registro se ha completado correctamente.\n\n";
    }

    else
    {
        error();
    }

    escritura.close();
    verificador.close();
    pausa();
}


void listarClientes()
{
     char nombre[30];
    char domicilio[30];
    char celular[20];
    char FechaPago[30];
    char codigoCliente[30];

    int i=0;
    ifstream lectura;
    lectura.open("clientes.txt",ios::in);
    if(lectura.is_open())
    {
        cout<<"\t\t\t\t***Listado de todos los clientes***\t\t\t\t\n\n";
        lectura>>codigoCliente;
        while(!lectura.eof())
        {
            i++;
            lectura>>nombre>>domicilio>>celular>>FechaPago;
            cout<<"C\242digo: "<<codigoCliente<<endl;
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Domicilio: "<<domicilio<<endl;
            cout<<"Celular: "<<celular<<endl;
            cout<<"Fecha de inscripci\242n: "<<FechaPago<<endl;
            cout<<"\n\n";
            lectura>>codigoCliente;
        }

        if(i==1)
            cout<<"Hay un solo cliente registrado en este gimnasio\n\n";

        else

            cout<<"Hay un total de "<<i<<" clientes registrados en este gimnasio\n\n";
    }
    else
    {
        error();
    }
    lectura.close();
    pausa();
}

void pausa()
{
    cout<<"Presiona Enter para continuar...";
    getch();
    system("cls");
}



void error()
{
    cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
    cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
    cout<<"clientes.txt, si el archivo tiene otro nombre ren\242mbrelo al ya mencionado\n\n";
}

void mostarRegistro(char codigo[30])
{

 char nombre[30];
    char domicilio[30];
    char celular[20];
    char FechaPago[30];
    char codigoCliente[30];

    ifstream mostrar;
    mostrar.open("clientes.txt",ios::in);
    mostrar>>codigoCliente;
    while(!mostrar.eof())
    {
        mostrar>>nombre>>domicilio>>celular>>FechaPago;
        if(strcmp(codigo,codigoCliente)==0)
        {
            cout<<"\n\nRegistro Encontrado\n\n";
            cout<<"C\242digo: "<<codigoCliente<<endl;
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Domicilio: "<<domicilio<<endl;
            cout<<"Celular: "<<celular<<endl;
            cout<<"Fecha de inscripci\242n: "<<FechaPago<<endl;
            cout<<"\n\n";
        }

        mostrar>>codigoCliente;
    }

    mostrar.close();
}


int main()
{
    menuPrincipal();
    return 0;
}
