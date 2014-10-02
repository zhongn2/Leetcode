import java.util.Stack;

//Min_stack
// using two stacks to implement a minstack
// the first stack is to store numbers, the other one is to store the min number from 1st stack

public class minstack{
	private Stack<Integer> stack1; 
	private Stack<Integer> min_stack; 
	// copy constructor
	public minstack(){
		stack1 = new Stack<Integer>();
		min_stack = new Stack<Integer>();
	}
	
	public void push(int number){
		stack1.push(number);
		if(min_stack.empty()){
			min_stack.push(number);
		}else{
			if(min_stack.peek() >= number){
				min_stack.push(number);
			}
		}
	}
	public int pop(){
		if(stack1.peek() == min_stack.peek()){
			min_stack.pop();
		}
		return stack1.pop();
	}
	public int min(){
		return min_stack.peek();
	}
	public static void main(String[] args){
		minstack minstack = new minstack();
		minstack.push(2);
		minstack.push(4);
		minstack.push(10);
		minstack.push(3);
		minstack.pop();
		System.out.println(minstack.min());
	}
}

