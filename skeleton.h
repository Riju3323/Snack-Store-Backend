#include<bits/stdc++.h>
using namespace std;

class Food; class Shop;

class Snack{
	int id;
	string name;
	int price;

public:
	Snack(){

	}
	Snack(int u_id, string name,int price){
		id = u_id;
		this->name = name;
		this->price = price;
	}
	string getDisplayName(){
		return name + " : INR: " + to_string(price) + "\n";
	}
	string getShortName(){
		return name.substr(1,2);
	}
	friend class Food;
	friend class Shop;
};

class Food{
	Snack product;
	int quantity;

public:
	Food(){}
	Food(Snack p, int q):product(p), quantity(q){}

	int getItemPrice(){
		return quantity * product.price;
	}
	string getItemInfo(){
		return to_string(quantity) + " x " + product.name + " Rs. " + to_string(quantity * product.price) + "\n";
	}

	friend class Shop;
};	


class Shop{
	unordered_map<int,Food>  items;

public:

	void addProduct(Snack product){
		if(items.count(product.id)==0){
			Food newItem(product,1);
			items[product.id] = newItem;
		}
		else{
			items[product.id].quantity += 1;
		}
	}

	int getTotal(){
		int total = 0;
		for(auto itemPair : items){
			auto item = itemPair.second;
			total += item.getItemPrice();
		}
		return total;

	}

	string viewCart(){
		if(items.empty()){
			return "Shop is empty";	
		}

		string itemizedList;
		int cart_total = getTotal();

		for(auto itemPair : items){
			auto item = itemPair.second;
			itemizedList.append(item.getItemInfo());
		}

		return itemizedList + "\n Total Amount : Rs. " + to_string(cart_total) + '\n';
	}
	bool isEmpty(){
		return items.empty();
	}

};