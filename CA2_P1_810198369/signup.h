struct user* signup(struct user temp, struct user *account) {
	printf("signup was successful.\n");
	account->username = temp.username;
	account->password = temp.password;
	account->role = temp.role;
	account->balance = 0;
	return account;
}
int check_signup(struct user **account, struct user temp, int num) {
	for (int j = 0; j < num; j++)
		if (!strcmp(temp.username, account[j]->username)) {//if the user is repeated return 0;
			printf("This username has already been used.\n");
			return 0;
		}
	return 1;
}