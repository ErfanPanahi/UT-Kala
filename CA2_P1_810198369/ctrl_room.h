int ctrl_room(void) {
	struct user  **seller = (struct user **)malloc(sizeof(struct user*));
	struct user  **buyer = (struct user **)malloc(sizeof(struct user*));
	struct goods **goods = (struct goods **)malloc(sizeof(struct goods*));
	struct goods **bought_goods = (struct goods **)malloc(sizeof(struct goods*));
	struct user temp;//for new user
	struct goods temp_goods;//for new goods
	int seller_count = 0, buyer_count = 0, goods_num = 0, buying_num = 0;//counter of new users and goods
	char*order, *seller_order, *buyer_order;
	for (;;) {
		printf("Enter an order(signup/login-username-password-role)or(exit).\n");
		order = (char*)malloc(sizeof(char));
		order = get_string(order);
		if (!strcmp(order, "exit")) break; //for closing all and finish
		temp = new_user();// information of new account for checking
		if (!strcmp(order, "signup")) {
			if (!strcmp(temp.role, "seller")) {
				if (check_signup(seller, temp, seller_count)) {
					seller = (struct user **)realloc(seller, (seller_count + 1) * sizeof(struct user*));
					seller[seller_count] = (struct user *)malloc(sizeof(struct user));
					seller[seller_count] = signup(temp, seller[seller_count]);
					seller_count++;
				}
			}
			else if (!strcmp(temp.role, "buyer")) {
				if (check_signup(buyer, temp, buyer_count)) {
					buyer = (struct user **)realloc(buyer, (buyer_count + 1) * sizeof(struct user*));
					buyer[buyer_count] = (struct user *)malloc(sizeof(struct user));
					buyer[buyer_count] = signup(temp, buyer[buyer_count]);
					buyer_count++;
				}
			}
			else
				printf("Invalid role.(seller-buyer)\n");
		}
		else if (!strcmp(order, "login")) {
			if (!strcmp(temp.role, "seller")) {
				int seller_num;
				seller_num = check_login(seller, temp, seller_count);
				if (seller_num >= 0) {
					printf("login was successful.\n");
					printf("Enter an order.(show_good-add_goods-view-logout)\n");
					while (1) {
						seller_order = (char*)malloc(sizeof(char));
						seller_order = get_string(seller_order);
						if (!strcmp(seller_order, "logout")) {
							printf("logout was successful.\n");
							break;
						}
						else if (!strcmp(seller_order, "view"))
							view_seller(seller[seller_num], goods, goods_num);
						else if (!strcmp(seller_order, "show_goods"))
							show_goods(goods, goods_num);
						else if (!strcmp(seller_order, "add_goods")) {
							temp_goods = new_goods();
							if (check_goods(temp_goods, goods, seller[seller_num], goods_num)) {
								goods = (struct goods **)realloc(goods, (goods_num + 1) * sizeof(struct goods*));
								goods[goods_num] = (struct goods *)malloc(sizeof(struct goods));
								goods[goods_num] = add_goods(temp_goods, goods[goods_num], seller[seller_num]);
								goods_num++;
							}

						}
						else printf("incorrect role.\n");
					}
				}
			}
			else if (!strcmp(temp.role, "buyer")) {
				int buyer_num;
				buyer_num = check_login(buyer, temp, buyer_count);
				if (buyer_num >= 0) {
					printf("login was successful.\n");
					printf("Enter an order.(show_good-buy-deposit-view-logout)\n");
					while (1) {
						buyer_order = (char*)malloc(sizeof(char));
						buyer_order = get_string(buyer_order);
						if (!strcmp(buyer_order, "logout")) {
							printf("logout was successful.\n");
							break;
						}
						else if (!strcmp(buyer_order, "view"))
							view_buyer(buyer[buyer_num], bought_goods, buying_num);
						else if (!strcmp(buyer_order, "show_goods"))
							show_goods(goods, goods_num);
						else if (!strcmp(buyer_order, "deposit"))
							deposit(buyer[buyer_num]);
						else if (!strcmp(buyer_order, "buy")) {
							temp_goods = new_buy();
							if (check_buy(temp_goods, goods, bought_goods, buyer[buyer_num], seller, buying_num, goods_num, seller_count)) {
								bought_goods = (struct goods **)realloc(bought_goods, (buying_num + 1) * sizeof(struct goods*));
								bought_goods[buying_num] = (struct goods *)malloc(sizeof(struct goods));
								bought_goods[buying_num] = buy(temp_goods, bought_goods[buying_num], goods, buyer[buyer_num], seller, goods_num, seller_count);
								buying_num++;
							}
						}
						else printf("incorrect role.\n");
					}
				}
			}
			else
				printf("Invalid role.(seller-buyer-exit)\n");
		}
		else
			printf("Invalid order.(login-signup)\n");
	}
	for (int i = 0; i < seller_count; i++) free(seller[i]);
	for (int i = 0; i < buyer_count; i++) free(buyer[i]);
	for (int i = 0; i < goods_num; i++) free(goods[i]);
	for (int i = 0; i < buying_num; i++) free(bought_goods[i]);
	free(seller);
	free(buyer);
	free(goods);
	free(bought_goods);
}