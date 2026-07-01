#include <iostream>
using namespace std;
/*
 * STRINGS VS. CHARACTER ARRAYS
 *
 * Definition:
 * A string is a set of characters used to store names, paragraphs, etc.
 * The primary difference between a character array and a string is that
 * strings are delimited by a null character ('\0'), whereas standard
 * character arrays do not require a null terminator.
 *
 * The Null Terminator (\0):
 * Without the null terminator, functions like printf() or strlen()
 * wouldn't know where the string ends, causing them to read into random
 * memory until they crash or find a random zero.
 *
 * Visualizing the Difference in Memory:
 * - Array of Chars (Not a string): ['H', 'e', 'l', 'l', 'o']      (Size: 5 bytes)
 * - C-Style String:                ['H', 'e', 'l', 'l', 'o', '\0'] (Size: 6 bytes)
 *
 * A Note on Modern Languages:
 * While C-style strings rely on '\0', modern languages (Python, Java, JS)
 * manage strings by storing the explicit length of the string in memory
 * next to the characters, making length checks much faster.
 */
// display string
void display(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        cout << str[i];
        i++;
    }
}
// calculate length of string
int length_of_string(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}
// change string to lower case
char *change_to_lower_case(char *str)
{
    int length_of_str = length_of_string(str);
    char *lower_case_string = new char[length_of_str + 1];
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 65 && str[i] <= 90)
        {
            lower_case_string[i] = str[i] + 32;
        }
        i++;
    }
    lower_case_string[length_of_str] = '\0';
    return lower_case_string;
}
// calculate no. of words.
int no_of_words(char *str)
{
    int i = 0, word = 1;
    while (str[i] != '\0')
    {
        if (str[i] == ' ' && str[i - 1] != ' ')
            word++;
        i++;
    }
    return word;
}
// validate string : if not in range of capital alphabets, lower alphabets and numbers then string is not valid
int is_valid_string(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        // allow uppercase A-Z, lowercase a-z, digits 0-9
        if (!((str[i] >= 'A' && str[i] <= 'Z') ||
              (str[i] >= 'a' && str[i] <= 'z') ||
              (str[i] >= '0' && str[i] <= '9')))
        {
            return 0;
        }
        i++;
    }
    return 1;
}
// reverse string using two index pointer
void reverse_string(char *str)
{
    int j = 0;
    // j pointer points to '\0' element
    for (; str[j] != '\0'; j++)
    {
    }
    j = j - 1;
    for (int i = 0; i < j; i++, j--)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
// comparing two strings
void compare_two_strings(char *str1, char *str2)
{
    int str1_len = length_of_string(str1);
    int str2_len = length_of_string(str2);
    int i = 0, j = 0;
    if (str1_len == str2_len)
    {

        for (; i != '\0' && j != '\0'; i++, j++)
        {
            if (str1[i] != str2[j])
                break;
        }
        if (str1[i] == str2[j])
            cout << str1 << " is same as " << str2 << endl;
        else if (str1[i] < str2[i])
            cout << str1 << " is greater than " << str2 << endl;
        else
            cout << str2 << " is greater than " << str1 << endl;
    }
    else if (str2_len > str1_len)
    {
        cout << str2 << " is greater than " << str1 << endl;
    }
    else
    {
        cout << str1 << " is greater than " << str2 << endl;
    }
}
// check anagram
int anagram(char *str1, char *str2)
{
    int hash[26] = {0};
    int i = 0;
    while (str1[i] != '\0')
    {
        hash[str1[i] - 97]++;
        i++;
    }
    i = 0;
    while (str2[i] != '\0')
    {

        if (hash[str2[i] - 97] > 0)
        {

            hash[str2[i] - 97]--;
        }
        else
        {
            break;
        }
        i++;
    }
    if (str2[i] == '\0')
        return 1;
    else
        return 0;
}
int main()
{
    char arr1[4] = {'J', 'H', 'O', 'N'};       // array of characters
    char arr2[5] = {'J', 'H', 'O', 'N', '\0'}; // array of characters with '\0' also called string
    char arr3[] = "nohi";
    char arr4[] = "jhon";
    string str1 = "JHON"; // string object
    cout << arr1 << endl; // prints "JHON"
    cout << arr2 << endl; // prints "JHON"
    cout << str1 << endl; // prints "JHON"
    cout << anagram(arr3, arr4);
    return 0;
}