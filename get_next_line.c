#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t i;

    i = -1;
    if (size)
    {
        while ((++i) + 1 < size && src[i])
            dst[i] = src[i];
        dst[i] = '\0';
    }
    return (strlen(src));
}

char *ft_strchr(char *s, int c)
{
    int i;

    i = 0;
    if (!s)
        return (0);
    if (c == '\0')
        return ((char *)&s[strlen(s)]);
    while (s[i] != '\0')
    {
        if (s[i] == (char)c)
            return ((char *)&s[i]);
        i++;
    }
    return (0);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    int len;
    char *str;
    int i;
    int j;

    if (!s1 || !s2)
        return (0);
    len = strlen(s1) + strlen(s2);
    str = malloc(sizeof(char) * len + 1);
    if (!str)
        return (0);
    i = 0;
    j = 0;
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        str[i] = s2[j];
        i++;
        j++;
    }
    str[i] = '\0';
    return (str);
}

char *new_file_reader(int fd, char *str)
{
    char *tmp;
    int bytes;

    tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!tmp)
        return (NULL);
    bytes = 1;
        bytes = read(fd, tmp, BUFFER_SIZE);
        if (bytes == -1)
        {
            free(tmp);
            return (NULL);
        }
        tmp[bytes] = '\0';
        str = ft_strjoin(str, tmp);
    free(tmp);
    return (str);
}

void get_next_line(int fd)
{
    static  char *str;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return ;
    printf("%s\n", new_file_reader(fd, str));
}

int main()
{
    
    int fd = open("example.txt", O_RDONLY);
    get_next_line(fd);
    return (0);
}