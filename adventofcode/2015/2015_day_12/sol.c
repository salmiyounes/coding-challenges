# include <stdio.h>
# include <cjson/cJSON.h>



void parse_data(FILE *file) {
	char buf   = (char *) malloc(sizeof(char) * 1024);
	int length = fread(buf, 1, sizeof(buf), file);
	fclose(file);
	cJSON *json = cJSON_Parse(buffer);
	if (json == NULL) {
		const char *error_ptr = cJSON_GetErrorPtr();
		if (error_ptr != NULL) {
			printf ("Error: %s\n", error_ptr);
		}
		cJSON_Delete(json);
		return 1;
	}


	cJSON *name =  cJSON_GetObjectItemCaseSensitive(json, "name");
	if (cJSON_IsString(name) && (name->valuestring != NULL)) {
		printf ("Name: %s\n", name->valuestring);
	} 
	cJSON_Delete(json);
	return 0;
}

int int main()
{
	FILE *file = fopen("input.txt", "r");
	parse_data(file);
	/* code */
	return 0;
}