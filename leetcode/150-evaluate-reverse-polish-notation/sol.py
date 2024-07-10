import math
class Solution:
   def evalRPN(self, tokens: List[str]) -> int:
      stack = []
      operators = ['+', '-', '*','/']
      for char in tokens :
         if char not in operators :
            stack.append(int(char))
         else :
            if stack  :
               if char == '+' :
                  stack.append(stack.pop() + stack.pop())
               elif char == '-' :
                  num1 = stack.pop()
                  num2 = stack.pop()
                  stack.append(num2 - num1)
               elif char == '*' :
                  stack.append(stack.pop() * stack.pop())
               elif char == '/' :
                  num1 = stack.pop()
                  num2 = stack.pop()
                  stack.append(math.trunc(num2/num1)) 
      return stack[0]
