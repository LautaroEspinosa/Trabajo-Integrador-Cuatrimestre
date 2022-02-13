//Modulo Administracion
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<strings.h>


using namespace std;


//Estructura p/creacion de usuario recepcionista
struct recep{
	char usuario[11];
	char pass[33];
	char Apynom[61];
	int id;
	int dni;
	char tel[25];
};

//Estructura p/creacion de usuario pro
struct user{
	char usuario[11];
	char pass[33];
	char Apynom[61];
	int id;
	int dni;
	char tel[25];
};
void creacionUsuarioPro(); //Prototipo de funcion
void creacionUsuarioRec();


main(){
		creacionUsuarioPro();
		creacionUsuarioRec();
	

}




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


