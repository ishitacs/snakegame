 #include <iostream>
#include <conio.h>
using namespace std;
bool gameover;
const int width=20;
const int height=20;
int x,y,fruitX,fruitY,score;
int tailx[100],tailY[100];
int ntail;
enum edirection{stop=0, LEFT,RIGHT,TOP,DOWN};
edirection dir;
void setup()
{
    gameover=false;
    dir=stop;
    x=width/2;
    y=height/2;
    fruitX= rand()%width;
    fruitY= rand()%height;
    score=0;

}
void draw()
{
    system("cls");
    for(int i=0;i<width+2;i++)
    cout<<"#";
    cout<<endl;
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(j==0){cout<<"#";}

            if(i==y && j==x){cout<<"O";}
            else if(i==fruitY && j==fruitX){cout<<"$";}
            else{ bool print =false;
                    for(int k=0;k<ntail;k++)
                  {
                    if(tailx[k]==j && tailY[k]==i){cout<<"o"; print=true;}
                   }  if (!print)
                    cout<<" ";}
            if(j==width-1){cout<<"#";}
        }
        cout<<endl;
    }
    for(int i=0;i<width+2;i++)
    {cout<<"#";}
    cout<<endl;
cout<<"SCORE : "<< score<<endl;
}
void input()
{ if(_kbhit())
{switch(_getch())
{
    case 'a': dir=LEFT;
    break;
    case 'w': dir=TOP;
    break;
    case 'd':dir=RIGHT;
    break;
    case 's': dir=DOWN;
    break;
    case 'x': gameover=true;
    break;
}
}}
void logic()
{ int i;
int prevX=tailx[0];
int prevy=tailY[0];
int prevx2;
int prevy2;
tailx[0]=x;
tailY[0]=y;
for(i=1;i<ntail;i++)
{
    prevx2=tailx[i];
    prevy2=tailY[i];
    tailx[i]=prevX;
    tailY[i]=prevy;
}
    switch(dir)
{
    case LEFT: x--;
    break;
    case TOP: y--;
    break;
    case RIGHT: x++;
    break;
    case DOWN: y++;
    break;
    default:
    break;
    }
    if(x>width || x<0 || y>height || y<0)
    { gameover=true;}
if(x== fruitX && y==fruitY)
{ ntail++;
    score=score+10;
    fruitX= rand()%width;
    fruitY= rand()%height;

}
    }
int main()
{ setup();
    while(!gameover)
    {
        draw();
        input();
        logic();
    }

    return 0;
}
