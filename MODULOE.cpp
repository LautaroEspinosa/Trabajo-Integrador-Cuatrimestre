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
	FILE*profesionales;
	FILE*pass;
	
	profesionales = fopen ("profesionales.dat","r");
	pass = fopen ("contrasenas.dat","r");
	
	printf ("\t Iniciar sesion \n");
	_flushall();
	printf ("\nIngrese su nombre de usuario: ");
	gets (nom1);
	fread (&nombre, sizeof(char), 1, profesionales);
		while (!feof(profesionales))
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
						gg=1; 
						return (gg);
						
						else
						fread (&contrasenas, sizeof(char), 1, pass);
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
	//consulte un archivo con las contraseñas, las compara una por una hasta encontrar una igual
	//Cada contraseña tiene asiganada un numero
	
}

int lista ()

{
	FILE*clientes;
	FILE*Turnos;
	clientes = fopen ("clientes.dat","r+");
	turnos = fopen ("turnos.dat","r+");

	fread (&turnos, sizeof(char), 1, arch);
	
	while (!feof(arch) )
    {	
    	{
			printf ("\n\n Apellido y nombre: %s ", empresa.apyn);
			printf ("\n\n Numero de vendedor: %d ", empresa.numv);
			printf ("\n\n Importe: %f ", empresa.importe);
			printf ("\n\n Forma de pago: %d ", empresa.form);
			printf ("\n\n Factura: %d ", empresa.fact);
			printf ("\n\n %d - %d - %d ", empresa.fecc.anio, empresa.fecc.mes, empresa.fecc.dia);
    		printf ("\n\n ------------------------------------- \n\n");	
    		fread (&empresa, sizeof(registro), 1, arch);
   		}
	}
	
}

int plus ()

{
	FILE* clientes;
	FILE* Turnos;
	FILE* ficha;
	char auxnom[60];
	int dia,mes,anio;
	char evolucion [380];
	
	ficha = fopen("tratamiento.txt","ab+");
	clientes = fopen("clientes.dat","ab+");
	Turnos = fopen("turnos.dat","ab+");
	
	printf (" Ingrese el DNI del paciente: ");
	scanf ("%d", &DNIp);
	while (DNIp == DNI.reg)
		{
			if (DNIp == DNI.reg)
			printf ("Nombre: %s \n Apellido: %s \n DNI: %d \n CodP: ")
		}
		
	ficha = fopen("tratamiento.txt","ab+");
	
	_flushall();
	printf ("\n Escriba su nombre: ");
		gets (auxnom);
	printf("\n Escriba el día de la fecha ");
		scanf ("%d", &dia);
		scanf ("%d", &mes);
		scanf ("%d", &anio);
		fprintf (tratamiento.txt "\n Dia: %d / Mes: %d / Anio: %d", dia, mes, anio );
	_flushall();
	printf("\n Evolucion del paciente (por favor no exceder los 380 caracteres) \n ");	
		gets (evolucion);
		fprintf (tratamiento.txt "%s", evolucion );
	fclose(ficha);
	

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
		
	fclose (profesionales);
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
	
