# Cash Memo

A Cash Memo console application in C is a program designed to handle basic billing and receipt generation tasks typically used in retail or small business settings. This application captures details of purchases, calculates totals, and generates a printable receipt (cash memo) for the customer.

## Guide

### Running the Program

1. **Starting the Application**
   - After running the program, you will see the message **"Give Input"**.

2. **Adding Products**
   - Enter `1` to provide the number of products, followed by the product names and their prices.

3. **Viewing Products**
   - After entering products, when the **"Give Input"** message appears again, enter `2` to see the list of products you have entered.

4. **Deleting a Product**
   - When the **"Give Input"** message appears again, enter `3` if you want to delete a product.
   - You will be prompted with **"Enter serial"**. Enter the serial number of the product you want to delete.
   - The updated cash memo table will be displayed without the deleted item.

5. **Updating a Product**
   - When the **"Give Input"** message appears again, enter `4` to update a product.
   - You will be prompted to enter the new product name, the new product price, and the serial number of the product you want to update.
   - After entering the information, the updated cash memo table will be displayed with the updated product.

6. **Generating the Cash Memo**
   - When the **"Give Input"** message appears again, enter `5` to print the cash memo.
   - You will have two options for discount:
     - Enter `1` to apply a discount. You will be prompted to enter the discount amount, and the cash memo will be printed as a file.
     - Enter `2` if there is no discount. The cash memo will be printed without applying any discount.

### Additional Guides

- If you enter any number other than `1` for the first input, a blank table will be displayed.
- If you provide any input other than the assigned numbers, you will see the message **"No Access"** and be prompted to give the input again.

[Watch the demonstration video](https://user-images.githubusercontent.com/71332807/121227750-bebeba00-c8ad-11eb-9979-d257a7bad339.mp4)
