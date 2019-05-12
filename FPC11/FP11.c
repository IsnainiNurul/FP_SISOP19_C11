#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<syslog.h>
#include<pthread.h>
#include<string.h>
#define MAXCHAR 1000
char kal1[100];
char kal2[100];
char kal3[100];
char kal4[100];
char kal5[100];
char kal6[100];
char kal7[100];
char kal8[100];
char kal9[100];
char menits[3];
char jams[3];
char tanggals[3];
char bulans[3];
char haris[3];

pthread_t tid1, tid2;
int status;
int nomor;
  
void* cron(void *arg)
{
  printf("trit berjalan \n ");
  struct tm *infowaktu;
  time_t rawtime;
  time(&rawtime);
  infowaktu = localtime (&rawtime );
  sprintf(menits, "%d", infowaktu->tm_min);
  sprintf(jams, "%d", infowaktu->tm_hour);
  sprintf(tanggals, "%d", infowaktu->tm_mday);
  sprintf(bulans, "%d", infowaktu->tm_mon+1);
  sprintf(haris, "%d", infowaktu->tm_wday);
  printf("%s %s %s %s %s",kal9,kal8,kal7,kal6,kal5);
  if( infowaktu->tm_sec == 0 && ((strcmp(kal9, menits) == 0)|| (strcmp(kal9, "*") == 0)) && ((strcmp(kal8, jams) == 0) || (strcmp(kal8, "*") == 0)) && ((strcmp(kal7, tanggals) == 0) || (strcmp(kal7, "*") == 0)) && ((strcmp(kal6, bulans) == 0) || (strcmp(kal6, "*") == 0)) && ((strcmp(kal5, haris) == 0 || strcmp(kal5, "*") == 0)))
  {
    printf("Sama \n");
    if(fork() == 0)
    {
      char *argv[4] = {kal4,kal3,kal2};
      execv(kal4,argv);  
    }
  }
}

const char *reverse(char kata[])
{
  char temp[100];
  int n = strlen(kata),i=0;
  int k = n;
  while(n--)
  {
    temp[i]=kata[n];
    i++;
  }
    n = strlen(kata);
  while(n--)
  {
    kata[n]=temp[n];
  }
}


int main(void *arg)
{
  pid_t pid, sid;
  pid = fork();
  if (pid < 0) 
  {
    exit(EXIT_FAILURE);
  }
  if (pid > 0) 
  {
    exit(EXIT_SUCCESS);
  }
  umask(0);
  sid = setsid();
  if (sid < 0) 
  {
    exit(EXIT_FAILURE);
  }
  if ((chdir("/")) < 0) 
  {
    exit(EXIT_FAILURE);
  }
  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);
  while(1) 
  {
    struct tm *infowakta;
    time_t rawtime;
    time(&rawtime);
    infowakta = localtime (&rawtime );
    FILE *baca;
    char string[MAXCHAR];
    char* filename = "/home/isnaini/FPC11/crontab.data";
    baca = fopen(filename, "r");
    int var=0;
    int ke=0;
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    int e=0;
    int f=0;
    int g=0;
    int h=0;
    int i=0;
    int count = 0;
    int panjang = (int) strlen(string);
    if (baca == NULL)
    {
        printf("Could not open file %s",filename);
        return 1;
    }
    while (fgets(string, MAXCHAR, baca) != NULL)
    {
    kal1[0]='\0';
    kal2[0]='\0';
    kal3[0]='\0';
    kal4[0]='\0';
    kal5[0]='\0';
    kal6[0]='\0';
    kal7[0]='\0';
    kal8[0]='\0';
    kal9[0]='\0';
    int panjang = (int) strlen(string)-1;   
    while(panjang--)
    {
            if (string[panjang] == ' ')
            {   
                ke=ke+1;
            }
              else
              {
                if(ke==0)
                { 
                  kal1[a]=string[panjang]; 
                  a=a+1;
                  if(string[panjang-1] == ' ')
                  {
                    kal1[a] ='\0';
                  }
               }
               if(ke==1)
               {
                   kal2[b]=string[panjang];
                   b=b+1;
                   if(string[panjang-1] == ' ')
                   {
                    kal2[b] ='\0';
                   }
               }
               if(ke==2)
               {
                   kal3[c]=string[panjang];
                   c=c+1;
                   if(string[panjang-1] == ' ')
                   {
                    kal3[c] ='\0';
                   }
               }
               if(ke==3)
               {
                   kal4[d]=string[panjang];
                   d=d+1;
                   if(string[panjang-1] == ' ')
                   {
                    kal4[d] ='\0';
                   }
               }
               if(ke==4)       
               {
                   kal5[e]=string[panjang];
                   e=e+1;
                   if(string[panjang-1] == ' ')
                   {
                    kal5[e] ='\0';
                   }
               }
               if(ke==5)
              {
                   kal6[f]=string[panjang];
                   f=f+1;
                   if(string[panjang-1] == ' ')
                   {
                    kal6[f] ='\0';
                   }
              }
              if(ke==6)
              {
                   kal7[g]=string[panjang];
                   g=g+1;
                   if(string[panjang-1] == ' ')
                   {
                    kal7[g] ='\0';
                   }
               }
              if(ke==7)
              {
                   kal8[h]=string[panjang];
                   h=h+1;
                   if(string[panjang-1] == ' ')
                   {
                    kal8[h] ='\0';
                   }
                } 
              if(ke==8)
              {  
                   kal9[i]=string[panjang];
                   i=i+1;   
                   if(string[panjang-1] == ' ')
                   {
                    kal9[i] ='\0';
                   }
              }
            } 
    }
    reverse(kal1);
    reverse(kal2);
    reverse(kal3);
    reverse(kal4);
    reverse(kal6);
    reverse(kal7); 
    reverse(kal8);
    reverse(kal9);
    a=0;
    b=0;
    c=0;
    d=0;
    e=0;
    f=0;
    g=0;
    h=0;
    i=0;
    ke=0;   
    pthread_create(&(tid1), NULL, cron, NULL);
    pthread_join(tid1, NULL);
    printf("%d",infowakta->tm_sec);
    }
    fclose(baca);
    sleep(1);
  }
  exit(EXIT_SUCCESS);
}
