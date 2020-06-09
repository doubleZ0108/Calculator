//
//  show_interface.h
//  Console_Calculator
//  
//  Created by double Z on 2020/06/09 .
//  Copyright © 2020 double Z. All rights reserved.
//

#ifndef CONSOLE_CALCULATOR_INTERFACE_H
#define CONSOLE_CALCULATOR_INTERFACE_H

#include <stdio.h>

void clear()
{
    printf("%c[2K", 27);
    printf("\33[2K\r");
//    system("cls");        // only use for windows
}

/**
 * Command not found interface
 **/
void showNotFound()
{
    printf("      ====================================================================\n");
    printf("      #                                                                  #\n");
    printf("      #         *******                       Welcome to                 #\n");
    printf("      #            **                     <Cherry Calculator>            #\n");
    printf("      #        ***  **                                                   #\n");
    printf("      #     ******   **                                                  #\n");
    printf("      #   ******      **                                                 #\n");
    printf("      #   ****      **  **                      Sorry                    #\n");
    printf("      #            **    **            Your command is not found         #\n");
    printf("      #        ******     ****                                           #\n");
    printf("      #      **********  ******                                          #\n");
    printf("      #      **********   ****                                           #\n");
    printf("      #        ******                                                    #\n");
    printf("      #                                                                  #\n");
    printf("      #                                                                  #\n");
    printf("      #                 Input [help] for more information.               #\n");
    printf("      #                                                                  #\n");
    printf("      #                                                                  #\n");
    printf("      #               Powered by 1754060 Zhe Zhang(doubleZ)              #\n");
    printf("      #                        ALL RIGHT REVERSED                        #\n");
    printf("      ====================================================================\n");
    printf("\n\n");
}

/**
 * Exit interface
 **/
void showExit()
{
    printf("      ====================================================================\n");
    printf("      #                                                                  #\n");
    printf("      #         *******                                                  #\n");
    printf("      #            **                                                    #\n");
    printf("      #        ***  **                                                   #\n");
    printf("      #     ******   **                                                  #\n");
    printf("      #   ******      **                  Hope you'll come to            #\n");
    printf("      #   ****      **  **                <Cherry Calculator>            #\n");
    printf("      #            **    **                      again                   #\n");
    printf("      #        ******     ****                                           #\n");
    printf("      #      **********  ******                                          #\n");
    printf("      #      **********   ****                                           #\n");
    printf("      #        ******                                                    #\n");
    printf("      #                                                                  #\n");
    printf("      #                                                                  #\n");
    printf("      #                        Have a nice day :)                        #\n");
    printf("      #                                                                  #\n");
    printf("      #                                                                  #\n");
    printf("      #               Powered by 1754060 Zhe Zhang(doubleZ)              #\n");
    printf("      #                        ALL RIGHT REVERSED                        #\n");
    printf("      ====================================================================\n");
    printf("\n\n");
}

/**
 * Help interface
 **/
void showHelp(){
    clear();
    printf("      ====================================================================\n");
    printf("      #         *******                         Welcome to               #\n");
    printf("      #            **                       Cherry Calculator            #\n");
    printf("      #        ***  **                                                   #\n");
    printf("      #     ******   **                     <COMMAND --- math>           #\n");
    printf("      #   ******      **          Calculate the value of the expression  #\n");
    printf("      #   ****      **  **        and you can do more by adding options. #\n");
    printf("      #            **    **         The operator we support: [+-*/()]    #\n");
    printf("      #        ******     ****                                           #\n");
    printf("      #      **********  ******   [EXAMPLE]                              #\n");
    printf("      #      **********   ****       math -beauty 1 +  2   -3*4          #\n");
    printf("      #        ******                math -rev 3 * ( 7 - 4 ) + 8 / 4     #\n");
    printf("      #                              math 1+2-(3*4)/5                    #\n");
    printf("      #         [OPTION LIST]                                            #\n");
    printf("      #             -beauty [exp] -> beautify the expression             #\n");
    printf("      #             -rev [exp] -> output the reverse polish notation     #\n");
    printf("      #             no option -> just calculate the value                #\n");
    printf("      #                                                                  #\n");
    printf("      #               Powered by 1754060 Zhe Zhang(doubleZ)              #\n");
    printf("      #                        ALL RIGHT REVERSED                        #\n");
    printf("      ====================================================================\n");
}

#endif //CONSOLE_CALCULATOR_INTERFACE_H
