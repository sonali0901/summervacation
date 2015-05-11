#include<stdio.h>
#include<string.h>
int main()
{
        int t,i,j,k,len;
        char a[101],swap;
        scanf("%d",&t);
        for(i=0;i<t;i++){
	scanf("%s",a);
        len=strlen(a);
        for(j=0;j<len-1;j++)
        {
                for(k=0;k<len-j-1;k++){
                if(a[k]>a[k+1]){
                swap=a[k];
                a[k]=a[k+1];
                a[k+1]=swap;
                }
                }
        } /*sorting done*/

	char b[101];
	b[0]=a[0];
	int p=1;
      	for(k=1;k<=len;k++){
	if(a[k]!=a[k-1]){
	b[p]=a[k];
	p++;}
	
        }

	int len2=strlen(b);
	if(len2==26)
	printf("YES\n");
		else
	printf("NO\n");
}
        return 0;
}
