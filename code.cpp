//Registro clientes del Gimnasio

#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>

//Limpiar pantalla
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(_unix_)||defined(_unix)||defined(__APPLE_)||defined(_MACH_)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif

using namespace std;


class menu
{
private:
    char nombre[30];
    char domicilio[30];
    char celular[20];
    char FechaPago[30];
    char codigoCliente[30];

public:
    void CrearCuenta();
    void bajaCliente();
    void modificarCliente();
    void listarClientes();
    void menuPrincipal();
    void detallesCliente();
    void mostarRegistro(char codigo [30]);
};

void pausa();
void error();

void menu::menuPrincipal()
{
    int opcion;
    do
    {
        cout<<"\t\t\t\t***Registro de Usuarios del BancoMatico***\t\t\t\t\n\n";
        cout<<"1. Crear Cuenta\n\n";
        cout<<"2. Mostrar detalles de Cuenta\n\n";
        cout<<"3. Listar Usuarios\n\n";
        cout<<"4. Dar de baja una Cuenta\n\n";
        cout<<"5. Modificar un Cuenta\n\n";
        cout<<"6. Salir\n\n";
        cout<<"Opci\242n: ";
        cin>>opcion;
        system(CLEAR);
        switch(opcion)
        {
        default:
            cout<<"Ha ingresado una opci\242n no valida!\n\n";
            break;

        case 1:
            CrearCuenta();
            break;

        case 2:
            detallesCliente();
            break;

        case 3:
            listarClientes();
            break;

        case 4:
            bajaCliente();
            break;

        case 5:
            modificarCliente();
            break;

        case 6:
            break;
        }
    }
    while(opcion!=6);
}

void menu::CrearCuenta()
{
    ofstream escritura;
    ifstream verificador;
    char auxCodigo[30];
    bool coincidencia=false;
    verificador.open("clientes.txt",ios::in);
    escritura.open("clientes.txt",ios::app);
    if(escritura.is_open()&&verificador.is_open())
    {
        cout<<"\t\t\t\t***Crear Cueta Bancaria***\t\t\t\t\n\n";
        fflush(stdin);
        cout<<"Ingresar numero  de Cuenta: ";
        cin.getline(auxCodigo,30);
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
        system(CLEAR);
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

void menu::bajaCliente()
{
    ifstream lectura;
    ofstream auxiliar;
    bool encontrado=false;
    char auxCodigo[30];
    char respuesta[5];
    lectura.open("clientes.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    cout<<"\t\t\t\t***Dar de baja un cliente***\t\t\t\t\n\n";
    if(lectura.is_open()&&auxiliar.is_open())
    {
        fflush(stdin);
        cout<<"Ingresa el c\242digo del cliente que deseas dar de baja: ";
        cin.getline(auxCodigo,30);
        lectura>>codigoCliente;
        while(!lectura.eof())
        {
            lectura>>nombre>>domicilio>>celular>>FechaPago;
            if(strcmp(auxCodigo,codigoCliente)==0)
            {
                encontrado=true;
                cout<<"\n\nRegistro Encontrado\n\n";
                cout<<"C\242digo: "<<codigoCliente<<endl;
                cout<<"Nombre: "<<nombre<<endl;
                cout<<"Domicilio: "<<domicilio<<endl;
                cout<<"Celular: "<<celular<<endl;
                cout<<"Fecha de inscripci\242n: "<<FechaPago<<endl;
                cout<<"\n\n";
                cout<<"Realmente deseas dar de baja a: "<<nombre<<" (s/n)?: ";
                cin.getline(respuesta,5);
                if(strcmp(respuesta,"s")==0||strcmp(respuesta,"S")==0||
                        strcmp(respuesta,"si")==0||strcmp(respuesta,"SI")==0||
                        strcmp(respuesta,"Si")==0||strcmp(respuesta,"sI")==0)
                {
                    cout<<"\n\nEl cliente se ha dado de baja correctamente\n\n";
                }

                else
                {

                    cout<<"\n\nCliente conservado\n\n";
                    auxiliar<<codigoCliente<<"\n\n"<<nombre<<"\n\n"<<domicilio<<"\n\n"<<celular
                            <<"\n\n"<<FechaPago<<"\n\n";

                }

            }
            else
            {
                auxiliar<<codigoCliente<<"\n\n"<<nombre<<"\n\n"<<domicilio<<"\n\n"<<celular
                        <<"\n\n"<<FechaPago<<"\n\n";
            }
            lectura>>codigoCliente;
        }
        if(encontrado==false)
        {
            cout<<"\n\nNo se encontr\242 el c\242digo: "<<auxCodigo<<"\n\n";
        }

    }
    else
    {
        error();
    }
    lectura.close();
    auxiliar.close();
    remove("clientes.txt");
    rename("auxiliar.txt","clientes.txt");
    pausa();
}

void menu::detallesCliente()
{
    char auxCodigo [30];
    ifstream mostrar;
    bool encontrado=false;
    mostrar.open("clientes.txt",ios::in);
    if(mostrar.is_open())
    {
        fflush(stdin);
        cout<<"\t\t\t\t***Consultar detalles de un cliente***\t\t\t\t\n\n";
        cout<<"Ingresa el c\242digo del cliente que deseas consultar detalles: ";
        cin.getline(auxCodigo,30);
        mostrar>>codigoCliente;
        while(!mostrar.eof())
        {
            mostrar>>nombre>>domicilio>>celular>>FechaPago;
            if(strcmp(auxCodigo,codigoCliente)==0)
            {
                encontrado=true;
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

        if(encontrado==false)
        {
            cout<<"\n\nNo se encontro el registro: "<<auxCodigo<<"\n\n";
        }
    }

    else
    {
        error();
    }

    mostrar.close();
    pausa();
}

void menu::modificarCliente()
{
    ifstream lectura;
    ifstream verificador;
    ofstream auxiliar;
    char auxCodigo[30];
    char codigoModif[30];
    char auxNombre[30];
    char auxDomicilio[30];
    char auxCelular[20];
    char auxFecha[30];
    bool encontrado=false;
    bool coincidencia=false;
    bool mismoCodigo=false;
    lectura.open("clientes.txt",ios::in);
    verificador.open("clientes.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    cout<<"\t\t\t\t***Modificar los datos de un cliente***\t\t\t\t\n\n";
    if(lectura.is_open()&&verificador.is_open()&&auxiliar.is_open())
    {
        fflush(stdin);
        cout<<"Ingresa el c\242digo del cliente que deseas modificar: ";
        cin.getline(auxCodigo,30);

        if(strcmp(auxCodigo,"")==0)
        {
            do
            {
                cout<<"c\242digo de cliente no v\240lido!, intentalo nuevamente: ";
                cin.getline(auxCodigo,30);
            }
            while(strcmp(auxCodigo,"")==0);
        }

        strcpy(codigoModif,auxCodigo);

        lectura>>codigoCliente;
        while(!lectura.eof())
        {
            lectura>>nombre>>domicilio>>celular>>FechaPago;
            if(strcmp(auxCodigo,codigoCliente)==0)
            {
                encontrado=true;
                mostarRegistro(codigoModif);

                cout<<"********************************************";
                cout<<"\n\n";
                cout<<"Ingresa la nueva informaci\242n para el cliente\n\n";
                fflush(stdin);
                cout<<"Ingresa el c\242digo del cliente: ";
                cin.getline(auxCodigo,30);
                if(strcmp(auxCodigo,codigoModif)==0)
                {
                    mismoCodigo=true;
                }
                if(mismoCodigo==false)
                {
                    do
                    {
                        if(strcmp(auxCodigo,codigoModif)==0)
                        {
                            coincidencia=false;
                            break;
                        }
                        verificador.seekg(0);
                        verificador>>codigoCliente;
                        while(!verificador.eof())
                        {
                            verificador>>nombre>>domicilio>>celular>>FechaPago;

                            if(strcmp(codigoCliente,auxCodigo)==0)
                            {
                                coincidencia=true;
                                cout<<"\n\nYa existe un cliente con ese c\242digo!\n\n";
                                cout<<"El cliente con ese c\242digo es: "<<nombre<<"\n\n";
                                cout<<"Ingresa un c\242digo v\240lido!: ";
                                cin.getline(auxCodigo,30);

                                if(strcmp(auxCodigo,"")==0)
                                {
                                    do
                                    {
                                        cout<<"\nc\242digo de cliente no v\240lido!, ";
                                        cout<<"intentalo nuevamente: ";
                                        cin.getline(auxCodigo,30);
                                    }
                                    while(strcmp(auxCodigo,"")==0);
                                }
                                break;
                            }

                            verificador>>codigoCliente;
                        }

                        if(verificador.eof()&&strcmp(auxCodigo,codigoCliente)!=0)
                        {
                            coincidencia=false;
                        }

                    }
                    while(coincidencia==true);
                }
                system(CLEAR);
                cout<<"***Modificar los datos de un cliente***\n\n";
                cout<<"Ingresa el c\242digo del cliente que deseas modificar: ";
                cout<<codigoModif;
                mostarRegistro(codigoModif);
                cout<<"********************************************";
                cout<<"\n\n";
                cout<<"Ingresa la nueva informaci\242n para el cliente\n\n";
                cout<<"Ingresa el c\242digo del cliente: ";
                cout<<auxCodigo;
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa el nombre del cliente: ";
                cin.getline(auxNombre,30);
                fflush(stdin);
                cout<<"\n\n";
                cout<<"Ingresa el domicilio del cliente: ";
                cin.getline(auxDomicilio,30);
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa el n\243mero de telefono del cliente: ";
                cin.getline(auxCelular,20);
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa la fecha de inscripci\242n del cliente: ";
                cin.getline(auxFecha,30);
                cout<<"\n\n";
                auxiliar<<auxCodigo<<"\n\n"<<auxNombre<<"\n\n"<<auxDomicilio<<"\n\n"<<auxCelular
                        <<"\n\n"<<auxFecha<<"\n\n";
                cout<<"El Registro se ha modificado correctamente.\n\n";
            }


            else
            {

                auxiliar<<codigoCliente<<"\n\n"<<nombre<<"\n\n"<<domicilio<<"\n\n"<<celular
                        <<"\n\n"<<FechaPago<<"\n\n";
            }


            lectura>>codigoCliente;
        }

    }
    else
    {
        error();
    }

    if(encontrado==false)
    {
        cout<<"\n\nNo se encontr\242 ning\243n registro con ese c\242digo!\n\n";
    }
    lectura.close();
    verificador.close();
    auxiliar.close();
    remove("clientes.txt");
    rename("auxiliar.txt","clientes.txt");
    pausa();
}

void menu::listarClientes()
{
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
    system(CLEAR);
}

int main()
{
    system ("color f0");
    menu inicio;
    inicio.menuPrincipal();
    return 0;
}

void error()
{
    cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
    cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
    cout<<"clientes.txt, si el archivo tiene otro nombre ren\242mbrelo al ya mencionado\n\n";
}

void menu::mostarRegistro(char codigo[30])
{

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
