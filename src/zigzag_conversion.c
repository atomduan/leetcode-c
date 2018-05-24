/*
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
 * (you may want to display this pattern in a fixed font for better legibility)
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a number of rows:
 * 
 * string convert(string s, int numRows);
 * Example 1:
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * Example 2:
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * 
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 */
#include <linux_config.h>
#include <misc_utils.h>

static int 
compute_line_number(int index, int row_num) 
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
convert(char* s, int numRows) 
{
    int len = 0; 
    int line_index = 0;
    int i = 0;
    char *result = NULL; 
    char *curr = NULL;

    if (numRows == 1) return s;

    len = strlen(s);
    result = malloc(len+1);; 
    curr = result;
    memset(result, 0, len+1);

    for (line_index=0; line_index<numRows; line_index++) {
        for (i = 0; i<len; i++) {
            if (compute_line_number(i, numRows) == line_index) {
                *curr++ = s[i];
            }
        }
    }

    return result;
}

int main(int argc, char **argv) {
    char *s = "PAYPALISHIRING";
    int numRows = 4;
    printf("result is:\n%s\n%s should\n", convert(s, numRows), "PINALSIGYAHRPI");
    return 0;
}
