
#include<iostream>
#include<iomanip>
#include<cmath>
#define N 3

using namespace std;

int main()
{
	float Matrix[N][N+1],x[N];
	// Matris = Art�r�lm�� Matris [N]
	float temp,s;
	//d�ng�ler i�in de�i�kenler
	int i,j,k;

	//Matrix'in de�erlerini taray�n.
	cout<<"Denklem Sayisi = "<<N<<endl;
	cout<<fixed;

	for(i=0; i<N; i++)
	{
		cout<<i+1<<" Denklem Katsayilari: \n ";
		for(j=0; j<N+1; j++)
		cin>>Matrix[i][j];
	}
	
	 //Yukar�daki matrisi �st ��gen Matrix yapma
	for(j=0; j<N-1; j++)
	{
		for(i=j+1; i<N; i++)
		{
			temp=Matrix[i][j]/Matrix[j][j];

			for(k=0; k<N+1; k++)
				Matrix[i][k]-=Matrix[j][k]*temp;
		}
	}	
	
		//�st ��gen matrisi yazd�r
	cout<<"\n ---------------------------------\n";
	cout<<"\n Ust Ucgen Matris  \n"  ;
	for(i=0; i<N; i++)
	{
		for(j=0; j<N+1; j++)
		cout<<setw(8)<<setprecision(4)<<Matrix[i][j];
		cout<<endl;
	}
	
	//x,y,z de�erlerini bulun
	cout<<"\n ---------------------------------\n";

	for(i=N-1; i>=0; i--)
	{
		s=0;
		for(j=i+1; j<N; j++)
		s += Matrix[i][j]*x[j];
		x[i]=(Matrix[i][N]-s)/Matrix[i][i];
	}

	//x,y,z de�erlerini yazd�r
	cout<<"Sistem Cozumu \n";
	for(i=0; i<N; i++)
	 cout<<"x["<<setw(3)<<i+1<<"]="<<setw(7)<<setprecision(4)<<x[i]<<endl;

return 0;

}
