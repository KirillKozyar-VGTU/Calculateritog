#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void calculateMaterials(float length, float width, float height) {
    const float cementRatio = 0.02; // Доля цемента
    const float sandRatio = 0.04;   // Доля песка
    const float gravelRatio = 0.08; // Доля щебня

    const float gravelCto = 119; // цена щебня
    const float sandCto = 158; // цена песка
    const float cementCto = 200 ; // цена цемента



    float area = length * width;
    float totalVolume = area * height;
    float cement = totalVolume * cementRatio;
    float sand = totalVolume * sandRatio;
    float gravel = totalVolume * gravelRatio;

    float CC = cement * cementCto ; // цемент
    float SC = sand * sandCto ; // песок
    float GC = gravel * gravelCto ; // щебень
    float OO = CC + SC + GC;// общая цена 
    



    printf("\n====================================\nДля площадки размерами %.2f м x %.2f м x %.2f м:\n", length, width, height);
    printf("Необходимо цемента: %.2f кг на куб.м\n", cement);
    printf("Необходимо песка: %.2f кг на куб.м\n", sand);
    printf("Необходимо щебня: %.2f кг на куб.м\n", gravel);
    printf("Общая стоимость всех материалов: %.2f рублей \n", OO);

  
    FILE* file = fopen("calculator_results.txt", "a");
    if (file == NULL) {
        printf("Ошибка при сохранении результатов в файл.\n");
        exit(1);
    }
    fprintf(file, "Длина: %.2f м, Ширина: %.2f м, Высота: %.2f м\n", length, width, height);
    fprintf(file, "Цемент: %.2f куб.м, Песок: %.2f куб.м, Щебень: %.2f куб.м\n\n", cement, sand, gravel);
    fprintf(file, "Общая стоимость всех материалов: %.2f рублей\n\n\n",OO);
    fclose(file);
}

int main() {
    setlocale(LC_CTYPE, "RUS");
    printf("Студент: Козяр Кирилл Максимович Группа:бИСТ-231 Строительный калькулятор\n");
    printf("\n====================================\n");
    printf("  Добро пожаловать в калькулятор!  \n");
    printf("====================================\n\n");

    char choice;
    do {
        float length, width, height;
        int inputStatus;

        do {
            printf("Введите длину площадки (в метрах): ");
            inputStatus = scanf("%f", &length);
            while (getchar() != '\n'); 
            if (inputStatus != 1)
                printf("Неверный ввод. Пожалуйста, введите число.\n");
        } while (inputStatus != 1);

        do {
            printf("Введите ширину площадки (в метрах): ");
            inputStatus = scanf("%f", &width);
            while (getchar() != '\n');
            if (inputStatus != 1)
                printf("Неверный ввод. Пожалуйста, введите число.\n");
        } while (inputStatus != 1);

        do {
            printf("Введите высоту площадки (в метрах): ");
            inputStatus = scanf("%f", &height);
            while (getchar() != '\n'); 
            if (inputStatus != 1)
                printf("Неверный ввод. Пожалуйста, введите число.\n");
        } while (inputStatus != 1);

        calculateMaterials(length, width, height);

        printf("\nХотите выполнить еще один расчет? (y/n): ");
        printf("\nДля того чтобы продолжить введите: y\nДля того чтобы завершить введите: n\nВведите:");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Программа завершена.\n");

    return 0;
    
}