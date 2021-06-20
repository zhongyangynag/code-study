import Node from './Node';
interface IBinaryTree<T>{
    root:T;
    inorders:number[]
}
export default class BinaryTree implements IBinaryTree<Node>{
    root:Node;
    inorders:number[]
    constructor(params:number[]){
        this.root= new Node(params[0]);
        this.inorders=[]
        this.init(params)
    }
    init(params:number[]){
        let rootNode = this.root;
        for (let index = 1; index < params.length; index++) {
            this.insertNode(rootNode,params[index])
        }
    }
    insertNode(node:Node,key:number){
        let startNode = node;
        if(key<startNode.key){
            if(startNode.left===null){
                startNode.left=new Node(key)
            }else{
                this.insertNode(startNode.left,key)
            }
        }else{
            if(startNode.right===null){
                startNode.right=new Node(key)
            }else{
                this.insertNode(startNode.right,key)
            }
        }
    }
    inOrder(){
        let rootNode = this.root;
        let callback=(key:number)=>{
            this.inorders.push(key)
        }
        this.inorderTraversal(rootNode,callback)
    }
    private inorderTraversal(node:Node|null,callback:any){
        if(node!==null){
            this.inorderTraversal(node.left,callback)
            callback(node.key)
            this.inorderTraversal(node.right,callback)
        }
    }
}