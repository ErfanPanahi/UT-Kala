struct user new_user(void) {
	struct user temp;
	char*name = (char*)malloc(sizeof(char));
	char*pass = (char*)malloc(sizeof(char));
	char*role = (char*)malloc(sizeof(char));
	name = get_string(name);
	pass = get_string(pass);
	role = get_string(role);
	temp.username = name;
	temp.password = pass;
	temp.role = role;
	return temp;
}
struct goods new_goods(void) {
	char *name = (char*)malloc(sizeof(char));
	char *price = (char*)malloc(sizeof(char));
	char *count = (char*)malloc(sizeof(char));
	name = get_string(name);
	price = get_string(price);
	count = get_string(count);
	struct goods temp;
	temp.goods_name = name;
	temp.goods_price = atoi(price);
	temp.goods_count = atoi(count);
	return temp;
}
struct goods new_buy(void) {
	char *name = (char*)malloc(sizeof(char));
	char *count = (char*)malloc(sizeof(char));
	char *seller = (char*)malloc(sizeof(char));
	name = get_string(name);
	count = get_string(count);
	seller = get_string(seller);
	struct goods temp;
	temp.goods_name = name;
	temp.goods_count = atoi(count);
	temp.seller_name = seller;
	return temp;
}