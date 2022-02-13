//Modulo Administracion
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<strings.h>


using namespace std;


//Estructura p/registro de profesionales
struct Prof {
	char AyN[60];
	int id;
	int dni;
	char tel[25];
};
//Estructura p/creacion de usuario
struct user{
	char usuario[11];
	char pass[33];
	char Apynom[61];
};
void creacionUsuario(int &comprobacionusuario, int tam, user us[100]); //Prototipo de funcion
void pass1();//prototipo de funcion

main(){
	int comprobacionusuario=0,i, tam=5;// tam =5 por ahora
	user us [100];
	cout<<"\nIngrese usuarios ";
	for(i=0;i<5;i++){
		cout<<"\nIngrese nombre de usuario ";
		_flushall();
		gets(us[i].usuario);
	}
		creacionUsuario(comprobacionusuario, tam, us);
		system("cls");
		pass1();
}











void creacionUsuario(int &comprobacionusuario, int tam, user us[100]){
	cout<<"\nPrimero debe escoger un nombre de usuario";
	char nomus[100];
	int largo, i, comp, mayus=0,dig=0, conda=0,condb=0,condc=0,j, comparacionreg=0,bandera3=0, condD=0,bandera4=0;
	cout<<"\nPrimero debe escoger un nombre de usuario";
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
	cout<<"\nEl nombre de usuario no cumple con las condiciones requeridas";
}
	if(bandera3==1){
		cout<<"El nombre de usuario ya ha sido escogido. Elija otro";
	}
if(conda==1 and condb==1 and condc==1 and condD==1 and bandera3!=1){
	cout<<"\nEl nombre de usuario\n ";
	puts(nomus);
	cout<<" ha sido elegido correctamente.";
	bandera4=1;
	system("pause");
	}
}while(bandera4==0);
}

void pass1(){
int i,bandera,cant,numeros=0,mayus=0,minus=0, cons=0,numcons=0,j, contracorrecta=0, letcons, band2=0, val2,val1,resultado=0,res;
	char password[100];
	do{
		numeros=0;
		mayus=0;
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
				mayus++;
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
		system("pause");
	}
	}
	}
	}
}

if(contracorrecta!=1){
		cout<<"\nLa password no cumple con las condiciones requeridas. Elija otra";
}

}while(contracorrecta==0);
}


