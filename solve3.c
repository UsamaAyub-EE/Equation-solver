#include<stdio.h>
#include<math.h>
int GCD(int,int);
void print_eqs(int[][5],int[],int);
int det(int,int[][5]);
void print_fraction(int,int);
int main()
{
	int number,copy[5][5],A[5][5],B[5],i,j,k,detA;
	char vars[]="xyzvw";
	char* eq_number[]={"first","second","third","fourth","fifth"};
	puts("Enter the number of equations");
	scanf("%d",&number);
	for(i=0;i<number;i++)
	{
		for(j=0;j<number;j++)
		{
			printf("Enter the coefficient of %c in %s equation\n",vars[j],eq_number[i]);
			scanf("%d",&A[i][j]);
		}
		printf("Enter the constant term for %s equation\n",eq_number[i]);
		scanf("%d",&B[i]);
	}
	puts("The equations you entered are as under:");
	print_eqs(A,B,number);
	detA=det(number,A);
	if(detA==0)
	{
		puts("The solution of these equations is not possible.");
		return 0;
	}
	puts("The solution of these equations is as under:");
	for(k=0;k<number;k++)
	{
		for(i=0;i<number;i++)
		{
			for(j=0;j<number;j++)
			{
				if(j==k)
					copy[i][j]=B[i];
				else
					copy[i][j]=A[i][j];
			}
		}
		printf("\n%c= ",vars[k]);
		print_fraction(det(number,copy),detA);
	}
	return 0;
}
int det(int size,int a[][5])
{
	int sub[5][5],i,j,l,m,in1,in2,deter=0;
	if(size==2)
	{
		return a[0][0]*a[1][1]-a[0][1]*a[1][0];
	}
	else
	{
		for(i=0;i<1;i++)
		{
			for(j=0;j<size;j++)
			{
				in1=in2=0;
				for(l=0;l<size;l++)
				{
					for(m=0;m<size;m++)
					{
						if(l!=i&&m!=j)
						{
							sub[in1][in2]=a[l][m];
								if(in2<(size-2))
								{
									in2++;
								}
								else
								{
									in2=0;
									in1++;
								}
						}
					}
				}
				deter+=pow(-1,i+j)*a[i][j]*det(size-1,sub);
			}
		}
	}
	return deter;
}
void print_eqs(int A[][5],int B[],int number)
{
	int i;
	for(i=0;i<number;i++)
	{
		if(number==2)
			printf(" %d.x %+d.y = %d\n",A[i][0],A[i][1],B[i]);
		if(number==3)
			printf(" %d.x %+d.y %+d.z = %d\n",A[i][0],A[i][1],A[i][2],B[i]);
		if(number==4)
			printf(" %d.x %+d.y %+d.z %+d.v = %d\n",A[i][0],A[i][1],A[i][2],A[i][3],B[i]);
		if(number==5)
			printf(" %d.x %+d.y %+d.z %+d.v %+d.w = %d\n",A[i][0],A[i][1],A[i][2],A[i][3],A[i][4],B[i]);
	}
}
void print_fraction(int num,int den)
{
	if(num==0)
	{
		printf("0");
		return;
	}
	int gcd=GCD(num,den);
	if((den/gcd)==1)
		printf("%d",num/gcd);
	else
		printf("%d\\%d",num/gcd,den/gcd);
}
int GCD(int n,int m)
{
	if(m!=0)
	{
		return GCD(m,n%m);
	}
	else
	{
		return n;
	}
}
