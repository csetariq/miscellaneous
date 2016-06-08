public class BST {
    
    private class Node {
        int data;
        Node left;
        Node right;
    }
    
    private Node root;
    
    public BST() {
        
    }
    
    public boolean isEmpty() {
        return root == null;
    }
    
    public void insert(int value) {
        Node temp = new Node();
        temp.data = value;
        
        root = insert(root, temp);
    }
    
    private Node insert(Node candidate, Node current) {
        if (candidate == null)
            return current;
        
        if (current.data < candidate.data)
            candidate.left = insert(candidate.left, current);
        else
            candidate.right = insert(candidate.right, current);
        
        return candidate;
    }
    
    public int max() {
        if (root == null)
            return Integer.MIN_VALUE;
        
        Node temp = root;
        while (temp.right != null)
            temp = temp.right;
        
        return temp.data;
    }
    
    public int min() {
        if (root == null)
            return Integer.MAX_VALUE;
        
        Node temp = root;
        while (temp.left != null)
            temp = temp.left;
        
        return temp.data;
    }
    
    public void inorder() {
        inorder(root);
        System.out.println();
    }
    
    private void inorder(Node node) {
        if (node != null) {
            inorder(node.left);
            System.out.print(node.data + " ");
            inorder(node.right);
        }
    }
    
    public void preorder() {
        preorder(root);
        System.out.println();
    }
    
    private void preorder(Node node) {
        if (node != null) {
            System.out.print(node.data + " ");
            preorder(node.left);
            preorder(node.right);
        }
    }
    
    public void postorder() {
        postorder(root);
        System.out.println();
    }
    
    private void postorder(Node node) {
        if (node != null) {
            postorder(node.left);
            postorder(node.right);
            System.out.print(node.data + " ");
        }
    }
    
    public static void main(String... args) {
        BST bst = new BST();
        
        int[] input = new int[] {8, 4, 12, 2, 6, 1, 3, 5, 7, 10, 14, 9, 11, 13, 15};
        
        for (int num : input)
            bst.insert(num);
        
        System.out.println("min: " + bst.min());
        System.out.println("max: " + bst.max());
        System.out.println("inorder: ");
        bst.inorder();
        System.out.println("preorder: ");
        bst.preorder();
        System.out.println("postorder: ");
        bst.postorder();
    }
}
