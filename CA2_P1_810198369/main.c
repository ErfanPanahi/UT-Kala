#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "get_string.h"
#include "new_temp.h"
#include "signup.h"
#include "check_login.h"
#include "login_orders.h"
#include "ctrl_room.h"
int main() {
	printf("welcome to buy and sell management system.\n");
	ctrl_room();//the main loop is here
	printf("goodbye!\n");
	return 0;
}
