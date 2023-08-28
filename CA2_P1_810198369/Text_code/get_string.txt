char* get_string(char *);
char* get_string(char *str) {
	char ch;
	int j;
	for (j = 0;; j++) {
		scanf("%c", &ch);
		if (ch == ' ' || ch == '\n') {
			break;
		}
		str = (char*)realloc(str, (j + 2));
		*(str + j) = ch;
	}
	*(str + j) = NULL;
	fflush(stdin);
	return str;
}