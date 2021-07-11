#include<iostream>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstddef>
#include<cstddef>

using namespace std;

class Puzzle
{
    public://تابع پازل با یک رایه و مشخصکردن هزینه و وال
        int state[9];
        int cost;
        Puzzle * parent;
        Puzzle();
        int actions();
int find_ziro() //محل قرار گیری صفر
{
    for (int i=0;i<9;i++)
        if(state[i]==0)
           {
             return i;
           }
return 1;
}
};
Puzzle::Puzzle()//مقدار دهی اولیه
{
    for(int i=0; i<9; ++i)
    {
        state[i] = -1;
    }

    cost = 0;

    parent = NULL;
}

int Puzzle::actions()// عمل بر اساس محل قرار گیری بلنک یا صفر
{
    //اعمال و حرکت های مورد نیاز برای حل مسلهپازل 8 تایی
			//	{ UP, LEFT, DOWN, RIGHT }
    int ziro_pos = find_ziro();

    switch(ziro_pos)
    {
        case 0:
             return 1;
        case 1:
             return 2;
        case 2:
             return 3;
        case 3:
             return 4;
        case 4:
             return 5;
        case 5:
             return 6;
        case 6:
             return 7;
        case 7:
             return 8;
        case 8:
             return 9;
    }

}
//-----------------------------------------------


bool goalTest(Puzzle * enode)//تابع هدف و بررسی برابری استیت مورد بررسی با هدف
{
    int goal_state[9] = {0,1,2,3,4,5,6,7,8};
    for(int i=0; i<9; ++i)
    {
        if(enode->state[i] != goal_state[i])
            return false;
    }
    return true;
}

int heuristic(Puzzle * node)//تعداد خانه های اشتباه نود مورد بررسی را بر میگرداند
{
    int goal_state[9] = {0,1,2,3,4,5,6,7,8};
    int heuristic = 0;
    for(int i=0; i<9; ++i)
    {
        if(node->state[i] != goal_state[i])
        {
            heuristic++;
        }
    }
    return heuristic;
}

Puzzle* movenode(Puzzle *node, int action)//برای حرکت دادن یا جابه جا کردن خانه ها براساس اکشن انتخابی
{
    Puzzle *next_node = new Puzzle;

    int blank_pos = node->state[0];
    int tile;

    if(action==1)//حرکت به بالا
    {
        tile = blank_pos - 3;
        for(int i=1;i<9;++i)
        {
            if(node->state[i]==tile)

            {
                next_node->state[0] = tile;
                next_node->state[i] = blank_pos;
            }
            else
            {
                next_node->state[i] = node->state[i];

            }
        }

    }

  if(action==2)//حرکت به چپ
    {
        tile = blank_pos-1;

        for(int i=0;i<9;++i)
        {
            if(node->state[i]==blank_pos-1)

            {
                next_node->state[0] = tile;
                next_node->state[i] = blank_pos;
            }
            else
            {
                next_node->state[i] = node->state[i];
            }
        }

    }

  if(action==3)//حرکت به پایین
    {
        tile = blank_pos+3;

        for(int i=0;i<9;++i)
        {
            if(node->state[i]==blank_pos+3)

            {
                next_node->state[0] = tile;
                next_node->state[i] = blank_pos;
            }
            else
            {
                next_node->state[i] = node->state[i];
            }
        }

    }

   if(action==4)//حرکت به راست
    {
        tile = blank_pos+1;

        for(int i=0;i<9;++i)
        {
            if(node->state[i]==blank_pos+1)

            {
                next_node->state[0] = tile;
                next_node->state[i] = blank_pos;
            }
            else
            {
                next_node->state[i] = node->state[i];
            }
        }

    }

    next_node->parent = node;
    next_node->cost = node->cost + 1;

    return next_node;
}
//------------------------------------------------





Puzzle * frontier = new Puzzle[1000000];//نود های رو به رویا اماده جستو جو بعدی
/*if(!frontier)
{
       cout <<"allocation failure \n ";
       system("pause");
       exit(1);
   }*/

long int top = -1;

int explored[1000000][9];//جستو جو ها
long int top_exp = -1;

void insertFrontier(Puzzle *a_node) // بررسیهزینه ها و اضافه کردن به لیست
{

    if(top==-1)
    {
        frontier[0] = *a_node;
    }
    else
    {
        long int i=0,j=0;

        while(i<=top && frontier[i].cost + heuristic(&frontier[i]) <= a_node->cost + heuristic(a_node))
            i++;
        for(j=top;j>=i; --j)
            frontier[j+1] = frontier[j];
        frontier[i] = *a_node;
    }
    top++;
}

Puzzle * popFrontier()// حذف کردن نود بررسی شده از لیست موارد رو به رو
{
    Puzzle * popped = new Puzzle;
    if(top==-1)
        return NULL;
    else
    {
        for(int i=0; i<9; ++i)
            popped->state[i] = frontier[0].state[i];
        popped->parent = frontier[0].parent;
        popped->cost = frontier[0].cost;
        for(long int i=0; i<top; ++i)
            frontier[i] = frontier[i+1];
        top--;
        return popped;
    }
}

void insertExplored(int * state)// اضافه کردن به لیست جستو جو شده
{
    top_exp++;
    for(int i=0; i<9; ++i)
        explored[top_exp][i] = state[i];
}

int isExplored(int * state)//بررسی تناسب جستئ جو شده
{
    int counter = 0;
    for(long int i=0; i<=top_exp; ++i)
    {
        counter = 0;
        for(int j=0; j<9; ++j)
        {
            if(explored[i][j] == state[j])
            {
                counter++;
            }
        }
        if(counter==9)
            return 1;
    }
    return 0;
}

void astar(Puzzle fnode)//تابع اصلی برای جستو جو
{

    Puzzle * first1 = new Puzzle;
    first1 = &fnode;

    Puzzle * temp, * gen_node;
    int actions;
    int possible_actions[4];//حداکثر حرکات ممکن

    insertFrontier(first1);//بررسی خانه های اشتباه

    while(1)
    {
        if(top==-1)//هدف یافت نشد یا خطا
        {
            cout<<"not found! any thing ?? <fild>"<<endl;
            system("pause");
            return;
        }
        temp = popFrontier();
        insertExplored(temp->state);
        if(goalTest(temp))//هدف یاف شد
        {
            int counter ;//tcost ;
            cout<<"\n====================================="<<"\n\t Necessary moves :\n";;
            while(temp)
            {
                for(int i=0; i<9; ++i)
                    cout<<temp->state[i]<<" ";
                cout<<endl;
                temp = temp->parent;
              //  tcost += temp->cost;
                counter ++;
            }
            cout<<"\n \t Number moves And Depth:"<<--counter<<endl;
         //   cout<<"\n \t cost:"<<tcost<<endl;
            return;
        }

        actions = temp->actions();
        switch(actions)//بررسی بهترین حال حرکت
        {
            case 9:
                possible_actions[0]=1;
                possible_actions[1]=1;
                possible_actions[2]=0;
                possible_actions[3]=0;
                break;
            case 7:
                possible_actions[0]=1;
                possible_actions[3]=1;
                possible_actions[2]=0;
                possible_actions[1]=0;
                break;
            case 3:
                possible_actions[1]=1;
                possible_actions[2]=1;
                possible_actions[0]=0;
                possible_actions[3]=0;
                break;
            case 1:
                possible_actions[2]=1;
                possible_actions[3]=1;
                possible_actions[1]=0;
                possible_actions[0]=0;
                break;
            case 6:
                possible_actions[0]=1;
                possible_actions[1]=1;
                possible_actions[2]=0;
                possible_actions[3]=0;
                break;
            case 8:
                possible_actions[0]=1;
                possible_actions[1]=1;
                possible_actions[3]=1;
                possible_actions[2]=0;
                break;
            case 4:
                possible_actions[0]=1;
                possible_actions[3]=1;
                possible_actions[2]=1;
                possible_actions[1]=0;
                break;
            case 2:
                possible_actions[3]=1;
                possible_actions[1]=1;
                possible_actions[2]=1;
                possible_actions[0]=0;
                break;
            case 5:
                possible_actions[0]=1;
                possible_actions[1]=1;
                possible_actions[2]=1;
                possible_actions[3]=1;
                break;
        }

        for(int i=0; i<4; ++i)
        {
            if(possible_actions[i]==1)
            {
                gen_node = movenode(temp,حخنتتتتت);
                if(isExplored(gen_node->state) == 0)
                    insertFrontier(gen_node);
            }
        }

    }

}

//---------------------------------------------------------

int main()
{
    Puzzle first;
    int p,k=1;




    for(int i=0; i<9; ++i) //دریافت ورودی
    {
        cout<<"Enter number ! "<<k<<" :";
        cin>>p;
        first.state[i] = p;
        k++;
    }

    astar(first);
    return 0;
}
