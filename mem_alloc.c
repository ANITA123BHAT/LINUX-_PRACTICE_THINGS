#include<stdio.h>
#include<malloc.h>
int main(){
	int *ptr1,*ptr2,*ptr3;
ptr1=(int*)malloc(5*sizeof(int));

ptr2=(int*)malloc(10*sizeof(int));
ptr3=(int*)malloc(12*sizeof(int));
*(ptr1+0)=99;
*(ptr1+1)=88;
*(ptr1+2)=77;
*(ptr1+3)=66;

*(ptr2+0)=90;
*(ptr2+1)=80;
*(ptr2+2)=70;
*(ptr2+3)=60;

*(ptr3+0)=11;
*(ptr3+1)=12;
*(ptr3+2)=33;
*(ptr3+3)=34;

*(ptr3+4)=12;
*(ptr3+5)=12;
*(ptr3+6)=12;
*(ptr3+7)=12;
*(ptr3+8)=12;
*(ptr3+9)=12;
*(ptr3+10)=12;
printf("ptrr1 data:\n");
for(int i=0;i<4;i++){
	printf("%d\n",*(ptr1+i));
}

printf("ptr2 data:\n");
for(int i=0;i<4;i++){
	printf("%d\n",*(ptr2+i));
}
printf("ptrr3 data:\n");
for(int i=0;i<11;i++){
	printf("%d\n",*(ptr3+i));
}
free(ptr1);
free(ptr2);
free(ptr3);
}
