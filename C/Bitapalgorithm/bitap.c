    #include <string.h>
    #include <stdlib.h>
    #include <stdio.h>

     


    int bitap_search(const char* text, const char* pattern)

    {

        int m = strlen(pattern);

        long pattern_mask[256];

        /** Initialize the bit array R **/

        long R = ~1;

        if (m == 0)

            return -1;

        if (m > 63)

        {

	    printf("Pattern is too long!\n");
            return -1;

        }

     

        /** Initialize the pattern bitmasks **/

        for (int i = 0; i <= 255; ++i)

            pattern_mask[i] = ~0;

        for (int i = 0; i < m; ++i)

            pattern_mask[pattern[i]] &= ~(1L << i);

        for (int i = 0; i < strlen(text); ++i)

        {

            /** Update the bit array **/

            R |= pattern_mask[text[i]];

            R <<= 1;

            if ((R & (1L << m)) == 0)

     

                return i - m + 1;

        }

        return -1;

    }

    void findPattern(char* t, char* p)

    {

        int pos = bitap_search(t, p);

        if (pos == -1)

		printf("\nNo Match\n");
        else
		printf("\nPattern found at position : %d ",pos);


    }

     

    int main(int argc, char **argv)

    {

     

	    printf("Bitmap Algorithm Test\n");
        
	    printf("Enter Text\n");

        char*  text=malloc(sizeof(char)*CHAR_MAX);

        scanf("%s",text);
	printf("Enter Pattern\n");

      

        char* pattern=malloc(sizeof(char)*CHAR_MAX);

        scanf("%s", pattern);

        findPattern(text, pattern);

    }

