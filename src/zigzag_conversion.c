/**
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
 * (you may want to display this pattern in a fixed font for better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 * string convert(string s, int numRows);
 * Example 1:
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 *
 * Example 2:
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 *
 * Explanation:
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 */
#include <let_config.h>

static int
compute_line_number(int index,int row_num)
{
    int step = 0;
    int sidx = 0;
    int line = 0;
    step = (row_num - 1) * 2;
    sidx = index % step;
    line = sidx < row_num ? sidx : 2*(row_num-1) - sidx;
    return line;
}

char *
convert(char* s,int numRows)
{
    int len = 0;
    int line_index = 0;
    int i = 0;
    char *result = NULL;
    char *curr = NULL;
    char **dict = NULL;
    char **tmpd = NULL;

    if (numRows == 1) return s;

    len = strlen(s);
    result = malloc(len+1);;
    curr = result;
    memset(result, 0, len+1);

    dict = malloc(sizeof(char *)*numRows);
    for (i=0; i<numRows; i++) {
        dict[i] = malloc(len/numRows + 1);
        memset(dict[i], 0, len/numRows + 1);
    }

    tmpd = malloc(sizeof(char *)*numRows);
    memcpy(tmpd, dict, sizeof(char *)*numRows);

    for (i = 0; i<len; i++) {
        line_index = compute_line_number(i, numRows);
        *tmpd[line_index]++ = s[i];
    }

    for (i=0; i<numRows; i++) {
        for (;*dict[i]!='\0'; dict[i]++) {
            *curr++ = *dict[i];
        }
    }

    return result;
}

int
main(int argc,char **argv)
{
    char *s = "PAYPALISHIRING";
    int numRows = 4;
    printf("result is:\n%s\n%s should\n", convert(s, numRows), "PINALSIGYAHRPI");
    return 0;
}
