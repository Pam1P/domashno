Mini Library System – C++ OOP Project
 Описание

Проектът представлява минимална библиотечна система, реализирана на C++ с цел демонстрация на добри обектно-ориентирани практики:

капсулация

const-коректност

статични членове

валидация на данни

списъци за инициализация

прилагане на Rule of 3/5

коректни конструктори/деструктори

Системата включва следните класове: Author, Book, Member, Loan, Library.

 Класове (кратко описание)
Author

Данни: име и година на раждане

Валидиране на диапазона на годината

Методи: to_string(), getters/setter

Book

Данни: заглавие, автор, година, цена, ISBN

Статичен член totalBooks – брои живите книги

Поддръжка на Rule of 5 (copy/move конструктори и оператори)

to_string() и валидиращи setter-и

Member

Данни: име, ID, година на присъединяване

Валидация за празно ID

to_string()

Loan

Данни: ISBN, ID на читателя, дати, статус

Валидация: dueDate >= startDate

Методи: markReturned(), isOverdue(), to_string()

Library

Съдържа вектори от Books, Members и Loans

Поддържа:

добавяне на книга/читател

проверка за наличност

създаване/връщане на заем

търсене по автор


Компилация
g++ -std=gnu++17 -Wall -Wextra -O2 -o library main.cpp Library.cpp Book.cpp Author.cpp Member.cpp Loan.cpp


общо to_string()
