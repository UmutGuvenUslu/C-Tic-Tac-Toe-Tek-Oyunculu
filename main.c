#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char tahta[3][3];
const char oyuncu = 'X';
const char rakip = 'O';
char kazanankisi = ' ';

void tahtasifirla(){
int i , j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
				tahta[i][j] = ' ';
						}
					}
}
void tahtagoster(){
	printf("\n|---|---|---|\n");
	printf("|%c  | %c | %c |" , tahta[0][0] , tahta[1][0] , tahta[2][0]);
	printf("\n|---|---|---|\n");
	printf("|%c  | %c | %c |" , tahta[0][1] , tahta[1][1] , tahta[2][1]);
	printf("\n|---|---|---|\n");
	printf("|%c  | %c | %c |" , tahta[0][2] , tahta[1][2] , tahta[2][2]);
	printf("\n|---|---|---|\n");
}
int kazanantest(){
	if(tahta[0][0] == oyuncu && tahta[1][0] == oyuncu && tahta[2][0] == oyuncu || tahta[0][0] == oyuncu && tahta[0][1] == oyuncu && tahta[0][2] == oyuncu || tahta[0][1] == oyuncu && tahta[1][1] == oyuncu && tahta[2][1] == oyuncu || tahta[0][2] == oyuncu && tahta[1][2] == oyuncu && tahta[2][2] == oyuncu || tahta[1][0] == oyuncu && tahta[1][1] == oyuncu && tahta[1][2] == oyuncu || tahta[2][0] == oyuncu && tahta[2][1] == oyuncu && tahta[2][2] == oyuncu || tahta[0][0] == oyuncu && tahta[1][1] == oyuncu && tahta[2][2] == oyuncu || tahta[0][2] == oyuncu && tahta[1][1] == oyuncu && tahta[2][0] == oyuncu ){
		printf("\n\n####OYUN SONUCU####\n");
		printf("TEBRIKLER KAZANDIN!!!!");
		kazanankisi= oyuncu;
		return oyuncu;
	}else if(tahta[0][0] == rakip && tahta[1][0] == rakip && tahta[2][0] == rakip || tahta[0][0] == rakip && tahta[0][1] == rakip && tahta[0][2] == rakip || tahta[0][1] == rakip && tahta[1][1] == rakip && tahta[2][1] == rakip || tahta[0][2] == rakip && tahta[1][2] == rakip && tahta[2][2] == rakip || tahta[1][0] == rakip && tahta[1][1] == rakip && tahta[1][2] == rakip || tahta[2][0] == rakip && tahta[2][1] == rakip && tahta[2][2] == rakip || tahta[0][0] == rakip && tahta[1][1] == rakip && tahta[2][2] == rakip || tahta[0][2] == rakip && tahta[1][1] == rakip && tahta[2][0] == rakip){
		printf("\n\n####OYUN SONUCU####\n");
		printf("KAYBETTIN!!!!");
		kazanankisi= rakip;
		return rakip;
	}else if(oyunkontrol()==0){
		printf("BERABERE KALDIN...");
		kazanankisi= 'B';
		return 'B';
	}else{
		kazanankisi= ' ';
		return ' ';
		
	}
		
	
	
}
void oyuncuu(){
	int x; int y;
	printf("Satiri Giriniz(1-3 arasi): ");
	scanf("%d" , &x);
	x--;
	printf("Sutunu Giriniz(1-3 arasi): ");
	scanf("%d" , &y);
	y--;
	
	while(tahta[x][y] == rakip || tahta[x][y] != ' ' || tahta[x][y] == oyuncu){
	printf("\nGECERSIZ HAMLE!!\n");
	printf("Satiri Giriniz(1-3 arasi): ");
	scanf("%d" , &x);
	x--;
	printf("Sutunu Giriniz(1-3 arasi): ");
	scanf("%d" , &y);
	y--;

	
	}
	tahta[x][y]= oyuncu;
}
int oyunkontrol(){
	int kontrol =9;
	int u, k;
	for(u=0;u<3;u++){
		for(k=0;k<3;k++){
			if(tahta[u][k] != ' '){
				kontrol=kontrol-1;
			}
		}
	}
	return kontrol;
}
void oyuncuu2(){
	int x; int y;
	srand(time(NULL));
	x = rand() % 3;
	
	y = rand() % 3;
	
	
	while(tahta[x][y] == rakip||tahta[x][y] == oyuncu || tahta[x][y] != ' '){
		
	
	
	x = rand() % 3;
	
	y = rand() % 3;
	

	}
	tahta[x][y]= rakip;
}
			
	




int main() {
	int kk; 
	tahtasifirla();
	while(oyunkontrol!=0 || kazanankisi == ' '){
		tahtagoster();
		oyuncuu();
		kazanantest();
		kk = oyunkontrol();
		if(kazanankisi != ' ' || kk==0){
			break;
		}
		oyuncuu2();
		kazanantest();
		kk = oyunkontrol();
		if(kazanankisi != ' ' || kk==0){
			break;
		}
	}
	
	tahtagoster();
	
	getch();
	
	return 0;
}
