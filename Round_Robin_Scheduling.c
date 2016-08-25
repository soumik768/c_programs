// this function is to demonstrate Round Robin Scheduling Algo in c 

#include<stdio.h> 
static int n;
int i,j,quantum_time=0;
float a_tat=0,a_wt=0;
int queue[100000];
int time=0,front=0,rear=0,q_count=0,m=0,s=0;

typedef struct Queue
{
    int at,st,ct,tat,wt;
    char process_name[20];
    float ntat;
}Q;

Q g;

// this function is push the element to the next
void push(int q)
{
    queue[rear++]=q;
    m++;
}
// this function is to pop out the elements
int pop()
{
    s++;
    int x;
    x=queue[front++];

    return x;
}

// this function is to check 
void check(Q a[])
{
    while(a[j].at<=time&&j<n)
    {
        q_count++;	
        push(j++);
    }
}

// this function is to dysplay the contents
void display(Q a[])
{

    printf("n=%d	\n",n);

    for(i=0;i<n;i++)
    {
        a[i].tat=a[i].ct-a[i].at;
        a[i].wt=a[i].tat-a[i].st;
    }

    printf("process_name\tarival_time\tservice_time\twt\t\n");
    for(i=0;i<n;i++)
    {
        printf("%s\t\t%d\t\t%d\t\t%d\n",a[i].process_name,a[i].at,a[i].st,a[i].wt);
    }

}




// this function is to find the which process is next
void find(Q a[])
{


    int tmp_st[n], selected_process=0,count=0,p_process;
    j=0;
    int blash;
    printf("enter the time quantum\n");
    scanf("%d",&blash);
    for(i=0;i<n;i++)
    {
        tmp_st[i]=a[i].st;
    }


    time=a[0].at;


    q_count=1;
    push(j++);
    while(time<=quantum_time)
    {
        if(selected_process==1||q_count!=0)
        {
            if(selected_process==0&&count==0)
            {

                p_process=pop();

                
                count=0;
                selected_process=1;

            }
            tmp_st[p_process]--;

            if(tmp_st[p_process]==0)
            {
                time++;
                count=0;
                a[p_process].ct=time;
                selected_process=0;
                q_count--;
                check(a);
                continue;
            }
            count++;
            
            if(count==blash)
            {
                count=0;
                time++;
                check(a);
                push(p_process);
                selected_process=0;
            }
            else
            {
                time++;
                check(a);
            }
        }
        else
        {
            time++;
            check(a);
        }


    }
    display(a);
}




int main()
{
    printf("enter the no of process\n");
    scanf("%d",&n);

    Q amanda[n];
    for(i=0;i<n;i++)
    {
        printf("enter the name of process %d,at,st\n",i);
        scanf("%s",&amanda[i].process_name);
        scanf("%d%d",&amanda[i].at,&amanda[i].st);
    }

    //sorting
    for(i=0;i<n;i++)
    {
        for(j=i;j>=1;j--)
        {
            if(amanda[j].at<amanda[j-1].at)
            {
                g=amanda[j-1];
                amanda[j-1]=amanda[j];
                amanda[j]=g;
            }
            else if(amanda[j].at==amanda[j-1].at)
            {
                if(amanda[j].st<amanda[j-1].st)
                {
                    g=amanda[j-1];
                    amanda[j-1]=amanda[j];
                    amanda[j]=g;
                }
            }
        }
    }

    quantum_time+=amanda[0].at+amanda[0].st;
    for(i=1;i<n;i++)
    {
        if(amanda[i].at>quantum_time)
            quantum_time=amanda[i].at;
        quantum_time+=amanda[i].st;
    }


    find(amanda);
    return 0;
}

