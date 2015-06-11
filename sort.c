# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int main ()
{
    FILE *fp;
    int i;
    char *ch, str[100];
    float size[20];
    fp=fopen("layersize.txt", "rt");
    while(fgets(str, 100, fp))
    {
       //printf("%s", str);
       i=0;
       size[i++]=atof(strtok(str, " "));
       while((ch=strtok(NULL, " ")))
       {
           size[i++]=atof(ch);
       }
       bubblesort(size, i-1);
    }
}

int bubblesort(float size[], int n)
{
    int i, j;
    float temp;
    for(i=n-1; i>0; i--)
    {
        for(j=0; j<i; j++)
        {
	    if(size[j]<size[j+1])
            {
                temp=size[j];
                size[j]=size[j+1];
                size[j+1]=temp;
            }
        }
    }
    for(i=0; i<n; i++)
       printf("%.3f  ", size[i]);
    printf("\n");
}

