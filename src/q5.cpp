/*
 * 替换空格
 * @Author: garryfang 
 * @Date: 2019-08-31 11:17:35 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-08-31 11:55:45
 */

void replaceBlank(char string[], int length)
{
    if (!string || length <= 0)
        return;
    int origin_string_length(0), new_string_length(0);
    for (size_t i = 0; string[i] != '\0'; ++i)
    {
        if (string[i] == ' ')
            new_string_length += 3;
        else
            ++new_string_length;
        ++origin_string_length;
    }
    ++origin_string_length; // 末尾的'\0'
    ++new_string_length;

    if (new_string_length > length)
        return;

    int i(origin_string_length - 1), j(new_string_length - 1);
    while (i >= 0 && i < j)
    {
        if (string[i] == ' ')
        {
            string[j--] = '0';
            string[j--] = '2';
            string[j--] = '%';
        }
        else
            string[j--] = string[i];
        --i;
    }
}