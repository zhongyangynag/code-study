interface cacheNode<T> {
    key: T;
    value: T;
    prev: cacheNode<T> | null;
    next: cacheNode<T> | null;
}

class LRUCache {
    cacheMap: Map<number, cacheNode<number>>;
    lastestRecentlyUsed: cacheNode<number> | null;
    size: number;
    contain: number;
    constructor(capacity: number) {
        this.cacheMap = new Map();
        this.lastestRecentlyUsed = null;
        this.contain = 0;
        this.size = capacity;
    }

    get(key: number): number {
        let node = this.cacheMap.get(key);
        if (node) {
            this.remove(node).insertHead(node);
            return node.value;
        }
        return -1;
    }

    put(key: number, value: number): void {
        if (this.contain === this.size) {
            if (this.size === 0) {
                return;
            }
            // delete lastest key

            let discardNode = this.lastestRecentlyUsed!
                .prev as cacheNode<number>;
            console.log('deletedNext', discardNode.next);
            this.cacheMap.delete(discardNode.key);
            this.remove(discardNode);
            this.contain--;
        }
        let pendingNode = this.cacheMap.get(key);
        if (pendingNode) {
            pendingNode.value = value;
            this.remove(pendingNode).insertHead(pendingNode);
        } else {
            pendingNode = {
                key,
                value,
                next: null,
                prev: null,
            };
            this.contain++;
            this.push(pendingNode);
            this.cacheMap.set(key, pendingNode);
        }
    }
    //["LRUCache","put","put","get","put","get","put","get","get","get"]
    //[[2],       [1,1],[2,2], [1], [3,3], [2], [4,4], [1],  [3],  [4]]
    private insertHead(node: cacheNode<number> | null) {
        if (node) {
            if (this.lastestRecentlyUsed) {
                node.next = this.lastestRecentlyUsed.next;
                node.prev = this.lastestRecentlyUsed.prev;
                this.lastestRecentlyUsed!.next!.prev = node;
                this.lastestRecentlyUsed!.prev!.next = node;
                this.lastestRecentlyUsed = node;
            } else {
                this.lastestRecentlyUsed = node;
                this.lastestRecentlyUsed.prev = this.lastestRecentlyUsed.next = node;
            }
        }
        return this;
    }

    private push(node: cacheNode<number> | null) {
        if (node) {
            if (this.lastestRecentlyUsed) {
                let lastNode = this.lastestRecentlyUsed
                    .prev as cacheNode<number>;
                lastNode.next!.prev = node;
                lastNode.next = node;
                node.next = this.lastestRecentlyUsed;
                node.prev = lastNode;

                console.log('push', this.lastestRecentlyUsed);
            } else {
                this.lastestRecentlyUsed = node;
                this.lastestRecentlyUsed.prev = this.lastestRecentlyUsed.next = node;
            }
        }
        return this;
    }

    private remove(node: cacheNode<number> | null) {
        if (node && this.lastestRecentlyUsed) {
            if (
                this.lastestRecentlyUsed.next === this.lastestRecentlyUsed.prev
            ) {
                if (this.lastestRecentlyUsed === node) {
                    this.lastestRecentlyUsed = null;
                }
            } else {
                node.next!.prev = node.prev;
                node.prev!.next = node.next;
                if (node === this.lastestRecentlyUsed) {
                    this.lastestRecentlyUsed = node.next;
                }
            }
        }
        return this;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
