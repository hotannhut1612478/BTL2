#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    cout<<" "<<endl;
    cout<<"*       *       * ******** * 	      *******   ******  *       * ********"<<endl;
    cout<<" *     * *     *  *        *	     *	       *      * * *   * * *	  "<<endl;
    cout<<"  *   *   *   *   ******** *         *	       *      * *  * *  * ********"<<endl;
    cout<<"   * *     * *    *        *	     *	       *      * *   *   * *"<<endl;
    cout<<"    *       *     ******** ********   *******   ******  *       * ********"<<endl;
    cout<<"-------========__________________________________________========---------"<<endl;
    cout<<"  "<<endl;
    cout<<" chon :"<<endl;
    cout <<"1.nguoi dung"<<endl;
    cout<<"2.quan ly"<<endl;
    cout<<"3.thu thu"<<endl;
    int a;
    cin>>a;
    switch(a){
        case 1:
            cout<<"chon"<<endl;
            cout<<"1.tim kiem"<<endl;
            cout<<"2.xem tong bao"<<endl;
            cout<<"3.xem thong tin"<<endl;
            cout<<"4.doi mat khau"<<endl;
            cin>>a;
            switch(a){
            case 1:
                cout<<"nhap sach can tim kiem"<<endl;
                break;
            case 2:
                cout<<"cac thong bao gan day la"<<endl;
                break;
            case 3:
                cout<<"nhap tinh nang can dung"<<endl;
                cout<<"1.Lich su muon/tra sach"<<endl;
                cout<<"2.Lich su bi phat"<<endl;
                cin>>a;
                break;
            case 4:
                cout<<"nhap "<<endl;
                break;
            }
        break;
        case 2:
            cout<<"chon tinh nang"<<endl;
            cout<<"1.quan ly thong tin nguoi dung"<<endl;
            cout<<"2.quan ly tai khoan"<<endl;
            cin>>a;
            switch(a){
            case 1:
                cout<<"chon tinh nang"<<endl;
                cout<<"1.Them vao"<<endl;
                cout<<"2.Chinh sua"<<endl;
                cout<<"3.Xoa khoi he thong"<<endl;
                cout<<"4.Tim kiem"<<endl;
                break;
            case 2:
                cout<<"chon tinh nang"<<endl;
                cout<<"1.them vao tai khoan"<<endl;
                cout<<"2.Mo va khoa tai khoan"<<endl;
                cout<<"3.Lap lai mat khau"<<endl;
                cout<<"4.Tim kiem tai khoan"<<endl;
                break;
            default:
                 cout<<"xin nhap lai"<<endl;
            }
        break;
        case 3:{
            cout<<"chon tinh nang"<<endl;
            cout<<"1.danh cho nguoi"<<endl;
            cout<<"2.danh cho sach"<<endl;
            cin>>a;
            switch(a){
            case 2:
                cout<<"1.Them vao"<<endl;
                cout<<"2.Chinh sua"<<endl;
                cout<<"3.Xoa khoi he thong"<<endl;
                cout<<"4.Tim kiem"<<endl;
                break;
            case 1:
                cout<<"1.Ghi nhan muon/tra sach"<<endl;
                cout<<"2.phat vi qua han"<<endl;
                cout<<"3.giai quyet viec lam that lac sach"<<endl;
                break;
            default:
                 cout<<" xin nhap lai"<<endl;
            }
        break;
        }
     default: cout<<"xin nhap lai"<<endl;
    }
    return 0;
}