enum ErrorCode
{
         success,
         underflow,
         overflow
};

const int maxStack = 100;             // 栈的最大容量
template <class StackEntry>
class MyStack
{
public:
         MyStack() : size(0) {
                   for (int i = 0; i < maxStack; i++) {
                       entry[i] = 0;
                   }
         }
         /*
                   判断栈是否为空，若为空则返回true，非空则返回false
          */
         bool empty() const {
              if (size == 0) {
                       return true;
              } else {
                     return false;
              }
         }
         /*
                   出栈操作，若正常出栈则返回success，若栈内无元素则返回underflow
          */
         ErrorCode pop()
          {
                   ErrorCode temp = success;
                   if (size == 0)
                   {
                            return underflow;
                   }
                   else
                   {
                       size--;
                       return success;
                   }
          }
         /*
                   获取栈顶元素，若正常出栈则返回success，若栈内无元素则返回underflow
                   元素内容保存在引用参数item中
          */

         ErrorCode top(StackEntry &item) const
         {
                   if (size == 0) {
                            return underflow;
                            } else {
                                   item = entry[size - 1];
                                   return success;
                                   }
         }
         /*
                   入栈操作，若正常入栈则返回success，若栈满则返回overflow
          */

         ErrorCode push(const StackEntry &item)
         {
                   if (size == maxStack)
                   {
                            return overflow;
                            }
                            else
                            {
                                entry[size++] = item;
                                }
         }
private:
         int size;
         StackEntry entry[maxStack];
};                                 
