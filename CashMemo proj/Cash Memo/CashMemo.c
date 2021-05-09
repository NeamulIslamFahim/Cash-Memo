#include<stdio.h>
#include<string.h>
#include<time.h>
#define size 1000

//Its a menu bar of the cash memo
void Menu() {
    printf("\n");
    printf("\t******************************************************************************\n");
    printf("\t*                        Cash Memo\n\t*\n");
    printf("\t*    1) Take number of products and Input product name and product price.\n");
    printf("\t*    2) Display the product name and product price.\n");
    printf("\t*    3) Delete the unwanted product and display.\n");
    printf("\t*    4) Update product and display.\n");
    printf("\t*    5) Print the Cash Memo.\n\t*\n");
    printf("\t******************************************************************************\n");
}
//The product details (name and price)
struct product_details{

    char product_name[size];
    double product_price;
};
//Inputting the name and price of the product and also the size.
void Input_Product(struct product_details p[], int m) {


    printf("Enter product name and product price: \n");
    for(int i=1; i<=m; i++) {
        gets(p[i].product_name);
        scanf("%lf", &p[i].product_price);
        getchar();
    }
    printf("\n");
}
//Displaying the products that have been selected and also the prices
void display(struct product_details p[], int m) {

    double sum=0;

    printf("\t=========================================\n");
     printf("\t             Cash Memo\n\n");
    printf("\tSL\tProduct Name\tProduct Price\n");
        for(int i=1; i<=m; i++) {
            printf("\t%d.\t%s\t\tTK.%.2lf\n",i,p[i].product_name, p[i].product_price);

            sum = sum+p[i].product_price;
        }
    printf("\t============================================\n");
    printf("\tTotal:\t\t\tTK.%.2lf\n", sum);
    printf("\n\n");
}
//Deleting any of the product along with the price using the index/serial number.
void Delete_product(struct product_details p[], int m) {

    printf("Enter Serial Number: ");
    int index;
    scanf("%d",&index);

    for(int i=index; i<=m; i++) {
        p[i] = p[i+1];
    }
    m--;

    display(p, m);
}
//Updating the product and the price
void Update_prod(struct product_details p[], int m) {

    char name[100];
    printf("Enter name of the new product: ");
    gets(name);

    double price;
    printf("Enter price of the new product: ");
    scanf("%lf", &price);

    int pos,i;
    printf("Enter serial number you want to update: ");
    scanf("%d", &pos);

    for(int i = m-1; i>=pos; i--) {

        p[i+1] = p[i];
    }
    p[pos].product_price = price;
    strcpy(p[pos].product_name, name);

    display(p,m);
}
//The Printing CashMemo in a file
void CashMemo(struct product_details p[], int m) {

    FILE *file;
    file = fopen("Cash Memo.txt", "w");
    time_t ct;
    time(&ct);


    if(file==NULL) {
        printf("File not exists\n");
    }

    else {
        double sum=0, result, result2, result3, result4;
        int x, y, i;

    fprintf(file,"=========================================\n");
     fprintf(file,"\t\tCash Memo\n");
     fprintf(file,"\t  %s\n",ctime(&ct));
    fprintf(file,"SL\tProduct Name\tProduct Price\n");
        for(i=1; i<=m; i++) {
            fprintf(file,"%d.\t%s\t\tTK.%.2lf\n",i,p[i].product_name, p[i].product_price);

            sum = sum+p[i].product_price;
        }
    fprintf(file,"============================================\n");
    fprintf(file,"Total:\t\t\tTK.%.2lf\n", sum);
    //Percentage of offer or discount
    printf("Enter percentage of discount/offer: ");
    scanf("%d",&y);

    result = y/100.00;
    result2 = sum-(result*sum);
    result3 = result2*0.1;
    result4 = result3+result2;

    fprintf(file,"Discount:\t\t\t%d%\n", y);
    fprintf(file,"Total payment:\t\tTK.%.2lf\n", result2);
    fprintf(file,"Vat(10%%):\t\t\tTK.%.2lf\n", result4);
    printf("Cash Memo is out\n\n");
    }
    fclose(file);
}

//----------------Main Function----------------//
int main(void) {

    struct product_details p[100];
    int n, m, i;

    Menu();

    while(1) {

    printf("Give input: ");
    scanf("%d", &n);
    getchar();

    switch(n) {

        case 1: {
            printf("\n");
            printf("Take number of product: ");
            scanf("%d", &m);
            getchar();
            Input_Product(p,m);
            break;
         }
        case 2: {

            display(p,m);
            break;
          }
        case 3: {

            Delete_product(p,m);
            break;
          }
        case 4: {

            Update_prod(p,m);
            break;
        }
        case 5: {

            CashMemo(p,m);
            if("Cash memo is out") {
                exit(0);
            }
            break;

          }
        default: {
            printf("No access\n");
        }
       }
     }
}

