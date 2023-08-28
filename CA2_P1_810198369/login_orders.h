int show_goods(struct goods **goods, int goods_num) {
	if (goods_num == 0) printf("no goods!\n");
	for (int i = 0; i < goods_num; i++) {
		printf("%s\t%d\t%d\t%s\n", goods[i]->goods_name, goods[i]->goods_price, goods[i]->goods_count, goods[i]->seller_name);
	}
}
int view_seller(struct user *account, struct goods** goods, int num) {
	printf("username: %s\n", account->username);
	printf("roll: %s\n", account->role);
	printf("balance account: %d\n", account->balance);
	int a = 0;
	printf("your goods for sell:\n");
	for (int i = 0; i <= num; i++) {
		if (i == num) {
			if (a == 0) printf("you have not any good to sell.\n");
		}
		else if (!strcmp(goods[i]->seller_name, account->username)) {//searching for goods that the current user wants to sell
			printf("%d:name:%s\tprice:%d\tcount:%d\n", a + 1, goods[i]->goods_name, goods[i]->goods_price, goods[i]->goods_count);
			a++;
		}
	}
}
int view_buyer(struct user *buyer, struct goods** bought_goods, int buying_num) {
	printf("username: %s\n", buyer->username);
	printf("roll: buyer\n");
	printf("balance account: %d\n", buyer->balance);
	int a = 0;
	printf("goods that you have bought:\n");
	for (int l = 0; l < buying_num; l++)
		if (!strcmp(bought_goods[l]->buyer_name, buyer->username)) {//searching for goods that the current user has bought
			printf("%d: name:%s\tprice:%d\tcount:%d\tseller:%s\n", a + 1, bought_goods[l]->goods_name, bought_goods[l]->goods_price, bought_goods[l]->goods_count, bought_goods[l]->seller_name);
			a++;
		}
	if (a == 0) printf("you have not bought any goods.\n");
}
struct user* deposit(struct user*buyer) {
	char*charge = (char*)malloc(sizeof(char));
	charge = get_string(charge);
	buyer->balance += atoi(charge);
	printf("deposit was succesful.\n");
}
struct goods* add_goods(struct goods temp, struct goods *new_goods, struct user *account) {
	new_goods->goods_name = temp.goods_name;
	new_goods->goods_price = temp.goods_price;
	new_goods->goods_count = temp.goods_count;
	new_goods->seller_name = account->username;
	printf("your goods added successfully.\n");
	return new_goods;
}
int check_goods(struct goods temp, struct goods **goods, struct user *account, int num) {
	if (temp.goods_count <= 0) {
		printf("this count is invalid.");
		return 0;
	}
	if (temp.goods_price <= 0) {
		printf("this price is invalid.");
		return 0;
	}
	for (int i = 0; i < num; i++) {
		if (!strcmp(temp.goods_name, goods[i]->goods_name)) {
			if (!strcmp(account->username, goods[i]->seller_name)) {
				if (temp.goods_price == goods[i]->goods_price) {
					goods[i]->goods_count += temp.goods_count;
					printf("you have added %d numbers to your goods.\n", temp.goods_count);
					return 0;
				}
				else {
					printf("you have added this good with another price.\n");
					return 0;
				}
			}
			else {
				printf("another seller has added this goods.\n");
				return 0;
			}
		}
	}
	return 1;
}
struct goods* buy(struct goods temp, struct goods *buy, struct goods **goods, struct user *account, struct user **seller, int num, int seller_count) {
	printf("buying was successfully.\n");
	buy->goods_name = temp.goods_name;
	buy->goods_count = temp.goods_count;
	buy->buyer_name = account->username;
	buy->seller_name = temp.seller_name;
	for (int i = 0; i < num; i++)
		if (!strcmp(temp.goods_name, goods[i]->goods_name)) {
			account->balance -= temp.goods_count*goods[i]->goods_price;
			goods[i]->goods_count -= temp.goods_count;
			buy->goods_price = goods[i]->goods_price;
			for (int k = 0; k < seller_count; k++)
				if (!strcmp(seller[k]->username, temp.seller_name))
					seller[k]->balance += temp.goods_count*goods[i]->goods_price;
		}
	return buy;
}
int check_buy(struct goods temp, struct goods**goods, struct goods** bought_goods, struct user *account, struct user**seller, int buying_num, int goods_num, int seller_count) {
	if (temp.goods_count <= 0) {
		printf("this count is invalid.");
		return 0;
	}
	for (int i = 0; i < goods_num; i++) {
		if (!strcmp(temp.goods_name, goods[i]->goods_name)) {
			if (!strcmp(temp.seller_name, goods[i]->seller_name)) {
				if (temp.goods_count <= goods[i]->goods_count) {
					if (temp.goods_count*goods[i]->goods_price <= account->balance) {
						for (int j = 0; j < buying_num; j++) {
							if (!strcmp(temp.goods_name, bought_goods[j]->goods_name)) {//if the current user had bought this goods past.
								if (!strcmp(account->username, bought_goods[j]->buyer_name)) {
									printf("buying was successfully.\n");
									bought_goods[j]->goods_count += temp.goods_count;
									goods[i]->goods_count -= temp.goods_count;
									account->balance -= temp.goods_count*goods[i]->goods_price;
									for (int k = 0; k < seller_count; k++)
										if (!strcmp(seller[k]->username, temp.seller_name))
											seller[k]->balance += temp.goods_count*goods[i]->goods_price;
									return 0;
								}
							}
						}
						return 1;
					}
					else {
						printf("your balance is not enough.\n");
						return 0;
					}
				}
				else {
					printf("there are not enough goods for you.\n");
					return 0;
				}
			}
			else {
				printf("this goods is for %s.\n", goods[i]->seller_name);
				return 0;
			}
		}
	}
	printf("this goods does not exist.\n");
	return 0;
}

