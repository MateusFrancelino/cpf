#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
using namespace std;
string limpador(string cpf ){
    string limpa;
for(int t=0; t<cpf.size();t++){
     if(t==3||t==7||t==11){
     }
     else{
        limpa+=cpf[t];
     }
}
return limpa;
}

int* trocador (string cpf)
{
    long long int numeros;
    static int narray[11];
    istringstream iss (cpf);
    iss>>numeros;
    for (int t=cpf.size()-1;t>=0;t--){
    narray[t]= numeros%10;
    numeros=numeros/10;
    }

    return narray;
}


 bool validacao (int cpf[11]){
int somador1=0,somador2=0;
bool vali;
 for (int t=10,n=0;t>=2;n++,t--){
    somador1+=cpf[n]*t;
 }
 somador1=somador1%11;
 if (somador1<=2){
    somador1=0;
 }
 else{
    somador1=11-somador1;
 }
 cout<<somador1<<endl;
 for (int t=11,n=0;t>=2;n++,t--){
    somador2+=cpf[n]*t;
 }
 somador2=somador2%11;
 if (somador2<=2){
    somador2=0;
 }
 else{
    somador2=11-somador2;
 }

cout<<somador2<<endl;

if(cpf[9]==somador1&&cpf[10]==somador2){
    vali=true;
}
else{
    vali=false;
}



}




int main()
{
    bool valido;
    string cpf;
    cout<<"digite seu cpf";
    cin>>cpf;
    if (cpf.size()<11||cpf.size()>14){
        cout<<"Digite um cpf valido"<<endl;
        main();
    }
    else{
    if(cpf.size()==14){
    cpf=limpador(cpf);
   }
   int* cpfnumeros= trocador(cpf);
       for(int t=0;t<=10;t++){
        cout<<"teste"<<t<<"n: "<<cpfnumeros[t]<<endl;
     }
     if(cpfnumeros[10]==cpfnumeros[9]==cpfnumeros[8]==cpfnumeros[7]==cpfnumeros[6]==cpfnumeros[5]==cpfnumeros[4]==cpfnumeros[3]==cpfnumeros[2]==cpfnumeros[1]==cpfnumeros[0]){
        valido=false;
     }
     else{

   valido = validacao(cpfnumeros);
     }
   if(valido==true){
    cout<<"sim"<<endl;
    main();
   }
   else if(valido==false){
    cout<<"não"<<endl;
    main();
   }
    return 0;
    }
}
