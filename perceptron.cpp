#include<iostream>
#include<cstdlib>
#include<fstream>
#include<conio.h>
#include<math.h>
#include<windows.h>
using namespace std;
int main()
{
	float x[3],w[3],w1[3],direction[3],y,y1,sigmoid,error,derror,r;
	int actual,n,n1,i[5];
	n1=0;
	n=1;//generation=1
	r=0.8;//learning_rate
	//initialize w(n)
	w[0]=0.3;
	w[1]=0.6;
	w[2]=0.2;
	cout<<"n1"<<"="<<"(1~200)"<<endl;
	cin>>n1;
	DWORD start_time=GetTickCount();//計時開始
	float **data=NULL;//pointer initialization
	data=new float*[n1];
	for(int i=0;i<=n1-1;i++)
	{
		data[i]=new float[4];
	}
	ifstream infile;//定義讀取檔案流，相對於程式來說是in
	infile.open("perceptron.txt");//開啟檔案
	for(int row=0;row<=n1-1;row++)
	{
		for(int col=0;col<=3;col++)
		{
			infile>>data[row][col];//讀取一個值（空格、製表符、換行隔開）就寫入到矩陣中，行列不斷迴圈進行
		}
		//n1=n1+1;
	}
	infile.close();//讀取完成之後關閉檔案
	for(n=1;n<=n1;n++)
	{
		cout<<"generation="<<n<<endl;
		//forward propagation
		//input layer
		cout<<"width="<<endl<<"length="<<endl<<"bias="<<endl;
		for(i[0]=0;i[0]<=2;i[0]++)//y=sum(xi1wi1)
		{
			x[i[0]]=data[n-1][i[0]];
			cout<<x[i[0]]<<endl;
		}
		y=0;
		for(i[1]=0;i[1]<=2;i[1]++)//輸出w(n)
		{
			cout<<"weight"<<"["<<i[1]<<"]"<<"="<<w[i[1]]<<endl;
			y=y+x[i[1]]*w[i[1]];
		}
		cout<<"y="<<y<<endl;
		//hidden layer
		sigmoid=1/(1+exp(-y));
		cout<<"sigmoid(y)="<<sigmoid<<endl;//prediction
		if(sigmoid>0.5)
		{
			cout<<"預測:藍色花"<<endl;
		}
		else
		{
			cout<<"預測:紅色花"<<endl;
		}
		//output layer
		cout<<"actual="<<endl<<"1=藍色花"<<endl<<"0=紅色花"<<endl;
		cout<<data[n-1][3]<<endl;
		error=(sigmoid-data[n-1][3])*(sigmoid-data[n-1][3]);
		cout<<"error="<<error<<endl;
		//back propagation
		//output layer
		derror=2*(sigmoid-data[n-1][3]);
		cout<<"derror="<<derror<<endl;
		//hidden layer
		y1=sigmoid*(1-sigmoid);//y1=dy
		cout<<"y1=sigmoid(y)*(1-sigmoid(y))="<<y1<<endl;
		//input layer
		for(i[2]=0;i[2]<=2;i[2]++)
		{
			direction[i[2]]=derror*y1*x[i[2]];
			cout<<"direction"<<"["<<i[2]<<"]"<<"="<<direction[i[2]]<<endl;
		}
		for(i[3]=0;i[3]<=2;i[3]++)
		{
			w1[i[3]]=w[i[3]]-r*direction[i[3]];//w(n+1)=w(n)-learning_rate*direction
			cout<<"w1"<<"["<<i[3]<<"]"<<"="<<w1[i[3]]<<endl;
		}
		for(i[4]=0;i[4]<=2;i[4]++)
		{
			w[i[4]]=w1[i[4]];
		}
		cout<<endl;
	}
	DWORD end_time=GetTickCount();//計時結束
	cout<<"執行時間="<<(end_time-start_time)<<"ms"<<endl;
	system("pause");
	return 0;
}

//galaxy890624 
