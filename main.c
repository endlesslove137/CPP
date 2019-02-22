#include <stdio.h>
class Sample{
    public:
        Sample(int x){
           p = (int*)new(x)
        }
        ~Sample(){
            if(p) delete p;
        }
        int show(){
            return *p;
        }
    private:
        int*p;
};
int main(){
    Sample S(5);
    cout<<"%d"<<S.show()
    return 0;
}

