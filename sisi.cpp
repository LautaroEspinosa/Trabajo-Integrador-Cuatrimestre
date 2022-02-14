#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <modulos.h>

using namespace std;

void espacios()
{	
	turnos regi;
	user us;
	FILE*ar;
	FILE*pass;
	FILE*archi;
	FILE*arch;
	int gg;
	FILE *ficha;
	aux turno;
	
	int opc = 0;
	
	printf("%c============================================================================================%c\n", 201,187);
	printf("%c                        M E N U   D E  M O D U L O   E S P A C I O S                        %c\n", 186,186);
	printf("%c============================================================================================%c\n", 186,186);
	printf("%c                                                                                            %c\n", 186,186);
	printf("%c      1 - INICIAR SESION.                                                                   %c\n", 186,186);
	printf("%c                                                                                            %c\n", 186,186);
	printf("%c      2 - VISUALIZAR LISTA DE ESPERA DE TURNOS.                                             %c\n", 186,186);
	printf("%c                                                                                            %c\n", 186,186);
	printf("%c      3 - REGISTRAR EVOLUCION DEL TRATAMIENTO.                                              %c\n", 186,186);
	printf("%c                                                                                            %c\n", 186,186);
	printf("%c      4 - CERRAR APLICACION.                                                                %c\n", 186,186);
	printf("%c                                                                                            %c\n", 186,186);
	printf("%c============================================================================================%c\n", 200,188);
	
	printf("\n\tINGRESE SU OPCION: ");
	scanf("%d", &opc);
	 
	do
	{
		printf ("\n\n");
		system ("pause");
		
		switch (opc)
		{
			case 1:
					{
						system ("cls");
						printf("\tINICIAR SESION\n");
						registro(gg);         
						printf ("\n\n");   
						system ("pause");
						break;
					}
			case 2:
					{
						system ("cls");
						printf("\tVISUALIZAR LISTA DE ESPERA DE TURNOS\n");
						lista (arch);					
						printf ("\n\n");
						system ("pause");
						break;
					}
			case 3:
					{
						system ("cls");
						printf("\tREGISTRAR EVOLUCION DEL TRATAMIENTO\n");
						tratamiento (ficha,archi,turno);	
						printf ("\n\n");              
						system ("pause");
						break;
					}
		}
	} while (opc!=4);
	
	if (opc==4)   
	{
		system ("cls");
	}
}

void recepcionista()
{	int bandinises=0;
	int opc = 0;
	
	printf("%c============================================================================================%c\n", 201,187);
	printf("%c               M E N U   D E  M O D U L O   D E L  R E C E P C I O N I S T A                %c\n", 186,186);
	printf("%c============================================================================================%c\n", 186,186);
	printf("%c                                                                                            %c\n", 186,186);
	printf("%c      1 - INICIAR SESION.                                                                   %c\n", 186,186);
	printf("%c                                                                                            %c\n", 186,186);
	printf("%c      2 - REGISTRAR CLIENTE.                                                                %c\n", 186,186);
	printf("%c                                                                                            %c\n", 186,186);
	printf("%c      3 - REGISTRAR TURNO.                                                                  %c\n", 186,186);
	printf("%c                                                                                            %c\n", 186,186);
	printf("%c      4 - LISTADO DE ATENCIPN POR PROFESIONAL Y FECHA.                                      %c\n", 186,186);
	printf("%c                                                                                            %c\n", 186,186);
	printf("%c      5 - CERRAR APLICACION.                                                                %c\n", 186,186);
	printf("%c                                                                                            %c\n", 186,186);
	printf("%c============================================================================================%c\n", 200,188);
	
	printf("\n\tINGRESE SU OPCION: ");
	scanf("%d", &opc);
	 
	do
	{
		printf ("\n\n");
		system ("pause");
		
		switch (opc)
		{
			case 1:
					{
						system ("cls");
						printf("\tINICIAR SESION\n");
						iniciarsesion();
						printf ("\n\n");   
						system ("pause");
						break;
					}
			case 2:
					{
						system ("cls");
						printf("\tREGISTRAR CLIENTE\n");
						regclient();
						printf ("\n\n");
						system ("pause");
						break;
					}
			case 3:
					{
						system ("cls");
						printf("\tREGISTRAR TURNO\n");
						regturno();
						printf ("\n\n");              
						system ("pause");
						break;
					}
			case 4:
					{
						system ("cls");
						printf("\tLISTADO DE ATENCIONES POR PROFESIONAL Y FECHA\n");
						listado();
						printf ("\n\n");              
						system ("pause");
						break;
					}
		}
	} while (opc!=5);
	
	if (opc==5)   
	{
		system ("cls");
	}
}

void administracion()
{
	int opc = 0;
	
	printf("%c============================================================================================%c\n", 201,187);
	printf("%c                  M E N U   D E  M O D U L O   A D M I N I S T R A C I O N                  %c\n", 186,186);
	printf("%c============================================================================================%c\n", 186,186);
	printf("%c                                                                                            %c\n", 186,186);
	printf("%c      1 - REGISTRAR PROFESIONAL.                                                            %c\n", 186,186);
	printf("%c                                                                                            %c\n", 186,186);
	printf("%c      2 - REGISTRAR USUARIO RECEPCIONISTA.                                                  %c\n", 186,186);
	printf("%c                                                                                            %c\n", 186,186);
	printf("%c      3 - ATENCIONES POR PROFECIONAL.                                                       %c\n", 186,186);
	printf("%c                                                                                            %c\n", 186,186);
	printf("%c      4 - RANKING DE PROFECIONALES POR ATENCION.                                            %c\n", 186,186);
	printf("%c                                                                                            %c\n", 186,186);
	printf("%c      5 - CERRAR APLICACION.                                                                %c\n", 186,186);
	printf("%c                                                                                            %c\n", 186,186);
	printf("%c============================================================================================%c\n", 200,188);
	
	printf("\n\tINGRESE SU OPCION: ");
	scanf("%d", &opc);
	 
	do
	{
		printf ("\n\n");
		system ("pause");
		
		switch (opc)
		{
			case 1:
					{
						system ("cls");
						printf("\tREGISTRAR PROFESIONAL\n");
						creacionUsuarioPro();
						printf ("\n\n");   
						system ("pause");
						break;
					}
			case 2:
					{
						system ("cls");
						printf("\tREGISTRAR USUARIO RECEPCIONISTA\n");
						creacionUsuarioRec();
						printf ("\n\n");
						system ("pause");
						break;
					}
			case 3:
					{
						system ("cls");
						printf("\tATENCION POR PROFECIONAL\n");
						atenxprof();
						printf ("\n\n");              
						system ("pause");
						break;
					}
			case 4:
					{
						system ("cls");
						printf("\tRANKING DE PROFECIONALES POR ATENCIONES\n");
						ranking();
						printf ("\n\n");              
						system ("pause");
						break;
					}
		}
	} while (opc!=5);
	
	if (opc==5)   
	{
		system ("cls");
	}
}

main()
{
	system ("color F0");
	
	int opc = 0;
	
	printf("%c============================================================================================%c\n", 201,187);
	printf("%c                                 M E N U   P R I N C I P A L                                %c\n", 186,186);
	printf("%c============================================================================================%c\n", 186,186);
	printf("%c                                                                                            %c\n", 186,186);
	printf("%c      1 - MODULO DE ESPACIOS.                                                               %c\n", 186,186);
	printf("%c                                                                                            %c\n", 186,186);
	printf("%c      2 - MODULO DEL RECEPCIONISTA.                                                         %c\n", 186,186);
	printf("%c                                                                                            %c\n", 186,186);
	printf("%c      3 - MODULO DE ADMINISTRACION.                                                         %c\n", 186,186);
	printf("%c                                                                                            %c\n", 186,186);
	printf("%c      4 - CERRAR PROGRAMA.                                                                  %c\n", 186,186);
	printf("%c                                                                                            %c\n", 186,186);
	printf("%c============================================================================================%c\n", 200,188);
	
	printf("\n\tINGRESE SU OPCION: ");
	scanf("%d", &opc);
	 
	do
	{
		printf ("\n\n");
		system ("pause");
		
		switch (opc)
		{
			case 1:
					{
						system ("cls");
						espacios();
						printf ("\n\n");
						opc=4;
						break;
					}
			case 2:
					{
						system ("cls");
						recepcionista();
						printf ("\n\n");
						opc=4;
						break;
					}
			case 3:
					{
						system ("cls");
						administracion();
						printf ("\n\n");
						opc=4;
						break;
					}
		}
	} while (opc!=4);
	
	if (opc==4)   
	{
		system ("cls");
		printf ("\n\tFIN DE LA APLICACION.\n");
	}
}
