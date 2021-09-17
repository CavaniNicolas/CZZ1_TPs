#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "commun.h"
#include "liste.h"
#include "histo.h"

int ERROR = 0;

int main(int argc, char ** argv) {
    list_t list; 
    initList(&list);
    histogram_t h;
    int text = 1;
    char * file = NULL;

    if (argc<2) {
        printf("[HELP] %s file mode\n", argv[0]);
        printf("       where file is a text file containing the data to display\n");
        printf("       where mode belongs to text/graph\n\n");
    } else {
        /* first parameter is file */
        if (strcmp(argv[1], "text")  && strcmp(argv[1], "graph") ) {
            file = argv[1];
            if (argc>=3)
            text = strcmp(argv[2], "graph");  
        } else {
            /* first parameter is text/graph */
            text = strcmp(argv[1], "graph");
            if (argc>=3)
                file=argv[2];
        }

        if (file) {
            fprintf(stderr, "Reading external file not implemented\n\n");
            ERROR = ERROR_FILE;
        } else {

            printf("DEMO MODE -- dummy data");
      
            insert(&list, "un", 20);
            insert(&list, "deux", 10);
            insert(&list, "trois", 20);
            insert(&list, "quatre", 15);
            insert(&list, "cinq", 15);
            insert(&list, "six", 15);
            insert(&list, "sept", 0);
            insert(&list, "huit", 14);
            insert(&list, "neuf", 11);
            insert(&list, "dix", 7);
            displayByKey(list);
            displayByValue(list);
            computeHisto(h,list);

            if (text) {
                displayText(h);
            } else {
                displayGraph(h);
            }

            freeList(&list);
        }
    }

    return ERROR;
}   