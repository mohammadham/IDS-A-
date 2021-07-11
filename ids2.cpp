#include <iostream>
#include <algorithm>

using namespace std;
int goal[9]={0,1,2,3,4,5,6,7,8}; //goal

void swapt(int x[],int y,int z)     //جابه جایی
{
    int temp=x[y];
    x[y]=x[z];
    x[z]=temp;
}

void copy_arr(int x[],int y[]) //کپی کردن دو ارایه
{
    for(int i=0;i<9;i++)
        y[i]=x[i];
}

bool chek_goal(int x[]) //بررسی رسیدن به هدف
{
    for(int i=0;i<9;i++)
        if (goal[i]!=x[i])
            return false;

        return true;
}

int find_ziro(int x[]) //محل قرار گیری صفر
{
    for (int i=0;i<9;i++)
        if(x[i]==0)
           {
             i++;
             return i;
           }
return 1;
}
void print(int x[]) //چاپ ارایه
{
    for (int i=0 ;i<9;i++)
        cout<<x[i];
}
bool dfs(int x[],int n)// تابع جستو جوی اول عمق
{
    bool re=false;
 int ziro =find_ziro(x);
 int temp_array[9];

 //chek goal
 if (chek_goal(x)==true)
 {
     print(x);
    return true;
 }
        n--;
        if(n<=0)
            return false;

 // محل قرار گیری خانه صفر
 switch(ziro)
 {
 case 1:


        copy_arr(x,temp_array);
        copy_arr(x,temp_array);//copy kardan az aval ta akhar x be aval right
            swapt(temp_array,0,1);
        re=dfs(temp_array,n);
        if(re==true){
        print(x);
        cout<<endl;
        return true;
        }
        copy_arr(x,temp_array);//copy kardan az aval ta akhar x be aval down
        swapt(temp_array,0,3);
        re=dfs(temp_array,n);
        if(re==true){
        print(x);
        cout<<endl;
        return true;
        }

        return false;
 case 7:


        copy_arr(x,temp_array);//copy kardan az aval ta akhar x be aval right
            swapt(temp_array,6,7);
        re=dfs(temp_array,n);
        if(re==true){
        print(x);
        cout<<endl;
        return true;
        }
        copy_arr(x,temp_array);//copy kardan az aval ta akhar x be aval up
        swapt(temp_array,6,3);
        re=dfs(temp_array,n);
        if(re==true){
        print(x);
        cout<<endl;
        return true;
        }

        return false;
 case 3:


       copy_arr(x,temp_array);//copy kardan az aval ta akhar x be aval left
            swapt(temp_array,2,1);
        re=dfs(temp_array,n);
        if(re==true){
        print(x);
        cout<<endl;
        return true;
        }
        copy_arr(x,temp_array);//copy kardan az aval ta akhar x be aval down
        swapt(temp_array,2,5);
        re=dfs(temp_array,n);
        if(re==true){
        print(x);
        cout<<endl;
        return true;
        }

        return false;
 case 9:


      copy_arr(x,temp_array);//copy kardan az aval ta akhar x be aval left
           swapt(temp_array,8,7);
        re=dfs(temp_array,n);
        if(re==true){
        print(x);
        cout<<endl;
        return true;
        }
       copy_arr(x,temp_array);//copy kardan az aval ta akhar x be aval up
       swapt(temp_array,8,5);
        re=dfs(temp_array,n);
        if(re==true){
        print(x);
        cout<<endl;
        return true;
        }

        return false;
 case 2:



        copy_arr(x,temp_array);//copy kardan az aval ta akhar x be aval left
            swapt(temp_array,1,0);
        re=dfs(temp_array,n);
        if(re==true){
        print(x);
        cout<<endl;
        return true;
        }
        copy_arr(x,temp_array);//copy kardan az aval ta akhar x be aval down
        swapt(temp_array,1,4);
        re=dfs(temp_array,n);
        if(re==true){
        print(x);
        cout<<endl;
        return true;
        }
        copy_arr(x,temp_array);//copy kardan az aval ta akhar x be aval right
        swapt(temp_array,1,2);
        re=dfs(temp_array,n);
        if(re==true){
        print(x);
        cout<<endl;
        return true;
        }

        return false;
  case 8:



       copy_arr(x,temp_array);//copy kardan az aval ta akhar x be aval left
            swapt(temp_array,7,6);
        re=dfs(temp_array,n);
        if(re==true){
        print(x);
        cout<<endl;
        return true;
        }
        copy_arr(x,temp_array);//copy kardan az aval ta akhar x be aval up
        swapt(temp_array,7,4);
        re=dfs(temp_array,n);
        if(re==true){
        print(x);
        cout<<endl;
        return true;
        }
        copy_arr(x,temp_array);//copy kardan az aval ta akhar x be aval right
        swapt(temp_array,7,8);
        re=dfs(temp_array,n);
        if(re==true){
        print(x);
        cout<<endl;
        return true;
        }

        return false;

  case 4:



       copy_arr(x,temp_array);//copy kardan az aval ta akhar x be aval up
            swapt(temp_array,3,0);
        re=dfs(temp_array,n);
        if(re==true){
        print(x);
        cout<<endl;
        return true;
        }
       copy_arr(x,temp_array);//copy kardan az aval ta akhar x be aval down
        swapt(temp_array,3,6);
        re=dfs(temp_array,n);
        if(re==true){
        print(x);
        cout<<endl;
        return true;
        }
        copy_arr(x,temp_array);//copy kardan az aval ta akhar x be aval right
        swapt(temp_array,3,4);
        re=dfs(temp_array,n);
        if(re==true){
        print(x);
        cout<<endl;
        return true;
        }

        return false;

  case 6:

        copy_arr(x,temp_array);//copy kardan az aval ta akhar x be aval left
        swapt(temp_array,5,4);
        re=dfs(temp_array,n);
        if(re==true){
        print(x);
        cout<<endl;
        return true;
        }
        copy_arr(x,temp_array);//copy kardan az aval ta akhar x be aval up
            swapt(temp_array,5,2);
        re=dfs(temp_array,n);
        if(re==true){
        print(x);
        cout<<endl;
        return true;
        }
        copy_arr(x,temp_array);//copy kardan az aval ta akhar x be aval down
       swapt(temp_array,5,8);
        re=dfs(temp_array,n);
        if(re==true){
        print(x);
        cout<<endl;
        return true;
        }


        return false;
   case 5:

        copy_arr(x,temp_array);//copy kardan az aval ta akhar x be aval left
        swapt(temp_array,4,3);
        re=dfs(temp_array,n);
        if(re==true){
        print(x);
        cout<<endl;
        return true;
        }

        copy_arr(x,temp_array);//copy kardan az aval ta akhar x be aval up
swapt(temp_array,4,1);
        re=dfs(temp_array,n);
        if(re==true){
        print(x);
        cout<<endl;
        return true;
        }
        copy_arr(x,temp_array);//copy kardan az aval ta akhar x be aval down
       swapt(temp_array,4,7);
        re=dfs(temp_array,n);
        if(re==true){
        print(x);
        cout<<endl;
        return true;
        }

        copy_arr(x,temp_array);//copy kardan az aval ta akhar x be aval right
        swapt(temp_array,4,5);
        re=dfs(temp_array,n);
        if(re==true){
        print(x);
        cout<<endl;
        return true;
        }

        return false;



 }
return false;
}


int main()
{
    int x[9],n=0;
    for (int i=0;i<9;i++)
    {
        cout << "enter number "<<i+1<<":" ;
        cin>>x[i];
    }
    while(1){
    if(dfs(x,n)==true)
        {cout<<"\ndepth : "<<n+1<<endl;
           // print(x);
            break;
        }
        n++;
    }
    cout << "\n END" << endl;
    return 0;
}
