#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include<iostream>
#include <readline/readline.h>
using namespace std;
void typ_prmpt(){
    static int flag=0;
    if(flag==0){                        //for the first time clean the prompt
        const char* clear_promt = "\e[1;1H\e[2J"; //clears the screen(\e:ANSI escape code)
        write(STDOUT_FILENO,clear_promt,12); // here 12 is size of the message of clear_prompt
        flag = 1;
    }
    printf(">>");                       //displaying prompt
}
char **get_input(char *input) {
    char **command = (char **)malloc(8 * sizeof(char *));
    char *parsed; 
    int index = 0; 
    char separator[] = " "; 

    parsed = strtok(input, separator);

    while (parsed != NULL) {
        command[index] = parsed;
        index++;

        parsed = strtok(NULL, separator);

    }

    command[index] = NULL;

    return command;
}
int cd(char *path) { // function for cd
    return chdir(path);
}
int main(){
    // char cmd[100], command[100], *parameters[20];
    char **command;
    char *input;
    //envir var
    
    int child_status;
    pid_t child_pid;
    // char *env[] = {(char *) "PATH=/bin",0 };
    while(1){                               //infinite loop
        typ_prmpt();   //displaying prompt on the screen   
                
        input = readline(" ");
        command = get_input(input);

        if(!command[0]) {  
              
            free(input);
            free(command);
            continue;
        }

        if(strcmp(command[0],"exit")==0){      // for the command exit we are breaking the loop and ending the program
            break;
        }
        if (strcmp(command[0], "cd") == 0) {
            if (cd(command[1]) < 0) { // handling error
                cout << "error: changing the dir" << endl;
            }
            continue;
        }
    
        child_pid =fork();  
        if(child_pid == 0){ // child process
            execvp(command[0], command);  
            cout << command[0] << " command not found" << endl;       
        }
                                            
        else{ // parent process
           waitpid(child_pid, &child_status, 2); // wait for child process to finish before continuing.  
            // continue;
        }
        // free()
        
    }
    return 0;
}