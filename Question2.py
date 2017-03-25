import re

def getPostFix(infix):
	postfix = []
	temp = []
	operator = -10
	operand = -20
	leftparentheses = -30
	rightparentheses = -40
	empty = -50
	 
	def precedence(s):
		if s is '(':
			return 0
		elif s is '+' or '|':
			return 1
		elif s is '*':
			return 2
		else:
			return 99
					 
	def typeof(s):
		if s is '(':
			return leftparentheses
		elif s is ')':
			return rightparentheses
		elif s is '+' or s is '*' or s is '|':
			return operator
		elif s is ' ':
			return empty    
		else :
			return operand
	
	#infix = input("Enter the infix notation : ")
	for i in infix :
		type = typeof(i)
		if type is leftparentheses :
			temp.append(i)
		elif type is rightparentheses :
			next = temp.pop()
			while next is not '(':
				postfix.append(next)
				next = temp.pop()
		elif type is operand:
			postfix.append(i)
		elif type is operator:
			p = precedence(i)
			while len(temp) is not 0 and p <= precedence(temp[-1]) :
				postfix.append(temp.pop())
			temp.append(i)
		elif type is empty:
			continue
					 
	while len(temp) > 0 :
		postfix.append(temp.pop())
		 
	print("It's postfix notation is ",''.join(postfix))
	return ''.join(postfix)

def getNFA(postfix):
	keys=list(set(re.sub('[^A-Za-z0-9]+', '', regex)+'e'))
	
	s=[];stack=[];start=0;end=1
	
	counter=-1;c1=0;c2=0
	
	for i in regex:
		if i in keys:
			counter=counter+1;c1=counter;counter=counter+1;c2=counter;
			s.append({});s.append({})
			stack.append([c1,c2])
			s[c1][i]=c2
		elif i=='*':
			r1,r2=stack.pop()
			counter=counter+1;c1=counter;counter=counter+1;c2=counter;
			s.append({});s.append({})
			stack.append([c1,c2])
			s[r2]['e']=(r1,c2);s[c1]['e']=(r1,c2)
			if start==r1:start=c1 
			if end==r2:end=c2 
		elif i=='.':
			r11,r12=stack.pop()
			r21,r22=stack.pop()
			stack.append([r21,r12])
			s[r22]['e']=r11
			if start==r11:start=r21 
			if end==r22:end=r12 
		else:
			counter=counter+1;c1=counter;counter=counter+1;c2=counter;
			s.append({});s.append({})
			r11,r12=stack.pop()
			r21,r22=stack.pop()
			stack.append([c1,c2])
			s[c1]['e']=(r21,r11); s[r12]['e']=c2; s[r22]['e']=c2
			if start==r11 or start==r21:start=c1 
			if end==r22 or end==r12:end=c2
	
	print("The states in the NFA are : ", keys)
	
	print("The transition table is : ", s)

if __name__ == "__main__":
	infix = input("Enter the infix notation : ")
	regex = getPostFix(infix)
	getNFA(regex)
	
