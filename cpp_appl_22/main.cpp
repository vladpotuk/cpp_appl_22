#include <iostream>
#include<Windows.h>


int findMax(int* array, int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}


int findMin(int* array, int size) {
    int min = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}


double findAvg(int* array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return static_cast<double>(sum) / size;
}


int Action(int* A, int* B, int size, int (*func)(int*, int)) {
    return func(A, size);
}


double Action(int* A, int* B, int size, double (*func)(int*, int)) {
    return func(A, size);
}

int main() {
    system("chcp 1251");
    system("cls");
    int size;
    std::cout << "������ ����� ������: ";
    std::cin >> size;

    int A[100], B[100];

    std::cout << "������ �������� ������ A:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "A[" << i << "]: ";
        std::cin >> A[i];
    }

    std::cout << "������ �������� ������ B:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "B[" << i << "]: ";
        std::cin >> B[i];
    }

    int choice;
    std::cout << "������ ��������:" << std::endl;
    std::cout << "1. ������ ��������" << std::endl;
    std::cout << "2. ������ �����" << std::endl;
    std::cout << "3. ������ ������" << std::endl;
    std::cin >> choice;

    if (choice < 1 || choice > 3) {
        std::cout << "������������ ���� ��������." << std::endl;
        return 1;
    }

    if (choice == 1) {
        int result = Action(A, B, size, findMax);
        std::cout << "��������: " << result << std::endl;
    }
    else if (choice == 2) {
        int result = Action(A, B, size, findMin);
        std::cout << "̳����: " << result << std::endl;
    }
    else if (choice == 3) {
        double avg = Action(A, B, size, findAvg);
        std::cout << "������: " << avg << std::endl;
    }

    return 0;
}
