#include<bits/stdc++.h>
#include "skeleton.h"
using namespace std;

vector<Snack> FoodItems = {
	Snack(1,"(bu)rger",100),
	Snack(2,"(pi)zza",200),
	Snack(3,"(fr)ench Fries",40),
	Snack(4,"(nu)ggets",120),
	Snack(5,"(pa)sta",180),
	Snack(6,"(mo)mos",180),
  Snack(7,"(ic)e Cream",100),
  Snack(8,"(sp)ring Roll",140),
  Snack(9,"(co)okie",60)
};

Snack* chooseProduct(){

	string productList;
	cout<<"Available Food: "<<"\n";
  cout<<"Type letters in bracket to order "<<"\n";

	for(auto product : FoodItems){
		productList.append(product.getDisplayName());
	}
	cout << productList <<"\n";

	cout<<"-*-*-*-*-*-*-*-*-*-"<<"\n";
	string choice;
	cin>>choice;

	for(int i=0; i< FoodItems.size(); i++){
		if(FoodItems[i].getShortName()==choice){
			return &FoodItems[i];
		}
	}
	cout<<"Food not in our menu!" <<"\n";
	return NULL;
}

bool finalorder(Shop &foodcounter){
	if(foodcounter.isEmpty()){
		return false;
	}

	int total = foodcounter.getTotal();

  string addon;
  cout<<"Would like a Cola to go with your meal? Price: INR 40"<<"\n";
  cout<<"Press (y)es or (n)o "<<"\n";
  cin>> addon; 
  if(addon == "y")
  {
    total = total + 40;
    cout<<"Cola has been added to your food counter."<<"\n";
  }
  cout<<"Would you like to donate INR 10 for you Children Hospital Charity"<<"\n";
  cout<<"Press (y)es or (n)o "<<"\n";
  cin>> addon;
  if(addon == "y")
  {
    total = total + 10;
    cout<<"Thank you for your donation."<<"\n";
  }
  cout<<"Your updated total is: "<<total<<"\n";
	cout<<"Cash Payment ->  ";
	int payment;
	cin>> payment;

	if(payment>=total){
		cout<<"Change " <<payment - total << "\n";
		cout<<"Here's your order! Enjoy Your Meal";
		return true;
	}

	else{
		cout<<"Payment is not sufficient!"<<"\n";
    cout<<"Order Cancelled"<<"\n";
		return false;
	}

}

int main(){

	char action;
	Shop foodcounter;
  cout<<" Welcome to XYZ Snacks "<<"\n\n";
	while(true){
		cout<<"Select an action -  (o)rder food, (v)iew foodcounter, (f)inalise" <<"\n";
		cin>> action;

		if(action=='o'){
			Snack * product = chooseProduct();
			if(product!=NULL){
				cout<<"Added to your Food Counter: "<<product->getDisplayName() <<"\n";
				foodcounter.addProduct(*product);
			}

		}
		else if(action=='v'){
			cout<<"-*-*-*-*-*-*-*-*-*-" <<"\n";
			cout << foodcounter.viewCart()<<"\n";
			cout<<"-*-*-*-*-*-*-*-*-*-"<<"\n";
		}
		else{
			foodcounter.viewCart();
			if(finalorder(foodcounter)){
				break;
			}
		}
	}

	return 0;
}