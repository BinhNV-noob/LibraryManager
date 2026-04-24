#include<iostream>
#include<string>
#include<vector>

//tạo 1 struct với thông tin cơ bản của 1 quyển sách
struct Book
{
    int id;                 //id = stt nhập vào của sách
    std::string title;      // tên đầu sách
    std::string author;     // tên tác giả
    int year;               // năm phát hành
};


int main(void){

    std::vector<Book> books;  //Book là kiểu dữ liệu, còn books là danh sách chứa nhiều Book
    Book temp; //đây là 1 biến lưu tạm để sau khi nhập thông tin sẽ đẩy vào danh sách

    std::cout << "Enter id: ";
    std::cin >> temp.id;
    std::cin.ignore(); // xóa ký tự Enter còn sót lại sau cin >> để getline không bị bỏ qua

    std::cout << "Enter title: ";
    getline(std::cin,temp.title); // getline đọc cả dòng, bao gồm khoảng trắng, cho tới khi gặp Enter
                                  // cin >> chỉ đọc tới khi gặp khoảng trắng hoặc Enter
    std::cout << "Enter author: ";
    getline(std::cin, temp.author);

    std::cout << "Enter year: ";
    std::cin >> temp.year; 
    std::cin.ignore(); //đoạn này cũng tương tự như ở trên thôi, nó được dùng để tiếp tục cho 1 quá trình nhập tiếp theo nếu chưa áp dụng vòng lặp vào chương trình
                       //đoạn này thêm vào để giải thích thôi, chứ chắc chưa dùng đến
    books.push_back(temp); //dùng để lấy thông tin từ biến lưu tạm, cụ thể là copy dữ liệu của biến lưu rồi đưa vào danh sách

    std::cout << "\n====BOOK====" << std::endl;
    std::cout << "ID: " << temp.id << std::endl;
    std::cout << "Title: " << temp.title << std::endl;
    std::cout << "Author: " << temp.author << std::endl;
    std::cout << "Year: " << temp.year;
    //hiển thị thông tin của sách vừa được nhập









    return 0;
}

