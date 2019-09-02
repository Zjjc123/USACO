struct Type
{

};

int main()
{
    // Java

    // Auto destroy
    // Stack
    int a = 5;
    // Heap
    Type b = new Type();


    // C++
    // Stack --> Auto Destroy
    int c; int d = 5;
    Type e;

    // Heap
    Type * f = new Type();
    delete f;

}