#include <stdio.h>
int main(){
	for(int i = 0; i < 10; i++){
		for(int j = 1; j < 10 ; j++){
			if(j == 5) break;
			printf("%d ", j);
		}
		printf("\n");
	}
	return 0;
}


					...

					外层循环() 
					{
						...
						
						内层循环()
						{
							...;
		
						} 
						
						...
						
					} 







 
