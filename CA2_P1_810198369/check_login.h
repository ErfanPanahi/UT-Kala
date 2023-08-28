int check_login(struct user **account, struct user temp, int num) {
	for (int j = 0; j < num; j++) {
		if (!strcmp(temp.username, account[j]->username))
			if (!strcmp(temp.password, account[j]->password))
				return j;
			else {
				printf("incorrect password.\n");
				return -1;
			}
	}
	printf("you must signup with this username at first.\n");
	return -1;
}