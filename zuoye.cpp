#include<stdio.h>
#include<string.h>
int flag=1;
int n;
int change1(char a[]){
	int n;
	if(strcmp(a,"零")==0) n=0;
	else if (strcmp(a,"一")==0) n=1;
	else if (strcmp(a,"二")==0) n=2;
	else if (strcmp(a,"三")==0) n=3;
	else if (strcmp(a,"四")==0) n=4;
	else if (strcmp(a,"五")==0) n=5;
	else if (strcmp(a,"六")==0) n=6;
	else if (strcmp(a,"七")==0) n=7;
	else if (strcmp(a,"八")==0) n=8;
	else if (strcmp(a,"九")==0) n=9;
	else n=10;
	return n;
}
void change3(int n){
	if(n==0) printf("零"); 
	else if(n==1) printf("一"); 
	else if(n==2) printf("二"); 
	else if(n==3) printf("三"); 
	else if(n==4) printf("四"); 
	else if(n==5) printf("五"); 
	else if(n==6) printf("六"); 
	else if(n==7) printf("七"); 
	else if(n==8) printf("八"); 
	else if(n==9) printf("九"); 
	if(n==10) printf("十"); 
}
void change4(int n){
	if(n==0) printf("十"); 
	else if(n==1) printf("十一"); 
	else if(n==2) printf("十二"); 
	else if(n==3) printf("十三"); 
	else if(n==4) printf("十四"); 
	else if(n==5) printf("十五"); 
	else if(n==6) printf("十六"); 
	else if(n==7) printf("十七"); 
	else if(n==8) printf("十八"); 
	else if(n==9) printf("十九"); 

}
void change2(int n){
	if(n<=9){
		change3(n);
	}
	else{
		int shiwei,gewei;
		shiwei=n/10;
		gewei=n%10;
		if(shiwei==1)//11-19
		{
			change4(gewei);
		}
		else{
			if(gewei==0)//整十 
			{
				change3(shiwei);
				printf("十"); 
			}
			else//十位不为1，个位不为0 
			{
				change3(shiwei);
				printf("十");
				change3(gewei);
			}
		} 
	}
}
int main(){
	int n;
	char lei[10],rongqi[10],fuhao[10],shuzi[10],r2[10];
	scanf("%s %s %s %s",lei,rongqi,fuhao,shuzi);
	n=change1(shuzi);
	if(strcmp(lei,"整数")==0) {
		if(strcmp(rongqi,"钱包")==0){
			while(1){
				scanf("%s",r2);
				if(strcmp(r2,"钱包")==0) {
					scanf("%s %s",fuhao,shuzi);
					if(strcmp(fuhao,"增加")==0) n+=change1(shuzi);
					else n-=change1(shuzi);
				} 
				if(strcmp(r2,"看看")==0) break;
			}
		}
		else flag=0; //标记变量不为“钱包” 
	}
	else flag=0;//标记变量不为“整数” 
	if(flag==0) printf("error");
	else change2(n);
	return 0;
} 
