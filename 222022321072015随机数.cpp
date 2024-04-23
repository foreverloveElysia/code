//传一个二维数组，在随机位置生成一共指定数目生成随机数，随机数范围一到八 ，没有随机数的位置0 
#include<stdio.h>
#include<stdlib.h>
#include<time.h> 

void Printshuzu(int *t,int rows,int cols){
	int i,j;
	for(i = 0;i < rows;i++){
		for(j = 0;j < cols;j++){
			if(j != 0){
			printf(" %d",*(t + i*rows + j));
			}
			else
			printf("%d",*(t + i*rows + j));
		}
		printf("\n");
	}
} 

void Initshuzu(int *t, int rows,int cols){
	for(int i = 0;i < rows;i++){
		for(int j = 0;j < cols;j++){
			*(t + i*rows + j)=0;
		}
	}
}

void Createshuzu(int *t, int rows,int cols,int num){
	srand(time(NULL));
	int ran_num_row = 0;
	for(int i = 0;i < rows;i++){
		int k = 1;
		if(num <= 0){
			continue;
		}
		
		if(num >= cols){
			ran_num_row = rand()%(cols + 1); 
		}
		else{
			ran_num_row = rand()%(num + 1);
		} 
		
		if(i == rows - 1 && num > 0){
			ran_num_row = num;
		} 
		num -= ran_num_row;
		int col_num = cols - ran_num_row + 1;
		while(ran_num_row > 0){
			int j = rand()%col_num + k;
			*(t + i*rows + j)=  rand()%8 + 1;
			ran_num_row--;
			col_num = cols - k - ran_num_row + 1;
			k = j + 1;
		}
	}	
}

int main(void){
//	int t[3][2] = {{3,4},{5,6},{7,8}};
//	Printshuzu(*t,3,2);
	int rows,cols,num;
	printf("请输入你想要创建的数组的大小（先行后列）：");
	scanf("%d %d",&rows,&cols);
	int t[rows][cols];
	printf("\n请输入生成随机数的数目：");
	scanf("%d",&num); 
	Initshuzu(*t, rows,cols);
	Createshuzu(*t,rows,cols,num);
	Printshuzu(*t,rows,cols);
}
