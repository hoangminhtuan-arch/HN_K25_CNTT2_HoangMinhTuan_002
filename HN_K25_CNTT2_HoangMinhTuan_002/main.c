#include <stdio.h>

#define MAX_SIZE 50

int main(void){
    int steps[MAX_SIZE] = {4500, 8200, 6000, 3200, 10000};
    int n = 5;
    int choice;
    int loop = 0;
    int value;
    int pos;

    while (loop == 0)
    {
        printf("==============================================\n");
        printf("    CHUONG TRINH QUAN LY BUOC CHAN FITLEFT\n");
        printf("==============================================\n");
        printf("1. Them so buoc chan\n");
        printf("2. Sua so buoc chan\n");
        printf("3. Xoa so buoc chan\n");
        printf("4. tim kiem so buoc chan\n");
        printf("0. Thoat chuong trinh\n");
        printf("==============================================\n");

        printf("Vui long nhap lua chon cua ban(0-4): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("==============================================\n");
            printf("            Them so buoc chan\n");
            printf("==============================================\n");
            printf("Cac phan tu dang co trong mang:");
            for (int i = 0; i < n; i++){
                printf("%d ",steps[i]);
            }
            printf("\n");
            if(n == MAX_SIZE){
                printf("Mang da day, khong the them!\n");
                break;
            }
            printf("Nhap so buoc chan can them: ");
            scanf("%d", &value);
            if(value < 0){
                printf("So buoc chan khong hop le!\n");
                break;
            }

            printf("Nhap vi tri can them(1-%d): ", n + 1);
            scanf("%d", &pos);
            if(pos < 1 || pos > n + 1){
                printf("Vi tri sua khong hop le!");
                break;
            }

            for (int i = n ; i >= pos - 1; i--){
                steps[i] = steps[i - 1];
            }
            n++;
            steps[pos - 1] = value;
            printf("Them thanh cong so buoc chan!\n");
            printf("Mang sau khi them:");
            for (int i = 0; i < n; i++){
                printf("%d ",steps[i]);
            }
            printf("\n");
            break;
        case 2:
            printf("==============================================\n");
            printf("            Sua so buoc chan\n");
            printf("==============================================\n");
            printf("Cac phan tu dang co trong mang:");
            for (int i = 0; i < n; i++){
                printf("%d ",steps[i]);
            }
            printf("\n");
            printf("Nhap vi tri can sua(1-%d): ", n);
            scanf("%d", &pos);
            if(pos < 1 || pos > n + 1){
                printf("Vi tri sua khong hop le!");
                break;
            }

            printf("Nhap gia tri moi: ");
            scanf("%d", &value);
            if(value < 0){
                printf("So buoc chan khong hop le!\n");
                break;
            }
            steps[pos - 1] = value;
            printf("Sua thanh cong!\n");
            printf("Mang sau khi sua:");
            for (int i = 0; i < n; i++){
                printf("%d ",steps[i]);
            }
            printf("\n");
            break;
        case 3:
            printf("==============================================\n");
            printf("            Xoa so buoc chan\n");
            printf("==============================================\n");
            if(n == 0){
                printf("Mang rong, khong the xoa!\n");
                break;
            }
            printf("Cac phan tu dang co trong mang:");
            for (int i = 0; i < n; i++){
                printf("%d ",steps[i]);
            }
            printf("\n");
            printf("Nhap vi tri can xoa(1-%d): ", n);
            scanf("%d", &pos);
            if(pos < 1 || pos > n + 1){
                printf("Vi tri xoa khong hop le!");
                break;
            }

            for (int i = pos -1; i < n -1 ; i++){
                steps[i] = steps[i + 1];
            }
            n--;
            printf("Xoa thanh cong!\n");
            printf("Mang sau khi xoa:");
            for (int i = 0; i < n; i++){
                printf("%d ",steps[i]);
            }
            printf("\n");
            break;
        case 4:
            printf("==============================================\n");
            printf("            Tim kiem so buoc chan\n");
            printf("==============================================\n");
            printf("Cac phan tu dang co trong mang:");
            for (int i = 0; i < n; i++){
                printf("%d ",steps[i]);
            }
            printf("\n");
            int count = 0;
            printf("Nhap gia tri can tim target: ");
            scanf("%d", &value);

            if(value < 0){
                printf("So buoc chan khong hop le(Khong am)!\n");
                break;
            }
            printf("==============================================\n");
            printf("    KET QUA TIM KIEM\n");
            printf("==============================================\n");
            printf("Target= %d \n", value);
            printf("Tim thay tai vi tri:   ");
            for (int i = 0 ; i<n; i++)
            {
                if(steps[i] == value){
                    printf("%d ", i + 1);
                    count++;
                }
            }
            printf("\n");
            if (count == 0){
                printf("Khong tim thay gia tri trong mang!");
            }else{
                printf("Tong so lan xuat hien: %d lan", count);
            }
            printf("\n");
            break;
        case 0:
            printf("==============================================\n");
            printf("Thoat chuong trinh thanh cong!\n");
            printf("==============================================\n");
            loop = 1;
            break;
        default:
            printf("Lua chon khong hop le");
            break;
        }
    }
    
}