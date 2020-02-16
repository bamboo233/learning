#include<stdio.h>
#include<string.h>
#include<iostream>
#include<cstring>
using namespace std;
const char *ch[11]={"零","一","二","三","四","五","六","七","八","九","十"}; 
int change1(char shu[] ){
	char *chin;
	chin=shu;
	int i=0;
	while(1){
		if(!strcmp(chin,ch[i])) break;
		i++;
	}
	return i;
} 
int change2(char shu[]){//10-20，整十数 
    char *chin,shu2[10]={0}; 
	chin=shu;
    int i,j,l=0,k=0,n=0,len=strlen(shu);
    int g=0;
    for(i=0,j=0;j<len;i++,j+=2){
        for(k=0;k<2;l++,k++) {
           shu2[k]=shu[l];
        }
        chin=shu2;
        n+=g;
        for (g=0;;g++){
            if (!strcmp(chin,ch[g])){
                break;
            }
        }
        if(g!=10&&i==0)
        return g*10;
    }
    return n+g;
}
int change3(char shu[]){
    char *chin;
    char shu2[10];
    int i,j,s[2]={0,4},n=0,g=0;
    for(i=0;i<2;i++) {
        for(j=0;j<2;s[i]++,j++){
            shu2[j]=shu[s[i]];
        }
        chin=shu2;
        if(i==1){
        	n=g*10;
		}
        for(g=0;;g++){
            if (!strcmp(chin,ch[g])){
                break;
            }
        }
    }
    return n+g;
}
int input(char shu[]){
	int len=strlen(shu),n;
	if(len==2){
	    n=change1(shu);	
	}
	else  if(len==4){
		n=change2(shu);
	}
	else{
		n=change3(shu);
	}
	return n;
} 
void switch1(int n){
	cout << ch[n];
}
void switch2(int n){
	n%=10;
	cout <<"十";
	cout << ch[n]; 
}
void switch3(int n){
	int ge,shi;
	shi=n/10;
	ge=n%10;
	if(!ge){
	    cout << ch[shi];
	    cout << "十"; 
	}
	else{
		cout << ch[shi];
		cout <<"十";
		cout << ch[ge];
	}
}
void output(int n){
	if(n<=10){
		switch1(n);
	} 
	else if(n>=11&&n<=19){
		switch2(n);
	} 
	else{
		switch3(n); 
	}
}
int main(){
	int n;
	char lei[10],rong[10],fu[10],shu[10],r2[10];
	cin >> lei >> rong >> fu >> shu;
	n=input(shu);
	if(strcmp(lei,"整数")==0) {
		if(strcmp(rong,"钱包")==0){
			while(1){
				cin >> r2;
				if(strcmp(r2,"钱包")==0) {
					cin >> fu >> shu;
					if(strcmp(fu,"增加")==0) n+=input(shu);
					else n-=input(shu);
				} 
				if(strcmp(r2,"看看")==0) break;
			}
		}
	}
    output(n);
    return 0;
}
