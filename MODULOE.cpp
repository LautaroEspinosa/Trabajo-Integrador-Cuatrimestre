#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int menu()
{
	int opcion = 0;
	
	printf ("\tMENU PRINCIPAL DE DOCTOR *Insertar nombre*");
	printf ("\n1. Visualizar lista de espera.");
	printf ("\n2. Registrar datos de evolucion del tratamiento.");
	printf ("\n3. Salir.");
	
	return opcion;
}

int registro (int gg)
{
	char nom1 [20];
	char pass1 [20];
	arch = fopen ("contraseñas.dat","r");
	
	printf ("\t Iniciar sesion \n");
	_flushall();
	printf ("\nIngrese su nombre de usuario: ");
	gets (nom1);
	//if (nom1 != X) Luego hay que tener una base de doctores para validar el registro
	_flushall();
	printf("\nIngrese su contraseña");
	gets (pass1); 
	//if (pass1 != X) Lo mismo que arriba y aqui gg == 1
	
	//idea: para abrir la informacion de un medico guardar en distintos archs su info
	//usar gg para indicar que arch de que medico voy a usar para acceder a la info mas facil
	//consulte un archivo con las contraseñas, las compara una por una hasta encontrar una igual
	//Cada contraseña tiene asiganada un numero
	
	return (gg);
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
	//agarrar un bloc de notas y aumentar texto	
}
main ()

{
	int opcc=0, N, I, gg=0;
	
	do
	{
		system("cls");
		while (gg==0)
		{
		gg = registro (gg);
		}
		
		opcc= menu();
		
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
	}
	
	
	menu();
	
	registro ();
	
	system("PAUSE");
}
