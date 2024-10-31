#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node
{
    int age;
    char name[105];
    int number;
} Person;

bool compare(const Person &person1, const Person &person2)
{
    if(person1.age<person2.age)
        return true;
    else if(person1.age==person2.age)
    {
        if(person1.number<person2.number)
            return true;
    }
    return false;
}

int main(void)  
{
    int n;
    scanf("%d", &n);
    vector<Person>
        people(n);
    for (int i = 0; i < n;i++)
    {
        scanf("%d%s", &people[i].age, people[i].name);
        people[i].number = i;
    }
    sort(people.begin(), people.end(), compare);
    for (int i = 0; i < n;i++)
    {
        printf("%d %s\n", people[i].age, people[i].name);
    }
}