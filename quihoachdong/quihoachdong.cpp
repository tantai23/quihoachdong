#include <stdio.h>
#include <stdlib.h> // Để sử dụng malloc và free

// Hàm trả về giá trị lớn nhất có thể đạt được
int unboundedKnapsack(int W, int n, int weight[], int value[]) {
    // Cấp phát động cho mảng dp
    int* dp = (int*)malloc((W + 1) * sizeof(int));
    if (dp == NULL) {
        printf("khong the cap phat bo nho cho mang.\n");
        return -1; // Trả về giá trị lỗi
    }

    // Khởi tạo mảng dp với giá trị 0
    for (int i = 0; i <= W; i++) {
        dp[i] = 0;
    }

    // Tính giá trị lớn nhất cho mỗi trọng lượng từ 1 đến W
    for (int i = 1; i <= W; i++) {
        for (int j = 0; j < n; j++) {
            if (weight[j] <= i) {
                dp[i] = (dp[i] > dp[i - weight[j]] + value[j]) ? dp[i] : dp[i - weight[j]] + value[j];
            }
        }
    }

    int result = dp[W]; // Lưu kết quả trước khi giải phóng bộ nhớ

    // Giải phóng bộ nhớ cho mảng dp
    free(dp);

    return result;
}

int main() {
    int n, W;

    // Nhập số lượng loại đồ vật và trọng lượng tối đa của ba lô
    printf("nhap so luogn do vat: ");
    scanf("%d", &n);
    printf("nhap trong luong toi da cua balo: ");
    scanf("%d", &W);

    // Cấp phát động cho mảng weight và value
    int* weight = (int*)malloc(n * sizeof(int));
    int* value = (int*)malloc(n * sizeof(int));

    // Kiểm tra xem cấp phát động có thành công hay không
    if (weight == NULL || value == NULL) {
        printf("khong the cap phat bo nho.\n");
        return 1;
    }

    // Nhập trọng lượng và giá trị của từng loại đồ vật
    for (int i = 0; i < n; i++) {
        printf("nhap trong luong cua do vat thu %d: ", i + 1);
        scanf("%d", &weight[i]);
        printf("nhap gia tri cua do vat thu %d: ", i + 1);
        scanf("%d", &value[i]);
    }

    // Gọi hàm và in kết quả
    int result = unboundedKnapsack(W, n, weight, value);
    if (result != -1) {
        printf("gia tri lon nhat co the dat duoc: %d\n", result);
    }

    // Giải phóng bộ nhớ
    free(weight);
    free(value);

    return 0;
}
