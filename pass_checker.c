//Система аутентификации с проверкой паролем

//Подключаемые библиотеки
#include <stdio.h>
#include <string.h>

// Константы для нашей программы
#define PASS_SIZE 100
#define PASSWORD "STRONGpassword"

int compare(char* str_1, char* str_2) {
    for (int i = 0; i < PASS_SIZE; ++i) {
        if (str_1[i] != str_2[i]) {
            return i + 1;
        }
    }

    return 0;
}

int main() {
    int count = 0; // счетчик попыток
    char password[] = PASSWORD; //
    char buff[PASS_SIZE];  // Буфер для пароля, вводимого системой 
    
    // Цикл аутентификации
    for (;; ++count) {
        printf("Enter password: ");

        // Считываем пароль с клавиатуры
        fgets(&buff[0], PASS_SIZE, stdin);

        // Сверяем введеный и оригинальный пароль
        if (compare(buff, password)) {
            printf("Wrong password\n"); // Сообщаем об ошибке
        } else {
            break; // Выход из цикла
        }

        // Выходим при трех неудачных попытках
        if (count == 2) {
            return -1;
        }
    }

    printf("Password OK. Welcome to the club, buddy!");
    return 0;
}
