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
//tìm theo id
void findBookById(const std::vector<Book>& books){

    int targetId;


    std::cout << "Hãy nhập id sách: ";
    std::cin >> targetId;
    std::cin.ignore();

    

    for(int i = 0; i < books.size(); i++){
        if(books[i].id == targetId){

        std::cout << "BOOK " << i + 1 << std::endl;
        std::cout << "ID: " << books[i].id << std::endl;
        std::cout << "Title: " << books[i].title << std::endl;
        std::cout << "Author: " << books[i].author << std::endl; 
        std::cout << "Year: " << books[i].year << std::endl;
        std::cout << std::endl;
        return;
        }
    }
    std::cout << "Không có thông tin!!" << std::endl;

}

//tìm theo năm
void findBookByYear(const std::vector<Book>& books){
    int targetYear;
    std::cout << "Nhập năm phát hành: ";
    std::cin >> targetYear;
    std::cin.ignore();

    bool found = false;

    for(int i = 0; i < books.size();i++){
        if(books[i].year == targetYear){

        std::cout << "BOOK" << i + 1 << std::endl;
        std::cout << "ID: " << books[i].id << std::endl;
        std::cout << "Title: " << books[i].title << std::endl;
        std::cout << "Author: " << books[i].author << std::endl; 
        std::cout << "Year: " << books[i].year << std::endl;
        std::cout << std::endl;
        found = true;
        }
    }
    if(found == false){
        std::cout << "Không có thông tin!!" << std::endl;       
    }

}
//tìm theo title
void findBookByTitle(const std::vector<Book>& books){
    std::string targetAuthor;
        if (books.empty()) //dùng để kiểm tra danh sách có rỗng không
    {
        std::cout << "Chưa có sách trong thư viện!" << std::endl;
        return;
    }

    std::cout << "Nhập tên sách: ";
    getline(std::cin,targetAuthor);
    
    bool found = false;

    for(int i = 0; i < books.size(); i++){
        if(books[i].title == targetAuthor){
        std::cout << "BOOK" << i + 1 << std::endl;
        std::cout << "ID: " << books[i].id << std::endl;
        std::cout << "Title: " << books[i].title << std::endl;
        std::cout << "Author: " << books[i].author << std::endl; 
        std::cout << "Year: " << books[i].year << std::endl;
        std::cout << std::endl;
        found = true;
        }     
    }
    if(found == false){
    std::cout << "Không có thông tin!!" << std::endl;
    }
}
//tìm theo author
void findBookByAuthor(const std::vector<Book>& books){
    std::string targetAuthor;
    std::cout << "Nhập tên tác giả: ";
    getline(std::cin,targetAuthor);
    
    bool found = false;

    for(int i = 0; i < books.size(); i++){
        if(books[i].title == targetAuthor){
        std::cout << "BOOK" << i + 1 << std::endl;
        std::cout << "ID: " << books[i].id << std::endl;
        std::cout << "Title: " << books[i].title << std::endl;
        std::cout << "Author: " << books[i].author << std::endl; 
        std::cout << "Year: " << books[i].year << std::endl;
        std::cout << std::endl;
        found = true;
        }     
    }
    if(found == false){
    std::cout << "Không có thông tin!!" << std::endl;
    }    

}

//MENU

//hàm chọn menu
void PrintMenu(){
    std::cout << "\n===Menu===" << std::endl;
    std::cout << "1.Thêm sách." << std::endl;
    std::cout << "2.Hiển thị." << std::endl;
    std::cout << "3.Tìm sách." << std::endl;
    std::cout << "4.Update/Delete sách!" << std::endl;
    std::cout << "0.Exit." << std::endl;
    std::cout << "Chọn: ";
}
//menu tìm sách
void FindMenu(){
    std::cout << "\n===Menu===" << std::endl;
    std::cout << "1.Tìm sách theo Id!" << std::endl;
    std::cout << "2.Tìm sách theo năm phát hành!" << std::endl;
    std::cout << "3.Tìm sách theo title!" << std::endl;
    std::cout << "4.Tìm sách theo tên tác giả!" << std::endl;
    std::cout << "0.Exit." << std::endl;
    std::cout << "Chọn: ";
}
//menu chọn xóa
void SelectOption(){
    std::cout << "\n===Menu===" << std::endl;
    std::cout << "1.Update sách!" << std::endl;
    std::cout << "2.Delete sách!" << std::endl;
    std::cout << "0.Exit." << std::endl;
    std::cout << "Chọn: ";
}

//update and delete books

//update books
void updateBookById(std::vector<Book>& books){
    int updateForId;
    if(books.empty()){
        std::cout << "Không có thông tin sách!";
        return;
    }
    
    std::cout << "Nhập Id sách: ";
    std::cin >> updateForId;
    std::cin.ignore();


    bool found = false;

    for(int i = 0; i < books.size(); i++){
        if(books[i].id == updateForId){

            std::cout << "Nhập title mới: ";
            getline(std::cin,books[i].title);
            std::cout << "Nhập author mới: ";
            getline(std::cin,books[i].author);
            std::cout << "Nhập year: ";
            std::cin >> books[i].year;
            std::cin.ignore();
            found = true;
            std::cout << "Update thành công!" << std::endl;
            return;
        }
    }
    if(found == false){
    std::cout << "Không có thông tin!!" << std::endl;
    } 
}
// hàm delete
void deleteBookById(std::vector<Book>& books){

    int delBookForId;
    if(books.empty()){
        std::cout << "Không có thông tin sách!";
        return;
    }
    std::cout << "Nhập Id sách: ";
    std::cin >> delBookForId;
    std::cin.ignore();
    for(int i = 0; i < books.size(); i++){
        if(books[i].id == delBookForId){
            books.erase(books.begin() + i);
            std::cout << "Xóa thành công!";
            return;
        }    
    }
    std::cout << "Không có thông tin!!" << std::endl;
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
            int find;
            do
            {
                FindMenu();
                std::cin >> find;
                std::cin.ignore();

                switch (find)
                {
                case 1:
                    findBookById(books);
                    break;
                case 2:
                    findBookByYear(books);
                    break;
                case 3:
                    findBookByTitle(books);
                    break;
                case 4:
                    findBookByAuthor(books);
                    break;
                case 0:
                    std::cout << "Đã thoát chương trình!" << std::endl;
                    break;
                default:
                    std::cout << "Error!";
                    break;
                }
            } while (find != 0);
            break;
        case 4: 
            int selectedOption;
            do
            {
                SelectOption();
                std::cin >> selectedOption;
                std::cin.ignore();

                switch(selectedOption)
                {
                    case 1:
                        updateBookById(books);
                        break;
                    case 2:
                        deleteBookById(books);
                        break;
                    case 0:
                        std::cout << "Đã thoát chương trình!" << std::endl;
                        break;
                    default:
                        std::cout << "Error!";
                        break;
                }
            } while (selectedOption != 0);
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