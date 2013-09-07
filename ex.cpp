#include <iostream>
 
using namespace std;
 
class ClxTest
{
    public:
        ClxTest();
        ~ClxTest();
 
    void Output() const;
    int GetOutputTimes() const;
 
    private:
        mutable int m_iTimes;
};
 
ClxTest::ClxTest()
{
    m_iTimes = 0;
}
 
ClxTest::~ClxTest()
{}
 
void ClxTest::Output() const
{
    cout << "Output for test!" << endl;
    m_iTimes++; // const object can only call const function, const function cannot change data member except mutable member
}
 
int ClxTest::GetOutputTimes() const
{
    return m_iTimes;
}
 
void OutputTest(const ClxTest& lx)
{
    cout << lx.GetOutputTimes() << endl;
    lx.Output();
    cout << lx.GetOutputTimes() << endl;
    lx.Output();
    cout << lx.GetOutputTimes() << endl;
}
 
int main()
{
    ClxTest* lx = new ClxTest;
    OutputTest(*lx);
}
/* 
$ a.exe
0
Output for test!
1
Output for test!
2
 
 * */
