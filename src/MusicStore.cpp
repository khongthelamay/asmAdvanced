#include "../include/MusicStore.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;
//biến static store này được khởi tạo giá trị bằng 0;
MusicStore* MusicStore::store = 0;
//menthod pricate MusicStore
MusicStore::MusicStore()
{}
//Trả về một đối tượng kiểu MusicStore duy nhất
//Nếu chương trình đã tồn tại thì trả về store chính là đối tượng kiểu MusicStore duy nhất đó
//Nếu chưa tồn tại thì tạo ra một đối tượng mới rồi mới trả về kết quả
MusicStore* MusicStore:: getStore()
{
    if(store == 0)
    {
        store = new MusicStore();
    }
    return store;
}

//Xem trong file header (MusicStore.h) để biết xem SongGenres là gì
//phần này hiểu đơn giản vòng lặp for chạy từ đầu đến cuối của vector SongGenres
//sau đó lấy tên của từng phần tử so sánh với tên thể loại bài hát mình muốn thêm
//nếu trùng thì tiến hành gọi method addSong của phần tử đó và thoát khỏi method
//trong trường hợp không có thể loại nhạc đó thì mới [1]
//để hiểu tại sao có thể thêm được bài hát vào từng phần tử mở file SongGenre.ccp
void MusicStore::addSong(const string &name, const string &genre)
{
    for(int i =0; i < SongGenres.size();i++)
    {
        if(SongGenres[i].get_name() == genre)
        {
            SongGenres[i].addSong(name);
            cout << "Insert completed." << endl;
            cout << endl;
            return;
        }
    }
    //[1] thêm loại bài hát vào trong vector SongGenres
    //sau đó mới thêm bài hát vào trong phần tử SongGenres[x nào đấy] vừa tạo
    SongGenres.push_back(genre);
    SongGenres[SongGenres.size()-1].addSong(name);
}
//đây là hàm trả về vector SongGenre tức là tất cả thể loại nhạc sẽ được trả về tại hàm này
vector<SongGenre> MusicStore::get_song()
{
    return SongGenres;
}
//Để tìm kiếm bài hát cần 2 yếu tố: 1.Tên thể loại của bài hát đó(genre); 2.tên bài hát(name)
//Tương tự như lúc addsong, sử dụng vòng lặp đầu tiên để tìm ra genre 
//Nếu có genre thì mới tìm trong genre đó có bài hát name không?
// đoạn này t đoán dù có tìm đc hay không thì nó vẫn ghi là not found
//nếu như t đoán thì thêm 1 câu return vào sau dòng 70
void MusicStore::findSong(const string &name, const string &genre)
{
    cout << endl;
    cout << "------ RESULT SEARCHING -----" << endl;
    for(int i=0;i<SongGenres.size();i++)
    {
        if(SongGenres[i].get_name() == genre)
        {
            vector<Song> songs = SongGenres[i].get_song();
            for(int j = 0; j < songs.size(); j++)
            {
                if(songs[j].get_name() == name) {
                    cout << songs[j].get_name() << " || " << name;   
                }
            }

        }
    }
    cout << "Not found" << endl;
}

//Tương tự với deleteSong gọi hàm findSong nếu có thì gọi tới deleteSong cái nafyy cũng mở File Songenre ra để hiểu
void MusicStore::deleteSong(const string &name)
{
    for(int i =0;i<SongGenres.size();i++)
    {
        if(SongGenres[i].findSong(name))
        {
            SongGenres[i].deleteSong(name);
        }
    }
    // cout << "Not found" << endl;
}

//cái hàm này là show ra toàn bộ bài hát và loại bài hát của nó
//nó viết ra loại nhạc rồi các bài hát trong loại nhạc đấy
//làm nào đúng thì ib t teamview chứ visual code của t, t không biết phải cài những gì đế cho nó chạy :V
void MusicStore::show_song()const
{
    cout << "* --- LIST OF SONGS: --- *" << endl;
    for( int i = 0; i < SongGenres.size(); i++)
    {
        cout <<"- Genre: "<< SongGenres[i].get_name() << endl;
        vector<Song> songs = SongGenres[i].get_song();
        for(int j= 0; j < songs.size();j++)
        {
            cout << "     + " << songs[j].get_name() << endl;
        }
        //lam nao dung?
    }
}
//cái này thì đơn giản là thêm 1 loại nhạc vào trong biến SongGenres
//cái địt mẹ thằng nào dạy m cái này đây vả chết cụ nó đi ngu lol thật
//chương trình vẫn chạy đc là cả 1 kì tích đấy. N mà để này cũng không sao đâu mỗi tội trông như đb
void MusicStore::add_gender(const string &name)
{
    SongGenres.push_back(name);
}