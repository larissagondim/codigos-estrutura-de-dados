# raw_linkedlist.py
# showcases how a linked list works using a dictionary

# what i will be showcasing is a linked list with three elements, displayed like this
# 7 -> 5 -> 8

head = {
    "data": 7,
    "next": {
        "data": 5,
        "next": {
            "data": 8,
            "next": None
        }
    }
}

# if we want to access a specific element, we can do this
print(f"1st element (index 0): {head['data']}")
print(f"2nd element (index 1): {head['next']['data']}")
print(f"3rd element (index 2): {head['next']['next']['data']}")
