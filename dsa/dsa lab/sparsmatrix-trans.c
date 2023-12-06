#include<stdio.h>
                struct spa
                {
                    int row; int col; int val;
                };
                main()
                {
                    struct spa a[20],b[20];
                    printf("Enter of rows, coloums, and Value\n");
                    scanf("%d%d%d",&a[0].row,&a[0].col,&a[0].val);
                    int i,n=a[0].val;
                    printf("Enter row number, coloum number, and value\n");
                    for(i=1; i<=n; i++)
                    {
                        scanf("%d%d%d",&a[i].row,&a[i].col,&a[i].val);
                    }
            
                    display(a);
                    transpose(a,b);
                    fast(a,b);
                    display(b);
                    
                 
                }
                
                display(struct spa a[]){
                	int i;
                printf("\nROW \t Column\t Value\n");
                
                for( i=1;i<=a[0].val;i++)
                    printf("\n%d\t %d\t %d\t",a[i].row,a[i].col,a[i].val);
                
                
                }
               
                transpose(struct spa a[],struct spa b[])
                {
                    int i=0,j,k=1,t=0;
                      b[0].row=a[0].col;
				   b[0].col=a[0].row; 
				   b[0].val=a[0].val;
                       for(i=0; i< a[0].col; i++)
                         {
                             for(j=1; j<=a[0].val; j++)
                               {
                          if(i==a[j].col)
                          {
                               b[k].row=a[j].col;
                                b[k].col=a[j].row;
                                 b[k].val=a[j].val;
                                  k++;
                          }
                        }
                      }
                      printf("\nSimple Transpose matrix is:\n");
                    
                       display(b);
                }
                fast(struct spa a[],struct spa b[])
                {
                    int i=0,j,k=1,t=0;
				 int r_terms[20],start_pos[20];
                      b[0].row=a[0].col; 
				  b[0].col=a[0].row; 
				  b[0].val=a[0].val;
                       for(i=0; i< a[0].col; i++)
                         {
					r_terms[i]=0;
					}
                         for(i=1; i<=a[0].val; i++)
                         {
					r_terms[a[i].col]++;
					}
                         start_pos[0]=1;
                         for(i=1; i< a[0].col; i++)
                         {
                         	
                         	
                         	
                         	
                         	
					start_pos[i]=r_terms[i-1]+start_pos[i-1];
					}
                        for(j=1; j<=a[0].val; j++)
                        {  k=start_pos[a[j].col]++;
                
                               b[k].row=a[j].col; 
						 b[k].col=a[j].row;
						  b[k].val=a[j].val;
                          }
                
                
                      printf("\nFast-Transpose matrix is:\n");
                 
                       display(b);
                }
