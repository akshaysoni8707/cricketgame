#include <stdio.h>
#include <stdlib.h>
int checkinput(char* team[],int* ball,int *wicket,int* run,int* over,int* target,int* choice,int* bcount)
{
    if(*ball==6)
    {
        ++*over;
        *ball=0;
    }
    switch(*choice)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        *run=*run+*choice;
        ++*ball;
        ++*bcount;
        break;
    case 7:
    case 8:
        ++*run;
        break;
    case 9:
        *wicket +=1;
        ++*ball;
        ++*bcount;
        break;
        return 0;
    }
}
void display(char team[],int* ball,int *wicket,int* run,int* over,int* target,int *bcount)
{
    printf("\n%s",team);
    int rem =*target +1 - *run;
    int ballc,overc;
    float rr,req=((float)rem*6)/(30-*bcount);
    if(*bcount==0)
    {
        rr=0;
    }
    else if(*bcount>0)
    {
        rr=(*run / (float)*bcount)*6;
    }
    if(*ball<6)
    {
        ballc=*ball;
        overc=*over;
    }
    if(*ball==6)
    {
        ballc=0;
        overc=*over+1;
    }
    printf("\n%d/%d   |over %d.%d |target %d\t\t\tcurrent run rate %.2f\trequired run rate %.2f",*run,*wicket,overc,ballc,rem,rr,req);
}
main()
{
    char x;
    do
    {
        int end=0;
        char team[10];
        int run=0,ball=0,target=40,wicket=0,over=0,choice=0,win=0,bcount=0;
        printf("\n\t\t\t\t\tCRICKET  ");
        printf("\n\n\nenter name of your team  :");
        fflush(stdin);
        scanf("%s",&team);
        printf("\nyour target is %d\nto enter a no or wide ball press 7/8\nto enter fall of a wicket press 9\nto enter runs press 0-6\n",target+1);
        display(team,&ball,&wicket,&run,&over,&target,&bcount);
        do
        {

            int overd,balld;
            if(ball==6)
            {
                balld=1;
            }
            if(ball<5)
            {
                balld=ball+1;
                overd=over;
            }
            if(ball==5)
            {
                balld=0;
                overd=over+1;
            }
            printf("\n\nenter what happend on %d.%d ball",overd,balld);
            //display(&team,&ball,&wicket,&run,&over,&target);
            scanf("%d",&choice);

            checkinput(&team,&ball,&wicket,&run,&over,&target,&choice,&bcount);
            display(&team,&ball,&wicket,&run,&over,&target,&bcount);

            if((over==4)&&(run==target)&&(wicket<=3) &&(ball==6))
            {
                printf("\n\nthe game is draw");
                end=1;
                break;
            }
            if((over==4)&&(run<target)&&(wicket<=3)&& (ball==6))
            {
                printf("\n\nthe overs are completed you lost by %d runs",target-run);
                end=1;
                break;
            }
            if((run<target) && (wicket==3))
            {
                printf("\n\nyou are all out you lost by %d runs",target-run);
                end=1;
                break;
            }
            if((run>target) && (wicket<3)&& (over<=4) && (ball<=6))
            {
                printf("\n\nyou won by %d wickets",3-wicket);
                end=1;
                break;
            }
        }
        while(end==0);
        printf("\n\nwant to play again type y or Y");
        fflush(stdin);
        scanf("%c",&x);
    }
    while(x=='y'||x=='Y');
    return 0;
}
