#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int registro (int FILE*profesionales, FILE*pass)
{
	char nom1 [10];
	char nom2 [10];
	
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
					fread (&password, sizeof(char), 1, pass);
					while (!feof(pass))
					{
						if (strcmp (nom1,password)==0)
						gg=1; 
						return (gg);
						
						else
						fread (&password, sizeof(char), 1, pass);
					}
				}
				else
				{
					fread (&nombre, sizeof(char), 1, profesionales);
				}
			}
	if (gg=0)
	{
		printf ("\n Ingrese nuevamente el usuario y contraseña");
		return (gg);
	}
	//consulte un archivo con las contraseñas, las compara una por una hasta encontrar una igual
}

void lista (FILE*archi)

{
	int ID;
	clientes = fopen ("clientes.dat","r+");
	archi = fopen ("Turnos.dat","r+");
	
	printf ("\n Ingrese su ID de profesional");
	scanf ("%d", &ID);
	fread (&regi, sizeof(regi), 1, archi);
	while (!feof(archi))
    {	
    	if (ID == regi.idprof)
    	{
			printf ("\n\n Apellido y nombre: %s ", empresa.apyn);
			printf ("\n\n DNI: %d ", regi.dni);
			printf ("\n\n Detalle de atención: %s ", regi.detaten);
			printf ("\n\n %d - %d - %d ", regi.fech.year, regi.fech.mes, regi.fech.dia);
    		printf ("\n\n ------------------------------------- \n\n");	
    		fread (&regi, sizeof(regi), 1, archi);
   		}
	}
	fclose (archi);	
}

int plus (FILE* ficha, FILE* archi, FILE* clientes)

{
	
	char auxnom[60];
	int dia,mes,anio, DNIp;
	char evolucion [380];
	
	ficha = fopen("tratamiento.txt","ab+");
	clientes = fopen("clientes.dat","ab+");
	Turnos = fopen("Turnos.dat","ab+");
	
	//realizar copia
	
	printf (" Ingrese el DNI del paciente: ");
	scanf ("%d", &DNIp);
	while (DNIp == regi.dni)
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
	
