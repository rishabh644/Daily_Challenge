class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}  # key -> value
        self.usage_order = []  # list to track usage order

    def get(self, key: int) -> int:
        if key in self.cache:
            # Move the accessed key to the end to mark it as recently used
            self.usage_order.remove(key)
            self.usage_order.append(key)
            return self.cache[key]
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            # Update the value
            self.cache[key] = value
            # Move the key to the end to mark it as recently used
            self.usage_order.remove(key)
            self.usage_order.append(key)
        else:
            if len(self.cache) >= self.capacity:
                # Remove the least recently used key
                lru_key = self.usage_order.pop(0)
                del self.cache[lru_key]
            # Add the new key-value pair
            self.cache[key] = value
            self.usage_order.append(key)

# Example usage:
cache = LRUCache(2)
cache.put(1, 1)
cache.put(2, 2)
print(cache.get(1))    # returns 1
cache.put(3, 3)       # evicts key 2
print(cache.get(2))    # returns -1 (not found)
cache.put(4, 4)       # evicts key 1
print(cache.get(1))    # returns -1 (not found)
print(cache.get(3))    # returns 3
print(cache.get(4))    # returns 4
