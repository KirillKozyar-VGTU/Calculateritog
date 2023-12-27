#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void calculateMaterials(float length, float width, float height) {
    const float cementRatio = 0.02; // ���� �������
    const float sandRatio = 0.04;   // ���� �����
    const float gravelRatio = 0.08; // ���� �����

    const float gravelCto = 119; // ���� �����
    const float sandCto = 158; // ���� �����
    const float cementCto = 200 ; // ���� �������



    float area = length * width;
    float totalVolume = area * height;
    float cement = totalVolume * cementRatio;
    float sand = totalVolume * sandRatio;
    float gravel = totalVolume * gravelRatio;

    float CC = cement * cementCto ; // ������
    float SC = sand * sandCto ; // �����
    float GC = gravel * gravelCto ; // ������
    float OO = CC + SC + GC;// ����� ���� 
    



    printf("\n====================================\n��� �������� ��������� %.2f � x %.2f � x %.2f �:\n", length, width, height);
    printf("���������� �������: %.2f �� �� ���.�\n", cement);
    printf("���������� �����: %.2f �� �� ���.�\n", sand);
    printf("���������� �����: %.2f �� �� ���.�\n", gravel);
    printf("����� ��������� ���� ����������: %.2f ������ \n", OO);

  
    FILE* file = fopen("calculator_results.txt", "a");
    if (file == NULL) {
        printf("������ ��� ���������� ����������� � ����.\n");
        exit(1);
    }
    fprintf(file, "�����: %.2f �, ������: %.2f �, ������: %.2f �\n", length, width, height);
    fprintf(file, "������: %.2f ���.�, �����: %.2f ���.�, ������: %.2f ���.�\n\n", cement, sand, gravel);
    fprintf(file, "����� ��������� ���� ����������: %.2f ������\n\n\n",OO);
    fclose(file);
}

int main() {
    setlocale(LC_CTYPE, "RUS");
    printf("�������: ����� ������ ���������� ������:����-231 ������������ �����������\n");
    printf("\n====================================\n");
    printf("  ����� ���������� � �����������!  \n");
    printf("====================================\n\n");

    char choice;
    do {
        float length, width, height;
        int inputStatus;

        do {
            printf("������� ����� �������� (� ������): ");
            inputStatus = scanf("%f", &length);
            while (getchar() != '\n'); 
            if (inputStatus != 1)
                printf("�������� ����. ����������, ������� �����.\n");
        } while (inputStatus != 1);

        do {
            printf("������� ������ �������� (� ������): ");
            inputStatus = scanf("%f", &width);
            while (getchar() != '\n');
            if (inputStatus != 1)
                printf("�������� ����. ����������, ������� �����.\n");
        } while (inputStatus != 1);

        do {
            printf("������� ������ �������� (� ������): ");
            inputStatus = scanf("%f", &height);
            while (getchar() != '\n'); 
            if (inputStatus != 1)
                printf("�������� ����. ����������, ������� �����.\n");
        } while (inputStatus != 1);

        calculateMaterials(length, width, height);

        printf("\n������ ��������� ��� ���� ������? (y/n): ");
        printf("\n��� ���� ����� ���������� �������: y\n��� ���� ����� ��������� �������: n\n�������:");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("��������� ���������.\n");

    return 0;
    
}