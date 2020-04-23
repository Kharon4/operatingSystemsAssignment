#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

void typ_prmpt(){
    static int flag=0;
    if(flag==0){                        //for the first time clean the prompt
        const char* clear_promt = "\e[1;1H\e[2J"; //clears the screen(\e:ANSI escape code)
        write(STDOUT_FILENO,clear_promt,12) // here 12 is size of the message of clear_prompt
        flag=1;
    }
    printf(">>");                       //displaying prompt
}
void rd_cmd(char prm[],char *par[] ){
    char line[1024];
    char *arr[100],*parse;
    int count=0,i=0,j=0;
    // reading the line
    for(;;){
        int a = fgetc(stdin);
        line[count++] = (char) a; 
        if(a=="\n"){
            break;
        }
    }
    if(count==1){
        return;
    }
    parse = strtok(line, " \n");
    //parsing the line into words
    while(parse!=NULL){
        arr[i++] = strdup(parse);
        parse = strtok(NULL," \n");
    }
    strcpy(cmd,arr[0]);
    for(j=0;j<i;j++){
        par[j] = arr[j];
        par[i] = NULL;//teminate the list of parameter
    }

}

int main(){
    char cmd[100], command[100], *parameters[20];
    //envir var
    char *env[] = {(char *) "PATH=/bin",0 };
    while(i){                               //infinite loop
        typ_prmpt();                       //displaying prompt on the screen
        rd_cmd(command,parameters);         //
        if(fork()!=0){                      //forking first creats parent with pid for which we have to wait 
            wait(NULL);
        }
                                            //Child process
        else{
            strcpy(cmd,"/bin/");         
            strncat(cmd,command);          //copying
            execv(given,parameters,env);
        }
        if(strcmp(command,"exit")==0){      // for the command exit we are breaking the loop and ending the program
            break;
        }
        if(strcmp(command,"clearscreen")==0){
            typ_prmpt();
        }
    }
    return 0;
}