# Inventory & Shopping Cart System (C++)

## Giới thiệu
Đây là một chương trình quản lý sản phẩm đơn giản bằng C++ theo phong cách **OOP**.  
Chương trình cho phép:
- Quản lý sản phẩm (Product) và sản phẩm điện tử (Electronics, có thêm bảo hành).  
- Quản lý kho hàng bằng template class `InventoryList<T>`.  
- Thêm sản phẩm vào giỏ hàng với số lượng tùy chọn.  
- Áp dụng giảm giá thông qua interface `Discountable`.  
- Hiển thị thông tin giỏ hàng và tồn kho.  

## Thiết kế chính
- **Inheritance:** Electronics kế thừa từ Product để mở rộng thêm thuộc tính bảo hành.  
- **Operator Overloading:**  
  - `Product::operator==` để so sánh sản phẩm dựa trên ID.  
  - `ShoppingCart::operator+=` để thêm sản phẩm vào giỏ hàng.  
- **Interface:** Lớp `Discountable` buộc các lớp kế thừa cài đặt hàm `applyDiscount(double rate)`.  
- **Template Class:** Lớp `InventoryList<T>` dùng template để quản lý nhiều loại sản phẩm khác nhau.  

## Hướng dẫn sử dụng
Sau khi biên dịch và chạy chương trình, menu sẽ xuất hiện:  

===== MENU =====

1.Add Product

2.Add Electronics

3.Show Inventory

4.Add Item to Cart

5.Show Cart

6.Exit
Choose:

### Nhập dữ liệu
1. **Thêm Product** (chọn `1`):  
   - Nhập ID sản phẩm (ví dụ: P01)  
   - Nhập tên (ví dụ: Bàn phím)  
   - Nhập giá (ví dụ: 200)  
   - Nhập số lượng tồn kho (ví dụ: 10)  

2. **Thêm Electronics** (chọn `2`):  
   - Nhập ID (ví dụ: E01)  
   - Nhập tên (ví dụ: Laptop)  
   - Nhập giá (ví dụ: 1500)  
   - Nhập số lượng tồn kho (ví dụ: 5)  
   - Nhập thời gian bảo hành (tháng, ví dụ: 12)  

3. **Xem kho hàng** (chọn `3`):  
   Hiển thị tất cả sản phẩm đã nhập.  

4. **Thêm vào giỏ hàng** (chọn `4`):  
   - Nhập ID sản phẩm muốn mua.  
   - Nhập số lượng cần thêm.  

5. **Xem giỏ hàng** (chọn `5`):  
   Hiển thị toàn bộ sản phẩm trong giỏ và số lượng tương ứng.

## Hướng dẫn biên dịch và chạy

### Trên Dev-C++ 5.11
- Mở **Dev-C++ 5.11** → File → New → Project → Console Application → C++.  
- Dán toàn bộ code vào file `main.cpp`.  
- Nhấn **F11** hoặc chọn Compile & Run để chạy chương trình.  

### Trên Visual Studio (Windows)
- Tạo dự án Console App C++.  
- Trong file `main.cpp`, thay phần thư viện đầu bằng:  
  ```cpp
  #include <iostream>
  #include <vector>
  #include <string>
  using namespace std;

