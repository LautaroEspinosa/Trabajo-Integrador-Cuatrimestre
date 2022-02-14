#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<strings.h>


using namespace std;

int bandinises=0, bandinisesusu=0;

//estructuras
	//estructura de fecha
struct fecha{
	int dia;
	int mes;
	int year;
};

	//estructura de inicio de sesion de recep
struct recep{
	char usuario[11];
	char pass[33];
	char Apynom[61];
	int id;
	int dni;
	char tel[25];
};

	//estructura de inicio de sesion pro
struct user{
	char usuario[11];
	char pass[33];
	char Apynom[61];
	int id;
	int dni;
	char tel[25];
};

	//estructura de registro de clientes
struct cliente{
	char apeynom[60];
	char domicilio[60];
	int dni;
	char localidad[60];
	fecha fechnac;
	float peso;
	int telef[25]; 
};

	//estructura de registro de turnos
struct turnos{
	int idprof;
	fecha fech;
	int dni;
	char detaten[380];
	bool validez;
};

	//estructura aux de registro de turnos
struct aux
{
	int idprof;
	fecha fech;
	int dni;
	char detaten[380];
};

	

//modulo espacios
	//iniciar sesion
int registro ( int gg)
{	
		FILE *ar;
	char usuario1[11];
	char contra1[33];
	int contador=0, contcorr=0, usercorr=0, comp, comp2=1, i=0;
	user us[100];
	ar=fopen("Profesionales.dat","r+b");
	fread(&us, sizeof(user),1,ar);
	while(!feof(ar)){
		contador++;
		fread(&us, sizeof(user),1,ar);
	}
	printf("\nIngrese el nombre de usuario ");
	_flushall();
	gets(usuario1);
	comp=strcmp(usuario1,us[i].usuario);
	while(comp!=0){
		printf("\nEl usuario ingresado no esta registrado\n");
		system("pause");
		system("cls");
		printf("\nIngrese el nombre de usuario ");
		_flushall();
		gets(usuario1);
		i++;
		comp=strcmp(usuario1,us[i].usuario);
	}
		printf("\nIngrese la contrasenia: ");
		_flushall();
		gets(contra1);
		comp2=strcmp(contra1,us[i].pass);
	while (comp2!=0){
		printf("\nLa contrasenia ingresada es incorrecta \n");
		system("pause");
		system("cls");
		printf("\nIngrese la contrasenia: ");
		_flushall();
		gets(contra1);
		comp2=strcmp(contra1,us[i].pass);
	}
	if (comp2==0 and comp==0){
		bandinisesusu=1;
	}
	if(bandinisesusu==1){
		cout<<"\nIniciaste sesion correctamente\n";
		system("pause");
		system("cls");
	}
}

	//lista de espera
void lista (FILE*arch)

{
	if(bandinisesusu==1){

	int ID;
	arch = fopen ("Turnos.dat","r");
	turnos regi;
	printf ("\n Ingrese su ID de profesional");
	scanf ("%d", &ID);
	fread (&regi, sizeof(regi), 1, arch);
	while (!feof(arch))
    {	
    	if (ID == regi.idprof)
    	{
    		if (regi.validez = true)
    			{
					printf ("\n\n DNI: %d ", regi.dni);
					printf ("\n\n Detalle de atencion: %s ", regi.detaten);
					printf ("\n\n %d - %d - %d ", regi.fech.year, regi.fech.mes, regi.fech.dia);
    				printf ("\n\n ------------------------------------- \n\n");	
   				}
   			fread (&regi, sizeof(regi), 1, arch);		
  	 	}
	}
	fclose (arch);	
}
else{
cout<<"\nPrimero debe iniciar sesion";
	
}
}

	//evolucion de tratamiento
int tratamiento (FILE* ficha, FILE* archi, aux turno){
	if(bandinisesusu==1){
	char auxnom[60];
	int dia,mes,anio, DNIp;
	char evolucion [380];
	turnos regi;
	ficha = fopen("tratamiento.txt","ab+");
	archi = fopen("Turnos.dat","ab+");
	
	while (!feof(archi))
	{
		fread (&regi, sizeof(regi),1, archi);
		printf (" Ingrese el DNI del paciente: ");
		scanf ("%d", &turno.dni);
		if (turno.dni == regi.dni)
		{
			turno.fech.dia = regi.fech.dia;
			turno.fech.mes = regi.fech.mes;
			turno.fech.year = regi.fech.year;
			turno.idprof = regi.idprof;
			 strcpy(turno.detaten, regi.detaten );
		}
		else
		fread (&regi, sizeof(regi),1, archi);	
	}	
	ficha = fopen("tratamiento.txt","ab");
	_flushall();
	printf ("\n Escriba su nombre: ");
		gets (auxnom);
		fprintf(ficha, " \n Dia: %d / Mes: %d / Anio: %d", turno.fech.dia, turno.fech.mes, turno.fech.year );
	_flushall();
	printf("\n Evolucion del paciente (por favor no exceder los 380 caracteres) \n ");	
		gets (evolucion);
		fprintf (ficha, "prescripción: %s \n\n evolucion: %s", turno.detaten, evolucion );
	fclose(ficha);
	
	rewind (archi);
	while (!feof(archi))
	{
		if (turno.dni == regi.dni)
		{
			regi.validez=false;
			fseek(archi,-sizeof(regi),SEEK_CUR);
    		fwrite (&regi, sizeof(regi), 1, archi);
		}
		fread (&regi, sizeof(regi),1, archi);
	}
}
else{
	cout<<"\nPrimero debe iniciar sesion";
}
}
	



//modulo recepcionista
	//iniciar sesion
void iniciarsesion(){
	FILE *ar;
	char usuario1[11];
	char contra1[33];
	int contador=0, contcorr=0, usercorr=0, comp, comp2=1, i=0;
	recep rec[100];
	ar=fopen("recepcionistas.dat","r+b");
	fread(&rec, sizeof(recep),1,ar);
	while(!feof(ar)){
		contador++;
		fread(&rec, sizeof(recep),1,ar);
	}
	printf("\nIngrese el nombre de usuario ");
	_flushall();
	gets(usuario1);
	comp=strcmp(usuario1,rec[i].usuario);
	while(comp!=0){
		printf("\nEl usuario ingresado no esta registrado\n");
		system("pause");
		system("cls");
		printf("\nIngrese el nombre de usuario ");
		_flushall();
		gets(usuario1);
		i++;
		comp=strcmp(usuario1,rec[i].usuario);
	}
		printf("\nIngrese la contrasenia: ");
		_flushall();
		gets(contra1);
		comp2=strcmp(contra1,rec[i].pass);
	while (comp2!=0){
		printf("\nLa contrasenia ingresada es incorrecta \n");
		system("pause");
		system("cls");
		printf("\nIngrese la contrasenia: ");
		_flushall();
		gets(contra1);
		comp2=strcmp(contra1,rec[i].pass);
	}
	if (comp2==0 and comp==0){
		bandinises=1;
	}
	if(bandinises==1){
		cout<<"\nIniciaste sesion correctamente\n";
		system("pause");
		system("cls");
	}
}





	//Registrar cliente
void regclient(){
	if(bandinises==1){
	int N;
	FILE*arch;
	cliente reg;
	
	arch=fopen("Clientes.dat","a+b");
	if(arch==NULL){
		printf("\nerror al crear o abrir el archivo.");
		exit(1);	
	}	
	
	printf("\nIndicar el numero de clientes que desea registrar: ");
	scanf("%d",&N);
	
	for(int i=0; i<N; i++){
		printf("\n\tIngresar los datos del cliente:%d",i+1);
		printf("\nIngresar nombre y apellido: ");
		_flushall();
		gets(reg.apeynom);
		printf("\nIngresar domicilio: ");
		_flushall();
		gets(reg.domicilio);
		printf("\nIngresar numero DNI: ");
		scanf("%d",&reg.dni);
		printf("\nIngresar localidad de nacimiento: ");
		_flushall();
		gets(reg.localidad);
		printf("\nIngresar fecha de nacimiento:");
		printf("\nDia: ");
		scanf("%d",&reg.fechnac.dia);
		printf("\nMes: ");
		scanf("%d",&reg.fechnac.mes);
		printf("\nAnio: ");
		scanf("%d",&reg.fechnac.year);
		printf("\nIngesar peso actual: ");
		scanf("%f",&reg.peso);
		printf("\nIngresar numero de telefono de contacto: ");
		scanf("%d",&reg.telef);
	}
	fseek(arch,0,SEEK_END);
	fwrite(&reg,sizeof(reg),1,arch);
	printf("\n\tClientes registrados exitosamente!!");
	printf("\n\n");
	fclose(arch);
	system("pause");
	system("cls");
}
	else{
		cout<<"\nPrimero debe iniciar sesion";
	}
}

	//registrar turnos
void regturno(){
	bool validez=true;
	int T;
	FILE*archi;
	turnos regi;
	if(bandinises==1){	
	archi=fopen("Turnos.dat","a+b");
	if(archi==NULL){
		printf("\nerror al crear o abrir el archivo.");
		exit(1);	
	}	
	printf("Indicar la cantidad de turnos que se van a registrar: ");
	scanf("%d",&T);
	
	for (int i=0;i<T;i++){
		printf("\nRegistrar turno n%d:", i+1);
		printf("\nIngresar numero id del profesional: ");
		scanf("%d",&regi.idprof);
		printf("\nIngresar fecha programada: ");
		printf("\nDia: ");
		scanf("%d",&regi.fech.dia);
		printf("\nMes: ");
		scanf("%d",&regi.fech.mes);
		printf("\nAnio: ");
		scanf("%d",&regi.fech.year);
		printf("\nIngresar DNI del cliente: ");
		scanf("%d",&regi.dni);
		printf("\nIndicar detalles relevantes sobre la atencion: ");
		_flushall();
		gets(regi.detaten);
		//printf("\n");
	}
	fseek(archi,0,SEEK_END);
	fwrite(&regi,sizeof(regi),1,archi);
	printf("\n\tTurnos registrados exitosamente!!");
	printf("\n\n");
	fclose(archi);
	system("pause");
	system("cls");
}
	else{
		cout<<"\nPrimero debe iniciar sesion";
	}
}

	//listado de atenciones por fecha y profesional.
void listado(){
	if(bandinises==1){
	int cont=0,i,x,z,comp=0,d,m,a,cf=0;
	FILE *ar;
	ar=fopen("Turnos.dat","r+b");
	turnos turn[100];
	fread(&turn,sizeof(turnos),1,ar);
	while(!feof(ar)){
		cont++;
		fread(&turn,sizeof(turnos),1,ar);
	}
	fclose(ar);
	cout<<"\nDesea listar por profesional o por fecha? \n1--> Profesional\n2--> Fecha \n";
	cin>>x;
	switch (x){
		case 1:{
			cout<<"\nElija el id del profesional ";
			cin>>z;
			cout<<endl;
			system("pause");
			system("cls");
			cout<<"\nId del profesional "<<z;
			for(i=0;i<cont;i++){
				if(turn[i].idprof==z){
					comp++;
					cout<<"\nFecha\nDia "<<turn[i].fech.dia<<"\nMes "<<turn[i].fech.mes<<"\nAnio "<<turn[i].fech.year;
					cout<<"\n DNI PACIENTE "<<turn[i].dni<<"\nDetalle: ";
					puts(turn[i].detaten);
					cout<<"\n";
					system("pause");
					system("cls");
				}
				if(comp==0){
					cout<<"\nEl id ingresado no corresponde a ningun profesional";
				}
			}
			break;
		}
		case 2:{
			cout<<"\nElija la fecha: dia: ";
			cin>>d;
			cout<<"\nmes: ";
			cin>>m;
			cout<<"\nanio ";
			cin>>a;
			for(i=0;i<cont;i++){
				if(d==turn[i].fech.dia){
					if(m==turn[i].fech.mes){
						if(a==turn[i].fech.year){
							cf++;
					cout<<"\nFecha\nDia "<<turn[i].fech.dia<<"\nMes "<<turn[i].fech.mes<<"\nAnio "<<turn[i].fech.year;
					cout<<"\nId Profesional "<<turn[i].idprof;
					cout<<"\n DNI PACIENTE "<<turn[i].dni<<"\nDetalle: ";
					puts(turn[i].detaten);
					cout<<"\n";
					system("pause");
					system("cls");
						}
					}
				}
			}
			if(cf==0){
				cout<<"En la fecha ingresada no hay ningun turno registrado ";
			}
			
			break;
		}
	}
}
else{
		cout<<"\nPrimero debe iniciar sesion";
	}	
}



//modulo administracion 
	//creacion de usuario profesional
void creacionUsuarioPro( ){
	char nomus[100];
	int largo, i, comp, mayus=0,dig=0, conda=0,condb=0,condc=0,j, comparacionreg=0,bandera3=0, condD=0,bandera4=0;//variables de nombre de usuario
	int bandera,cant,numeros=0,mayus2=0,minus=0, cons=0,numcons=0, contracorrecta=0, letcons, band2=0, val2,val1,resultado=0,res;//variables de contrasena
	char password[100];
	//**************************************************************
	FILE *ar;
	int l=0;
	ar=fopen("Profesionales.dat", "a+b");
	int comprobacionusuario=0, tam=0;
	user us [100];
	rewind(ar);
	fread(&us[tam],sizeof(user),1,ar);
	
	while(!feof(ar)){
		tam++;
		fread(&us[tam],sizeof(user),1,ar);
	}
	cout<<"\ntam="<<tam;
	fclose(ar);
	//***********************************************
	
	
	cout<<"\nPrimero debe escoger un nombre de usuario";
	//CREACION NOMBRE DE USUARIO
	do{
		conda=0;
		condb=0;
		condc=0;
		condD=0;
		bandera3=0;
		bandera4=0;
	cout<<"\nIngrese el nombre de usuario deseado\nEl nombre de usuario debe:\na. Comenzar con una letra minuscula\nb. Tener al menos 2 letras mayusculas\nc. Tener como maximo 3 digitos\n ";
	_flushall();
	gets(nomus);
	largo=strlen(nomus);
	if (largo>=6 or largo <=10){
		condD=1;
}
	if(nomus[0]>=97 and nomus[0] <=122){
		conda=1;
	for(i=0;i<largo;i++){
		if(nomus[i]>=65 and nomus[i]<=90){
			mayus++;
		}
		if(nomus[i]>=42 and nomus[i]<=57){
			dig++;
		}
		if(nomus[i]==33 or nomus[i]==63 ){
			dig++;
		}
	}
}
if(mayus>=2){
	condb=1;
}
if(dig<=3){
	condc=1;
}
if(conda==1 and condb==1 and condc==1 and condD==1){
	for(i=0;i<tam;i++){
	comp=strcmp(us[i].usuario, nomus);
	if(comp==0){
		bandera3=1;
	}	
	}
}
else{
	cout<<"\nEl nombre de usuario no cumple con las condiciones requeridas\n";
	system("pause");
system("cls");
	
}
	if(bandera3==1){
		cout<<"El nombre de usuario ya ha sido escogido. Elija otro\n";
		system("pause");
system("cls");
	}
if(conda==1 and condb==1 and condc==1 and condD==1 and bandera3!=1){
	cout<<"\nEl nombre de usuario\n ";
	puts(nomus);
	cout<<" ha sido elegido correctamente.";
	bandera4=1;

	}
}while(bandera4==0);
system("pause");
system("cls");

//CREACION DE CONTRASEÑA

do{
		numeros=0;
		mayus2=0;
		minus=0;
		cons=0;
		numcons=0;
		contracorrecta=0;
		band2=0;
		resultado=0;
	cout<<"\nIngrese una password valida\n  1. Deberá contener al menos una letra mayuscula, una letra minuscula y un numero.\n2. No podra contener ningun caracter de puntuacion, ni acentos, ni espacios. Solo caracteres alfanumericos.\n3. Debera tener entre 6 y 32 caracteres. \n4. No debe tener mas de 3 caracteres numericos consecutivos. 5. No debe tener 2 caracteres consecutivos que refieran a letras alfabeticamente consecutivas (ascendentemente). Este criterio es valido tanto para letras mayusculas, minusculas o combinacion de ambas. ";
	gets(password);
	cant=strlen(password);

		
		for(i=0;i<cant;i++){
			bandera=0;
		if(password[i]>=48 and password[i]<=57){
			numeros++;
			bandera=1;	
		}
		else{
			cons=0;
		}
		if(password[i]>=65 and password[i]<=90){
				bandera=1;
				mayus2++;
			}
			if(password[i]>=97 and password[i]<=122){
					minus++;
					bandera=1;
				}
}
	for(j=0;j<cant;j++){
	if(password[j]>=48 and password[j]<=57){
	cons++;
	if(cons==4){
		numcons=1;
	}
	}
	else{
		cons=0;
	}
}
	for(i=0;i<cant;i++){
		if(password[i]>=65 and password[i]<=122){
	val1=password[i];
	val2=password[i+1];
	//cout<<"\nVal1="<<val1<<"\nVal2="<<val2;
	res=val1-val2;
	//cout<<"\nRes="<<res;
	if(res==-1 or res==31 or res==-33){
		resultado=1;	
	}
}
	//return resultado;
	//cout<<"\nresultado="<<resultado;
	if(resultado==1){
		band2=1;
	}
}
	
	
	
	if(cant>=6 and cant<=32){
	if (bandera==1){
		if(numeros>=1 and mayus>=1 and minus>=1){
			if(numcons!=1){
				if(band2!=1){
				contracorrecta=1;
		cout<<"\nLa contrasena es correcta\n\n";
	}
	}
	}
	}
}

if(contracorrecta!=1){
		cout<<"\nLa password no cumple con las condiciones requeridas. Elija otra\n\n";
		system("pause");
		system("cls");
}

}while(contracorrecta==0);

//Agregar nombre y apellido
system("pause");
system("cls");
cout<<"\n Cargar  los datos del profesional ";
cout<<"\nAgregar nombre y apellido\n";
_flushall();
gets(us[tam].Apynom);
//Agregar nombre de usuario y password al registro
strcpy(us[tam].usuario,nomus);
strcpy(us[tam].pass,password);
us[tam].id=tam+1;
cout<<"\n Ingrese el DNI del profesional ";
cin>>us[tam].dni;
cout<<"\n Ingrese el numero de celular ";
_flushall();
gets(us[tam].tel);
tam++;
ar=fopen("Profesionales.dat", "wb");
rewind(ar);
for(i=0;i<tam;i++){
fwrite(&us[i],sizeof(user),1,ar);
}
cout<<"\n";
fclose(ar);

system("pause");
system("cls");

}

	//creacion de usuario recepcionista
void creacionUsuarioRec( ){
	char nomus[100];
	int largo, i, comp, mayus=0,dig=0, conda=0,condb=0,condc=0,j, comparacionreg=0,bandera3=0, condD=0,bandera4=0;//variables de nombre de usuario
	int bandera,cant,numeros=0,mayus2=0,minus=0, cons=0,numcons=0, contracorrecta=0, letcons, band2=0, val2,val1,resultado=0,res;//variables de contrasena
	char password[100];
	//**************************************************************
	FILE *ar;
	int l=0;
	ar=fopen("Recepcionistas.dat", "a+b");
	int comprobacionusuario=0, tam=0;
	recep rec[100];
	rewind(ar);
	fread(&rec[tam],sizeof(recep),1,ar);
	
	while(!feof(ar)){
		tam++;
		fread(&rec[tam],sizeof(recep),1,ar);
	}
	cout<<"\ntam="<<tam;
	fclose(ar);
	//***********************************************
	
	
	cout<<"\nPrimero debe escoger un nombre de usuario";
	//CREACION NOMBRE DE USUARIO
	do{
		conda=0;
		condb=0;
		condc=0;
		condD=0;
		bandera3=0;
		bandera4=0;
	cout<<"\nIngrese el nombre de usuario deseado\nEl nombre de usuario debe:\na. Comenzar con una letra minuscula\nb. Tener al menos 2 letras mayusculas\nc. Tener como maximo 3 digitos\n ";
	_flushall();
	gets(nomus);
	largo=strlen(nomus);
	if (largo>=6 or largo <=10){
		condD=1;
}
	if(nomus[0]>=97 and nomus[0] <=122){
		conda=1;
	for(i=0;i<largo;i++){
		if(nomus[i]>=65 and nomus[i]<=90){
			mayus++;
		}
		if(nomus[i]>=42 and nomus[i]<=57){
			dig++;
		}
		if(nomus[i]==33 or nomus[i]==63 ){
			dig++;
		}
	}
}
if(mayus>=2){
	condb=1;
}
if(dig<=3){
	condc=1;
}
if(conda==1 and condb==1 and condc==1 and condD==1){
	for(i=0;i<tam;i++){
	comp=strcmp(rec[i].usuario, nomus);
	if(comp==0){
		bandera3=1;
	}	
	}
}
else{
	cout<<"\nEl nombre de usuario no cumple con las condiciones requeridas\n";
	system("pause");
system("cls");
	
}
	if(bandera3==1){
		cout<<"El nombre de usuario ya ha sido escogido. Elija otro\n";
		system("pause");
system("cls");
	}
if(conda==1 and condb==1 and condc==1 and condD==1 and bandera3!=1){
	cout<<"\nEl nombre de usuario\n ";
	puts(nomus);
	cout<<" ha sido elegido correctamente.";
	bandera4=1;

	}
}while(bandera4==0);
system("pause");
system("cls");

//CREACION DE CONTRASEÑA

do{
		numeros=0;
		mayus2=0;
		minus=0;
		cons=0;
		numcons=0;
		contracorrecta=0;
		band2=0;
		resultado=0;
	cout<<"\nIngrese una password valida\n  1. Deberá contener al menos una letra mayuscula, una letra minuscula y un numero.\n2. No podra contener ningun caracter de puntuacion, ni acentos, ni espacios. Solo caracteres alfanumericos.\n3. Debera tener entre 6 y 32 caracteres. \n4. No debe tener mas de 3 caracteres numericos consecutivos. 5. No debe tener 2 caracteres consecutivos que refieran a letras alfabeticamente consecutivas (ascendentemente). Este criterio es valido tanto para letras mayusculas, minusculas o combinacion de ambas. ";
	gets(password);
	cant=strlen(password);

		
		for(i=0;i<cant;i++){
			bandera=0;
		if(password[i]>=48 and password[i]<=57){
			numeros++;
			bandera=1;	
		}
		else{
			cons=0;
		}
		if(password[i]>=65 and password[i]<=90){
				bandera=1;
				mayus2++;
			}
			if(password[i]>=97 and password[i]<=122){
					minus++;
					bandera=1;
				}
}
	for(j=0;j<cant;j++){
	if(password[j]>=48 and password[j]<=57){
	cons++;
	if(cons==3){
		numcons=1;
	}
	}
	else{
		cons=0;
	}
}
	for(i=0;i<cant;i++){
		if(password[i]>=65 and password[i]<=122){
	val1=password[i];
	val2=password[i+1];
	//cout<<"\nVal1="<<val1<<"\nVal2="<<val2;
	res=val1-val2;
	//cout<<"\nRes="<<res;
	if(res==-1 or res==31 or res==-33){
		resultado=1;	
	}
}
	//return resultado;
	//cout<<"\nresultado="<<resultado;
	if(resultado==1){
		band2=1;
	}
}
	
	
	
	if(cant>=6 and cant<=32){
	if (bandera==1){
		if(numeros>=1 and mayus>=1 and minus>=1){
			if(numcons!=1){
				if(band2!=1){
				contracorrecta=1;
		cout<<"\nLa contrasena es correcta\n\n";
	}
	}
	}
	}
}

if(contracorrecta!=1){
		cout<<"\nLa password no cumple con las condiciones requeridas. Elija otra\n\n";
		system("pause");
		system("cls");
}

}while(contracorrecta==0);

//Agregar nombre y apellido
system("pause");
system("cls");
cout<<"\n Cargar  los datos del profesional ";
cout<<"\nAgregar nombre y apellido\n";
_flushall();
gets(rec[tam].Apynom);
//Agregar nombre de usuario y password al registro
strcpy(rec[tam].usuario,nomus);
strcpy(rec[tam].pass,password);
rec[tam].id=tam+1;
cout<<"\n Ingrese el DNI del profesional ";
cin>>rec[tam].dni;
cout<<"\n Ingrese el numero de celular ";
_flushall();
gets(rec[tam].tel);
tam++;
ar=fopen("Recepcionistas.dat", "wb");
rewind(ar);
for(i=0;i<tam;i++){
fwrite(&rec[i],sizeof(recep),1,ar);
}
cout<<"\n";
fclose(ar);

system("pause");
system("cls");


}

void atenxprof(){
 	FILE *ar;
 	int cont=0, pro,i,sum=0,mes;
 	ar=fopen("Turnos.dat","r+b");
 	turnos turn[100];
 	fread(&turn,sizeof(turnos),1,ar);
 	while(!feof(ar)){
 		cont++;
 		fread(&turn,sizeof(turnos),1,ar);
	 }
	 fclose(ar);
	 cout<<"\nIngrese el Mes actual ";
	 cin>>mes;
	cout<<"\nIngrese el id del profesional que desea saber cuantos turnos atendio ";
	cin>>pro;
	for(i=0;i<cont;i++){
		if(turn[i].idprof==pro){
			if(mes==turn[i].fech.mes){
			sum++;
		}
		}
	}
		if(sum>0){
			cout<<"\nLa cantidad de atenciones que tuvo el profesional ID: "<<pro<<" fue de "<<sum;
		}
		else{
			cout<<"\nEl profesional ingresado no tuvo atenciones";
		}
		
}


	//ranking de profecionales
void ranking(){
	FILE *ar;
	int vector [100];
 	int cont=0, pro,i,sum=0,mes,j=0, b=0, mayor=0,indi;
 
 	ar=fopen("Turnos.dat","a+b");
 	
 	turnos turn[100];
 	
 	fread(&turn,sizeof(turnos),1,ar);
 	
 	while(!feof(ar))
	 {
 		cont++;
 		fread(&turn,sizeof(turnos),1,ar);
	 }
	 fclose(ar);
	 cout<<"\nIngrese el Mes actual ";
	 cin>>mes;
	 for(i=0;i<cont;i++){
	 	if(turn[i].fech.mes){
	 		b=turn[i].idprof;
	 		for(j=1;j<100;j++){
	 			if(j==b){
	 				vector[j]++;
				 }
			 }
		 }
	 }
	 for(i=0;i<100;i++){
	 	if(vector[i]>mayor){
	 		mayor=vector[i];
	 		indi=i;
		 }
	}
	cout<<"\nEl profesional con mayores turnos atendidos fue el que tiene un id: "<<turn[indi].idprof<<" con: "<<mayor<<" atenciones";
}

