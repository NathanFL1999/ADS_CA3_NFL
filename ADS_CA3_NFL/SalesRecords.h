#pragma once

#include<iostream>

using namespace std;

struct SalesRecords
{
public:

	string productName;
	float price;
	int quantity;
	string country;
	string region;
	string currency;
	int orderDateTime;
	int deliveryDate;

	SalesRecords(string productName, float price, int quantity, string country, string region, string currency, int orderDateTime, int deliveryDate)
	{
		this->productName = productName;
		this->price = price;
		this->quantity = quantity;
		this->country = country;
		this->region = region;
		this->currency = currency;
		this->orderDateTime = orderDateTime;
		this->deliveryDate = deliveryDate;
	}	

	  friend ostream& operator<<(ostream& os, const SalesRecords& salesRecords) {
		  os << "Product Name: " << salesRecords.productName;
		  os << "Price: " << salesRecords.price;
		  os << ", quantity: " << salesRecords.quantity;
		  os << ", country: " << salesRecords.country;
		  os << ", region: " << salesRecords.region;
		  os << ", currency: " << salesRecords.currency;
		  os << ", orderDateTime: " << salesRecords.orderDateTime;
		  os << ", deliveryDate: " << salesRecords.deliveryDate;
		  return os;
	  }
};
