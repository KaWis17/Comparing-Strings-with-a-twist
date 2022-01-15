#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool match(char* wzorzec, char* lancuch);

int main()
{
    char wzorzec[] = "a??a";
    char lancuch[] = "abba";

    printf(match(wzorzec, lancuch)? "PRAWDA\n":"FALSZ\n");

    return 0;
}

bool match(char* wzorzec, char* lancuch)
{
    printf("%s\n%s\n\n\n", wzorzec, lancuch);                       //PRINTING ARRAYS
    if (wzorzec[0] == '\0' && lancuch[0] == '\0') return true;      //END OF ARRAYS
    else if(wzorzec[0] == lancuch[0] || wzorzec[0] == '?'){         //VALUES CORRECT OR ?
        match(wzorzec+1, lancuch+1);
    }
    else if(wzorzec[0] == '*'){                                     //* APPEARS
        int elements_wzorzec = 0, elements_lancuch = 0, number_of_stars = 0;
        while(wzorzec[elements_wzorzec] != '\0') elements_wzorzec++;
        for(int i=0; i<elements_wzorzec; i++) if(wzorzec[i]=='*') number_of_stars++;
        while(lancuch[elements_lancuch] != '\0') elements_lancuch++;
        for(int k=elements_lancuch-number_of_stars; k>=0; k--){
            if(match(wzorzec+1, lancuch+k)) return true;
        }
        return false;
    }
    else return false;                                              //INCORRECT VALUES
}
