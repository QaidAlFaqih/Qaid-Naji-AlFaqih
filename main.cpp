#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
using namespace std;

struct products{

int PNo;
string PName;
float pprice;
float pQty;

void Cteat_Product(){
    cout <<"enter product number : "<<endl;
    cin >>PNo;
    cout <<"enter product name :"<<endl;
    cin >>PName;
     cout <<"enter product price :"<<endl;
     cin>>pprice;
      cout <<"enter product quantity :"<<endl;
      cin >>pQty;

}
void Show_Info(){

 cout <<"product name is :"<<PNo<<endl;
  cout <<" product mane is :"<<PName<<endl;
   cout <<" product price is :"<<pprice<<endl;
    cout <<"enter product quantity :"<<pQty<<endl;

}
int Pnum(){return PNo ;}
string Pname(){return PName ;}
float Pprice (){return pprice ;}


};

products pro ;
fstream fp;

void Write_Product(){

 fp.open("shop.txt",ios::out|ios::app);
 Pro.Creat_Product();
 fp.write((char*)&pro.sizeof(Products));
 fp.close();
 cout <<"\n\n the product created ";
 getch();
 }

 void Display_Products()
 {
     cout <<"all the product information :\n \n ";
     fp.open("shop.txt",ios::in);
     while(fp.read((char*)&pro,sizeof (Products)))
     {
         pro.Show_Info();
         cout <<"\n\n==========================\n ";
         getch();
     }
     fp.close();
     getch();
 }
 void Search_Products(int num)
 {
     int flag =0;
     fp.open("shop.txt",ios.in);
     while (fp.read((char*)&pro,sizeof(Products)))  {

        if (pro.Pnum()==num ){
            pro.Show_Info();
            flag=1;
        }
     }
     fp.close();
        if (flag ==0){
            cout <<"product not stored "<<endl;
            getch();
        }
 }

 void Delete_Product(){

 int num;
 cout <<"\n please enter the product you want to delete :";
 cin >>num;
 fp.open("shop.txt",ios::in|ios::out);
 fstream fp2;
 fp2.open("Replace.txt",ios::out);
 fp.seekg(0,ios::beg);
 while(fp.read((char*)&pro,sizeof(Products)))
 {
     if (pro.Pnum()!=num)
        {
    fp2.write((char*)&pro,sizeof(Products));
     }
 }
 fp2.close();
 fp.close();
 remove ("shop.txt");
 cout <<"\n\n the products deleted ";
 getch();

 }

int main()
{
    char ch;
    do
    {
        cout <<"\n \nmain menu";
        cout <<"\n\n \t1.create products ";
        cout <<"\n\n\t2.display all product";
        cout <<"\n\n\t3.search";
        cout <<"\n\n\t.4Delete Product";
        cout <<"\n\n\t.5View product menu ";
        cout <<"\n\n\t6.Exit";
        cout <<"\n\n\t.Please enter your choice (1-6)";
        ch=getch();
        switch(ch){
        case '1':Write_Product();
        break;
        case '2':
            Display_Products();
            break;
        case '3':
        int Num ;
        cout <<"enter the num to search :\t";
        cin >>Num;Search_Products(Num);
        break;
        case '4'Delete_Product();
        break;
        case '5':
            exit(0);
        default :
            cout <<"error";
            exit(0);
    }

    }while(ch!=5)

    return 0;
}
