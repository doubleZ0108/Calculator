//
//  main.c
//  Console_Calculator
//  
//  Created by double Z on 2020/06/09 .
//  Copyright © 2020 double Z. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "interface.h"
#include "calculator.h"

int main(){
    char command[128];      // user input - command
    char option[100];       // option that command carry by

    clear();

    while (1)   // loop the command input
    {
        printf("master@cherry-calculator: $ ");

        memset(option, 0, sizeof(option));

        scanf("%[^\n]", command);
        getchar();
        mystrncpy(option, command, 4);

        if (!strcmp(option, "math"))        // math [option] command
        {
            if (strlen(command) > 5) {
                mathMain(command + 5);
            }
            else {
                char* str = "NULL";
                mathMain(str);
            }

            continue;
        }
        else if (!strcmp(option, "help"))   // help command
        {
            clear();
            showHelp();
        }
        else if (!strcmp(command, ""))      // empty command
        {
            continue;
        }
        else if (!strcmp(command, "exit"))  // exit command
        {
            break;
        }
        else
        {
            clear();
            showNotFound();
        }
    }

    showExit();

    return 0;
}