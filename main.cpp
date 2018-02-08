#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h>       /* exp */
#include <windows.h>
#include "time.h"
#include<conio.h>
#include <iomanip>

using namespace std;

//VERSI 2
//int argc, char*argv[]

int main ()
{
    double hasil_awal=0, hasil_baru=0,hasil_terbaik=0,hasil_exp=0,hasil_rand_decimal,pra_exp, dE,pangkat,input_baru1=0,input_baru2=0,input1=0,input2=0, random_input_1=0,random_input_2=0;
    boolean status=true;
    double temp, temp_min=1, coolingrate=0.9, temp_baru;
    int i=1;

    cout<<"Masukkan temp: ";
    cin>>temp;

    srand (time(NULL));

    cout<<"----------------------iterasi awal-----------------------"<<endl;
    cout<<"Temp ke-0: "<<temp<<endl;

    input1 = ((double)rand()*(30-10) / (double)RAND_MAX-10);
    input2 = ((double)rand()*(30-10) / (double)RAND_MAX-10);

    cout<<"x1 ke-0: "<<input1<<endl;
    cout<<"x2 ke-0: "<<input2<<endl;

    hasil_awal=(4-2.1*(input1*input1)+((input1*input1*input1*input1)/3.0))*(input1*input1)+input1*input2+(-4+4*(input2*input2))*input2*input2;

    hasil_terbaik=hasil_awal;

    cout<<"hasil ke-0: "<<hasil_awal<<endl;
    cout<<"hasil terbaik ke-0: "<<hasil_terbaik<<endl;

    cout<<endl;

    while (temp > temp_min){

    cout<<"----------------------iterasi ke-"<<i<<"-----------------------"<<endl;
    cout<<"Temp ke-"<<i<<": "<<temp<<endl;

        //random_x = rand() % 100;
        /*input1 = rand() % 20 + (-10);
        input2 = rand() % 20 + (-10); */

        random_input_1 = ((double)rand()*(30-10) / (double)RAND_MAX-10);
        random_input_2 = ((double)rand()*(30-10) / (double)RAND_MAX-10);

        //input_baru1 = input1 + random_input_1;
        //input_baru2 = input2 + random_input_2;

        while ((input1 + random_input_1 > 10) || (input1 + random_input_1 < -10 )){
            random_input_1 = ((double)rand()*(30-10) / (double)RAND_MAX-10);
        }
        input1 = input1 + random_input_1;

        while ((input2 + random_input_2 > 10) || (input2 + random_input_2 < -10 )){
            random_input_2 = ((double)rand()*(30-10) / (double)RAND_MAX-10);
        }
        input2 = input2 + random_input_2;

        hasil_baru=(4-2.1*(input1*input1)+((input1*input1*input1*input1)/3.0))*(input1*input1)+input1*input2+(-4+4*(input2*input2))*input2*input2;

        cout<<"x1 ke-"<<i<<": "<<input1<<endl;
        cout<<"x2 ke-"<<i<<": "<<input2<<endl;
        cout<<"hasil ke-"<<i<<": "<<hasil_baru<<endl;

        if(hasil_baru<hasil_terbaik){
            hasil_terbaik=hasil_baru;
        cout<<"hasil terbaik ke-"<<i<<": "<<hasil_terbaik<<endl;
        cout<<endl;

        }else{
            dE=((hasil_terbaik)-(hasil_baru));
            pangkat=(dE/temp);
            hasil_exp=exp(pangkat);
            //hasil_exp=exp(((hasil_baru)-(hasil_terbaik))/T);
            //pra_exp=(((hasil_baru)-(hasil_terbaik))/T);
            //cout<<"hasil baru - hasil terbaik di bagi T: "<<pra_exp<<endl;
            hasil_rand_decimal=(double)rand() / (double)RAND_MAX ;
            /*if((pra_exp <= -13) || (pra_exp >= 27) ){
                hasil_exp=0;
                cout<<"ERORRRRRRRR!!!!!!!!!!";
            }else{
                hasil_exp=exp(((hasil_baru)-(hasil_terbaik))/T);
            }*/
            cout<<"hasil exp ke-"<<i<<": "<<hasil_exp<<endl;
            cout<<"hasil random desimal ke-"<<i<<": "<<hasil_rand_decimal<<endl;

            if(hasil_exp > hasil_rand_decimal){
                hasil_terbaik=hasil_baru;
            }
        cout<<"hasil terbaik ke-"<<i<<": "<<hasil_terbaik<<endl;
        cout<<endl;
        }

        temp=temp*coolingrate;
        i++;
    }

    cout<<"hasil terbaik FINAL: "<<hasil_terbaik<<endl;
    /*
    if(status == false){
        cout<<"inputan x diluar scope";
    }else{
        cout<<"inputan x aman";
    } */
  return 0;

}
