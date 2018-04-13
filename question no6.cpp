//												Question No. 6




#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

struct pro{
	int id, burst_time, arrival_time, completion_time, turnaround_time, waiting_time, status;				
}r[10];


bool comp(pro a, pro b)
{
	return a.burst_time < b.burst_time;
}

void display(int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Process ID: "<<r[i].id<<endl<<"Process Burst time: "<<r[i].burst_time<<endl;
		cout<<"Process arrival time: "<<r[i].arrival_time<<endl<<"Process status: "<<r[i].status;
		cout<<endl<<endl;
	}
}

void show(queue <int> gq)
{
	queue <int> g = gq;
	while(!g.empty())
	{
		cout<<"\t"<<g.front();
		g.pop();
	}
	cout<<"\n";
}

int main()
{
	int n,i,j,k;
	cout<<"Enter the number of processes:\n";
	cin>>n;
	queue <int> o;
		
	cout<<"Enter the arrival time of each process:\n";
	for(i=0;i<n;i++)
	{
		cout<<"Enter the ariival time of P"<<i+1<<":"<<endl;
		cin>>r[i].arrival_time;
		r[i].id = i+1;
	}

	cout<<"Enter the burst time of each process:\n";
	for(i=0;i<n;i++)
	{
		cout<<"Enter the burst time of P"<<i+1<<":"<<endl;
		cin>>r[i].burst_time;
	}
	
	for(i=0;i<n;i++)
		r[i].status = 0;	
	
	sort(r, r+n, comp);
	

	int min = r[0].arrival_time;
	int loc;
	for(i=0;i<n;i++)
	{
		if(min > r[i].arrival_time)
			loc = i;
	}
	
	cout<<"Processing P"<<r[loc].id<<" for "<<r[loc].burst_time<<" seconds"<<endl;
	int time = r[loc].burst_time;
	r[loc].status = 1;
	r[loc].completion_time = time;
	o.push(r[loc].id);
	
	i=0;
	int process_count = 1;
	while(process_count!=n)
	{
		if(r[i].status!=1 && r[i].arrival_time <= time)
		{
			cout<<"Processing P"<<r[i].id<<" for "<<r[i].burst_time<<" seconds"<<endl;
			time += r[i].burst_time;
			o.push(r[i].id);
			r[i].status = 1;
			r[i].completion_time = time;
			process_count++;
		}
		i = (i+1)%n;
	}
	
	show(o);
	

	for(i=0;i<n;i++)
	{
		r[i].turnaround_time = r[i].completion_time - r[i].arrival_time;
	}
	
	for(i=0;i<n;i++)
	{
		r[i].waiting_time = r[i].turnaround_time - r[i].burst_time;
	}
	
	
	int sum = 0;
	for(i=0;i<n;i++)
	{
		sum+= r[i].turnaround_time;
	}
	cout<<"\nAverage turnaround time is "<<sum/n<<endl;
	
	sum = 0;
	for(i=0;i<n;i++)
	{
		sum+= r[i].waiting_time;
	}
	cout<<"\nAverage waiting time is "<<sum/n<<endl;

	return 0;
}

