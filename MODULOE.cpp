#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int menu(int gg)
{
	int opcion = 0;
	int x;
	
	if (gg )
	
	printf ("\tMENU PRINCIPAL DE DOCTOR %s ", );
	printf ("\n1. Visualizar lista de espera.");
	printf ("\n2. Registrar datos de evolucion del tratamiento.");
	printf ("\n3. Salir.");
	
	return opcion;
}

int registro (int gg)
{
	char nom1 [10];
	char nom2 [10];
	FILE*Usuario;
	FILE*pass;
	
	Usuario = fopen ("profesionales.dat","r");
	pass = fopen ("contraseñas.dat","r");
	
	printf ("\t Iniciar sesion \n");
	_flushall();
	printf ("\nIngrese su nombre de usuario: ");
	gets (nom1);
	fread (&nombre, sizeof(char), 1, Usuario);
		while (!feof(Usuario))
			{
				if (strcmp (nom1,nombre)==0)
				{
					_flushall();
					printf("\nIngrese su contraseña");
					gets (nom2); 
					fread (&contrasena, sizeof(char), 1, pass);
					while (!feof(pass))
					{
						if (strcmp (nom1,pass)==0)
						gg=1; // El numero de gg va a ser el indicador de que doctor estamos hablando;
						return (gg);
						
						else
						fread (&contrasena, sizeof(char), 1, pass);
					}
				}
				else
				{
					fread (&nombre, sizeof(char), 1, Usuario);
				}
			}
	if (gg=0)
	{
		printf ("\n Ingrese nuevamente el usuario y contraseña");
		return (gg);
	}
	//idea: para abrir la informacion de un medico guardar en distintos archs su info
	//usar gg para indicar que arch de que medico voy a usar para acceder a la info mas facil
	//consulte un archivo con las contraseñas, las compara una por una hasta encontrar una igual
	//Cada contraseña tiene asiganada un numero
	
	
}

int lista ()

{
	int auxg;
	//consultar el archivo segun la "llave" que tenga el gg
	arch = fopen ("contraseñas.dat","r");
	arch = fopen ("xxx.dat","r+");
	//auxg es una guia para el archivo del doctor a abrir
	
	if (auxg == n)
	{
		//abre los archivos de un doctor
	}
	n++;
	//limite de doctores?
}

int plus ()

{
	FILE* (registro de DNIs de pacientes)
	
	printf (" Ingrese el DNI del paciente: ");
	scanf ("%d", &DNIp);
	while (DNIp == DNI.reg)
		{
			if (DNIp == DNI.reg)
			printf ("Nombre: %s \n Apellido: %s \n DNI: %d \n CodP: ")
		}

	
	

	//tiene que salir de la cola de atendidos
}
main ()

{
	int opcc=0, N, I, gg=0;
	File*Usuario;
	FILE*pass;
	
	do
	{
		system("cls");
		while (gg==0)
		{
		gg = registro (gg);
		}
		
	fclose (Usuario);
	fclose (pass);
		
		opcc= menu(gg);
		printf ("\n\n Por favor selecciona una opcion: ");
		scanf ("%d", &opcc);
		system("cls");
		
		switch (opcc)
		{
			case 1:
					{
						system ("cls");
						printf("\tVisualizar lista de espera.\n");
						lista ();
						system("pause");
					}
			case 2:
					{
						system ("cls");
						printf("\tRegistrar datos de evolucion del tratamiento.\n");
						plus ();
						system("pause");
					}
					
	} while (opc!=3);
	
	if (opc==3)
	{
		printf ("\n\tFin del programa.\n");
	}
	
	return 0;
}
	
