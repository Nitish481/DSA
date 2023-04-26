#include<stdio.h>
#include<stdlib.h>
int n;
int* create(int *ptr){
	int i;
	printf("\nenter the size of array: ");
	scanf("%d",&n);
	ptr=(int*)malloc(n*sizeof(int));
	printf("\nenter the elements:");
	for(i=0;i<n;i++){
		scanf("%d",&ptr[i]);
	}
	return ptr;
}

void display(int *ptr, int n){
	int i;
	printf("\nthe array :  ");
	for(i=0;i<n;i++)
		printf("%d  ",ptr[i]);
        printf("\n");
} 

void count(){
	if(n==0){
		printf("\nempty array");
		return;
	}
	printf("\ntotal number of elements :%d",n);
}

void reverse(int *ptr)
{
    int start,r,temp;
    start=0;  r=n-1;
    while(start<r)
    {
        temp=ptr[start];
        ptr[start]=ptr[r];
        ptr[r]=temp;
        start+=1;
        r-=1;
    }
	display(ptr,n);
}

void sort(int *ptr){
	int temp;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(ptr[i]>ptr[j]){
				temp=ptr[i];
				ptr[i]=ptr[j];
				ptr[j]=temp;
			   }
		}
	}
		display(ptr,n);
}

void indexed_element(int * ptr,int l){
	if(l>=n)
	{
	   printf("\nindex not present");
	   return;
        }
	printf("\n the element at index %d is: %d",l,ptr[l]);
} 

void search(int *ptr,int ele){
	int flag=0,pos;
	for(int i=0;i<n;i++){
		if(ptr[i]==ele)
		{
		  flag=1;
		  pos=i;
		  break;
		}
	}
	if(flag==1)
	     printf("\nelement %d is found at index %d",ele,pos);
	else
	     printf("\nelement not found");
}   	

void insert(int item, int pos, int *ptr)
{
	int i;
	ptr = (int*)realloc(ptr,sizeof(int));
	n++;
	for (i=n-1;i>=pos;i--)
	{
		ptr[i] = ptr[i-1];
	}
	ptr[pos] = item;
	printf("Element inserted successfully\n");
	display(ptr,n);
}

void delete(int k,int*ptr){
	if(k<0 || k>=n){
		printf("\ninvalid position");
		return;
	}
	else{
		for(int i=k;i<n-1;i++){
			ptr[i]=ptr[i+1];
		}
	}
	n--;
		display(ptr,n);
}

void merge(int *ptr,int *ptr1){
	int n2;
	int *res=NULL;
	printf("\nenter the size of  2nd array: ");
	scanf("%d",&n2);
	ptr1=(int*)malloc(n2*sizeof(int));
	printf("\nenter the elements:");
	for(int i=0;i<n2;i++){
		scanf("%d",&ptr1[i]);
	}
	int i=0,j=0,k=0;
	res=(int*)malloc((n+n2)*sizeof(int));
	while(i<n && j<n2){
		if(ptr[i]<ptr1[j]){
			res[k]=ptr[i];
			i++; k++;
		}
		else{
			res[k]=ptr1[j];
			j++; k++;
		}
	}
	while(i<n){
		res[k++]=ptr[i++];
	}
	while(j<n2){
		res[k++]=ptr1[j++];
	}
	display(res,k);
}

void split(int *ptr, int n)
{
    int *s1,*s2,i,k;
    if(ptr==NULL){
    	return;
	}
	s1=(int*)malloc(sizeof(int)*(n/2));
	s2=(int*)malloc(sizeof(int)*(n/2));
	for(i=0;i<n/2;i++){
		s1[i]=ptr[i];
	}
	k=0;
	for(;i<n;i++){
		s2[k++]=ptr[i];
	}
	printf("\n1st half\n");
	display(s1,n/2);
	printf("\n2nd half\n");
	display(s2,k);
}

void index_of(int *ptr,int ele){
	int i,found=0;
	printf("Indices of %d:",ele);
	for(i=0;i<n;i++)
	{
		if(ptr[i]==ele)
		{
			printf("%d ",i);
			found=1;
		}
	}
	if(!found)
		printf("None");
	
	printf("\n");
}   	

int main(){
	int *ptr=NULL;
	int *ptr1=NULL;
	int ch,l,item,pos;
	while(1){
		  printf("\n\n______MENU________");
		  printf("\nenter 1 for create \nenter 2 for display \nenter 3 for count\nenter 4 for reverse\nenter 5 for get index of a number\nenter 6 for indexed element\nenter 7 to insert\n");
		  printf("enter 8 to delete\nenter 9 to merge\nenter 10 to split\nenter 11 to sort\nenter 12 to search\nenter 0 to exit....\n\nenter choice:  ");
		  scanf("%d",&ch);
		  switch(ch)
		  {
		    case 1: ptr=create(ptr);
			   break;
		    case 2: display(ptr,n);
			   break;
		    case 3: count();
			   break;
		    case 4: reverse(ptr);
			   break;
			case 5: printf("\nenter the element: ");    
			    scanf("%d",&l);
			    index_of(ptr,l);
				break;	
		    
		    case 6: printf("\nenter an index ");
			    scanf("%d",&l);
			    indexed_element(ptr,l);  
			    break;
 		    case 7: 	printf("Enter a element you want to insert: ");
				scanf("%d", &item);
				printf("Enter the position where you want to insert the element: ");
				scanf("%d", &pos);
				insert(item, pos, ptr);
				break;
		    
			case 8:	printf("\nenter the position:(0 indexing)  ");
			    scanf("%d",&pos);
			    delete(pos,ptr);
				break;
			case 9: printf("create 2nd array :\n ");
				merge(ptr,ptr1);
				break;
			case 10: split(ptr,n);
				break;
			case 11: sort(ptr);
			   break;
			case 12: printf("\nenter the element to be search ");
			    scanf("%d",&l);
			    search(ptr,l);
			    break;
					 
		    case 0: printf("\n..........exit.........."); exit(0);

		    default : printf("\nwrong choice. try again");
			     break;
		  }
		}
	return 0;
}
