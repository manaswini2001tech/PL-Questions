#include <bits/stdc++.h>
using namespace std;
struct Book{
    char Product[5];
    int Price;
    int SeqNum;
} b[5];

struct Product {
    string id;
    vector<int> prices;
};
Book* Load()
{
   //Storing information
   for(int i=0;i<5;i++)
   {
       cout<<"Enter Product id"<<endl;
       cin>> b[i].Product;
       cout<<"Enter Price"<<endl;
       cin>> b[i].Price;
       b[i].SeqNum = i+1;
       cout<<b[i].SeqNum<<endl;
   }

   return b;
}

void Process(const Book* b)
{
    map<string, Product> products;

for(int i=0;i<5;i++)
{
    // Inserting Product ID from books to a variable
       const string id = b[i].Product;
       if (products.find(id) == products.end())
       {
           // No - need to create a new product...
           Product p;
           p.id = id;

           //... and add it to the map.
           products[id] = p;
       }

       // Add this book's price to the end of the product's prices.
       products[id].prices.push_back(b[i].Price);
       sort(products[id].prices.begin(),products[id].prices.end());
       // Output current prices for this product.
       cout << id.c_str() << " || ";
       for (auto price: products[id].prices)
           cout << " " << price;
       cout <<" ||"<< endl;

}


}

int main()
{
    Book* b = Load();
    Process(b);
    return 0;
}
