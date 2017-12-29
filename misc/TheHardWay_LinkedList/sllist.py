# Node class
class SingleLinkedListNode(object):
    def __init__(self, value, nxt):
        self.value = value
        self.next = nxt

    def __repr__(self):
        nval = self.next and self.next.value or None
        #return f"[{self.value}:{repr(nval)}]" # Need python 3.6
        return "[{self.value}:{repr(nval)}]".format(self.value, repr(nval))

# Controller
class SingleLinkedList(object):

    def __init__(self):
        self.begin = None
        self.end = None

    def push(self, obj):
        """Appends a new value on the end of the list."""
        newNode = SingleLinkedListNode(obj, None)
        if self.begin == None:
            self.begin = newNode
            self.end = self.begin
        else:
            self.end.next = newNode
            self.end = self.end.next

    def pop(self):
        """Removes the last item and returns it."""
        # Case 1: empty list
        if self.begin == None:
            return None

        # Case 2: single element list
        if self.begin == self.end:
            result = self.begin
            self.begin = None
            self.end = None
            return result.value
        else:
            result = self.end
            iterator = self.begin
            while iterator.next != self.end:
                iterator = iterator.next
            self.end = iterator
            self.end.next = None
            return result.value

    def shift(self, obj):
        """Appends a new value on the start of the list."""
        newNode = SingleLinkedListNode(obj, None)
        if self.begin == None:
            self.begin = newNode
            self.end = self.begin
        else:
            newNode.next = self.begin
            self.begin = newNode

    def unshift(self):
        """Removes the first item and returns it."""
        if self.begin == None:
            return None
        if self.begin == self.end:
            result = self.begin
            self.begin = None
            self.end = None
            return result.value
        else:
            result = self.begin
            self.begin = result.next
            return result.value

    def remove(self, obj):
        """Finds a matching item and removes it from the list."""
        if self.begin.value == obj:
            if self.begin == self.last:
                self.last = None
            self.begin = self.begin.next
            return 0
        else:
            index = 0
            iterator = self.begin
            while iterator.next != None:
                if iterator.next.value == obj:
                    iterator.next = iterator.next.next
                    return index+1
                else:
                    iterator = iterator.next
                    index += 1
            return None
                

    def first(self):
        """Returns a *reference* to the first item, does not remove."""
        return self.begin.value

    def last(self):
        """Returns a reference to the last item, does not remove."""
        return self.end.value

    def count(self):
        """Counts the number of elements in the list."""
        if self.begin == None:
            return 0
        else:
            counter = 1
            iterator = self.begin
            while iterator.next != None:
                iterator = iterator.next
                counter += 1
            return counter

    def get(self, index):
        """Get the value at index."""
        ind = 0
        iterator = self.begin
        while iterator != None:
            if ind == index:
                return iterator.value
            else:
                iterator = iterator.next
                ind+=1
        return None

    def dump(self, mark):
        """Debugging function that dumps the contents of the list."""
        print(mark,": ")
        iterator = self.begin
        while iterator != None:
            print(iterator.value, end=" ")
            iterator = iterator.next
        print("")
