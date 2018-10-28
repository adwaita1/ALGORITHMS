#include<iostream>
using namespace std;

#define MAXSIZE 10
int total_items;
float total_weight,profit[MAXSIZE],weight[MAXSIZE];

struct tuple{
	int flag,id;
	float UB,LB;
};

void get_input(){
	int i;
	cout<<"Enter total number of items: ";
	cin>>total_items;
	cout<<"Enter the profit: \n";
	for(i=1;i<=total_items;i++)
		cin>>profit[i];
	cout<<"Enter the weight: \n";
	for(i=1;i<=total_items;i++)
		cin>>weight[i];
	cout<<"Enter weight contraint: ";
	cin>>total_weight;
}

void sort_input(){
	float ratio[total_items];
	int i,j,temp;
	for(i=1;i<=total_items;i++)
		ratio[i]=profit[i]/weight[i];
	for(i=1;i<=total_items;i++){
		for(j=i+1;j<=total_items;j++){
			if(weight[j]<weight[j-1]){
				temp=profit[j];
				profit[j]=profit[j-1];
				profit[j-1]=temp;
				temp=ratio[j];
				ratio[j]=ratio[j-1];
				ratio[j-1]=temp;
				temp=weight[j];
				weight[j]=weight[j-1];
				weight[j-1]=temp;
			}
		}
	}
	for(i=1;i<=total_items;i++){
		for(j=i+1;j<=total_items;j++){
			if(ratio[j]>ratio[j-1]){
				temp=profit[j];
				profit[j]=profit[j-1];
				profit[j-1]=temp;
				temp=ratio[j];
				ratio[j]=ratio[j-1];
				ratio[j-1]=temp;
				temp=weight[j];
				weight[j]=weight[j-1];
				weight[j-1]=temp;
			}
		}
	}
	cout<<"Input is: \n";
	cout<<"Tuple\tProfit\tWeight\tRatio\n";
	for(i=1;i<=total_items;i++)
		cout<<i<<"\t"<<profit[i]<<"\t"<<weight[i]<<"\t"<<ratio[i]<<"\n";
}

float calculate_ub(float current_wt,float current_pr,int current_item){
	float cw=current_wt;
	float cp=current_pr;
	for(int i=current_item+1;i<=total_items;i++){
		if(cw+weight[i]<=total_weight){
			cw=cw+weight[i];
			cp=cp-profit[i];
		}
	}
	return cp;
}

float calculate_lb(float current_wt,float current_pr,int current_item){
	float cw=current_wt;
	float cp=current_pr;
	for(int i=current_item+1;i<=total_items;i++){
		cw=cw+weight[i];
		if(cw<total_weight){
			cp=cp-profit[i];
		}
		else{
			return (cp-(1-(cw-total_weight)/weight[i])*profit[i]);
		}
	}
	return cp;
}

void knapsack_bb(){
	int i,next,solution[MAXSIZE]={0};
	float wt=0,pr=0;
	struct tuple left_child,right_child,current;
	current.UB=calculate_ub(0,0,0);
	current.LB=calculate_lb(0,0,0);
	current.flag=-1;
	current.id=0;
	i=1;
	do{
		next=current.id+1;
		right_child.UB=calculate_ub(wt,pr,next);
		right_child.LB=calculate_lb(wt,pr,next);
		right_child.flag=0;
		right_child.id=next;
		left_child.flag=1;
		left_child.id=next;
		if(wt+weight[next]<=total_weight){
			left_child.UB=calculate_ub(wt+weight[next],pr-profit[next],next);
			left_child.LB=calculate_lb(wt+weight[next],pr-profit[next],next);
		}
		else{
			current.UB=pr;
			left_child.LB=pr;
		}
		if(left_child.LB<=right_child.LB && left_child.UB<=right_child.UB)
			current=left_child;
		else
			current=right_child;
		solution[i]=current.flag;
		i++;
		if(current.flag==1){
			pr=pr-profit[(current.id)];
			wt=wt-weight[(current.id)];
		}
	}while(current.id!=total_items);
	cout<<"\nSolution= ";
	for(i=1;i<=total_items;i++)
		cout<<solution[i]<<"\t";
	cout<<"\nMax profit: "<<-(current.LB)<<"\n";
}

int main(){
	get_input();
	sort_input();
	knapsack_bb();
	return 0;
}

















