class LinkedList:
    def __init__(self):
        self.data = None
        self.next = None
        self.prev = None

def solve(logs):
    n = len(logs)
    dk = {}
    head = None
    tail = None

    for i in range(n):
        if head is None:
            head = LinkedList()
            head.data = logs[i]
            tail = head
            head.next = None
            tail.next = None
            tail.prev = None

            dk[logs[i]] = head
        else:
            if logs[i] in dk:
                temp = dk[logs[i]]
                if temp != head:
                    temp.prev.next = temp.next
                    if temp.next is not None:
                        temp.next.prev = temp.prev
                    temp.prev = None
                    temp.next = head
                    head.prev = temp
                    head = temp
            else:
                new_node = LinkedList()
                new_node.prev = tail
                new_node.next = None
                tail.next = new_node
                tail = new_node
                tail.data = logs[i]
                dk[logs[i]] = tail

    ans = []
    while head:
        ans.append(head.data)
        head = head.next

    return ans

logs = []
result = solve(logs)

print("Result:", result)

token_dict = {}  
result = []  
    
for query in queries:
    tokens = query.split() 
    
    if tokens[0] == "generate":
        token_id = tokens[1]
        current_time = int(tokens[2])
        expiration_time = current_time + time_to_live
        
        token_dict[token_id] = expiration_time
    
    elif tokens[0] == "renew":
        token_id = tokens[1]
        current_time = int(tokens[2])
        
        if token_id in token_dict and token_dict[token_id] > current_time:
            token_dict[token_id] = current_time + time_to_live
    
    elif tokens[0] == "count":
        current_time = int(tokens[1])

        count = sum(1 for exp_time in token_dict.values() if exp_time > current_time)
        result.append(count)

return result