#include <iostream>
#include <string>
#include <vector>


struct Book {
    int id;
    std::string title;
    std::string author;
    int year;
};

//hàm thêm sách
void addBook(std::vector<Book>& books){

    Book temp;
 
    //nhập dữ liệu
    std::cout << "Enter id: ";
    std::cin >> temp.id;
    std::cin.ignore();

    std::cout << "Enter title: ";
    getline(std::cin, temp.title);

    std::cout << "Enter author: ";
    getline(std::cin, temp.author);

    std::cout << "Enter year: ";
    std::cin >> temp.year;
    std::cin.ignore();

    books.push_back(temp);

    std::cout << "\n Nhập thành công!" << std::endl;
}

//hàm hiển thị
void displayBook(const std::vector<Book>& books){
    if(books.empty()){
        std::cout << "Không có sách!" << std::endl;
        return;
    }
    Book temp;
    std::cout << "\n====Library Manager====" << std::endl;
    //xuất dữ liệu

    for(int i = 0; i < books.size(); i++){
    std::cout << "BOOK" << i + 1 << std::endl;
    std::cout << "ID: " << books[i].id << std::endl;
    std::cout << "Title: " << books[i].title << std::endl;
    std::cout << "Author: " << books[i].author << std::endl; 
    std::cout << "Year: " << books[i].year << std::endl;
    std::cout << std::endl;
    }
}
//hàm tìm sách
void findBookbyId(const std::vector<Book>& books){

    int targetId;

    std::cout << "Hãy nhập id sách: ";
    std::cin >> targetId;
    std::cin.ignore();

    for(int i = 0; i < books.size(); i++){
        if(books[i].id == targetId){

        std::cout << "BOOK" << i + 1 << std::endl;
        std::cout << "ID: " << books[i].id << std::endl;
        std::cout << "Title: " << books[i].title << std::endl;
        std::cout << "Author: " << books[i].author << std::endl; 
        std::cout << "Year: " << books[i].year << std::endl;
        std::cout << std::endl;
        return;
        

        }
        std::cout << "Không có thông tin!!" << std::endl;
    }
}

//hàm chọn menu
void PrintMenu(){
    std::cout << "\n===Menu===" << std::endl;
    std::cout << "1.Thêm sách." << std::endl;
    std::cout << "2.Hiển thị." << std::endl;
    std::cout << "3.Tìm sách." << std::endl;
    std::cout << "0.Exit." << std::endl;
    std::cout << "Chọn: ";
}



int main(void){
    std::vector<Book> books; //books = danh sách chứa nhiều Book
    int choice;
    do
    {
        PrintMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice)
        {
        case 1:
            addBook(books);
            break;
        case 2:
            displayBook(books);
            break;
        case 3: 
            findBookbyId(books);
            break;
        case 0:
            std::cout << "Đã thoát chương trình!";
            break;
        default:
            std::cout << "Lỗi!";
            break;
        }
    } while (choice != 0);
    


    return 0;
}