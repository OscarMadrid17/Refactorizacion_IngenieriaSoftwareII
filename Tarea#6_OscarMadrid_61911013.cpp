#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;


void Menu()
{
 cout<<"SELECCIONE LA OPCION QUE DESEA EJECUTAR"<<endl;
 cout<<"1.) Grabar las Notas de los Alumnos. "<<endl;
 cout<<"2.) Lista de las Notas de los Alumnos. "<<endl;
 cout<<"3.) Borrar las Notas de los Alumnos. "<<endl;
 cout<<"0.) Salir. "<<endl;
}


void Grabar(){
	
    string nombreArchivo="notas.txt";
    
    ofstream archivo(nombreArchivo.data(),ios::out |ios::app);

    if(!archivo){
     cout << "Error. No se pudo abrir el archivo." << endl;    
    } 
    
    int Codigo=0;
    char Nombre[20], Apellido[20];
    double Nota1;
	double Nota2;
	double Acumulado;
    
    cout << "Introduzca el Codigo del Alumno (0 para terminar): ";
    cin >> Codigo;
    
    while(Codigo  > 0){	
     cout << "Introduzca el Nombre del Alumno: ";
     cin >> Nombre;
     cout << "Introduzca el Apellido del Alumno: ";
     cin >> Apellido;
     cout << "Introduzca la Nota 1: ";
     cin >> Nota1;
     cout << "Introduzca la Nota 2: ";
     cin >> Nota2;
     cout << "Introduzca la Nota de Acumulativos: ";
     cin >> Acumulado;
     
     archivo << Codigo << " "
             << Nombre << " "
             << Apellido << " "
             << Nota1 << " "
             << Nota2 << " "
             << Acumulado << endl;
             
     cout << "Introduzca el Codigo del Alumno (0 para terminar): ";
     cin >> Codigo;
     } 
    archivo.close();
    
    cout << "Operacion finalizada con exito." << endl;
    cout << endl; 
   }


void Mostrar(){
	
    string nombreArchivo="notas.txt";
        
    ifstream archivo(nombreArchivo.data(),ios::in);

    int Codigo=0;
    char Nombre[20], Apellido[20];
    double Nota1;
	double Nota2;
	double Acumulado;
    
    cout << '\n'
         << setw(15) << "Codigo"
         << setw(15) << "Nombre"
         << setw(15) << "Apellido"
         << setw(10) << "Nota 1"
         << setw(10) << "Nota 2"
         << setw(15) << "Acumulativos"
         << setw(15) << "Total"
         << setw(15) << "Observacion"
         << fixed << setprecision(2)
         << endl;
    for(int i=0; i<120; i++)
        cout << '=';
    	cout << endl;
    
    archivo >> Codigo
            >> Nombre
            >> Apellido
            >> Nota1
            >> Nota2
            >> Acumulado;
            
    while(!archivo.eof()){
    	
        cout << setw(15) << Codigo
          	 << setw(15) << Nombre
             << setw(15) << Apellido
             << right << setw(10) << Nota1
             << right << setw(10) << Nota2
             << right << setw(15) << Acumulado
             << right << setw(15) << Nota1+Nota2+Acumulado
             << right << setw(10) << "Esta: ";if(Nota1+Nota2+Acumulado>=60){cout<<"Aprobado";}
											 if(Nota1+Nota2+Acumulado<60){cout<<"Reprobado";}
			 cout << endl;

        archivo >> Codigo
                >> Nombre
                >> Apellido
                >> Nota1
	        	>> Nota2
			    >> Acumulado;
    		} 
      
    archivo.close();
    cout << endl;
    cout << endl; 
    cout << "Operacion finalizada con exito." << endl;
    cout << endl;
    cout << endl;
	}


int Borrar(){
	
    string nombreArchivo="notas.txt";
    bool encontrado=false;
    
    ifstream archivo(
             nombreArchivo.data(),
             ios::in);

    if(!archivo)
    {
        cout << "Error.  No se pudo abrir el archivo."<< endl;
        system("pause");
        return -1;
    }
    
    ofstream archivoTemp("Temp.txt", ios::out);
    
    if(!archivoTemp)
    {
         cout << "Error.  No se pudo crear archivo temporal."<< endl;
         system("pause");
         return -1;
    }
    
    int Codigo=0, Buscador=0;
    char Nombre[20], Apellido[20];
    double Nota1;
    double Nota2;
    double Acumulado;
    
    cout << "Introduzca el Codigo del Alumno que Desea Borrar: ";
    cin >> Buscador;
    
    cout << '\n'
         << setw(15) << "Codigo"
         << setw(15) << "Nombre"
         << setw(15) << "Apellido"
         << setw(10) << "Nota 1"
         << setw(10) << "Nota 2"
         << setw(15) << "Acumulado"
         << setw(15) << "Total"
         << setw(15) << "Observacion"
         << fixed << setprecision(2)
         << endl;
    for(int i=0; i<120; i++)
        cout << '=';
    
    cout << endl;
    
    archivo >> Codigo
            >> Nombre
            >> Apellido
			>> Nota1
            >> Nota2
			>> Acumulado;
            
    while(!archivo.eof())
    {
         if(Codigo == Buscador) {
              encontrado = true;
              
        cout << setw(15) << Codigo
          	 << setw(15) << Nombre
             << setw(15) << Apellido
             << right << setw(10) << Nota1
             << right << setw(10) << Nota2
             << right << setw(15) << Acumulado
             << right << setw(15) << Nota1+Nota2+Acumulado
             << right << setw(10) << "Esta: ";if(Nota1+Nota2+Acumulado>=60){cout<<"Aprobado";}
											 if(Nota1+Nota2+Acumulado<60){cout<<"Reprobado";}
			 cout << endl;    
         }
         else
         	archivoTemp << Codigo
                        << Nombre
                        << Apellido
                        << Nota1
                        << Nota2
		                << Acumulado; 	 
						
			archivo >> Codigo
                    >> Nombre
                    >> Apellido
                    >> Nota1
	                >> Nota2
	                >> Acumulado;         
        }
    
    if(!encontrado) {
         cout << "\nEl Alumno no esta registrado...\n";
    }
    
    archivo.close();
    archivoTemp.close();

    if( remove( "notas.txt" ) != 0 )
        cout << "\nNo se pudo borrar el archivo." ;
    else {
        cout << "\nArchivo borrado.\n";
	}
    if ( rename("Temp.txt" , nombreArchivo.data()) == 0 )
        cout << "\nArchivo Renombrado.";
    else{
            cout << "\nNo se pudo renombrar el archivo." ;
    }
        
    cout << "\n\nOperacion finalizada con exito.\n\n";
    
    system("pause");
    return 0;
}


void SwitchCase(int Op){
	
	switch (Op){
		case 1: Grabar();
		break;
		case 2: Mostrar();
		break;
		case 3: Borrar();
		break;
		case 0: 
		break;	
		}
	}


int main(){
	
	int Op = 0;
	
	do{
		Menu();
		cin>>Op;
		if (Op != 0)SwitchCase(Op);
	}while(Op != 0);
}
