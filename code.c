#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct
{
    int sno;
    char name[20];
}even;
typedef struct{char id[10];char pwd[10];}reg;
int valid_id(char a[]);
int valid_pwd(char b[]);
int check(char a[],char b[]);
typedef struct{char id[10];char pwd[10];char name[15];char clg[10];int regno;int year;}user;

int signin();
int signup();
even temp;
int main()
{  
    int num, num2, flag = 0,sign=0,k=0,m=0,i=0;
    char spot[20];
    
    printf("----------------WELCOME TO MITAFEST 2023-------------------------");
    printf("\n\n If you are already registered press 1 for SIGN IN / To SIGN UP press 2:  ");
    scanf("%d",&sign);
    scanf("%c");
    if(sign==2) {k=signup();
                 if(k==1) {
                    m=signin(); 
                    if(m==2) { i=0; printf("\n SIGNIN UNSUCCESSFUL");
                     printf("\n If you wish to continue press 1 : to exit press 2: ");
                     scanf("%d",&i);
                    if(i==1)
                    signin();
                    else exit(0);}}
                else {printf("\n SIGNUP UNSUCCESFUL"); 
                printf("\n If you wish to continue press 1 : to exit press 2: ");
                scanf("%d",&i);
                if(i==1)
                   signup();
                else exit(0);}}
    else if(sign==1) {m=signin(); if(m==2) { i=0; printf("\n SIGNIN UNSUCCESSFUL");
                     printf("\n If you wish to continue press 1 : to exit press 2: ");
                     scanf("%d",&i);
                    if(i==1)
                    signin();
                    else exit(0);}}
    else main();


    printf("\n\nLIST OF EVENTS\n\n");
    printf("\nDAY 1\t\t\t\t03-03-2023(FRIDAY)\n");
    printf("1 - JUST A MINUTE(JAM)\t\t10 AM - 1 PM\n");
    printf("2 - MITASPELL\t\t\t\t3 PM - 5 PM\n");
    printf("\nDAY 2\t\t\t\t04-03-2023(SATURDAY)\n");
    printf("3 - ONCE UPON A TIME, THERE LIVED A GHOST\t\t10 AM - 1 PM\n");
    printf("4 - POP QUIZ\t\t\t\t3 PM - 5 PM\n");
    printf("\nDAY 3\t\t\t\t05-03-2023(SUNDAY)\n");
    printf("5 - TREASURE HUNT\t\t10 AM - 1 PM\n");
    printf("6 - SOLO SINGING\t\t3 PM - 5 PM\n\n");
    int op;
    do{
    int n, i;
    even prog;
    char c;
    FILE * p, *event;
    event = fopen("eventdeets.dat", "r");
    if(event==NULL) 
        printf("no");
    printf("\nEnter an event number to get a description and register if interested: ");
    scanf("%d", &n);
    scanf("%c");

    switch(n)
    {
        case 1:
        {
            p = fopen("JAM.dat", "r");
                while(fscanf(p, "%d %s", &temp.sno, temp.name)!=EOF){
                    if(strcmp(spot, temp.name)==0){
                        printf("\n\nAlready registered for this event\n");
                        flag = 1;
                        break;
                    }
                    //fscanf(p, "%d %s", &temp.sno, temp.name);
                    //printf("%d--%s\n", temp.sno, temp.name);
                }
                fclose(p);
                if(flag == 1){
                    break;
                }
            printf("\n\nA standard Just A Minute; 60 mins of coherent thoughts with proper chronology and remember, no fillers, no repetition and most importantly no deviation. This will be an individual event.");
            printf("\n\nTo register enter Y else N: ");
            scanf("%c", &c);
            if(c=='Y'){

                fseek(event, (n-1)*5, SEEK_SET);
                fscanf(event, "%d%d", &num, &num2);
                //printf("--%d-%d--", num, num2);
                rewind(event);
                ++num2;
                FILE * poop;
                poop = fopen("temp.dat", "w");
                int i, rwr;
                char naur[20];
                for(i=1; i<=6; ++i){
                    if(i!=n){
                        fscanf(event, "%s %d", naur, &rwr);
                        fprintf(poop, "%s %d\n", naur, rwr);
                    }
                    else{
                        fscanf(event, "%s %d", naur, &rwr);
                        fprintf(poop, "101 %d\n",  num2);
                    }
                }
                fclose(poop);
                fclose(event);
                remove("eventdeets.dat");
                rename("temp.dat", "eventdeets.dat");
                //fprintf(event, "%s\t%d\n", spot, ++num);
                p = fopen("JAM.dat", "a");
                fprintf(p, "%-15d %-15s\n", num2, spot);
                fclose(p);
                printf("\n\nREGISTRATION FOR EVENT %d SUCCESSFUL",n);
            }break;
        }
        case 2:
        {
            p = fopen("MITASPELL.dat", "r");
                while(fscanf(p, "%d %s", &temp.sno, temp.name)!=EOF){
                    if(strcmp(spot, temp.name)==0){
                        printf("\n\nAlready registered for this event\n");
                        flag = 1;
                        break;
                    }
                    //fscanf(p, "%d %s", &temp.sno, temp.name);
                    //printf("%d--%s\n", temp.sno, temp.name);
                }
                fclose(p);
                if(flag == 1){
                    break;
                }
            printf("\n\nYou don't have to search,hurry,suggest,argue,hunt or contend.Simply spell out the word as we say it.");
           printf("\n\nTo register enter Y else N: ");
            scanf("%c", &c);
            if(c=='Y'){
                

                /*for(i=0; i<6; ++i){
                    fread(&prog,sizeof(even),1,p);
                    if(prog.sno==n){
                        prog.count++;
                        fseek(p,-sizeof(even),1);
                        fwrite(&prog,sizeof(even),1,p);
                        break;
                    }
                }*/
            //    char line[100]; 
   
    // Iterate through each line in the file 
    /*for (int i = 1; fgets(line, 100, event); i++) { 
        // Check if the current line is the desired line 
        if (i == n) { 
            // Get the current position of the file pointer 
            long pos = ftell(event); 
 
            // Move the file pointer to the position 
            fseek(event, pos, SEEK_SET); 
            break; 
        } 
    } */

               // printf("--%s--", spot);
               fseek(event, (n-1)*5, SEEK_SET);
                fscanf(event, "%d%d", &num, &num2);
              //  printf("--%d-%d--", num, num2);
                rewind(event);
                ++num2;
                FILE * poop;
                poop = fopen("temp.dat", "w");
                int i, rwr;
                char naur[20];
                for(i=1; i<=6; ++i){
                    if(i!=n){
                        fscanf(event, "%s %d", naur, &rwr);
                        fprintf(poop, "%s %d\n", naur, rwr);
                    }
                    else{
                        fscanf(event, "%s %d", naur, &rwr);
                        fprintf(poop, "102 %d\n",  num2);
                    }
                }
                fclose(poop);
                fclose(event);
                remove("eventdeets.dat");
                rename("temp.dat", "eventdeets.dat");
                //fprintf(event, "%s\t%d\n", spot, ++num);
                p = fopen("MITASPELL.dat", "a");
                fprintf(p, "%-15d %-15s\n", num2, spot);
                fclose(p);
                printf("\n\nREGISTRATION FOR EVENT %d SUCCESSFUL",n);
/*
                fseek(event, (n-1)*sizeof(temp), SEEK_SET);
                fscanf(event, "%s%d", spot, &num);
                printf("--%s--", spot);
                rewind(event);
                FILE * poop;
                poop = fopen("temp.dat", "w");
                int i, rwr;
                char naur[20];
                for(i=1; i<=6; ++i){
                    if(i!=n){
                        fscanf(event, "%s %d", naur, &rwr);
                        fprintf(poop, "%s %d\n", naur, rwr);
                    }
                    else{
                        fprintf(poop, "%s %d\n", spot, ++num);
                    }
                }
                fclose(poop);
                fclose(event);
                remove("eventdeets.dat");
                rename("temp.dat", "eventdeets.dat");
                //fprintf(event, "%s\t%d\n", spot, ++num);
                p = fopen("MITASPELL.dat", "a");
                fprintf(p, "%-15d %-15s\n", num, temp.name);
                fclose(p);*/
            }break;
        }
        case 3:
        {
            p = fopen("OUAT.dat", "r");
                while(fscanf(p, "%d %s", &temp.sno, temp.name)!=EOF){
                    if(strcmp(spot, temp.name)==0){
                        printf("\n\nAlready registered for this event\n");
                        flag = 1;
                        break;
                    }
                    //fscanf(p, "%d %s", &temp.sno, temp.name);
                    //printf("%d--%s\n", temp.sno, temp.name);
                }
                fclose(p);
                if(flag == 1){
                    break;
                }
            printf("\n\nThink you can get to the end by weaving a fantastic story,while competing against other storytellers who have the same motive?Give it a go at Once upon a time,there lived a ghost");
            printf("\n\nTo register enter Y else N: ");
            scanf("%c", &c);
            if(c=='Y'){

               /* for(i=0; i<6; ++i){
                    fread(&prog,sizeof(even),1,p);
                    if(prog.sno==n){
                        prog.count++;
                        fseek(p,-sizeof(even),1);
                        fwrite(&prog,sizeof(even),1,p);
                        break;
                    }
                }*/

                 fseek(event, (n-1)*7, SEEK_SET);
                fscanf(event, "%d%d", &num, &num2);
                printf("--%d-%d--", num, num2);
                rewind(event);
                ++num2;
                FILE * poop;
                poop = fopen("temp.dat", "w");
                int i, rwr;
                char naur[20];
                for(i=1; i<=6; ++i){
                    if(i!=n){
                        fscanf(event, "%s %d", naur, &rwr);
                        fprintf(poop, "%s %d\n", naur, rwr);
                    }
                    else{
                        fscanf(event, "%s %d", naur, &rwr);
                        fprintf(poop, "201 %d\n",  num2);
                    }
                }
                fclose(poop);
                fclose(event);
                remove("eventdeets.dat");
                rename("temp.dat", "eventdeets.dat");
                //fprintf(event, "%s\t%d\n", spot, ++num);
                p = fopen("OUAT.dat", "a");
                fprintf(p, "%-15d %-15s\n", num2, spot);
                fclose(p);
                printf("\n\nREGISTRATION FOR EVENT %d SUCCESSFUL",n);

            }break;
        }
        case 4:
        {
            p = fopen("POPQUIZ.dat", "r");
                while(fscanf(p, "%d %s", &temp.sno, temp.name)!=EOF){
                    if(strcmp(spot, temp.name)==0){
                        printf("\n\nalready registered for this event\n");
                        flag = 1;
                        break;
                    }
                    //fscanf(p, "%d %s", &temp.sno, temp.name);
                    //printf("%d--%s\n", temp.sno, temp.name);
                }
                fclose(p);
                if(flag == 1){
                    break;
                }
            printf("\n\nAre you up-to-date with everything that's up today? Movies,Books,Music and more,test how well you know them at the pop-quiz");
            printf("\n\nTo register enter Y else N: ");
            scanf("%c", &c);
            if(c=='Y'){

               /* for(i=0; i<6; ++i){
                    fread(&prog,sizeof(even),1,p);
                    if(prog.sno==n){
                        prog.count++;
                        fseek(p,-sizeof(even),1);
                        fwrite(&prog,sizeof(even),1,p);
                        break;
                    }
                }*/

                fseek(event, (n-1)*7, SEEK_SET);
                fscanf(event, "%d%d", &num, &num2);
                printf("--%d-%d--", num, num2);
                rewind(event);
                ++num2;
                FILE * poop;
                poop = fopen("temp.dat", "w");
                int i, rwr;
                char naur[20];
                for(i=1; i<=6; ++i){
                    if(i!=n){
                        fscanf(event, "%s %d", naur, &rwr);
                        fprintf(poop, "%s %d\n", naur, rwr);
                    }
                    else{
                        fscanf(event, "%s %d", naur, &rwr);
                        fprintf(poop, "202 %d\n",  num2);
                    }
                }
                fclose(poop);
                fclose(event);
                remove("eventdeets.dat");
                rename("temp.dat", "eventdeets.dat");
                //fprintf(event, "%s\t%d\n", spot, ++num);
                p = fopen("POPQUIZ.dat", "a");
                fprintf(p, "%-15d %-15s\n", num2, spot);
                fclose(p);
                printf("\n\nREGISTRATION FOR EVENT %d SUCCESSFUL",n);
            }break;
        }
        case 5:
        {
            p = fopen("TREASUREHUNT.dat", "r");
                while(fscanf(p, "%d %s", &temp.sno, temp.name)!=EOF){
                    if(strcmp(spot, temp.name)==0){
                        printf("\n\nAlready registered for this event\n");
                        flag = 1;
                        break;
                    }
                    //fscanf(p, "%d %s", &temp.sno, temp.name);
                    //printf("%d--%s\n", temp.sno, temp.name);
                }
                fclose(p);
                if(flag == 1){
                    break;
                }
            printf("\n\nFind the treasure with your team before anyone else does.Clear vision holds the key!!!- Maximum 3 team members ");
            printf("\n\nTo register enter Y else N: ");
            scanf("%c", &c);
            if(c=='Y'){
                /*for(i=0; i<6; ++i){
                    fread(&prog,sizeof(even),1,p);
                    if(prog.sno==n){
                        prog.count++;
                        fseek(p,-sizeof(even),1);
                        fwrite(&prog,sizeof(even),1,p);
                        break;
                    }
                }*/

                fseek(event, (n-1)*5, SEEK_SET);
                fscanf(event, "%d%d", &num, &num2);
               // printf("--%d-%d--", num, num2);
                rewind(event);
                ++num2;
                FILE * poop;
                poop = fopen("temp.dat", "w");
                int i, rwr;
                char naur[20];
                for(i=1; i<=6; ++i){
                    if(i!=n){
                        fscanf(event, "%s %d", naur, &rwr);
                        fprintf(poop, "%s %d\n", naur, rwr);
                    }
                    else{
                        fscanf(event, "%s %d", naur, &rwr);
                        fprintf(poop, "301 %d\n",  num2);
                    }
                }
                fclose(poop);
                fclose(event);
                remove("eventdeets.dat");
                rename("temp.dat", "eventdeets.dat");
                //fprintf(event, "%s\t%d\n", spot, ++num);
                p = fopen("TREASUREHUNT.dat", "a");
                fprintf(p, "%-15d %-15s\n", num2, spot);
                fclose(p);
                printf("\n\nREGISTRATION FOR EVENT %d SUCCESSFUL",n);
            }break;

        }
        case 6:
        {
            p = fopen("SOLOSINGING.dat", "r");
                while(fscanf(p, "%d %s", &temp.sno, temp.name)!=EOF){
                    if(strcmp(spot, temp.name)==0){
                        printf("\n\nAlready registered for this event\n");
                        flag = 1;
                        break;
                    }
                    //fscanf(p, "%d %s", &temp.sno, temp.name);
                    //printf("%d--%s\n", temp.sno, temp.name);
                }
                fclose(p);
                if(flag == 1){
                    break;
                }
            printf("\n\nBring out the talented singer in you and get the applause you deserve");
            printf("\n\nTo register enter Y else N: ");
            scanf("%c", &c);
            if(c=='Y'){

               /* for(i=0; i<6; ++i){
                    fread(&prog,sizeof(even),1,p);
                    if(prog.sno==n){
                        prog.count++;
                        fseek(p,-sizeof(even),1);
                        fwrite(&prog,sizeof(even),1,p);
                        break;
                    }
                }*/

                fseek(event, (n-1)*7, SEEK_SET);
                fscanf(event, "%d%d", &num, &num2);
               // printf("--%d-%d--", num, num2);
                rewind(event);
                ++num2;
                FILE * poop;
                poop = fopen("temp.dat", "w");
                int i, rwr;
                char naur[20];
                for(i=1; i<=6; ++i){
                    if(i!=n){
                        fscanf(event, "%s %d", naur, &rwr);
                        fprintf(poop, "%s %d\n", naur, rwr);
                    }
                    else{
                        fscanf(event, "%s %d", naur, &rwr);
                        fprintf(poop, "302 %d\n",  num2);
                    }
                }
                fclose(poop);
                fclose(event);
                remove("eventdeets.dat");
                rename("temp.dat", "eventdeets.dat");
                //fprintf(event, "%s\t%d\n", spot, ++num);
                p = fopen("SOLOSINGING.dat", "a");
                fprintf(p, "%-15d %-15s\n", num2, spot);
                fclose(p);
                printf("\n\nREGISTRATION FOR EVENT %d SUCCESSFUL",n);
            }break;
        }
        default: break;
    }
    
    printf("Enter 1 to continue to register for the events/ 2 to exit: ");
    scanf("%d", &op);
    }while(op==1);
    //fclose(event);
    return 0;
}

int signin()
{ reg check;
  int n=0,i=0;
  char uid[10],pd[10];
  printf("\n Enter your USERID: ");
  gets(uid);
  printf("\n Enter your PASSWORD: ");
  gets(pd);

  FILE*p=fopen("loginfo.dat","r");
  if(p==NULL)
    {
        printf("\n file loginfo could not be opened");
        return 2;
    }
   while(fscanf(p,"%s %s",check.id,check.pwd)!=EOF)
   { if(strcmp(check.id,uid)==0)
    {  
        if(strcmp(check.pwd,pd)!=0)
        {
            printf("\n INCORRECT PASSWORD");
            fclose(p);
            return 2;
        }
        return 1;
        break;}
    }
    printf("\n INVALID USERID");
    return 2;
}
int signup()
{
    int n=0,i=0;
    user temp;

    printf("\n Enter your USERID - the USERID must have 5-9 characters : ");
    scanf("%s",temp.id);
    n=valid_id(temp.id);
    if(n==1)
      {
        printf("\n If you wish to continue press 1 : to exit press 2: ");
        scanf("%d",&i);
        if(i==1)
            signup();
        else exit(0);
      }


    char check_pwd[10];
    printf("\n Enter your PASSWORD - the PASSWORD must have 5-9 characters : ");
    scanf("%s",temp.pwd);
    

    n=0;i=0;
    while(n==0)
    {
    printf("\n Confirm your password: ");
    scanf("%s",check_pwd);
    n=check(check_pwd,temp.pwd);
    }


    n=0;i=0;
    n=valid_pwd(temp.pwd);
    if(n==1)
    {
        printf("\n If you wish to continue press 1 : to exit press 2");
        scanf("%d",&i);
        if(i==1)
            signup();
        else exit(0);
    }


    printf("\n please enter your name: ");
    scanf("\n");
    gets(temp.name);
    printf("\n enter the name of your college: ");
    gets(temp.clg);
    printf("\n enter your regno: ");
    scanf("%d",&temp.regno);
    printf("\n enter your college year: ");
    scanf("%d",&temp.year);
    scanf("%c");

    FILE*log=fopen("loginfo.dat","a");
    if(log==NULL)
    {
        printf("file loginfo could not be opened");
        return 0;
    }
    FILE*info=fopen("userinfo.dat","a");
    if(info==NULL)
    {
        printf("file userinfo could not be opened");
        return 0;
    }

    fprintf(info,"\n %-15s %-15s %-15s %-15d %-15d",temp.id,temp.name,temp.clg,temp.regno,temp.year);
    fprintf(log,"\n %-15s %-15s\n",temp.id,temp.pwd);

    fclose(log);
    fclose(info);
    return 1;
}
int valid_id(char a[])
{
   if(strlen(a)<5||strlen(a)>9)
      {   printf("\n Invalid userid length");
          return 1;
      }
   FILE*p=fopen("loginfo.dat","r");
   if(p==NULL)
    {
        printf("file loginfo could not be opened");
        return 0;
    }
   user regi;
   int i=0;

    while(fscanf(p,"%s %s",regi.id,regi.pwd)!= EOF)
    {
       if(strcmp(regi.id,a)==0)
       {   fclose(p);
           printf("\n Userid already exists");
           return 1;
       }
    }
   fclose(p);
   return 0;
}
int valid_pwd(char b[])
{
    if(strlen(b)<5||strlen(b)>9)
      {   printf("Invalid password length");
          return 1;
      }
   else return 0;
}
int check(char a[],char b[])
{
    if(strcmp(a,b)!=0)
       { printf("\n Passwords do not match");
         return 0;
       }
    else return 1;
}
