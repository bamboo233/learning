#include<stdio.h>
#include<string.h>
int flag=1;
int n;
int change1(char a[]){
	int n;
	if(strcmp(a,"��")==0) n=0;
	else if (strcmp(a,"һ")==0) n=1;
	else if (strcmp(a,"��")==0) n=2;
	else if (strcmp(a,"��")==0) n=3;
	else if (strcmp(a,"��")==0) n=4;
	else if (strcmp(a,"��")==0) n=5;
	else if (strcmp(a,"��")==0) n=6;
	else if (strcmp(a,"��")==0) n=7;
	else if (strcmp(a,"��")==0) n=8;
	else if (strcmp(a,"��")==0) n=9;
	else n=10;
	return n;
}
void change3(int n){
	if(n==0) printf("��"); 
	else if(n==1) printf("һ"); 
	else if(n==2) printf("��"); 
	else if(n==3) printf("��"); 
	else if(n==4) printf("��"); 
	else if(n==5) printf("��"); 
	else if(n==6) printf("��"); 
	else if(n==7) printf("��"); 
	else if(n==8) printf("��"); 
	else if(n==9) printf("��"); 
	if(n==10) printf("ʮ"); 
}
void change4(int n){
	if(n==0) printf("ʮ"); 
	else if(n==1) printf("ʮһ"); 
	else if(n==2) printf("ʮ��"); 
	else if(n==3) printf("ʮ��"); 
	else if(n==4) printf("ʮ��"); 
	else if(n==5) printf("ʮ��"); 
	else if(n==6) printf("ʮ��"); 
	else if(n==7) printf("ʮ��"); 
	else if(n==8) printf("ʮ��"); 
	else if(n==9) printf("ʮ��"); 

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
			if(gewei==0)//��ʮ 
			{
				change3(shiwei);
				printf("ʮ"); 
			}
			else//ʮλ��Ϊ1����λ��Ϊ0 
			{
				change3(shiwei);
				printf("ʮ");
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
	if(strcmp(lei,"����")==0) {
		if(strcmp(rongqi,"Ǯ��")==0){
			while(1){
				scanf("%s",r2);
				if(strcmp(r2,"Ǯ��")==0) {
					scanf("%s %s",fuhao,shuzi);
					if(strcmp(fuhao,"����")==0) n+=change1(shuzi);
					else n-=change1(shuzi);
				} 
				if(strcmp(r2,"����")==0) break;
			}
		}
		else flag=0; //��Ǳ�����Ϊ��Ǯ���� 
	}
	else flag=0;//��Ǳ�����Ϊ�������� 
	if(flag==0) printf("error");
	else change2(n);
	return 0;
} 
