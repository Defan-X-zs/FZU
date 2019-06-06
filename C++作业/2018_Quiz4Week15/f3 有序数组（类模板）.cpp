//有序数组（类模板）
template<class T>
class MyArray{
private:
    T *data;
    int size;
public:
    MyArray(int s);
    ~MyArray();
    void sort();
    void display();
    bool check();
};
template<class T>
void MyArray<T>::display(){
    for(int i=0;i<size;i++){
        cout<<data[i];
        if(i<size-1)
            cout<<" ";
    }
    cout<<endl;
}
template<class T>
MyArray<T>::MyArray(int s){
        size = s;
        data = new T[size];
        for(int i=0;i<size;i++)
            cin>>data[i];
    }
template<class T>
void MyArray<T>::sort(){
        for(int i=0;i<size-1;i++)
            for(int j=0;j<size-i-1;j++)
                if(data[j]>data[j+1]){
                    T temp = data[j];
                    data[j] = data[j+1];
                    data[j+1] = temp;
                }
  }