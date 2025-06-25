// TODO : Print all elements in queue

#include <iostream>
#include <queue>
using namespace std;
int main()
{
  queue<int> q;

  q.push(2);
  q.push(4);
  q.push(6);
  q.push(3);
  q.push(5);

  while (!q.empty())
  {
    cout << q.front() << " ";
    q.pop();
  }

  return 0;
}

// TODO : Print all elements in queue without pop out

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
  queue<int> q;

  q.push(2);
  q.push(4);
  q.push(6);
  q.push(3);
  q.push(5);

  vector<int> ans(q.size());

  while (!q.empty())
  {
    cout << q.front() << " ";
    ans.push_back(q.front()); // store queue elements into vector
    q.pop();
  }

  // push elements from vector to queue
  for (int i = 0; i < ans.size(); i++)
  {
    q.push(ans[i]);
  }

  return 0;
}

// TODO : Print all elements in queue without using extra space

#include <iostream>
#include <queue>
using namespace std;
int main()
{
  queue<int> q;

  q.push(2);
  q.push(4);
  q.push(6);
  q.push(3);
  q.push(5);

  int n = q.size();

  while (n--)
  {
    cout << q.front() << " ";
    q.pop();
    q.push(q.front());
  }

  return 0;
}

// TODO : Queue Reversal

// & Method 1 :- reverse queue elements using array

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
  queue<int> q;

  q.push(3);
  q.push(7);
  q.push(11);
  q.push(8);
  q.push(9);

  int n = q.size();

  vector<int> arr(n);

  for (int i = 0; i < n; i++)
  {
    arr[i] = q.front();
    q.pop();
  }

  for (int i = arr.size() - 1; i >= 0; i--)
  {
    q.push(arr[i]);
  }

  while (!q.empty())
  {
    cout << q.front() << " ";
    q.pop();
  }

  return 0;
}

// & Method 2 :- reverse queue elements using stack

#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main()
{
  queue<int> q;

  q.push(3);
  q.push(7);
  q.push(11);
  q.push(8);
  q.push(9);

  int n = q.size();

  stack<int> st;

  for (int i = 0; i < n; i++)
  {
    st.push(q.front());
    q.pop();
  }

  while (!st.empty())
  {
    q.push(st.top());
    st.pop();
  }

  while (!q.empty())
  {
    cout << q.front() << " ";
    q.pop();
  }

  return 0;
}

// TODO : Reverse first k elements of queue

#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main()
{
  int k = 3;
  stack<int> st;
  queue<int> q;

  q.push(3);
  q.push(7);
  q.push(10);
  q.push(13);
  q.push(8);
  q.push(5);
  q.push(4);

  // push first k elements of queue into stack

  while (k--)
  {
    st.push(q.front());
    q.pop();
  }

  // store the size of queue
  int n = q.size();

  // push all elements of stack into queue
  while (!st.empty())
  {
    q.push(st.top());
    st.pop();
  }

  // push first n elements of queue at last
  for (int i = 0; i < n; i++)
  {
    q.push(q.front());
    q.pop();
  }

  // printing the resultant queue
  while (!q.empty())
  {
    cout << q.front() << " ";
    q.pop();
  }

  return 0;
}

// TODO : Time Needed to Buy Tickets
// & link : https://leetcode.com/problems/time-needed-to-buy-tickets/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
  vector<int> tickets;
  tickets.push_back(1);
  tickets.push_back(5);
  tickets.push_back(2);
  tickets.push_back(3);
  tickets.push_back(7);

  int k = 4;
  queue<int> q;

  for (int i = 0; i < tickets.size(); i++)
  {
    q.push(i);
  }

  int time = 0;

  while (tickets[k] != 0)
  {
    tickets[q.front()]--;

    if (tickets[q.front()])
    {
      q.push(q.front());
    }

    q.pop();

    time++;
  }

  cout << "The time taken by element which is at " << k << " index takes " << time << "s time";

  return 0;
}

// & Method 2 :- Time complexity O(n)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
  vector<int> tickets;
  // tickets.push_back(1);
  // tickets.push_back(5);
  // tickets.push_back(2);
  // tickets.push_back(3);
  // tickets.push_back(7);
  tickets.push_back(1);
  tickets.push_back(2);
  tickets.push_back(3);
  tickets.push_back(4);
  tickets.push_back(5);
  tickets.push_back(6);
  tickets.push_back(7);
  tickets.push_back(8);

  int k = 4;

  int time = 0;

  for (int i = 0; i <= k; i++)
  {
    time += min(tickets[i], tickets[k]);
  }

  for (int j = k + 1; j < tickets.size(); j++)
  {
    time += min(tickets[j], tickets[k] - 1);
  }

  cout << "The time taken by element which is at " << k << " index takes " << time << "s time";

  return 0;
}

// TODO : Implement Queue Using Stack :-
// & Link :- https://leetcode.com/problems/implement-queue-using-stacks/description/

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Queue
{
  stack<int> st1;
  stack<int> st2;

public:
  bool empty()
  {
    return st1.empty() && st2.empty();
  }

  void push(int x)
  {
    st1.push(x);
  }

  int pop()
  {
    if (empty())
    {
      cout << "Queue is empty" << endl;
      return -1; // Return -1 to indicate error
    }

    if (st2.empty())
    {
      while (!st1.empty())
      {
        st2.push(st1.top());
        st1.pop();
      }
    }

    int element = st2.top();
    st2.pop();
    return element;
  }

  int peek()
  {
    if (empty())
    {
      cout << "Queue is empty" << endl;
      return -1; // Return -1 to indicate error
    }

    if (st2.empty())
    {
      while (!st1.empty())
      {
        st2.push(st1.top());
        st1.pop();
      }
    }

    return st2.top();
  }
};

int main()
{
  Queue q;

  q.push(3);
  q.push(7);
  q.push(10);
  q.push(13);
  q.push(8);
  q.push(5);
  q.push(4);

  cout << "Front element: " << q.peek() << endl;
  cout << "Popped element: " << q.pop() << endl;
  cout << "New front element: " << q.peek() << endl;

  cout << "All elements: ";
  while (!q.empty())
  {
    cout << q.pop() << " ";
  }
  cout << endl;

  return 0;
}

// TODO :- Implement Stack Using Queue :-
// & Link :- https://leetcode.com/problems/implement-stack-using-queues/description/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Stack
{
  queue<int> q1;
  queue<int> q2;

public:
  bool empty()
  {
    return q1.empty() && q2.empty();
  }

  void push(int x)
  {
    if (empty())
    {
      q1.push(x);
    }
    else if (q1.empty())
    {
      q2.push(x);
    }
    else
    {
      q1.push(x);
    }
  }

  int pop()
  {
    if (empty())
    {
      return 0;
    }
    else if (q1.empty())
    {
      while (q2.size() > 1)
      {
        q1.push(q2.front());
        q2.pop();
      }

      int element = q2.front();
      q2.pop();
      return element;
    }
    else
    {
      while (q2.size() > 1)
      {
        q2.push(q1.front());
        q1.pop();
      }

      int element = q1.front();
      q1.pop();
      return element;
    }
  }

  int top()
  {
    if (empty())
    {
      return 0;
    }
    else if (q1.empty())
    {
      return q2.back();
    }
    else
    {
      return q1.back();
    }
  }
};

int main()
{
  Stack st; // Changed from stack<int> to Stack

  st.push(3);
  st.push(7);
  st.push(10);
  st.push(13);
  st.push(8);
  st.push(5);
  st.push(4);

  cout << "Front element: " << st.top() << endl;
  cout << "Popped element: " << st.pop() << endl;
  cout << "New front element: " << st.top() << endl; // Changed from peek() to top()

  cout << "All elements: ";
  while (!st.empty())
  {
    cout << st.pop() << " ";
  }
  cout << endl;

  return 0;
}