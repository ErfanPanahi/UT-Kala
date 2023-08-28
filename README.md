# UT-Kala
In this repository, I have implemented a virtual buying and selling management system between individuals.

Purchase and Sale Management System:
Managing purchases and sales is one of the essential requirements in businesses, particularly in online businesses. In this project, you will implement a virtual purchase and sale management system among individuals. In this system, there are two types of users:
1) Seller
2) Buyer

Each of these two user types has distinct privileges and behaviors.

Introduction:
As mentioned, specific privileges and behaviors are defined for each type of user, and users will operate within their defined framework. In this project, you should implement user roles, their addition to the system, and relationships among users using the concepts learned in the course. In this phase of the project, you must utilize dynamic memory and the data structure "Struct."

Project Explanation and Desired Features:
In this project phase, you need to implement the following features in a Command Line environment. Note that after successfully executing each of the commands below, an appropriate message should be displayed to the user. In case of an error, an appropriate error message should inform the user.

1) Registering a New User:
Initially, any new user entering the system must register. This feature applies to both seller and buyer roles. To register a new user, the username, password, and role of the user should be entered in the following format. Note that usernames within each role must be unique. It's not allowed to add a user with a similar username and the same role (e.g., two buyers with the same username). If this condition is violated and a duplicate user exists in the system, an appropriate error message should be displayed. It's possible for a username to exist as both a seller and a buyer in the system. Also, note that the items specified in the form below should be separated by spaces, and you cannot use spaces in the username and password fields.

2) Logging into a User Account:
If a user with a specific role has already registered in the system, they can log into their account using the following command. Note that after successful login, an appropriate message should be displayed to the user. In case a user hasn't directly entered the system after registration, they need to log in. Also, if a user doesn't exist with the entered information, an appropriate error message should be displayed.

3) Logging out of a User Account:
To log out of a user account, use the following command format. Note that the program should still be running after executing the logout command, as another user might intend to log into the system.

4) Viewing User Information:
Every user should be able to view their information in the system by entering the "view" command. This information includes:
- Username
- User role
- Account balance (for new users, it will be zero)
- If the user is a buyer:
  - All purchases, including item name, unit price, quantity bought, and seller's name.
- If the user is a seller:
  - The list of items they've put up for sale, including item name, unit price, and quantity available.

5) Adding Credit:
Every buyer user (this feature is not available for seller users) can add credit to their account. For this, they need to specify the desired amount of money using the following format.

6) Adding Items for Sale:
Users registered with the seller role can list their items for sale in the system. For this, they need to enter their username and the details of the item, including item name, unit price, and quantity available.

7) Viewing Available Items:
Every user should be able to view information about all items in the system using the "show_goods" command.

8) Buying Items:
Any user with the buyer role can purchase items using the following command format. Upon a successful purchase, the item should be removed from the system's item list (its quantity should decrease), the buyer's list of purchases should be updated, and the cost of the purchase should be deducted from the buyer's account and transferred to the seller's account.

Please note that if a buyer does not have sufficient balance, an appropriate message should inform them. Also, if an item's quantity reaches zero, it cannot be ordered unless the seller increases its quantity.
