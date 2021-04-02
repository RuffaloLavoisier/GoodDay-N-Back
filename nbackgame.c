
#include<stdio.h>
#include<stdlib.h>    // srand, rand
#include<time.h>    // time_t, clock, difftime

//#define DELAY 3000    // 지연시간 5초
#define N_BACK 3
int main(void)
{
	int n_back_mode = N_BACK;
	int n_back_box[N_BACK + 1] = { 0 }; //n back 박스 생성

	int score_r = 0;                // 정답 수 
	time_t new_time, old_time;    // 경과 시간 
	int ScoreStart=0;                    // 답 입력 여부 
	int count = 0;
	int real_q_count = 0;

	char prev_answer = 'Z';
	char my_prev_answer = 'Z';

	char answer = 'Z';
	char my_answer = 'Z';


	//-----------------------동적할당 세트
	/*int* n_back_box;
	int n_back_mode;
	printf("How many N - BACKs would you like to challenge? : ");
	scanf_s("%d", &n_back_mode);
	n_back_box = (int*)malloc(sizeof(int) * n_back_mode);
	free(n_back_box);*/

	srand(time(NULL));        // 시작할 때마다 값이 달라지도록 함

	printf("********************************\n");
	printf("*   Welcome to brain training  *\n");
	printf("*          <N - BACK>          *\n");
	printf("*          2020.09.24          *\n");
	printf("*      Sunghwan Version 2      *\n");
	printf("********************************\n");
	printf("\n");
	printf("< How To Start? >\n");
	printf("Random numbers appear in turn.\n");
	printf("If the current number and the number before the second number are the same,\n");
	printf("you can type O or X.\n");
	printf("Of course, if there are no previous numbers to compare,\n");
	printf("you can just prepare you are mind, right? Good luck.\n");
	printf("\n");
	printf("Are you ready ? Press Enter(please give me answer in 2 s)");
	getchar();

	while (1) {
		for (int i = 0; i <= n_back_mode; i++)//배열 숫자 밀어내기
		{
			if (i != n_back_mode)
				n_back_box[i] = n_back_box[i + 1];
			else
				n_back_box[i] = 0;
		}
		n_back_box[n_back_mode] = (rand() % 9 + 1) * (rand() % 9 + 1) % 10;//한자리의 랜덤한 숫자 부여
		count++;//랜덤 생성 횟수
		if (n_back_box[0] == n_back_box[n_back_mode])//n-back 정답 추출
			answer = 'o';
		else
			answer = 'x';

//		old_time = clock();        // 시작 시간 
//		keyin = 1;                // 키입력 초기값 
		system("clear");
		if(count>=N_BACK+1){
			printf("총 문제 : %d 맞은 갯수 : %d \n이전 정답 : %c 내가 쓴 정답 : %c \n", real_q_count, score_r, prev_answer, my_prev_answer);
			ScoreStart = 1;
		}
		printf("Random : %d\n", n_back_box[n_back_mode]);
/*		
		do {
			new_time = clock();    // 현재 시간 
			if (difftime(new_time, old_time) > DELAY) {    // 시간 초과 검사 
				my_answer = 'Z';        // 답이 없음 
				keyin = 0;        // 키입력이 없음 
				break;
			}
		} while (!kbhit());        // 키가 안 눌린 동안 


		if (keyin == 1) {
*/
			scanf(" %c",&my_answer);       // 답을 받음 
/*			new_time = clock();    // 현재 시간 
			if (difftime(new_time, old_time) > DELAY) my_answer = 'Z';
		}
*/if (ScoreStart){
		if (answer == my_answer) {
			score_r++;    // 정답수 
		}
		else {
			//printf("시간을 초과했거나 틀렸어요 정답은 %d입니다\n총 맞추신개수는 %d입니다\n", sum, score);
			//printf("시간을 초과했거나 틀렸어요\n");
			//return 0;
		}}

		my_prev_answer = my_answer;
		prev_answer = answer;
		if (count >= sizeof(n_back_box) / sizeof(n_back_box[0])) {
			real_q_count++;
		}
	}
}
