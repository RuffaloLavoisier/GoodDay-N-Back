#include <stdio.h>	// standard input output
#include <stdlib.h> // srand, rand
#include <time.h>	// time_t, clock, difftime

//#define n_back_mode 3 //what do you want game version ?

#define BASE 20

int main(void)
{
	int n_back_mode = 0; //사용자 지정 n box

	//----------------------

	int n_back_mode_box[BASE];

	for (int box = 0; box <= BASE - 1; box++)
	{ //init n box - 충분한 상자를 초기화
		n_back_mode_box[box] = 0;
	}

	//----------------------------------------
	FILE *fp = fopen("answer", "w"); // save log answer - 답안 저장 파일 생성

	//	int n_back_mode_box[n_back_mode + 1]; 	//n back 박스 생성 - version 1
	// 전처리를 이용해 컴파일 할 때 선언해준 상수를 가지고 n box를 생성한 경우

	int score = 0;	 		// 정답 수 (O,X)
	int ScoreStart = 0;	  // 답 입력 여부 (Bool)
	int count = 0;		  //문제 출제 조건 (랜덤 숫자 지나치기)
	int real_q_count = 0; // 첫 시작 카운트를 제외하고서 문제 수를 카운트

	char prev_answer = 'Z';	   //나름의 초기화
	char my_prev_answer = 'Z'; //나름의 초기화

	char answer = 'Z';
	char my_answer = 'Z';
	//-------------------
	srand(time(NULL)); // 시작할 때마다 값이 달라지도록 함
					   //--------------print 영역------------
	printf("********************************\n");
	printf("*   Welcome to Brain Training  *\n");
	printf("*          <N - BACK>          *\n");
	printf("*          2020.09.24          *\n");
	printf("*      Sunghwan Version 4      *\n");
	printf("********************************\n");
	printf("\n");
	printf("< How To Start? >\n");
	printf("Random numbers appear in turn.\n");
	printf("If the current number and the number before the second number are the same,\n");
	printf("you can type O or X.\n");
	printf("Of course, if there are no previous numbers to compare,\n");
	printf("you can just prepare you are mind, right? Good luck.\n");
	printf("\n");
	printf("Are you ready ? Press Enter(please give me answer in 2 s)\n");
	printf("\n");
	//--------------print 영역------------
	getchar();

	system("clear"); //clear screen
	//--------------print 영역------------
	printf("sample ! \n");
	printf("\n");

	printf("    **************           \n");
	printf("    *            *           \n");
	printf("    *     ****************   \n");
	printf("    *     *      *       *   \n");
	printf("    V     V      *       *   \n");
	printf(" ****** ****** ****** ****** \n");
	printf("*      *      *      *      *\n");
	printf("*   3  *   2  *   1  *   2  *\n");
	printf("*      *      *      *      *\n");
	printf(" ****** ****** ****** ****** \n");
	printf(" First  Second Third  Fourth \n");
	printf(" None   None    ( X )  ( O ) \n");
	//--------------print 영역------------
	getchar();

	system("clear"); //clear screen

	printf("How many boxes do you need?\n");
	scanf("%d", &n_back_mode);
	//printf("Your N BACK MODE : %d\n", n_back_mode);
	//getchar();

	for (int index = 0; index <= n_back_mode; index++) //사용자로부터 지정받은 숫자로 n box 초기화
	{
		n_back_mode_box[index] = 0;
	}

	//------------------------------------------------

	//main loop
	while (1){
		for (int box = 0; box <= n_back_mode; box++){ 
			//배열 숫자 밀어내기

			//현재 카운트하고 있는 box 값이
			//설정된 nback mode 값과 같지 않을 때 박스 밀어내기 시작
			if (box != n_back_mode){
				n_back_mode_box[box] = n_back_mode_box[box + 1]; // n back 첫번쨰 박스에는 두번째 박스의 값을 집어 넣는다.
			}
			else{
				n_back_mode_box[box] = 0; // n back 3 : **0 - 최신 값을 가져오기 전 0으로 초기화
			}
		}

		//n back 제일 마지막 상자에 한자리의 랜덤한 숫자 부여
		n_back_mode_box[n_back_mode] = (rand() % 9 + 1) * (rand() % 9 + 1) % 10;

		//랜덤 생성 횟수
		count++; //	n back 문제 출제 조건이 갖춰지는지 확인을 위한 이전 값을 넘김
				 // 3 Back : 랜덤한 숫자 3개를 지나쳐야 한다.

		//n-back 정답 추출
		if (n_back_mode_box[0] == n_back_mode_box[n_back_mode]) // 첫번째 값과 n back 마지막 값이 같을 때 정답 처리
			answer = 'o';
		else
			answer = 'x';

		//문제 프린트 전 이전에 프린트 된 내용을 삭제
		system("clear"); //clear screen

		//랜덤 보낸 숫자 횟수 값이 n back 상자보다 많아질 때 문제 출제 시작
		if (count >= n_back_mode + 1){
			//문제 출제 부터 카운트,맞은 갯수 카운트, 이전 정답, 내가 쓴 정답
			printf("%d - B A C K\n총 문제 : %d 맞은 갯수 : %d \n이전 정답 : %c 내가 쓴 정답 : %c \n",
				   n_back_mode, real_q_count, score, prev_answer, my_prev_answer);
			fprintf(fp, "%d - B A C K 총 문제 : %d 맞은 갯수 : %d 이전 정답 : %c 내가 쓴 정답 : %c 정답 : %c ", //(save log)
					n_back_mode, real_q_count, score, prev_answer, my_prev_answer, answer);
			ScoreStart = 1; //문제 출제 부터 점수 체크 시작
			real_q_count++; //총문제 카운트 시작 : 지정된 n back 상자 보다 카운트가 크면 총문제 카운트 시작
		}
		//최신화된 랜덤 숫자 프린트
		printf("exit : q\nRandom : %d\n", n_back_mode_box[n_back_mode]); // 메인 랜덤 숫자
		fprintf(fp, "Random : %d\n", n_back_mode_box[n_back_mode]);		 // 메인 랜덤 숫자(save log)
		//사용자로부터 값을 받음
		scanf(" %c", &my_answer); // 답을 받음
		if (my_answer == 'q')
			break;
		//점수 체크 시작되었다면
		if (ScoreStart){
			 //score check start !
			if (answer == my_answer) //N BACK 정답과 내가 쓴 정답이 같을 경우
				score++;			 // 정답수
		}
		// 내가 쓴 정답을 이전 정답에 대입
		my_prev_answer = my_answer;
		//이전 정답에 현재 정답을 대입
		prev_answer = answer;
	}

	system("clear"); //clear screen
	printf("save log\n");
	fclose(fp); //close file
}
