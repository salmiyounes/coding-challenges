#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 300

int split (const char *txt, char delim, char ***tokens)
{
    int *tklen, *t, count = 1;
    char **arr, *p = (char *) txt;

    while (*p != '\0') if (*p++ == delim) count += 1;
    t = tklen = calloc (count, sizeof (int));
    for (p = (char *) txt; *p != '\0'; p++) *p == delim ? *t++ : (*t)++;
    *tokens = arr = malloc (count * sizeof (char *));
    t = tklen;
    p = *arr++ = calloc (*(t++) + 1, sizeof (char *));
    while (*txt != '\0')
    {
        if (*txt == delim)
        {
            p = *arr++ = calloc (*(t++) + 1, sizeof (char *));
            txt++;
        }
        else *p++ = *txt++;
    }
    free (tklen);
    return count;
}

int min(const int a, const int b) {
	return a > b ? b:a;
}
int solve(char* data, int* paper, int* slack) {
	int count = 0;
	char **arr= NULL;
	count = split(data, 'x', &arr);
	
	int l = atoi(arr[0]), w = atoi(arr[1]), h = atoi(arr[2]);
	*(slack) += min(l*w, min(h*l, w*h));
	*(paper) += 2 * (l*w + w*h + h*l);
	return 0;

}

int main() {
	char* fname = "input.txt";
	FILE* file = fopen(fname, "r");
	char* line = NULL;
	size_t len = SIZE;
	ssize_t read;

	if (file == NULL) {
		printf ("Error while open %s\n", fname);
		return 1;
	}
	
	int result = 0;
	int slack = 0;
	while ((read = getline(&line, &len, file) != -1)) {
		solve(line, &result, &slack);
	}
	fclose(file);
	if (line) free(line);
	printf ("Part 1: %d\n", result + slack);
	return 0;
}

