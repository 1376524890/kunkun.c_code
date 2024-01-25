#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<mmsystem.h>
#pragma comment(lib,"WINMM.LIB")//
#include<time.h>
#pragma warning(disable:4996)

static void SetPos(int x, int y)
{
	COORD point = { x,y };
	HANDLE HOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(HOutput, point);
}

int main()
{
	char vstart = 0;
	char check = 'y';
	printf("进入全屏获得最佳播放效果[y/n]\n");
	scanf("%s", &vstart);
	if (vstart == check)
	{
		FILE* fp;
		char buf[150], add[60], ai[5];
		int i = 1, delay = 33;
		clock_t stime = 0, ftime = 0;

		mciSendString(TEXT("..\\chicken_music.wav alias bkmusic"), NULL, 0, NULL);
		mciSendString(TEXT("play bkmusic"), NULL, 0, NULL);

		stime = clock();

		while (i <= 1772)
		{
			if (i % 30 == 0)
			{
				delay = 43;
			}
			else
			{
				delay = 33;
			}

			strcpy(add,"..\\text\\txt (");
			sprintf(ai, "%d", i);
			strcat(add, ai);
			strcat(add, ").txt");

			ftime = clock();
			if (ftime - stime >= delay)
			{
				fp = fopen(add, "r");

				if (NULL == fp)
				{
					printf("打开错误");

				}
				else
				{
					while (fgets(buf, 150, fp))
					{
						printf("%s", buf);
					}
					fclose(fp);
					SetPos(0, 0);
					i++;
					stime += delay;
				}

			}

		}
	}
	else
	{
		printf("您的输入错误\n");
		return 0;
	}


	return 0;
}